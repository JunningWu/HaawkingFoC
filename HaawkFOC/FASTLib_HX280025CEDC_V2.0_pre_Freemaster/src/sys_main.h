/*
 * sys_main.h
 *
 *  Created on: 2023年1月30日
 *      Author: Kangaihong
 */

#ifndef SYS_MAIN_H_
#define SYS_MAIN_H_

#include "motor_common.h"
#include "motor1_drive.h"

#define LED_BLINK_FREQ_Hz           (0.5f)       // 1Hz
#define POWER_RELAY_WAIT_TIME_ms    (1000)       // 1s

typedef struct _SYSTEM_Vars_t_
{
    float32_t speedRef_Hz;

    uint32_t mainLoopCnt;
    uint32_t timerCnt_1min;

    uint16_t timerBase_1ms;
    uint16_t timerCnt_5ms;
    uint16_t timerCnt_1s;

    uint16_t powerRelayWaitTime_ms;

    uint16_t counterLED;        //!< Counter used to divide down the ISR rate for
                                //!< visually blinking an LED


    bool flagEnableSystem;
}SYSTEM_Vars_t;

//Vcu控制
struct Cmd1_Struct_Bits{
	Uint64	flagEnableRunAndIdentify:1;			//使能
	Uint64	flagEnableRsOnLine:1;					//在线电阻辨识使能
	Uint64  flagEnableRsRecalc:1;                   //电阻再计算
	Uint64  Rsd1:5;
	Uint64	speedSet_rpm:16;					       //目标转速,rpm
	Uint64	speedSet_hz:16;					       //目标转速,hz
	Uint64  speedStart_hz:16;    //
	Uint64  Rsd2:8;
};
union Cmd1_Struct_All{
	Uint64	all;
	struct 	Cmd1_Struct_Bits bits;
};

struct Cmd2_Struct_Bits{
	Uint64	Kp_spd:16;			//速度环Kp
	Uint64	Ki_spd:16;			//速度环Ki
	Uint64  Kp_Cur:16;            //电流环Kp
	Uint64  Ki_Cur:16;            //电流环Ki
};

union Cmd2_Struct_All{
	Uint64	all;
	struct 	Cmd2_Struct_Bits  bits;
};

//McuStat1
struct Stat1_Struct_Bits{
	Uint64	nFbk_rpm:16;					//电机转速，rpm，-15000rpm
	Uint64	nFbk_hz:16;						//电机频率，hz，  -3000hz
	Uint64	est_sate:16;						//估算状态，

	Uint64	FaultState:8;						//故障状态
	Uint64	EnableRunsta:8;				//运行使能反馈

};
union Stat1_Struct_All{
	Uint64	all;
	struct Stat1_Struct_Bits bits;
};

struct Stat2_Struct_Bits{
	Uint64	Kp_spd_fbk:16;			//速度环Kp
	Uint64	Ki_spd_fbk:16;			//速度环Ki
	Uint64  Kp_Cur_fbk:16;            //电流环Kp
	Uint64  Ki_Cur_fbk:16;            //电流环Ki
};

union Stat2_Struct_All{
	Uint64	all;
	struct 	Stat2_Struct_Bits  bits;
};

typedef struct{
	//Vcu通信

	Uint16	TxStat1Tmr;
	Uint16	TxStat1Cnt;
	Uint16	TxStat2Tmr;
	Uint16	TxStat2Cnt;

	union Cmd1_Struct_All   	Can_Cmd1;
	union Cmd2_Struct_All 	Can_Cmd2;
	union Stat1_Struct_All	    MotorStat1;
	union Stat2_Struct_All	    pid_fbk;
//	union Stat3_Struct_All	McuStat3;
//	union Stat4_Struct_All	McuStat4;

}ComCtrl_Struct;


//ComCtrl_Struct  can_com;
#endif /* SYS_MAIN_H_ */
