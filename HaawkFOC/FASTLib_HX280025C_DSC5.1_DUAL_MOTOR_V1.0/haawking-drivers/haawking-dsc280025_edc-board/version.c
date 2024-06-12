//###########################################################################
//
// FILE:   version.c
//
// TITLE:  API to return the version number of the driverlib.lib in use.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "version.h"

//*****************************************************************************
//
// Version_getLibVersion
//
//*****************************************************************************
uint32_t
Version_getLibVersion(void)
{
    return(VERSION_NUMBER);
}
