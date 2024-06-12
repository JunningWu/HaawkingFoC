/*
 * self_struct.h
 *
 *  Created on: 2023Äê2ÔÂ1ÈÕ
 *  Author: KangAihong
 *
 *  Last revise: 2024/3/1
 *  reviser: GuanXingyu
 */

#ifndef SRC_CONTROL_TRANSFORM_H_
#define SRC_CONTROL_TRANSFORM_H_


#include "inc/hw_types.h"
#include "self_math.h"
#include "stdint.h"   // needed for C99 data types
#include "stdbool.h"  // needed for bool type, true/false
#include "always.h"


// the defines
#define MOD_INDEX_MAX      3


//*****************************************************************************
//
//! \brief Defines the CLARKE object
//
//*****************************************************************************
typedef struct _CLARKE_Obj_
{
    float32_t alpha_sf;           //!< the scale factor for the alpha component
    float32_t beta_sf;            //!< the scale factor for the beta component
    uint_least8_t numSensors;     //!< the number of sensors
} CLARKE_Obj;
typedef struct _CLARKE_Obj_ *CLARKE_Handle;


//*****************************************************************************
//
//! \brief Defines the IPARK object
//
//*****************************************************************************
typedef struct _IPARK_Obj_
{
    float32_t sinTh;    //!< the sine of the angle between the d,q and the alpha,
                      //!< beta coordinate systems
    float32_t cosTh;    //!< the cosine of the angle between the d,q and the
                      //!< alpha, beta coordinate systems
} IPARK_Obj;
typedef struct _IPARK_Obj_  *IPARK_Handle;


//*****************************************************************************
//
//! \brief Defines the PARK object
//
//*****************************************************************************
typedef struct _PARK_Obj_
{
    float32_t sinTh;     //!< the sine of the angle between the d,q and the
                       //!< alpha, beta coordinate systems
    float32_t cosTh;     //!< the cosine of the angle between the d,q and the
                       //!< alpha, beta coordinate systems
} PARK_Obj;
typedef struct _PARK_Obj_ *PARK_Handle;


//*****************************************************************************
//
//! \brief Defines the CPU_TIME handle
//
//*****************************************************************************
typedef struct _CPU_TIME_Obj_
{
  uint32_t  timerCntNow;
  uint32_t  timerCntPrev[MOD_INDEX_MAX];

  uint16_t  deltaNow[MOD_INDEX_MAX];    //!< the latest delta count value, cnts
  uint16_t  deltaMin[MOD_INDEX_MAX];    //!< the minimum delta counts, cnts
  uint16_t  deltaMax[MOD_INDEX_MAX];    //!< the maximum delta counts, cnts

  bool      flag_resetStatus;           //!< a flag to reset all measured data
} CPU_TIME_Obj;
typedef struct _CPU_TIME_Obj_ *CPU_TIME_Handle;


//*****************************************************************************
//
//! \brief     Runs the Clarke transform module for three inputs
//!
//! \param[in] handle        The Clarke transform handle
//!
//! \param[in] pInVec        The pointer to the input vector
//!
//! \param[in] pOutVec       The pointer to the output vector
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
CLARKE_run(CLARKE_Handle handle, const MATH_Vec3 *pInVec, MATH_Vec2 *pOutVec)
{
    CLARKE_Obj *obj = (CLARKE_Obj *)handle;

    uint_least8_t numSensors = obj->numSensors;

    float32_t alpha_sf = obj->alpha_sf;
    float32_t beta_sf = obj->beta_sf;

    //
    // Perform the Clarke transform for either 2 or 3 sensor setups
    //
    if(numSensors == 3)
    {
        pOutVec->value[0] =
            ((pInVec->value[0] *
              (float32_t)2.0f) - (pInVec->value[1] + pInVec->value[2])) * alpha_sf;
        pOutVec->value[1] = (pInVec->value[1] - pInVec->value[2]) * beta_sf;
    }
    else if(numSensors == 2)
    {
        pOutVec->value[0] = pInVec->value[0] * alpha_sf;
        pOutVec->value[1] =
            (pInVec->value[0] + (pInVec->value[1] * (float32_t)2.0f)) * beta_sf;
    }

    return;
} // end of CLARKE_run() function


//*****************************************************************************
//
//! \brief     Sets the cosine/sine phasor for the inverse Park transform
//!
//! \param[in] handle   The Park transform handle
//!
//! \param[in] pPhasor  The pointer to the cosine/sine phasor, pu
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PARK_setPhasor(PARK_Handle handle, const MATH_Vec2 *pPhasor)
{
    PARK_Obj *obj = (PARK_Obj *)handle;

    obj->cosTh = pPhasor->value[0];
    obj->sinTh = pPhasor->value[1];

    return;
} // end of PARK_setPhasor() function


//*****************************************************************************
//
//! \brief     Runs the Park transform module
//!
//! \param[in] handle  The Park transform handle
//!
//! \param[in] pInVec      The pointer to the input vector
//!
//! \param[in] pOutVec     The pointer to the output vector
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PARK_run(PARK_Handle handle, const MATH_Vec2 *pInVec, MATH_Vec2 *pOutVec)
{
    PARK_Obj *obj = (PARK_Obj *)handle;

    float32_t sinTh = obj->sinTh;
    float32_t cosTh = obj->cosTh;

    float32_t value_0 = pInVec->value[0];
    float32_t value_1 = pInVec->value[1];

    pOutVec->value[0] = (value_0 * cosTh) + (value_1 * sinTh);
    pOutVec->value[1] = (value_1 * cosTh) - (value_0 * sinTh);

    return;
} // end of PARK_run() function


//*****************************************************************************
//
//! \brief     Sets the cosine/sine phasor for the inverse Park transform
//!
//! \param[in] handle   The inverse Park transform handle
//!
//! \param[in] pPhasor  The pointer to the cosine/sine phasor, pu
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
IPARK_setPhasor(IPARK_Handle handle, const MATH_Vec2 *pPhasor)
{
    IPARK_Obj *obj = (IPARK_Obj *)handle;

    obj->cosTh = pPhasor->value[0];
    obj->sinTh = pPhasor->value[1];

    return;
} // end of IPARK_setPhasor() function


//*****************************************************************************
//
//! \brief     Runs the inverse Park transform module
//!
//! \param[in] handle  The inverse Park transform handle
//!
//! \param[in] pInVec       The pointer to the input vector
//!
//! \param[in] pOutVec      The pointer to the output vector
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
IPARK_run(IPARK_Handle handle, const MATH_Vec2 *pInVec, MATH_Vec2 *pOutVec)
{
    IPARK_Obj *obj = (IPARK_Obj *)handle;

    float32_t sinTh = obj->sinTh;
    float32_t cosTh = obj->cosTh;

    float32_t value_0 = pInVec->value[0];
    float32_t value_1 = pInVec->value[1];

    pOutVec->value[0] = (value_0 * cosTh) - (value_1 * sinTh);
    pOutVec->value[1] = (value_1 * cosTh) + (value_0 * sinTh);

    return;
} // end of IPARK_run() functio


#endif /* SRC_CONTROL_TRANSFORM_H_ */
