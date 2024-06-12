/*
 * HX_est.h
 *
 *  Created on: 2022Äê1ÔÂ19ÈÕ
 *      Author: haawking
 */

#ifndef SELF_INCLUDE_EST_H_
#define SELF_INCLUDE_EST_H_
#include "self_math.h"
#include "userParams.h"
#include "pi.h"
#include "est_Flux_states.h"
#include "est_Traj_states.h"
#include "est_states.h"

// the typedefs

//! \brief Enumeration for the Rs online filter types
//!
typedef enum
{
  EST_RSONLINEFILTERTYPE_CURRENT=0,        //!< Current Filter
  EST_RSONLINEFILTERTYPE_VOLTAGE           //!< Voltage Filter
} EST_RsOnLineFilterType_e;


//! \brief Defines the estimator (EST) input data
//!

typedef struct _EST_InputData_
{
  MATH_Vec2 Iab_A;              //!< the alpha/beta current values, A
  MATH_Vec2 Vab_V;              //!< the alpha/beta current values, V
  float32_t dcBus_V;            //!< the DC bus voltage value, V
  float32_t speed_ref_Hz;       //!< the speed reference value, Hz
} EST_InputData_t;

//! \brief Defines the estimator (EST) input data handle
//!
typedef struct _EST_InputData_      *EST_InputHandle;

//! \brief Defines the estimator (EST) output data
//!
typedef struct _EST_OutputData_
{
  float32_t angle_rad;          //!< the estimated angle value at t = m+1, rad
  float32_t fe_rps;             //!< the electrical frequency estimate, rad/sec
  float32_t fm_rps;             //!< the mechanical frequency estimate, rad/sec
  float32_t fm_lp_rps;          //!< the low pass filtered mechanical frequency estimate, rad/sec

  float32_t oneOverDcBus_invV;  //!< the DC Bus inverse, 1/V
} EST_OutputData_t;

//! \brief Defines the estimator (EST) output data handle
//!
typedef struct _EST_OutputData_     *EST_OutputHandle;


typedef struct _EST_Obj_ *EST_Handle;
 extern uint8_t est_motor_1[];

// **************************************************************************
// the function prototypes

//! \brief     Computes the magnetizing inductance in Henries (H)
//! \param[in] handle   The estimator (EST) handle
//! \param[in] current  The current in the rotor, A
//! \return    The magnetizing inductance, H
 extern  float32_t     EST_computeLmag_H(EST_Handle handle,const float32_t current_A);//flash


//! \brief     Computes the torque value in per Newton-meter (Nm)
//! \param[in] handle  The estimator (EST) handle
//! \return    The torque value, N*m
 extern  float32_t  EST_computeTorque_Nm(EST_Handle handle);//flash

//! \brief     Configures the trajectory generator for each of the estimator states
//! \param[in] handle  The estimator (EST) handle
 extern void   EST_configureTraj(EST_Handle handle);//flash

//! \brief     Disables the estimator
//! \param[in] handle  The estimator (EST) handle
 extern void   EST_disable(EST_Handle handle);//flash

//! \brief     Disables the estimator trajectory generator
//! \param[in] handle  The estimator (EST) handle
 extern void     EST_disableTraj(EST_Handle handle);//flash

//! \brief     Determines if current control should be performed during motor identification
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting whether (true) or not (false) to perform current control
 extern bool     EST_doCurrentCtrl(EST_Handle handle);//ram

//! \brief     Determines if speed control should be performed during motor identification
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting whether (true) or not (false) to perform speed control
 extern bool     EST_doSpeedCtrl(EST_Handle handle);//ram

//! \brief     Enables the estimator
//! \param[in] handle  The estimator (EST) handle
extern void     EST_enable(EST_Handle handle);//flash

//! \brief     Enables the estimator trajectory generator
//! \param[in] handle  The estimator (EST) handle
 extern  void     EST_enableTraj(EST_Handle handle);//flash

