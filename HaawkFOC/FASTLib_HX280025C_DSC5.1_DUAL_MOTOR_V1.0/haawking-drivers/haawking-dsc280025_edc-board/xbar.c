//###########################################################################
//
// FILE:   xbar.c
//
// TITLE:  H28x X-BAR driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "xbar.h"

//*****************************************************************************
//
// XBAR_setOutputMuxConfig
//
//*****************************************************************************
void
XBAR_setOutputMuxConfig(uint32_t base, XBAR_OutputNum output,
                        XBAR_OutputMuxConfig muxConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(XBAR_isBaseValid(base));

    uint32_t shift;
    uint32_t offset;

    //
    // If the configuration is for MUX16-31, we'll need an odd value to index
    // into the config registers.
    //
    if(((uint32_t)muxConfig & 0x2000U) != 0U)
    {
        offset = ((uint32_t)output << 1U) + 4U;
    }
    else
    {
        offset = (uint32_t)output << 1U;
    }

    //
    // Extract the shift from the input value.
    //
    shift = ((uint32_t)muxConfig >> 8U) & 0x1FU;

    //
    // Write the requested muxing value for this XBAR output.
    //
    EALLOW;

    HWREG(base + XBAR_O_OUTPUT1MUX0TO15CFG + offset) =
                           (HWREG(base + XBAR_O_OUTPUT1MUX0TO15CFG + offset) &
                          ~((uint32_t)0x3U << shift)) |
                           (((uint32_t)muxConfig & 0x3U) << shift);

    EDIS;
}

//*****************************************************************************
//
// XBAR_setEPWMMuxConfig
//
//*****************************************************************************
void
XBAR_setEPWMMuxConfig(XBAR_TripNum trip, XBAR_EPWMMuxConfig muxConfig)
{
    uint32_t shift;
    uint32_t offset;

    //
    // If the configuration is for MUX16-31, we'll need an odd value to index
    // into the config registers.
    //
    if(((uint32_t)muxConfig & 0x2000U) != 0U)
    {
        offset = ((uint32_t)trip << 1U) + 4U;
    }
    else
    {
        offset = (uint32_t)trip << 1U;
    }

    //
    // Extract the shift from the input value.
    //
    shift = ((uint32_t)muxConfig >> 8U) & 0x1FU;

    //
    // Write the requested muxing value for this XBAR trip.
    //
    EALLOW;

    HWREG(XBAR_EPWM_CFG_REG_BASE + offset) =
        (HWREG(XBAR_EPWM_CFG_REG_BASE + offset) & ~((uint32_t)0x3U << shift)) |
        (((uint32_t)muxConfig & 0x3U) << shift);

    EDIS;
}

//*****************************************************************************
//
// XBAR_setCLBMuxConfig
//
//*****************************************************************************
void
XBAR_setCLBMuxConfig(XBAR_AuxSigNum auxSignal, XBAR_CLBMuxConfig muxConfig)
{
    uint32_t shift;
    uint32_t offset;

    //
    // If the configuration is for MUX16-31, we'll need an odd value to index
    // into the config registers.
    //
    if(((uint32_t)muxConfig & 0x2000U) != 0U)
    {
        offset = ((uint32_t)auxSignal << 1U) + 4U;
    }
    else
    {
        offset = (uint32_t)auxSignal << 1U;
    }

    //
    // Extract the shift from the input value.
    //
    shift = ((uint32_t)muxConfig >> 8U) & 0x1FU;

    //
    // Write the requested muxing value for this XBAR auxSignal.
    //
    EALLOW;


    HWREG(XBAR_CLB_CFG_REG_BASE + offset) =
        (HWREG(XBAR_CLB_CFG_REG_BASE + offset) & ~((uint32_t)0x3U << shift)) |
        (((uint32_t)muxConfig & 0x3U) << shift);

    EDIS;
}

//*****************************************************************************
//
// XBAR_getInputFlagStatus
//
//*****************************************************************************
bool
XBAR_getInputFlagStatus(XBAR_InputFlag inputFlag)
{
    uint32_t offset;
    uint32_t inputMask;

    //
    // Determine flag register offset.
    //
    switch((uint32_t)inputFlag & XBAR_INPUT_FLG_REG_M)
    {
        case XBAR_INPUT_FLG_REG_1:
            offset = XBAR_O_FLG1;
            break;

        case XBAR_INPUT_FLG_REG_2:
            offset = XBAR_O_FLG2;
            break;

        case XBAR_INPUT_FLG_REG_3:
            offset = XBAR_O_FLG3;
            break;

        case XBAR_INPUT_FLG_REG_4:
            offset = XBAR_O_FLG4;
            break;

        default:
            //
            // This should never happen if a valid inputFlag value is used.
            //
            offset = 0U;
            break;
    }

    //
    // Get the status of the X-BAR input latch.
    //
    inputMask = (uint32_t)1U << ((uint32_t)inputFlag & XBAR_INPUT_FLG_INPUT_M);

    return((HWREG(XBAR_BASE + offset) & inputMask) != 0U);
}

//*****************************************************************************
//
// XBAR_clearInputFlag
//
//*****************************************************************************
void
XBAR_clearInputFlag(XBAR_InputFlag inputFlag)
{
    uint32_t offset;
    uint32_t inputMask;

    //
    // Determine flag clear register offset.
    //
    switch((uint32_t)inputFlag & XBAR_INPUT_FLG_REG_M)
    {
        case XBAR_INPUT_FLG_REG_1:
            offset = XBAR_O_CLR1;
            break;

        case XBAR_INPUT_FLG_REG_2:
            offset = XBAR_O_CLR2;
            break;

        case XBAR_INPUT_FLG_REG_3:
            offset = XBAR_O_CLR3;
            break;

        case XBAR_INPUT_FLG_REG_4:
            offset = XBAR_O_CLR4;
            break;

        default:
            //
            // This should never happen if a valid inputFlag value is used.
            //
            offset = 0U;
            break;
    }

    //
    // Set the bit that clears the X-BAR input latch.
    //
    inputMask = (uint32_t)1U << ((uint32_t)inputFlag & XBAR_INPUT_FLG_INPUT_M);
    HWREG(XBAR_BASE + offset) = inputMask;
}
