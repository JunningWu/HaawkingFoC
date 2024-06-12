//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:28 CDT 2021 $
// $Copyright:
// Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef USER_MTR1_H
#define USER_MTR1_H

//
//! \file   /solutions/fast_uni_lab/common/include/user_mtr1.h
//! \brief  Contains the user related definitions
//!
//

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup USER USER
//! @{
//
//*****************************************************************************

//
// the includes

// modules
#include "userParams.h"

#include "user_common.h"


// *****************************************************************************
// the defines

//------------------------------------------------------------------------------

//! \brief Defines the nominal DC bus voltage, V
//!
#define USER_M1_NOMINAL_DC_BUS_VOLTAGE_V         (24.0f)

//! \brief Defines the maximum voltage at the AD converter
#define USER_M1_ADC_FULL_SCALE_VOLTAGE_V         (57.52845691f)

//! \brief Defines the analog voltage filter pole location, Hz
#define USER_M1_VOLTAGE_FILTER_POLE_Hz           (680.4839141f)     // 47nF

//! \brief Defines the maximum current at the AD converter
#define USER_M1_ADC_FULL_SCALE_CURRENT_A         (47.14285714f)     // gain=10

//! \brief ADC current offsets for dc-link
// the dc-link offset current for BSXL8323RS_REVA
#define USER_M1_IDC_OFFSET_A            (USER_M1_ADC_FULL_SCALE_CURRENT_A / 2.0f)

//! \brief ADC current offsets for A, B, and C phases
#define USER_M1_IDC_OFFSET_AD           (2048.0f)

#define USER_M1_IDC_OFFSET_AD_MAX       (USER_M1_IDC_OFFSET_AD + 100.0f)
#define USER_M1_IDC_OFFSET_AD_MIN       (USER_M1_IDC_OFFSET_AD - 100.0f)

//! \brief ADC current offsets for A, B, and C phases
#define USER_M1_IA_OFFSET_AD    (2030.99646f)
#define USER_M1_IB_OFFSET_AD    (2016.76001f)
#define USER_M1_IC_OFFSET_AD    (2007.99329f)

//! \brief ADC voltage offsets for A, B, and C phases
#define USER_M1_VA_OFFSET_SF    (0.498977453f)
#define USER_M1_VB_OFFSET_SF    (0.497419506f)
#define USER_M1_VC_OFFSET_SF    (0.500700474f)

//! \brief DC bus over voltage threshold
#define USER_M1_OVER_VOLTAGE_FAULT_V        (53.0f)

//! \brief DC bus over voltage threshold
#define USER_M1_OVER_VOLTAGE_NORM_V         (52.5f)

//! \brief DC bus under voltage threshold
#define USER_M1_UNDER_VOLTAGE_FAULT_V       (0.2f)//(8.0f)//(25.0f)//

//! \brief DC bus under voltage threshold
#define USER_M1_UNDER_VOLTAGE_NORM_V        (10.0f)

//! \brief motor lost phase current threshold
#define USER_M1_LOST_PHASE_CURRENT_A        (0.2f)

//! \brief motor unbalance ratio percent threshold
#define USER_M1_UNBALANCE_RATIO             (0.2f)

//! \brief motor over load power threshold
#define USER_M1_OVER_LOAD_POWER_W           (250.0f)

//! \brief motor stall current threshold
#define USER_M1_STALL_CURRENT_A             (5.0f)

//! \brief motor fault check current threshold
#define USER_M1_FAULT_CHECK_CURRENT_A       (15.2f)

//! \brief motor failed maximum speed threshold
#define USER_M1_FAIL_SPEED_MAX_HZ           (350.0f)

//! \brief motor failed minimum speed threshold
#define USER_M1_FAIL_SPEED_MIN_HZ           (5.0f)

//! \brief Defines the number of failed torque
//!
#define USER_M1_TORQUE_FAILED_SET           (0.000001f)

// end of BSXL8323RS_REVA


//------------------------------------------------------------------------------
//! \brief ADC current offsets checking value for A, B, and C phases
#define USER_M1_IA_OFFSET_AD_MAX    (USER_M1_IA_OFFSET_AD + 150.0f)
#define USER_M1_IB_OFFSET_AD_MAX    (USER_M1_IB_OFFSET_AD + 150.0f)
#define USER_M1_IC_OFFSET_AD_MAX    (USER_M1_IC_OFFSET_AD + 150.0f)

