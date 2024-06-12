//#############################################################################
//
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd
// http://www.haawking.com/ All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Beijing Haawking Technology Co.,Ltd nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
//#############################################################################
//
// Release for HXS320F280025CEDC, Bitfield DriverLib, 1.0.0
//
// Release time: 2024-01-23 15:23:22.144640
//
//#############################################################################


#ifndef F28002X_DEVICE_H
#define F28002X_DEVICE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// Common CPU Definitions:
//

#define P_REG			(1)

#define  EINT	asm("csrsi mstatus, 0x8") //enable_interrupt(1)
#define  DINT   asm("csrci mstatus, 0x8") //disable_interrupt(1)


//#define  ERTM   asm(" clrc DBGM")//enable  debug   not support real-time debug
//#define  DRTM   asm(" csrs DBGM")//disable debug   not support real-time debug

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






#define  ERTM 

#define  DRTM 

extern uint32_t read_reg32(uintptr_t addr);
extern uint32_t read_reg16(uintptr_t addr);
extern uint8_t read_reg8(uintptr_t addr);

extern void write_reg32(uintptr_t addr,uint32_t val);
extern void write_reg16(uintptr_t addr,uint16_t val);
extern void write_reg8(uintptr_t addr,uint8_t val);



#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000

#define BIT0    0x0001
#define BIT1    0x0002
#define BIT2    0x0004
#define BIT3    0x0008
#define BIT4    0x0010
#define BIT5    0x0020
#define BIT6    0x0040
#define BIT7    0x0080
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000



//
// Include All Peripheral Header Files:
//
#include "hx_rv32_dev.h"
#include "hx_rv32_type.h"
#include "f28002x_adc.h"
#include "f28002x_analogsubsys.h"
#include "f28002x_bgcrc.h"
#include "f28002x_can.h"
#include "f28002x_clb.h"
#include "f28002x_clbxbar.h"
#include "f28002x_cmpss.h"
#include "f28002x_cputimer.h"
#include "f28002x_dcc.h"
#include "f28002x_dcsm.h"
#include "f28002x_dma.h"
#include "f28002x_ecap.h"
#include "f28002x_epwm.h"
#include "f28002x_epwm_xbar.h"
#include "f28002x_eqep.h"
#include "f28002x_erad.h"
#include "f28002x_flash.h"
#include "f28002x_fsi.h"
#include "f28002x_gpio.h"
#include "f28002x_hic.h"
#include "f28002x_i2c.h"
#include "f28002x_i2s.h"
#include "f28002x_input_xbar.h"
#include "f28002x_lin.h"
#include "f28002x_memconfig.h"
#include "f28002x_nmiintrupt.h"
#include "f28002x_output_xbar.h"
#include "f28002x_piectrl.h"
#include "f28002x_pievect.h"
#include "f28002x_pmbus.h"
#include "f28002x_sci.h"
#include "f28002x_spi.h"
#include "f28002x_sysctrl.h"
#include "f28002x_xbar.h"
#include "f28002x_xint.h"
#include "f28002x_globalvariabledefs.h"

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
