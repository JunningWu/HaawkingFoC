/*
 * motor_drive.c
 *
 *  Created on: 2024Äê3ÔÂ4ÈÕ
 *      Author: GuanXingyu
 */
#include "sys_main.h"
#include "motor_drive.h"
#include "always.h"

CODE_SECTION(".data") volatile MOTOR_Handle      motorHandle[2];
CODE_SECTION(".data") volatile MOTOR_Vars_t      motorVars[2];
CODE_SECTION(".data")          USER_Params       userParams[2];
CODE_SECTION(".data")          MOTOR_SetVars_t   motorSetVars[2];
CODE_SECTION( ".ramgs0")       EST_Handle        EST[2];
CODE_SECTION(".data")          HAL_MTR_Obj       halMtr[2];
CODE_SECTION(".data")          DRVIC_VARS_t      drvicVars[2];
CODE_SECTION(".data")          CLARKE_Obj        clarke_V[2];
CODE_SECTION(".data")          CLARKE_Obj        clarke_I[2];
CODE_SECTION(".data")          IPARK_Obj         ipark_V[2];
CODE_SECTION(".data")          PARK_Obj          park_I[2];
CODE_SECTION(".data")          PARK_Obj          park_V[2];
CODE_SECTION(".data")          PI_Obj            pi_Id[2];
CODE_SECTION(".data")          PI_Obj            pi_Iq[2];
CODE_SECTION(".data")          PI_Obj            pi_spd[2];
CODE_SECTION(".data")          SVGEN_Obj         svgen[2];
CODE_SECTION(".data")          TRAJ_Obj          traj_spd[2];

void initMotorHandles(MOTOR_Handle handle, const MotorNum_e motorNum)
{
	MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

	if(motorNum == MTR_1)
	{
		obj->motorSetsHandle = &motorSetVars[MTR_1];
		obj->userParamsHandle = &userParams[MTR_1];
		obj->estHandle = (EST_Handle)est_motor_1;
		// initialize the driver
		obj->halMtrHandle = HAL_MTR1_init(&halMtr[MTR_1], sizeof(halMtr[MTR_1]));
		obj->drvVarsHandle = &drvicVars[MTR_1];
	}

	if(motorNum == MTR_2)
	{
		obj->motorSetsHandle = &motorSetVars[MTR_2];
		obj->userParamsHandle = &userParams[MTR_2];
		obj->estHandle = (EST_Handle)est_motor_2;
		// initialize the driver
		obj->halMtrHandle = HAL_MTR2_init(&halMtr[MTR_2], sizeof(halMtr[MTR_2]));
		obj->drvVarsHandle = &drvicVars[MTR_2];
	}
    return;
}

