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
// Release for HXS320F280025CEDC, Bitfield DriverLib, 1.0.1
//
// Release time: 2024-02-19 16:25:19.512017
//
//#############################################################################


#ifndef F28002X_CMPSS_H
#define F28002X_CMPSS_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CMPSS Individual Register Bit Definitions:

struct COMPCTL_BITS {                         // bits description
    Uint32 COMPHSOURCE:1;                     // 0 High Comparator Source Select
    Uint32 COMPHINV:1;                        // 1 High Comparator Invert Select
    Uint32 CTRIPHSEL:2;                       // 3:2 High Comparator Trip Select
    Uint32 CTRIPOUTHSEL:2;                    // 5:4 High Comparator Trip Output Select
    Uint32 ASYNCHEN:1;                        // 6 High Comparator Asynchronous Path Enable
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 COMPLSOURCE:1;                     // 8 Low Comparator Source Select
    Uint32 COMPLINV:1;                        // 9 Low Comparator Invert Select
    Uint32 CTRIPLSEL:2;                       // 11:10 Low Comparator Trip Select
    Uint32 CTRIPOUTLSEL:2;                    // 13:12 Low Comparator Trip Output Select
    Uint32 ASYNCLEN:1;                        // 14 Low Comparator Asynchronous Path Enable
    Uint32 COMPDACE:1;                        // 15 Comparator/DAC Enable
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union COMPCTL_REG {
    Uint32  all;
    struct  COMPCTL_BITS  bit;
};

struct COMPHYSCTL_BITS {                      // bits description
    Uint32 COMPHYS:3;                         // 2:0 Comparator Hysteresis Trim
    Uint32 CMPSS_ENABLE:1;                    // 3 CMPSS ENABLE bit
    Uint32 DACBUFEN:1;                        // 4 CMPSS BUF ENABLE bit
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union COMPHYSCTL_REG {
    Uint32  all;
    struct  COMPHYSCTL_BITS  bit;
};

struct COMPSTS_BITS {                         // bits description
    Uint32 COMPHSTS:1;                        // 0 High Comparator Status
    Uint32 COMPHLATCH:1;                      // 1 High Comparator Latched Status
    Uint32 rsvd1:6;                           // 7:2 Reserved
    Uint32 COMPLSTS:1;                        // 8 Low Comparator Status
    Uint32 COMPLLATCH:1;                      // 9 Low Comparator Latched Status
    Uint32 rsvd2:22;                          // 31:10 Reserved
};

union COMPSTS_REG {
    Uint32  all;
    struct  COMPSTS_BITS  bit;
};

struct COMPSTSCLR_BITS {                      // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 HLATCHCLR:1;                       // 1 High Comparator Latched Status Clear
    Uint32 HSYNCCLREN:1;                      // 2 High Comparator EPWMSYNCPER Clear Enable
    Uint32 rsvd2:6;                           // 8:3 Reserved
    Uint32 LLATCHCLR:1;                       // 9 Low Comparator Latched Status Clear
    Uint32 LSYNCCLREN:1;                      // 10 Low Comparator EPWMSYNCPER Clear Enable
    Uint32 rsvd3:21;                          // 31:11 Reserved
};

union COMPSTSCLR_REG {
    Uint32  all;
    struct  COMPSTSCLR_BITS  bit;
};

struct COMPDACCTL_BITS {                      // bits description
    Uint32 DACSOURCE:1;                       // 0 DAC Source Control
    Uint32 RAMPSOURCE:4;                      // 4:1 Ramp Generator Source Control
    Uint32 SELREF:1;                          // 5 DAC Reference Select
    Uint32 RAMPLOADSEL:1;                     // 6 Ramp Load Select
    Uint32 SWLOADSEL:1;                       // 7 Software Load Select
    Uint32 BLANKSOURCE:4;                     // 11:8 EPWMBLANK Source Select
    Uint32 BLANKEN:1;                         // 12 EPWMBLANK Enable
    Uint32 rsvd1:1;                           // 13 Reserved
    Uint32 FREESOFT:2;                        // 15:14 Free/Soft Emulation Bits
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union COMPDACCTL_REG {
    Uint32  all;
    struct  COMPDACCTL_BITS  bit;
};

struct DACHVALS_BITS {                        // bits description
    Uint32 DACVAL:12;                         // 11:0 DAC Value Control
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union DACHVALS_REG {
    Uint32  all;
    struct  DACHVALS_BITS  bit;
};

struct DACHVALA_BITS {                        // bits description
    Uint32 DACVAL:12;                         // 11:0 DAC Value Control
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union DACHVALA_REG {
    Uint32  all;
    struct  DACHVALA_BITS  bit;
};

struct DACLVALS_BITS {                        // bits description
    Uint32 DACVAL:12;                         // 11:0 DAC Value Control
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union DACLVALS_REG {
    Uint32  all;
    struct  DACLVALS_BITS  bit;
};

struct DACLVALA_BITS {                        // bits description
    Uint32 DACVAL:12;                         // 11:0 DAC Value Control
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union DACLVALA_REG {
    Uint32  all;
    struct  DACLVALA_BITS  bit;
};

struct RAMPDLYA_BITS {                        // bits description
    Uint32 DELAY:13;                          // 12:0 Ramp Delay Value
    Uint32 rsvd1:19;                          // 31:13 Reserved
};

union RAMPDLYA_REG {
    Uint32  all;
    struct  RAMPDLYA_BITS  bit;
};

struct RAMPDLYS_BITS {                        // bits description
    Uint32 DELAY:13;                          // 12:0 Ramp Delay Value
    Uint32 rsvd1:19;                          // 31:13 Reserved
};

union RAMPDLYS_REG {
    Uint32  all;
    struct  RAMPDLYS_BITS  bit;
};

struct CTRIPLFILCTL_BITS {                    // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 SAMPWIN:5;                         // 8:4 Sample Window
    Uint32 THRESH:5;                          // 13:9 Majority Voting Threshold
    Uint32 rsvd2:1;                           // 14 Reserved
    Uint32 FILINIT:1;                         // 15 Filter Initialization Bit
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CTRIPLFILCTL_REG {
    Uint32  all;
    struct  CTRIPLFILCTL_BITS  bit;
};

struct CTRIPLFILCLKCTL_BITS {                 // bits description
    Uint32 CLKPRESCALE:10;                    // 9:0 Sample Clock Prescale
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union CTRIPLFILCLKCTL_REG {
    Uint32  all;
    struct  CTRIPLFILCLKCTL_BITS  bit;
};

struct CTRIPHFILCTL_BITS {                    // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 SAMPWIN:5;                         // 8:4 Sample Window
    Uint32 THRESH:5;                          // 13:9 Majority Voting Threshold
    Uint32 rsvd2:1;                           // 14 Reserved
    Uint32 FILINIT:1;                         // 15 Filter Initialization Bit
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CTRIPHFILCTL_REG {
    Uint32  all;
    struct  CTRIPHFILCTL_BITS  bit;
};

struct CTRIPHFILCLKCTL_BITS {                 // bits description
    Uint32 CLKPRESCALE:10;                    // 9:0 Sample Clock Prescale
    Uint32 rsvd1:6;                           // 15:10 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CTRIPHFILCLKCTL_REG {
    Uint32  all;
    struct  CTRIPHFILCLKCTL_BITS  bit;
};

struct COMPLOCK_BITS {                        // bits description
    Uint32 COMPCTL:1;                         // 0 COMPCTL Lock
    Uint32 COMPHYSCTL:1;                      // 1 COMPHYSCTL Lock
    Uint32 DACCTL:1;                          // 2 DACCTL Lock
    Uint32 CTRIP:1;                           // 3 CTRIP Lock
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:11;                          // 15:5 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union COMPLOCK_REG {
    Uint32  all;
    struct  COMPLOCK_BITS  bit;
};

struct COMPCLKDIV_BITS {                      // bits description
    Uint32 COMPDIV:8;                         // 7:0 Comparator Frequency Division Coefficient
    Uint32 rsvd1:16;                          // 23:8 Reserved
};

union COMPCLKDIV_REG {
    Uint32  all;
    struct  COMPCLKDIV_BITS  bit;
};

struct  CMPSS_REGS {
    union   COMPCTL_REG                      COMPCTL;                     // 0x0 CMPSS Comparator Control Register
    union   COMPHYSCTL_REG                   COMPHYSCTL;                  // 0x4 CMPSS Comparator Hysteresis Control Register
    union   COMPSTS_REG                      COMPSTS;                     // 0x8 CMPSS Comparator Status Register
    union   COMPSTSCLR_REG                   COMPSTSCLR;                  // 0xc CMPSS Comparator Status Clear Register
    union   COMPDACCTL_REG                   COMPDACCTL;                  // 0x10 CMPSS DAC Control Register
    union   DACHVALS_REG                     DACHVALS;                    // 0x14 CMPSS High DAC Value Shadow Register
    union   DACHVALA_REG                     DACHVALA;                    // 0x18 CMPSS High DAC Value Active Register
    Uint32                                   RAMPMAXREFA;                 // 0x1c CMPSS Ramp Max Reference Active Register
    Uint32                                   RAMPMAXREFS;                 // 0x20 CMPSS Ramp Max Reference Shadow Register
    Uint32                                   RAMPDECVALA;                 // 0x24 CMPSS Ramp Decrement Value Active Register
    Uint32                                   RAMPDECVALS;                 // 0x28 CMPSS Ramp Decrement Value Shadow Register
    Uint32                                   RAMPSTS;                     // 0x2c CMPSS Ramp Status Register
    union   DACLVALS_REG                     DACLVALS;                    // 0x30 CMPSS Low DAC Value Shadow Register
    union   DACLVALA_REG                     DACLVALA;                    // 0x34 CMPSS Low DAC Value Active Register
    union   RAMPDLYA_REG                     RAMPDLYA;                    // 0x38 CMPSS Ramp Delay Active Register
    union   RAMPDLYS_REG                     RAMPDLYS;                    // 0x3c CMPSS Ramp Delay Shadow Register
    union   CTRIPLFILCTL_REG                 CTRIPLFILCTL;                // 0x40 CTRIPL Filter Control Register
    union   CTRIPLFILCLKCTL_REG              CTRIPLFILCLKCTL;             // 0x44 CTRIPL Filter Clock Control Register
    union   CTRIPHFILCTL_REG                 CTRIPHFILCTL;                // 0x48 CTRIPH Filter Control Register
    union   CTRIPHFILCLKCTL_REG              CTRIPHFILCLKCTL;             // 0x4c CTRIPH Filter Clock Control Register
    union   COMPLOCK_REG                     COMPLOCK;                    // 0x50 CMPSS Lock Register
    union   COMPCLKDIV_REG                   COMPCLKDIV;                  // 0x54 CMPSS Clock Division Controller Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================