//###########################################################################
//
// FILE:    f28002x_gpio_defines.h
//
// TITLE:   f28002x GPIO support definitions
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef F28002x_GPIO_DEFINES_H
#define F28002x_GPIO_DEFINES_H

//
// Defines
//

//
// CPU pin masters for GPIO_SelectPinMux()
//
#define GPIO_MUX_CPU1       0x0
#define GPIO_MUX_CPU1CLA    0x1

//
// Flags for GPIO_SetupPinOptions(). The qualification flags (SYNC, QUAL3,
// QUAL6, and ASYNC) take up two bits and must be in the order specified.
//
#define GPIO_INPUT      0
#define GPIO_OUTPUT     1
#define GPIO_PUSHPULL   0
#define GPIO_PULLUP     (1 << 0)
#define GPIO_INVERT     (1 << 1)
#define GPIO_OPENDRAIN  (1 << 2)
#define GPIO_SYNC       (0x0 << 4)
#define GPIO_QUAL3      (0x1 << 4)
#define GPIO_QUAL6      (0x2 << 4)
#define GPIO_ASYNC      (0x3 << 4)

//
// Flags for GPIO_SetupLock().
//
#define GPIO_UNLOCK     0
#define GPIO_LOCK       1

//
// Helpful constants for array-based access to GPIO registers
//
#define GPY_CTRL_OFFSET (0x40/2)
#define GPY_DATA_OFFSET (0x8/2)

#define GPYQSEL     (0x2/2)
#define GPYMUX      (0x6/2)
#define GPYDIR      (0xA/2)
#define GPYPUD      (0xC/2)
#define GPYINV      (0x10/2)
#define GPYODR      (0x12/2)
#define GPYGMUX     (0x20/2)
#define GPYCSEL     (0x28/2)
#define GPYLOCK     (0x3C/2)
#define GPYCR       (0x3E/2)

#define GPYDAT      (0x0/2)
#define GPYSET      (0x2/2)
#define GPYCLEAR    (0x4/2)
#define GPYTOGGLE   (0x6/2)

#endif  // end of F28002x_GPIO_DEFINES_H definition

//
// End of file
//


