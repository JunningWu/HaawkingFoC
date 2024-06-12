//#############################################################################
//
// FILE:   svgen.h
//
// TITLE:  C28x InstaSPIN Space Vector Generator (SVGEN) library
//         (floating point)
//
//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:27 CDT 2021 $
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

#ifndef SVGEN_H
#define SVGEN_H

#include "self_math.h"
#include "always.h"
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
//! \defgroup SVGEN SVGEN
//! @{
//
//*****************************************************************************


//! \brief Enumeration for svpwm mode
//!
typedef enum
{
  SVM_COM_C = 0,                //!< SVPWM common SVM mode
  SVM_MIN_C = 1,                //!< DPWM minimum SVM mode
  SVM_MAX_C = 2,                //!< DPWM maximum SVM
  SVM_DQ_S  = 3                 //!< SVPWM standard DQ mode
} SVM_Mode_e;

//*****************************************************************************
//
//! \brief Defines the Space Vector Generator (SVGEN) object
//
//*****************************************************************************
typedef struct _SVGEN_Obj_
{
    float32_t oneOverDcBus_invV;    //!< The inverse DC bus voltage value, 1/V
    uint16_t sector;                //!< the sector value of space vector
    SVM_Mode_e svmMode;
} SVGEN_Obj;

//*****************************************************************************
//
//! \brief Defines the SVGEN handle
//
//*****************************************************************************
typedef struct _SVGEN_Obj_ *SVGEN_Handle;

//*****************************************************************************
//
//! \brief     Gets the one over DC bus voltage value
//!
//! \param[in] handle  The space vector generator (SVGEN) handle
//!
//! \return    The inverse DC bus voltage value, 1/V
//
//*****************************************************************************
static inline float32_t
SVGEN_getOneOverDcBus_invV(SVGEN_Handle handle)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    return(obj->oneOverDcBus_invV);
} // end of SVGEN_getOneOverDcBus_invV() function

//*****************************************************************************
//
//! \brief     Gets the spave vector mode
//!
//! \param[in] handle  The space vector generator (SVGEN) handle
//!
//! \return    The mode value of spave vector
//
//*****************************************************************************
static inline SVM_Mode_e SVGEN_getMode(SVGEN_Handle handle)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    return(obj->svmMode);
} // end of SVGEN_getMode() function


//*****************************************************************************
//
//! \brief     Gets the spave vector sector value
//!
//! \param[in] handle  The space vector generator (SVGEN) handle
//!
//! \return    The sector value of spave vector
//
//*****************************************************************************
static inline uint16_t SVGEN_getSector(SVGEN_Handle handle)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    return(obj->sector);
} // end of SVGEN_getSector() function

//*****************************************************************************
//
//! \brief     Sets the one over DC bus voltage value
//!
//! \param[in] handle            The space vector generator (SVGEN) handle
//!
//! \param[in] oneOverVbus_invV  The inverse DC bus voltage value, 1/V
//!
//! \return    None
//
//*****************************************************************************
static inline void
SVGEN_setOneOverDcBus_invV(SVGEN_Handle handle,
                           const float32_t oneOverDcBus_invV)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    obj->oneOverDcBus_invV = oneOverDcBus_invV;

    return;
} // end of SVGEN_setOneOverDcBus_invV() function

//*****************************************************************************
//
//! \brief     Sets the spave vector mode
//!
//! \param[in] handle  The space vector generator (SVGEN) handle
//!
//! \param[in] svmMode  The mode of spave vector
//!
//! \return    N/A
//
//*****************************************************************************
static inline void SVGEN_setMode(SVGEN_Handle handle, SVM_Mode_e svmMode)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    obj->svmMode = svmMode;

    return;
} // end of SVGEN_setMode() function

//*****************************************************************************
//
//! \brief     Sets the spave vector sector value
//!
//! \param[in] handle  The space vector generator (SVGEN) handle
//!
//! \param[in] sector  The sector value of spave vector
//!
//! \return    N/A
//
//*****************************************************************************
static inline void SVGEN_setSector(SVGEN_Handle handle, uint16_t sector)
{
    SVGEN_Obj *obj = (SVGEN_Obj *)handle;

    obj->sector = sector;

    return;
} // end of SVGEN_setSector() function

