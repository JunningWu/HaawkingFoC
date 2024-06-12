//###########################################################################
//
// FILE:   cpu.h
//
// TITLE:  Useful H28x CPU defines.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#ifndef CPU_H
#define CPU_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "hx_rv32_type.h"
#include "hx_rv32_dev.h"

//
// External reference to the interrupt flag register (IFR) register
//
extern volatile uint32_t  CODE_SECTION(".ifr_register")  IFR;

//
// External reference to the interrupt enable register (IER) register
//
extern volatile uint32_t  CODE_SECTION(".ier_register")  IER;


//
// Define for emulation stop
//
#ifndef ESTOP0
#define  ESTOP0 asm(" ebreak"); //send debug call
#endif

//
// Define for emulation stop
//
#ifndef ESTOP1
#define  ESTOP1 asm(" ebreak"); //send debug call
#endif



//
// Define for putting processor into a low-power mode
//
#ifndef _DUAL_HEADERS
#ifndef IDLE
#define IDLE   __asm(" wfi")
#endif
#else
#define IDLE_ASM __asm(" wfi");
#endif

//*****************************************************************************
//
// Extern compiler intrinsic prototypes. See compiler User's Guide for details.
//
//*****************************************************************************
//extern void __eallow(void);
//extern void __edis(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // CPU_H
