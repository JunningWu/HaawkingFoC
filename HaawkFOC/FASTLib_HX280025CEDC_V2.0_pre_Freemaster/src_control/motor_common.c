#include "motor_common.h"

HAL_Handle    halHandle;      //!< the handle for the hardware abstraction layer
HAL_Obj       hal;            //!< the hardware abstraction layer object

static inline void
CLARKE_setNumSensors(CLARKE_Handle handle, const uint_least8_t numSensors)
{
    CLARKE_Obj *obj = (CLARKE_Obj *)handle;

    obj->numSensors = numSensors;

    return;
} // end of CLARKE_setNumSensors() function

static inline void
CLARKE_setScaleFactors(CLARKE_Handle handle, const float32_t alpha_sf,
                       const float32_t beta_sf)
{
    CLARKE_Obj *obj = (CLARKE_Obj *)handle;

    obj->alpha_sf = alpha_sf;
    obj->beta_sf = beta_sf;

    return;
} // end of CLARKE_setScaleFactors() function

//! \brief     Sets the number of voltage sensors
//! \param[in] handle             The Clarke (CLARKE) handle
//! \param[in] numVoltageSensors  The number of voltage sensors
void setupClarke_V(CLARKE_Handle handle,const uint16_t numVoltageSensors)
{
    float32_t alpha_sf,beta_sf;

    // initialize the Clarke transform module for voltage
    if(numVoltageSensors == 3)
    {
        alpha_sf = MATH_ONE_OVER_THREE;
        beta_sf = MATH_ONE_OVER_SQRT_THREE;
    }
    else
    {
        alpha_sf = 0.0f;
        beta_sf = 0.0f;
    }

    // set the parameters
    CLARKE_setScaleFactors(handle, alpha_sf, beta_sf);
    CLARKE_setNumSensors(handle, numVoltageSensors);

    return;
} // end of setupClarke_V() function

//! \brief     Sets the number of current sensors
//! \param[in] handle             The Clarke (CLARKE) handle
//! \param[in] numCurrentSensors  The number of current sensors
void setupClarke_I(CLARKE_Handle handle, const uint16_t numCurrentSensors)
{
    float32_t alpha_sf, beta_sf;

    // initialize the Clarke transform module for current
    if(3 == numCurrentSensors)
    {
        alpha_sf = MATH_ONE_OVER_THREE;
        beta_sf = MATH_ONE_OVER_SQRT_THREE;
    }
    else if(2 == numCurrentSensors)
    {
        alpha_sf = 1.0f;
        beta_sf = MATH_ONE_OVER_SQRT_THREE;
    }
    else
    {
        alpha_sf = 0.0f;
        beta_sf = 0.0f;
    }

    // set the parameters
    CLARKE_setScaleFactors(handle, alpha_sf, beta_sf);
    CLARKE_setNumSensors(handle, numCurrentSensors);

    return;
} // end of setupClarke_I() function

// Resets motor control parameters for restarting motor
void resetMotorControl(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

    if(obj->flagEnableFlyingStart == false)
    {

        // disable the estimator
        EST_disable(obj->estHandle);

        // disable the trajectory generator
        EST_disableTraj(obj->estHandle);

        TRAJ_setIntValue(obj->trajHandle_spd, 0.0f);
    }
    else
    {
        TRAJ_setIntValue(obj->trajHandle_spd, obj->speed_Hz);

        obj->stateRunTimeCnt = 0;
        obj->flagStateFlyingStart = false;
    }

    TRAJ_setTargetValue(obj->trajHandle_spd, 0.0f);

    // disable the PWM
    HAL_disablePWM(obj->halMtrHandle);

    // clear integral outputs of the controllers
    PI_setRefValue(obj->piHandle_Id, 0.0f);
    PI_setRefValue(obj->piHandle_Iq, 0.0f);
    PI_setRefValue(obj->piHandle_spd, 0.0f);

    PI_setUi(obj->piHandle_Id, 0.0f);
    PI_setUi(obj->piHandle_Iq, 0.0f);
    PI_setUi(obj->piHandle_spd, 0.0f);

    // clear current references
    obj->Idq_out_A.value[0] = 0.0f;
    obj->Idq_out_A.value[1] = 0.0f;

    obj->IdRated_A = 0.0f;
    obj->IsRef_A = 0.0f;

    obj->angleCurrent_rad = 0.0f;


    obj->stateRunTimeCnt = 0;

    obj->overLoadTimeCnt = 0;
    obj->motorStallTimeCnt = 0;
    obj->lostPhaseTimeCnt = 0;
    obj->unbalanceTimeCnt = 0;
    obj->startupFailTimeCnt = 0;
    obj->overSpeedTimeCnt = 0;

    SVGEN_setMode(obj->svgenHandle, SVM_COM_C);
    return;
}


