//###########################################################################
//
// FILE:   adc.c
//
// TITLE:  H28x ADC driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "adc.h"

//*****************************************************************************
//
// Defines for locations of ADC calibration functions in OTP for use in
// ADC_setVREF(). Not intended for use by application code.
//
//*****************************************************************************
#define ADC_OFFSET_TRIM_OTP    0x7A0864U

#define ADC_VOLTAGE_REF_REG_OFFSET              8U

//*****************************************************************************
//
// ADC_setVREF
//
//*****************************************************************************
void
ADC_setVREF(uint32_t base, ADC_ReferenceMode refMode,
            ADC_ReferenceVoltage refVoltage)
{
    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));

    EALLOW;
    //
    // Configure the reference mode (internal or external).
    //
    if((refMode == ADC_REFERENCE_INTERNAL)&&(refVoltage == ADC_REFERENCE_2_5V))
    {
    	HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAVREFHIEN \
    																		| ASYSCTL_ANAREFCTL_ANAREFAVDDSEL \
																			| ASYSCTL_ANAREFCTL_ANAREFCVDDSEL);
		HWREG(0x38F20) &= ~(0x8);
    }
    else if((refMode == ADC_REFERENCE_INTERNAL)&&(refVoltage == ADC_REFERENCE_3_3V))
    {
    	//
		// Not allowed to be choosen
		//
		ESTOP0;
    }
    else if(refMode == ADC_REFERENCE_EXTERNAL)
    {
    	HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) = (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) \
																		& ~(ASYSCTL_ANAREFCTL_ANAREFAVDDSEL \
																				| ASYSCTL_ANAREFCTL_ANAREFCVDDSEL)) \
																		| ASYSCTL_ANAREFCTL_ANAVREFHIEN;
    	HWREG(0x38F20) &= ~(0x8);
    }
    EDIS;
    //
    // Set ADC offset trim for the all the ADC instances
    //
    ADC_setOffsetTrimAll(refMode, refVoltage);
}

//*****************************************************************************
//
// ADC_setOffsetTrim
//
//*****************************************************************************
void
ADC_setOffsetTrim(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));
}

//*****************************************************************************
//
// ADC_setOffsetTrimAll
//
//*****************************************************************************
void
ADC_setOffsetTrimAll(ADC_ReferenceMode refMode, ADC_ReferenceVoltage refVoltage)
{
	refMode = refMode * 2;
	refVoltage = refVoltage * 2;

	refMode = refMode >> 1U;
	refVoltage = refVoltage >> 1U;
}


//*****************************************************************************
//
// ADC_setPPBTripLimits
//
//*****************************************************************************
void
ADC_setPPBTripLimits(uint32_t base, ADC_PPBNumber ppbNumber,
                     int32_t tripHiLimit, int32_t tripLoLimit)
{
    uint32_t ppbHiOffset;
    uint32_t ppbLoOffset;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));
    ASSERT((tripHiLimit <= 65535) && (tripHiLimit >= -65536));
    ASSERT((tripLoLimit <= 65535) && (tripLoLimit >= -65536));

    //
    // Get the offset to the appropriate trip limit registers.
    //
    ppbHiOffset = (ADC_PPBxTRIPHI_STEP * (uint32_t)ppbNumber) +
                  ADC_O_PPB1TRIPHI;
    ppbLoOffset = (ADC_PPBxTRIPLO_STEP * (uint32_t)ppbNumber) +
                  ADC_O_PPB1TRIPLO;

    EALLOW;

    //
    // Set the trip high limit.
    //
    HWREG(base + ppbHiOffset) =
        (HWREG(base + ppbHiOffset) & ~ADC_PPBTRIP_MASK) |
        ((uint32_t)tripHiLimit & ADC_PPBTRIP_MASK);

    //
    // Set the trip low limit.
    //
    HWREG(base + ppbLoOffset) =
        (HWREG(base + ppbLoOffset) & ~ADC_PPBTRIP_MASK) |
        ((uint32_t)tripLoLimit & ADC_PPBTRIP_MASK);

    EDIS;
}