// initialize control parameters for motor
void initMotorCtrlParameters(MOTOR_Handle handle, const MotorNum_e motorNum)
{
	MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
	MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);
	USER_Params *objUser = (USER_Params *)(handle->userParamsHandle);

	// initialize the user parameters
	USER_setParams_priv(obj->userParamsHandle);

	// set the driver parameters
	HAL_MTR_setParams(obj->halMtrHandle, obj->userParamsHandle, motorNum);

	if(motorNum == MTR_1)
	{
		// initialize the user parameters
		USER_setMotor1Params(obj->userParamsHandle);

		objSets->Kp_spd = 0.05f;
		objSets->Ki_spd = 0.005f;

		objSets->Kp_fwc = USER_M1_FWC_KP;
		objSets->Ki_fwc = USER_M1_FWC_KI;
		objSets->angleFWCMax_rad = USER_M1_FWC_MAX_ANGLE_RAD;

		objSets->overModulation = USER_M1_MAX_VS_MAG_PU;
		objSets->RsOnLineCurrent_A = 0.1f * USER_MOTOR1_MAX_CURRENT_A;

		objSets->lostPhaseSet_A = USER_M1_LOST_PHASE_CURRENT_A;
		objSets->unbalanceRatioSet = USER_M1_UNBALANCE_RATIO;
		objSets->overLoadSet_W = USER_M1_OVER_LOAD_POWER_W;
		objSets->stallCurrentSet_A = USER_M1_STALL_CURRENT_A;

		objSets->IsFailedChekSet_A = USER_M1_FAULT_CHECK_CURRENT_A;

		objSets->speedFailMaxSet_Hz = USER_M1_FAIL_SPEED_MAX_HZ;
		objSets->speedFailMinSet_Hz = USER_M1_FAIL_SPEED_MIN_HZ;

		objSets->toqueFailMinSet_Nm = USER_M1_TORQUE_FAILED_SET;

		objSets->maxPeakCurrent_A = USER_M1_ADC_FULL_SCALE_CURRENT_A * 0.495f;
		objSets->overCurrent_A = USER_MOTOR1_OVER_CURRENT_A;
		objSets->currentInv_sf = USER_M1_CURRENT_INV_SF;

		objSets->overVoltageFault_V = USER_M1_OVER_VOLTAGE_FAULT_V;
		objSets->overVoltageNorm_V = USER_M1_OVER_VOLTAGE_NORM_V;
		objSets->underVoltageFault_V = USER_M1_UNDER_VOLTAGE_FAULT_V;
		objSets->underVoltageNorm_V = USER_M1_UNDER_VOLTAGE_NORM_V;

		objSets->voltageFaultTimeSet = USER_M1_VOLTAGE_FAULT_TIME_SET;

		objSets->overLoadTimeSet = USER_M1_OVER_LOAD_TIME_SET;
		objSets->motorStallTimeSet = USER_M1_STALL_TIME_SET;
		objSets->unbalanceTimeSet = USER_M1_UNBALANCE_TIME_SET;
		objSets->lostPhaseTimeSet = USER_M1_LOST_PHASE_TIME_SET;
		objSets->overSpeedTimeSet = USER_M1_OVER_SPEED_TIME_SET;
		objSets->startupFailTimeSet = USER_M1_STARTUP_FAIL_TIME_SET;

		objSets->overCurrentTimesSet = USER_M1_OVER_CURRENT_TIMES_SET;

		objSets->stopWaitTimeSet = USER_M1_STOP_WAIT_TIME_SET;
		objSets->restartWaitTimeSet = USER_M1_RESTART_WAIT_TIME_SET;


		objSets->restartTimesSet = USER_M1_START_TIMES_SET;

		objSets->dacCMPValH = 2048U + 1024U;    // set default positive peak value
		objSets->dacCMPValL = 2048U - 1024U;    // set default negative peak value

		obj->stopWaitTimeCnt = 0;

		obj->adcData.voltage_sf = objUser->voltage_sf;
		obj->adcData.dcBusvoltage_sf = objUser->voltage_sf;

		obj->adcData.current_sf = objUser->current_sf;
		obj->flagEnableRestart = false;

		obj->operateMode = OPERATE_MODE_SPEED;
		obj->faultMtrMask.all = MTR1_FAULT_MASK_SET;

		obj->speedStart_Hz = USER_MOTOR1_SPEED_START_Hz;
		obj->speedForce_Hz = USER_MOTOR1_SPEED_FORCE_Hz;
		obj->speedFlyingStart_Hz = USER_MOTOR1_SPEED_FS_Hz;

		obj->accelerationMax_Hzps = USER_MOTOR1_ACCEL_MAX_Hzps;
		obj->accelerationStart_Hzps = USER_MOTOR1_ACCEL_START_Hzps;

		obj->VsRef_pu = 0.98f * USER_M1_MAX_VS_MAG_PU;
		obj->VsRef_V = 0.98f * USER_M1_MAX_VS_MAG_PU * USER_M1_NOMINAL_DC_BUS_VOLTAGE_V;

		obj->fluxCurrent_A = USER_MOTOR1_FLUX_CURRENT_A;
		obj->alignCurrent_A = USER_MOTOR1_ALIGN_CURRENT_A;
		obj->startCurrent_A = USER_MOTOR1_STARTUP_CURRENT_A;
		obj->maxCurrent_A = USER_MOTOR1_MAX_CURRENT_A;
		obj->IsSet_A = USER_MOTOR1_TORQUE_CURRENT_A;

		obj->power_sf = MATH_TWO_PI / USER_MOTOR1_NUM_POLE_PAIRS;
		obj->VIrmsIsrScale = objUser->ctrlFreq_Hz;

		obj->angleDelayed_sf = 0.5f * MATH_TWO_PI * USER_M1_CTRL_PERIOD_sec;

		obj->flyingStartTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 0.5f); // 0.5s

		obj->flyingStartMode = FLYINGSTART_MODE_HALT;

		if(objUser->flag_bypassMotorId == true)
		{

			obj->svmMode = SVM_MIN_C;

			obj->flagEnableFWC = true;
		}
		else
		{
			obj->svmMode = SVM_COM_C;
			obj->flagEnableFWC = false;
		}

		obj->flagEnableForceAngle = true;
		obj->flagEnableFlyingStart = false;
		obj->flagEnableIPD = false;

		obj->flagEnableSpeedCtrl = true;
		obj->flagEnableCurrentCtrl = true;

		obj->estState = EST_STATE_IDLE;
		obj->trajState = EST_TRAJ_STATE_IDLE;

		obj->flagEnableAlignment = true;
		obj->alignTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 0.1f);          // 0.1s
		obj->forceRunTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 1.0f);       // 1.0s

		obj->fwcTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 2.0f);        // 2.0s

		// initialize the Clarke modules
		obj->clarkeHandle_V = &clarke_V[motorNum];

		// set the Clarke parameters
		setupClarke_V(obj->clarkeHandle_V, objUser->numVoltageSensors);

		// initialize the Clarke modules
		obj->clarkeHandle_I = &clarke_I[motorNum];

		// set the Clarke parameters
		setupClarke_I(obj->clarkeHandle_I, objUser->numCurrentSensors);

		// initialize the inverse Park module
		obj->iparkHandle_V = &ipark_V[motorNum];

		// initialize the Park module
		obj->parkHandle_I = &park_I[motorNum];

		// initialize the Park module
		obj->parkHandle_V = &park_V[motorNum];

		// initialize the PI controllers
		obj->piHandle_Id  = &pi_Id[motorNum];
		obj->piHandle_Iq  = &pi_Iq[motorNum];
		obj->piHandle_spd = &pi_spd[motorNum];

		// initialize the space vector generator module
		obj->svgenHandle = &svgen[motorNum];

		SVGEN_setMode(obj->svgenHandle, SVM_COM_C);

		HAL_setTriggerPrams(&obj->pwmData, USER_SYSTEM_FREQ_MHz, 0.2f, 0.1f);
		// initialize the speed reference trajectory
		obj->trajHandle_spd = &traj_spd[motorNum];

		// configure the speed reference trajectory (Hz)
		TRAJ_setTargetValue(obj->trajHandle_spd, 0.0f);
		TRAJ_setIntValue(obj->trajHandle_spd, 0.0f);
		TRAJ_setMinValue(obj->trajHandle_spd, -objUser->maxFrequency_Hz);
		TRAJ_setMaxValue(obj->trajHandle_spd, objUser->maxFrequency_Hz);
		TRAJ_setMaxDelta(obj->trajHandle_spd, (objUser->maxAccel_Hzps / objUser->ctrlFreq_Hz));

		// turn on the DRV8323/DRV8353/DRV8316 if present
		HAL_enableDRV(obj->halMtrHandle);

		// initialize the DRV8323/DRV8353/DRV8316 interface
		HAL_setupDRVSPI(obj->halMtrHandle, &drvicVars[motorNum]);

		drvicVars[MTR_1].ctrlReg02.bit.OTW_REP = true;
		drvicVars[MTR_1].ctrlReg02.bit.PWM_MODE = DRV8323_PWMMODE_6;

		drvicVars[MTR_1].ctrlReg05.bit.VDS_LVL = DRV8323_VDS_LEVEL_1P700_V;
		drvicVars[MTR_1].ctrlReg05.bit.OCP_MODE = DRV8323_AUTOMATIC_RETRY;
		drvicVars[MTR_1].ctrlReg05.bit.DEAD_TIME = DRV8323_DEADTIME_100_NS;
		drvicVars[MTR_1].ctrlReg06.bit.CSA_GAIN = DRV8323_Gain_10VpV;

		drvicVars[MTR_1].ctrlReg06.bit.LS_REF = false;
		drvicVars[MTR_1].ctrlReg06.bit.VREF_DIV = true;
		drvicVars[MTR_1].ctrlReg06.bit.CSA_FET = false;

		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);

		drvicVars[motorNum].writeCmd = 1;
		HAL_writeDRVData(obj->halMtrHandle, &drvicVars[motorNum]);

		// set the default estimator parameters
		EST_setParams(obj->estHandle, obj->userParamsHandle);
		EST_setFlag_enableForceAngle(obj->estHandle,obj->flagEnableForceAngle);
		EST_setFlag_enableRsRecalc(obj->estHandle,obj->flagEnableRsRecalc);
		EST_setOneOverFluxGain_sf(obj->estHandle,
									  obj->userParamsHandle, USER_M1_EST_FLUX_HF_SF);
		EST_setFreqLFP_sf(obj->estHandle, obj->userParamsHandle, USER_M1_EST_FREQ_HF_SF);
		EST_setBemf_sf(obj->estHandle,
					   obj->userParamsHandle, USER_M1_EST_BEMF_HF_SF);


		// if motor is an induction motor, configure default state of PowerWarp
		if(objUser->motor_type == MOTOR_TYPE_INDUCTION)
		{
			EST_setFlag_enablePowerWarp(obj->estHandle, obj->flagEnablePowerWarp);
			EST_setFlag_bypassLockRotor(obj->estHandle, obj->flagBypassLockRotor);
		}

		// for Rs online calibration
		obj->flagRsOnLineContinue = false;
		obj->flagStartRsOnLine = false;

		objSets->RsOnlineWaitTimeSet = USER_MOTOR1_RSONLINE_WAIT_TIME;
		objSets->RsOnlineWorkTimeSet = USER_MOTOR1_RSONLINE_WORK_TIME;

		// setup the controllers, speed, d/q-axis current pid regulator
		setupControllers(handle);

		// setup faults
