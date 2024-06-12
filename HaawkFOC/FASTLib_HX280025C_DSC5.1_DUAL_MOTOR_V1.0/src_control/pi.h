//#############################################################################
//
// FILE:   pi.h
//

//#############################################################################

#ifndef PI_H
#define PI_H
#include "hx_intrinsics.h"
#include "always.h"
#include <stddef.h>
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
//! \defgroup PI PI
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Defines the PI controller object
//
//*****************************************************************************
typedef struct _PI_Obj_
{
    float32_t Kp;                //!< the proportional gain for the PI controller
    float32_t Ki;                //!< the integral gain for the PI controller
    float32_t Ui;                //!< the integrator start value for the PI
                               //!< controller
    float32_t refValue;          //!< the reference input value
    float32_t fbackValue;        //!< the feedback input value
    float32_t ffwdValue;         //!< the feedforward input value
    float32_t outMin;            //!< the minimum output value allowed for the PI
                               //!< controller
    float32_t outMax;            //!< the maximum output value allowed for the PI
                               //!< controller
} PI_Obj;

//*****************************************************************************
//
//! \brief Defines the PI handle
//
//*****************************************************************************
typedef struct _PI_Obj_ *PI_Handle;


//*****************************************************************************
//
//! \brief     Gets the feedback value in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The feedback value in the PI controller
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE float32_t
PI_getFbackValue(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->fbackValue);
} // end of PI_getFbackValue() function

//*****************************************************************************
//
//! \brief     Gets the feedforward value in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The feedforward value in the PI controller
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE float32_t
PI_getFfwdValue(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->ffwdValue);
} // end of PI_getFfwdValue() function

//*****************************************************************************
//
//! \brief      Gets the gains in the PI controller
//!
//! \param[in]  handle  The PI controller handle
//!
//! \param[out] pKp     The pointer to the proportional gain value
//!
//! \param[out] pKi     The pointer to the integrator gain value
//!
//! \return     None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_getGains(PI_Handle handle, float32_t *pKp, float32_t *pKi)
{
    PI_Obj *obj = (PI_Obj *)handle;

    *pKp = obj->Kp;
    *pKi = obj->Ki;

    return;
} // end of PI_getGains() function

//*****************************************************************************
//
//! \brief     Gets the integral gain in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The integral gain in the PI controller
//
//*****************************************************************************
static ALWAYSINLINE float32_t
PI_getKi(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->Ki);
} // end of PI_getKi() function

//*****************************************************************************
//
//! \brief     Gets the proportional gain in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The proportional gain in the PI controller
//
//*****************************************************************************
static ALWAYSINLINE float32_t
PI_getKp(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->Kp);
} // end of PI_getKp() function

//*****************************************************************************
//
//! \brief      Gets the minimum and maximum output value allowed in the PI
//!             controller
//!
//! \param[in]  handle   The PI controller handle
//!
//! \param[out] pOutMin  The pointer to the minimum output value allowed
//!
//! \param[out] pOutMax  The pointer to the maximum output value allowed
//!
//! \return     None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_getMinMax(PI_Handle handle, float32_t *pOutMin, float32_t *pOutMax)
{
    PI_Obj *obj = (PI_Obj *)handle;

    *pOutMin = obj->outMin;
    *pOutMax = obj->outMax;

    return;
} // end of PI_getMinMax() function

//*****************************************************************************
//
//! \brief      Gets the maximum output value allowed in the PI controller
//!
//! \param[in]  handle  The PI controller handle
//!
//! \return     The maximum output value allowed
//
//*****************************************************************************
static ALWAYSINLINE float32_t
PI_getOutMax(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->outMax);
} // end of PI_getOutMax() function

//*****************************************************************************
//
//! \brief      Gets the minimum output value allowed in the PI controller
//!
//! \param[in]  handle  The PI controller handle
//!
//! \return     The minimum output value allowed
//
//*****************************************************************************
static ALWAYSINLINE float32_t
PI_getOutMin(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->outMin);
} // end of PI_getOutMin() function

//*****************************************************************************
//
//! \brief     Gets the reference value in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The reference value in the PI controller
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE float32_t
PI_getRefValue(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->refValue);
} // end of PI_getRefValue() function

//*****************************************************************************
//
//! \brief     Gets the integrator start value in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \return    The integrator start value for the PI controller
//
//*****************************************************************************
static ALWAYSINLINE  float32_t
PI_getUi(PI_Handle handle)
{
    PI_Obj *obj = (PI_Obj *)handle;

    return(obj->Ui);
} // end of PI_getUi() function

