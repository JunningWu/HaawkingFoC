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


#ifndef F28002X_XBAR_H
#define F28002X_XBAR_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// XBAR Individual Register Bit Definitions:

struct XBARFLG1_BITS {                        // bits description
    Uint32 CMPSS1_CTRIPL:1;                   // 0 Input Flag for CMPSS1.CTRIPL Signal
    Uint32 CMPSS1_CTRIPH:1;                   // 1 Input Flag for CMPSS1.CTRIPH Signal
    Uint32 CMPSS2_CTRIPL:1;                   // 2 Input Flag for CMPSS2.CTRIPL Signal
    Uint32 CMPSS2_CTRIPH:1;                   // 3 Input Flag for CMPSS2.CTRIPH Signal
    Uint32 CMPSS3_CTRIPL:1;                   // 4 Input Flag for CMPSS3.CTRIPL Signal
    Uint32 CMPSS3_CTRIPH:1;                   // 5 Input Flag for CMPSS3.CTRIPH Signal
    Uint32 CMPSS4_CTRIPL:1;                   // 6 Input Flag for CMPSS4.CTRIPL Signal
    Uint32 CMPSS4_CTRIPH:1;                   // 7 Input Flag for CMPSS4.CTRIPH Signal
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:1;                           // 9 Reserved
    Uint32 rsvd3:1;                           // 10 Reserved
    Uint32 rsvd4:1;                           // 11 Reserved
    Uint32 rsvd5:1;                           // 12 Reserved
    Uint32 rsvd6:1;                           // 13 Reserved
    Uint32 rsvd7:1;                           // 14 Reserved
    Uint32 rsvd8:1;                           // 15 Reserved
    Uint32 CMPSS1_CTRIPOUTL:1;                // 16 Input Flag for CMPSS1.CTRIPOUTL Signal
    Uint32 CMPSS1_CTRIPOUTH:1;                // 17 Input Flag for CMPSS1.CTRIPOUTH Signal
    Uint32 CMPSS2_CTRIPOUTL:1;                // 18 Input Flag for CMPSS2.CTRIPOUTL Signal
    Uint32 CMPSS2_CTRIPOUTH:1;                // 19 Input Flag for CMPSS2.CTRIPOUTH Signal
    Uint32 CMPSS3_CTRIPOUTL:1;                // 20 Input Flag for CMPSS3.CTRIPOUTL Signal
    Uint32 CMPSS3_CTRIPOUTH:1;                // 21 Input Flag for CMPSS3.CTRIPOUTH Signal
    Uint32 CMPSS4_CTRIPOUTL:1;                // 22 Input Flag for CMPSS4.CTRIPOUTL Signal
    Uint32 CMPSS4_CTRIPOUTH:1;                // 23 Input Flag for CMPSS4.CTRIPOUTH Signal
    Uint32 rsvd9:1;                           // 24 Reserved
    Uint32 rsvd10:1;                          // 25 Reserved
    Uint32 rsvd11:1;                          // 26 Reserved
    Uint32 rsvd12:1;                          // 27 Reserved
    Uint32 rsvd13:1;                          // 28 Reserved
    Uint32 rsvd14:1;                          // 29 Reserved
    Uint32 rsvd15:1;                          // 30 Reserved
    Uint32 rsvd16:1;                          // 31 Reserved
};

union XBARFLG1_REG {
    Uint32  all;
    struct  XBARFLG1_BITS  bit;
};