void setupControllers(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
    USER_Params *objUser = (USER_Params *)(handle->userParamsHandle);


    float32_t Ls_d_H = objUser->motor_Ls_d_H;
    float32_t Ls_q_H = objUser->motor_Ls_q_H;

    float32_t Rs_Ohm = objUser->motor_Rs_Ohm;
    float32_t RdoverLd_rps = Rs_Ohm / Ls_d_H;
    float32_t RqoverLq_rps = Rs_Ohm / Ls_q_H;

    float32_t BWc_rps = objUser->BWc_rps;
    float32_t currentCtrlPeriod_sec =
                (float32_t)objUser->numCtrlTicksPerCurrentTick /
                objUser->ctrlFreq_Hz;

    float32_t outMax_V = objUser->Vd_sf *
            objUser->maxVsMag_V;

    float32_t Kp_Id = Ls_d_H * BWc_rps;
    float32_t Ki_Id = 0.25f * RdoverLd_rps * currentCtrlPeriod_sec;

    float32_t Kp_Iq = Ls_q_H * BWc_rps;
    float32_t Ki_Iq = 0.25f * RqoverLq_rps * currentCtrlPeriod_sec;

    // set the Id controller
    PI_setGains(obj->piHandle_Id, Kp_Id, Ki_Id);
    PI_setUi(obj->piHandle_Id, 0.0f);
    PI_setRefValue(obj->piHandle_Id, 0.0f);
    PI_setFbackValue(obj->piHandle_Id, 0.0f);
    PI_setFfwdValue(obj->piHandle_Id, 0.0f);
    PI_setMinMax(obj->piHandle_Id, -outMax_V, outMax_V);

    // set the Iq controller
    PI_setGains(obj->piHandle_Iq, Kp_Iq, Ki_Iq);
    PI_setUi(obj->piHandle_Iq, 0.0f);
    PI_setRefValue(obj->piHandle_Iq, 0.0f);
    PI_setFbackValue(obj->piHandle_Iq, 0.0f);
    PI_setFfwdValue(obj->piHandle_Iq, 0.0f);
    PI_setMinMax(obj->piHandle_Iq, 0.0f, 0.0f);
    // set the speed controller
    if(objUser->Kctrl_Wb_p_kgm2 <= 0.01f)
    {
        float32_t Kp_spd1 = 2.5f * objUser->maxCurrent_A / objUser->maxFrequency_Hz;
        float32_t Ki_spd1 = 5.0f * objUser->maxCurrent_A * objUser->ctrlPeriod_sec;

        PI_setGains(obj->piHandle_spd, Kp_spd1, Ki_spd1);
    }
    else
    {
        float32_t speedCtrlPeriod_sec =
            (float32_t)objUser->numCtrlTicksPerSpeedTick /
            objUser->ctrlFreq_Hz;

        float32_t BWdelta = objUser->BWdelta;

        float32_t Kctrl_Wb_p_kgm2 = objUser->Kctrl_Wb_p_kgm2;

        float32_t Kp_spd = BWc_rps / (BWdelta * Kctrl_Wb_p_kgm2);
        float32_t Ki_spd = BWc_rps * speedCtrlPeriod_sec / (BWdelta * BWdelta);

        PI_setGains(obj->piHandle_spd, Kp_spd, Ki_spd);
    }

    PI_setUi(obj->piHandle_spd, 0.0f);
    PI_setRefValue(obj->piHandle_spd, 0.0f);
    PI_setFbackValue(obj->piHandle_spd, 0.0f);
    PI_setFfwdValue(obj->piHandle_spd, 0.0f);
    PI_setMinMax(obj->piHandle_spd,
                 -objUser->maxCurrent_A,
                 objUser->maxCurrent_A);

    // copy the Id, Iq and speed controller parameters to motorVars
    getControllers(handle);


    return;
} // end of setupControllers() function

