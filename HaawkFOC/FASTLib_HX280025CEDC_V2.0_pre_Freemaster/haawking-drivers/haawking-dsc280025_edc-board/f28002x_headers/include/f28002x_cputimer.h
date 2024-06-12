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


#ifndef F28002X_CPUTIMER_H
#define F28002X_CPUTIMER_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CPUTIMER Individual Register Bit Definitions:

struct TIM_BITS {                             // bits description
    Uint32 LSW:16;                            // 15:0 CPU-Timer Counter Registers
    Uint32 MSW:16;                            // 31:16 CPU-Timer Counter Registers High
};

union TIM_REG {
    Uint32  all;
    struct  TIM_BITS  bit;
};

struct PRD_BITS {                             // bits description
    Uint32 LSW:16;                            // 15:0 CPU-Timer Period Registers
    Uint32 MSW:16;                            // 31:16 CPU-Timer Period Registers High
};

union PRD_REG {
    Uint32  all;
    struct  PRD_BITS  bit;
};

struct TCR_BITS {                             // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 TSS:1;                             // 4 CPU-Timer stop status bit.
    Uint32 TRB:1;                             // 5 Timer reload
    Uint32 rsvd2:4;                           // 9:6 Reserved
    Uint32 SOFT:1;                            // 10 Emulation modes
    Uint32 FREE:1;                            // 11 Emulation modes
    Uint32 rsvd3:2;                           // 13:12 Reserved
    Uint32 TIE:1;                             // 14 CPU-Timer Interrupt Enable.
    Uint32 TIF:1;                             // 15 CPU-Timer Interrupt Flag.
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union TCR_REG {
    Uint32  all;
    struct  TCR_BITS  bit;
};

struct TPR_BITS {                             // bits description
    Uint32 TDDR:16;                           // 15:0 CPU-Timer Divide-Down.
    Uint32 PSC:16;                            // 31:16 CPU-Timer Prescale Counter.
};

union TPR_REG {
    Uint32  all;
    struct  TPR_BITS  bit;
};

struct  CPUTIMER_REGS {
    union   TIM_REG                          TIM;                         // 0x0 CPU-Timer, Counter Register
    union   PRD_REG                          PRD;                         // 0x4 CPU-Timer, Period Register
    union   TCR_REG                          TCR;                         // 0x8 CPU-Timer, Control Register
    union   TPR_REG                          TPR;                         // 0xc CPU-Timer, Prescale Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================