//		HAL_setupMtrFaults(obj->halMtrHandle, motorNum);

		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);
	}

	if(motorNum == MTR_2)
	{
		// initialize the user parameters
		USER_setMotor2Params(obj->userParamsHandle);

		objSets->Kp_spd = 0.05f;
		objSets->Ki_spd = 0.005f;

		objSets->Kp_fwc = USER_M2_FWC_KP;
		objSets->Ki_fwc = USER_M2_FWC_KI;
		objSets->angleFWCMax_rad = USER_M2_FWC_MAX_ANGLE_RAD;

		objSets->overModulation = USER_M2_MAX_VS_MAG_PU;
		objSets->RsOnLineCurrent_A = 0.1f * USER_MOTOR2_MAX_CURRENT_A;

		objSets->lostPhaseSet_A = USER_M2_LOST_PHASE_CURRENT_A;
		objSets->unbalanceRatioSet = USER_M2_UNBALANCE_RATIO;
		objSets->overLoadSet_W = USER_M2_OVER_LOAD_POWER_W;
		objSets->stallCurrentSet_A = USER_M2_STALL_CURRENT_A;

		objSets->IsFailedChekSet_A = USER_M2_FAULT_CHECK_CURRENT_A;

		objSets->speedFailMaxSet_Hz = USER_M2_FAIL_SPEED_MAX_HZ;
		objSets->speedFailMinSet_Hz = USER_M2_FAIL_SPEED_MIN_HZ;

		objSets->toqueFailMinSet_Nm = USER_M2_TORQUE_FAILED_SET;

		objSets->maxPeakCurrent_A = USER_M2_ADC_FULL_SCALE_CURRENT_A * 0.495f;
		objSets->overCurrent_A = USER_MOTOR2_OVER_CURRENT_A;
		objSets->currentInv_sf = USER_M2_CURRENT_INV_SF;

		objSets->overVoltageFault_V = USER_M2_OVER_VOLTAGE_FAULT_V;
		objSets->overVoltageNorm_V = USER_M2_OVER_VOLTAGE_NORM_V;
		objSets->underVoltageFault_V = USER_M2_UNDER_VOLTAGE_FAULT_V;
		objSets->underVoltageNorm_V = USER_M2_UNDER_VOLTAGE_NORM_V;

		objSets->voltageFaultTimeSet = USER_M2_VOLTAGE_FAULT_TIME_SET;

		objSets->overLoadTimeSet = USER_M2_OVER_LOAD_TIME_SET;
		objSets->motorStallTimeSet = USER_M2_STALL_TIME_SET;
		objSets->unbalanceTimeSet = USER_M2_UNBALANCE_TIME_SET;
		objSets->lostPhaseTimeSet = USER_M2_LOST_PHASE_TIME_SET;
		objSets->overSpeedTimeSet = USER_M2_OVER_SPEED_TIME_SET;
		objSets->startupFailTimeSet = USER_M2_STARTUP_FAIL_TIME_SET;

		objSets->overCurrentTimesSet = USER_M2_OVER_CURRENT_TIMES_SET;

		objSets->stopWaitTimeSet = USER_M2_STOP_WAIT_TIME_SET;
		objSets->restartWaitTimeSet = USER_M2_RESTART_WAIT_TIME_SET;


		objSets->restartTimesSet = USER_M2_START_TIMES_SET;

		objSets->dacCMPValH = 2048U + 1024U;    // set default positive peak value
		objSets->dacCMPValL = 2048U - 1024U;    // set default negative peak value

		obj->stopWaitTimeCnt = 0;

		obj->adcData.voltage_sf = objUser->voltage_sf;
		obj->adcData.dcBusvoltage_sf = objUser->voltage_sf;

		obj->adcData.current_sf = objUser->current_sf;
		obj->flagEnableRestart = false;

		obj->operateMode = OPERATE_MODE_SPEED;
		obj->faultMtrMask.all = MTR2_FAULT_MASK_SET;

		obj->speedStart_Hz = USER_MOTOR2_SPEED_START_Hz;
		obj->speedForce_Hz = USER_MOTOR2_SPEED_FORCE_Hz;
		obj->speedFlyingStart_Hz = USER_MOTOR2_SPEED_FS_Hz;

		obj->accelerationMax_Hzps = USER_MOTOR2_ACCEL_MAX_Hzps;
		obj->accelerationStart_Hzps = USER_MOTOR2_ACCEL_START_Hzps;

		obj->VsRef_pu = 0.98f * USER_M2_MAX_VS_MAG_PU;
		obj->VsRef_V = 0.98f * USER_M2_MAX_VS_MAG_PU * USER_M2_NOMINAL_DC_BUS_VOLTAGE_V;

		obj->fluxCurrent_A = USER_MOTOR2_FLUX_CURRENT_A;
		obj->alignCurrent_A = USER_MOTOR2_ALIGN_CURRENT_A;
		obj->startCurrent_A = USER_MOTOR2_STARTUP_CURRENT_A;
		obj->maxCurrent_A = USER_MOTOR2_MAX_CURRENT_A;
		obj->IsSet_A = USER_MOTOR2_TORQUE_CURRENT_A;

		obj->power_sf = MATH_TWO_PI / USER_MOTOR2_NUM_POLE_PAIRS;
		obj->VIrmsIsrScale = objUser->ctrlFreq_Hz;

		obj->angleDelayed_sf = 0.5f * MATH_TWO_PI * USER_M2_CTRL_PERIOD_sec;

		obj->flyingStartTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 0.5f); // 0.5s

		obj->flyingStartMode = FLYINGSTART_MODE_HALT;

		if(objUser->flag_bypassMotorId == true)
		{

			obj->svmMode = SVM_MIN_C;

			obj->flagEnableFWC = true;
		}
		else
		{
			obj->svmMode = SVM_COM_C;
			obj->flagEnableFWC = false;
		}

		obj->flagEnableForceAngle = true;
		obj->flagEnableFlyingStart = false;
		obj->flagEnableIPD = false;

		obj->flagEnableSpeedCtrl = true;
		obj->flagEnableCurrentCtrl = true;

		obj->estState = EST_STATE_IDLE;
		obj->trajState = EST_TRAJ_STATE_IDLE;

		obj->flagEnableAlignment = true;
		obj->alignTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 0.1f);          // 0.1s
		obj->forceRunTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 1.0f);       // 1.0s

		obj->fwcTimeDelay = (uint16_t)(objUser->ctrlFreq_Hz * 2.0f);        // 2.0s

		// initialize the Clarke modules
		obj->clarkeHandle_V = &clarke_V[motorNum];

		// set the Clarke parameters
		setupClarke_V(obj->clarkeHandle_V, objUser->numVoltageSensors);

		// initialize the Clarke modules
		obj->clarkeHandle_I = &clarke_I[motorNum];

		// set the Clarke parameters
		setupClarke_I(obj->clarkeHandle_I, objUser->numCurrentSensors);

		// initialize the inverse Park module
		obj->iparkHandle_V = &ipark_V[motorNum];

		// initialize the Park module
		obj->parkHandle_I = &park_I[motorNum];

		// initialize the Park module
		obj->parkHandle_V = &park_V[motorNum];

		// initialize the PI controllers
		obj->piHandle_Id  = &pi_Id[motorNum];
		obj->piHandle_Iq  = &pi_Iq[motorNum];
		obj->piHandle_spd = &pi_spd[motorNum];

		// initialize the space vector generator module
		obj->svgenHandle = &svgen[motorNum];

		SVGEN_setMode(obj->svgenHandle, SVM_COM_C);

		HAL_setTriggerPrams(&obj->pwmData, USER_SYSTEM_FREQ_MHz, 0.2f, 0.1f);
		// initialize the speed reference trajectory
		obj->trajHandle_spd = &traj_spd[motorNum];

		// configure the speed reference trajectory (Hz)
		TRAJ_setTargetValue(obj->trajHandle_spd, 0.0f);
		TRAJ_setIntValue(obj->trajHandle_spd, 0.0f);
		TRAJ_setMinValue(obj->trajHandle_spd, -objUser->maxFrequency_Hz);
		TRAJ_setMaxValue(obj->trajHandle_spd, objUser->maxFrequency_Hz);
		TRAJ_setMaxDelta(obj->trajHandle_spd, (objUser->maxAccel_Hzps / objUser->ctrlFreq_Hz));

		// turn on the DRV8323/DRV8353/DRV8316 if present
		HAL_enableDRV(obj->halMtrHandle);

		// initialize the DRV8323/DRV8353/DRV8316 interface
		HAL_setupDRVSPI(obj->halMtrHandle, &drvicVars[MTR_2]);

		drvicVars[MTR_2].ctrlReg02.bit.OTW_REP = true;
		drvicVars[MTR_2].ctrlReg02.bit.PWM_MODE = DRV8323_PWMMODE_6;

		drvicVars[MTR_2].ctrlReg05.bit.VDS_LVL = DRV8323_VDS_LEVEL_1P700_V;
		drvicVars[MTR_2].ctrlReg05.bit.OCP_MODE = DRV8323_AUTOMATIC_RETRY;
		drvicVars[MTR_2].ctrlReg05.bit.DEAD_TIME = DRV8323_DEADTIME_100_NS;
		drvicVars[MTR_2].ctrlReg06.bit.CSA_GAIN = DRV8323_Gain_10VpV;

		drvicVars[MTR_2].ctrlReg06.bit.LS_REF = false;
		drvicVars[MTR_2].ctrlReg06.bit.VREF_DIV = true;
		drvicVars[MTR_2].ctrlReg06.bit.CSA_FET = false;

		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);

		drvicVars[motorNum].writeCmd = 1;
		HAL_writeDRVData(obj->halMtrHandle, &drvicVars[motorNum]);

		HAL_readDRVData(obj->halMtrHandle, &drvicVars[motorNum]);

		// set the default estimator parameters
		EST_setParams(obj->estHandle, obj->userParamsHandle);
		EST_setFlag_enableForceAngle(obj->estHandle,obj->flagEnableForceAngle);
		EST_setFlag_enableRsRecalc(obj->estHandle,obj->flagEnableRsRecalc);
		EST_setOneOverFluxGain_sf(obj->estHandle,
									  obj->userParamsHandle, USER_M2_EST_FLUX_HF_SF);
		EST_setFreqLFP_sf(obj->estHandle, obj->userParamsHandle, USER_M2_EST_FREQ_HF_SF);
		EST_setBemf_sf(obj->estHandle,
					   obj->userParamsHandle, USER_M2_EST_BEMF_HF_SF);


		// if motor is an induction motor, configure default state of PowerWarp
		if(objUser->motor_type == MOTOR_TYPE_INDUCTION)
		{
			EST_setFlag_enablePowerWarp(obj->estHandle, obj->flagEnablePowerWarp);
			EST_setFlag_bypassLockRotor(obj->estHandle, obj->flagBypassLockRotor);
		}

		// for Rs online calibration
		obj->flagRsOnLineContinue = false;
		obj->flagStartRsOnLine = false;

		objSets->RsOnlineWaitTimeSet = USER_MOTOR2_RSONLINE_WAIT_TIME;
		objSets->RsOnlineWorkTimeSet = USER_MOTOR2_RSONLINE_WORK_TIME;

		// setup the controllers, speed, d/q-axis current pid regulator
		setupControllers(handle);

		// setup faults
		HAL_setupMtrFaults(obj->halMtrHandle, motorNum);

		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);
	}
    return;
}

