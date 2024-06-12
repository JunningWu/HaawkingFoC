/*
 * motor1_drive.h
 *
 *  Created on: 2023Äê1ÔÂ31ÈÕ
 *      Author: Kangaihong
 */

#ifndef SRC_CONTROL_MOTOR1_DRIVE_H_
#define SRC_CONTROL_MOTOR1_DRIVE_H_

#include "userParams.h"
#include "motor_common.h"

// the globals
extern volatile MOTOR_Handle motorHandle_M1;

extern volatile MOTOR_Vars_t motorVars_M1;

extern MOTOR_SetVars_t motorSetVars_M1;

extern USER_Params userParams_M1;

extern void initMotor1Handles(MOTOR_Handle handle);
extern void initMotor1CtrlParameters(MOTOR_Handle handle);
extern void runMotor1OffsetsCalculation(MOTOR_Handle handle);
//! \brief run motor control in main loop
extern void runMotor1Control(MOTOR_Handle handle);
//extern INTERRUPT void motor1CtrlISR(void);

#endif /* SRC_CONTROL_MOTOR1_DRIVE_H_ */
