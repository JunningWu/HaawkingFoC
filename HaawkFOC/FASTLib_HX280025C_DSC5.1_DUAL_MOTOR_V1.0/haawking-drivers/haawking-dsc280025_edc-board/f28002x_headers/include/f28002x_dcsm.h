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


#ifndef F28002X_DCSM_H
#define F28002X_DCSM_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DCSM Individual Register Bit Definitions:

struct  DCSM_BANK0_Z1_OTP_REGS {
    Uint32                                   B0_Z1OTP_LINKPOINTER1;       // 0x0 Zone 1 Link Pointer1 in Z1 OTP for flash BANK0
    Uint32                                   rsvd1;                       // 0x4 Reserved
    Uint32                                   B0_Z1OTP_LINKPOINTER2;       // 0x8 Zone 1 Link Pointer2 in Z1 OTP for flash BANK0
    Uint32                                   rsvd2;                       // 0xc Reserved
    Uint32                                   B0_Z1OTP_LINKPOINTER3;       // 0x10 Zone 1 Link Pointer3 in Z1 OTP for flash BANK0
    Uint32                                   rsvd3;                       // 0x14 Reserved
    Uint32                                   Z1OTP_BOOTPIN_CONFIG;        // 0x18 Boot Pin Configuration
    Uint32                                   Z1OTP_GPREG2;                // 0x1c Zone-1 General Purpose Register-2 content
    Uint32                                   Z1OTP_PSWDLOCK;              // 0x20 Secure Password Lock in Z1 OTP
    Uint32                                   rsvd4;                       // 0x24 Reserved
    Uint32                                   Z1OTP_CRCLOCK;               // 0x28 Secure CRC Lock in Z1 OTP
    Uint32                                   rsvd5[3];                    // 0x2c Reserved
    Uint32                                   Z1OTP_BOOTDEF_LOW;           // 0x38 Boot definition (low 32bit)
    Uint32                                   Z1OTP_BOOTDEF_HIGH;          // 0x3c Boot definition (high 32bit)
};

struct  DCSM_BANK0_Z2_OTP_REGS {
    Uint32                                   B0_Z2OTP_LINKPOINTER1;       // 0x0 Zone 2Link Pointer1 in Z2 OTP for flash BANK0
    Uint32                                   rsvd1;                       // 0x4 Reserved
    Uint32                                   B0_Z2OTP_LINKPOINTER2;       // 0x8 Zone 2 Link Pointer2 in Z2 OTP for flash BANK0
    Uint32                                   rsvd2;                       // 0xc Reserved
    Uint32                                   B0_Z2OTP_LINKPOINTER3;       // 0x10 Zone 12Link Pointer3 in Z2 OTP for flash BANK0
    Uint32                                   rsvd3;                       // 0x14 Reserved
    Uint32                                   Z2OTP_BOOTPIN_CONFIG;        // 0x18 Boot Pin Configuration
    Uint32                                   Z2OTP_GPREG2;                // 0x1c Zone-2 General Purpose Register-2 content
    Uint32                                   Z2OTP_PSWDLOCK;              // 0x20 Secure Password Lock in Z2 OTP
    Uint32                                   rsvd4;                       // 0x24 Reserved
    Uint32                                   Z2OTP_CRCLOCK;               // 0x28 Secure CRC Lock in Z2 OTP
    Uint32                                   rsvd5[3];                    // 0x2c Reserved
    Uint32                                   Z2OTP_BOOTDEF_LOW;           // 0x38 Boot definition (low 32bit)
    Uint32                                   Z2OTP_BOOTDEF_HIGH;          // 0x3c Boot definition (high 32bit)
};

struct B0_Z1_LINKPOINTER_BITS {               // bits description
    Uint32 LINKPOINTER:29;                    // 28:0 Zone1 LINK Pointer for zone Flash BANK0
    Uint32 rsvd1:3;                           // 31:29 Reserved
};

