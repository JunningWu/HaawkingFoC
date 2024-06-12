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
float32_t Iuvw[3];
float32_t Vuvw[4];


Uint32 len;
uint16_t   rxMsgData[8];
uint16_t   rxMsgData1[8];
uint16_t   txMsgData1[8];
uint16_t   txMsgData2[8];
void CAN_init(void);
ComCtrl_Struct  can_com;
void updataCANCmd(void);

int main(void)
{
	int j;
//	 HAL_clearDataRAM((void *)USER_RAM_START_ADDR, (uint16_t)USER_RAM_VARS_SIZE);
//Initialize device clock and perioherals
 	Device_init();

 	EALLOW;
 	HWREG(0x38F28) = 0xF3F;
 	EDIS;

//Disable pin locks and enable interal pullups
	Device_initGPIO();

	can_com.Can_Cmd1.bits.speedSet_rpm = 0;
	can_com.Can_Cmd1.bits.flagEnableRunAndIdentify = false;
	can_com.TxStat1Tmr = 20;
	can_com.TxStat2Tmr = 50;
	can_com.TxStat1Cnt = 0;
	can_com.TxStat2Cnt = 0;
//	rxMsgData[0] =0x8;
//	rxMsgData[1] =0xBB;
//	rxMsgData[2] =0x0;
    // initialize the interrupt controller
    Interrupt_initModule();

    // init vector table
    Interrupt_initVectorTable();

	halHandle = HAL_init(&hal);
	// set the driver parameters
	HAL_setParams(halHandle);
    CAN_init();
    // set the control parameters for motor 1
    motorHandle_M1 = (MOTOR_Handle)(&motorVars_M1);

    // set the reference speed, this can be replaced or removed
    motorVars_M1.flagEnableRunAndIdentify = false;
    motorVars_M1.speedRef_Hz = 1.0f;
    userParams_M1.flag_bypassMotorId =true;//false;//
    initMotor1Handles(motorHandle_M1);
    // initialize motor control parameters
    initMotor1CtrlParameters(motorHandle_M1);
    // initialize the CPU usage module
    cpuTimeHandle = &cpuTime;
    CPU_TIME_reset(cpuTimeHandle);


    systemVars.flagEnableSystem = true;
    // initialize the interrupt vector table
 //   HAL_initIntVectorTable(halHandle);
    HAL_initIntVectorTable();
    // enable the ADC/PWM interrupts for control
    // enable interrupts to trig DMA
    HAL_enableCtrlInts();
    motorVars_M1.flagEnableOffsetCalc = true;

//    motorVars_M1.flagEnableRsOnLine = true;
  //  motorVars_M1.flagEnableRsRecalc = true;
    // run offset calibration for motor 1
    runMotor1OffsetsCalculation(motorHandle_M1);


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

//	for(j=0;j<11520;j++);
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
                  runMotorMonitor(motorHandle_M1);
                   break;
               case 2:
                   calculateRMSData(motorHandle_M1);
                   break;
               case 3:
                   break;
               case 4:     // calculate motor protection value
                   calcMotorOverCurrentThreshold(motorHandle_M1);
                   break;
               case 5:     // system control
                   systemVars.timerBase_1ms = 0;
                   systemVars.timerCnt_5ms++;
                   break;
           }

       //    updataCANCmd();
       }

       runMotor1Control(motorHandle_M1);

//       for(j=0;j<11520;j++);
       	FMSTR_Poll();
       	FMSTR_Recorder();

   }
   // disable the PWM
   HAL_disablePWM(motorHandle_M1->halMtrHandle);
}