void CPU_TIME_reset(CPU_TIME_Handle handle)
{
    CPU_TIME_Obj *obj = (CPU_TIME_Obj *)handle;
    uint16_t cnt;

    for(cnt = 0; cnt < MOD_INDEX_MAX; cnt++)
    {
        obj->deltaNow[cnt] = 0;
        obj->deltaMin[cnt] = 0xFFFF;
        obj->deltaMax[cnt] = 0;
    }

    obj->flag_resetStatus = true;

    return;
} // end of CPU_TIME_setParams() function

// timer base is 5ms
void runMotorMonitor(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
    MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);

    if(obj->flagEnableRsOnLine == true)
    {
        if(obj->flagRsOnLineContinue == true)
        {
            obj->flagStartRsOnLine = true;
        }
        else if(obj->RsOnlineTimeCnt == 0)
        {
            if(EST_getFlag_enableRsOnLine(obj->estHandle) == true)
            {
                obj->RsOnlineTimeCnt = objSets->RsOnlineWaitTimeSet;
                obj->flagStartRsOnLine = false;
            }
            else
            {
                obj->RsOnlineTimeCnt = objSets->RsOnlineWorkTimeSet;
                obj->flagStartRsOnLine = true;
            }
        }
        else
        {
            obj->RsOnlineTimeCnt--;
        }
    }

    if(obj->stopWaitTimeCnt > 0)
    {
        obj->stopWaitTimeCnt--;
    }

    // Check if DC bus voltage is over threshold
    if(obj->adcData.VdcBus_V > objSets->overVoltageFault_V)
    {
        if(obj->overVoltageTimeCnt > objSets->voltageFaultTimeSet)
        {
            obj->faultMtrNow.bit.overVoltage = 1;
        }
        else
        {
            obj->overVoltageTimeCnt++;
        }
    }
    else if(obj->adcData.VdcBus_V < objSets->overVoltageNorm_V)
    {
        if(obj->overVoltageTimeCnt == 0)
        {
            obj->faultMtrNow.bit.overVoltage = 0;
        }
        else
        {
            obj->overVoltageTimeCnt--;
        }
    }

    // Check if DC bus voltage is under threshold
    if(obj->adcData.VdcBus_V < objSets->underVoltageFault_V)
    {
        if(obj->underVoltageTimeCnt > objSets->voltageFaultTimeSet)
        {
            obj->faultMtrNow.bit.underVoltage = 1;
        }
        else
        {
            obj->underVoltageTimeCnt++;
        }
    }
    else if(obj->adcData.VdcBus_V > objSets->underVoltageNorm_V)
    {
        if(obj->underVoltageTimeCnt == 0)
        {
            obj->faultMtrNow.bit.underVoltage = 0;
        }
        else
        {
            obj->underVoltageTimeCnt--;
        }
    }

    // check these fault when motor is running
    if(obj->mctrlState == MCTRL_CONT_RUN)
    {
        // Over Load Check
        if(obj->powerActive_W > objSets->overLoadSet_W)
        {
            if(obj->overLoadTimeCnt > objSets->overLoadTimeSet)
            {
            //    obj->faultMtrNow.bit.overLoad = 1;
                obj->overLoadTimeCnt = 0;
            }
            else
            {
                obj->overLoadTimeCnt++;
            }
        }
        else if(obj->overLoadTimeCnt > 0)
        {
            obj->overLoadTimeCnt--;
        }

        // Motor Stall
        if( (obj->Is_A > objSets->stallCurrentSet_A)
                && (obj->speedAbs_Hz < objSets->speedFailMinSet_Hz))
        {
            if(obj->motorStallTimeCnt > objSets->motorStallTimeSet)
            {
        //        obj->faultMtrNow.bit.motorStall = 1;
                obj->motorStallTimeCnt = 0;
            }
            else
            {
                obj->motorStallTimeCnt++;
            }
        }
        else if(obj->motorStallTimeCnt > 0)
        {
            obj->motorStallTimeCnt--;
        }

        // (obj->torque_Nm < objSets->toqueFailMinSet_Nm)
        // Motor Lost Phase Fault Check
        if( (obj->speedAbs_Hz > objSets->speedFailMinSet_Hz) &&
            ( (obj->Irms_A[0] < objSets->lostPhaseSet_A) ||
              (obj->Irms_A[1] < objSets->lostPhaseSet_A) ||
              (obj->Irms_A[2] < objSets->lostPhaseSet_A)) )
        {
            if(obj->lostPhaseTimeCnt > objSets->lostPhaseTimeSet)
            {
                obj->faultMtrNow.bit.motorLostPhase = 1;
                obj->lostPhaseTimeCnt = 0;
            }
            else
            {
                obj->lostPhaseTimeCnt++;
            }
        }
        else if(obj->lostPhaseTimeCnt > 0)
        {
            obj->lostPhaseTimeCnt--;
        }

        // Only when the torque is great than a setting value
        if(obj->Is_A > objSets->IsFailedChekSet_A)
        {
            // Motor Phase Current Unbalance
            if(obj->unbalanceRatio > objSets->unbalanceRatioSet)
            {
                if(obj->unbalanceTimeCnt > objSets->unbalanceTimeSet)
                {
               //     obj->faultMtrNow.bit.currentUnbalance = 1;
                    obj->unbalanceTimeCnt = 0;
                }
                else
                {
                    obj->unbalanceTimeCnt++;
                }
            }
            else if(obj->unbalanceTimeCnt > 0)
            {
                obj->unbalanceTimeCnt--;
            }

            // Motor Startup Failed
            if( (obj->Is_A < objSets->stallCurrentSet_A)
               && (obj->speedAbs_Hz < objSets->speedFailMinSet_Hz))
            {
                if(obj->startupFailTimeCnt > objSets->startupFailTimeSet)
                {
            //        obj->faultMtrNow.bit.startupFailed = 1;
                    obj->startupFailTimeCnt = 0;
                }
                else
                {
                    obj->startupFailTimeCnt++;
                }
            }
            else if(obj->startupFailTimeCnt > 0)
            {
                obj->startupFailTimeCnt--;
            }

            // Motor Over speed
            if(obj->speedAbs_Hz > objSets->speedFailMaxSet_Hz)
            {
                if(obj->overSpeedTimeCnt > objSets->overSpeedTimeSet)
                {
                    obj->faultMtrNow.bit.overSpeed = 1;
                    obj->overSpeedTimeCnt = 0;
                }
                else
                {
                    obj->overSpeedTimeCnt++;
                }
            }
            else if(obj->overSpeedTimeCnt > 0)
            {
                obj->overSpeedTimeCnt--;
            }
        } // obj->Is_A > objSets->IsFailedChekSet_A
    } // obj->operateState == OPERATE_State_Run

    return;
}