struct XBARFLG2_BITS {                        // bits description
    Uint32 INPUT1:1;                          // 0 Input Flag for INPUT1 Signal
    Uint32 INPUT2:1;                          // 1 Input Flag for INPUT2 Signal
    Uint32 INPUT3:1;                          // 2 Input Flag for INPUT3 Signal
    Uint32 INPUT4:1;                          // 3 Input Flag for INPUT4 Signal
    Uint32 INPUT5:1;                          // 4 Input Flag for INPUT5 Signal
    Uint32 INPUT6:1;                          // 5 Input Flag for INPUT6 Signal
    Uint32 ADCSOCA:1;                         // 6 Input Flag for ADCSOCA Signal
    Uint32 ADCSOCB:1;                         // 7 Input Flag for ADCSOCB Signal
    Uint32 INPUT7:1;                          // 8 Input Flag for INPUT7 Signal
    Uint32 INPUT8:1;                          // 9 Input Flag for INPUT8 Signal
    Uint32 INPUT9:1;                          // 10 Input Flag for INPUT9 Signal
    Uint32 INPUT10:1;                         // 11 Input Flag for INPUT10 Signal
    Uint32 INPUT11:1;                         // 12 Input Flag for INPUT11 Signal
    Uint32 INPUT12:1;                         // 13 Input Flag for INPUT12 Signal
    Uint32 INPUT13:1;                         // 14 Input Flag for INPUT13 Signal
    Uint32 INPUT14:1;                         // 15 Input Flag for INPUT14 Signal
    Uint32 ECAP1_OUT:1;                       // 16 Input Flag for ECAP1.OUT Signal
    Uint32 ECAP2_OUT:1;                       // 17 Input Flag for ECAP2.OUT Signal
    Uint32 ECAP3_OUT:1;                       // 18 Input Flag for ECAP3.OUT Signal
    Uint32 rsvd1:1;                           // 19 Reserved
    Uint32 rsvd2:1;                           // 20 Reserved
    Uint32 rsvd3:1;                           // 21 Reserved
    Uint32 EXTSYNCOUT:1;                      // 22 Input Flag for EXTSYNCOUT Signal
    Uint32 ADCAEVT1:1;                        // 23 Input Flag for ADCAEVT1 Signal
    Uint32 ADCAEVT2:1;                        // 24 Input Flag for ADCAEVT2 Signal
    Uint32 ADCAEVT3:1;                        // 25 Input Flag for ADCAEVT3 Signal
    Uint32 ADCAEVT4:1;                        // 26 Input Flag for ADCAEVT4 Signal
    Uint32 rsvd4:1;                           // 27 Reserved
    Uint32 rsvd5:1;                           // 28 Reserved
    Uint32 rsvd6:1;                           // 29 Reserved
    Uint32 rsvd7:1;                           // 30 Reserved
    Uint32 ADCCEVT1:1;                        // 31 Input Flag for ADCCEVT1 Signal
};

union XBARFLG2_REG {
    Uint32  all;
    struct  XBARFLG2_BITS  bit;
};

struct XBARFLG3_BITS {                        // bits description
    Uint32 ADCCEVT2:1;                        // 0 Input Flag for ADCCEVT2 Signal
    Uint32 ADCCEVT3:1;                        // 1 Input Flag for ADCCEVT3 Signal
    Uint32 ADCCEVT4:1;                        // 2 Input Flag for ADCCEVT4 Signal
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 rsvd5:1;                           // 7 Reserved
    Uint32 rsvd6:1;                           // 8 Reserved
    Uint32 rsvd7:1;                           // 9 Reserved
    Uint32 rsvd8:1;                           // 10 Reserved
    Uint32 rsvd9:1;                           // 11 Reserved
    Uint32 rsvd10:1;                          // 12 Reserved
    Uint32 rsvd11:1;                          // 13 Reserved
    Uint32 rsvd12:1;                          // 14 Reserved
    Uint32 rsvd13:1;                          // 15 Reserved
    Uint32 rsvd14:1;                          // 16 Reserved
    Uint32 rsvd15:1;                          // 17 Reserved
    Uint32 rsvd16:1;                          // 18 Reserved
    Uint32 rsvd17:1;                          // 19 Reserved
    Uint32 rsvd18:1;                          // 20 Reserved
    Uint32 rsvd19:1;                          // 21 Reserved
    Uint32 rsvd20:1;                          // 22 Reserved
    Uint32 rsvd21:1;                          // 23 Reserved
    Uint32 rsvd22:1;                          // 24 Reserved
    Uint32 rsvd23:1;                          // 25 Reserved
    Uint32 rsvd24:1;                          // 26 Reserved
    Uint32 rsvd25:1;                          // 27 Reserved
    Uint32 rsvd26:1;                          // 28 Reserved
    Uint32 rsvd27:1;                          // 29 Reserved
    Uint32 rsvd28:1;                          // 30 Reserved
    Uint32 rsvd29:1;                          // 31 Reserved
};