//! \brief     Gets the value of the flag which enables online stator resistance (Rs) estimation
//! \param[in] handle  The estimator (EST) handle
//! \return    The enable online Rs flag value
//! \retval
//!            true   Rs online recalibration algorithm is enabled. The estimator will run a set of
//!                   functions related to rs online which recalculates the stator resistance while the
//!                   motor is rotating. This algorithm is useful when motor heats up, and hence stator
//!                   resistance increases.
//! \retval
//!            false  Rs online recalibration algorithm is disabled, and no updates to Rs will be made
//!                   even if the motor heats up. Low speed performace, and startup performance with
//!                   full torque might be affected if stator resistance changes due to motor heating
//!                   up. The stator resistance will be fixed, and equal to the value returned by:
//!                   EST_getRs_Ohm().
 extern bool     EST_getFlag_enableRsOnLine(EST_Handle handle);//flash


//! \brief     Gets the flux value in Weber (Wb).
//! \details   The estimator continuously calculates the flux linkage between the rotor and stator, which is the
//!            portion of the flux that produces torque. This function returns the flux linkage, ignoring the
//!            number of turns, between the rotor and stator coils, in Weber, or Wb, or Volts * Seconds / rad (V.sec/rad).
//!            This functions returns a precise value only after the motor has been identified, which can be
//!            checked by the following code example:
//! \code
//! if(EST_isMotorIdentified(handle))
//!   {
//!     // once the motor has been identified, get the flux
//!     float32_t Flux_Wb = EST_getFlux_Wb(handle);
//!   }
//! \endcode
//! \param[in] handle  The estimator (EST) handle
//! \return    The flux value, Weber or V*sec/rad, in floating point
 extern float32_t  EST_getFlux_Wb(EST_Handle handle);//flash

//! \brief     Gets the low pass filtered mechanical frequency of the motor in Hz
//! \param[in] handle  The estimator (EST) handle
//! \return    The low pass filtered mechanical frequency, Hz
extern float32_t  EST_getFm_lp_Hz(EST_Handle handle);//ram

//! \brief     Gets the Id rated current value from the estimator in Ampere (A).
//! \param[in] handle  The estimator (EST) handle
//! \return    The Id rated current value, A
 extern float32_t  EST_getIdRated_A(EST_Handle handle);//ram


//! \brief     Gets the intermediate value from the Id trajectory generator
//! \param[in] handle  The estimator (EST) handle
//! \return    The intermediate value, A
 extern float32_t  EST_getIntValue_Id_A(EST_Handle handle);//ram

//! \brief     Gets the intermediate value from the speed trajectory generator
//! \param[in] handle  The estimator (EST) handle
//! \return    The intermediate value, Hz
extern float32_t  EST_getIntValue_spd_Hz(EST_Handle handle);//ram

//! \brief     Gets the direct stator inductance value in Henry (H).
//! \param[in] handle  The estimator (EST) handle
//! \return    The direct stator inductance value, H
 extern float32_t  EST_getLs_d_H(EST_Handle handle);//flash


//! \brief     Gets the stator inductance value in the quadrature coordinate direction in Henry (H).
//! \param[in] handle  The estimator (EST) handle
//! \return    The stator inductance value, H
 extern float32_t  EST_getLs_q_H(EST_Handle handle);//flash



//! \brief     Gets the R/L value from the estimator
//! \param[in] handle  The estimator (EST) handle
//! \return    The R/L value, rad/sec
 extern float32_t  EST_getRoverL_rps(EST_Handle handle);//flash


//! \brief     Gets the rotor resistance value in Ohms (\f$\Omega\f$).
//! \param[in] handle  The estimator (EST) handle
//! \return    The rotor resistance value, Ohm
 extern float32_t  EST_getRr_Ohm(EST_Handle handle);//flash

//! \brief     Gets the stator resistance value in Ohms (\f$\Omega\f$).
//! \param[in] handle  The estimator (EST) handle
//! \return    The stator resistance value, Ohm
 extern float32_t  EST_getRs_Ohm(EST_Handle handle);//flash