#define USER_M1_IA_OFFSET_AD_MIN    (USER_M1_IA_OFFSET_AD - 150.0f)
#define USER_M1_IB_OFFSET_AD_MIN    (USER_M1_IB_OFFSET_AD - 150.0f)
#define USER_M1_IC_OFFSET_AD_MIN    (USER_M1_IC_OFFSET_AD - 150.0f)

//! \brief ADC voltage offsets for A, B, and C phases
#define USER_M1_VA_OFFSET_SF_MAX    (USER_M1_VA_OFFSET_SF + 0.05f)
#define USER_M1_VB_OFFSET_SF_MAX    (USER_M1_VB_OFFSET_SF + 0.05f)
#define USER_M1_VC_OFFSET_SF_MAX    (USER_M1_VC_OFFSET_SF + 0.05f)

#define USER_M1_VA_OFFSET_SF_MIN    (USER_M1_VA_OFFSET_SF - 0.05f)
#define USER_M1_VB_OFFSET_SF_MIN    (USER_M1_VB_OFFSET_SF - 0.05f)
#define USER_M1_VC_OFFSET_SF_MIN    (USER_M1_VC_OFFSET_SF - 0.05f)

//******************************************************************************
//------------------------------------------------------------------------------
//! \brief Vbus used to calculate the voltage offsets A, B, and C
// =0.5*USER_M1_NOMINAL_DC_BUS_VOLTAGE_V
#define USER_M1_VBUS_OFFSET_V  (0.5*USER_M1_ADC_FULL_SCALE_VOLTAGE_V)


//! \brief Defines the maximum negative current to be applied in Id reference
//!
#define USER_M1_MAX_NEGATIVE_ID_REF_CURRENT_A       ((float32_t)(-2.0))


//! \brief Defines the number of pwm clock ticks per isr clock tick
//!        Note: Valid values are 1, 2 or 3 only
#define USER_M1_NUM_PWM_TICKS_PER_ISR_TICK          (1)


//! \brief Defines the number of ISR clock ticks per current controller clock tick
//!
#define USER_M1_NUM_ISR_TICKS_PER_CURRENT_TICK      (1)


//! \brief Defines the number of ISR clock ticks per speed controller clock tick
//!
#define USER_M1_NUM_ISR_TICKS_PER_SPEED_TICK        (15)


//! \brief Defines the number of current sensors
//!
#define USER_M1_NUM_CURRENT_SENSORS                 (3)


//! \brief Defines the number of voltage sensors
//!
#define USER_M1_NUM_VOLTAGE_SENSORS                 (3)


//! \brief Defines the Pulse Width Modulation (PWM) frequency, kHz
//!
#define USER_M1_PWM_FREQ_kHz        ((float32_t)(15.0f))
#define USER_M1_PWM_TBPRD_NUM       (uint16_t)(USER_SYSTEM_FREQ_MHz * 1000.0f / USER_M1_PWM_FREQ_kHz / 2.0f)

//! \brief Defines the Pulse Width Modulation (PWM) period, usec
//!
#define USER_M1_PWM_PERIOD_usec     ((float32_t)1000.0/USER_M1_PWM_FREQ_kHz)


//! \brief Defines the Interrupt Service Routine (ISR) frequency, Hz
//!
#define USER_M1_ISR_FREQ_Hz         (USER_M1_PWM_FREQ_kHz * (float32_t)1000.0 / (float32_t)USER_M1_NUM_PWM_TICKS_PER_ISR_TICK)

//! \brief Defines the SFRA sampling, Hz
//!
#define MOTOR1_SAMPLING_FREQ_HZ     USER_M1_ISR_FREQ_Hz


//! \brief Defines the Interrupt Service Routine (ISR) period, usec
//!
#define USER_M1_ISR_PERIOD_usec     (USER_M1_PWM_PERIOD_usec * (float32_t)USER_M1_NUM_PWM_TICKS_PER_ISR_TICK)


//! \brief Defines the direct voltage (Vd) scale factor
//!
#define USER_M1_VD_SF               ((float32_t)(0.95f))


//! \brief Defines the voltage scale factor for the system
//!
#define USER_M1_VOLTAGE_SF          (USER_M1_ADC_FULL_SCALE_VOLTAGE_V / 4096.0f)

