//###########################################################################
//
// FILE:   eqep.c
//
// TITLE:  C28x eQEP driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "eqep.h"

//*****************************************************************************
//
// EQEP_setCompareConfig
//
//*****************************************************************************
void
EQEP_setCompareConfig(uint32_t base, uint32_t config, uint32_t compareValue,
                      uint32_t cycles)
{
    uint32_t regValue;

    //
    // Check the arguments.
    //
    ASSERT(EQEP_isBaseValid(base));
    ASSERT(cycles <= (EQEP_QPOSCTL_PCSPW_M + 1U));

    //
    // Set the compare match value
    //
    HWREG(base + EQEP_O_QPOSCMP) = compareValue;

    //
    // Set the shadow register settings and pulse width.
    //
    regValue = (config & (uint32_t)(EQEP_QPOSCTL_PCSHDW |
                  EQEP_QPOSCTL_PCLOAD)) | (cycles - 1U);

    HWREG(base + EQEP_O_QPOSCTL) = (HWREG(base + EQEP_O_QPOSCTL) &
                                     ~(EQEP_QPOSCTL_PCSPW_M |
                                       EQEP_QPOSCTL_PCLOAD |
                                       EQEP_QPOSCTL_PCSHDW)) | regValue;

    //
    // Set position compare sync-output mode.
    //
    regValue = config & (uint32_t)(EQEP_QDECCTL_SOEN | EQEP_QDECCTL_SPSEL);

    HWREG(base + EQEP_O_QDECCTL) = (HWREG(base + EQEP_O_QDECCTL) &
                                     ~(EQEP_QDECCTL_SOEN |
                                       EQEP_QDECCTL_SPSEL)) | regValue;
}

//*****************************************************************************
//
// EQEP_setInputPolarity
//
//*****************************************************************************
void
EQEP_setInputPolarity(uint32_t base, bool invertQEPA, bool invertQEPB,
                      bool invertIndex, bool invertStrobe)
{
    //
    // Check the arguments.
    //
    ASSERT(EQEP_isBaseValid(base));

    //
    // Configure QEPA signal
    //
    if(invertQEPA)
    {
        HWREG(base + EQEP_O_QDECCTL) |= EQEP_QDECCTL_QAP;
    }
    else
    {
        HWREG(base + EQEP_O_QDECCTL) &= ~EQEP_QDECCTL_QAP;
    }

    //
    // Configure QEPB signal
    //
    if(invertQEPB)
    {
        HWREG(base + EQEP_O_QDECCTL) |= EQEP_QDECCTL_QBP;
    }
    else
    {
        HWREG(base + EQEP_O_QDECCTL) &= ~EQEP_QDECCTL_QBP;
    }

    //
    // Configure index signal
    //
    if(invertIndex)
    {
        HWREG(base + EQEP_O_QDECCTL) |= EQEP_QDECCTL_QIP;
    }
    else
    {
        HWREG(base + EQEP_O_QDECCTL) &= ~EQEP_QDECCTL_QIP;
    }

    //
    // Configure strobe signal
    //
    if(invertStrobe)
    {
        HWREG(base + EQEP_O_QDECCTL) |= EQEP_QDECCTL_QSP;
    }
    else
    {
        HWREG(base + EQEP_O_QDECCTL) &= ~EQEP_QDECCTL_QSP;
    }
}
