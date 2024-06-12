//###########################################################################
//
// FILE:    __enable_interrupts.S
//
// TITLE:   DSP28002x  __enable_interrupts Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

.section .text, "ax", @progbits

.global __enable_interrupts

__enable_interrupts:

csrrsi a0,mstatus,8

ret

.size  __enable_interrupts,   .-__enable_interrupts
