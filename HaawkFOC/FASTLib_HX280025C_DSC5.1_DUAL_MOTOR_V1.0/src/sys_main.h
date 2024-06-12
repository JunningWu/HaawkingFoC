/*
 * sys_main.h
 *
 *  Created on: 2023��1��30��
 *      Author: Kangaihong
 */

#ifndef SYS_MAIN_H_
#define SYS_MAIN_H_

#include "motor_common.h"
#include "motor_drive.h"

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

//Vcu����
struct Cmd1_Struct_Bits{
	Uint64	flagEnableRunAndIdentify:1;			//ʹ��
	Uint64	flagEnableRsOnLine:1;				//���ߵ����ʶʹ��
	Uint64  flagEnableRsRecalc:1;               //�����ټ���
	Uint64  Rsd1:5;
	Uint64	speedSet_rpm:16;					//Ŀ��ת��,rpm
	Uint64	speedSet_hz:16;					    //Ŀ��ת��,hz
	Uint64  speedStart_hz:16;                   //
	Uint64  Rsd2:8;
};
union Cmd1_Struct_All{
	Uint64	all;
	struct 	Cmd1_Struct_Bits bits;
};

struct Cmd2_Struct_Bits{
	Uint64	Kp_spd:16;			  //�ٶȻ�Kp
	Uint64	Ki_spd:16;			  //�ٶȻ�Ki
	Uint64  Kp_Cur:16;            //������Kp
	Uint64  Ki_Cur:16;            //������Ki
};

union Cmd2_Struct_All{
	Uint64	all;
	struct 	Cmd2_Struct_Bits  bits;
};

//McuStat1
struct Stat1_Struct_Bits{
	Uint64	nFbk_rpm:16;					//���ת�٣�rpm��-15000rpm
	Uint64	nFbk_hz:16;						//���Ƶ�ʣ�hz��  -3000hz
	Uint64	est_sate:16;					//����״̬��

	Uint64	FaultState:8;					//����״̬
	Uint64	EnableRunsta:8;				    //����ʹ�ܷ���

};
union Stat1_Struct_All{
	Uint64	all;
	struct Stat1_Struct_Bits bits;
};

struct Stat2_Struct_Bits{
	Uint64	Kp_spd_fbk:16;			  //�ٶȻ�Kp
	Uint64	Ki_spd_fbk:16;			  //�ٶȻ�Ki
	Uint64  Kp_Cur_fbk:16;            //������Kp
	Uint64  Ki_Cur_fbk:16;            //������Ki
};

union Stat2_Struct_All{
	Uint64	all;
	struct 	Stat2_Struct_Bits  bits;
};


#endif /* SYS_MAIN_H_ */
