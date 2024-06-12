//###########################################################################
//
// FILE:   f28002x_adc_defines.h
//
// TITLE:  #defines used in ADC examples
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef F28002X_ADC_DEFINES_H
#define F28002X_ADC_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//

//
// Definitions for specifying an ADC
//
#define ADC_ADCA        0
#define ADC_ADCC        2


//
// Definitions for specifying reference mode
//
#define ADC_INTERNAL    0
#define ADC_EXTERNAL    1

//
// Definitions for specifying reference voltage
//
#define ADC_VREF3P3     0
#define ADC_VREF2P5     1


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif

//
// End of file
//
