//###########################################################################
//
// FILE:   cmpss.c
//
// TITLE:  H28x CMPSS driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "cmpss.h"

//*****************************************************************************
//
// CMPSS_configFilterHigh
//
//*****************************************************************************
void
CMPSS_configFilterHigh(uint32_t base, uint32_t samplePrescale,
                       uint32_t sampleWindow, uint32_t threshold)
{
    uint32_t regValue;

    //
    // Check the arguments.
    //
    ASSERT(CMPSS_isBaseValid(base));
    ASSERT(samplePrescale <= 1023U);
    ASSERT((sampleWindow >= 1U) && (sampleWindow <= 32U));
    ASSERT((threshold - 1U) >= ((sampleWindow - 1U) / 2U));

    //
    // Shift the sample window and threshold values into the correct positions
    // and write them to the appropriate register.
    //
    regValue = ((sampleWindow - 1U) << CMPSS_CTRIPHFILCTL_SAMPWIN_S) |
               ((threshold - 1U) << CMPSS_CTRIPHFILCTL_THRESH_S);

    EALLOW;

    HWREG(base + CMPSS_O_CTRIPHFILCTL) =
        (HWREG(base + CMPSS_O_CTRIPHFILCTL) &
         ~(CMPSS_CTRIPHFILCTL_SAMPWIN_M | CMPSS_CTRIPHFILCTL_THRESH_M)) |
        regValue;

    //
    // Set the filter sample clock prescale for the high comparator.
    //
    HWREG(base + CMPSS_O_CTRIPHFILCLKCTL) = samplePrescale;

    EDIS;
}

//*****************************************************************************
//
// CMPSS_configFilterLow
//
//*****************************************************************************
void
CMPSS_configFilterLow(uint32_t base, uint32_t samplePrescale,
                      uint32_t sampleWindow, uint32_t threshold)
{
    uint32_t regValue;

    //
    // Check the arguments.
    //
    ASSERT(CMPSS_isBaseValid(base));
    ASSERT(samplePrescale <= 1023U);
    ASSERT((sampleWindow >= 1U) && (sampleWindow <= 32U));
    ASSERT((threshold - 1U) >= ((sampleWindow - 1U) / 2U));

    //
    // Shift the sample window and threshold values into the correct positions
    // and write them to the appropriate register.
    //
    regValue = ((sampleWindow - 1U) << CMPSS_CTRIPLFILCTL_SAMPWIN_S) |
               ((threshold - 1U) << CMPSS_CTRIPLFILCTL_THRESH_S);

    EALLOW;

    HWREG(base + CMPSS_O_CTRIPLFILCTL) =
        (HWREG(base + CMPSS_O_CTRIPLFILCTL) &
         ~(CMPSS_CTRIPLFILCTL_SAMPWIN_M | CMPSS_CTRIPLFILCTL_THRESH_M)) |
        regValue;

    //
    // Set the filter sample clock prescale for the low comparator.
    //
    HWREG(base + CMPSS_O_CTRIPLFILCLKCTL) = samplePrescale;

    EDIS;
}

//*****************************************************************************
//
// CMPSS_configLatchOnPWMSYNC
//
//*****************************************************************************
void
CMPSS_configLatchOnPWMSYNC(uint32_t base, bool highEnable, bool lowEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(CMPSS_isBaseValid(base));

    //
    // If the highEnable is true, set the bit that will enable PWMSYNC to reset
    // the high comparator digital filter latch. If not, clear the bit.
    //
    EALLOW;

    if(highEnable)
    {
        HWREG(base + CMPSS_O_COMPSTSCLR) |= CMPSS_COMPSTSCLR_HSYNCCLREN;
    }
    else
    {
        HWREG(base + CMPSS_O_COMPSTSCLR) &= ~CMPSS_COMPSTSCLR_HSYNCCLREN;
    }

    //
    // If the lowEnable is true, set the bit that will enable PWMSYNC to reset
    // the low comparator digital filter latch. If not, clear the bit.
    //
    if(lowEnable)
    {
        HWREG(base + CMPSS_O_COMPSTSCLR) |= CMPSS_COMPSTSCLR_LSYNCCLREN;
    }
    else
    {
        HWREG(base + CMPSS_O_COMPSTSCLR) &= ~CMPSS_COMPSTSCLR_LSYNCCLREN;
    }

    EDIS;
}

//*****************************************************************************
//
// CMPSS_configRamp
//
//*****************************************************************************
void
CMPSS_configRamp(uint32_t base, uint32_t maxRampVal, uint32_t decrementVal,
                 uint32_t delayVal, uint32_t pwmSyncSrc, bool useRampValShdw)
{
    //
    // Check the arguments.
    //
    ASSERT(CMPSS_isBaseValid(base));
    ASSERT(delayVal <= CMPSS_RAMPDLYS_DELAY_M);
    ASSERT((pwmSyncSrc >= 1U) && (pwmSyncSrc <= 16U));

    EALLOW;

    //
    // Write the ramp generator source to the register
    //
    HWREG(base + CMPSS_O_COMPDACCTL) =
        (HWREG(base + CMPSS_O_COMPDACCTL) &
         ~CMPSS_COMPDACCTL_RAMPSOURCE_M) |
        ((uint32_t)(pwmSyncSrc - 1U) << CMPSS_COMPDACCTL_RAMPSOURCE_S);

    //
    // Set or clear the bit that determines from where the max ramp value
    // should be loaded.
    //
    if(useRampValShdw)
    {
        HWREG(base + CMPSS_O_COMPDACCTL) |= CMPSS_COMPDACCTL_RAMPLOADSEL;
    }
    else
    {
        HWREG(base + CMPSS_O_COMPDACCTL) &= ~CMPSS_COMPDACCTL_RAMPLOADSEL;
    }

    EDIS;

    //
    // Write the maximum ramp value to the shadow register.
    //
    HWREG(base + CMPSS_O_RAMPMAXREFS) = maxRampVal;

    //
    // Write the ramp decrement value to the shadow register.
    //
    HWREG(base + CMPSS_O_RAMPDECVALS) = decrementVal;

    //
    // Write the ramp delay value to the shadow register.
    //
    HWREG(base + CMPSS_O_RAMPDLYS) = delayVal;
}