//*****************************************************************************
//
//! \brief     Initializes the PI controller
//!
//! \param[in] pMemory   A pointer to the memory for the PI controller object
//!
//! \param[in] numBytes  The number of bytes allocated for the PI controller
//!                      object, bytes
//!
//! \return    The PI controller (PI) object handle
//
//*****************************************************************************
extern PI_Handle
PI_init(void *pMemory, const size_t numBytes);

extern PI_Handle
cla_PI_init(void *pMemory, const size_t numBytes);

//*****************************************************************************
//
//! \brief     Sets the feedback value in the PI controller
//!
//! \param[in] handle      The PI controller handle
//!
//! \param[in] fbackValue  The feedback value
//!
//! \return    None
//
//*****************************************************************************
static ALWAYSINLINE void
PI_setFbackValue(PI_Handle handle, const float32_t fbackValue)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->fbackValue = fbackValue;

    return;
} // end of PI_setFbackValue() function

//*****************************************************************************
//
//! \brief     Sets the feedforward value in the PI controller
//!
//! \param[in] handle     The PI controller handle
//!
//! \param[in] ffwdValue  The feedforward value
//!
//! \return    None
//
//*****************************************************************************
static ALWAYSINLINE void
PI_setFfwdValue(PI_Handle handle, const float32_t ffwdValue)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->ffwdValue = ffwdValue;

    return;
} // end of PI_setFfwdValue() function

//*****************************************************************************
//
//! \brief     Sets the gains in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] Kp      The proportional gain for the PI controller
//!
//! \param[in] Ki      The integrator gain for the PI controller
//!
//! \return    None
//
//*****************************************************************************
static ALWAYSINLINE void
PI_setGains(PI_Handle handle, const float32_t Kp, const float32_t Ki)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->Kp = Kp;
    obj->Ki = Ki;

    return;
} // end of PI_setGains() function

//*****************************************************************************
//
//! \brief     Sets the integral gain in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] Ki         The integral gain for the PI controller
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_setKi(PI_Handle handle, const float32_t Ki)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->Ki = Ki;

    return;
} // end of PI_setKi() function

//*****************************************************************************
//
//! \brief     Sets the proportional gain in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] Kp         The proportional gain for the PI controller
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_setKp(PI_Handle handle, const float32_t Kp)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->Kp = Kp;

    return;
} // end of PI_setKp() function

//*****************************************************************************
//
//! \brief     Sets the minimum and maximum output value allowed in the PI
//!            controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] outMin  The minimum output value allowed
//!
//! \param[in] outMax  The maximum output value allowed
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_setMinMax(PI_Handle handle, const float32_t outMin, const float32_t outMax)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->outMin = outMin;
    obj->outMax = outMax;

    return;
} // end of PI_setMinMax() function

//*****************************************************************************
//
//! \brief     Sets the maximum output value allowed in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] outMax  The maximum output value allowed
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_setOutMax(PI_Handle handle, const float32_t outMax)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->outMax = outMax;

    return;
} // end of PI_setOutMax() function

//*****************************************************************************
//
//! \brief     Sets the minimum output value allowed in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] outMax  The minimum output value allowed
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_setOutMin(PI_Handle handle, const float32_t outMin)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->outMin = outMin;

    return;
} // end of PI_setOutMin() function

//*****************************************************************************
//
//! \brief     Sets the reference value in the PI controller
//!
//! \param[in] handle    The PI controller handle
//!
//! \param[in] refValue  The reference value
//!
//! \return    None
//
//*****************************************************************************
static ALWAYSINLINE void
PI_setRefValue(PI_Handle handle, const float32_t refValue)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->refValue = refValue;

    return;
} // end of PI_setRefValue() function

//*****************************************************************************
//
//! \brief     Sets the integrator start value in the PI controller
//!
//! \param[in] handle  The PI controller handle
//!
//! \param[in] Ui      The integral start value for the PI controller
//!
//! \return    None
//
//*****************************************************************************
static ALWAYSINLINE void
PI_setUi(PI_Handle handle, const float32_t Ui)
{
    PI_Obj *obj = (PI_Obj *)handle;

    obj->Ui = Ui;

    return;
} // end of PI_setUi() function

