//#############################################################################

//#############################################################################

#ifndef EST_LS_STATES_H
#define EST_LS_STATES_H

//! \file   libraries/observers/est/include/est_Ls_states.h
//! \brief  Contains the states for the stator
//!         inductance estimator (EST_Ls) module routines
//!


// **************************************************************************
// the includes


//!
//!
//! \addtogroup EST
//!
//! @{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

//! \brief Enumeration for the stator inductance estimator error codes
//!
typedef enum
{
  EST_LS_ERRORCODE_NOERROR=0,       //!< no error error code
  EST_LS_ERRORCODE_SHIFTOVERFLOW,   //!< inductance shift overflow error code
  EST_LS_NUMERRORCODES              //!< the number of estimator error codes
} EST_Ls_ErrorCode_e;


//! \brief Enumeration for the stator inductance estimator states
//!
typedef enum
{
  EST_LS_STATE_ERROR = 0,   //!< error
  EST_LS_STATE_IDLE = 1,    //!< idle
  EST_LS_STATE_RAMPUP = 2,  //!< the ramp up state
  EST_LS_STATE_INIT = 3,    //!< the init state
  EST_LS_STATE_COARSE = 4,  //!< the coarse estimation state
  EST_LS_STATE_FINE = 5,    //!< the fine estimation state
  EST_LS_STATE_DONE = 6,    //!< the done state
  EST_LS_NUMSTATES = 7      //!< number of stator inductance estimator states
} EST_Ls_State_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//! @} // ingroup
#endif // end of EST_LS_STATES_H definition

