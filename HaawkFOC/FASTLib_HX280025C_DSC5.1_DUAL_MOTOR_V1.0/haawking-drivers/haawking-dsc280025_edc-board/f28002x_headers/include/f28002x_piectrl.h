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


#ifndef F28002X_PIECTRL_H
#define F28002X_PIECTRL_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PIECTRL Individual Register Bit Definitions:

struct PIECTRL_BITS {                         // bits description
    Uint32 ENPIE:1;                           // 0 PIE Enable
    Uint32 PIEVECT:15;                        // 15:1 PIE Vector Address
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIECTRL_REG {
    Uint32  all;
    struct  PIECTRL_BITS  bit;
};

struct PIEACK_BITS {                          // bits description
    Uint32 ACK1:1;                            // 0 Acknowledge PIE Interrupt Group 1
    Uint32 ACK2:1;                            // 1 Acknowledge PIE Interrupt Group 2
    Uint32 ACK3:1;                            // 2 Acknowledge PIE Interrupt Group 3
    Uint32 ACK4:1;                            // 3 Acknowledge PIE Interrupt Group 4
    Uint32 ACK5:1;                            // 4 Acknowledge PIE Interrupt Group 5
    Uint32 ACK6:1;                            // 5 Acknowledge PIE Interrupt Group 6
    Uint32 ACK7:1;                            // 6 Acknowledge PIE Interrupt Group 7
    Uint32 ACK8:1;                            // 7 Acknowledge PIE Interrupt Group 8
    Uint32 ACK9:1;                            // 8 Acknowledge PIE Interrupt Group 9
    Uint32 ACK10:1;                           // 9 Acknowledge PIE Interrupt Group 10
    Uint32 ACK11:1;                           // 10 Acknowledge PIE Interrupt Group 11
    Uint32 ACK12:1;                           // 11 Acknowledge PIE Interrupt Group 12
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union PIEACK_REG {
    Uint32  all;
    struct  PIEACK_BITS  bit;
};

struct PIEIER1_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 1.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 1.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 1.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 1.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 1.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 1.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 1.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 1.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 1.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 1.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 1.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 1.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 1.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 1.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 1.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 1.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER1_REG {
    Uint32  all;
    struct  PIEIER1_BITS  bit;
};

struct PIEIFR1_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 1.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 1.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 1.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 1.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 1.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 1.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 1.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 1.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 1.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 1.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 1.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 1.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 1.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 1.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 1.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 1.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR1_REG {
    Uint32  all;
    struct  PIEIFR1_BITS  bit;
};

struct PIEIER2_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 2.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 2.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 2.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 2.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 2.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 2.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 2.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 2.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 2.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 2.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 2.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 2.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 2.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 2.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 2.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 2.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER2_REG {
    Uint32  all;
    struct  PIEIER2_BITS  bit;
};

struct PIEIFR2_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 2.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 2.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 2.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 2.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 2.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 2.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 2.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 2.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 2.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 2.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 2.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 2.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 2.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 2.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 2.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 2.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR2_REG {
    Uint32  all;
    struct  PIEIFR2_BITS  bit;
};

struct PIEIER3_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 3.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 3.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 3.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 3.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 3.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 3.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 3.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 3.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 3.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 3.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 3.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 3.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 3.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 3.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 3.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 3.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER3_REG {
    Uint32  all;
    struct  PIEIER3_BITS  bit;
};

struct PIEIFR3_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 3.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 3.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 3.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 3.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 3.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 3.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 3.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 3.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 3.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 3.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 3.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 3.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 3.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 3.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 3.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 3.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR3_REG {
    Uint32  all;
    struct  PIEIFR3_BITS  bit;
};

struct PIEIER4_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 4.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 4.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 4.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 4.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 4.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 4.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 4.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 4.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 4.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 4.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 4.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 4.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 4.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 4.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 4.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 4.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER4_REG {
    Uint32  all;
    struct  PIEIER4_BITS  bit;
};

struct PIEIFR4_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 4.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 4.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 4.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 4.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 4.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 4.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 4.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 4.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 4.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 4.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 4.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 4.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 4.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 4.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 4.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 4.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR4_REG {
    Uint32  all;
    struct  PIEIFR4_BITS  bit;
};

struct PIEIER5_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 5.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 5.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 5.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 5.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 5.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 5.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 5.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 5.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 5.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 5.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 5.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 5.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 5.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 5.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 5.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 5.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER5_REG {
    Uint32  all;
    struct  PIEIER5_BITS  bit;
};

struct PIEIFR5_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 5.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 5.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 5.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 5.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 5.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 5.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 5.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 5.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 5.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 5.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 5.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 5.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 5.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 5.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 5.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 5.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR5_REG {
    Uint32  all;
    struct  PIEIFR5_BITS  bit;
};

struct PIEIER6_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 6.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 6.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 6.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 6.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 6.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 6.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 6.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 6.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 6.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 6.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 6.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 6.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 6.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 6.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 6.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 6.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER6_REG {
    Uint32  all;
    struct  PIEIER6_BITS  bit;
};

struct PIEIFR6_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 6.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 6.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 6.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 6.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 6.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 6.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 6.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 6.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 6.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 6.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 6.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 6.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 6.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 6.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 6.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 6.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR6_REG {
    Uint32  all;
    struct  PIEIFR6_BITS  bit;
};

struct PIEIER7_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 7.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 7.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 7.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 7.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 7.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 7.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 7.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 7.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 7.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 7.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 7.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 7.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 7.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 7.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 7.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 7.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER7_REG {
    Uint32  all;
    struct  PIEIER7_BITS  bit;
};

struct PIEIFR7_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 7.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 7.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 7.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 7.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 7.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 7.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 7.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 7.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 7.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 7.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 7.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 7.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 7.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 7.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 7.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 7.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR7_REG {
    Uint32  all;
    struct  PIEIFR7_BITS  bit;
};

struct PIEIER8_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 8.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 8.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 8.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 8.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 8.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 8.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 8.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 8.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 8.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 8.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 8.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 8.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 8.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 8.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 8.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 8.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER8_REG {
    Uint32  all;
    struct  PIEIER8_BITS  bit;
};

struct PIEIFR8_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 8.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 8.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 8.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 8.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 8.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 8.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 8.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 8.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 8.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 8.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 8.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 8.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 8.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 8.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 8.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 8.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR8_REG {
    Uint32  all;
    struct  PIEIFR8_BITS  bit;
};

struct PIEIER9_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 9.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 9.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 9.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 9.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 9.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 9.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 9.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 9.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 9.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 9.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 9.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 9.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 9.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 9.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 9.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 9.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER9_REG {
    Uint32  all;
    struct  PIEIER9_BITS  bit;
};

struct PIEIFR9_BITS {                         // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 9.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 9.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 9.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 9.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 9.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 9.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 9.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 9.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 9.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 9.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 9.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 9.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 9.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 9.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 9.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 9.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR9_REG {
    Uint32  all;
    struct  PIEIFR9_BITS  bit;
};

struct PIEIER10_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 10.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 10.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 10.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 10.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 10.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 10.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 10.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 10.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 10.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 10.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 10.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 10.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 10.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 10.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 10.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 10.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER10_REG {
    Uint32  all;
    struct  PIEIER10_BITS  bit;
};

struct PIEIFR10_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 10.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 10.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 10.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 10.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 10.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 10.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 10.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 10.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 10.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 10.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 10.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 10.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 10.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 10.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 10.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 10.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR10_REG {
    Uint32  all;
    struct  PIEIFR10_BITS  bit;
};

struct PIEIER11_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 11.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 11.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 11.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 11.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 11.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 11.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 11.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 11.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 11.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 11.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 11.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 11.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 11.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 11.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 11.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 11.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER11_REG {
    Uint32  all;
    struct  PIEIER11_BITS  bit;
};

struct PIEIFR11_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 11.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 11.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 11.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 11.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 11.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 11.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 11.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 11.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 11.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 11.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 11.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 11.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 11.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 11.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 11.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 11.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR11_REG {
    Uint32  all;
    struct  PIEIFR11_BITS  bit;
};

struct PIEIER12_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Enable for Interrupt 12.1
    Uint32 INTx2:1;                           // 1 Enable for Interrupt 12.2
    Uint32 INTx3:1;                           // 2 Enable for Interrupt 12.3
    Uint32 INTx4:1;                           // 3 Enable for Interrupt 12.4
    Uint32 INTx5:1;                           // 4 Enable for Interrupt 12.5
    Uint32 INTx6:1;                           // 5 Enable for Interrupt 12.6
    Uint32 INTx7:1;                           // 6 Enable for Interrupt 12.7
    Uint32 INTx8:1;                           // 7 Enable for Interrupt 12.8
    Uint32 INTx9:1;                           // 8 Enable for Interrupt 12.9
    Uint32 INTx10:1;                          // 9 Enable for Interrupt 12.10
    Uint32 INTx11:1;                          // 10 Enable for Interrupt 12.11
    Uint32 INTx12:1;                          // 11 Enable for Interrupt 12.12
    Uint32 INTx13:1;                          // 12 Enable for Interrupt 12.13
    Uint32 INTx14:1;                          // 13 Enable for Interrupt 12.14
    Uint32 INTx15:1;                          // 14 Enable for Interrupt 12.15
    Uint32 INTx16:1;                          // 15 Enable for Interrupt 12.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIER12_REG {
    Uint32  all;
    struct  PIEIER12_BITS  bit;
};

struct PIEIFR12_BITS {                        // bits description
    Uint32 INTx1:1;                           // 0 Flag for Interrupt 12.1
    Uint32 INTx2:1;                           // 1 Flag for Interrupt 12.2
    Uint32 INTx3:1;                           // 2 Flag for Interrupt 12.3
    Uint32 INTx4:1;                           // 3 Flag for Interrupt 12.4
    Uint32 INTx5:1;                           // 4 Flag for Interrupt 12.5
    Uint32 INTx6:1;                           // 5 Flag for Interrupt 12.6
    Uint32 INTx7:1;                           // 6 Flag for Interrupt 12.7
    Uint32 INTx8:1;                           // 7 Flag for Interrupt 12.8
    Uint32 INTx9:1;                           // 8 Flag for Interrupt 12.9
    Uint32 INTx10:1;                          // 9 Flag for Interrupt 12.10
    Uint32 INTx11:1;                          // 10 Flag for Interrupt 12.11
    Uint32 INTx12:1;                          // 11 Flag for Interrupt 12.12
    Uint32 INTx13:1;                          // 12 Flag for Interrupt 12.13
    Uint32 INTx14:1;                          // 13 Flag for Interrupt 12.14
    Uint32 INTx15:1;                          // 14 Flag for Interrupt 12.15
    Uint32 INTx16:1;                          // 15 Flag for Interrupt 12.16
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union PIEIFR12_REG {
    Uint32  all;
    struct  PIEIFR12_BITS  bit;
};

struct  PIE_CTRL_REGS {
    union   PIECTRL_REG                      PIECTRL;                     // 0x0 ePIE Control Register
    union   PIEACK_REG                       PIEACK;                      // 0x4 Interrupt Acknowledge Register
    union   PIEIER1_REG                      PIEIER1;                     // 0x8 Interrupt Group 1 Enable Register
    union   PIEIFR1_REG                      PIEIFR1;                     // 0xc Interrupt Group 1 Flag Register
    union   PIEIER2_REG                      PIEIER2;                     // 0x10 Interrupt Group 2 Enable Register
    union   PIEIFR2_REG                      PIEIFR2;                     // 0x14 Interrupt Group 2 Flag Register
    union   PIEIER3_REG                      PIEIER3;                     // 0x18 Interrupt Group 3 Enable Register
    union   PIEIFR3_REG                      PIEIFR3;                     // 0x1c Interrupt Group 3 Flag Register
    union   PIEIER4_REG                      PIEIER4;                     // 0x20 Interrupt Group 4 Enable Register
    union   PIEIFR4_REG                      PIEIFR4;                     // 0x24 Interrupt Group 4 Flag Register
    union   PIEIER5_REG                      PIEIER5;                     // 0x28 Interrupt Group 5 Enable Register
    union   PIEIFR5_REG                      PIEIFR5;                     // 0x2c Interrupt Group 5 Flag Register
    union   PIEIER6_REG                      PIEIER6;                     // 0x30 Interrupt Group 6 Enable Register
    union   PIEIFR6_REG                      PIEIFR6;                     // 0x34 Interrupt Group 6 Flag Register
    union   PIEIER7_REG                      PIEIER7;                     // 0x38 Interrupt Group 7 Enable Register
    union   PIEIFR7_REG                      PIEIFR7;                     // 0x3c Interrupt Group 7 Flag Register
    union   PIEIER8_REG                      PIEIER8;                     // 0x40 Interrupt Group 8 Enable Register
    union   PIEIFR8_REG                      PIEIFR8;                     // 0x44 Interrupt Group 8 Flag Register
    union   PIEIER9_REG                      PIEIER9;                     // 0x48 Interrupt Group 9 Enable Register
    union   PIEIFR9_REG                      PIEIFR9;                     // 0x4c Interrupt Group 9 Flag Register
    union   PIEIER10_REG                     PIEIER10;                    // 0x50 Interrupt Group 10 Enable Register
    union   PIEIFR10_REG                     PIEIFR10;                    // 0x54 Interrupt Group 10 Flag Register
    union   PIEIER11_REG                     PIEIER11;                    // 0x58 Interrupt Group 11 Enable Register
    union   PIEIFR11_REG                     PIEIFR11;                    // 0x5c Interrupt Group 11 Flag Register
    union   PIEIER12_REG                     PIEIER12;                    // 0x60 Interrupt Group 12 Enable Register
    union   PIEIFR12_REG                     PIEIFR12;                    // 0x64 Interrupt Group 12 Flag Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