void calculateRMSData(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

    float32_t IrmsMax_A, IrmsMin_A, VIrmsIsrSet;

    if(obj->flagVIrmsCal == true)
    {
        obj->flagVIrmsCal = false;

        obj->Irms_A[0] =
                sqrtf(obj->IrmsPrdSum[0] * obj->IrmsCalSF);

        obj->Irms_A[1] =
                sqrtf(obj->IrmsPrdSum[1] * obj->IrmsCalSF);

        obj->Irms_A[2] =
                sqrtf(obj->IrmsPrdSum[2] * obj->IrmsCalSF);

        obj->Vrms_V[0] =
                sqrtf(obj->VrmsPrdSum[0] * obj->VrmsCalSF);

        obj->Vrms_V[1] =
                sqrtf(obj->VrmsPrdSum[1] * obj->VrmsCalSF);

        obj->Vrms_V[2] =
                sqrtf(obj->VrmsPrdSum[2] * obj->VrmsCalSF);

        if(obj->Irms_A[0] > obj->Irms_A[1])
        {
            IrmsMax_A = obj->Irms_A[0];
            IrmsMin_A = obj->Irms_A[1];
        }
        else
        {
            IrmsMax_A = obj->Irms_A[0];
            IrmsMin_A = obj->Irms_A[1];
        }

        IrmsMax_A = (obj->Irms_A[2] > IrmsMax_A) ? obj->Irms_A[2] : IrmsMax_A;
        IrmsMin_A = (obj->Irms_A[2] < IrmsMin_A) ? obj->Irms_A[2] : IrmsMin_A;

        VIrmsIsrSet = obj->VIrmsIsrScale / obj->speedAbs_Hz;
        VIrmsIsrSet = (VIrmsIsrSet > obj->VIrmsIsrScale) ?
                obj->VIrmsIsrScale : VIrmsIsrSet;

        obj->VIrmsIsrSet = (uint16_t)(VIrmsIsrSet);

        obj->IrmsCalSF = 1.0f / ((float32_t)(obj->VIrmsIsrSet));
        obj->VrmsCalSF = obj->IrmsCalSF;

        obj->unbalanceRatio =
                (IrmsMax_A - IrmsMin_A) / (IrmsMax_A + IrmsMin_A);

        obj->powerActive_W = obj->Irms_A[0] * obj->Vrms_V[0] +
                obj->Irms_A[1] * obj->Vrms_V[1] + obj->Irms_A[2] * obj->Vrms_V[2];
    }

    obj->powerReal_W = obj->torque_Nm *
            obj->speedAbs_Hz * obj->power_sf;
}