void runMotorOffsetsCalculation(MOTOR_Handle handle, const MotorNum_e motorNum)
{
	MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
	MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);

	// calculate motor and pfc protection value
	calcMotorOverCurrentThreshold(handle);

	HAL_setMtrCMPSSDACValue(obj->halMtrHandle,
							objSets->dacCMPValH, objSets->dacCMPValL);

	if(motorNum == MTR_1)
	{
//		ADC_setPPBReferenceOffset(MTR1_IU_ADC_BASE, MTR1_IU_ADC_PPB_NUM,
//				(uint32_t)USER_M1_IA_OFFSET_AD);
//
//		ADC_setPPBReferenceOffset(MTR1_IV_ADC_BASE, MTR1_IV_ADC_PPB_NUM,
//				(uint32_t)USER_M1_IB_OFFSET_AD);
//
//		ADC_setPPBReferenceOffset(MTR1_IW_ADC_BASE, MTR1_IW_ADC_PPB_NUM,
//				(uint32_t)USER_M1_IC_OFFSET_AD);

		obj->adcData.offset_I_ad.value[0]  =  USER_M1_IA_OFFSET_AD ;
		obj->adcData.offset_I_ad.value[1]  =  USER_M1_IB_OFFSET_AD ;
		obj->adcData.offset_I_ad.value[2]  =  USER_M1_IC_OFFSET_AD ;

		// Offsets in phase voltage sensing
		obj->adcData.offset_V_sf.value[0]  =  USER_M1_VA_OFFSET_SF;
		obj->adcData.offset_V_sf.value[1]  =  USER_M1_VB_OFFSET_SF;
		obj->adcData.offset_V_sf.value[2]  =  USER_M1_VC_OFFSET_SF;
	}
	else if(motorNum == MTR_2)
	{
//		ADC_setPPBReferenceOffset(MTR2_IU_ADC_BASE, MTR2_IU_ADC_PPB_NUM,
//				(uint32_t)USER_M2_IA_OFFSET_AD);
//
//		ADC_setPPBReferenceOffset(MTR2_IV_ADC_BASE, MTR2_IV_ADC_PPB_NUM,
//				(uint32_t)USER_M2_IB_OFFSET_AD);
//
//		ADC_setPPBReferenceOffset(MTR2_IW_ADC_BASE, MTR2_IW_ADC_PPB_NUM,
//				(uint32_t)USER_M2_IC_OFFSET_AD);

		obj->adcData.offset_I_ad.value[0]  =  USER_M2_IA_OFFSET_AD ;
		obj->adcData.offset_I_ad.value[1]  =  USER_M2_IB_OFFSET_AD ;
		obj->adcData.offset_I_ad.value[2]  =  USER_M2_IC_OFFSET_AD ;

		// Offsets in phase voltage sensing
		obj->adcData.offset_V_sf.value[0]  =  USER_M2_VA_OFFSET_SF;
		obj->adcData.offset_V_sf.value[1]  =  USER_M2_VB_OFFSET_SF;
		obj->adcData.offset_V_sf.value[2]  =  USER_M2_VC_OFFSET_SF;
	}

		if(obj->flagEnableOffsetCalc == true)
		{
			float32_t offsetK1 = 0.998001f;  // Offset filter coefficient K1: 0.05/(T+0.05);
			float32_t offsetK2 = 0.001999f;  // Offset filter coefficient K2: T/(T+0.05);
			float32_t invCurrentSf = 1.0f / obj->adcData.current_sf;

			float32_t invVdcbus;

			uint16_t offsetCnt;

			SysCtl_delay(50U);

			if(motorNum == MTR_1)
			{
//				ADC_setPPBReferenceOffset(MTR1_IU_ADC_BASE, MTR1_IU_ADC_PPB_NUM, 0);
//				ADC_setPPBReferenceOffset(MTR1_IV_ADC_BASE, MTR1_IV_ADC_PPB_NUM, 0);
//				ADC_setPPBReferenceOffset(MTR1_IW_ADC_BASE, MTR1_IW_ADC_PPB_NUM, 0);
			}
			else if(motorNum == MTR_2)
			{
//				ADC_setPPBReferenceOffset(MTR2_IU_ADC_BASE, MTR2_IU_ADC_PPB_NUM, 0);
//				ADC_setPPBReferenceOffset(MTR2_IV_ADC_BASE, MTR2_IV_ADC_PPB_NUM, 0);
//				ADC_setPPBReferenceOffset(MTR2_IW_ADC_BASE, MTR2_IW_ADC_PPB_NUM, 0);
			}

			obj->adcData.offset_I_ad.value[0] =
					 obj->adcData.offset_I_ad.value[0] * obj->adcData.current_sf;
			obj->adcData.offset_I_ad.value[1] =
					 obj->adcData.offset_I_ad.value[1] * obj->adcData.current_sf;
			obj->adcData.offset_I_ad.value[2] =
					 obj->adcData.offset_I_ad.value[2] * obj->adcData.current_sf;

			// Set the 3-phase output PWMs to 50% duty cycle
			obj->pwmData.Vabc_pu.value[0] = 0.0f;
			obj->pwmData.Vabc_pu.value[1] = 0.0f;
			obj->pwmData.Vabc_pu.value[2] = 0.0f;

			// write the PWM compare values
			HAL_writePWMData(obj->halMtrHandle, &obj->pwmData);

			// enable the PWM
			HAL_enablePWM(obj->halMtrHandle);

			for(offsetCnt = 0; offsetCnt < 32000; offsetCnt++)
			{
				// clear the ADC interrupt flag
				ADC_clearInterruptStatus(MTR1_ADC_INT_BASE, MTR1_ADC_INT_NUM);

				while(ADC_getInterruptStatus(MTR1_ADC_INT_BASE, MTR1_ADC_INT_NUM) == false);

				if(motorNum == MTR_1)
				{
					HAL_readADCData(&obj->adcData, MTR_1);
				}
				else if(motorNum == MTR_2)
				{
					HAL_readADCData(&obj->adcData, MTR_2);
				}
				if(offsetCnt >= 2000)       // Ignore the first 2000 times
				{
					// Offsets in phase current sensing

					obj->adcData.offset_I_ad.value[0] =
							offsetK1 * obj->adcData.offset_I_ad.value[0] +
							obj->adcData.I_A.value[0] * offsetK2;

					obj->adcData.offset_I_ad.value[1] =
							offsetK1 * obj->adcData.offset_I_ad.value[1] +
							obj->adcData.I_A.value[1] * offsetK2;

					obj->adcData.offset_I_ad.value[2] =
							offsetK1 * obj->adcData.offset_I_ad.value[2] +
							obj->adcData.I_A.value[2] * offsetK2;

					invVdcbus = 1.0f / obj->adcData.VdcBus_V;

					// Offsets in phase voltage sensing
					obj->adcData.offset_V_sf.value[0] =
							 offsetK1 * obj->adcData.offset_V_sf.value[0] +
							 (invVdcbus * obj->adcData.V_V.value[0]) * offsetK2;

					obj->adcData.offset_V_sf.value[1] =
							 offsetK1 * obj->adcData.offset_V_sf.value[1] +
							 (invVdcbus * obj->adcData.V_V.value[1]) * offsetK2;

					obj->adcData.offset_V_sf.value[2] =
							 offsetK1 * obj->adcData.offset_V_sf.value[2] +
							 (invVdcbus * obj->adcData.V_V.value[2]) * offsetK2;
				}
				else
				{
					// enable the PWM
					HAL_enablePWM(obj->halMtrHandle);
				}
			} // for()

			// disable the PWM
			HAL_disablePWM(obj->halMtrHandle);

			obj->flagEnableOffsetCalc = false;

			obj->adcData.offset_I_ad.value[0] =
					 obj->adcData.offset_I_ad.value[0] * invCurrentSf;
			obj->adcData.offset_I_ad.value[1] =
					 obj->adcData.offset_I_ad.value[1] * invCurrentSf;
			obj->adcData.offset_I_ad.value[2] =
					 obj->adcData.offset_I_ad.value[2] * invCurrentSf;
			if(motorNum == MTR_1)
			{
				ADC_setPPBReferenceOffset(MTR1_IU_ADC_BASE, MTR1_IU_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[0]);

				ADC_setPPBReferenceOffset(MTR1_IV_ADC_BASE, MTR1_IV_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[1]);

				ADC_setPPBReferenceOffset(MTR1_IW_ADC_BASE, MTR1_IW_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[2]);
			}
			else if(motorNum == MTR_2)
			{
				ADC_setPPBReferenceOffset(MTR2_IU_ADC_BASE, MTR2_IU_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[0]);

				ADC_setPPBReferenceOffset(MTR2_IV_ADC_BASE, MTR2_IV_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[1]);

				ADC_setPPBReferenceOffset(MTR2_IW_ADC_BASE, MTR2_IW_ADC_PPB_NUM,
										  (uint16_t)obj->adcData.offset_I_ad.value[2]);
			}
		}   // flagEnableOffsetCalc = true

		// Check current and voltage offset
		if(motorNum == MTR_1)
		{
			if( (obj->adcData.offset_I_ad.value[0] > USER_M1_IA_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[0] < USER_M1_IA_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_I_ad.value[1] > USER_M1_IB_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[1] < USER_M1_IB_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_I_ad.value[2] > USER_M1_IC_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[2] < USER_M1_IC_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[0] > USER_M1_VA_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[0] < USER_M1_VA_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[1] > USER_M1_VB_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[1] < USER_M1_VB_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[2] > USER_M1_VC_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[2] < USER_M1_VC_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}
		}
		else if(motorNum == MTR_2)
		{
			if( (obj->adcData.offset_I_ad.value[0] > USER_M2_IA_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[0] < USER_M2_IA_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_I_ad.value[1] > USER_M2_IB_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[1] < USER_M2_IB_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_I_ad.value[2] > USER_M2_IC_OFFSET_AD_MAX) ||
				(obj->adcData.offset_I_ad.value[2] < USER_M2_IC_OFFSET_AD_MIN) )
			{
				obj->faultMtrNow.bit.currentOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[0] > USER_M2_VA_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[0] < USER_M2_VA_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[1] > USER_M2_VB_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[1] < USER_M2_VB_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}

			if( (obj->adcData.offset_V_sf.value[2] > USER_M2_VC_OFFSET_SF_MAX) ||
				(obj->adcData.offset_V_sf.value[2] < USER_M2_VC_OFFSET_SF_MIN) )
			{
				obj->faultMtrNow.bit.voltageOffset = 1;
			}
		}
    return;
}

