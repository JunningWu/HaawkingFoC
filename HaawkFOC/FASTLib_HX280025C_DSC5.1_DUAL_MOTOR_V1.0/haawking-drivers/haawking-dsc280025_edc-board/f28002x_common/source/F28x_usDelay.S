//###########################################################################
//
// FILE:   SysCtl_delay.S
//
// TITLE:  H28x SysCtl_delay driver.
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


.section  ramfuncs, "ax", @progbits

.global	 F28x_usDelay


F28x_usDelay:

.align 1
	addi  sp,sp,-20
	sw    a1,16(sp) 
	csrr  a1,0x7c0
	sw    a1,12(sp)
	csrr  a1,mstatus
	
.align 2
	rpt a0,4
	nop
   
	csrw  mstatus,a1
	lw    a1,12(sp)
	csrw  0x7c0,a1
	lw    a1,16(sp)
	addi  sp,sp,20

	ret
	
.size  F28x_usDelay,   .-F28x_usDelay