//! \brief Defines the current scale factor for the system
//!
#define USER_M1_CURRENT_SF          (USER_M1_ADC_FULL_SCALE_CURRENT_A / 4096.0f)


//! \brief Defines the current scale invert factor for the system
//!
#define USER_M1_CURRENT_INV_SF      (4096.0f / USER_M1_ADC_FULL_SCALE_CURRENT_A)


//! \brief Defines the analog voltage filter pole location, rad/s
//!
#define USER_M1_VOLTAGE_FILTER_POLE_rps  (MATH_TWO_PI * USER_M1_VOLTAGE_FILTER_POLE_Hz)

//! \brief Defines the maximum Vs magnitude in per units allowed
//! \brief This value sets the maximum magnitude for the output of the Id and
//! \brief Iq PI current controllers. The Id and Iq current controller outputs
//! \brief are Vd and Vq. The relationship between Vs, Vd, and Vq is:
//! \brief Vs = sqrt(Vd^2 + Vq^2).  In this FOC controller, the Vd value is set
//! \brief equal to USER_MAX_VS_MAG*USER_VD_MAG_FACTOR.
//! \brief so the Vq value is set equal to sqrt(USER_MAX_VS_MAG^2 - Vd^2).
//!
//! \brief Set USER_MAX_VS_MAG = 0.5 for a pure sinewave with a peak at
//! \brief SQRT(3)/2 = 86.6% duty cycle.  No current reconstruction
//! \brief is needed for this scenario.
//!
//! \brief Set USER_MAX_VS_MAG = 1/SQRT(3) = 0.5774 for a pure sinewave
//! \brief with a peak at 100% duty cycle.  Current reconstruction
//! \brief will be needed for this scenario (Lab08).
//!
//! \brief Set USER_MAX_VS_MAG = 2/3 = 0.6666 to create a trapezoidal
//! \brief voltage waveform.  Current reconstruction will be needed
//! \brief for this scenario (Lab08).
//!
//! \brief For space vector over-modulation, see lab08 for details on
//! \brief system requirements that will allow the SVM generator to
//! \brief go all the way to trapezoidal.
//!
//#define USER_M1_MAX_VS_MAG_PU            (0.66)
//#define USER_M1_MAX_VS_MAG_PU              (0.65)
#define USER_M1_MAX_VS_MAG_PU            (0.576)
//#define USER_M1_MAX_VS_MAG_PU            (0.565)
//#define USER_M1_MAX_VS_MAG_PU            (0.5)


//! \brief Defines the reference Vs magnitude in per units allowed
//! \      Set the value equal from 0.5 to 0.95 of the maximum Vs magnitude
#define USER_M1_VS_REF_MAG_PU             (float32_t)(0.8) * USER_MAX_VS_MAG_PU)

//! \brief Defines the R/L excitation frequency, Hz
//!
#define USER_M1_R_OVER_L_EXC_FREQ_Hz  ((float32_t)(300.0))


//! \brief Defines the R/L Kp scale factor, pu
//! \brief Kp used during R/L is USER_M1_R_OVER_L_KP_SF * USER_M1_NOMINAL_DC_BUS_VOLTAGE_V / USER_MOTOR1_MAX_CURRENT_A;
//!
#define USER_M1_R_OVER_L_KP_SF        ((float32_t)(0.02))


//! \brief Defines maximum acceleration for the estimation speed profiles, Hz/sec
//!
#define USER_M1_MAX_ACCEL_Hzps        ((float32_t)(1.0))


//! \brief Defines the controller execution period, usec
//!
#define USER_M1_CTRL_PERIOD_usec      (USER_M1_ISR_PERIOD_usec)


//! \brief Defines the controller execution period, sec
//!
#define USER_M1_CTRL_PERIOD_sec       ((float32_t)USER_M1_CTRL_PERIOD_usec/(float32_t)1000000.0)


//! \brief Defines the IdRated delta to use during estimation
//!
#define USER_M1_IDRATED_DELTA_A                 ((float32_t)(0.0001))

//! \brief Defines the forced angle frequency, Hz
#define USER_M1_FORCE_ANGLE_FREQ_Hz             ((float32_t)(1.0))