//*****************************************************************************
//
//! \brief     Sets up the space vector generator (SVGEN) module
//!
//! \param[in] handle             The space vector generator (SVGEN) handle
//!
//! \param[in] oneOverDcBus_invV  The inverse DC bus voltage value, 1/V
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
SVGEN_setup(SVGEN_Handle handle, const float32_t oneOverDcBus_invV)
{
    SVGEN_setOneOverDcBus_invV(handle,oneOverDcBus_invV);

    return;
} // end of SVGEN_setup() function

//*****************************************************************************
//
//! \brief     Initializes the space vector generator module
//!
//! \param[in] pMemory   A pointer to the space vector generator object memory
//!
//! \param[in] numBytes  The number of bytes allocated for the space vector
//!                      generator object, bytes
//!
//! \return    The state vector generator (SVGEN) object handle
//
//*****************************************************************************
extern SVGEN_Handle
SVGEN_init(void *pMemory, const size_t numBytes);

//*****************************************************************************
//
//! \brief  Implements a SVM that saturates at the level of MaxModulation.
//!
//! \param[in] handle    The space vector generator (SVGEN) handle
//!
//! \param[in] pVab_V    The pointer to the alpha/beta voltages, V
//!
//! \param[in] pVabc_pu  The pointer to the three phase voltages, pu
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
SVGEN_run(SVGEN_Handle handle, const MATH_Vec2 *pVab_V, MATH_Vec3 *pVabc_pu)
{
    float32_t Vmax_pu = 0,Vmin_pu = 0,Vcom_pu;
    float32_t oneOverDcBus_invV = SVGEN_getOneOverDcBus_invV(handle);
    SVM_Mode_e svmMode = SVGEN_getMode(handle);

    float32_t Valpha_pu = pVab_V->value[0] * oneOverDcBus_invV;
    float32_t Vbeta_pu = pVab_V->value[1] * oneOverDcBus_invV;

    float32_t Va_tmp = (float32_t)(0.5f) * Valpha_pu;
    float32_t Vb_tmp = MATH_SQRTTHREE_OVER_TWO * Vbeta_pu;

    float32_t Va_pu = Valpha_pu;

    //
    // -0.5*Valpha + sqrt(3)/2 * Vbeta
    //
    float32_t Vb_pu = -Va_tmp + Vb_tmp;

    //
    // -0.5*Valpha - sqrt(3)/2 * Vbeta
    float32_t Vc_pu = -Va_tmp - Vb_tmp;

    //
    // Find Vmax and Vmin
    //
    if(Va_pu > Vb_pu)
    {
        Vmax_pu = Va_pu;
        Vmin_pu = Vb_pu;
    }
    else
    {
        Vmax_pu = Vb_pu;
        Vmin_pu = Va_pu;
    }

    if(Vc_pu > Vmax_pu)
    {
        Vmax_pu = Vc_pu;
    }
    else if(Vc_pu < Vmin_pu)
    {
        Vmin_pu = Vc_pu;
    }

    // Compute Vcom = 0.5*(Vmax+Vmin)
    Vcom_pu = 0.5f * (Vmax_pu + Vmin_pu);

    if(svmMode == SVM_COM_C)
    {
        // Subtract common-mode term to achieve SV modulation
        pVabc_pu->value[0] = (Va_pu - Vcom_pu);
        pVabc_pu->value[1] = (Vb_pu - Vcom_pu);
        pVabc_pu->value[2] = (Vc_pu - Vcom_pu);
    }
    else if(svmMode == SVM_MIN_C)
    {
        pVabc_pu->value[0] = (Va_pu - Vmin_pu) - 0.5f;
        pVabc_pu->value[1] = (Vb_pu - Vmin_pu) - 0.5f;
        pVabc_pu->value[2] = (Vc_pu - Vmin_pu) - 0.5f;
    }
    else if(svmMode == SVM_MAX_C)
    {
        pVabc_pu->value[0] = (Va_pu - Vmax_pu) + 0.5f;
        pVabc_pu->value[1] = (Vb_pu - Vmax_pu) + 0.5f;
        pVabc_pu->value[2] = (Vc_pu - Vmax_pu) + 0.5f;
    }

    return;
} // end of SVGEN_run() function

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

#endif // end of SVGEN_H definition
