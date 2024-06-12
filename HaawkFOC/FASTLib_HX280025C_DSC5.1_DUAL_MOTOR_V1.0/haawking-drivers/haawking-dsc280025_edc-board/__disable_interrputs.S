//###########################################################################
//
// FILE:    __disable_interrputs.S
//
// TITLE:   DSP28002x  __disable_interrputs Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

.section .text,  "ax", @progbits


.global __disable_interrupts


__disable_interrupts:

csrrci a0,mstatus,0x8
ret

.size  __disable_interrupts,   .-__disable_interrupts