union B0_Z1_LINKPOINTER_REG {
    Uint32  all;
    struct  B0_Z1_LINKPOINTER_BITS  bit;
};

struct Z1_OTPSECLOCK_BITS {                   // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 PSWDLOCK:4;                        // 7:4 Zone1 Password Lock.
    Uint32 CRCLOCK:4;                         // 11:8 Zone1 CRC Lock.
    Uint32 rsvd2:4;                           // 15:12 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union Z1_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z1_OTPSECLOCK_BITS  bit;
};

struct B0_Z1_LINKPOINTERERR_BITS {            // bits description
    Uint32 Z1_LINKPOINTERERR:29;              // 28:0 Error to Resolve Z1 Link pointer from OTP loaded values
    Uint32 rsvd1:3;                           // 31:29 Reserved
};

union B0_Z1_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B0_Z1_LINKPOINTERERR_BITS  bit;
};

struct Z1_CR_BITS {                           // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 ALLZERO:1;                         // 3 CSMPSWD All Zeros
    Uint32 ALLONE:1;                          // 4 CSMPSWD All Ones
    Uint32 UNSECURE:1;                        // 5 CSMPSWD Match CSMKEY
    Uint32 ARMED:1;                           // 6 CSM Passwords Read Status
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 rsvd3:7;                           // 14:8 Reserved
    Uint32 FORCESEC:1;                        // 15 Force Secure
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union Z1_CR_REG {
    Uint32  all;
    struct  Z1_CR_BITS  bit;
};

struct B0_Z1_GRABSECTR_BITS {                 // bits description
    Uint32 GRAB_SECT0:2;                      // 1:0 Grab Flash Sector 0 in BANK0
    Uint32 GRAB_SECT1:2;                      // 3:2 Grab Flash Sector 1 in BANK0
    Uint32 GRAB_SECT2:2;                      // 5:4 Grab Flash Sector 2 in BANK0
    Uint32 GRAB_SECT3:2;                      // 7:6 Grab Flash Sector 3 in BANK0
    Uint32 GRAB_SECT4:2;                      // 9:8 Grab Flash Sector 4 in BANK0
    Uint32 GRAB_SECT5:2;                      // 11:10 Grab Flash Sector 5 in BANK0
    Uint32 GRAB_SECT6:2;                      // 13:12 Grab Flash Sector 6 in BANK0
    Uint32 GRAB_SECT7:2;                      // 15:14 Grab Flash Sector 7 in BANK0
    Uint32 GRAB_SECT8:2;                      // 17:16 Grab Flash Sector 8 in BANK0
    Uint32 GRAB_SECT9:2;                      // 19:18 Grab Flash Sector 9 in BANK0
    Uint32 GRAB_SECT10:2;                     // 21:20 Grab Flash Sector 10 in BANK0
    Uint32 GRAB_SECT11:2;                     // 23:22 Grab Flash Sector 11 in BANK0
    Uint32 GRAB_SECT12:2;                     // 25:24 Grab Flash Sector 12 in BANK0
    Uint32 GRAB_SECT13:2;                     // 27:26 Grab Flash Sector 13 in BANK0
    Uint32 GRAB_SECT14:2;                     // 29:28 Grab Flash Sector 14 in BANK0
    Uint32 GRAB_SECT15:2;                     // 31:30 Grab Flash Sector 15 in BANK0
};

union B0_Z1_GRABSECTR_REG {
    Uint32  all;
    struct  B0_Z1_GRABSECTR_BITS  bit;
};

struct Z1_GRABRAMR_BITS {                     // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 rsvd2:2;                           // 3:2 Reserved
    Uint32 rsvd3:2;                           // 5:4 Reserved
    Uint32 rsvd4:2;                           // 7:6 Reserved
    Uint32 GRAB_RAM4:2;                       // 9:8 Grab RAM LS4
    Uint32 GRAB_RAM5:2;                       // 11:10 Grab RAM LS5
    Uint32 GRAB_RAM6:2;                       // 13:12 Grab RAM LS6
    Uint32 GRAB_RAM7:2;                       // 15:14 Grab RAM LS7
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union Z1_GRABRAMR_REG {
    Uint32  all;
    struct  Z1_GRABRAMR_BITS  bit;
};

struct B0_Z1_EXEONLYSECTR_BITS {              // bits description
    Uint32 EXEONLY_SECT0:1;                   // 0 Execute-Only Flash Sector 0 in Flash BANK0
    Uint32 EXEONLY_SECT1:1;                   // 1 Execute-Only Flash Sector 1 in Flash BANK0
    Uint32 EXEONLY_SECT2:1;                   // 2 Execute-Only Flash Sector 2 in Flash BANK0
    Uint32 EXEONLY_SECT3:1;                   // 3 Execute-Only Flash Sector 3 in Flash BANK0
    Uint32 EXEONLY_SECT4:1;                   // 4 Execute-Only Flash Sector 4 in Flash BANK0
    Uint32 EXEONLY_SECT5:1;                   // 5 Execute-Only Flash Sector 5 in Flash BANK0
    Uint32 EXEONLY_SECT6:1;                   // 6 Execute-Only Flash Sector 6 in Flash BANK0
    Uint32 EXEONLY_SECT7:1;                   // 7 Execute-Only Flash Sector 7 in Flash BANK0
    Uint32 EXEONLY_SECT8:1;                   // 8 Execute-Only Flash Sector 8 in Flash BANK0
    Uint32 EXEONLY_SECT9:1;                   // 9 Execute-Only Flash Sector 9 in Flash BANK0
    Uint32 EXEONLY_SECT10:1;                  // 10 Execute-Only Flash Sector 10 in Flash BANK0
    Uint32 EXEONLY_SECT11:1;                  // 11 Execute-Only Flash Sector 11 in Flash BANK0
    Uint32 EXEONLY_SECT12:1;                  // 12 Execute-Only Flash Sector 12 in Flash BANK0
    Uint32 EXEONLY_SECT13:1;                  // 13 Execute-Only Flash Sector 13 in Flash BANK0
    Uint32 EXEONLY_SECT14:1;                  // 14 Execute-Only Flash Sector 14 in Flash BANK0
    Uint32 EXEONLY_SECT15:1;                  // 15 Execute-Only Flash Sector 15 in Flash BANK0
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union B0_Z1_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B0_Z1_EXEONLYSECTR_BITS  bit;
};

struct Z1_EXEONLYRAMR_BITS {                  // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 EXEONLY_RAM4:1;                    // 4 Execute-Only RAM LS4
    Uint32 EXEONLY_RAM5:1;                    // 5 Execute-Only RAM LS5
    Uint32 EXEONLY_RAM6:1;                    // 6 Execute-Only RAM LS6
    Uint32 EXEONLY_RAM7:1;                    // 7 Execute-Only RAM LS7
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union Z1_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z1_EXEONLYRAMR_BITS  bit;
};

struct  DCSM_BANK0_Z1_REGS {
    union   B0_Z1_LINKPOINTER_REG            B0_Z1_LINKPOINTER;           // 0x0 Zone 1 Link Pointer for flash BANK0
    union   Z1_OTPSECLOCK_REG                Z1_OTPSECLOCK;               // 0x4 Zone 1 OTP Secure lock
    Uint32                                   Z1_BOOTDEF_HIGH;             // 0x8 Boot definition (high 32bit)
    union   B0_Z1_LINKPOINTERERR_REG         B0_Z1_LINKPOINTERERR;        // 0xc Link Pointer Error for flash BANK0
    Uint32                                   Z1_BOOTPIN_CONFIG;           // 0x10 Boot Pin Configuration
    Uint32                                   Z1_GPREG2;                   // 0x14 Zone1 General Purpose Register-2
    Uint32                                   Z1_BOOTDEF_LOW;              // 0x18 Boot definition (low 32bit)
    Uint32                                   rsvd1;                       // 0x1c Reserved
    Uint32                                   Z1_CSMKEY0;                  // 0x20 Zone 1 CSM Key 0
    Uint32                                   Z1_CSMKEY1;                  // 0x24 Zone 1 CSM Key 1
    Uint32                                   Z1_CSMKEY2;                  // 0x28 Zone 1 CSM Key 2
    Uint32                                   Z1_CSMKEY3;                  // 0x2c Zone 1 CSM Key 3
    union   Z1_CR_REG                        Z1_CR;                       // 0x30 Zone 1 CSM Control Register
    union   B0_Z1_GRABSECTR_REG              B0_Z1_GRABSECTR;             // 0x34 Zone 1 Grab Flash BANK0 Sectors Register
    union   Z1_GRABRAMR_REG                  Z1_GRABRAMR;                 // 0x38 Zone 1 Grab RAM Blocks Register
    union   B0_Z1_EXEONLYSECTR_REG           B0_Z1_EXEONLYSECTR;          // 0x3c Zone 1 Flash BANK0 Execute_Only Sector Register
    union   Z1_EXEONLYRAMR_REG               Z1_EXEONLYRAMR;              // 0x40 Zone 1 RAM Execute_Only Block Register
};

struct B0_Z2_LINKPOINTER_BITS {               // bits description
    Uint32 LINKPOINTER:29;                    // 28:0 Zone2 LINK Pointer in Flash BANK0
    Uint32 rsvd1:3;                           // 31:29 Reserved
};

union B0_Z2_LINKPOINTER_REG {
    Uint32  all;
    struct  B0_Z2_LINKPOINTER_BITS  bit;
};

struct Z2_OTPSECLOCK_BITS {                   // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 PSWDLOCK:4;                        // 7:4 Zone2 Password Lock.
    Uint32 CRCLOCK:4;                         // 11:8 Zone2 CRC Lock.
    Uint32 rsvd2:4;                           // 15:12 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union Z2_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z2_OTPSECLOCK_BITS  bit;
};

struct B0_Z2_LINKPOINTERERR_BITS {            // bits description
    Uint32 Z2_LINKPOINTERERR:29;              // 28:0 Error to Resolve Z2 Link pointer from OTP loaded values
    Uint32 rsvd1:3;                           // 31:29 Reserved
};

union B0_Z2_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B0_Z2_LINKPOINTERERR_BITS  bit;
};

struct Z2_CR_BITS {                           // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 ALLZERO:1;                         // 3 CSMPSWD All Zeros
    Uint32 ALLONE:1;                          // 4 CSMPSWD All Ones
    Uint32 UNSECURE:1;                        // 5 CSMPSWD Match CSMKEY
    Uint32 ARMED:1;                           // 6 CSM Passwords Read Status
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 rsvd3:7;                           // 14:8 Reserved
    Uint32 FORCESEC:1;                        // 15 Force Secure
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union Z2_CR_REG {
    Uint32  all;
    struct  Z2_CR_BITS  bit;
};

struct B0_Z2_GRABSECTR_BITS {                 // bits description
    Uint32 GRAB_SECT0:2;                      // 1:0 Grab Flash Sector 0 in Flash BANK0
    Uint32 GRAB_SECT1:2;                      // 3:2 Grab Flash Sector 1 in Flash BANK0
    Uint32 GRAB_SECT2:2;                      // 5:4 Grab Flash Sector 2 in Flash BANK0
    Uint32 GRAB_SECT3:2;                      // 7:6 Grab Flash Sector 3 in Flash BANK0
    Uint32 GRAB_SECT4:2;                      // 9:8 Grab Flash Sector 4 in Flash BANK0
    Uint32 GRAB_SECT5:2;                      // 11:10 Grab Flash Sector 5 in Flash BANK0
    Uint32 GRAB_SECT6:2;                      // 13:12 Grab Flash Sector 6 in Flash BANK0
    Uint32 GRAB_SECT7:2;                      // 15:14 Grab Flash Sector 7 in Flash BANK0
    Uint32 GRAB_SECT8:2;                      // 17:16 Grab Flash Sector 8 in Flash BANK0
    Uint32 GRAB_SECT9:2;                      // 19:18 Grab Flash Sector 9 in Flash BANK0
    Uint32 GRAB_SECT10:2;                     // 21:20 Grab Flash Sector 10 in Flash BANK0
    Uint32 GRAB_SECT11:2;                     // 23:22 Grab Flash Sector 11 in Flash BANK0
    Uint32 GRAB_SECT12:2;                     // 25:24 Grab Flash Sector 12 in Flash BANK0
    Uint32 GRAB_SECT13:2;                     // 27:26 Grab Flash Sector 13 in Flash BANK0
    Uint32 GRAB_SECT14:2;                     // 29:28 Grab Flash Sector 14 in Flash BANK0
    Uint32 GRAB_SECT15:2;                     // 31:30 Grab Flash Sector 15 in Flash BANK0
};

union B0_Z2_GRABSECTR_REG {
    Uint32  all;
    struct  B0_Z2_GRABSECTR_BITS  bit;
};

struct Z2_GRABRAMR_BITS {                     // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 rsvd2:2;                           // 3:2 Reserved
    Uint32 rsvd3:2;                           // 5:4 Reserved
    Uint32 rsvd4:2;                           // 7:6 Reserved
    Uint32 GRAB_RAM4:2;                       // 9:8 Grab RAM LS4
    Uint32 GRAB_RAM5:2;                       // 11:10 Grab RAM LS5
    Uint32 GRAB_RAM6:2;                       // 13:12 Grab RAM LS6
    Uint32 GRAB_RAM7:2;                       // 15:14 Grab RAM LS7
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union Z2_GRABRAMR_REG {
    Uint32  all;
    struct  Z2_GRABRAMR_BITS  bit;
};

struct B0_Z2_EXEONLYSECTR_BITS {              // bits description
    Uint32 EXEONLY_SECT0:1;                   // 0 Execute-Only Flash Sector 0 in Flash BANK0
    Uint32 EXEONLY_SECT1:1;                   // 1 Execute-Only Flash Sector 1 in Flash BANK0
    Uint32 EXEONLY_SECT2:1;                   // 2 Execute-Only Flash Sector 2 in Flash BANK0
    Uint32 EXEONLY_SECT3:1;                   // 3 Execute-Only Flash Sector 3 in Flash BANK0
    Uint32 EXEONLY_SECT4:1;                   // 4 Execute-Only Flash Sector 4 in Flash BANK0
    Uint32 EXEONLY_SECT5:1;                   // 5 Execute-Only Flash Sector 5 in Flash BANK0
    Uint32 EXEONLY_SECT6:1;                   // 6 Execute-Only Flash Sector 6 in Flash BANK0
    Uint32 EXEONLY_SECT7:1;                   // 7 Execute-Only Flash Sector 7 in Flash BANK0
    Uint32 EXEONLY_SECT8:1;                   // 8 Execute-Only Flash Sector 8 in Flash BANK0
    Uint32 EXEONLY_SECT9:1;                   // 9 Execute-Only Flash Sector 9 in Flash BANK0
    Uint32 EXEONLY_SECT10:1;                  // 10 Execute-Only Flash Sector 10 in Flash BANK0
    Uint32 EXEONLY_SECT11:1;                  // 11 Execute-Only Flash Sector 11 in Flash BANK0
    Uint32 EXEONLY_SECT12:1;                  // 12 Execute-Only Flash Sector 12 in Flash BANK0
    Uint32 EXEONLY_SECT13:1;                  // 13 Execute-Only Flash Sector 13 in Flash BANK0
    Uint32 EXEONLY_SECT14:1;                  // 14 Execute-Only Flash Sector 14 in Flash BANK0
    Uint32 EXEONLY_SECT15:1;                  // 15 Execute-Only Flash Sector 15 in Flash BANK0
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union B0_Z2_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B0_Z2_EXEONLYSECTR_BITS  bit;
};

struct Z2_EXEONLYRAMR_BITS {                  // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 EXEONLY_RAM4:1;                    // 4 Execute-Only RAM LS4
    Uint32 EXEONLY_RAM5:1;                    // 5 Execute-Only RAM LS5
    Uint32 EXEONLY_RAM6:1;                    // 6 Execute-Only RAM LS6
    Uint32 EXEONLY_RAM7:1;                    // 7 Execute-Only RAM LS7
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union Z2_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z2_EXEONLYRAMR_BITS  bit;
};

struct  DCSM_BANK0_Z2_REGS {
    union   B0_Z2_LINKPOINTER_REG            B0_Z2_LINKPOINTER;           // 0x0 Zone 2 Link Pointer for flash BANK0
    union   Z2_OTPSECLOCK_REG                Z2_OTPSECLOCK;               // 0x4 Zone 2 OTP Secure lock
    Uint32                                   Z2_BOOTDEF_HIGH;             // 0x8 Boot definition (high 32bit)
    union   B0_Z2_LINKPOINTERERR_REG         B0_Z2_LINKPOINTERERR;        // 0xc Link Pointer Error for flash BANK0
    Uint32                                   Z2_BOOTPIN_CONFIG;           // 0x10 Boot Pin Configuration
    Uint32                                   Z2_GPREG2;                   // 0x14 Zone2 General Purpose Register-2
    Uint32                                   Z2_BOOTDEF_LOW;              // 0x18 Boot definition (low 32bit)
    Uint32                                   rsvd1;                       // 0x1c Reserved
    Uint32                                   Z2_CSMKEY0;                  // 0x20 Zone 2 CSM Key 0
    Uint32                                   Z2_CSMKEY1;                  // 0x24 Zone 2 CSM Key 1
    Uint32                                   Z2_CSMKEY2;                  // 0x28 Zone 2 CSM Key 2
    Uint32                                   Z2_CSMKEY3;                  // 0x2c Zone 2 CSM Key 3
    union   Z2_CR_REG                        Z2_CR;                       // 0x30 Zone 2 CSM Control Register
    union   B0_Z2_GRABSECTR_REG              B0_Z2_GRABSECTR;             // 0x34 Zone 2 Grab Flash BANK0 Sectors Register
    union   Z2_GRABRAMR_REG                  Z2_GRABRAMR;                 // 0x38 Zone 2 Grab RAM Blocks Register
    union   B0_Z2_EXEONLYSECTR_REG           B0_Z2_EXEONLYSECTR;          // 0x3c Zone 2 Flash BANK0 Execute_Only Sector Register
    union   Z2_EXEONLYRAMR_REG               Z2_EXEONLYRAMR;              // 0x40 Zone 2 RAM Execute_Only Block Register
};

struct FLSEM_BITS {                           // bits description
    Uint32 SEM:2;                             // 1:0 Flash Semaphore Bit
    Uint32 rsvd1:6;                           // 7:2 Reserved
    Uint32 KEY:8;                             // 15:8 Semaphore Key
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union FLSEM_REG {
    Uint32  all;
    struct  FLSEM_BITS  bit;
};

struct B0_SECTSTAT_BITS {                     // bits description
    Uint32 STATUS_SECT0:2;                    // 1:0 Zone Status Flash BANK0 Sector 0
    Uint32 STATUS_SECT1:2;                    // 3:2 Zone Status Flash BANK0 sector 1
    Uint32 STATUS_SECT2:2;                    // 5:4 Zone Status Flash BANK0 Sector 2
    Uint32 STATUS_SECT3:2;                    // 7:6 Zone Status Flash BANK0 Sector 3
    Uint32 STATUS_SECT4:2;                    // 9:8 Zone Status Flash BANK0 Sector 4
    Uint32 STATUS_SECT5:2;                    // 11:10 Zone Status Flash BANK0 Sector 5
    Uint32 STATUS_SECT6:2;                    // 13:12 Zone Status Flash BANK0 Sector 6
    Uint32 STATUS_SECT7:2;                    // 15:14 Zone Status Flash BANK0 Sector 7
    Uint32 STATUS_SECT8:2;                    // 17:16 Zone Status Flash BANK0 sector 8
    Uint32 STATUS_SECT9:2;                    // 19:18 Zone Status Flash BANK0 Sector 9
    Uint32 STATUS_SECT10:2;                   // 21:20 Zone Status Flash BANK0 Sector 10
    Uint32 STATUS_SECT11:2;                   // 23:22 Zone Status Flash BANK0 Sector 11
    Uint32 STATUS_SECT12:2;                   // 25:24 Zone Status Flash BANK0 Sector 12
    Uint32 STATUS_SECT13:2;                   // 27:26 Zone Status Flash BANK0 Sector 13
    Uint32 STATUS_SECT14:2;                   // 29:28 Zone Status Flash BANK0 Sector 14
    Uint32 STATUS_SECT15:2;                   // 31:30 Zone Status Flash BANK0 Sector 15
};

union B0_SECTSTAT_REG {
    Uint32  all;
    struct  B0_SECTSTAT_BITS  bit;
};

struct RAMSTAT_BITS {                         // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 rsvd2:2;                           // 3:2 Reserved
    Uint32 rsvd3:2;                           // 5:4 Reserved
    Uint32 rsvd4:2;                           // 7:6 Reserved
    Uint32 STATUS_RAM4:2;                     // 9:8 Zone Status RAM LS4
    Uint32 STATUS_RAM5:2;                     // 11:10 Zone Status RAM LS5
    Uint32 STATUS_RAM6:2;                     // 13:12 Zone Status RAM LS6
    Uint32 STATUS_RAM7:2;                     // 15:14 Zone Status RAM LS7
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union RAMSTAT_REG {
    Uint32  all;
    struct  RAMSTAT_BITS  bit;
};

struct SECERRSTAT_BITS {                      // bits description
    Uint32 ERR:1;                             // 0 Security Configuration load Error Status
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SECERRSTAT_REG {
    Uint32  all;
    struct  SECERRSTAT_BITS  bit;
};

struct SECERRCLR_BITS {                       // bits description
    Uint32 ERR:1;                             // 0 Clear Security Configuration Load Error Status Bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SECERRCLR_REG {
    Uint32  all;
    struct  SECERRCLR_BITS  bit;
};

struct SECERRFRC_BITS {                       // bits description
    Uint32 ERR:1;                             // 0 Set Security Configuration Load Error Status Bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SECERRFRC_REG {
    Uint32  all;
    struct  SECERRFRC_BITS  bit;
};

struct  DCSM_COMMON_REGS {
    union   FLSEM_REG                        FLSEM;                       // 0x0 Flash Wrapper Semaphore Register
    union   B0_SECTSTAT_REG                  B0_SECTSTAT;                 // 0x4 Flash BANK0 Sectors Status Register
    union   RAMSTAT_REG                      RAMSTAT;                     // 0x8 RAM Status Register
    Uint32                                   rsvd1[2];                    // 0xc Reserved
    union   SECERRSTAT_REG                   SECERRSTAT;                  // 0x14 Security Error Status Register
    union   SECERRCLR_REG                    SECERRCLR;                   // 0x18 Security Error Clear Register
    union   SECERRFRC_REG                    SECERRFRC;                   // 0x1c Security Error Force Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================