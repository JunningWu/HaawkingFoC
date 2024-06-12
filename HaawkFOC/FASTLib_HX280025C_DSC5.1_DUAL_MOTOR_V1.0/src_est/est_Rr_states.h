//#############################################################################

//#############################################################################

#ifndef EST_RR_STATES_H
#define EST_RR_STATES_H

//! \file   libraries/observers/est/include/est_Rr_states.h
//! \brief  Contains the public interface to the rotor
//!         resistance estimator (EST_Rr) module routines
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

//! \brief Enumeration for the rotor resistance estimator states
//!
typedef enum {
  EST_RR_STATE_ERROR=0,         //!< error
  EST_RR_STATE_IDLE = 1,        //!< idle
  EST_RR_STATE_RAMPUP = 2,      //!< the Id ramp up state
  EST_RR_STATE_COARSE = 3,      //!< the coarse estimation state
  EST_RR_STATE_FINE = 4,        //!< the fine estimation state
  EST_RR_STATE_DONE = 5,        //!< the done state
  EST_RR_NUMSTATES = 6          //!< number of stator resistance estimator states
} EST_Rr_State_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//! @} // ingroup
#endif // end of EST_RR_STATES_H definition

