//#############################################################################

//#############################################################################

#ifndef EST_RS_STATES_H
#define EST_RS_STATES_H

//! \file   libraries/observers/est/include/est_Rs_states.h
//! \brief  Contains the public interface to the stator
//!         resistance estimator (EST_Rs) module routines
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

//! \brief Enumeration for the stator resistance estimator states
//!
typedef enum
{
  EST_RS_STATE_ERROR=0,     //!< error
  EST_RS_STATE_IDLE = 1,    //!< idle
  EST_RS_STATE_RAMPUP = 2,  //!< the Id ramp up state
  EST_RS_STATE_COARSE = 3,  //!< the coarse estimation state
  EST_RS_STATE_FINE = 4,    //!< the fine estimation state
  EST_RS_STATE_DONE = 5,    //!< the done state
  EST_RS_NUMSTATES = 6      //!< number of stator resistance estimator states
} EST_Rs_State_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//! @} // ingroup
#endif // end of EST_RS_STATES_H definition