// Sets up control parameters for restarting motor
void restartMotorControl(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

    if(obj->mctrlState >= MCTRL_NORM_STOP)
    {
        obj->mctrlState = MCTRL_CONT_RUN;
    }
    else
    {
        obj->mctrlState = MCTRL_FIRST_RUN;
    }

    if(obj->flagEnableFlyingStart == true)
    {
        obj->motorState = MOTOR_SEEK_POS;
    }
    else
    {
        obj->motorState = MOTOR_ALIGNMENT;
    }
    obj->speed_int_Hz = 0.0f;

    SVGEN_setMode(obj->svgenHandle, SVM_COM_C);

    obj->flagRunIdentAndOnLine = true;
    obj->stateRunTimeCnt = 0;
    obj->startSumTimesCnt++;

    return;
}

// Sets up control parameters for stopping motor
void stopMotorControl(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

    obj->speed_int_Hz = 0.0f;

    obj->flagRunIdentAndOnLine = false;

    obj->motorState = MOTOR_STOP_IDLE;
    obj->mctrlState = MCTRL_NORM_STOP;

    SVGEN_setMode(obj->svgenHandle, SVM_COM_C);

    obj->restartTimesCnt = 0;

    return;
}

void runRsOnLine(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
    MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);

    // execute Rs OnLine code
    if(obj->flagRunIdentAndOnLine == true)
    {
        if((EST_getState(obj->estHandle) == EST_STATE_ONLINE) &&
                (obj->flagStartRsOnLine == true))
        {
            EST_setFlag_enableRsOnLine(obj->estHandle, true);

            EST_setRsOnLineId_mag_A(obj->estHandle, objSets->RsOnLineCurrent_A);

            float32_t RsError_Ohm =
                    objSets->RsOnLine_Ohm - objSets->Rs_Ohm;

            if(fabsf(RsError_Ohm) < (objSets->Rs_Ohm * 0.05f))
            {
                EST_setFlag_updateRs(obj->estHandle, true);
            }
        }
        else
        {
            EST_setRsOnLineId_mag_A(obj->estHandle, 0.0f);
            EST_setRsOnLineId_A(obj->estHandle, 0.0f);
            EST_setRsOnLine_Ohm(obj->estHandle, EST_getRs_Ohm(obj->estHandle));

            EST_setFlag_enableRsOnLine(obj->estHandle, false);
            EST_setFlag_updateRs(obj->estHandle, false);
        }
    }

    return;
} // end of runRsOnLine() function

