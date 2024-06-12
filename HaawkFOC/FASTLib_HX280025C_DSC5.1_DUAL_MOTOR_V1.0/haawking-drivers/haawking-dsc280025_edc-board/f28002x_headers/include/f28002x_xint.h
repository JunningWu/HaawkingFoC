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


#ifndef F28002X_XINT_H
#define F28002X_XINT_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// XINT Individual Register Bit Definitions:

struct XINT1CR_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 XINT1 Enable
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 POLARITY:2;                        // 3:2 XINT1 Polarity
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union XINT1CR_REG {
    Uint32  all;
    struct  XINT1CR_BITS  bit;
};

struct XINT2CR_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 XINT2 Enable
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 POLARITY:2;                        // 3:2 XINT2 Polarity
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union XINT2CR_REG {
    Uint32  all;
    struct  XINT2CR_BITS  bit;
};

struct XINT3CR_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 XINT3 Enable
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 POLARITY:2;                        // 3:2 XINT3 Polarity
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union XINT3CR_REG {
    Uint32  all;
    struct  XINT3CR_BITS  bit;
};

struct XINT4CR_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 XINT4 Enable
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 POLARITY:2;                        // 3:2 XINT4 Polarity
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union XINT4CR_REG {
    Uint32  all;
    struct  XINT4CR_BITS  bit;
};

struct XINT5CR_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 XINT5 Enable
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 POLARITY:2;                        // 3:2 XINT5 Polarity
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union XINT5CR_REG {
    Uint32  all;
    struct  XINT5CR_BITS  bit;
};

struct  XINT_REGS {
    union   XINT1CR_REG                      XINT1CR;                     // 0x0 XINT1 configuration register
    union   XINT2CR_REG                      XINT2CR;                     // 0x4 XINT2 configuration register
    union   XINT3CR_REG                      XINT3CR;                     // 0x8 XINT3 configuration register
    union   XINT4CR_REG                      XINT4CR;                     // 0xc XINT4 configuration register
    union   XINT5CR_REG                      XINT5CR;                     // 0x10 XINT5 configuration register
    Uint32                                   XINT1CTR;                    // 0x14 XINT1 counter register
    Uint32                                   XINT2CTR;                    // 0x18 XINT2 counter register
    Uint32                                   XINT3CTR;                    // 0x1c XINT3 counter register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================