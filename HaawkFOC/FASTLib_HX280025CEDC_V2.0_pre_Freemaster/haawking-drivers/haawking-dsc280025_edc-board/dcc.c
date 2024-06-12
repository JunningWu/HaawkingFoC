//###########################################################################
//
// FILE:   dcc.c
//
// TITLE:  H28x DCC driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "dcc.h"


//*****************************************************************************
//
// DCC_verifyClockFrequency
//
//*****************************************************************************
bool
DCC_verifyClockFrequency(uint32_t base,
                         DCC_Count1ClockSource clock1,
                         float32_t freq1,
                         DCC_Count0ClockSource clock0,
                         float32_t freq0,
                         float32_t tolerance,
                         float32_t freqerr,
                         float32_t freq_sysclk)
{

    uint32_t count0;
    uint32_t valid;
    uint32_t count1;
    float valid_div;
    float count1_div;


    //
    // Check the arguments.
    //
    ASSERT(DCC_isBaseValid(base));

    count0 = 5000;

    count1_div = (float)(((count0+2)*(1000/freq0)*(100+tolerance)/100 + 2*(1000/freq_sysclk)*1.03 - 2*(1000/freq1)*(100 - freqerr)/100)/((1000/freq1)*(100 - freqerr)/100));
    count1_div = (float)(count1_div/10);
    count1 = (uint32_t)((count1_div+1)*10);



    valid_div =(float)(((count1 + 2)*(1000/freq1)*(100+freqerr)/100 +  2*(1000/freq_sysclk)*1.03 - (2 + 5000)*(1000/freq0)*(100-tolerance)/100)/((1000/freq0)*(100-tolerance)/100));
    valid_div = (float)valid_div/10;
    valid = (uint32_t)((valid_div+1)*10);




    //
    // Clear Error & Done Flag
    //
    DCC_clearErrorFlag(base);
    DCC_clearDoneFlag(base);

    //
    // Disable DCC and the error and done signals
    //
    DCC_disableModule(base);
    DCC_disableErrorSignal(base);
    DCC_disableDoneSignal(base);

    //
    // Configure Clock Source0 and clock source1
    //
    DCC_setCounter0ClkSource(base, clock0);
    DCC_setCounter1ClkSource(base, clock1);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(base, count0, valid, count1);

    //
    // Enable Single Shot mode
    //
    DCC_enableSingleShotMode(base, DCC_MODE_COUNTER_ZERO);

    //
    // Enable Error Signal and Done signal
    //
    DCC_enableErrorSignal(base);
    DCC_enableDoneSignal(base);

    //
    // Enable DCC to start counting
    //
    DCC_enableModule(base);

    //
    // Wait until Error or Done Flag is generated
    //
    while((DCC_getSingleShotStatus(base) || DCC_getErrorStatus(base)) == 0);

    //
    // Returns true if DCC completes without error
    //
    if (DCC_getSingleShotStatus(base) == 1U)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
// DCC_measureClockFrequency
//
//*****************************************************************************
float32_t
DCC_measureClockFrequency(uint32_t base,
                          DCC_Count1ClockSource clock1,
                          DCC_Count0ClockSource clock0,
                          float32_t freq0,
                          float32_t tolerance,
                          float32_t freqerr,
                          float32_t freq_sysclk)
{
    uint32_t count0;
    uint32_t valid;
    uint32_t count1;
    uint32_t actual_cnt1;
    float32_t freq1;
    tolerance += (float32_t)tolerance;
    freqerr += (float32_t)freqerr;


    //
    // Check the arguments.
    //
    ASSERT(DCC_isBaseValid(base));


    //
    // DCC counter configuration :
    //
    count0 = 5000;
    valid = 1000;

    count1 = 0xFFFFFU;

    //
    // Clear Error & Done Flag
    //
    DCC_clearErrorFlag(base);
    DCC_clearDoneFlag(base);

    //
    // Disable DCC and the error and done signals
    //
    DCC_disableModule(base);
    DCC_disableErrorSignal(base);
    DCC_disableDoneSignal(base);

    //
    // Configure Clock Source0 and clock source1
    //
    DCC_setCounter0ClkSource(base, clock0);
    DCC_setCounter1ClkSource(base, clock1);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(base, count0, valid, count1);

    //
    // Enable Single Shot mode
    //
    DCC_enableSingleShotMode(base, DCC_MODE_COUNTER_ZERO);

    //
    // Enable Error Signal and Done signal
    //
    DCC_enableErrorSignal(base);
    DCC_enableDoneSignal(base);

    //
    // Enable DCC to start counting
    //
    DCC_enableModule(base);

    //
    // Wait until Error or Done Flag is generated
    //
    while((DCC_getSingleShotStatus(base) || DCC_getErrorStatus(base)) == 0);

    //
    // Calculate the difference of the current counter
    // values with the initial fed counter values. This
    // will give the counts corresponding to the frequency
    // of each clock source
    //
    actual_cnt1 = count1 - DCC_getCounter1Value(base);

    //
    // Compute the frequency using relation F1 = (F0 * Actual C1)/Window.
    //
    freq1= actual_cnt1/((count0 + valid)/freq0+(2/freq_sysclk));

    return(freq1);
}

//*****************************************************************************
//
// DCC_continuousMonitor
//
//*****************************************************************************
void
DCC_continuousMonitor(uint32_t base,
                      DCC_Count1ClockSource clock1,
                      float32_t freq1,
                      DCC_Count0ClockSource clock0,
                      float32_t freq0,
                      float32_t tolerance,
                      float32_t freqerr,
                      float32_t freq_sysclk)
{
    uint32_t count0;
    uint32_t valid;
    uint32_t count1;
    float valid_div;
    float count1_div;

    //
    // Check the arguments.
    //
    ASSERT(DCC_isBaseValid(base));

    count0 = 5000;

    count1_div = (float)(((count0+2)*(1000/freq0)*(100+tolerance)/100 + 2*(1000/freq_sysclk)*1.03 - 2*(1000/freq1)*(100 - freqerr)/100)/((1000/freq1)*(100 - freqerr)/100));
    count1_div = (float)(count1_div/10);
    count1 = (uint32_t)((count1_div+1)*10);



    valid_div =(float)(((count1 + 2)*(1000/freq1)*(100+freqerr)/100 +  2*(1000/freq_sysclk)*1.03 - (2 + 5000)*(1000/freq0)*(100-tolerance)/100)/((1000/freq0)*(100-tolerance)/100));
    valid_div = (float)valid_div/10;
    valid = (uint32_t)((valid_div+1)*10);

    //
    // Clear Error & Done Flag
    //
    DCC_clearErrorFlag(base);
    DCC_clearDoneFlag(base);

    //
    // Disable DCC and the error and done signals
    //
    DCC_disableModule(base);
    DCC_disableErrorSignal(base);
    DCC_disableDoneSignal(base);

    //
    // Configure Clock Source0 and clock source1
    //
    DCC_setCounter0ClkSource(base, clock0);
    DCC_setCounter1ClkSource(base, clock1);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(base, count0, valid, count1);

    //
    // Enable Continuous mode
    //
    DCC_disableSingleShotMode(base);

    //
    // Enable Error Signal
    //
    DCC_enableErrorSignal(base);

    //
    // Enable DCC to start counting
    //
    DCC_enableModule(base);
}
