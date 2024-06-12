//###########################################################################
//
// FILE:    f28002x_cputimers.c
//
// TITLE:   f28002x CPU 32-bit Timers Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

//
// Included Files
//
#include "f28002x_device.h"      // Headerfile Include File
#include "f28002x_examples.h"    // Examples Include File

//
// Globals
//
struct CPUTIMER_VARS CpuTimer0;
struct CPUTIMER_VARS CpuTimer1;
struct CPUTIMER_VARS CpuTimer2;

//
// InitCpuTimers - This function initializes all three CPU timers
// to a known state.
//
void
InitCpuTimers(void)
{
    //
    // CPU Timer 0
    // Initialize address pointers to respective timer registers
    //
    CpuTimer0.RegsAddr = &CpuTimer0Regs;

    //
    // Initialize timer period to maximum
    //
    CpuTimer0Regs.PRD.all  = 0xFFFFFFFF;

    //
    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    CpuTimer0Regs.TPR.all  = 0;

    //
    // Make sure timer is stopped
    //
    CpuTimer0Regs.TCR.bit.TSS = 1;

    //
    // Reload all counter register with period value
    //
    CpuTimer0Regs.TCR.bit.TRB = 1;

    //
    // Reset interrupt counters
    //
    CpuTimer0.InterruptCount = 0;

    //
    // CPU Timer 1 and 2
    // Initialize address pointers to respective timer registers
    //
    CpuTimer1.RegsAddr = &CpuTimer1Regs;
    CpuTimer2.RegsAddr = &CpuTimer2Regs;

    //
    // Initialize timer period to maximum
    //
    CpuTimer1Regs.PRD.all  = 0xFFFFFFFF;
    CpuTimer2Regs.PRD.all  = 0xFFFFFFFF;

    //
    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    CpuTimer1Regs.TPR.all  = 0;
    CpuTimer2Regs.TPR.all  = 0;

    //
    // Make sure timers are stopped
    //
    CpuTimer1Regs.TCR.bit.TSS = 1;
    CpuTimer2Regs.TCR.bit.TSS = 1;

    //
    // Reload all counter register with period value
    //
    CpuTimer1Regs.TCR.bit.TRB = 1;
    CpuTimer2Regs.TCR.bit.TRB = 1;

    //
    // Reset interrupt counters
    //
    CpuTimer1.InterruptCount = 0;
    CpuTimer2.InterruptCount = 0;
}

//
// ConfigCpuTimer - This function initializes the selected timer to the period
// specified by the "Freq" and "Period" parameters. The "Freq" is entered
// as "MHz" and the "Period" in "uSeconds". The timer is held in the stopped
// state after configuration.
//
void
ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period)
{
    Uint32 temp;

    //
    // Initialize timer period
    //
    Timer->CPUFreqInMHz = Freq;
    Timer->PeriodInUSec = Period;
    temp = (long) (Freq * Period);
    Timer->RegsAddr->PRD.all = temp;

    //
    // Set pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    Timer->RegsAddr->TPR.all  = 0;

    //
    // Initialize timer control register
    //

    //
    // 1 = Stop timer, 0 = Start/Restart Timer
    //
    Timer->RegsAddr->TCR.bit.TSS = 1;

    //
    // 1 = reload timer
    //
    Timer->RegsAddr->TCR.bit.TRB = 1;
    Timer->RegsAddr->TCR.bit.SOFT = 0;

    //
    // Timer Free Run Disabled
    //
    Timer->RegsAddr->TCR.bit.FREE = 0;

    //
    // 0 = Disable 1 = Enable Timer Interrupt
    //
    Timer->RegsAddr->TCR.bit.TIE = 1;

    //
    // Reset interrupt counter
    //
    Timer->InterruptCount = 0;
}

//
// End of File
//