union XBARFLG3_REG {
    Uint32  all;
    struct  XBARFLG3_BITS  bit;
};

struct XBARFLG4_BITS {                        // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 rsvd5:1;                           // 4 Reserved
    Uint32 rsvd6:1;                           // 5 Reserved
    Uint32 rsvd7:1;                           // 6 Reserved
    Uint32 rsvd8:1;                           // 7 Reserved
    Uint32 rsvd9:8;                           // 15:8 Reserved
    Uint32 CLB1_4_1:1;                        // 16 Input Flag for CLB1_4.1 Signal
    Uint32 CLB1_5_1:1;                        // 17 Input Flag for CLB1_5.1 Signal
    Uint32 CLB2_4_1:1;                        // 18 Input Flag for CLB2_4.1 Signal
    Uint32 CLB2_5_1:1;                        // 19 Input Flag for CLB2_5.1 Signal
    Uint32 rsvd10:1;                          // 20 Reserved
    Uint32 rsvd11:1;                          // 21 Reserved
    Uint32 rsvd12:1;                          // 22 Reserved
    Uint32 rsvd13:1;                          // 23 Reserved
    Uint32 rsvd14:7;                          // 30:24 Reserved
    Uint32 rsvd15:1;                          // 31 Reserved
};

union XBARFLG4_REG {
    Uint32  all;
    struct  XBARFLG4_BITS  bit;
};

struct XBARCLR1_BITS {                        // bits description
    Uint32 CMPSS1_CTRIPL:1;                   // 0 Input Flag Clear for CMPSS1.CTRIPL Signal
    Uint32 CMPSS1_CTRIPH:1;                   // 1 Input Flag Clear for CMPSS1.CTRIPH Signal
    Uint32 CMPSS2_CTRIPL:1;                   // 2 Input Flag Clear for CMPSS2.CTRIPL Signal
    Uint32 CMPSS2_CTRIPH:1;                   // 3 Input Flag Clear for CMPSS2.CTRIPH Signal
    Uint32 CMPSS3_CTRIPL:1;                   // 4 Input Flag Clear for CMPSS3.CTRIPL Signal
    Uint32 CMPSS3_CTRIPH:1;                   // 5 Input Flag Clear for CMPSS3.CTRIPH Signal
    Uint32 CMPSS4_CTRIPL:1;                   // 6 Input Flag Clear for CMPSS4.CTRIPL Signal
    Uint32 CMPSS4_CTRIPH:1;                   // 7 Input Flag Clear for CMPSS4.CTRIPH Signal
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:1;                           // 9 Reserved
    Uint32 rsvd3:1;                           // 10 Reserved
    Uint32 rsvd4:1;                           // 11 Reserved
    Uint32 rsvd5:1;                           // 12 Reserved
    Uint32 rsvd6:1;                           // 13 Reserved
    Uint32 rsvd7:1;                           // 14 Reserved
    Uint32 rsvd8:1;                           // 15 Reserved
    Uint32 CMPSS1_CTRIPOUTL:1;                // 16 Input Flag Clear for CMPSS1.CTRIPOUTL Signal
    Uint32 CMPSS1_CTRIPOUTH:1;                // 17 Input Flag Clear for CMPSS1.CTRIPOUTH Signal
    Uint32 CMPSS2_CTRIPOUTL:1;                // 18 Input Flag Clear for CMPSS2.CTRIPOUTL Signal
    Uint32 CMPSS2_CTRIPOUTH:1;                // 19 Input Flag Clear for CMPSS2.CTRIPOUTH Signal
    Uint32 CMPSS3_CTRIPOUTL:1;                // 20 Input Flag Clear for CMPSS3.CTRIPOUTL Signal
    Uint32 CMPSS3_CTRIPOUTH:1;                // 21 Input Flag Clear for CMPSS3.CTRIPOUTH Signal
    Uint32 CMPSS4_CTRIPOUTL:1;                // 22 Input Flag Clear for CMPSS4.CTRIPOUTL Signal
    Uint32 CMPSS4_CTRIPOUTH:1;                // 23 Input Flag Clear for CMPSS4.CTRIPOUTH Signal
    Uint32 rsvd9:1;                           // 24 Reserved
    Uint32 rsvd10:1;                          // 25 Reserved
    Uint32 rsvd11:1;                          // 26 Reserved
    Uint32 rsvd12:1;                          // 27 Reserved
    Uint32 rsvd13:1;                          // 28 Reserved
    Uint32 rsvd14:1;                          // 29 Reserved
    Uint32 rsvd15:1;                          // 30 Reserved
    Uint32 rsvd16:1;                          // 31 Reserved
};

