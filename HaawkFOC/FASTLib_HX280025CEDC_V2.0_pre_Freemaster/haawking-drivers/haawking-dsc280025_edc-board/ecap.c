//###########################################################################
//
// FILE:   ecap.c
//
// TITLE: H28x ECAP driver
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "ecap.h"

//*****************************************************************************
//
// ECAP_setEmulationMode
//
//*****************************************************************************
void ECAP_setEmulationMode(uint32_t base, ECAP_EmulationMode mode)
{
    ASSERT(ECAP_isBaseValid(base));

    EALLOW;

    //
    // Write to FREE/SOFT bit
    //
    HWREG(base + ECAP_O_ECCTL1) =
            ((HWREG(base + ECAP_O_ECCTL1) & (~ECAP_ECCTL1_FREE_SOFT_M)) |
             ((uint32_t)mode << ECAP_ECCTL1_FREE_SOFT_S));
    EDIS;
}
