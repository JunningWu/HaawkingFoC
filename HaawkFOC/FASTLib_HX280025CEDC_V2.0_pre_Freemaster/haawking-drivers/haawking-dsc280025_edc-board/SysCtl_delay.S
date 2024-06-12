//###########################################################################
//
// FILE:   SysCtl_delay.S
//
// TITLE:  H28x SysCtl_delay driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


.section  ramfuncs, "ax", @progbits

.global	 SysCtl_delay


SysCtl_delay:

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
	
.size  SysCtl_delay,   .-SysCtl_delay