//! \brief Defines the forced angle acceleration, Hz
#define USER_M1_FORCE_ANGLE_ACCEL_Hzps          ((float32_t)(10.0))

//! \brief Defines the near zero speed limit for electrical frequency estimation, Hz
//!        The flux integrator uses this limit to regulate flux integration
#define USER_M1_FREQ_NEARZEROSPEEDLIMIT_Hz      ((float_t)(0.0f))

//! \brief Defines the fraction of IdRated to use during inductance estimation
//!
#define USER_M1_IDRATED_FRACTION_FOR_L_IDENT    ((float32_t)(0.5))


//! \brief Defines the fraction of SpeedMax to use during inductance estimation
//!
#define USER_M1_SPEEDMAX_FRACTION_FOR_L_IDENT  ((float32_t)(1.0))


//! \brief Defines the Power Warp gain for computing Id reference
//! \brief If motor parameters are known, set this gain to:
//! \brief USER_M1_PW_GAIN = SQRT(1.0 + USER_MOTOR1_Rr_Ohm / USER_MOTOR1_Rs_Ohm)
//!
#define USER_M1_PW_GAIN                        ((float32_t)(1.0))


//! \brief Defines the pole location for the DC bus filter, rad/sec
//!
#define USER_M1_DCBUS_POLE_rps                  ((float32_t)(100.0))


//! \brief Defines the pole location for the voltage and current offset estimation, rad/s
//!
#define USER_M1_OFFSET_POLE_rps                 ((float32_t)(20.0))


//! \brief Defines the pole location for the speed control filter, rad/sec
//!
#define USER_M1_SPEED_POLE_rps                  ((float32_t)(100.0))


//! \brief Defines the pole location for the direction filter, rad/sec
//!
#define USER_M1_DIRECTION_POLE_rps             (MATH_TWO_PI * (float32_t)(10.0))


//! \brief Defines the pole location for the second direction filter, rad/sec
//!
#define USER_M1_DIRECTION_POLE_2_rps           (MATH_TWO_PI * (float32_t)(100.0))


//! \brief Defines the pole location for the flux estimation, rad/sec
//!
#define USER_M1_FLUX_POLE_rps                  ( (float32_t)(10.0))

//! \brief Defines the pole location for the R/L estimation, rad/sec
//!
#define USER_M1_R_OVER_L_POLE_rps              (MATH_TWO_PI * (float32_t)(3.2))

//! \brief Defines the convergence factor for the estimator
//!
#define USER_M1_EST_KAPPAQ                          ((float32_t)(1.5f))


//! \brief Defines the scale factor for the flux estimation
//! the default value is 1.0f, change the value between 0.1f and 1.25f
//!
//#define USER_M1_EST_FLUX_HF_SF                     ((float32_t)(0.120f))
#define USER_M1_EST_FLUX_HF_SF                     ((float32_t)(0.250f))
//#define USER_M1_EST_FLUX_HF_SF                     ((float32_t)(1.00f))

//! \brief Defines the scale factor for the frequency estimation
//! the default value is 1.0f, change the value between 0.5f and 1.5f
//!
#define USER_M1_EST_FREQ_HF_SF                     ((float32_t)(1.00f))

//! \brief Defines the scale factor for the bemf estimation
//! the default value is 1.0f, change the value between 0.50f and 1.25f
//!
#define USER_M1_EST_BEMF_HF_SF                     ((float32_t)(1.00f))

//------------------------------------------------------------------------------
//! brief Define the Kp gain for Field Weakening Control
#define USER_M1_FWC_KP                 0.0225

//! brief Define the Ki gain for Field Weakening Control
#define USER_M1_FWC_KI                 0.00225

//! brief Define the maximum current vector angle for Field Weakening Control
#define USER_M1_FWC_MAX_ANGLE          -10.0f                        // degree
#define USER_M1_FWC_MAX_ANGLE_RAD      USER_M1_FWC_MAX_ANGLE /180.0f * MATH_PI

//! brief Define the minimum current vector angle for Field Weakening Control
#define USER_M1_FWC_MIN_ANGLE          0.0f                          // degree
#define USER_M1_FWC_MIN_ANGLE_RAD      USER_M1_FWC_MIN_ANGLE /180.0f * MATH_PI