union XBARCLR1_REG {
    Uint32  all;
    struct  XBARCLR1_BITS  bit;
};

struct XBARCLR2_BITS {                        // bits description
    Uint32 INPUT1:1;                          // 0 Input Flag Clear for INPUT1 Signal
    Uint32 INPUT2:1;                          // 1 Input Flag Clear for INPUT2 Signal
    Uint32 INPUT3:1;                          // 2 Input Flag Clear for INPUT3 Signal
    Uint32 INPUT4:1;                          // 3 Input Flag Clear for INPUT4 Signal
    Uint32 INPUT5:1;                          // 4 Input Flag Clear for INPUT5 Signal
    Uint32 INPUT6:1;                          // 5 Input Flag Clear for INPUT6 Signal
    Uint32 ADCSOCA:1;                         // 6 Input Flag Clear for ADCSOCA Signal
    Uint32 ADCSOCB:1;                         // 7 Input Flag Clear for ADCSOCB Signal
    Uint32 INPUT7:1;                          // 8 Input Flag Clear for INPUT7 Signal
    Uint32 INPUT8:1;                          // 9 Input Flag Clear for INPUT8 Signal
    Uint32 INPUT9:1;                          // 10 Input Flag Clear for INPUT9 Signal
    Uint32 INPUT10:1;                         // 11 Input Flag Clear for INPUT10 Signal
    Uint32 INPUT11:1;                         // 12 Input Flag Clear for INPUT11 Signal
    Uint32 INPUT12:1;                         // 13 Input Flag Clear for INPUT12 Signal
    Uint32 INPUT13:1;                         // 14 Input Flag Clear for INPUT13 Signal
    Uint32 INPUT14:1;                         // 15 Input Flag Clear for INPUT14 Signal
    Uint32 ECAP1_OUT:1;                       // 16 Input Flag Clear for ECAP1.OUT Signal
    Uint32 ECAP2_OUT:1;                       // 17 Input Flag Clear for ECAP2.OUT Signal
    Uint32 ECAP3_OUT:1;                       // 18 Input Flag Clear for ECAP3.OUT Signal
    Uint32 rsvd1:1;                           // 19 Reserved
    Uint32 rsvd2:1;                           // 20 Reserved
    Uint32 rsvd3:1;                           // 21 Reserved
    Uint32 EXTSYNCOUT:1;                      // 22 Input Flag Clear for EXTSYNCOUT Signal
    Uint32 ADCAEVT1:1;                        // 23 Input Flag Clear for ADCAEVT1 Signal
    Uint32 ADCAEVT2:1;                        // 24 Input Flag Clear for ADCAEVT2 Signal
    Uint32 ADCAEVT3:1;                        // 25 Input Flag Clear for ADCAEVT3 Signal
    Uint32 ADCAEVT4:1;                        // 26 Input Flag Clear for ADCAEVT4 Signal
    Uint32 rsvd4:1;                           // 27 Reserved
    Uint32 rsvd5:1;                           // 28 Reserved
    Uint32 rsvd6:1;                           // 29 Reserved
    Uint32 rsvd7:1;                           // 30 Reserved
    Uint32 ADCCEVT1:1;                        // 31 Input Flag Clear for ADCCEVT1 Signal
};

union XBARCLR2_REG {
    Uint32  all;
    struct  XBARCLR2_BITS  bit;
};

