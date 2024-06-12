//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:28 CDT 2021 $
// $Copyright:
// Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
//! \file   /solutions/fast_uni_lab/common/source/user_mtr1.c
//! \brief  InstaSPIN function for setting initialization data for the
//!         CTRL, HAL, and EST modules (floating point)
//!
//

#include "user.h"

#include "hal.h"

//*****************************************************************************
//
// USER_setParams, set control parameters for motor 1
//
//*****************************************************************************
void USER_setMotor1Params(USER_Params *pUserParams)
{
    pUserParams->dcBus_nominal_V = USER_M1_NOMINAL_DC_BUS_VOLTAGE_V;

    pUserParams->numIsrTicksPerCtrlTick = 1;
    pUserParams->numIsrTicksPerEstTick = 1;
    pUserParams->numIsrTicksPerTrajTick = 1;

    pUserParams->numCtrlTicksPerCurrentTick = 1;
    pUserParams->numCtrlTicksPerSpeedTick = USER_M1_NUM_ISR_TICKS_PER_SPEED_TICK;

    pUserParams->numCurrentSensors = USER_M1_NUM_CURRENT_SENSORS;
    pUserParams->numVoltageSensors = USER_M1_NUM_VOLTAGE_SENSORS;

    pUserParams->systemFreq_MHz = USER_SYSTEM_FREQ_MHz;

    pUserParams->pwmPeriod_usec = USER_M1_PWM_PERIOD_usec;

    pUserParams->voltage_sf = USER_M1_VOLTAGE_SF;

    pUserParams->current_sf = USER_M1_CURRENT_SF;

    pUserParams->dcBusPole_rps = USER_M1_DCBUS_POLE_rps;

    pUserParams->speedPole_rps = USER_M1_SPEED_POLE_rps;

    pUserParams->voltageFilterPole_rps = USER_M1_VOLTAGE_FILTER_POLE_rps;

    pUserParams->maxVsMag_pu = USER_M1_MAX_VS_MAG_PU;

    pUserParams->motor_type = USER_MOTOR1_TYPE;

    pUserParams->motor_numPolePairs = USER_MOTOR1_NUM_POLE_PAIRS;

    pUserParams->motor_numEncSlots = USER_MOTOR1_NUM_ENC_SLOTS;

    pUserParams->motor_ratedFlux_Wb = USER_MOTOR1_RATED_FLUX_VpHz / MATH_TWO_PI;
    pUserParams->flux_Wb = USER_MOTOR1_RATED_FLUX_VpHz / MATH_TWO_PI;

    pUserParams->motor_Rr_Ohm = USER_MOTOR1_Rr_Ohm;
    pUserParams->motor_Rs_Ohm = USER_MOTOR1_Rs_Ohm;

    pUserParams->motor_Ls_d_H = USER_MOTOR1_Ls_d_H;
    pUserParams->motor_Ls_q_H = USER_MOTOR1_Ls_q_H;

    pUserParams->maxCurrent_A = USER_MOTOR1_MAX_CURRENT_A;

    pUserParams->IdRated_A = USER_MOTOR1_MAGNETIZING_CURRENT_A;

    pUserParams->Vd_sf = USER_M1_VD_SF;
    pUserParams->maxVsMag_V = USER_MOTOR1_RATED_VOLTAGE_V;

    /* It's a compile time flag providing user a
       choice to use or bypass motor identification; so OK"*/
    if(pUserParams->flag_bypassMotorId == true)
    {
        pUserParams->BWc_rps = MATH_TWO_PI * (float32_t)400.0f;
        pUserParams->BWdelta = (float32_t)10.0f;

        pUserParams->Kctrl_Wb_p_kgm2 = (float32_t)3.0f *
                                   pUserParams->motor_numPolePairs *
                                   pUserParams->motor_ratedFlux_Wb /
                                   (float32_t) (2.0f * USER_MOTOR1_INERTIA_Kgm2);
    }
    else
    {
        pUserParams->BWc_rps = MATH_TWO_PI * (float32_t)200.0f;
        pUserParams->BWdelta = (float32_t)20.0f;
        pUserParams->Kctrl_Wb_p_kgm2 = (float32_t)3.0f *
                                       pUserParams->motor_numPolePairs *
                                       (float32_t)(0.001f) /
                                       (float32_t)(2.0f * 0.000001f);
    }

    pUserParams->angleDelayed_sf_sec = (float32_t)0.5f * USER_M1_CTRL_PERIOD_sec;

    pUserParams->fluxExcFreq_Hz = USER_MOTOR1_FLUX_EXC_FREQ_Hz;

    pUserParams->estWaitTime[EST_STATE_ERROR] = 0;
    pUserParams->estWaitTime[EST_STATE_IDLE] = 0;
    pUserParams->estWaitTime[EST_STATE_ROVERL] = (int_least32_t)(5.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_RS] = 0;
    pUserParams->estWaitTime[EST_STATE_RAMPUP] = (int_least32_t)((USER_MOTOR1_FLUX_EXC_FREQ_Hz /
            USER_M1_MAX_ACCEL_Hzps + (float32_t)1.0) * USER_M1_ISR_FREQ_Hz);

    pUserParams->estWaitTime[EST_STATE_CONSTSPEED] = (int_least32_t)(1.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_IDRATED] = (int_least32_t)(20.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_RATEDFLUX_OL] = (int_least32_t)(1.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_RATEDFLUX] = 0;
    pUserParams->estWaitTime[EST_STATE_RAMPDOWN] = (int_least32_t)(0.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_LOCKROTOR] = 0;
    pUserParams->estWaitTime[EST_STATE_LS] = 0;
    pUserParams->estWaitTime[EST_STATE_RR] = (int_least32_t)(5.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->estWaitTime[EST_STATE_MOTORIDENTIFIED] = 0;
    pUserParams->estWaitTime[EST_STATE_ONLINE] = 0;

    pUserParams->FluxWaitTime[EST_FLUX_STATE_ERROR] = 0;
    pUserParams->FluxWaitTime[EST_FLUX_STATE_IDLE] = 0;
    pUserParams->FluxWaitTime[EST_FLUX_STATE_CL1] = (int_least32_t)(10.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->FluxWaitTime[EST_FLUX_STATE_CL2] = (int_least32_t)(0.2 * USER_M1_ISR_FREQ_Hz);
    pUserParams->FluxWaitTime[EST_FLUX_STATE_FINE] = (int_least32_t)(20.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->FluxWaitTime[EST_FLUX_STATE_DONE] = 0;

    pUserParams->LsWaitTime[EST_LS_STATE_ERROR] = 0;
    pUserParams->LsWaitTime[EST_LS_STATE_IDLE] = 0;
    pUserParams->LsWaitTime[EST_LS_STATE_RAMPUP] = (int_least32_t)(10.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->LsWaitTime[EST_LS_STATE_COARSE] = (int_least32_t)(30.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->LsWaitTime[EST_LS_STATE_FINE] = (int_least32_t)(30.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->LsWaitTime[EST_LS_STATE_DONE] = 0;

    pUserParams->RrWaitTime[EST_RR_STATE_ERROR] = 0;
    pUserParams->RrWaitTime[EST_RR_STATE_IDLE] = 0;
    pUserParams->RrWaitTime[EST_RR_STATE_RAMPUP] = (int_least32_t)(1.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RrWaitTime[EST_RR_STATE_COARSE] = (int_least32_t)(10.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RrWaitTime[EST_RR_STATE_FINE] = (int_least32_t)(30.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RrWaitTime[EST_RR_STATE_DONE] = 0;

    pUserParams->RsWaitTime[EST_RS_STATE_ERROR] = 0;
    pUserParams->RsWaitTime[EST_RS_STATE_IDLE] = 0;
    pUserParams->RsWaitTime[EST_RS_STATE_RAMPUP] = (int_least32_t)(1.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RsWaitTime[EST_RS_STATE_COARSE] = (int_least32_t)(2.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RsWaitTime[EST_RS_STATE_FINE] = (int_least32_t)(10.0 * USER_M1_ISR_FREQ_Hz);
    pUserParams->RsWaitTime[EST_RS_STATE_DONE] = 0;

    pUserParams->trajWaitTime[EST_TRAJ_STATE_ERROR] = 0;
    pUserParams->trajWaitTime[EST_TRAJ_STATE_IDLE] = 0;
    pUserParams->trajWaitTime[EST_TRAJ_STATE_EST] = 0;
    pUserParams->trajWaitTime[EST_TRAJ_STATE_ONLINE] = 0;

    pUserParams->ctrlFreq_Hz = USER_M1_ISR_FREQ_Hz;

    pUserParams->estFreq_Hz = USER_M1_ISR_FREQ_Hz;

    pUserParams->RoverL_excFreq_Hz = USER_M1_R_OVER_L_EXC_FREQ_Hz;

    pUserParams->trajFreq_Hz = USER_M1_ISR_FREQ_Hz;

    pUserParams->ctrlPeriod_sec = USER_M1_CTRL_PERIOD_sec;

    pUserParams->maxAccel_Hzps = USER_M1_MAX_ACCEL_Hzps;

    pUserParams->maxCurrent_resEst_A = USER_MOTOR1_RES_EST_CURRENT_A;
    pUserParams->maxCurrent_indEst_A = USER_MOTOR1_IND_EST_CURRENT_A;

    pUserParams->maxCurrentDelta_A = USER_M1_MAX_CURRENT_DELTA_A;
    pUserParams->maxCurrentDelta_pw_A = USER_M1_MAX_CURRENT_DELTA_PW_A;

    pUserParams->IdRated_delta_A = USER_M1_IDRATED_DELTA_A;

    pUserParams->forceAngleFreq_Hz = USER_M1_FORCE_ANGLE_FREQ_Hz;

    pUserParams->forceAngleAccel_Hzps = USER_M1_FORCE_ANGLE_ACCEL_Hzps;

    pUserParams->indEst_speedMaxFraction = USER_M1_SPEEDMAX_FRACTION_FOR_L_IDENT;

    pUserParams->IdRatedFraction_indEst = USER_M1_IDRATED_FRACTION_FOR_L_IDENT;

    pUserParams->pwGain = USER_M1_PW_GAIN;

    pUserParams->Kp_min_VpA = (float32_t)0.001f;
    pUserParams->Kp_max_VpA = (float32_t)1000.0f;

    pUserParams->RoverL_Kp_sf = USER_M1_R_OVER_L_KP_SF;
    pUserParams->RoverL_min_rps = MATH_TWO_PI * (float32_t)5.0f;
    pUserParams->RoverL_max_rps = MATH_TWO_PI * (float32_t)5000.0f;

    pUserParams->oneOverDcBus_min_invV = (float32_t)1.0f / (float32_t)400.0f;
    pUserParams->oneOverDcBus_max_invV = (float32_t)1.0f / (float32_t)10.0f;

    pUserParams->Ls_d_H = (float32_t)1.0e-6;
    pUserParams->Ls_q_H = (float32_t)1.0e-6;
    pUserParams->Ls_coarseDelta_H = (float32_t)0.0000001f;
    pUserParams->Ls_fineDelta_H = (float32_t)0.00000001f;
    pUserParams->Ls_min_H = (float32_t)0.000001f;
    pUserParams->Ls_max_H = (float32_t)100.0f;

    pUserParams->Rr_Ohm = (float32_t)0.0;
    pUserParams->Rr_coarseDelta_Ohm = (float32_t)0.0001f;
    pUserParams->Rr_fineDelta_Ohm = (float32_t)0.00001f;
    pUserParams->Rr_min_Ohm = (float32_t)0.0f;
    pUserParams->Rr_max_Ohm = (float32_t)1000.0f;

    pUserParams->Rs_Ohm = (float32_t)0.0;
    pUserParams->Rs_coarseDelta_Ohm = (float32_t)0.01f;
    pUserParams->Rs_fineDelta_Ohm = (float32_t)0.00001f;
    pUserParams->Rs_min_Ohm = (float32_t)0.001f;
    pUserParams->Rs_max_Ohm = (float32_t)1000.0f;

    pUserParams->RsOnLine_DeltaInc_Ohm = (float32_t)0.00001f;
    pUserParams->RsOnLine_DeltaDec_Ohm = (float32_t)0.00001f;
    pUserParams->RsOnLine_min_Ohm = (float32_t)0.001f;
    pUserParams->RsOnLine_max_Ohm = (float32_t)1000.0f;

    pUserParams->RsOnLine_angleDelta_rad = (float32_t)0.00001f;
    pUserParams->RsOnLine_pole_rps = MATH_TWO_PI * (float32_t)0.2f;

    pUserParams->maxFrequency_Hz = USER_MOTOR1_FREQ_MAX_HZ;

    pUserParams->freqNearZeroSpeedLimit_Hz = USER_MOTOR1_FREQ_NEARZEROLIMIT_Hz;

    return;
} // end of USER_setParams() function
