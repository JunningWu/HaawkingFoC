//###########################################################################
//
// FILE:   f28002x_epwm.c
//
// TITLE:  F28002x EPwm Initialization & Support Functions.
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


// InitEPwm1Gpio - Initialize EPWM1 GPIOs
//
void InitEPwm1Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;   // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;   // Disable pull-up on GPIO1 (EPWM1B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 1; // Disable pull-up on GPIO30 (EPWM1A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1; // Disable pull-up on GPIO31 (EPWM1B)

    //
    // Configure EPWM-1 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM1 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO30 = 2; // Configure GPIO30 as EPWM1A
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 2; // Configure GPIO31 as EPWM1B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3; // Configure GPIO30 as EPWM1A
//    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3; // Configure GPIO31 as EPWM1B

    EDIS;
}

//
// InitEPwm2Gpio - Initialize EPWM2 GPIOs
//
void InitEPwm2Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;   // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;   // Disable pull-up on GPIO3 (EPWM2B)
//    GpioCtrlRegs.GPBPUD.bit.GPIO41 = 1; // Disable pull-up on GPIO41 (EPWM2A)
//    GpioCtrlRegs.GPBPUD.bit.GPIO40 = 1; // Disable pull-up on GPIO40 (EPWM2B)

    //
    // Configure EPwm-2 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM2 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO41 = 1; // Configure GPIO41 as EPWM2A
//    GpioCtrlRegs.GPBGMUX1.bit.GPIO40 = 1; // Configure GPIO40 as EPWM2B
//    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 1; // Configure GPIO41 as EPWM2A
//    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 1; // Configure GPIO40 as EPWM2B

    EDIS;
}

//
// InitEPwm3Gpio - Initialize EPWM3 GPIOs
//
void InitEPwm3Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;   // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;   // Disable pull-up on GPIO5 (EPWM3B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1; // Disable pull-up on GPIO14 (EPWM3A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1; // Disable pull-up on GPIO15 (EPWM3B)

    //
    // Configure EPwm-3 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM3 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO14 = 3; // Configure GPIO14 as EPWM3A
//    GpioCtrlRegs.GPAGMUX1.bit.GPIO15 = 3; // Configure GPIO15 as EPWM3B
//    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1; // Configure GPIO14 as EPWM3A
//    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1; // Configure GPIO15 as EPWM3B

    EDIS;
}

//
// InitEPwm4Gpio - Initialize EPWM4 GPIOs
//
void InitEPwm4Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;   // Disable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;   // Disable pull-up on GPIO7 (EPWM4B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 1; // Disable pull-up on GPIO22 (EPWM4A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 1; // Disable pull-up on GPIO23 (EPWM4B)

     //
     // Configure EPWM-4 pins using GPIO regs. This specifies which of the
     // possible GPIO pins will be EPWM4 functional pins.
     // Comment out other unwanted lines.
     //
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO22 = 3; // Configure GPIO22 as EPWM4A
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO23 = 3; // Configure GPIO23 as EPWM4B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 2; // Configure GPIO22 as EPWM4A
//    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 2; // Configure GPIO23 as EPWM4B

    EDIS;
}

//
// InitEPwm5Gpio - Initialize EPWM5 GPIOs
//
void InitEPwm5Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;   // Disable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;   // Disable pull-up on GPIO9 (EPWM5B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 1; // Disable pull-up on GPIO16 (EPWM5A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1; // Disable pull-up on GPIO17 (EPWM5B)

    //
    // Configure EPWM-5 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM5 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO16 = 1; // Configure GPIO16 as EPWM5A
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 1; // Configure GPIO17 as EPWM5B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1; // Configure GPIO16 as EPWM5A
//    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1; // Configure GPIO17 as EPWM5B

    EDIS;
}

//
// InitEPwm6Gpio - Initialize EPWM6 GPIOs
//
void InitEPwm6Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;  // Disable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;  // Disable pull-up on GPIO11 (EPWM6B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 1; // Disable pull-up on GPIO18 (EPWM6A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 1; // Disable pull-up on GPIO19 (EPWM6B)

    //
    // Configure EPWM-6 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM6 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;  // Configure GPIO10 as EPWM6A
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;  // Configure GPIO11 as EPWM6B
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO18 = 1; // Configure GPIO155 as EPWM6A
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO19 = 1; // Configure GPIO156 as EPWM6B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1; // Configure GPIO155 as EPWM6A
//    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1; // Configure GPIO156 as EPWM6B

    EDIS;
}

//
// InitEPwm7Gpio - Initialize EPWM7 GPIOs
//
void InitEPwm7Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;  // Disable pull-up on GPIO12 (EPWM7A)
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;  // Disable pull-up on GPIO13 (EPWM7B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 1; // Disable pull-up on GPIO28 (EPWM7A)
//    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1; // Disable pull-up on GPIO29 (EPWM7B)

    //
    // Configure EPWM-7 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM7 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as EPWM7A
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // Configure GPIO13 as EPWM7B
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO28 = 0; // Configure GPIO28 as EPWM7A
//    GpioCtrlRegs.GPAGMUX2.bit.GPIO29 = 0; // Configure GPIO29 as EPWM7B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3; // Configure GPIO28 as EPWM7A
//    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3; // Configure GPIO29 as EPWM7B

    EDIS;
}

//
// InitEPwm8Gpio - Initialize EPWM8 GPIOs
//
void InitEPwm8Gpio(void)
{
    EALLOW;

    //
    // Disable internal pull-up for the selected output pins for reduced
    // power consumption. Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1;  // Disable pull-up on GPIO14 (EPWM8A)
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1;  // Disable pull-up on GPIO15 (EPWM8B)
    //
    // Configure EPWM-8 pins using GPIO regs. This specifies which of the
    // possible GPIO pins will be EPWM8 functional pins.
    // Comment out other unwanted lines.
    //
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;  // Configure GPIO14 as EPWM8A
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;  // Configure GPIO15 as EPWM8B

    EDIS;
}

//
// InitEPwmGpio - Initialize all EPWM modules' GPIOs
//
void InitEPwmGpio(void)
{
    InitEPwm1Gpio();
    InitEPwm2Gpio();
    InitEPwm3Gpio();
    InitEPwm4Gpio();
    InitEPwm5Gpio();
    InitEPwm6Gpio();
    InitEPwm7Gpio();
    InitEPwm8Gpio();
}

//
//
// End of File
//