//! \brief     Gets the online stator resistance value in Ohm (\f$\Omega\f$).
//! \param[in] handle  The estimator (EST) handle
//! \return    The online stator resistance value, Ohm
 extern float32_t  EST_getRsOnLine_Ohm(EST_Handle handle);//flash

//! \brief     Gets the state of the estimator
//! \param[in] handle  The estimator (EST) handle
//! \return    The estimator state
 extern EST_State_e     EST_getState(EST_Handle handle);//ram

//! \brief     Gets the trajectory generator state
//! \param[in] handle  The estimator (EST) handle
//! \return    The state
 extern EST_Traj_State_e EST_getTrajState(EST_Handle handle);//flash

//! \brief     Determines if the estimator (EST) is enabled
//! \param[in] handle  The estimator (EST) handle
 extern bool     EST_isEnabled(EST_Handle handle);//ram

//! \brief     Determines if there is an error in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting if there is an error (true) or not (false)
 extern bool     EST_isError(EST_Handle handle);//flash

//! \brief     Determines if the estimator is idle
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting if the estimator is idle (true) or not (false)
 extern bool  EST_isIdle(EST_Handle handle);//flash

//! \brief     Determines if the estimator is waiting for the rotor to be locked
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting if the estimator is waiting for the rotor to be locked (true) or not (false)
 extern bool  EST_isLockRotor(EST_Handle handle);//flash

//! \brief     Determines if the motor has been identified
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting if the motor is identified (true) or not (false)
 extern bool  EST_isMotorIdentified(EST_Handle handle);//ram



//! \brief     Determines if there is an error in the trajectory generator
//! \param[in] handle  The estimator (EST) handle
//! \return    A boolean value denoting if there is an error (true) or not (false)
 extern bool     EST_isTrajError(EST_Handle handle);//flash



//! \brief     Runs the estimator
//! \param[in] handle       The estimator (EST) handle
//! \param[in] pInputData   The pointer to the input data
//! \param[in] pOutputData  The pointer to the output data
extern void   EST_run(EST_Handle handle,
                        const EST_InputData_t *pInputData,
                        EST_OutputData_t *pOutputData);//ram

//! \brief     Runs the trajectory generator
//! \param[in] handle  The estimator (EST) handle
 extern void     EST_runTraj(EST_Handle handle);//ram



//! \brief     Sets the angle value at t = n in both the estimator and trajectory in radians (rad).
//! \details   This function overwrites the estimated angle with a user's provided angle.
//!            The set value should be between -pi and pi
//!            The following example shows how to overwrite the estimated angle:
//! \code
//! float32_t Overwrite_Flux_Angle_rad = MATH_PI * 0.5;
//! EST_setAngle_rad(handle,Overwrite_Flux_Angle_rad);
//! \endcode
//! \details   This function is not recommended for general use, since this will automatically generate
//!            an axis misalignment between the rotor flux axis and the control signals driving the motor.
//!            The use of this function is recommended for advanced users interested in doing open loop
//!            startup algorithms that need to bypass the estimator.
//! \param[in] handle     The estimator (EST) handle
//! \param[in] angle_rad  The angle value at t = n, rad
 extern void  EST_setAngle_rad(EST_Handle handle,const float32_t angle_rad);//ram

//! \brief     Sets the bypass lock rotor flag value in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired state
 extern void  EST_setFlag_bypassLockRotor(EST_Handle handle,const bool state);//flash


//! \brief     Sets the enable force angle flag in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired flag state, on (1) or off (0)
//!            <b>true</b> Enable forced angle.
//!            <b>false</b> Disable forced angle.
 extern void  EST_setFlag_enableForceAngle(EST_Handle handle,const bool state);//flash

//! \brief     Sets the enable PowerWarp flag in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired flag state, on (1) or off (0)
 extern void  EST_setFlag_enablePowerWarp(EST_Handle handle,const bool state);//flash

