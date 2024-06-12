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


#ifndef F28002X_FLASH_H
#define F28002X_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// FLASH Individual Register Bit Definitions:

struct FRDCNTL_BITS {                         // bits description
    Uint32 RWAIT:3;                           // 2:0 Flash Read Control Word
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union FRDCNTL_REG {
    Uint32  all;
    struct  FRDCNTL_BITS  bit;
};

struct FBFALLBACK_BITS {                      // bits description
    Uint32 BNKPWR0:2;                         // 1:0 Bank Power Mode of BANK0
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:12;                          // 15:4 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union FBFALLBACK_REG {
    Uint32  all;
    struct  FBFALLBACK_BITS  bit;
};

struct FBAC2_BITS {                           // bits description
    Uint32 PAGP:16;                           // 15:0 Control continuous access to flash time
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union FBAC2_REG {
    Uint32  all;
    struct  FBAC2_BITS  bit;
};

struct FMSTAT_BITS {                          // bits description
    Uint32 STATUS:6;                          // 5:0 Status register
    Uint32 INIT_FINISH:1;                     // 6 Power on initialization completion flag signal
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union FMSTAT_REG {
    Uint32  all;
    struct  FMSTAT_BITS  bit;
};

struct FRD_INTF_CTRL_BITS {                   // bits description
    Uint32 PREFETCH_EN:1;                     // 0 Prefetch Enable
    Uint32 DATA_CACHE_EN:1;                   // 1 Data Cache Enable
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union FRD_INTF_CTRL_REG {
    Uint32  all;
    struct  FRD_INTF_CTRL_BITS  bit;
};

struct  FLASH_CTRL_REGS {
    Uint32                                   FLASH_INIT;                  // 0x0 flash init Register No configuration required,automatic initialzation after power-on
    union   FRDCNTL_REG                      FRDCNTL;                     // 0x4 Flash Read Control Register
    union   FBFALLBACK_REG                   FBFALLBACK;                  // 0x8 Flash Bank Fallback Power Register
    union   FBAC2_REG                        FBAC2;                       // 0xc Flash Bank Access Control Register
    union   FMSTAT_REG                       FMSTAT;                      // 0x10 FLASH status register
    union   FRD_INTF_CTRL_REG                FRD_INTF_CTRL;               // 0x14 Flash Read Interface Control Register
    Uint32                                   rsvd1[26];                   // 0x18 Reserved
    Uint32                                   FT100N;                      // 0x80 100ns Control Word
    Uint32                                   FT4U;                        // 0x84 4us Control Word
    Uint32                                   FT5U;                        // 0x88 5us Control Word
    Uint32                                   FT9U;                        // 0x8c 9us Control Word
    Uint32                                   FT20U;                       // 0x90 20us Control Word
    Uint32                                   FT25U;                       // 0x94 25us Control Word
    Uint32                                   FT50U;                       // 0x98 50us Control Word
    Uint32                                   FT900U;                      // 0x9c 900us Control Word
    Uint32                                   FT4M;                        // 0xa0 3600us Control Word
    Uint32                                   FT9M;                        // 0xa4 9ms Control Word
};

struct ECC_ENABLE_BITS {                      // bits description
    Uint32 ENABLE:4;                          // 3:0 Enable ECC
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ECC_ENABLE_REG {
    Uint32  all;
    struct  ECC_ENABLE_BITS  bit;
};

struct ERR_STATUS_BITS {                      // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 UNC_ERR_L:1;                       // 2 Lower 64 bits Uncorrectable error occurred
    Uint32 rsvd2:15;                          // 17:3 Reserved
    Uint32 UNC_ERR_H:1;                       // 18 Upper 64 bits Uncorrectable error occurred
    Uint32 rsvd3:13;                          // 31:19 Reserved
};

union ERR_STATUS_REG {
    Uint32  all;
    struct  ERR_STATUS_BITS  bit;
};

struct ERR_STATUS_CLR_BITS {                  // bits description
    Uint32 rsvd1:2;                           // 1:0 Lower 64bits Single Bit Error Corrected Value 0 Clear
    Uint32 UNC_ERR_L_CLR:1;                   // 2 Lower 64 bits Uncorrectable error occurred Clear
    Uint32 rsvd2:15;                          // 17:3 Reserved
    Uint32 UNC_ERR_H_CLR:1;                   // 18 Upper 64 bits Uncorrectable error occurred Clear
    Uint32 rsvd3:13;                          // 31:19 Reserved
};

union ERR_STATUS_CLR_REG {
    Uint32  all;
    struct  ERR_STATUS_CLR_BITS  bit;
};

struct ERR_CNT_BITS {                         // bits description
    Uint32 ERR_CNT:16;                        // 15:0 Error counter
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ERR_CNT_REG {
    Uint32  all;
    struct  ERR_CNT_BITS  bit;
};

struct ERR_THRESHOLD_BITS {                   // bits description
    Uint32 ERR_THRESHOLD:16;                  // 15:0 Error Threshold
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ERR_THRESHOLD_REG {
    Uint32  all;
    struct  ERR_THRESHOLD_BITS  bit;
};

struct ERR_INTFLG_BITS {                      // bits description
    Uint32 SINGLE_ERR_INTFLG:1;               // 0 Single Error Interrupt Flag
    Uint32 UNC_ERR_INTFLG:1;                  // 1 Uncorrectable Interrupt Flag
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ERR_INTFLG_REG {
    Uint32  all;
    struct  ERR_INTFLG_BITS  bit;
};

struct ERR_INTCLR_BITS {                      // bits description
    Uint32 SINGLE_ERR_INTCLR:1;               // 0 Single Error Interrupt Flag Clear
    Uint32 UNC_ERR_INTCLR:1;                  // 1 Uncorrectable Interrupt Flag Clear
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ERR_INTCLR_REG {
    Uint32  all;
    struct  ERR_INTCLR_BITS  bit;
};

struct FADDR_TEST_BITS {                      // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 ADDRL:13;                          // 15:3 ECC Address Low
    Uint32 ADDRH:6;                           // 21:16 ECC Address High
    Uint32 rsvd2:10;                          // 31:22 Reserved
};

union FADDR_TEST_REG {
    Uint32  all;
    struct  FADDR_TEST_BITS  bit;
};

struct FECC_TEST_BITS {                       // bits description
    Uint32 ECC:8;                             // 7:0 ECC Control Bits
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union FECC_TEST_REG {
    Uint32  all;
    struct  FECC_TEST_BITS  bit;
};

struct FECC_CTRL_BITS {                       // bits description
    Uint32 ECC_TEST_EN:1;                     // 0 Enable ECC Test Logic
    Uint32 ECC_SELECT:1;                      // 1 ECC Bit Select
    Uint32 DO_ECC_CALC:1;                     // 2 Enable ECC Calculation
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union FECC_CTRL_REG {
    Uint32  all;
    struct  FECC_CTRL_BITS  bit;
};

struct FECC_STATUS_BITS {                     // bits description
    Uint32 SINGLE_ERR:1;                      // 0 Test Result is Single Bit Error
    Uint32 UNC_ERR:1;                         // 1 Test Result is Uncorrectable Error
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union FECC_STATUS_REG {
    Uint32  all;
    struct  FECC_STATUS_BITS  bit;
};

struct  FLASH_ECC_REGS {
    union   ECC_ENABLE_REG                   ECC_ENABLE;                  // 0x0 ECC Enable
    Uint32                                   SINGLE_ERR_ADDR_LOW;         // 0x4 Single Error Address Low
    Uint32                                   SINGLE_ERR_ADDR_HIGH;        // 0x8 Single Error Address High
    Uint32                                   UNC_ERR_ADDR_LOW;            // 0xc Uncorrectable Error Address Low
    Uint32                                   UNC_ERR_ADDR_HIGH;           // 0x10 Uncorrectable Error Address High
    union   ERR_STATUS_REG                   ERR_STATUS;                  // 0x14 Error Status
    Uint32                                   rsvd1;                       // 0x18 Reserved
    union   ERR_STATUS_CLR_REG               ERR_STATUS_CLR;              // 0x1c Error Status Clear
    union   ERR_CNT_REG                      ERR_CNT;                     // 0x20 Error Control
    union   ERR_THRESHOLD_REG                ERR_THRESHOLD;               // 0x24 Error Threshold
    union   ERR_INTFLG_REG                   ERR_INTFLG;                  // 0x28 Error Interrupt Flag
    union   ERR_INTCLR_REG                   ERR_INTCLR;                  // 0x2c Error Interrupt Flag Clear
    Uint32                                   FDATAH_TEST;                 // 0x30 Data High Test
    Uint32                                   FDATAL_TEST;                 // 0x34 Data Low Test
    union   FADDR_TEST_REG                   FADDR_TEST;                  // 0x38 ECC Test Address
    union   FECC_TEST_REG                    FECC_TEST;                   // 0x3c ECC Test Address
    union   FECC_CTRL_REG                    FECC_CTRL;                   // 0x40 ECC Control
    Uint32                                   FOUTH_TEST;                  // 0x44 Test Data Out High
    Uint32                                   FOUTL_TEST;                  // 0x48 Test Data Out Low
    union   FECC_STATUS_REG                  FECC_STATUS;                 // 0x4c ECC Status
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================