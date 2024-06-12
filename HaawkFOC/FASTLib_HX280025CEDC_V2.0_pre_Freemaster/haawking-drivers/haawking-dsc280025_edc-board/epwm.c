//###########################################################################
//
// FILE:   epwm.c
//
// TITLE:  H28x EPWM driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "epwm.h"

//*****************************************************************************
//
// EPWM_setEmulationMode
//
//*****************************************************************************
void EPWM_setEmulationMode(uint32_t base, EPWM_EmulationMode emulationMode)
{
    //
    // Check the arguments.
    //
    ASSERT(EPWM_isBaseValid(base));

    //
    // Write to FREE_SOFT bits
    //
    HWREG(base + EPWM_O_TBCTL) =
           ((HWREG(base + EPWM_O_TBCTL) & (~EPWM_TBCTL_FREE_SOFT_M)) |
            ((uint32_t)emulationMode << EPWM_TBCTL_FREE_SOFT_S));
}

//*****************************************************************************
//
// EPWM_configureSignal
//
//*****************************************************************************
void EPWM_configureSignal(uint32_t base, const EPWM_SignalParams *signalParams)
{
    float32_t tbClkInHz = 0.0F;
    uint32_t tbPrdVal = 0U, cmpAVal = 0U, cmpBVal = 0U;

    //
    // Check the arguments.
    //
    ASSERT(EPWM_isBaseValid(base));

    //
    // Configure Time Base counter Clock
    //
    EPWM_setClockPrescaler(base, signalParams->tbClkDiv,
                           signalParams->tbHSClkDiv);

    //
    // Configure Time Base Counter Mode
    //
    EPWM_setTimeBaseCounterMode(base, signalParams->tbCtrMode);

    //
    // Calculate TBCLK, TBPRD and CMPx values to be configured for
    // achieving desired signal
    //
    tbClkInHz = ((float32_t)signalParams->sysClkInHz /
                (1U << (uint32_t)signalParams->tbClkDiv));

    if(signalParams->tbHSClkDiv <= EPWM_HSCLOCK_DIVIDER_4)
    {
        tbClkInHz /= (1U << (uint32_t)signalParams->tbHSClkDiv);
    }
    else
    {
        tbClkInHz /= (2U * (uint32_t)signalParams->tbHSClkDiv);
    }

    if(signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP)
    {
        tbPrdVal = (uint32_t)((tbClkInHz / signalParams->freqInHz) - 1.0f);
        cmpAVal = (uint32_t)((float32_t)signalParams->dutyValA *
                             (tbPrdVal + 1U));
        cmpBVal = (uint32_t)((float32_t)signalParams->dutyValB *
                             (tbPrdVal + 1U));
    }
    else if(signalParams->tbCtrMode == EPWM_COUNTER_MODE_DOWN)
    {
        tbPrdVal = (uint32_t)((tbClkInHz / signalParams->freqInHz) - 1.0f);
        cmpAVal = (uint32_t)((tbPrdVal + 1U) -
                       ((float32_t)signalParams->dutyValA * (tbPrdVal + 1U)));
        cmpBVal = (uint32_t)((tbPrdVal + 1U) -
                       ((float32_t)signalParams->dutyValB * (tbPrdVal + 1U)));
    }
    else if((signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP_DOWN))
    {
        tbPrdVal = (uint32_t)(tbClkInHz / (2.0f * signalParams->freqInHz));
        cmpAVal = (uint32_t)(((float32_t)tbPrdVal -
                             ((float32_t)(signalParams->dutyValA *
                              tbPrdVal))) + 0.5f);
        cmpBVal = (uint32_t)(((float32_t)tbPrdVal -
                             ((float32_t)(signalParams->dutyValB *
                              tbPrdVal))) + 0.5f);
    }

    //
    // Configure TBPRD value
    //
    EPWM_setTimeBasePeriod(base, tbPrdVal);

    //
    // Default Configurations.
    //
    EPWM_disablePhaseShiftLoad(base);
    EPWM_setPhaseShift(base, 0U);
    EPWM_setTimeBaseCounter(base, 0U);

    //
    // Setup shadow register load on ZERO
    //
    EPWM_setCounterCompareShadowLoadMode(base,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(base,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    //
    // Set Compare values
    //
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A,
                                cmpAVal);
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_B,
                                cmpBVal);

    //
    // Set actions for ePWMxA & ePWMxB
    //
    if(signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP)
    {
        //
        // Set PWMxA on Zero
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

        //
        // Clear PWMxA on event A, up count
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

        if(signalParams->invertSignalB == true)
        {
            //
            // Clear PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            //
            // Set PWMxB on event B, up count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
        }
        else
        {
            //
            // Set PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            //
            // Clear PWMxB on event B, up count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

        }
    }
    else if((signalParams->tbCtrMode == EPWM_COUNTER_MODE_DOWN))
    {
        //
        // Set PWMxA on Zero
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

        //
        // Clear PWMxA on event A, down count
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

        if(signalParams->invertSignalB == true)
        {
            //
            // Clear PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            //
            // Set PWMxB on event B, down count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
        else
        {
            //
            // Set PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            //
            // Clear PWMxB on event B, down count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
    }
    else if(signalParams->tbCtrMode == EPWM_COUNTER_MODE_UP_DOWN)
    {
        //
        // Clear PWMxA on Zero
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

        //
        // Set PWMxA on event A, up count
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

        //
        // Clear PWMxA on event A, down count
        //
        EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

        if(signalParams->invertSignalB == true)
        {
            //
            // Set PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

            //
            // Clear PWMxB on event B, up count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
            //
            // Set PWMxB on event B, down count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
        else
        {
            //
            // Clear PWMxB on Zero
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

            //
            // Set PWMxB on event B, up count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_HIGH,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
            //
            // Clear PWMxB on event B, down count
            //
            EPWM_setActionQualifierAction(base,
                                          EPWM_AQ_OUTPUT_B,
                                          EPWM_AQ_OUTPUT_LOW,
                                          EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        }
    }
}

