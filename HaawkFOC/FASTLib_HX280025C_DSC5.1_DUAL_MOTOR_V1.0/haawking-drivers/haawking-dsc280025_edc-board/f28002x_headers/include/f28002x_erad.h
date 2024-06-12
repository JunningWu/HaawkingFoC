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


#ifndef F28002X_ERAD_H
#define F28002X_ERAD_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ERAD Individual Register Bit Definitions:

struct GLBL_EVENT_STAT_BITS {                 // bits description
    Uint32 HWBP1:1;                           // 0 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP2:1;                           // 1 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP3:1;                           // 2 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP4:1;                           // 3 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP5:1;                           // 4 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP6:1;                           // 5 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP7:1;                           // 6 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 HWBP8:1;                           // 7 Enhanced Bus Comparator (EBC) Module Event Status
    Uint32 CTM1:1;                            // 8 Counter Module Event Status
    Uint32 CTM2:1;                            // 9 Counter Module Event Status
    Uint32 CTM3:1;                            // 10 Counter Module Event Status
    Uint32 CTM4:1;                            // 11 Counter Module Event Status
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union GLBL_EVENT_STAT_REG {
    Uint32  all;
    struct  GLBL_EVENT_STAT_BITS  bit;
};

struct GLBL_HALT_STAT_BITS {                  // bits description
    Uint32 HWBP1:1;                           // 0 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP2:1;                           // 1 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP3:1;                           // 2 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP4:1;                           // 3 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP5:1;                           // 4 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP6:1;                           // 5 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP7:1;                           // 6 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 HWBP8:1;                           // 7 Enhanced Bus Comparator (EBC) Module Halt Status
    Uint32 CTM1:1;                            // 8 Counter Module Halt Status
    Uint32 CTM2:1;                            // 9 Counter Module Halt Status
    Uint32 CTM3:1;                            // 10 Counter Module Halt Status
    Uint32 CTM4:1;                            // 11 Counter Module Halt Status
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union GLBL_HALT_STAT_REG {
    Uint32  all;
    struct  GLBL_HALT_STAT_BITS  bit;
};

struct GLBL_ENABLE_BITS {                     // bits description
    Uint32 HWBP1:1;                           // 0 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP2:1;                           // 1 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP3:1;                           // 2 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP4:1;                           // 3 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP5:1;                           // 4 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP6:1;                           // 5 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP7:1;                           // 6 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 HWBP8:1;                           // 7 Enhanced Bus Comparator (EBC) Module Global Enable
    Uint32 CTM1:1;                            // 8 Counter Module Global Enable
    Uint32 CTM2:1;                            // 9 Counter Module Global Enable
    Uint32 CTM3:1;                            // 10 Counter Module Global Enable
    Uint32 CTM4:1;                            // 11 Counter Module Global Enable
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union GLBL_ENABLE_REG {
    Uint32  all;
    struct  GLBL_ENABLE_BITS  bit;
};

struct GLBL_CTM_RESET_BITS {                  // bits description
    Uint32 CTM1:1;                            // 0 Global Reset for the counters
    Uint32 CTM2:1;                            // 1 Global Reset for the counters
    Uint32 CTM3:1;                            // 2 Global Reset for the counters
    Uint32 CTM4:1;                            // 3 Global Reset for the counters
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union GLBL_CTM_RESET_REG {
    Uint32  all;
    struct  GLBL_CTM_RESET_BITS  bit;
};

struct GLBL_NMI_CTL_BITS {                    // bits description
    Uint32 HWBP1:1;                           // 0 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP2:1;                           // 1 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP3:1;                           // 2 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP4:1;                           // 3 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP5:1;                           // 4 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP6:1;                           // 5 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP7:1;                           // 6 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 HWBP8:1;                           // 7 Enhanced Bus Comparator (EBC) non-maskable interrupt enable
    Uint32 CTM1:1;                            // 8 Counter non-maskable interrupt enable
    Uint32 CTM2:1;                            // 9 Counter non-maskable interrupt enable
    Uint32 CTM3:1;                            // 10 Counter non-maskable interrupt enable
    Uint32 CTM4:1;                            // 11 Counter non-maskable interrupt enable
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union GLBL_NMI_CTL_REG {
    Uint32  all;
    struct  GLBL_NMI_CTL_BITS  bit;
};

struct GLBL_OWNER_BITS {                      // bits description
    Uint32 OWNER:2;                           // 1:0 Global Ownership Bits
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union GLBL_OWNER_REG {
    Uint32  all;
    struct  GLBL_OWNER_BITS  bit;
};

struct GLBL_EVENT_AND_MASK_BITS {             // bits description
    Uint32 MASK1_HWBP1:1;                     // 0 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP2:1;                     // 1 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP3:1;                     // 2 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP4:1;                     // 3 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP5:1;                     // 4 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP6:1;                     // 5 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP7:1;                     // 6 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK1_HWBP8:1;                     // 7 Enhanced Bus Comparator (EBC) AND Event Mask1
    Uint32 MASK2_HWBP1:1;                     // 8 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP2:1;                     // 9 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP3:1;                     // 10 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP4:1;                     // 11 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP5:1;                     // 12 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP6:1;                     // 13 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP7:1;                     // 14 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK2_HWBP8:1;                     // 15 Enhanced Bus Comparator (EBC) AND Event Mask2
    Uint32 MASK3_HWBP1:1;                     // 16 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP2:1;                     // 17 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP3:1;                     // 18 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP4:1;                     // 19 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP5:1;                     // 20 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP6:1;                     // 21 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP7:1;                     // 22 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK3_HWBP8:1;                     // 23 Enhanced Bus Comparator (EBC) AND Event Mask3
    Uint32 MASK4_HWBP1:1;                     // 24 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP2:1;                     // 25 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP3:1;                     // 26 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP4:1;                     // 27 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP5:1;                     // 28 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP6:1;                     // 29 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP7:1;                     // 30 Enhanced Bus Comparator (EBC) AND Event Mask4
    Uint32 MASK4_HWBP8:1;                     // 31 Enhanced Bus Comparator (EBC) AND Event Mask4
};

union GLBL_EVENT_AND_MASK_REG {
    Uint32  all;
    struct  GLBL_EVENT_AND_MASK_BITS  bit;
};

struct GLBL_EVENT_OR_MASK_BITS {              // bits description
    Uint32 MASK1_HWBP1:1;                     // 0 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP2:1;                     // 1 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP3:1;                     // 2 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP4:1;                     // 3 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP5:1;                     // 4 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP6:1;                     // 5 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP7:1;                     // 6 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK1_HWBP8:1;                     // 7 Enhanced Bus Comparator (EBC) OR Event Mask1
    Uint32 MASK2_HWBP1:1;                     // 8 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP2:1;                     // 9 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP3:1;                     // 10 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP4:1;                     // 11 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP5:1;                     // 12 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP6:1;                     // 13 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP7:1;                     // 14 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK2_HWBP8:1;                     // 15 Enhanced Bus Comparator (EBC) OR Event Mask2
    Uint32 MASK3_HWBP1:1;                     // 16 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP2:1;                     // 17 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP3:1;                     // 18 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP4:1;                     // 19 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP5:1;                     // 20 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP6:1;                     // 21 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP7:1;                     // 22 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK3_HWBP8:1;                     // 23 Enhanced Bus Comparator (EBC) OR Event Mask3
    Uint32 MASK4_HWBP1:1;                     // 24 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP2:1;                     // 25 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP3:1;                     // 26 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP4:1;                     // 27 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP5:1;                     // 28 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP6:1;                     // 29 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP7:1;                     // 30 Enhanced Bus Comparator (EBC) OR Event Mask4
    Uint32 MASK4_HWBP8:1;                     // 31 Enhanced Bus Comparator (EBC) OR Event Mask4
};

union GLBL_EVENT_OR_MASK_REG {
    Uint32  all;
    struct  GLBL_EVENT_OR_MASK_BITS  bit;
};

struct GLBL_AND_EVENT_INT_MASK_BITS {         // bits description
    Uint32 RTOSINT_MASK1:1;                   // 0 RTOSINT generation mask for global AND events
    Uint32 RTOSINT_MASK2:1;                   // 1 RTOSINT generation mask for global AND events
    Uint32 RTOSINT_MASK3:1;                   // 2 RTOSINT generation mask for global AND events
    Uint32 RTOSINT_MASK4:1;                   // 3 RTOSINT generation mask for global AND events
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union GLBL_AND_EVENT_INT_MASK_REG {
    Uint32  all;
    struct  GLBL_AND_EVENT_INT_MASK_BITS  bit;
};

struct GLBL_OR_EVENT_INT_MASK_BITS {          // bits description
    Uint32 RTOSINT_MASK1:1;                   // 0 RTOSINT generation mask for global OR events
    Uint32 RTOSINT_MASK2:1;                   // 1 RTOSINT generation mask for global OR events
    Uint32 RTOSINT_MASK3:1;                   // 2 RTOSINT generation mask for global OR events
    Uint32 RTOSINT_MASK4:1;                   // 3 RTOSINT generation mask for global OR events
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union GLBL_OR_EVENT_INT_MASK_REG {
    Uint32  all;
    struct  GLBL_OR_EVENT_INT_MASK_BITS  bit;
};

struct GLBL_HWBP_CMP_CTRL_BITS {              // bits description
    Uint32 MONI_LSU_IFUN_1:1;                 // 0 HWBP1 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_1:1;              // 1 HWBP1 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_2:1;                 // 2 HWBP2 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_2:1;              // 3 HWBP2 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_3:1;                 // 4 HWBP3 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_3:1;              // 5 HWBP3 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_4:1;                 // 6 HWBP4 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_4:1;              // 7 HWBP4 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_5:1;                 // 8 HWBP5 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_5:1;              // 9 HWBP5 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_6:1;                 // 10 HWBP6 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_6:1;              // 11 HWBP6 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_7:1;                 // 12 HWBP7 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_7:1;              // 13 HWBP7 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 MONI_LSU_IFUN_8:1;                 // 14 HWBP8 monitors target bit ifu or lsu bus
    Uint32 MONI_DATA_HI_LON_8:1;              // 15 HWBP8 represents the upper or lower 32 bits of the monitoring target bus
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union GLBL_HWBP_CMP_CTRL_REG {
    Uint32  all;
    struct  GLBL_HWBP_CMP_CTRL_BITS  bit;
};

struct  ERAD_GLOBAL_REGS {
    union   GLBL_EVENT_STAT_REG              GLBL_EVENT_STAT;             // 0x0 Global Event Status Register
    union   GLBL_HALT_STAT_REG               GLBL_HALT_STAT;              // 0x4 Global Halt Status Register
    union   GLBL_ENABLE_REG                  GLBL_ENABLE;                 // 0x8 Global Enable Register
    union   GLBL_CTM_RESET_REG               GLBL_CTM_RESET;              // 0xc Global Counter Reset
    union   GLBL_NMI_CTL_REG                 GLBL_NMI_CTL;                // 0x10 Global Debug NMI control
    union   GLBL_OWNER_REG                   GLBL_OWNER;                  // 0x14 Global Ownership
    union   GLBL_EVENT_AND_MASK_REG          GLBL_EVENT_AND_MASK;         // 0x18 Global Bus Comparator Event AND Mask Register
    union   GLBL_EVENT_OR_MASK_REG           GLBL_EVENT_OR_MASK;          // 0x1c Global Bus Comparator Event OR Mask Register
    union   GLBL_AND_EVENT_INT_MASK_REG      GLBL_AND_EVENT_INT_MASK;     // 0x20 Global AND Event Interrupt Mask Register
    union   GLBL_OR_EVENT_INT_MASK_REG       GLBL_OR_EVENT_INT_MASK;      // 0x24 Global OR Event Interrupt Mask Register
    union   GLBL_HWBP_CMP_CTRL_REG           GLBL_HWBP_CMP_CTRL;          // 0x28 Global OR Event Interrupt Mask Register
};

struct HWBP_CLEAR_BITS {                      // bits description
    Uint32 EVENT_CLR:1;                       // 0 Event Clear register
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union HWBP_CLEAR_REG {
    Uint32  all;
    struct  HWBP_CLEAR_BITS  bit;
};

struct HWBP_CNTL_BITS {                       // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 BUS_SEL:4;                         // 4:1 Bus select bits
    Uint32 STOP:1;                            // 5 Stop bit (Halt/No Halt of CPU)
    Uint32 RTOSINT:1;                         // 6 RTOSINT bit
    Uint32 COMP_MODE:3;                       // 9:7 Compare mode
    Uint32 rsvd2:1;                           // 10 Reserved
    Uint32 rsvd3:1;                           // 11 Reserved
    Uint32 rsvd4:20;                          // 31:12 Reserved
};

union HWBP_CNTL_REG {
    Uint32  all;
    struct  HWBP_CNTL_BITS  bit;
};

struct HWBP_STATUS_BITS {                     // bits description
    Uint32 EVENT_FIRED:1;                     // 0 HWBP (EBC) Event Fired bits
    Uint32 rsvd1:7;                           // 7:1 Reserved
    Uint32 MODULE_ID:6;                       // 13:8 Identification bits
    Uint32 STATUS:2;                          // 15:14 Status bits
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HWBP_STATUS_REG {
    Uint32  all;
    struct  HWBP_STATUS_BITS  bit;
};

struct  ERAD_HWBP_REGS {
    Uint32                                   HWBP_MASK;                   // 0x0 HWBP (EBC) Mask Register
    Uint32                                   HWBP_REF;                    // 0x4 HWBP (EBC) Reference Register
    union   HWBP_CLEAR_REG                   HWBP_CLEAR;                  // 0x8 HWBP (EBC) Clear Register
    union   HWBP_CNTL_REG                    HWBP_CNTL;                   // 0xc HWBP (EBC) Control Register
    union   HWBP_STATUS_REG                  HWBP_STATUS;                 // 0x10 HWBP (EBC) Status Register
};

struct CTM_CNTL_BITS {                        // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 START_STOP_MODE:1;                 // 2 Start_stop mode bit
    Uint32 EVENT_MODE:1;                      // 3 Event mode bit
    Uint32 RST_ON_MATCH:1;                    // 4 Reset_on_match bit
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 STOP:1;                            // 6 Stop bit (Halt/No Halt of CPU)
    Uint32 RTOSINT:1;                         // 7 RTOSINT bit
    Uint32 START_STOP_CUMULATIVE:1;           // 8 Start stop cumulative bit
    Uint32 rsvd3:1;                           // 9 Reserved
    Uint32 RST_EN:1;                          // 10 Enable Reset
    Uint32 CNT_INP_SEL_EN:1;                  // 11 Counter Input Select Enable
    Uint32 rsvd4:20;                          // 31:12 Reserved
};

union CTM_CNTL_REG {
    Uint32  all;
    struct  CTM_CNTL_BITS  bit;
};

struct CTM_STATUS_BITS {                      // bits description
    Uint32 EVENT_FIRED:1;                     // 0 Counter Event Fired bits
    Uint32 OVERFLOW:1;                        // 1 Counter Overflowed
    Uint32 MODULE_ID:10;                      // 11:2 Identification bits
    Uint32 STATUS:4;                          // 15:12 Status bits
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CTM_STATUS_REG {
    Uint32  all;
    struct  CTM_STATUS_BITS  bit;
};

struct CTM_INPUT_SEL_BITS {                   // bits description
    Uint32 CNT_INP_SEL:7;                     // 6:0 Counter Input Select
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 STA_INP_SEL:7;                     // 14:8 Counter Sart Input Select
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union CTM_INPUT_SEL_REG {
    Uint32  all;
    struct  CTM_INPUT_SEL_BITS  bit;
};

struct CTM_CLEAR_BITS {                       // bits description
    Uint32 EVENT_CLEAR:1;                     // 0 Clear EVENT_FIRED
    Uint32 OVERFLOW_CLEAR:1;                  // 1 Clear OVERFLOW
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union CTM_CLEAR_REG {
    Uint32  all;
    struct  CTM_CLEAR_BITS  bit;
};

struct CTM_INPUT_SEL_2_BITS {                 // bits description
    Uint32 STO_INP_SEL:7;                     // 6:0 Counter Stop Input Select
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 RST_INP_SEL:7;                     // 14:8 Counter Reset input Select
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union CTM_INPUT_SEL_2_REG {
    Uint32  all;
    struct  CTM_INPUT_SEL_2_BITS  bit;
};

struct CTM_INPUT_COND_BITS {                  // bits description
    Uint32 CTM_INP_INV:1;                     // 0 Counter Input Invert
    Uint32 CTM_INP_SYNCH:1;                   // 1 Counter input synchronizer enable
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 STA_INP_INV:1;                     // 4 Start input Invert
    Uint32 STA_INP_SYNCH:1;                   // 5 Start input synchronizer enable
    Uint32 rsvd2:2;                           // 7:6 Reserved
    Uint32 STO_INP_INV:1;                     // 8 Stop input Invert
    Uint32 STO_INP_SYNCH:1;                   // 9 Stop input synchronizer enable
    Uint32 rsvd3:2;                           // 11:10 Reserved
    Uint32 RST_INP_INV:1;                     // 12 Reset input Invert
    Uint32 RST_INP_SYNCH:1;                   // 13 Reset input synchronizer enable
    Uint32 rsvd4:18;                          // 31:14 Reserved
};

union CTM_INPUT_COND_REG {
    Uint32  all;
    struct  CTM_INPUT_COND_BITS  bit;
};

struct  ERAD_COUNTER_REGS {
    union   CTM_CNTL_REG                     CTM_CNTL;                    // 0x0 Counter Control Register
    union   CTM_STATUS_REG                   CTM_STATUS;                  // 0x4 Counter Status Register
    Uint32                                   CTM_REF;                     // 0x8 Counter Reference Register
    Uint32                                   CTM_COUNT;                   // 0xc Counter Current Value Register
    Uint32                                   CTM_MAX_COUNT;               // 0x10 Counter Max Count Value Register
    union   CTM_INPUT_SEL_REG                CTM_INPUT_SEL;               // 0x14 Counter Input Select Register
    union   CTM_CLEAR_REG                    CTM_CLEAR;                   // 0x18 Counter Clear Register
    union   CTM_INPUT_SEL_2_REG              CTM_INPUT_SEL_2;             // 0x1c Counter Input Select Extension Register
    union   CTM_INPUT_COND_REG               CTM_INPUT_COND;              // 0x20 Counter Input Conditioning Register
};

struct CRC_GLOBAL_CTRL_BITS {                 // bits description
    Uint32 CRC1_INIT:1;                       // 0 Initialize CRC Module 1
    Uint32 CRC2_INIT:1;                       // 1 Initialize CRC Module 2
    Uint32 CRC3_INIT:1;                       // 2 Initialize CRC Module 3
    Uint32 CRC4_INIT:1;                       // 3 Initialize CRC Module 4
    Uint32 CRC5_INIT:1;                       // 4 Initialize CRC Module 5
    Uint32 CRC6_INIT:1;                       // 5 Initialize CRC Module 6
    Uint32 CRC7_INIT:1;                       // 6 Initialize CRC Module 7
    Uint32 CRC8_INIT:1;                       // 7 Initialize CRC Module 8
    Uint32 CRC1_EN:1;                         // 8 Enable CRC Module 1
    Uint32 CRC2_EN:1;                         // 9 Enable CRC Module 2
    Uint32 CRC3_EN:1;                         // 10 Enable CRC Module 3
    Uint32 CRC4_EN:1;                         // 11 Enable CRC Module 4
    Uint32 CRC5_EN:1;                         // 12 Enable CRC Module 5
    Uint32 CRC6_EN:1;                         // 13 Enable CRC Module 6
    Uint32 CRC7_EN:1;                         // 14 Enable CRC Module 7
    Uint32 CRC8_EN:1;                         // 15 Enable CRC Module 8
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CRC_GLOBAL_CTRL_REG {
    Uint32  all;
    struct  CRC_GLOBAL_CTRL_BITS  bit;
};

struct  ERAD_CRC_GLOBAL_REGS {
    union   CRC_GLOBAL_CTRL_REG              CRC_GLOBAL_CTRL;             // 0x0 CRC_GLOBAL_CRTL
};

struct CRC_QUALIFIER_BITS {                   // bits description
    Uint32 CRC_QUALIFIER:5;                   // 4:0 CRC Qualifier Register
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union CRC_QUALIFIER_REG {
    Uint32  all;
    struct  CRC_QUALIFIER_BITS  bit;
};

struct  ERAD_CRC_REGS {
    Uint32                                   CRC_CURRENT;                 // 0x0 CRC_CURRENT
    Uint32                                   CRC_SEED;                    // 0x4 CRC SEED value
    union   CRC_QUALIFIER_REG                CRC_QUALIFIER;               // 0x8 CRC_QUALIFIER
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================