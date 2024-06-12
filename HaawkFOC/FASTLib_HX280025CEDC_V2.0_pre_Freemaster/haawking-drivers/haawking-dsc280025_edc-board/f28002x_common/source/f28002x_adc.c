//###########################################################################
//
// FILE:    f28002x_adc.c
//
// TITLE:   F28002x ADC Support Functions.
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
#include "f28002x_device.h"      // Header File Include File
#include "f28002x_examples.h"    // Examples Include File

//
// SetVREF - Set Vref mode. Function to select reference mode and offset trim.
// Offset trim for Internal VREF 3.3 is unique.  All other modes use the same
// offset trim. Also note that when the mode parameter is ADC_EXTERNAL, the
// ref parameter has no effect.
//
// In this device, the bandgaps are common for all the ADC instances,
// hence common Vref configuration needs to be done for all the ADCs. This
// API configures same Vref configuration for all the supported ADCs in the
// device.
//
void SetVREF(int module, int mode, int ref)
{
    module += module;

    EALLOW;
	
    (*((volatile Uint32 *)0x38F20)) &= (~(1 << 3));
	
    if((mode == ADC_INTERNAL) && (ref == ADC_VREF2P5))
    {
    	AnalogSubsysRegs.ANAREFCTL.all = 0;
    }
    else if((mode == ADC_INTERNAL) && (ref == ADC_VREF3P3))
    {
    	AnalogSubsysRegs.ANAREFCTL.all =0x81;
    }
    else if(mode == ADC_EXTERNAL)
    {
    	AnalogSubsysRegs.ANAREFCTL.all = 0x1;
    }
    else
    {

    }

    EDIS;

}

//
// End of File
//
