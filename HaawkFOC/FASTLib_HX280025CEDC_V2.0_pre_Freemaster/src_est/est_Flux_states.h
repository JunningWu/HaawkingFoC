//#############################################################################
//#############################################################################

#ifndef EST_FLUX_STATES_H
#define EST_FLUX_STATES_H

//! \file   libraries/observers/est/include/est_Flux_states.h
//! \brief  Contains the states for the flux
//!         estimator (EST_Flux) module routines
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

//! \brief Enumeration for the estimator error codes
//!
typedef enum
{
  EST_FLUX_ERRORCODE_NOERROR=0,      //!< no error error code
  EST_FLUX_ERRORCODE_SHIFTOVERFLOW,  //!< flux shift overflow error code
  EST_FLUX_ERRORCODE_CLIP,           //!< flux clip error code
  EST_FLUX_NUMERRORCODES             //!< the number of estimator error codes
} EST_Flux_ErrorCode_e;


//! \brief Enumeration for the estimator states
//!
typedef enum
{
  EST_FLUX_STATE_ERROR = 0, //!< error state
  EST_FLUX_STATE_IDLE = 1,  //!< idle state
  EST_FLUX_STATE_CL1 = 2,   //!< closed loop control stage 1
  EST_FLUX_STATE_CL2 = 3,   //!< closed loop control stage 2
  EST_FLUX_STATE_FINE = 4,  //!< fine estimate of flux
  EST_FLUX_STATE_DONE = 5,  //!< done state
  EST_FLUX_NUMSTATES = 6    //!< the number of flux estimator states
} EST_Flux_State_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//! @} // ingroup
#endif // end of EST_FLUX_STATES_H definition