//! \brief     Sets the enable Rs online flag in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired flag state, on (1) or off (0)
//!            <b>true</b> Enable the Rs online recalibration algorithm. The estimator will run a set of
//!                    functions related to rs online which recalculates the stator resistance while the
//!                    motor is rotating. This algorithm is useful when motor heats up, and hence stator
//!                    resistance increases.
//!            <b>false</b> Disable the Rs online recalibration algorithm. No updates to Rs will be made
//!                    even if the motor heats up. Low speed performace, and startup performance with
//!                    full torque might be affected if stator resistance changes due to motor heating up.
//!                    The stator resistance will be fixed, and equal to the value returned by EST_getRs_Ohm().
 extern void  EST_setFlag_enableRsOnLine(EST_Handle handle,const bool state);//flash

//! \brief     Sets the enable stator resistance (Rs) re-calculation flag in the estimator
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired flag state, on (1) or off (0)
//!            <b>true</b> Enable Rs recalibration. The estimator will inject a DC current to the D-axis
//!                    to recalibrate the stator resistance before the motor rotates. It is required that
//!                    the motor is at standstill to perform Rs recalibration. If online recalibration
//!                    of the stator resistance is needed, refer to EST_getFlag_enableRsOnLine() and
//!                    EST_setFlag_enableRsOnLine() functions.
//!            <b>false</b> Disable Rs recalibration. The estimator will start the motor with the resistance
//!                    value that was used before the motor was stopped, or what is returned by function:
//!                    EST_getRs_Ohm().
 extern void  EST_setFlag_enableRsRecalc(EST_Handle handle,const bool state);//flash


//! \brief     Sets the update stator resistance (Rs) flag in the estimator
//! \details   When the online resistance estimator is enabled, the update flag allows the online resistance
//!            to be copied to the resistance used by the estimator model. If the update flag is not set to true,
//!            the online resistance estimation will not be used by the estimator model, and if the resistance
//!            changes too much due to temperature increase, the model may not work as expected.
//! \code
//! EST_setFlag_updateRs(handle, true);
//! \endcode
//! \param[in] handle  The estimator (EST) handle
//! \param[in] state   The desired flag state
//!            <b>true</b> The stator resistance estimated by the Rs OnLine module will be copied to the'
//!                    the stator resistance used by the module, so of the motor's temperature changes,
//!                    the estimated angle will be calculated based on the most up to date stator
//!                    resistance
//!            <b>false</b> The stator resistance estimated by the Rs OnLine module may or may not be updated
//!                    depending on the enable flag, but will not be used in the motor's model used to generate
//!                    the estimated speed and angle.
 extern void  EST_setFlag_updateRs(EST_Handle handle,const bool state);//flash



//! \brief     Sets the direct current (Id) reference value in the estimator in Ampere (A).
//! \param[in] handle    The estimator (EST) handle
//! \param[in] Id_ref_A  The Id reference value, A
 extern void  EST_setId_ref_A(EST_Handle handle,const float32_t Id_ref_A);//ram

//! \brief     Sets the quadrature current (Iq) reference value in the estimator in Ampere (A).
//! \param[in] handle    The estimator (EST) handle
//! \param[in] Iq_ref_A  The Iq reference value, A
 extern void     EST_setIq_ref_A(EST_Handle handle,const float32_t Iq_ref_A);//ram

//! \brief     Sets the direct stator inductance value in the estimator in Henry (H).
//! \param[in] handle  The estimator (EST) handle
//! \param[in] Ls_d_H  The direct stator inductance value, Henry
 extern void     EST_setLs_d_H(EST_Handle handle,const float32_t Ls_d_H);//flash

//! \brief     Sets the quadrature stator inductance value in the estimator in Henry (H).
//! \param[in] handle  The estimator (EST) handle
//! \param[in] Ls_q_H  The quadrature stator inductance value, H
 extern void     EST_setLs_q_H(EST_Handle handle,const float32_t Ls_q_H);//flash

//! \brief     Sets the estimator parameters using the user parameters structreu
//! \param[in] handle       The estimator (EST) handle
//! \param[in] pUserParams  A pointer to the user parameters structure
 extern void  EST_setParams(EST_Handle handle, USER_Params *pUserParams);//flash

