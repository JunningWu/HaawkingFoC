//#############################################################################
//

//#############################################################################

#ifndef EST_STATES_H
#define EST_STATES_H

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
//! \addtogroup EST
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Enumeration for the estimator error codes
//
//*****************************************************************************
typedef enum
{
    EST_ERRORCODE_NOERROR = 0,                //!< no error error code
    EST_ERRORCODE_FLUX_OL_SHIFTOVERFLOW = 1,  //!< flux open loop shift
                                              //!< overflow error code
    EST_ERRORCODE_FLUXERROR = 2,              //!< flux estimator error code
    EST_ERRORCODE_DIR_SHIFTOVERFLOW = 3,      //!< direction shift overflow
                                              //!< error code
    EST_ERRORCODE_IND_SHIFTOVERFLOW = 4,      //!< inductance shift overflow
                                              //!< error code
    EST_NUMERRORCODES = 5                     //!< the number of estimator
                                              //!< error codes
} EST_ErrorCode_e;

//*****************************************************************************
//
//! \brief Enumeration for the estimator states
//
//*****************************************************************************

typedef enum
{
    EST_STATE_ERROR = 0,            //!< error
    EST_STATE_IDLE = 1,             //!< idle
    EST_STATE_ROVERL = 2,           //!< R/L estimation
    EST_STATE_RS = 3,               //!< Rs estimation state
    EST_STATE_RAMPUP = 4,           //!< ramp up the speed
    EST_STATE_CONSTSPEED = 5,       //!< constant speed after ramp up
    EST_STATE_IDRATED = 6,          //!< control Id and estimate the rated flux
    EST_STATE_RATEDFLUX_OL = 7,     //!< estimate the open loop rated flux
    EST_STATE_RATEDFLUX = 8,        //!< estimate the rated flux
    EST_STATE_RAMPDOWN = 9,         //!< ramp down the speed
    EST_STATE_LOCKROTOR = 0xA,      //!< lock the rotor
    EST_STATE_LS = 0xB,             //!< stator inductance estimation state
    EST_STATE_RR = 0xC,             //!< rotor resistance estimation state
    EST_STATE_MOTORIDENTIFIED = 0xD,  //!< motor identified state
    EST_STATE_ONLINE = 0xE,         //!< online parameter estimation
    EST_NUMSTATES = 0xF,            //!< the number of estimator states
    EST_RESERVED = 0x1000          //!< reserved to force 32 bit data
} EST_State_e;

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

#endif // EST_STATES_H
