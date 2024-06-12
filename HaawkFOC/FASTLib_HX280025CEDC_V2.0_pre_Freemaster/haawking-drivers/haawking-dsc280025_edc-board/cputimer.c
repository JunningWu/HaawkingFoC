//###########################################################################
//
// FILE:   cputimer.c
//
// TITLE:   H28x CPU timer Driver
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "cputimer.h"

//*****************************************************************************
//
// CPUTimer_setEmulationMode
//
//*****************************************************************************
void CPUTimer_setEmulationMode(uint32_t base, CPUTimer_EmulationMode mode)
{
    ASSERT(CPUTimer_isBaseValid(base));
    //
    // Write to FREE_SOFT bits of register TCR
    //
      HWREG(base + CPUTIMER_O_TCR) =
            (HWREG(base + CPUTIMER_O_TCR) &
            ~(CPUTIMER_TCR_FREE | CPUTIMER_TCR_SOFT)) |
            (uint32_t)mode;
}