//! \brief     Sets the stator resistance value in the online stator resistance estimator in Ohm (\f$\Omega\f$).
//! \param[in] handle  The estimator (EST) handle
//! \param[in] Rs_Ohm  The stator resistance value, Ohm
 extern void  EST_setRsOnLine_Ohm(EST_Handle handle,const float32_t Rs_Ohm);//flash

//! \brief     Sets the Id value in the online stator resistance estimator in Ampere (A).
//! \param[in] handle  The estimator (EST) handle
//! \param[in] Id_A    The Id value, A
 extern void EST_setRsOnLineId_A(EST_Handle handle,const float32_t Id_A);//flash

//! \brief     Sets the Id magnitude value used for online stator resistance estimation in Ampere (A).
//! \param[in] handle    The estimator (EST) handle
//! \param[in] Id_mag_A  The Id magnitude value, A
 extern void EST_setRsOnLineId_mag_A(EST_Handle handle,const float32_t Id_mag_A);//flash



//! \brief     Updates the Id reference value used for online stator resistance estimation in Ampere (A).
//! \param[in] handle     The estimator (EST) handle
//! \param[in] pId_ref_A  The pointer to the Id reference value, A
 extern void     EST_updateId_ref_A(EST_Handle handle,float32_t *pId_ref_A);//ram

//! \brief      Updates the estimator state
//! \param[in]  handle       The estimator (EST) handle
//! \param[in]  Id_target_A  The target Id current during each estimator state, A
//! \return     A boolean value denoting if the state has changed (true) or not (false)
 extern bool     EST_updateState(EST_Handle handle,const float32_t Id_target_A);//flash

//! \brief      Updates the trajectory generator state
//! \param[in]  handle  The estimator (EST) handle
//! \return     A boolean value denoting if the state has changed (true) or not (false)
 extern bool     EST_updateTrajState(EST_Handle handle);//flash


//! \brief     Configures the controller for each of the estimator states
//! \param[in] handle      The estimator (EST) handle
//! \param[in] pUserParams A pointer to the user parameters structure
//! \param[in] oneOverFluxGain_sf The gain coefficient for flux estimation
 extern void  EST_setOneOverFluxGain_sf(EST_Handle handle,
                                         USER_Params *pUserParams,
                                         const float32_t oneOverFluxGain_sf);//flash

//! \brief     Configures the controller for each of the estimator states
//! \param[in] handle      The estimator (EST) handle
//! \param[in] pUserParams A pointer to the user parameters structure
//! \param[in] freqLFP_sf The low pass filter coefficient
 extern void EST_setFreqLFP_sf(EST_Handle handle, USER_Params *pUserParams,
                              const float32_t freqLFP_sf);//flash

//! \brief     Configures the controller for each of the estimator states
//! \param[in] handle      The estimator (EST) handle
//! \param[in] pUserParams A pointer to the user parameters structure
//! \param[in] bemf_sf     The bemf coefficient
 extern void EST_setBemf_sf(EST_Handle handle, USER_Params *pUserParams,
                              const float32_t bemf_sf);//flash


//! \brief     Sets up the trajectory generator
//! \param[in] handle                The trajectory generator (EST_Traj) handle
//! \param[in] Iq_A
//! \param[in] targetValue_spd_Hz    The target speed value during run time, Hz
//! \param[in] targetValue_Id_A      The target Id current value during run time, A
 extern void EST_setupTrajState(EST_Handle handle,
                               const float32_t Iq_A,
                               const float32_t targetValue_spd_Hz,
                               const float32_t targetValue_Id_A);//ram

//! \brief     Configures the controller for each of the estimator states
//! \param[in] handle      The estimator (EST) handle
//! \param[in] pUserParams
 extern void EST_configureTrajState(EST_Handle handle, USER_Params *pUserParams,
                                   PI_Handle piHandle_spd,
                                   PI_Handle piHandle_Id, PI_Handle piHandle_Iq);//flash

extern  void USER_setParams_priv(USER_Params *pUserParams);//flash
#endif /* SELF_INCLUDE_HX_EST_H_ */