void CAN_init(void)
{
	CAN_initModule(CANA_BASE);
//    CAN_setBitTiming(CANA_BASE,7,0,15,7,3);
	CAN_setBitRate(CANA_BASE, 160000000, 500000, 20);//500k

    CAN_setupMessageObject(CANA_BASE, 1, 0x14444444, CAN_MSG_FRAME_EXT,
                           CAN_MSG_OBJ_TYPE_RX, 0, 0, 8);

    CAN_setupMessageObject(CANA_BASE, 2, 0x15555555, CAN_MSG_FRAME_EXT,
                           CAN_MSG_OBJ_TYPE_RX, 0, 0, 8);

    CAN_setupMessageObject(CANA_BASE, 3, 0x16666666, CAN_MSG_FRAME_EXT,
                           CAN_MSG_OBJ_TYPE_TX, 0, 0, 8);

    CAN_setupMessageObject(CANA_BASE,4, 0x17777777, CAN_MSG_FRAME_EXT,
                           CAN_MSG_OBJ_TYPE_TX, 0, 0, 8);


    CAN_startModule(CANA_BASE);
	can_com.Can_Cmd1.bits.speedSet_rpm = 0;
	can_com.Can_Cmd1.bits.flagEnableRunAndIdentify = false;
	can_com.Can_Cmd1.bits.flagEnableRsOnLine = false;
	can_com.Can_Cmd1.bits.flagEnableRsRecalc = false;

	can_com.Can_Cmd2.bits.Ki_Cur = motorVars_M1.piHandle_Id->Kp * 1000.0f;
	can_com.Can_Cmd2.bits.Kp_Cur = motorVars_M1.piHandle_Id->Ki * 1000.0f;
	can_com.Can_Cmd2.bits.Ki_spd = motorVars_M1.piHandle_spd->Ki * 1000.0f;
	can_com.Can_Cmd2.bits.Kp_spd = motorVars_M1.piHandle_spd->Kp * 1000.0f;

}
float32_t spd_temp;
float32_t spdstart_temp;
#define USER_M1_SPEED_MAX          (250.0f)
void updataCANCmd(void)
{
	 if(CAN_readMessage(CANA_BASE,2,rxMsgData))
	 {
		 CAN_clearInterruptStatus(CANA_BASE, 2);

		 can_com.Can_Cmd1.bits.flagEnableRunAndIdentify = (bool)(rxMsgData[0] & 0x01);
		 can_com.Can_Cmd1.bits.flagEnableRsOnLine = (bool)(rxMsgData[0] & 0x02);
		 can_com.Can_Cmd1.bits.flagEnableRsRecalc = (bool)(rxMsgData[0] & 0x04);
		 can_com.Can_Cmd1.bits.speedSet_rpm = (rxMsgData[2] << 8)  + rxMsgData[1] ;
		 can_com.Can_Cmd1.bits.speedSet_hz = (rxMsgData[4] << 8)  + rxMsgData[3] ;
		 can_com.Can_Cmd1.bits.speedStart_hz = (rxMsgData[6] << 8)  + rxMsgData[5] ;

		 spd_temp =( float32_t)(((int16_t)can_com.Can_Cmd1.bits.speedSet_hz ));
		 if(spd_temp > USER_M1_SPEED_MAX)  spd_temp = USER_M1_SPEED_MAX;
		 if(spd_temp < -USER_M1_SPEED_MAX)  spd_temp =- USER_M1_SPEED_MAX;
//         motorVars_M1.speedRef_Hz = spd_temp * (float32_t)USER_MOTOR1_NUM_POLE_PAIRS/60.0f;
		 motorVars_M1.speedRef_Hz = spd_temp;

		 spdstart_temp =( float32_t)(((int16_t)can_com.Can_Cmd1.bits.speedStart_hz ));
		 if(spdstart_temp > (USER_M1_SPEED_MAX + 10.0f))  spdstart_temp = (USER_M1_SPEED_MAX + 10.0f);
		 if(spdstart_temp < (-USER_M1_SPEED_MAX - 10.0f))  spdstart_temp =- USER_M1_SPEED_MAX - 10.0f;
		 motorVars_M1.speedStart_Hz = spdstart_temp;


         motorVars_M1.flagEnableRsOnLine =  can_com.Can_Cmd1.bits.flagEnableRsOnLine;
         motorVars_M1.flagEnableRsRecalc =  can_com.Can_Cmd1.bits.flagEnableRsRecalc;
         if((can_com.Can_Cmd1.bits.flagEnableRunAndIdentify == true)  && (motorHandle_M1->faultMtrUse.all == 0))
         {
        	 motorHandle_M1->flagEnableRunAndIdentify = true;
         }
         else if( (motorHandle_M1->flagEnableRunAndIdentify == true) && (can_com.Can_Cmd1.bits.flagEnableRunAndIdentify == false) )
         {
      		   motorHandle_M1->flagEnableRunAndIdentify = false;
      		 ESTOP0;	//debugestop
         }

	 }

	 if(CAN_readMessage(CANA_BASE,1,rxMsgData1))
	 {
		 CAN_clearInterruptStatus(CANA_BASE, 1);
		 can_com.Can_Cmd2.bits.Kp_spd = (rxMsgData1[1] << 8)  + rxMsgData1[0] ;
		 can_com.Can_Cmd2.bits.Ki_spd = (rxMsgData1[3] << 8)  + rxMsgData1[2] ;
		 can_com.Can_Cmd2.bits.Ki_Cur = (rxMsgData1[5] << 8)  + rxMsgData1[4] ;
		 can_com.Can_Cmd2.bits.Kp_Cur = (rxMsgData1[7] << 8)  + rxMsgData1[6] ;

		 motorVars_M1.motorSetsHandle->Kp_spd  = (float32_t)can_com.Can_Cmd2.bits.Kp_spd * 0.001;
		 motorVars_M1.motorSetsHandle->Ki_spd = (float32_t)can_com.Can_Cmd2.bits.Ki_spd * 0.001;

		 motorVars_M1.motorSetsHandle->Kp_Id = (float32_t)can_com.Can_Cmd2.bits.Kp_Cur * 0.001;
		 motorVars_M1.motorSetsHandle->Ki_Id = (float32_t)can_com.Can_Cmd2.bits.Ki_Cur * 0.001;

		 motorVars_M1.motorSetsHandle->Kp_Iq = (float32_t)can_com.Can_Cmd2.bits.Kp_Cur * 0.001;
		 motorVars_M1.motorSetsHandle->Ki_Iq = (float32_t)can_com.Can_Cmd2.bits.Ki_Cur * 0.001;

	 }

	 can_com.TxStat1Cnt++;
	 can_com.TxStat2Cnt++;
     if(can_com.TxStat1Tmr <= can_com.TxStat1Cnt)
     {
    	 can_com.TxStat1Cnt = 0;
    	 float32_t temp_spd;

    	 temp_spd = EST_getFm_lp_Hz(motorHandle_M1->estHandle) * 60.0f /(float32_t)USER_MOTOR1_NUM_POLE_PAIRS;

    	 can_com.MotorStat1.bits.nFbk_rpm = (int16)(temp_spd );

    	 temp_spd = EST_getFm_lp_Hz(motorHandle_M1->estHandle) ;
//    	 can_com.MotorStat1.bits.nFbk_hz = (Uint16)((temp_spd*10.0f +(float32_t)10000));
    	 can_com.MotorStat1.bits.nFbk_hz = (int16)(temp_spd*10.0f );
    	 can_com.MotorStat1.bits.est_sate = EST_getState(motorHandle_M1->estHandle);

         if(motorHandle_M1->faultMtrNow.bit.currentOffset == 1)
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x1;
         }
         if(motorHandle_M1->faultMtrNow.bit.voltageOffset == 1)
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x2;
         }
         if(motorHandle_M1->faultMtrNow.bit.moduleOverCurrent == 1)//   Hardware Over Current Fault Flag
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x4;
         }
         if(motorHandle_M1->faultMtrNow.bit.overPeakCurrent == 1) // internal CMPSS Over Current Fault Flag
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x8;
         }
         if(motorHandle_M1->faultMtrNow.bit.overVoltage == 1)//   DC Bus Over Voltage Fault
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x10;
         }
         if(motorHandle_M1->faultMtrNow.bit.underVoltage == 1) // DC Bus Under Voltage Fault
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x20;
         }
         if(motorHandle_M1->faultMtrNow.bit.overSpeed == 1) //  Motor Over Speed
         {
        	 can_com.MotorStat1.bits.FaultState |= 0x40;
         }
         can_com.MotorStat1.bits.EnableRunsta = motorHandle_M1->flagEnableRunAndIdentify ;

         txMsgData1[0] = can_com.MotorStat1.bits.nFbk_rpm &0xff;
         txMsgData1[1] =( can_com.MotorStat1.bits.nFbk_rpm >>8 )&0xff;
         txMsgData1[2] = can_com.MotorStat1.bits.nFbk_hz &0xff;
         txMsgData1[3] =( can_com.MotorStat1.bits.nFbk_hz >>8 )&0xff;
         txMsgData1[4] = can_com.MotorStat1.bits.est_sate;
         txMsgData1[5] = 0;
         txMsgData1[6] = can_com.MotorStat1.bits.FaultState;
         txMsgData1[7] = can_com.MotorStat1.bits.EnableRunsta;

         CAN_sendMessage(CANA_BASE, 4, 8, txMsgData1);

     }
     if(can_com.TxStat2Tmr <= can_com.TxStat2Cnt)
     {
    	 can_com.TxStat2Cnt = 0;
         can_com.pid_fbk.bits.Kp_spd_fbk = (Uint16)(motorVars_M1.piHandle_spd->Kp * 1000.0f);
         can_com.pid_fbk.bits.Ki_spd_fbk = (Uint16)(motorVars_M1.piHandle_spd->Ki * 1000.0f);

         can_com.pid_fbk.bits.Kp_Cur_fbk = (Uint16)(motorVars_M1.piHandle_Id->Kp * 1000.0f);
         can_com.pid_fbk.bits.Ki_Cur_fbk = (Uint16)(motorVars_M1.piHandle_Id->Ki * 1000.0f);
         txMsgData2[0] = can_com.pid_fbk.bits.Kp_spd_fbk  &0xff;
         txMsgData2[1] =( can_com.pid_fbk.bits.Kp_spd_fbk  >>8 )&0xff;
         txMsgData2[2] = can_com.pid_fbk.bits.Ki_spd_fbk &0xff;
         txMsgData2[3] =( can_com.pid_fbk.bits.Ki_spd_fbk >>8 )&0xff;

         txMsgData2[4] = can_com.pid_fbk.bits.Kp_Cur_fbk  &0xff;
         txMsgData2[5] =( can_com.pid_fbk.bits.Kp_Cur_fbk  >>8 )&0xff;
         txMsgData2[6] = can_com.pid_fbk.bits.Ki_Cur_fbk &0xff;
         txMsgData2[7] =( can_com.pid_fbk.bits.Ki_Cur_fbk >>8 )&0xff;
         CAN_sendMessage(CANA_BASE, 3, 8, txMsgData2);

     }


}
//
// End of File
//

