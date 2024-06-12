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


#ifndef F28002X_DMA_H
#define F28002X_DMA_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DMA Individual Register Bit Definitions:

struct MODE_BITS {                            // bits description
    Uint32 PERINTSEL:5;                       // 4:0 Peripheral Interrupt and Sync Select
    Uint32 rsvd1:2;                           // 6:5 Reserved
    Uint32 OVRINTE:1;                         // 7 Overflow Interrupt Enable
    Uint32 PERINTE:1;                         // 8 Peripheral Interrupt Enable
    Uint32 CHINTMODE:1;                       // 9 Channel Interrupt Mode
    Uint32 ONESHOT:1;                         // 10 One Shot Mode Bit
    Uint32 CONTINUOUS:1;                      // 11 Continuous Mode Bit
    Uint32 rsvd2:1;                           // 12 Reserved
    Uint32 rsvd3:1;                           // 13 Reserved
    Uint32 DATASIZE:1;                        // 14 Data Size Mode Bit
    Uint32 CHINTE:1;                          // 15 Channel Interrupt Enable Bit
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union MODE_REG {
    Uint32  all;
    struct  MODE_BITS  bit;
};

struct CONTROL_BITS {                         // bits description
    Uint32 RUN:1;                             // 0 Run Bit
    Uint32 HALT:1;                            // 1 Halt Bit
    Uint32 SOFTRESET:1;                       // 2 Soft Reset Bit
    Uint32 PERINTFRC:1;                       // 3 Interrupt Force Bit
    Uint32 PERINTCLR:1;                       // 4 Interrupt Clear Bit
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 rsvd2:1;                           // 6 Reserved
    Uint32 ERRCLR:1;                          // 7 Error Clear Bit
    Uint32 PERINTFLG:1;                       // 8 Interrupt Flag Bit
    Uint32 rsvd3:1;                           // 9 Reserved
    Uint32 rsvd4:1;                           // 10 Reserved
    Uint32 TRANSFERSTS:1;                     // 11 Transfer Status Bit
    Uint32 BURSTSTS:1;                        // 12 Burst Status Bit
    Uint32 RUNSTS:1;                          // 13 Run Status Bit
    Uint32 OVRFLG:1;                          // 14 Overflow Flag Bit
    Uint32 rsvd5:17;                          // 31:15 Reserved
};

union CONTROL_REG {
    Uint32  all;
    struct  CONTROL_BITS  bit;
};

struct BURST_SIZE_BITS {                      // bits description
    Uint32 BURSTSIZE:5;                       // 4:0 Burst Transfer Size
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union BURST_SIZE_REG {
    Uint32  all;
    struct  BURST_SIZE_BITS  bit;
};

struct BURST_COUNT_BITS {                     // bits description
    Uint32 BURSTCOUNT:5;                      // 4:0 Burst Transfer Size
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union BURST_COUNT_REG {
    Uint32  all;
    struct  BURST_COUNT_BITS  bit;
};

struct  CH_REGS {
    union   MODE_REG                         MODE;                        // 0x0 Mode Register
    union   CONTROL_REG                      CONTROL;                     // 0x4 Control Register
    union   BURST_SIZE_REG                   BURST_SIZE;                  // 0x8 Burst Size Register
    union   BURST_COUNT_REG                  BURST_COUNT;                 // 0xc Burst Count Register
    Uint32                                   SRC_BURST_STEP;              // 0x10 Source Burst Step Register
    Uint32                                   DST_BURST_STEP;              // 0x14 Destination Burst Step Register
    Uint32                                   TRANSFER_SIZE;               // 0x18 Transfer Size Register
    Uint32                                   TRANSFER_COUNT;              // 0x1c Transfer Count Register
    Uint32                                   SRC_TRANSFER_STEP;           // 0x20 Source Transfer Step Register
    Uint32                                   DST_TRANSFER_STEP;           // 0x24 Destination Transfer Step Register
    Uint32                                   SRC_WRAP_SIZE;               // 0x28 Source Wrap Size Register
    Uint32                                   SRC_WRAP_COUNT;              // 0x2c Source Wrap Count Register
    Uint32                                   SRC_WRAP_STEP;               // 0x30 Source Wrap Step Register
    Uint32                                   DST_WRAP_SIZE;               // 0x34 Destination Wrap Size Register
    Uint32                                   DST_WRAP_COUNT;              // 0x38 Destination Wrap Count Register
    Uint32                                   DST_WRAP_STEP;               // 0x3c Destination Wrap Step Register
    Uint32                                   SRC_BEG_ADDR_SHADOW;         // 0x40 Source Begin Address Shadow Register
    Uint32                                   SRC_ADDR_SHADOW;             // 0x44 Source Address Shadow Register
    Uint32                                   SRC_BEG_ADDR_ACTIVE;         // 0x48 Source Begin Address Active Register
    Uint32                                   SRC_ADDR_ACTIVE;             // 0x4c Source Address Active Register
    Uint32                                   DST_BEG_ADDR_SHADOW;         // 0x50 Destination Begin Address Shadow Register
    Uint32                                   DST_ADDR_SHADOW;             // 0x54 Destination Address Shadow Register
    Uint32                                   DST_BEG_ADDR_ACTIVE;         // 0x58 Destination Begin Address Active Register
    Uint32                                   DST_ADDR_ACTIVE;             // 0x5c Destination Address Active Register
	Uint32                                   rsvd1[8];
};

struct DMACTRL_BITS {                         // bits description
    Uint32 HARDRESET:1;                       // 0 Hard Reset Bit
    Uint32 PRIORITYRESET:1;                   // 1 Priority Reset Bit
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union DMACTRL_REG {
    Uint32  all;
    struct  DMACTRL_BITS  bit;
};

struct DEBUGCTRL_BITS {                       // bits description
    Uint32 rsvd1:15;                          // 14:0 Reserved
    Uint32 FREE:1;                            // 15 Debug Mode Bit
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DEBUGCTRL_REG {
    Uint32  all;
    struct  DEBUGCTRL_BITS  bit;
};

struct PRIORITYCTRL1_BITS {                   // bits description
    Uint32 CH1PRIORITY:1;                     // 0 Ch1 Priority Bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union PRIORITYCTRL1_REG {
    Uint32  all;
    struct  PRIORITYCTRL1_BITS  bit;
};

struct PRIORITYSTAT_BITS {                    // bits description
    Uint32 ACTIVESTS:3;                       // 2:0 Active Channel Status Bits
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 ACTIVESTS_SHADOW:3;                // 6:4 Active Channel Status Shadow Bits
    Uint32 rsvd2:25;                          // 31:7 Reserved
};

union PRIORITYSTAT_REG {
    Uint32  all;
    struct  PRIORITYSTAT_BITS  bit;
};

struct  DMA_REGS {
    union   DMACTRL_REG                      DMACTRL;                     // 0x0 DMA Control Register
    union   DEBUGCTRL_REG                    DEBUGCTRL;                   // 0x4 Debug Control Register
    Uint32                                   REVSION;                     // 0x8 Revsion Register
    union   PRIORITYCTRL1_REG                PRIORITYCTRL1;               // 0xc Priority Control 1 Register
    union   PRIORITYSTAT_REG                 PRIORITYSTAT;                // 0x10 Priority Status Register
    Uint32                                   rsvd1[27];                   // 0x14 Reserved
    struct CH_REGS                           CH1;                         // 0x80 DMA Channel 1 Registers
    struct CH_REGS                           CH2;                         // 0x100 DMA Channel 2 Registers
    struct CH_REGS                           CH3;                         // 0x180 DMA Channel 3 Registers
    struct CH_REGS                           CH4;                         // 0x200 DMA Channel 4 Registers
    struct CH_REGS                           CH5;                         // 0x280 DMA Channel 5 Registers
    struct CH_REGS                           CH6;                         // 0x300 DMA Channel 6 Registers
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================