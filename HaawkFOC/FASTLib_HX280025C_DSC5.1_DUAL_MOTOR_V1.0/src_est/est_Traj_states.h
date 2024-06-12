//#############################################################################

//#############################################################################

#ifndef EST_TRAJ_STATES_H
#define EST_TRAJ_STATES_H

//! \file   libraries/observers/est/include/est_Traj_states.h
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

//! \brief Enumeration for the trajectory generator error codes
//!
typedef enum
{
  EST_TRAJ_ERRORCODE_NOERROR=0,        //!< no error error code
  EST_TRAJ_ERRORCODE_IDCLIP,           //!< Id clip error code
  EST_TRAJ_NUMERRORCODES               //!< the number of trajectory generator error codes
} EST_Traj_ErrorCode_e;


//! \brief Enumeration for the trajectory generator states
//!
#ifdef CLA
typedef enum
{
  EST_TRAJ_STATE_ERROR=0,       //!< the trajectory generator error state
  EST_TRAJ_STATE_IDLE = 1,      //!< the trajectory generator idle state
  EST_TRAJ_STATE_EST = 2,       //!< the trajectory generator parameter estimation state
  EST_TRAJ_STATE_ONLINE = 3,    //!< the trajectory generator online state
  EST_TRAJ_NUMSTATES = 4,       //!< the number of trajectory generator states
  EST_TRAJ_RESERVED = 0x10000   //!< reserved to force 32 bit data
} EST_Traj_State_e;
#else
typedef enum
{
  EST_TRAJ_STATE_ERROR=0,       //!< the trajectory generator error state
  EST_TRAJ_STATE_IDLE = 1,      //!< the trajectory generator idle state
  EST_TRAJ_STATE_EST = 2,       //!< the trajectory generator parameter estimation state
  EST_TRAJ_STATE_ONLINE = 3,    //!< the trajectory generator online state
  EST_TRAJ_NUMSTATES = 4,       //!< the number of trajectory generator states
  EST_TRAJ_RESERVED = 0x10000   //!< reserved to force 32 bit data
} EST_Traj_State_e;
#endif

// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//! @} // ingroup
#endif // end of EST_TRAJ_STATES_H definition