void runMotorControl(MOTOR_Handle handle)
{
	MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
	MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);
	USER_Params *objUser = (USER_Params *)(handle->userParamsHandle);

	if(HAL_getPwmEnableStatus(obj->halMtrHandle) == true)
	{
		if(HAL_getMtrTripFaults(obj->halMtrHandle) != 0)
		{
			obj->faultMtrNow.bit.moduleOverCurrent = 1;
		}
	}

	obj->faultMtrPrev.all |= obj->faultMtrNow.all;
	obj->faultMtrUse.all = obj->faultMtrNow.all & obj->faultMtrMask.all;

	HAL_setMtrCMPSSDACValue(obj->halMtrHandle,
							objSets->dacCMPValH, objSets->dacCMPValL);

	if(obj->flagEnableRunAndIdentify == true)
	{
		// Had some faults to stop the motor
		if(obj->faultMtrUse.all != 0)
		{
			if(obj->flagRunIdentAndOnLine == true)
			{
				obj->flagRunIdentAndOnLine = false;
				obj->mctrlState = MCTRL_FAULT_STOP;

				obj->stopWaitTimeCnt = objSets->restartWaitTimeSet;
				obj->restartTimesCnt++;

				if(obj->flagEnableRestart == false)
				{
					obj->flagEnableRunAndIdentify = false;
					obj->stopWaitTimeCnt = 0;
				}
			}
			else if(obj->stopWaitTimeCnt == 0)
			{
				if(obj->restartTimesCnt < objSets->restartTimesSet)
				{
					obj->flagClearFaults = 1;
				}
				else
				{
					obj->flagEnableRunAndIdentify = false;
				}
			}
		}
		// Restart
		else if((obj->flagRunIdentAndOnLine == false) &&
				(obj->stopWaitTimeCnt == 0))
		{
			if(obj->flagEnableMotorIdentify == true)
			{
				obj->flagMotorIdentified = false;
				obj->flagSetupController = false;
				obj->svmMode = SVM_COM_C;
				obj->flagEnableFWC = false;
				obj->flagEnableMTPA = false;

				obj->speedRef_Hz = objUser->fluxExcFreq_Hz;

				objUser->flag_bypassMotorId = false;
				// disable interrupts
				DINT;
				__asm("  NOP");
				// set the default estimator parameters
				EST_setParams(obj->estHandle, obj->userParamsHandle);
				// enable interrupts
				EINT;
				__asm("  NOP");
				obj->flagEnableMotorIdentify = false;
			}
		restartMotorControl(handle);
		}
	}
	// if(obj->flagEnableRunAndIdentify == false)
	else if(obj->flagRunIdentAndOnLine == true)
	{
		stopMotorControl(handle);

		if(obj->flagEnableFlyingStart == false)
		{
			obj->stopWaitTimeCnt = objSets->stopWaitTimeSet;
		}
		else
		{
			obj->stopWaitTimeCnt = 0;
		}
	}
	else
	{

	}
	// enable or disable bypassLockRotor flag
	if((objUser->motor_type == MOTOR_TYPE_INDUCTION)
		&& (obj->flagMotorIdentified == true))
	{
		EST_setFlag_bypassLockRotor(obj->estHandle,obj->flagBypassLockRotor);
	}

	if(obj->flagClearFaults == true)
	{
		HAL_clearMtrFaultStatus(obj->halMtrHandle);

		obj->faultMtrNow.all &= MTR_FAULT_CLEAR;
		obj->flagClearFaults = false;
	}

	if(obj->flagRunIdentAndOnLine == true)
	{
		if(HAL_getPwmEnableStatus(obj->halMtrHandle) == false)
		{
			// enable the estimator
			EST_enable(obj->estHandle);

			// enable the trajectory generator
			EST_enableTraj(obj->estHandle);

			// enable the PWM
			HAL_enablePWM(obj->halMtrHandle);
		}

		if(obj->flagMotorIdentified == true)
		{
			if(obj->speedRef_Hz > 0.0f)
			{
				obj->direction = 1.0f;
			}
			else
			{
				obj->direction = -1.0f;
			}

			// enable or disable force angle
			EST_setFlag_enableForceAngle(obj->estHandle,
										 obj->flagEnableForceAngle);

			EST_setFlag_enableRsRecalc(obj->estHandle,
									   obj->flagEnableRsRecalc);

			TRAJ_setTargetValue(obj->trajHandle_spd, obj->speedRef_Hz);

			if(fabsf(obj->speed_Hz) > obj->speedStart_Hz)
			{
				TRAJ_setMaxDelta(obj->trajHandle_spd,
				  (obj->accelerationMax_Hzps / objUser->ctrlFreq_Hz));

				PI_setMinMax(obj->piHandle_spd, -obj->maxCurrent_A, obj->maxCurrent_A);

				SVGEN_setMode(obj->svgenHandle, obj->svmMode);

				if(obj->motorState >= MOTOR_CL_RUNNING)
				{
					obj->stateRunTimeCnt++;

					if(obj->stateRunTimeCnt == obj->fwcTimeDelay)
					{
						obj->Idq_out_A.value[0] = 0.0f;
						obj->motorState = MOTOR_CTRL_RUN;
						obj->mctrlState = MCTRL_CONT_RUN;
					}
				}
			}
			else
			{
				TRAJ_setMaxDelta(obj->trajHandle_spd,
				  (obj->accelerationStart_Hzps / objUser->ctrlFreq_Hz));

				if(obj->speed_int_Hz >= 0.0f)
				{
					PI_setMinMax(obj->piHandle_spd, -obj->startCurrent_A, obj->startCurrent_A);
				}
				else
				{
					PI_setMinMax(obj->piHandle_spd, -obj->startCurrent_A, obj->startCurrent_A);
				}

			}
		}

	}
    else
    {
    	// reset motor control parameters
    	resetMotorControl(handle);
    }

	// check the trajectory generator
	if(EST_isTrajError(obj->estHandle) == true)
	{
		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);
	}
	else
	{
		// update the trajectory generator state
		EST_updateTrajState(obj->estHandle);
	}

	// check the estimator
	if(EST_isError(obj->estHandle) == true)
	{
		// disable the PWM
		HAL_disablePWM(obj->halMtrHandle);
	}
	else        // No any estimator error
	{
		bool flagEstStateChanged = false;

		float32_t Id_target_A = EST_getIntValue_Id_A(obj->estHandle);

		if(obj->flagMotorIdentified == true)
		{
			flagEstStateChanged = EST_updateState(obj->estHandle, 0.0f);
		}
		else
		{
			flagEstStateChanged = EST_updateState(obj->estHandle, Id_target_A);
		}

		if(flagEstStateChanged == true)
		{
			// configure the trajectory generator
			EST_configureTraj(obj->estHandle);

			if(obj->flagMotorIdentified == false)
			{
				// configure the controllers
				EST_configureTrajState(obj->estHandle, obj->userParamsHandle,
										 obj->piHandle_spd,
										 obj->piHandle_Id, obj->piHandle_Iq);
			}

			if(objUser->flag_bypassMotorId == false)
			{
				if((EST_isLockRotor(obj->estHandle) == true) ||
										( (EST_isMotorIdentified(obj->estHandle) == true)
												  && (EST_isIdle(obj->estHandle) == true) ) )
				{
					if(EST_isMotorIdentified(obj->estHandle) == true)
					{
						obj->flagMotorIdentified = true;

						// clear the flag
						obj->flagRunIdentAndOnLine = false;
						obj->flagEnableRunAndIdentify = false;
						objUser->flag_bypassMotorId = true;

						// disable the estimator
						EST_disable(obj->estHandle);

						// enable the trajectory generator
						EST_disableTraj(obj->estHandle);
					}

					if(objUser->motor_type == MOTOR_TYPE_INDUCTION)
					{
						// clear the flag
						obj->flagRunIdentAndOnLine = false;
						obj->flagEnableRunAndIdentify = false;
					}
				}
			}
		}
	}

	obj->flagMotorIdentified = EST_isMotorIdentified(obj->estHandle);

	if(obj->flagMotorIdentified == true)
	{
		if(obj->flagSetupController == true)
		{
			// update the controller
			updateControllers(handle);
		}
		else
		{
			obj->flagSetupController = true;

			setupControllers(handle);
		}
	}

	// run Rs online
	runRsOnLine(handle);
	// update the global variables
	updateGlobalVariables(handle);

	return;
}