//! \brief Defines the number of DC bus over/under voltage setting time
//!  timer base = 5ms
#define USER_M1_VOLTAGE_FAULT_TIME_SET          (500)

//! \brief Defines the number of motor over load setting time
//!  timer base = 5ms, 1s
#define USER_M1_OVER_LOAD_TIME_SET              (200)

//! \brief Defines the number of motor stall setting time
//!  timer base = 5ms, 1s
#define USER_M1_STALL_TIME_SET                  (200)

//! \brief Defines the number of phase unbalance setting time
//!  timer base = 5ms, 5s
#define USER_M1_UNBALANCE_TIME_SET              (1000)

//! \brief Defines the number of lost phase setting time
//!  timer base = 5ms, 10s
#define USER_M1_LOST_PHASE_TIME_SET             (2000)

//! \brief Defines the number of over speed setting time
//!  timer base = 5ms
#define USER_M1_OVER_SPEED_TIME_SET             (600)

//! \brief Defines the number of startup failed setting time
//!  timer base = 5ms, 10s
#define USER_M1_STARTUP_FAIL_TIME_SET           (2000)

//! \brief Defines the number of over load setting times
//!
#define USER_M1_OVER_CURRENT_TIMES_SET          (5)

//! \brief Defines the number of stop wait time
//!  timer base = 5ms, 10s
#define USER_M1_STOP_WAIT_TIME_SET              (1000)

//! \brief Defines the number of restart wait time
//!  timer base = 5ms, 10s
#define USER_M1_RESTART_WAIT_TIME_SET           (1000)

//! \brief Defines the number of restart time
//!
#define USER_M1_START_TIMES_SET                 (3)

//! \brief Defines the alignment time
//!
#define USER_M1_ALIGN_TIMES_SET                 (2000)     // ctrl period

//!
//!
#define USER_M1_QEP_UNIT_TIMER_TICKS            (uint32_t)(USER_SYSTEM_FREQ_MHz/(2.0f * USER_M1_ISR_FREQ_Hz) * 1000000.0f)

//==============================================================================
// Motor defines

#define USER_MOTOR1 my_pm_motor_1

#define MOTOR_CHOICE_200W   0
#define MOTOR_CHOICE_400W  0
#define MOTOR_CHOICE_900W   0
#define MOTOR_CHOICE_48V400W   0
#define MOTOR_CHOICE_XINRUI   0
#define MOTOR_CHOICE_KANGNI   0
#define MOTOR_CHOICE_meidi   0
#define MOTOR_CHOICE_chixi  0
//------------------------------------------------------------------

#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.077951886)
#define USER_MOTOR1_Ls_d_H                 (0.00009795517)
#define USER_MOTOR1_Ls_q_H                 (0.00009795517)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.06931074)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (3.0f)                        //����������,�������0.1~0.2����ʶб�µ������粻��ת��������������
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.5f)                        //���ӵ�й������(������)���������-0.1 ~ -0.2
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (30.0f)                        //���㶨�ӵ�� (Ls) �ʹ�ͨ�����ԽСƵ����ҪԽ�����ͨ�͵�й���׶ε��ֹͣ�������Ӹ�Ƶ��
#define USER_MOTOR1_INERTIA_Kgm2           (2.8e-05)

#if (USER_MOTOR1 == my_pm_motor_1)
#if MOTOR_CHOICE_chixi
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.1380543)
#define USER_MOTOR1_Ls_d_H                 (2.6380474E-4)
#define USER_MOTOR1_Ls_q_H                 (2.6380474E-4)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.037428726)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (11.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (2.8e-05)

#elif MOTOR_CHOICE_meidi
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (8)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.035648562)
#define USER_MOTOR1_Ls_d_H                 (5.736165E-5)
#define USER_MOTOR1_Ls_q_H                 (5.736165E-5)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.02978852)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (15.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (5.8e-05)

#elif MOTOR_CHOICE_200W
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.238852248)
#define USER_MOTOR1_Ls_d_H                 (0.000343821011)
#define USER_MOTOR1_Ls_q_H                 (0.000343821011)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.05490241434)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (2.8e-05)
#elif MOTOR_CHOICE_KANGNI

#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.37000465)
#define USER_MOTOR1_Ls_d_H                 (7.094917E-4)
#define USER_MOTOR1_Ls_q_H                 (7.094917E-4)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.1679108)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (2.8e-05)

