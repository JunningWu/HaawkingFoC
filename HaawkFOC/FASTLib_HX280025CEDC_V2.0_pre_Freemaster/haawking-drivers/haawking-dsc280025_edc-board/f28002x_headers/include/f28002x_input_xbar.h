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


#ifndef F28002X_INPUT_XBAR_H
#define F28002X_INPUT_XBAR_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// INPUT_XBAR Individual Register Bit Definitions:

struct INPUTSELECTLOCK_BITS {                 // bits description
    Uint32 INPUT1SELECT:1;                    // 0 Lock bit for INPUT1SELECT Register
    Uint32 INPUT2SELECT:1;                    // 1 Lock bit for INPUT2SELECT Register
    Uint32 INPUT3SELECT:1;                    // 2 Lock bit for INPUT3SELECT Register
    Uint32 INPUT4SELECT:1;                    // 3 Lock bit for INPUT4SELECT Register
    Uint32 INPUT5SELECT:1;                    // 4 Lock bit for INPUT5SELECT Register
    Uint32 INPUT6SELECT:1;                    // 5 Lock bit for INPUT6SELECT Register
    Uint32 INPUT7SELECT:1;                    // 6 Lock bit for INPUT7SELECT Register
    Uint32 INPUT8SELECT:1;                    // 7 Lock bit for INPUT8SELECT Register
    Uint32 INPUT9SELECT:1;                    // 8 Lock bit for INPUT9SELECT Register
    Uint32 INPUT10SELECT:1;                   // 9 Lock bit for INPUT10SELECT Register
    Uint32 INPUT11SELECT:1;                   // 10 Lock bit for INPUT11SELECT Register
    Uint32 INPUT12SELECT:1;                   // 11 Lock bit for INPUT12SELECT Register
    Uint32 INPUT13SELECT:1;                   // 12 Lock bit for INPUT13SELECT Register
    Uint32 INPUT14SELECT:1;                   // 13 Lock bit for INPUT14SELECT Register
    Uint32 INPUT15SELECT:1;                   // 14 Lock bit for INPUT15SELECT Register
    Uint32 INPUT16SELECT:1;                   // 15 Lock bit for INPUT16SELECT Register
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union INPUTSELECTLOCK_REG {
    Uint32  all;
    struct  INPUTSELECTLOCK_BITS  bit;
};

struct  INPUT_XBAR_REGS {
    Uint32                                   INPUT1SELECT;                // 0x0 INPUT1 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT2SELECT;                // 0x4 INPUT2 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT3SELECT;                // 0x8 INPUT3 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT4SELECT;                // 0xc INPUT4 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT5SELECT;                // 0x10 INPUT5 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT6SELECT;                // 0x14 INPUT6 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT7SELECT;                // 0x18 INPUT7 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT8SELECT;                // 0x1c INPUT8 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT9SELECT;                // 0x20 INPUT9 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT10SELECT;               // 0x24 INPUT10 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT11SELECT;               // 0x28 INPUT11 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT12SELECT;               // 0x2c INPUT12 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT13SELECT;               // 0x30 INPUT13 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT14SELECT;               // 0x34 INPUT14 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT15SELECT;               // 0x38 INPUT15 Input Select Register (GPIO0 to x)
    Uint32                                   INPUT16SELECT;               // 0x3c INPUT16 Input Select Register (GPIO0 to x)
    Uint32                                   rsvd1[14];                   // 0x40 Reserved
    union   INPUTSELECTLOCK_REG              INPUTSELECTLOCK;             // 0x78 Input Select Lock Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================