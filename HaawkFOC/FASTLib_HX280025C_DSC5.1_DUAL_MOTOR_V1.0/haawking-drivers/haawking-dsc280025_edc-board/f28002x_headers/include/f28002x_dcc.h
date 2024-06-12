//#############################################################################
//
// $Copyright:
// Copyright (C) 2019-2024 Beijing Haawking Technology Co.,Ltd
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


#ifndef F28002X_DCC_H
#define F28002X_DCC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DCC Individual Register Bit Definitions:

struct DCCCNT0_BITS {                         // bits description
    Uint32 COUNT0:20;                         // 19:0 Current Value of Counter 0
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union DCCCNT0_REG {
    Uint32  all;
    struct  DCCCNT0_BITS  bit;
};

struct DCCVALID0_BITS {                       // bits description
    Uint32 VALID0:16;                         // 15:0 Current Value of Valid 0
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DCCVALID0_REG {
    Uint32  all;
    struct  DCCVALID0_BITS  bit;
};

struct DCCCNT1_BITS {                         // bits description
    Uint32 COUNT1:20;                         // 19:0 Current Value of Counter 1
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union DCCCNT1_REG {
    Uint32  all;
    struct  DCCCNT1_BITS  bit;
};

struct DCCSTATUS_BITS {                       // bits description
    Uint32 ERR:1;                             // 0 Error Flag
    Uint32 DONE:1;                            // 1 Single-Shot Done Flag
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCCSTATUS_REG {
    Uint32  all;
    struct  DCCSTATUS_BITS  bit;
};

struct DCCGCTRL_BITS {                        // bits description
    Uint32 DCCENA:4;                          // 3:0 DCC Enable
    Uint32 ERRENA:4;                          // 7:4 Error Enable
    Uint32 SINGLESHOT:4;                      // 11:8 Single-Shot Enable
    Uint32 DONEENA:4;                         // 15:12 DONE Enable
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DCCGCTRL_REG {
    Uint32  all;
    struct  DCCGCTRL_BITS  bit;
};

struct DCCCLKSRC0_BITS {                      // bits description
    Uint32 CLKSRC0:4;                         // 3:0 Clock Source Select for Counter 0
    Uint32 rsvd1:8;                           // 11:4 Reserved
    Uint32 KEY:4;                             // 15:12 Enables or Disables Clock Source Selection for COUNT0
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCCCLKSRC0_REG {
    Uint32  all;
    struct  DCCCLKSRC0_BITS  bit;
};

struct DCCCLKSRC1_BITS {                      // bits description
    Uint32 CLKSRC1:5;                         // 4:0 Clock Source Select for Counter 1
    Uint32 rsvd1:7;                           // 11:5 Reserved
    Uint32 KEY:4;                             // 15:12 Enables or Disables Clock Source Selection for COUNT1
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCCCLKSRC1_REG {
    Uint32  all;
    struct  DCCCLKSRC1_BITS  bit;
};

struct DCCCNTSEED0_BITS {                     // bits description
    Uint32 COUNTSEED0:20;                     // 19:0 Seed Value for Counter 0
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union DCCCNTSEED0_REG {
    Uint32  all;
    struct  DCCCNTSEED0_BITS  bit;
};

struct DCCVALIDSEED0_BITS {                   // bits description
    Uint32 VALIDSEED:16;                      // 15:0 Seed Value for Valid Duration Counter 0
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DCCVALIDSEED0_REG {
    Uint32  all;
    struct  DCCVALIDSEED0_BITS  bit;
};

struct DCCCNTSEED1_BITS {                     // bits description
    Uint32 COUNTSEED1:20;                     // 19:0 Seed Value for Counter 1
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union DCCCNTSEED1_REG {
    Uint32  all;
    struct  DCCCNTSEED1_BITS  bit;
};

struct DCCSRCLR_BITS {                        // bits description
    Uint32 SRCLR:1;                           // 0 Reset the clock switching logic
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union DCCSRCLR_REG {
    Uint32  all;
    struct  DCCSRCLR_BITS  bit;
};

struct  DCC_REGS {
    Uint32                                   rsvd1[2];                    // 0x0 Reserved
    union   DCCCNT0_REG                      DCCCNT0;                     // 0x8 Value of the counter attached to Clock Source 0.
    union   DCCVALID0_REG                    DCCVALID0;                   // 0xc Value of the valid counter attached to Clock Source 0.
    Uint32                                   rsvd2;                       // 0x10 Reserved
    union   DCCCNT1_REG                      DCCCNT1;                     // 0x14 Value of the counter attached to Clock Source 1.
    Uint32                                   rsvd3[2];                    // 0x18 Reserved
    union   DCCSTATUS_REG                    DCCSTATUS;                   // 0x20 Specifies the status of the DCC Module.
    union   DCCGCTRL_REG                     DCCGCTRL;                    // 0x24 Starts / stops the counters. Clears the error signal.
    union   DCCCLKSRC0_REG                   DCCCLKSRC0;                  // 0x28 Selects the clock source for Counter 0.
    union   DCCCLKSRC1_REG                   DCCCLKSRC1;                  // 0x2c Selects the clock source for Counter 1.
    union   DCCCNTSEED0_REG                  DCCCNTSEED0;                 // 0x30 Seed value for the counter attached to Clock Source 0.
    union   DCCVALIDSEED0_REG                DCCVALIDSEED0;               // 0x34 Seed value for the timeout counter attached to Clock Source 0.
    union   DCCCNTSEED1_REG                  DCCCNTSEED1;                 // 0x38 Seed value for the counter attached to Clock Source 1.
    union   DCCSRCLR_REG                     DCCSRCLR;                    // 0x3c Reset the clock switching logic
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================