/*
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (2)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.11472059)
#define USER_MOTOR1_Ls_d_H                 (0.00021241474)
#define USER_MOTOR1_Ls_q_H                 (0.00021241474)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.02636226)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (30.0f)

//36V 400W
#if MOTOR_CHOICE_200W
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.238852248)
#define USER_MOTOR1_Ls_d_H                 (0.000343821011)
#define USER_MOTOR1_Ls_q_H                 (0.000343821011)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.05490241434)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (2.8e-05)
*/
#elif MOTOR_CHOICE_400W
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.15055342)
#define USER_MOTOR1_Ls_d_H                 (0.000230621692)
#define USER_MOTOR1_Ls_q_H                 (0.000230621692)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.0682986006)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (10.5f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (5.8e-05)
#elif  MOTOR_CHOICE_900W
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (3)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (1.40885139)
#define USER_MOTOR1_Ls_d_H                 (0.00674297567)
#define USER_MOTOR1_Ls_q_H                 (0.00674297567)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.554637611)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (2.0f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (6.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (15.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (5.8e-05)
#elif  MOTOR_CHOICE_48V400W
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (5)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.13534182)
#define USER_MOTOR1_Ls_d_H                 (0.000212192)
#define USER_MOTOR1_Ls_q_H                 (0.000212192)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.07006894)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.5f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (11.0f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (20.0f)
#define USER_MOTOR1_INERTIA_Kgm2              (5.8e-05)

#elif  MOTOR_CHOICE_XINRUI
#define USER_MOTOR1_TYPE                   MOTOR_TYPE_PM
#define USER_MOTOR1_NUM_POLE_PAIRS         (7)
#define USER_MOTOR1_Rr_Ohm                 (0)
#define USER_MOTOR1_Rs_Ohm                 (0.1)
#define USER_MOTOR1_Ls_d_H                 (0.00014)
#define USER_MOTOR1_Ls_q_H                 (0.00014)
#define USER_MOTOR1_RATED_FLUX_VpHz        (0.026228967)
#define USER_MOTOR1_MAGNETIZING_CURRENT_A  (0)
#define USER_MOTOR1_RES_EST_CURRENT_A      (1.0f)
#define USER_MOTOR1_IND_EST_CURRENT_A      (-1.0f)
#define USER_MOTOR1_MAX_CURRENT_A          (7.5f)
#define USER_MOTOR1_FLUX_EXC_FREQ_Hz       (42.0f)

#define USER_MOTOR1_INERTIA_Kgm2              (1.13e-03)
#endif
// Number of lines on the motor's quadrature encoder
#define USER_MOTOR1_NUM_ENC_SLOTS          (2500)


#define USER_MOTOR1_FREQ_NEARZEROLIMIT_Hz  (0.0f)          // Hz

#define USER_MOTOR1_RATED_VOLTAGE_V        (36.0f)
#define USER_MOTOR1_RATED_SPEED_KRPM       (3.0f)

#define USER_MOTOR1_FREQ_MIN_HZ            (9.0f)          // Hz
#define USER_MOTOR1_FREQ_MAX_HZ            (350.0f)         // Hz

#define USER_MOTOR1_FREQ_LOW_HZ            (5.0f)            // Hz
#define USER_MOTOR1_FREQ_HIGH_HZ           (250.0f)          // Hz
#define USER_MOTOR1_VOLT_MIN_V             (1.0f)            // Volt
#define USER_MOTOR1_VOLT_MAX_V             (36.0f)           // Volt

#define USER_MOTOR1_FORCE_DELTA_A          (0.05f)          // A
#define USER_MOTOR1_ALIGN_DELTA_A          (0.01f)          // A
#define USER_MOTOR1_FLUX_CURRENT_A         (1.5f)           // A
#define USER_MOTOR1_ALIGN_CURRENT_A        (1.5f)//(1.5f)           // A
#define USER_MOTOR1_STARTUP_CURRENT_A      (11.0f)           // A
#define USER_MOTOR1_TORQUE_CURRENT_A       (2.0f)           // A
#define USER_MOTOR1_OVER_CURRENT_A         (15.0f)           // A

#define USER_MOTOR1_BRAKE_CURRENT_A        (1.0f)           // A
#define USER_MOTOR1_BRAKE_TIME_DELAY       (12000U)        // 60s/5ms