extern float32_t Iuvw[6];
extern float32_t Vuvw[8];
MotorNum_e isrNum = MTR_1;
__interrupt CODE_SECTION( "ramfuncs") void MainCtrlISR(void)
{

	motorVars[MTR_1].ISRCount++;
	motorVars[MTR_2].ISRCount++;

    MOTOR_Vars_t *obj[2] = {(MOTOR_Vars_t *)motorHandle[MTR_1], (MOTOR_Vars_t *)motorHandle[MTR_2]};
    USER_Params *objUser[2] = {(USER_Params *)(obj[MTR_1]->userParamsHandle), (USER_Params *)(obj[MTR_2]->userParamsHandle)};

    // acknowledge the ADC interrupt
    HAL_ackADCInt();

    for(isrNum = MTR_1; isrNum <= MTR_2; isrNum++)
    {
		HAL_readADCData(&obj[isrNum]->adcData, isrNum);
		obj[isrNum]->adcData.I_A.value[0] -= obj[isrNum]->adcData.offset_I_ad.value[0] * obj[isrNum]->adcData.current_sf;
		obj[isrNum]->adcData.I_A.value[1] -= obj[isrNum]->adcData.offset_I_ad.value[1] * obj[isrNum]->adcData.current_sf;
		obj[isrNum]->adcData.I_A.value[2] -= obj[isrNum]->adcData.offset_I_ad.value[2] * obj[isrNum]->adcData.current_sf;

//	    Vuvw[6] = (float32_t)ADC_readResult(ADCCRESULT_BASE, MTR2_VW_ADC_SOC_NUM);

		// remove offsets
		obj[isrNum]->adcData.V_V.value[0] -=
				obj[isrNum]->adcData.offset_V_sf.value[0] * obj[isrNum]->adcData.VdcBus_V;

		obj[isrNum]->adcData.V_V.value[1] -=
				obj[isrNum]->adcData.offset_V_sf.value[1] * obj[isrNum]->adcData.VdcBus_V;

		obj[isrNum]->adcData.V_V.value[2] -=
				obj[isrNum]->adcData.offset_V_sf.value[2] * obj[isrNum]->adcData.VdcBus_V;

    }

    for(isrNum = MTR_1; isrNum <= MTR_2; isrNum++)
    {
    	MATH_Vec2 phasor;

        CLARKE_run(obj[isrNum]->clarkeHandle_V,
                   &obj[isrNum]->adcData.V_V, &obj[isrNum]->estInputData.Vab_V);
        CLARKE_run(obj[isrNum]->clarkeHandle_I, &obj[isrNum]->adcData.I_A, &obj[isrNum]->estInputData.Iab_A);

        if(((EST_isMotorIdentified(obj[isrNum]->estHandle) == false) ||
            (EST_getState(obj[isrNum]->estHandle) == EST_STATE_RS)) &&
            (EST_isEnabled(obj[isrNum]->estHandle) == true))
        {
        	// run identification or Rs Recalibration
        	// setup the trajectory generator
        	EST_setupTrajState(obj[isrNum]->estHandle,
                               obj[isrNum]->Idq_out_A.value[1],
                               obj[isrNum]->speedRef_Hz,
                               0.0);

            // run the trajectories
            EST_runTraj(obj[isrNum]->estHandle);

            obj[isrNum]->IdRated_A = EST_getIntValue_Id_A(obj[isrNum]->estHandle);

            // store the input data into a buffer
            obj[isrNum]->estInputData.speed_ref_Hz = EST_getIntValue_spd_Hz(obj[isrNum]->estHandle);
            obj[isrNum]->speed_int_Hz = obj[isrNum]->estInputData.speed_ref_Hz;

            obj[isrNum]->enableSpeedCtrl = EST_doSpeedCtrl(obj[isrNum]->estHandle);
            obj[isrNum]->enableCurrentCtrl = EST_doCurrentCtrl(obj[isrNum]->estHandle);

            obj[isrNum]->motorState = MOTOR_CTRL_RUN;
        }
        else if(obj[isrNum]->flagMotorIdentified == true)   // Normal Running
        {
            if(obj[isrNum]->flagRunIdentAndOnLine == true)
            {
                obj[isrNum]->counterTrajSpeed++;

                if(obj[isrNum]->counterTrajSpeed >= objUser[isrNum]->numIsrTicksPerTrajTick)
                {
                    // clear counter
                    obj[isrNum]->counterTrajSpeed = 0;

                    // run a trajectory for speed reference,
                    // so the reference changes with a ramp instead of a step
                    TRAJ_run(obj[isrNum]->trajHandle_spd);
                }

                obj[isrNum]->enableCurrentCtrl = obj[isrNum]->flagEnableCurrentCtrl;
                obj[isrNum]->enableSpeedCtrl = obj[isrNum]->flagEnableSpeedCtrl;

                // get Id reference for Rs OnLine
                obj[isrNum]->IdRated_A = EST_getIdRated_A(obj[isrNum]->estHandle);
            }
            else
            {
                obj[isrNum]->enableSpeedCtrl = false;
                obj[isrNum]->enableCurrentCtrl = false;
            }
            obj[isrNum]->estInputData.speed_ref_Hz = TRAJ_getIntValue(obj[isrNum]->trajHandle_spd);
            obj[isrNum]->speed_int_Hz = obj[isrNum]->estInputData.speed_ref_Hz;
        }

        // store the input data into a buffer
        obj[isrNum]->estInputData.dcBus_V = obj[isrNum]->adcData.VdcBus_V;
        EST_run(obj[isrNum]->estHandle, &obj[isrNum]->estInputData, &obj[isrNum]->estOutputData);

        // compute angle with delay compensation
        obj[isrNum]->angleDelta_rad =
                objUser[isrNum]->angleDelayed_sf_sec * obj[isrNum]->estOutputData.fm_lp_rps;

        obj[isrNum]->angleEST_rad =
                MATH_incrAngle(obj[isrNum]->estOutputData.angle_rad, obj[isrNum]->angleDelta_rad);

        obj[isrNum]->speedEST_Hz = EST_getFm_lp_Hz(obj[isrNum]->estHandle);
        obj[isrNum]->speed_Hz = obj[isrNum]->speedEST_Hz;

        obj[isrNum]->speedFilter_Hz = obj[isrNum]->speedFilter_Hz *0.875f + obj[isrNum]->speed_Hz * 0.125f;
        obj[isrNum]->speedAbs_Hz = fabsf(obj[isrNum]->speedFilter_Hz);

        obj[isrNum]->oneOverDcBus_invV = obj[isrNum]->estOutputData.oneOverDcBus_invV;

        // Running state
        if(obj[isrNum]->motorState >= MOTOR_CL_RUNNING)
        {
            obj[isrNum]->angleFOC_rad = obj[isrNum]->angleEST_rad;
        }
        else if(obj[isrNum]->motorState == MOTOR_OL_START)
        {
            obj[isrNum]->angleFOC_rad = obj[isrNum]->angleEST_rad;
            obj[isrNum]->motorState = MOTOR_CL_RUNNING;
        }
        else if(obj[isrNum]->motorState == MOTOR_ALIGNMENT)
        {
            obj[isrNum]->angleFOC_rad = 0.0f;
            obj[isrNum]->enableSpeedCtrl = false;

            obj[isrNum]->stateRunTimeCnt++;

            obj[isrNum]->IsRef_A = 0.0f;
            obj[isrNum]->Idq_out_A.value[0] = obj[isrNum]->alignCurrent_A;
            obj[isrNum]->Idq_out_A.value[1] = 0.0f;

            TRAJ_setIntValue(obj[isrNum]->trajHandle_spd, 0.0f);

            if((obj[isrNum]->stateRunTimeCnt > obj[isrNum]->alignTimeDelay) ||
                     (obj[isrNum]->flagEnableAlignment == false))
            {
                obj[isrNum]->stateRunTimeCnt = 0;
                obj[isrNum]->motorState = MOTOR_OL_START;
                obj[isrNum]->Idq_out_A.value[0] = obj[isrNum]->fluxCurrent_A;

                EST_setAngle_rad(obj[isrNum]->estHandle, obj[isrNum]->angleFOC_rad);
                PI_setUi(obj[isrNum]->piHandle_spd, 0.0);
            }
        }
        else if(obj[isrNum]->motorState == MOTOR_SEEK_POS)
        {
            obj[isrNum]->enableSpeedCtrl = false;

            obj[isrNum]->stateRunTimeCnt++;

            obj[isrNum]->IsRef_A = 0.0f;
            obj[isrNum]->Idq_out_A.value[0] = 0.0f;
            obj[isrNum]->Idq_out_A.value[1] = 0.0f;

            obj[isrNum]->angleFOC_rad = obj[isrNum]->angleEST_rad;

            if(obj[isrNum]->stateRunTimeCnt > obj[isrNum]->flyingStartTimeDelay)
            {
                obj[isrNum]->stateRunTimeCnt = 0;

                if(obj[isrNum]->speedAbs_Hz > obj[isrNum]->speedFlyingStart_Hz)
                {
                    obj[isrNum]->speed_int_Hz = obj[isrNum]->speedFilter_Hz;
                    TRAJ_setIntValue(obj[isrNum]->trajHandle_spd, obj[isrNum]->speedFilter_Hz);
                    PI_setUi(obj[isrNum]->piHandle_spd, 0.0f);

                    obj[isrNum]->motorState = MOTOR_CL_RUNNING;
                }
                else
                {
                    obj[isrNum]->motorState = MOTOR_ALIGNMENT;
                }
            }
        }

        // compute the sin/cos phasor
        phasor.value[0] = __cos(obj[isrNum]->angleFOC_rad);
        phasor.value[1] = __sin(obj[isrNum]->angleFOC_rad);

        // set the phasor in the Park transform
        PARK_setPhasor(obj[isrNum]->parkHandle_I, &phasor);

        // run the Park transform
        PARK_run(obj[isrNum]->parkHandle_I, &(obj[isrNum]->estInputData.Iab_A),
                 (MATH_vec2 *)&(obj[isrNum]->Idq_in_A));
        // run the speed controller
        obj[isrNum]->counterSpeed++;

        if(obj[isrNum]->counterSpeed >= objUser[isrNum]->numCtrlTicksPerSpeedTick)
        {
            obj[isrNum]->counterSpeed = 0;

            if(obj[isrNum]->enableSpeedCtrl == true)
            {
                PI_run(obj[isrNum]->piHandle_spd,
                       obj[isrNum]->speed_int_Hz,
                       obj[isrNum]->speed_Hz,
                       (float32_t *)&obj[isrNum]->IsRef_A);
            }
            else if((obj[isrNum]->motorState >= MOTOR_CL_RUNNING) &&
                    (obj[isrNum]->flagMotorIdentified == true))
            {
                if(obj[isrNum]->speed_int_Hz > 0.0f)
                {
                    obj[isrNum]->IsRef_A = obj[isrNum]->IsSet_A;
                }
                else
                {
                    obj[isrNum]->IsRef_A = -obj[isrNum]->IsSet_A;
                }

                // for switching back speed closed-loop control
                PI_setUi(obj[isrNum]->piHandle_spd, obj[isrNum]->IsRef_A);
            }
        }

        obj[isrNum]->Idq_out_A.value[1] = obj[isrNum]->IsRef_A;
        obj[isrNum]->IdqRef_A.value[0] = obj[isrNum]->Idq_out_A.value[0] + obj[isrNum]->IdRated_A;
        EST_updateId_ref_A(obj[isrNum]->estHandle, &obj[isrNum]->IdqRef_A.value[0]);
        obj[isrNum]->IdqRef_A.value[1] = obj[isrNum]->Idq_out_A.value[1];

        if(obj[isrNum]->enableCurrentCtrl == true)
        {
            // Maximum voltage output
            objUser[isrNum]->maxVsMag_V =
                    objUser[isrNum]->maxVsMag_pu * obj[isrNum]->adcData.VdcBus_V;

            PI_setMinMax(obj[isrNum]->piHandle_Id,
                         -objUser[isrNum]->maxVsMag_V, objUser[isrNum]->maxVsMag_V);

            PI_run(obj[isrNum]->piHandle_Id, obj[isrNum]->IdqRef_A.value[0],
                   obj[isrNum]->Idq_in_A.value[0], (float32_t*)&obj[isrNum]->Vdq_out_V.value[0]);
            // calculate Iq controller limits
            float32_t outMax_V = __sqrt((objUser[isrNum]->maxVsMag_V * objUser[isrNum]->maxVsMag_V) -
                              (obj[isrNum]->Vdq_out_V.value[0] * obj[isrNum]->Vdq_out_V.value[0]));

            PI_setMinMax(obj[isrNum]->piHandle_Iq, -outMax_V, outMax_V);

            PI_run(obj[isrNum]->piHandle_Iq, obj[isrNum]->IdqRef_A.value[1],
                   obj[isrNum]->Idq_in_A.value[1], (float32_t*)&obj[isrNum]->Vdq_out_V.value[1]);
        }

        // set the phasor in the inverse Park transform
        IPARK_setPhasor(obj[isrNum]->iparkHandle_V, &phasor);

        // run the inverse Park module
        IPARK_run(obj[isrNum]->iparkHandle_V,
                  &obj[isrNum]->Vdq_out_V, &obj[isrNum]->Vab_out_V);

        // setup the space vector generator (SVGEN) module
        SVGEN_setup(obj[isrNum]->svgenHandle,
                    obj[isrNum]->oneOverDcBus_invV);

        // run the space vector generator (SVGEN) module
        SVGEN_run(obj[isrNum]->svgenHandle,
                  &obj[isrNum]->Vab_out_V, &(obj[isrNum]->pwmData.Vabc_pu));

        if(HAL_getPwmEnableStatus(obj[isrNum]->halMtrHandle) == false)
        {
            // clear PWM data
            obj[isrNum]->pwmData.Vabc_pu.value[0] = 0.0f;
            obj[isrNum]->pwmData.Vabc_pu.value[1] = 0.0f;
            obj[isrNum]->pwmData.Vabc_pu.value[2] = 0.0f;
        }

        // write the PWM compare values
        HAL_writePWMData(obj[isrNum]->halMtrHandle, &obj[isrNum]->pwmData);
        // Collect current and voltage data to calculate the RMS value
        collectRMSData(obj[isrNum]);
    }

    return;
}
