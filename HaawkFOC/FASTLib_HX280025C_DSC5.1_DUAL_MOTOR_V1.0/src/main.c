/*
 * Copyright (c) 2019-2022 Beijing Haawking Technology Co.,Ltd
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Junning Wu
 * Email  : junning.wu@mail.haawking.com
 * FILE   : main.c
 *****************************************************************/
 
#include <syscalls.h>
#include "IQmathLib.h"
#include "driverlib.h"
#include "device.h"
#include "sys_main.h"

#include "f28x_project.h"
#include "freemaster_sci.h"
#include "freemaster.h"

CPU_TIME_Obj     cpuTime;
CPU_TIME_Handle  cpuTimeHandle;
volatile SYSTEM_Vars_t systemVars;

float32_t Iuvw[6];
float32_t Vuvw[8];
//Uint32 len;

//#define SecureCopyCodeZ2  (Uint32 (*)(Uint32 length, Uint8 *dst, Uint8 *src)) 0x7c1000

int main(void)
{
//	 HAL_clearDataRAM((void *)USER_RAM_START_ADDR, (uint16_t)USER_RAM_VARS_SIZE);
	//Initialize device clock and perioherals
 	Device_init();

//	len = (*SecureCopyCodeZ2)(0x1cf2, (Uint8 *)0x16000, (Uint8 *)0x000000000063c000);
    //Disable pin locks and enable interal pullups
	Device_initGPIO();

    // initialize the interrupt controller
    Interrupt_initModule();

    // init vector table
    Interrupt_initVectorTable();

	halHandle = HAL_init(&hal);

	// set the driver parameters
	HAL_setParams(halHandle);

    // set the control parameters for motor 1
    motorHandle[MTR_1] = (MOTOR_Handle)(&motorVars[MTR_1]);
    motorHandle[MTR_2] = (MOTOR_Handle)(&motorVars[MTR_2]);

    // set the reference speed, this can be replaced or removed
    motorVars[MTR_1].flagEnableRunAndIdentify = false;
    motorVars[MTR_2].flagEnableRunAndIdentify = false;
    motorVars[MTR_1].speedRef_Hz = 5.0f;
    motorVars[MTR_2].speedRef_Hz = 5.0f;
    userParams[MTR_1].flag_bypassMotorId = true;// false;//
    userParams[MTR_2].flag_bypassMotorId = true;// false;//

    initMotorHandles(motorHandle[MTR_1], MTR_1);
    initMotorHandles(motorHandle[MTR_2], MTR_2);

    // initialize motor control parameters
    initMotorCtrlParameters(motorHandle[MTR_1], MTR_1);
    initMotorCtrlParameters(motorHandle[MTR_2], MTR_2);
    // initialize the CPU usage module
    cpuTimeHandle = &cpuTime;
    CPU_TIME_reset(cpuTimeHandle);

    systemVars.flagEnableSystem = true;
    // initialize the interrupt vector table
    HAL_initIntVectorTable();
    // enable the ADC/PWM interrupts for control
    // enable interrupts to trig DMA
    HAL_enableCtrlInts(halHandle);
    motorVars[MTR_1].flagEnableOffsetCalc = true;//false;//
    motorVars[MTR_2].flagEnableOffsetCalc = true;

//    motorVars[MTR_1].flagEnableRsOnLine = true;
//    motorVars[MTR_1].flagEnableRsRecalc = true;
    // run offset calibration for motor 1
    runMotorOffsetsCalculation(motorHandle[MTR_1], MTR_1);
    runMotorOffsetsCalculation(motorHandle[MTR_2], MTR_2);

    /*初始化串口通信的GPIO口*/
	/*GPIO28: SCIRXDA*/
	/*GPIO29: SCITXDA*/
	InitSciGpio();

	/*SCI寄存器配置*/
	Scia_Config(115200);

	FMSTR_Init();

    // enable global interrupts
    HAL_enableGlobalInts(halHandle);
    // enable debug interrupts
    HAL_enableDebugInt(halHandle);

    systemVars.powerRelayWaitTime_ms = POWER_RELAY_WAIT_TIME_ms;

	while(systemVars.flagEnableSystem == false)
	{
		if(HAL_getCPUTimerStatus(halHandle, HAL_CPU_TIMER0))
		{
			HAL_clearCPUTimerFlag(halHandle, HAL_CPU_TIMER0);

			systemVars.timerBase_1ms++;

			if(systemVars.timerBase_1ms > systemVars.powerRelayWaitTime_ms)
			{
				systemVars.flagEnableSystem = true;
				systemVars.timerBase_1ms = 0;
			}
		}
		FMSTR_Poll();
		FMSTR_Recorder();
	}
	while(systemVars.flagEnableSystem == true)
	{
		// loop while the enable system flag is true
		systemVars.mainLoopCnt++;
		// 1ms time base
		if(HAL_getCPUTimerStatus(halHandle, HAL_CPU_TIMER0))
		{
			HAL_clearCPUTimerFlag(halHandle, HAL_CPU_TIMER0);

			// toggle status LED
			systemVars.counterLED++;

			if(systemVars.counterLED > (uint16_t)(LED_BLINK_FREQ_Hz * 1000))
			{
				HAL_toggleLED( HAL_GPIO_LED2C);

				systemVars.counterLED = 0;
			}
			systemVars.timerBase_1ms++;

			switch(systemVars.timerBase_1ms)
			{
				case 1:     // motor 1 protection check
				runMotorMonitor(motorHandle[MTR_1]);
				runMotorMonitor(motorHandle[MTR_2]);
				break;
				case 2:
				calculateRMSData(motorHandle[MTR_1]);
				calculateRMSData(motorHandle[MTR_2]);
				break;
				case 3:
				break;
				case 4:     // calculate motor protection value
				calcMotorOverCurrentThreshold(motorHandle[MTR_1]);
				calcMotorOverCurrentThreshold(motorHandle[MTR_2]);
				break;
				case 5:     // system control
				systemVars.timerBase_1ms = 0;
				systemVars.timerCnt_5ms++;
				break;
			}
		}
		runMotorControl(motorHandle[MTR_1]);
		runMotorControl(motorHandle[MTR_2]);

		FMSTR_Poll();
		FMSTR_Recorder();
	}
   // disable the PWM
   HAL_disablePWM(motorHandle[MTR_1]->halMtrHandle);
   HAL_disablePWM(motorHandle[MTR_2]->halMtrHandle);
}

//
// End of File
//