#define USER_MOTOR1_SPEED_START_Hz         (20.0f)
#define USER_MOTOR1_SPEED_FORCE_Hz         (15.0f)
#define USER_MOTOR1_ACCEL_START_Hzps       (10.0f)
#define USER_MOTOR1_ACCEL_MAX_Hzps         (20.0f) // (20.0f)

#define USER_MOTOR1_SPEED_FS_Hz            (3.0f)

// only for encoder
#define USER_MOTOR1_ENC_POS_MAX            (USER_MOTOR1_NUM_ENC_SLOTS * 4 - 1)
#define USER_MOTOR1_ENC_POS_OFFSET         (668)

// Only for eSMO
#define USER_MOTOR1_KSLIDE_MAX             (0.75f)      //
#define USER_MOTOR1_KSLIDE_MIN             (0.15f)

#define USER_MOTOR1_PLL_KP_MAX             (6.75f)      //
#define USER_MOTOR1_PLL_KP_MIN             (0.75f)
#define USER_MOTOR1_PLL_KP_SF              (5.0f)

#define USER_MOTOR1_BEMF_THRESHOLD         (0.5f)
#define USER_MOTOR1_BEMF_KSLF_FC_Hz        (1.0f)
#define USER_MOTOR1_THETA_OFFSET_SF        (1.0f)
#define USER_MOTOR1_SPEED_LPF_FC_Hz        (200.0f)

// for IS-BLDC
#define USER_MOTOR1_RAMP_START_Hz           (3.0f)
#define USER_MOTOR1_RAMP_END_Hz             (30.0f)
#define USER_MOTOR1_RAMP_DELAY              (5)

#define USER_MOTOR1_ISBLDC_INT_MAX          (0.015f)
#define USER_MOTOR1_ISBLDC_INT_MIN          (0.010f)

// for Rs online calibration
#define USER_MOTOR1_RSONLINE_WAIT_TIME      (60000U)    // 5min/300s at 5ms base
#define USER_MOTOR1_RSONLINE_WORK_TIME      (24000U)     //2min/120s at 5ms base

#endif


//! \brief Defines the maximum current slope for Id trajectory
//!
#define USER_M1_MAX_CURRENT_DELTA_A        (USER_MOTOR1_RES_EST_CURRENT_A / USER_M1_ISR_FREQ_Hz)


//! \brief Defines the maximum current slope for Id trajectory during power warp mode
//!
#define USER_M1_MAX_CURRENT_DELTA_PW_A    (0.3 * USER_MOTOR1_RES_EST_CURRENT_A / USER_M1_ISR_FREQ_Hz)

// **************************************************************************
// the Defines
#define USER_M1_POT_ADC_MIN                 (200U)

#define USER_M1_POT_SPEED_SF                USER_MOTOR1_FREQ_MAX_HZ / ((float32_t)(4096.0f - USER_M1_POT_ADC_MIN))

//! \brief Defines the minimum frequency for pot
#define USER_M1_POT_SPEED_MIN_Hz            (USER_MOTOR1_FREQ_MAX_HZ * 0.1f)

//! \brief Defines the maximum frequency input
#define USER_M1_POT_SPEED_MAX_Hz            (USER_MOTOR1_FREQ_MAX_HZ * 0.5f)

//! \brief Defines the pot signal wait delay time
#define USER_M1_WAIT_TIME_SET               (500U)         // 0.5s/1ms

//! \brief Defines the minimum frequency for pulse input
#define USER_M1_SPEED_CAP_MIN_Hz            (20.0f)

//! \brief Defines the maximum frequency for pulse input
#define USER_M1_SPEED_CAP_MAX_Hz            (600.0f)

//! \brief Defines the pulse capture wait delay time
#define USER_M1_CAP_WAIT_TIME_SET           (200U)     // 0.2s/1ms

//! \brief Defines the switch signal wait delay time
#define USER_M1_SWITCH_WAIT_TIME_SET        (50U)      // 0.05s/1ms

// **************************************************************************
// the typedefs


// **************************************************************************
// the globals


// **************************************************************************
// the functions
//! \param[in]  pUserParams  The pointer to the user param structure
extern void USER_setMotor1Params(USER_Params *pUserParams);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // end of USER_MTR1_H definition

