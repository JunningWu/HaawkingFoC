//###########################################################################
//
// FILE:   f28002x_tempsensorconv.c
//
// TITLE:  F28002x Temperature Sensor Conversion Functions
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
#include "f28002x_device.h"
#include "f28002x_examples.h"
#include "inc/hw_types.h"



//
// Globals
//
int16_t tempSensor_tempSlope;
int16_t tempSensor_tempOffset;
float32_t tempSensor_scaleFactor;

//
// InitTempSensor - Initialize the temperature sensor by powering up the
//                  sensor, loading the calibration values from OTP to RAM,
//                  and recording the intended VREFHI voltage.
//                  Note: This function doesn't support VREFLO != 0.0V,
//                  but this could be implemented if desired.
//
void InitTempSensor(float vrefhi_voltage)
{
    EALLOW;

    //
    //power up the the temperature sensor
    //
    AnalogSubsysRegs.TSNSCTL.bit.ENABLE = 1;

    //
    //delay to allow the sensor to power up
    //
    DELAY_US(1000);


    //
    //need to remember VREFHI voltage so that sensor readings can be scaled
    //to match 2.5V values used for calibration data.
    //
    tempSensor_scaleFactor = vrefhi_voltage;

    EDIS;
}



//
// End of file
//
