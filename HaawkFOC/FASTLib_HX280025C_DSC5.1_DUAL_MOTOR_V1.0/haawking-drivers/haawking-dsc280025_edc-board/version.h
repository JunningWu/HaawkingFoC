//###########################################################################
//
// FILE:   version.h
//
// TITLE:  API to return the version number of the driverlib.lib in use.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef VERSION_H
#define VERSION_H

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
//! \addtogroup version_api Version
//! @{
//
//*****************************************************************************
#include <stdint.h>

//! Version number to be returned by Version_getLibVersion()
//!
#define VERSION_NUMBER      5000000U

//*****************************************************************************
//
//! Returns the driverlib version number
//!
//! This function can be used to check the version number of the driverlib.lib
//! that is in use. The version number will take the format x.xx.xx.xx, so for
//! example, if the function returns 2100200, the driverlib version being used
//! is 2.10.02.00.
//!
//! \return Returns an integer value indicating the driverlib version.
//
//*****************************************************************************
extern uint32_t
Version_getLibVersion(void);

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

#endif // VERSION_H
