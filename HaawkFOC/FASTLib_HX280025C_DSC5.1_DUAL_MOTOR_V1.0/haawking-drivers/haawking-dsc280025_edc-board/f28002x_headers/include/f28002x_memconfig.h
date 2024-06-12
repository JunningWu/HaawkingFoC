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


#ifndef F28002X_MEMCONFIG_H
#define F28002X_MEMCONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// MEMCONFIG Individual Register Bit Definitions:

struct DxLOCK_BITS {                          // bits description
    Uint32 LOCK_M0:1;                         // 0 M0 RAM Lock bits
    Uint32 LOCK_M1:1;                         // 1 M1 RAM Lock bits
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DxLOCK_REG {
    Uint32  all;
    struct  DxLOCK_BITS  bit;
};

struct DxCOMMIT_BITS {                        // bits description
    Uint32 COMMIT_M0:1;                       // 0 M0 RAM Permanent Lock bits
    Uint32 COMMIT_M1:1;                       // 1 M1 RAM Permanent Lock bits
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DxCOMMIT_REG {
    Uint32  all;
    struct  DxCOMMIT_BITS  bit;
};

struct DxTEST_BITS {                          // bits description
    Uint32 TEST_M0:2;                         // 1:0 Selects the different modes for M0 RAM
    Uint32 TEST_M1:2;                         // 3:2 Selects the different modes for M1 RAM
    Uint32 rsvd1:2;                           // 5:4 Reserved
    Uint32 rsvd2:2;                           // 7:6 Reserved
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DxTEST_REG {
    Uint32  all;
    struct  DxTEST_BITS  bit;
};

struct DxINIT_BITS {                          // bits description
    Uint32 INIT_M0:1;                         // 0 RAM Initialization control for M0 RAM.
    Uint32 INIT_M1:1;                         // 1 RAM Initialization control for M1 RAM.
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DxINIT_REG {
    Uint32  all;
    struct  DxINIT_BITS  bit;
};

struct DxINITDONE_BITS {                      // bits description
    Uint32 INITDONE_M0:1;                     // 0 RAM Initialization status for M0 RAM.
    Uint32 INITDONE_M1:1;                     // 1 RAM Initialization status for M1 RAM.
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DxINITDONE_REG {
    Uint32  all;
    struct  DxINITDONE_BITS  bit;
};

struct DxRAMTEST_LOCK_BITS {                  // bits description
    Uint32 M0:1;                              // 0 DxTEST.TEST_M0 LOCK
    Uint32 M1:1;                              // 1 DxTEST.TEST_M1 LOCK
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 KEY:16;                            // 31:16 Key for writing DxRAMTEST_LOCK
};

union DxRAMTEST_LOCK_REG {
    Uint32  all;
    struct  DxRAMTEST_LOCK_BITS  bit;
};

struct LSxLOCK_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 LOCK_LS4:1;                        // 4 LS4 RAM Lock bits
    Uint32 LOCK_LS5:1;                        // 5 LS5 RAM Lock bits
    Uint32 LOCK_LS6:1;                        // 6 LS6 RAM Lock bits
    Uint32 LOCK_LS7:1;                        // 7 LS7 RAM Lock bits
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union LSxLOCK_REG {
    Uint32  all;
    struct  LSxLOCK_BITS  bit;
};

struct LSxCOMMIT_BITS {                       // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 COMMIT_LS4:1;                      // 4 LS4 RAM Permanent Lock bits
    Uint32 COMMIT_LS5:1;                      // 5 LS5 RAM Permanent Lock bits
    Uint32 COMMIT_LS6:1;                      // 6 LS6 RAM Permanent Lock bits
    Uint32 COMMIT_LS7:1;                      // 7 LS7 RAM Permanent Lock bits
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union LSxCOMMIT_REG {
    Uint32  all;
    struct  LSxCOMMIT_BITS  bit;
};

struct LSxACCPROT1_BITS {                     // bits description
    Uint32 FETCHPROT_LS4:1;                   // 0 Fetch Protection For LS4 RAM
    Uint32 CPUWRPROT_LS4:1;                   // 1 CPU WR Protection For LS4 RAM
    Uint32 rsvd1:6;                           // 7:2 Reserved
    Uint32 FETCHPROT_LS5:1;                   // 8 Fetch Protection For LS5 RAM
    Uint32 CPUWRPROT_LS5:1;                   // 9 CPU WR Protection For LS5 RAM
    Uint32 rsvd2:6;                           // 15:10 Reserved
    Uint32 FETCHPROT_LS6:1;                   // 16 Fetch Protection For LS6 RAM
    Uint32 CPUWRPROT_LS6:1;                   // 17 CPU WR Protection For LS6 RAM
    Uint32 rsvd3:6;                           // 23:18 Reserved
    Uint32 FETCHPROT_LS7:1;                   // 24 Fetch Protection For LS7 RAM
    Uint32 CPUWRPROT_LS7:1;                   // 25 CPU WR Protection For LS7 RAM
    Uint32 rsvd4:6;                           // 31:26 Reserved
};

union LSxACCPROT1_REG {
    Uint32  all;
    struct  LSxACCPROT1_BITS  bit;
};

struct LSxTEST_BITS {                         // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 rsvd2:2;                           // 3:2 Reserved
    Uint32 rsvd3:2;                           // 5:4 Reserved
    Uint32 rsvd4:2;                           // 7:6 Reserved
    Uint32 TEST_LS4:2;                        // 9:8 Selects the different modes for LS4 RAM
    Uint32 TEST_LS5:2;                        // 11:10 Selects the different modes for LS5 RAM
    Uint32 TEST_LS6:2;                        // 13:12 Selects the different modes for LS6 RAM
    Uint32 TEST_LS7:2;                        // 15:14 Selects the different modes for LS7 RAM
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union LSxTEST_REG {
    Uint32  all;
    struct  LSxTEST_BITS  bit;
};

struct LSxINIT_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 INIT_LS4:1;                        // 4 RAM Initialization control for LS4 RAM.
    Uint32 INIT_LS5:1;                        // 5 RAM Initialization control for LS5 RAM.
    Uint32 INIT_LS6:1;                        // 6 RAM Initialization control for LS6 RAM.
    Uint32 INIT_LS7:1;                        // 7 RAM Initialization control for LS7 RAM.
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union LSxINIT_REG {
    Uint32  all;
    struct  LSxINIT_BITS  bit;
};

struct LSxINITDONE_BITS {                     // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 INITDONE_LS4:1;                    // 4 RAM Initialization status for LS4 RAM.
    Uint32 INITDONE_LS5:1;                    // 5 RAM Initialization status for LS5 RAM.
    Uint32 INITDONE_LS6:1;                    // 6 RAM Initialization status for LS6 RAM.
    Uint32 INITDONE_LS7:1;                    // 7 RAM Initialization status for LS7 RAM.
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union LSxINITDONE_REG {
    Uint32  all;
    struct  LSxINITDONE_BITS  bit;
};

struct LSxRAMTEST_LOCK_BITS {                 // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 LS4:1;                             // 4 LSxTEST.TEST_LS4 LOCK
    Uint32 LS5:1;                             // 5 LSxTEST.TEST_LS5 LOCK
    Uint32 LS6:1;                             // 6 LSxTEST.TEST_LS6 LOCK
    Uint32 LS7:1;                             // 7 LSxTEST.TEST_LS7 LOCK
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 KEY:16;                            // 31:16 KEY to enable write to lock
};

union LSxRAMTEST_LOCK_REG {
    Uint32  all;
    struct  LSxRAMTEST_LOCK_BITS  bit;
};

struct GSxLOCK_BITS {                         // bits description
    Uint32 LOCK_GS0:1;                        // 0 GS0 RAM Lock bits
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:1;                           // 6 Reserved
    Uint32 rsvd7:1;                           // 7 Reserved
    Uint32 rsvd8:1;                           // 8 Reserved
    Uint32 rsvd9:1;                           // 9 Reserved
    Uint32 rsvd10:1;                          // 10 Reserved
    Uint32 rsvd11:1;                          // 11 Reserved
    Uint32 rsvd12:1;                          // 12 Reserved
    Uint32 rsvd13:1;                          // 13 Reserved
    Uint32 rsvd14:1;                          // 14 Reserved
    Uint32 rsvd15:1;                          // 15 Reserved
    Uint32 rsvd16:16;                         // 31:16 Reserved
};

union GSxLOCK_REG {
    Uint32  all;
    struct  GSxLOCK_BITS  bit;
};

struct GSxCOMMIT_BITS {                       // bits description
    Uint32 COMMIT_GS0:1;                      // 0 GS0 RAM Permanent Lock bits
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:1;                           // 6 Reserved
    Uint32 rsvd7:1;                           // 7 Reserved
    Uint32 rsvd8:1;                           // 8 Reserved
    Uint32 rsvd9:1;                           // 9 Reserved
    Uint32 rsvd10:1;                          // 10 Reserved
    Uint32 rsvd11:1;                          // 11 Reserved
    Uint32 rsvd12:1;                          // 12 Reserved
    Uint32 rsvd13:1;                          // 13 Reserved
    Uint32 rsvd14:1;                          // 14 Reserved
    Uint32 rsvd15:1;                          // 15 Reserved
    Uint32 rsvd16:16;                         // 31:16 Reserved
};

union GSxCOMMIT_REG {
    Uint32  all;
    struct  GSxCOMMIT_BITS  bit;
};

struct GSxACCPROT0_BITS {                     // bits description
    Uint32 FETCHPROT_GS0:1;                   // 0 Fetch Protection For GS0 RAM
    Uint32 CPUWRPROT_GS0:1;                   // 1 CPU WR Protection For GS0 RAM
    Uint32 DMAWRPROT_GS0:1;                   // 2 DMA WR Protection For GS0 RAM
    Uint32 HICWRPROT_GS0:1;                   // 3 HIC WR Protection For GS0 RAM
    Uint32 rsvd1:4;                           // 7:4 Reserved
    Uint32 rsvd2:1;                           // 8 Reserved
    Uint32 rsvd3:1;                           // 9 Reserved
    Uint32 rsvd4:1;                           // 10 Reserved
    Uint32 rsvd5:5;                           // 15:11 Reserved
    Uint32 rsvd6:1;                           // 16 Reserved
    Uint32 rsvd7:1;                           // 17 Reserved
    Uint32 rsvd8:1;                           // 18 Reserved
    Uint32 rsvd9:5;                           // 23:19 Reserved
    Uint32 rsvd10:1;                          // 24 Reserved
    Uint32 rsvd11:1;                          // 25 Reserved
    Uint32 rsvd12:1;                          // 26 Reserved
    Uint32 rsvd13:5;                          // 31:27 Reserved
};

union GSxACCPROT0_REG {
    Uint32  all;
    struct  GSxACCPROT0_BITS  bit;
};

struct GSxTEST_BITS {                         // bits description
    Uint32 TEST_GS0:2;                        // 1:0 Selects the different modes for GS0 RAM
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 rsvd3:2;                           // 7:6 Reserved
    Uint32 rsvd4:2;                           // 9:8 Reserved
    Uint32 rsvd5:2;                           // 11:10 Reserved
    Uint32 rsvd6:2;                           // 13:12 Reserved
    Uint32 rsvd7:2;                           // 15:14 Reserved
    Uint32 rsvd8:2;                           // 17:16 Reserved
    Uint32 rsvd9:2;                           // 19:18 Reserved
    Uint32 rsvd10:2;                          // 21:20 Reserved
    Uint32 rsvd11:2;                          // 23:22 Reserved
    Uint32 rsvd12:2;                          // 25:24 Reserved
    Uint32 rsvd13:2;                          // 27:26 Reserved
    Uint32 rsvd14:2;                          // 29:28 Reserved
    Uint32 rsvd15:2;                          // 31:30 Reserved
};

union GSxTEST_REG {
    Uint32  all;
    struct  GSxTEST_BITS  bit;
};

struct GSxINIT_BITS {                         // bits description
    Uint32 INIT_GS0:1;                        // 0 RAM Initialization control for GS0 RAM.
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:1;                           // 6 Reserved
    Uint32 rsvd7:1;                           // 7 Reserved
    Uint32 rsvd8:1;                           // 8 Reserved
    Uint32 rsvd9:1;                           // 9 Reserved
    Uint32 rsvd10:1;                          // 10 Reserved
    Uint32 rsvd11:1;                          // 11 Reserved
    Uint32 rsvd12:1;                          // 12 Reserved
    Uint32 rsvd13:1;                          // 13 Reserved
    Uint32 rsvd14:1;                          // 14 Reserved
    Uint32 rsvd15:1;                          // 15 Reserved
    Uint32 rsvd16:16;                         // 31:16 Reserved
};

union GSxINIT_REG {
    Uint32  all;
    struct  GSxINIT_BITS  bit;
};

struct GSxINITDONE_BITS {                     // bits description
    Uint32 INITDONE_GS0:1;                    // 0 RAM Initialization status for GS0 RAM.
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:1;                           // 6 Reserved
    Uint32 rsvd7:1;                           // 7 Reserved
    Uint32 rsvd8:1;                           // 8 Reserved
    Uint32 rsvd9:1;                           // 9 Reserved
    Uint32 rsvd10:1;                          // 10 Reserved
    Uint32 rsvd11:1;                          // 11 Reserved
    Uint32 rsvd12:1;                          // 12 Reserved
    Uint32 rsvd13:1;                          // 13 Reserved
    Uint32 rsvd14:1;                          // 14 Reserved
    Uint32 rsvd15:1;                          // 15 Reserved
    Uint32 rsvd16:16;                         // 31:16 Reserved
};

union GSxINITDONE_REG {
    Uint32  all;
    struct  GSxINITDONE_BITS  bit;
};

struct GSxRAMTEST_LOCK_BITS {                 // bits description
    Uint32 GS0:1;                             // 0 GSxTEST.TEST_GS0 LOCK
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:1;                           // 6 Reserved
    Uint32 rsvd7:1;                           // 7 Reserved
    Uint32 rsvd8:1;                           // 8 Reserved
    Uint32 rsvd9:1;                           // 9 Reserved
    Uint32 rsvd10:1;                          // 10 Reserved
    Uint32 rsvd11:1;                          // 11 Reserved
    Uint32 rsvd12:1;                          // 12 Reserved
    Uint32 rsvd13:1;                          // 13 Reserved
    Uint32 rsvd14:1;                          // 14 Reserved
    Uint32 rsvd15:1;                          // 15 Reserved
    Uint32 KEY:16;                            // 31:16 KEY to enable write to lock
};

union GSxRAMTEST_LOCK_REG {
    Uint32  all;
    struct  GSxRAMTEST_LOCK_BITS  bit;
};

struct ROM_LOCK_BITS {                        // bits description
    Uint32 LOCK_BOOTROM:1;                    // 0 BOOTROM Lock bits
    Uint32 LOCK_SECUREROM:1;                  // 1 SECUREROM Lock bits
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 KEY:16;                            // 31:16 Key for writing ROM LOCK
};

union ROM_LOCK_REG {
    Uint32  all;
    struct  ROM_LOCK_BITS  bit;
};

struct ROM_TEST_BITS {                        // bits description
    Uint32 TEST_BOOTROM:2;                    // 1:0 Selects the different modes for BOOTROM
    Uint32 TEST_SECUREROM:2;                  // 3:2 Selects the different modes for SECUREROM
    Uint32 rsvd1:2;                           // 5:4 Reserved
    Uint32 rsvd2:10;                          // 15:6 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ROM_TEST_REG {
    Uint32  all;
    struct  ROM_TEST_BITS  bit;
};

struct ROM_FORCE_ERROR_BITS {                 // bits description
    Uint32 FORCE_BOOTROM_ERROR:1;             // 0 Force Bootrom Parity Error
    Uint32 FORCE_SECUREROM_ERROR:1;           // 1 Force SECUREROM Parity Error
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ROM_FORCE_ERROR_REG {
    Uint32  all;
    struct  ROM_FORCE_ERROR_BITS  bit;
};

struct  MEM_CFG_REGS {
    union   DxLOCK_REG                       DxLOCK;                      // 0x0 Dedicated RAM Config Lock Register
    union   DxCOMMIT_REG                     DxCOMMIT;                    // 0x4 Dedicated RAM Config Lock Commit Register
    union   DxTEST_REG                       DxTEST;                      // 0x8 Dedicated RAM TEST Register
    union   DxINIT_REG                       DxINIT;                      // 0xc Dedicated RAM Init Register
    union   DxINITDONE_REG                   DxINITDONE;                  // 0x10 Dedicated RAM InitDone Status Register
    union   DxRAMTEST_LOCK_REG               DxRAMTEST_LOCK;              // 0x14 Lock register to Dx RAM TEST registers
    union   LSxLOCK_REG                      LSxLOCK;                     // 0x18 Local Shared RAM Config Lock Register
    union   LSxCOMMIT_REG                    LSxCOMMIT;                   // 0x1c Local Shared RAM Config Lock Commit Register
    union   LSxACCPROT1_REG                  LSxACCPROT1;                 // 0x20 Local Shared RAM Config Register 1
    union   LSxTEST_REG                      LSxTEST;                     // 0x24 Local Shared RAM TEST Register
    union   LSxINIT_REG                      LSxINIT;                     // 0x28 Local Shared RAM Init Register
    union   LSxINITDONE_REG                  LSxINITDONE;                 // 0x2c Local Shared RAM InitDone Status Register
    union   LSxRAMTEST_LOCK_REG              LSxRAMTEST_LOCK;             // 0x30 Lock register to LSx RAM TEST registers
    union   GSxLOCK_REG                      GSxLOCK;                     // 0x34 Global Shared RAM Config Lock Register
    union   GSxCOMMIT_REG                    GSxCOMMIT;                   // 0x38 Global Shared RAM Config Lock Commit Register
    union   GSxACCPROT0_REG                  GSxACCPROT0;                 // 0x3c Global Shared RAM Config Register 0
    union   GSxTEST_REG                      GSxTEST;                     // 0x40 Global Shared RAM TEST Register
    union   GSxINIT_REG                      GSxINIT;                     // 0x44 Global Shared RAM Init Register
    union   GSxINITDONE_REG                  GSxINITDONE;                 // 0x48 Global Shared RAM InitDone Status Register
    union   GSxRAMTEST_LOCK_REG              GSxRAMTEST_LOCK;             // 0x4c Lock register to GSx RAM TEST registers
    union   ROM_LOCK_REG                     ROM_LOCK;                    // 0x50 ROM Config Lock Register
    union   ROM_TEST_REG                     ROM_TEST;                    // 0x54 ROM TEST Register
    union   ROM_FORCE_ERROR_REG              ROM_FORCE_ERROR;             // 0x58 ROM Force Error register
};

struct MAVFLG_BITS {                          // bits description
    Uint32 CPUFETCH:1;                        // 0 Master CPU Fetch Access Violation Flag
    Uint32 CPUWRITE:1;                        // 1 Master CPU Write Access Violation Flag
    Uint32 DMAWRITE:1;                        // 2 Master DMA Write Access Violation Flag
    Uint32 HICAWRITE:1;                       // 3 Master HICA Write Access Violation Flag
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union MAVFLG_REG {
    Uint32  all;
    struct  MAVFLG_BITS  bit;
};

struct MAVSET_BITS {                          // bits description
    Uint32 CPUFETCH:1;                        // 0 Master CPU Fetch Access Violation Flag Set
    Uint32 CPUWRITE:1;                        // 1 Master CPU Write Access Violation Flag Set
    Uint32 DMAWRITE:1;                        // 2 Master DMA Write Access Violation Flag Set
    Uint32 HICAWRITE:1;                       // 3 Master HICA Write Access Violation Flag Set
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union MAVSET_REG {
    Uint32  all;
    struct  MAVSET_BITS  bit;
};

struct MAVCLR_BITS {                          // bits description
    Uint32 CPUFETCH:1;                        // 0 Master CPU Fetch Access Violation Flag Clear
    Uint32 CPUWRITE:1;                        // 1 Master CPU Write Access Violation Flag Clear
    Uint32 DMAWRITE:1;                        // 2 Master DMA Write Access Violation Flag Clear
    Uint32 HICAWRITE:1;                       // 3 Master HICA Write Access Violation Flag Clear
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union MAVCLR_REG {
    Uint32  all;
    struct  MAVCLR_BITS  bit;
};

struct MAVINTEN_BITS {                        // bits description
    Uint32 CPUFETCH:1;                        // 0 Master CPU Fetch Access Violation Interrupt Enable
    Uint32 CPUWRITE:1;                        // 1 Master CPU Write Access Violation Interrupt Enable
    Uint32 DMAWRITE:1;                        // 2 Master DMA Write Access Violation Interrupt Enable
    Uint32 HICAWRITE:1;                       // 3 Master HICA Write Access Violation Interrupt Enable
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union MAVINTEN_REG {
    Uint32  all;
    struct  MAVINTEN_BITS  bit;
};

struct NMAVFLG_BITS {                         // bits description
    Uint32 CPUREAD:1;                         // 0 Non Master CPU Read Access Violation Flag
    Uint32 CPUWRITE:1;                        // 1 Non Master CPU Write Access Violation Flag
    Uint32 CPUFETCH:1;                        // 2 Non Master CPU Fetch Access Violation Flag
    Uint32 DMAWRITE:1;                        // 3 Non Master DMA Write Access Violation Flag
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:1;                           // 8 Reserved
    Uint32 rsvd6:1;                           // 9 Reserved
    Uint32 DMAREAD:1;                         // 10 Non Master DMA Read Access Violation Flag
    Uint32 HICREAD:1;                         // 11 Non Master HIC Read Access Violation Flag
    Uint32 HICWRITE:1;                        // 12 Non Master HIC Write Access Violation Flag
    Uint32 rsvd7:3;                           // 15:13 Reserved
    Uint32 rsvd8:16;                          // 31:16 Reserved
};

union NMAVFLG_REG {
    Uint32  all;
    struct  NMAVFLG_BITS  bit;
};

struct NMAVSET_BITS {                         // bits description
    Uint32 CPUREAD:1;                         // 0 Non Master CPU Read Access Violation Flag Set
    Uint32 CPUWRITE:1;                        // 1 Non Master CPU Write Access Violation Flag Set
    Uint32 CPUFETCH:1;                        // 2 Non Master CPU Fetch Access Violation Flag Set
    Uint32 DMAWRITE:1;                        // 3 Non Master DMA Write Access Violation Flag Set
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:1;                           // 8 Reserved
    Uint32 rsvd6:1;                           // 9 Reserved
    Uint32 DMAREAD:1;                         // 10 Non Master DMA Read Access Violation Flag Set
    Uint32 HICREAD:1;                         // 11 Non Master HIC Read Access Violation Flag Set
    Uint32 HICWRITE:1;                        // 12 Non Master HIC Write Access Violation Flag Set
    Uint32 rsvd7:3;                           // 15:13 Reserved
    Uint32 rsvd8:16;                          // 31:16 Reserved
};

union NMAVSET_REG {
    Uint32  all;
    struct  NMAVSET_BITS  bit;
};

struct NMAVCLR_BITS {                         // bits description
    Uint32 CPUREAD:1;                         // 0 Non Master CPU Read Access Violation Flag Clear
    Uint32 CPUWRITE:1;                        // 1 Non Master CPU Write Access Violation Flag Clear
    Uint32 CPUFETCH:1;                        // 2 Non Master CPU Fetch Access Violation Flag Clear
    Uint32 DMAWRITE:1;                        // 3 Non Master DMA Write Access Violation Flag Clear
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:1;                           // 8 Reserved
    Uint32 rsvd6:1;                           // 9 Reserved
    Uint32 DMAREAD:1;                         // 10 Non Master DMA Read Access Violation Flag Clear
    Uint32 HICREAD:1;                         // 11 Non Master HIC Read Access Violation Flag Clear
    Uint32 HICWRITE:1;                        // 12 Non Master HIC Write Access Violation Flag Clear
    Uint32 rsvd7:3;                           // 15:13 Reserved
    Uint32 rsvd8:16;                          // 31:16 Reserved
};

union NMAVCLR_REG {
    Uint32  all;
    struct  NMAVCLR_BITS  bit;
};

struct NMAVINTEN_BITS {                       // bits description
    Uint32 CPUREAD:1;                         // 0 Non Master CPU Read Access Violation Interrupt Enable
    Uint32 CPUWRITE:1;                        // 1 Non Master CPU Write Access Violation Interrupt Enable
    Uint32 CPUFETCH:1;                        // 2 Non Master CPU Fetch Access Violation Interrupt Enable
    Uint32 DMAWRITE:1;                        // 3 Non Master DMA Write Access Violation Interrupt Enable
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:1;                           // 8 Reserved
    Uint32 rsvd6:1;                           // 9 Reserved
    Uint32 DMAREAD:1;                         // 10 Non Master DMA Read Access Violation Interrupt Enable
    Uint32 HICREAD:1;                         // 11 Non Master HIC Read Access Violation Interrupt Enable
    Uint32 HICWRITE:1;                        // 12 Non Master HIC Write Access Violation Interrupt Enable
    Uint32 rsvd7:3;                           // 15:13 Reserved
    Uint32 rsvd8:16;                          // 31:16 Reserved
};

union NMAVINTEN_REG {
    Uint32  all;
    struct  NMAVINTEN_BITS  bit;
};

struct  ACCESS_PROTECTION_REGS {
    union   MAVFLG_REG                       MAVFLG;                      // 0x0 Master Access Violation Flag Register
    union   MAVSET_REG                       MAVSET;                      // 0x4 Master Access Violation Flag Set Register
    union   MAVCLR_REG                       MAVCLR;                      // 0x8 Master Access Violation Flag Clear Register
    union   MAVINTEN_REG                     MAVINTEN;                    // 0xc Master Access Violation Interrupt Enable Register
    Uint32                                   MCPUFAVADDR;                 // 0x10 Master CPU Fetch Access Violation Address
    Uint32                                   MCPUWRAVADDR;                // 0x14 Master CPU Write Access Violation Address
    Uint32                                   MDMAWRAVADDR;                // 0x18 Master DMA Write Access Violation Address
    Uint32                                   MHICWRAVADDR;                // 0x1c Master HIC Write Access Violation Address
    Uint32                                   NMHICRDAVADDR;               // 0x20 Non-Master HIC Read Access Violation Address
    Uint32                                   NMHICWRAVADDR;               // 0x24 Non-Master HIC Write Access Violation Address
    Uint32                                   rsvd1[2];                    // 0x28 Reserved
    union   NMAVFLG_REG                      NMAVFLG;                     // 0x30 Non-Master Access Violation Flag Register
    union   NMAVSET_REG                      NMAVSET;                     // 0x34 Non-Master Access Violation Flag Set Register
    union   NMAVCLR_REG                      NMAVCLR;                     // 0x38 Non-Master Access Violation Flag Clear Register
    union   NMAVINTEN_REG                    NMAVINTEN;                   // 0x3c Non-Master Access Violation Interrupt Enable Register
    Uint32                                   NMCPURDAVADDR;               // 0x40 Non-Master CPU Read Access Violation Address
    Uint32                                   NMCPUWRAVADDR;               // 0x44 Non-Master CPU Write Access Violation Address
    Uint32                                   NMCPUFAVADDR;                // 0x48 Non-Master CPU Fetch Access Violation Address
    Uint32                                   NMDMARDAVADDR;               // 0x4c Non-Master DMA Read Access Violation Address
};

struct UCERRFLG_BITS {                        // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Uncorrectable Read Error Flag
    Uint32 DMARDERR:1;                        // 1 DMA Uncorrectable Read Error Flag
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:1;                           // 4 Reserved
    Uint32 HICARDERR:1;                       // 5 HICA Uncorrectable Read Error Flag
    Uint32 rsvd4:10;                          // 15:6 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union UCERRFLG_REG {
    Uint32  all;
    struct  UCERRFLG_BITS  bit;
};

struct UCERRSET_BITS {                        // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Uncorrectable Read Error Flag Set
    Uint32 DMARDERR:1;                        // 1 DMA Uncorrectable Read Error Flag Set
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:1;                           // 4 Reserved
    Uint32 HICARDERR:1;                       // 5 HICA Uncorrectable Read Error Flag Set
    Uint32 rsvd4:10;                          // 15:6 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union UCERRSET_REG {
    Uint32  all;
    struct  UCERRSET_BITS  bit;
};

struct UCERRCLR_BITS {                        // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Uncorrectable Read Error Flag Clear
    Uint32 DMARDERR:1;                        // 1 DMA Uncorrectable Read Error Flag Clear
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:1;                           // 4 Reserved
    Uint32 HICARDERR:1;                       // 5 HICA Uncorrectable Read Error Flag Clear
    Uint32 rsvd4:10;                          // 15:6 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union UCERRCLR_REG {
    Uint32  all;
    struct  UCERRCLR_BITS  bit;
};

struct CERRFLG_BITS {                         // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Correctable Read Error Flag
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union CERRFLG_REG {
    Uint32  all;
    struct  CERRFLG_BITS  bit;
};

struct CERRSET_BITS {                         // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Correctable Read Error Flag Set
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union CERRSET_REG {
    Uint32  all;
    struct  CERRSET_BITS  bit;
};

struct CERRCLR_BITS {                         // bits description
    Uint32 CPURDERR:1;                        // 0 CPU Correctable Read Error Flag Clear
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union CERRCLR_REG {
    Uint32  all;
    struct  CERRCLR_BITS  bit;
};

struct CERRTHRES_BITS {                       // bits description
    Uint32 CERRTHRES:16;                      // 15:0 Correctable error threshold.
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CERRTHRES_REG {
    Uint32  all;
    struct  CERRTHRES_BITS  bit;
};

struct CEINTFLG_BITS {                        // bits description
    Uint32 CEINTFLAG:1;                       // 0 Total corrected error count exceeded threshold flag.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CEINTFLG_REG {
    Uint32  all;
    struct  CEINTFLG_BITS  bit;
};

struct CEINTCLR_BITS {                        // bits description
    Uint32 CEINTCLR:1;                        // 0 CPU Corrected Error Threshold Exceeded Error Clear.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CEINTCLR_REG {
    Uint32  all;
    struct  CEINTCLR_BITS  bit;
};

struct CEINTSET_BITS {                        // bits description
    Uint32 CEINTSET:1;                        // 0 Total corrected error count exceeded flag set.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CEINTSET_REG {
    Uint32  all;
    struct  CEINTSET_BITS  bit;
};

struct CEINTEN_BITS {                         // bits description
    Uint32 CEINTEN:1;                         // 0 CPU/DMA Correctable Error Interrupt Enable.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CEINTEN_REG {
    Uint32  all;
    struct  CEINTEN_BITS  bit;
};

struct  MEMORY_ERROR_REGS {
    union   UCERRFLG_REG                     UCERRFLG;                    // 0x0 Uncorrectable Error Flag Register
    union   UCERRSET_REG                     UCERRSET;                    // 0x4 Uncorrectable Error Flag Set Register
    union   UCERRCLR_REG                     UCERRCLR;                    // 0x8 Uncorrectable Error Flag Clear Register
    Uint32                                   UCCPUREADDR;                 // 0xc Uncorrectable CPU Read Error Address
    Uint32                                   UCDMAREADDR;                 // 0x10 Uncorrectable DMA Read Error Address
    Uint32                                   UCHICAREADDR;                // 0x14 Uncorrectable HICA Read Error Address
    union   CERRFLG_REG                      CERRFLG;                     // 0x18 Correctable Error Flag Register
    union   CERRSET_REG                      CERRSET;                     // 0x1c Correctable Error Flag Set Register
    union   CERRCLR_REG                      CERRCLR;                     // 0x20 Correctable Error Flag Clear Register
    Uint32                                   CCPUREADDR;                  // 0x24 Correctable CPU Read Error Address
    Uint32                                   CERRCNT;                     // 0x28 Correctable Error Count Register
    union   CERRTHRES_REG                    CERRTHRES;                   // 0x2c Correctable Error Threshold Value Register
    union   CEINTFLG_REG                     CEINTFLG;                    // 0x30 Correctable Error Interrupt Flag Status Register
    union   CEINTCLR_REG                     CEINTCLR;                    // 0x34 Correctable Error Interrupt Flag Clear Register
    union   CEINTSET_REG                     CEINTSET;                    // 0x38 Correctable Error Interrupt Flag Set Register
    union   CEINTEN_REG                      CEINTEN;                     // 0x3c Correctable Error Interrupt Enable Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================