// update motor control variables
void updateGlobalVariables(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;
    MOTOR_SetVars_t *objSets = (MOTOR_SetVars_t *)(handle->motorSetsHandle);

    obj->estState = EST_getState(obj->estHandle);
    obj->trajState = EST_getTrajState(obj->estHandle);

    objSets->Rr_Ohm = EST_getRr_Ohm(obj->estHandle);

    objSets->Rs_Ohm = EST_getRs_Ohm(obj->estHandle);

    objSets->Ls_d_H = EST_getLs_d_H(obj->estHandle);

    objSets->Ls_q_H = EST_getLs_q_H(obj->estHandle);

    objSets->flux_Wb   = EST_getFlux_Wb(obj->estHandle);
    objSets->flux_VpHz = EST_getFlux_Wb(obj->estHandle) * MATH_TWO_PI;

    objSets->magneticCurrent_A = EST_getIdRated_A(obj->estHandle);

    objSets->RoverL_rps = EST_getRoverL_rps(obj->estHandle);

    obj->torque_Nm = EST_computeTorque_Nm(obj->estHandle);

    objSets->RsOnLine_Ohm = EST_getRsOnLine_Ohm(obj->estHandle);

    obj->Is_A =
                sqrtf(obj->Idq_in_A.value[0] * obj->Idq_in_A.value[0] +
                      obj->Idq_in_A.value[1] * obj->Idq_in_A.value[1]);

    obj->Vs_V =
                sqrtf(obj->Vdq_out_V.value[0] * obj->Vdq_out_V.value[0] +
                      obj->Vdq_out_V.value[1] * obj->Vdq_out_V.value[1]);

    return;
} // end of updateGlobalVariables() function

void collectRMSData(MOTOR_Handle handle)
{
    MOTOR_Vars_t *obj = (MOTOR_Vars_t *)handle;

    obj->IrmsCalSum[0] += obj->adcData.I_A.value[0] * obj->adcData.I_A.value[0];
    obj->IrmsCalSum[1] += obj->adcData.I_A.value[1] * obj->adcData.I_A.value[1];
    obj->IrmsCalSum[2] += obj->adcData.I_A.value[2] * obj->adcData.I_A.value[2];

    obj->VrmsCalSum[0] += obj->adcData.V_V.value[0] * obj->adcData.V_V.value[0];
    obj->VrmsCalSum[1] += obj->adcData.V_V.value[1] * obj->adcData.V_V.value[1];
    obj->VrmsCalSum[2] += obj->adcData.V_V.value[2] * obj->adcData.V_V.value[2];

    obj->VIrmsIsrCnt++;

    if(obj->VIrmsIsrCnt > obj->VIrmsIsrSet)
    {
        obj->IrmsPrdSum[0] = obj->IrmsCalSum[0];
        obj->IrmsPrdSum[1] = obj->IrmsCalSum[1];
        obj->IrmsPrdSum[2] = obj->IrmsCalSum[2];

        obj->IrmsCalSum[0] = 0.0f;
        obj->IrmsCalSum[1] = 0.0f;
        obj->IrmsCalSum[2] = 0.0f;

        obj->VrmsPrdSum[0] = obj->VrmsCalSum[0];
        obj->VrmsPrdSum[1] = obj->VrmsCalSum[1];
        obj->VrmsPrdSum[2] = obj->VrmsCalSum[2];

        obj->VrmsCalSum[0] = 0.0f;
        obj->VrmsCalSum[1] = 0.0f;
        obj->VrmsCalSum[2] = 0.0f;

        obj->VIrmsIsrCnt = 0;
        obj->flagVIrmsCal = true;
    }
}