//*****************************************************************************
//
//! \brief     Runs the parallel form of the PI controller
//!
//! \param[in] handle      The PI controller handle
//!
//! \param[in] refValue    The reference value to the controller
//!
//! \param[in] fbackValue  The feedback value to the controller
//!
//! \param[in] ffwdValue   The feedforward value to the controller
//!
//! \param[in] pOutValue   The pointer to the controller output value
//!
//! \return    None
//
//*****************************************************************************
static inline void
PI_run_parallel(PI_Handle handle, const float32_t refValue,
                const float32_t fbackValue, const float32_t ffwdValue,
                float32_t *pOutValue)
{
    float32_t Error;
    float32_t Kp = PI_getKp(handle);
    float32_t Ki = PI_getKi(handle);
    float32_t Up;
    float32_t Ui = PI_getUi(handle);
    float32_t outMax = PI_getOutMax(handle);
    float32_t outMin = PI_getOutMin(handle);

    Error = refValue - fbackValue;

    //
    // Compute the proportional output
    //
    Up = Kp * Error;
    
    //
    // Compute the integral output
    //
    Ui = __fsat(Ui + (Ki * Error),outMax,outMin);

    PI_setUi(handle,Ui);
    PI_setRefValue(handle,refValue);
    PI_setFbackValue(handle,fbackValue);
    PI_setFfwdValue(handle,ffwdValue);

    //
    // Saturate the output
    //
    *pOutValue = __fsat(Up + Ui + ffwdValue,outMax,outMin);

    return;
} // end of PI_run_parallel() function

//*****************************************************************************
//
//! \brief     Runs the series form of the PI controller
//!
//! \param[in] handle      The PI controller handle
//!
//! \param[in] refValue    The reference value to the controller
//!
//! \param[in] fbackValue  The feedback value to the controller
//!
//! \param[in] ffwdValue   The feedback value to the controller
//!
//! \param[in] pOutValue   The pointer to the controller output value
//!
//! \return    None
//
//*****************************************************************************
static inline void
PI_run_series(PI_Handle handle, const float32_t refValue,
              const float32_t fbackValue, const float32_t ffwdValue,
              float32_t *pOutValue)
{
    float32_t Error;
    float32_t Kp = PI_getKp(handle);
    float32_t Ki = PI_getKi(handle);
    float32_t Up;
    float32_t Ui = PI_getUi(handle);
    float32_t outMax = PI_getOutMax(handle);
    float32_t outMin = PI_getOutMin(handle);

    Error = refValue - fbackValue;

    //
    // Compute the proportional output
    //
    Up = Kp * Error;

    //
    // Compute the integral output with saturation
    //
#ifdef __TMS320C28XX_CLA__
    Ui = MATH_sat(Ui + (Ki * Up), outMax, outMin);
#else
    Ui = __fsat(Ui + (Ki * Up), outMax, outMin);
#endif  // __TMS320C28XX_CLA__

    PI_setUi(handle,Ui);
    PI_setRefValue(handle, refValue);
    PI_setFbackValue(handle, fbackValue);
    PI_setFfwdValue(handle, ffwdValue);

    //
    // Saturate the output
    //
#ifdef __TMS320C28XX_CLA__
    *pOutValue = MATH_sat(Up + Ui + ffwdValue, outMax, outMin);
#else
    *pOutValue = __fsat(Up + Ui + ffwdValue, outMax, outMin);
#endif  // __TMS320C28XX_CLA__

    return;
} // end of PI_run_series() function


//*****************************************************************************
//
//! \brief     Runs the series form of the PI controller
//!
//! \param[in] handle      The PI controller handle
//!
//! \param[in] refValue    The reference value to the controller
//!
//! \param[in] fbackValue  The feedback value to the controller
//!
//! \param[in] pOutValue   The pointer to the controller output value
//!
//! \return    None
//
//*****************************************************************************
static __UNUSED ALWAYSINLINE void
PI_run(PI_Handle handle, const float32_t refValue,
       const float32_t fbackValue, float32_t *pOutValue)
{
    float32_t Error;
    float32_t Kp = PI_getKp(handle);
    float32_t Ki = PI_getKi(handle);
    float32_t Up;
    float32_t Ui = PI_getUi(handle);
    float32_t outMax = PI_getOutMax(handle);
    float32_t outMin = PI_getOutMin(handle);

    Error = refValue - fbackValue;

    // Compute the proportional output
    Up = Kp * Error;

    // Compute the integral output with saturation
#ifdef __TMS320C28XX_CLA__
    Ui = MATH_sat(Ui + (Ki * Up), outMax, outMin);
#else
    Ui = __fsat(Ui + (Ki * Up), outMax, outMin);
#endif  // __TMS320C28XX_CLA__

    PI_setUi(handle,Ui);
    PI_setRefValue(handle, refValue);
    PI_setFbackValue(handle, fbackValue);

    // Saturate the output
#ifdef __TMS320C28XX_CLA__
    *pOutValue = MATH_sat(Up + Ui, outMax, outMin);
#else
    *pOutValue = __fsat(Up + Ui, outMax, outMin);
#endif  // __TMS320C28XX_CLA__

    return;
} // end of PI_run_series() function

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

#endif // end of PI_H defines