struct XBARCLR3_BITS {                        // bits description
    Uint32 ADCCEVT2:1;                        // 0 Input Flag Clear for ADCCEVT2 Signal
    Uint32 ADCCEVT3:1;                        // 1 Input Flag Clear for ADCCEVT3 Signal
    Uint32 ADCCEVT4:1;                        // 2 Input Flag Clear for ADCCEVT4 Signal
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 rsvd5:1;                           // 7 Reserved
    Uint32 rsvd6:1;                           // 8 Reserved
    Uint32 rsvd7:1;                           // 9 Reserved
    Uint32 rsvd8:1;                           // 10 Reserved
    Uint32 rsvd9:1;                           // 11 Reserved
    Uint32 rsvd10:1;                          // 12 Reserved
    Uint32 rsvd11:1;                          // 13 Reserved
    Uint32 rsvd12:1;                          // 14 Reserved
    Uint32 rsvd13:1;                          // 15 Reserved
    Uint32 rsvd14:1;                          // 16 Reserved
    Uint32 rsvd15:1;                          // 17 Reserved
    Uint32 rsvd16:1;                          // 18 Reserved
    Uint32 rsvd17:1;                          // 19 Reserved
    Uint32 rsvd18:1;                          // 20 Reserved
    Uint32 rsvd19:1;                          // 21 Reserved
    Uint32 rsvd20:1;                          // 22 Reserved
    Uint32 rsvd21:1;                          // 23 Reserved
    Uint32 rsvd22:1;                          // 24 Reserved
    Uint32 rsvd23:1;                          // 25 Reserved
    Uint32 rsvd24:1;                          // 26 Reserved
    Uint32 rsvd25:1;                          // 27 Reserved
    Uint32 rsvd26:1;                          // 28 Reserved
    Uint32 rsvd27:1;                          // 29 Reserved
    Uint32 rsvd28:1;                          // 30 Reserved
    Uint32 rsvd29:1;                          // 31 Reserved
};

union XBARCLR3_REG {
    Uint32  all;
    struct  XBARCLR3_BITS  bit;
};

struct XBARCLR4_BITS {                        // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 rsvd5:1;                           // 4 Reserved
    Uint32 rsvd6:1;                           // 5 Reserved
    Uint32 rsvd7:1;                           // 6 Reserved
    Uint32 rsvd8:1;                           // 7 Reserved
    Uint32 rsvd9:8;                           // 15:8 Reserved
    Uint32 CLB1_4_1:1;                        // 16 Input Flag clear for CLB1_4.1 Signal
    Uint32 CLB1_5_1:1;                        // 17 Input Flag clear for CLB1_5.1 Signal
    Uint32 CLB2_4_1:1;                        // 18 Input Flag clear for CLB2_4.1 Signal
    Uint32 CLB2_5_1:1;                        // 19 Input Flag clear for CLB2_5.1 Signal
    Uint32 rsvd10:1;                          // 20 Reserved
    Uint32 rsvd11:1;                          // 21 Reserved
    Uint32 rsvd12:1;                          // 22 Reserved
    Uint32 rsvd13:1;                          // 23 Reserved
    Uint32 rsvd14:7;                          // 30:24 Reserved
    Uint32 rsvd15:1;                          // 31 Reserved
};

union XBARCLR4_REG {
    Uint32  all;
    struct  XBARCLR4_BITS  bit;
};

struct  XBAR_REGS {
    union   XBARFLG1_REG                     XBARFLG1;                    // 0x0 X-Bar Input Flag Register 1
    union   XBARFLG2_REG                     XBARFLG2;                    // 0x4 X-Bar Input Flag Register 2
    union   XBARFLG3_REG                     XBARFLG3;                    // 0x8 X-Bar Input Flag Register 3
    union   XBARFLG4_REG                     XBARFLG4;                    // 0xc X-Bar Input Flag Register 4
    union   XBARCLR1_REG                     XBARCLR1;                    // 0x10 X-Bar Input Flag Clear Register 1
    union   XBARCLR2_REG                     XBARCLR2;                    // 0x14 X-Bar Input Flag Clear Register 2
    union   XBARCLR3_REG                     XBARCLR3;                    // 0x18 X-Bar Input Flag Clear Register 3
    union   XBARCLR4_REG                     XBARCLR4;                    // 0x1c X-Bar Input Flag Clear Register 4
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================