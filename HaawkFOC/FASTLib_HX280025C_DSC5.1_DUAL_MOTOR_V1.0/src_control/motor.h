//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:26 CDT 2021 $
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

#ifndef MOTOR_H
#define MOTOR_H

//! \file   libraries/motor/include/motor.h for software library
//! \brief  Contains motor related definitions
//!


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
//! \defgroup MOTOR_LIB MOTOR_LIB
//! @{
//
//*****************************************************************************

// the includes

//#include "types.h"


// **************************************************************************
// the defines


// **************************************************************************
// the typedefs


//
//! \brief Enumeration for the motor types
//!
typedef enum
{
  MOTOR_TYPE_INDUCTION = 0,   //!< induction
  MOTOR_TYPE_PM               //!< permanent magnet
} MOTOR_Type_e;

//
//! \brief Enumeration for the Flying Start Mode
//
typedef enum
{
    FLYINGSTART_MODE_HALT    = 0,       //!< Halt Mode
    FLYINGSTART_MODE_STANDBY = 1        //!< Standby Mode
} FlyingStart_Mode_e;


//
//! \brief Enumeration for the braking Mode
//
typedef enum
{
    FREE_STOP_MODE           = 0,       //!< Free stop mode without braking
    HARDSWITCH_BRAKE_MODE    = 1,       //!< Hard switch braking mode
    FORCESTOP_BRAKE_MODE     = 2,       //!< Force alignment braking mode
    DYNAMIC_BRAKE_MODE       = 3,       //!< N/A, Dynamic braking mode
    REGENERATION_BRAKE_MODE  = 4        //!< N/A, Regeneration braking mode
} BRAKE_Mode_e;

//
//! \brief Enumeration for the control mode
//
typedef enum
{
    OPERATE_MODE_SPEED  = 0,           //!< Speed close loop running mode
    OPERATE_MODE_TORQUE = 1            //!< Torque close loop running mode
} OPERATE_Mode_e;

//! \brief Enumeration for the estimator mode
//
typedef enum
{
    SAMPLE_MODE_DCSS2  = 0,             //!< dclink_ss2
    SAMPLE_MODE_DCSS4  = 1,             //!< dclink_ss4
    SAMPLE_MODE_DCLINK = 2,             //!< dclink_ss
    SAMPLE_MODE_3LSR   = 3,             //!< three_shunt
    SAMPLE_MODE_3INL   = 4,             //!< inline
    SAMPLE_MODE_SDFM   = 5              //!< sdfm
} SAMPLE_Mode_e;

//! \brief Enumeration for the motor drive control state
//
typedef enum
{
    MCTRL_INIT_SET     = 0,         //!< Initialize run time parameters
    MCTRL_FAULT_STOP   = 1,         //!< motor stop with fault
    MCTRL_BRAKE_STOP   = 2,         //!< motor stop with braking
    MCTRL_FIRST_RUN    = 3,         //!< First start the motor
    MCTRL_NORM_STOP    = 4,         //!< Normal stop
    MCTRL_CONT_RUN     = 4          //!< Continue run the motor
} MCTRL_State_e;


// State machine typedef for motor running status
typedef enum
{
    MOTOR_STOP_IDLE     = 0,
    MOTOR_BRAKE_STOP    = 1,
    MOTOR_SEEK_POS      = 2,
    MOTOR_ALIGNMENT     = 3,
    MOTOR_OL_START      = 4,
    MOTOR_CL_RUNNING    = 5,
    MOTOR_CTRL_RUN      = 6
} MOTOR_Status_e;



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

#endif // end of MOTOR_LIB_H definition





