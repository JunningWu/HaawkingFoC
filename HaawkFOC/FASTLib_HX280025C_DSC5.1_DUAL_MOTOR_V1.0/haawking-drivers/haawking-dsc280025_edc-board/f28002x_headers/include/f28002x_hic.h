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


#ifndef F28002X_HIC_H
#define F28002X_HIC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// HIC Individual Register Bit Definitions:

struct HICREV_BITS {                          // bits description
    Uint32 MINOR:6;                           // 5:0 Minor Revision Number
    Uint32 CUSTOM:2;                          // 7:6 Custom Module Number
    Uint32 MAJOR:3;                           // 10:8 Major Revision Number
    Uint32 RTL:5;                             // 15:11 Design Release Number
    Uint32 FUNC:12;                           // 27:16 Functional Release Number
    Uint32 rsvd1:2;                           // 29:28 Reserved
    Uint32 SCHEME:2;                          // 31:30 Defines Scheme for Module
};

union HICREV_REG {
    Uint32  all;
    struct  HICREV_BITS  bit;
};

struct HICGCR_BITS {                          // bits description
    Uint32 HICEN:4;                           // 3:0 Host Interface Enable
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICGCR_REG {
    Uint32  all;
    struct  HICGCR_BITS  bit;
};

struct HICLOCK_BITS {                         // bits description
    Uint32 LOCK:1;                            // 0 LOCK enable
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 WRITE_ENABLE_KEY:16;               // 31:16 Key for enabling write
};

union HICLOCK_REG {
    Uint32  all;
    struct  HICLOCK_BITS  bit;
};

struct HICMODECR_BITS {                       // bits description
    Uint32 DW_MODE:2;                         // 1:0 Data Width Mode
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 RW_MODE:1;                         // 4 Read-Write Mode
    Uint32 BEN_PRESENT:1;                     // 5 Byte Enable Pins are present
    Uint32 RDY_PRESENT:1;                     // 6 Ready pin present
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 H2DBUF_DEVWREN:1;                  // 8 Write Enable for Device to H2D Buffer
    Uint32 D2HBUF_HOSTWREN:1;                 // 9 Write Enable for Host to D2H Buffer
    Uint32 EN_DEVACC:1;                       // 10 Enable Host access to Device region
    Uint32 EN_HOSTWREALLOW:1;                 // 11 Enable Host Write to EALLOWCTL register
    Uint32 rsvd3:4;                           // 15:12 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union HICMODECR_REG {
    Uint32  all;
    struct  HICMODECR_BITS  bit;
};

struct HICPINPOLCR_BITS {                     // bits description
    Uint32 CS_POL:1;                          // 0 Chip Select Polarity
    Uint32 BEN_POL:1;                         // 1 Byte Enable Polarity
    Uint32 OE_POL:1;                          // 2 Output Enable Polarity
    Uint32 WE_POL:1;                          // 3 Write Enable Polarity
    Uint32 RDY_POL:1;                         // 4 Ready Polarity
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICPINPOLCR_REG {
    Uint32  all;
    struct  HICPINPOLCR_BITS  bit;
};

struct HICBASESEL_BITS {                      // bits description
    Uint32 BASE_SELECT:3;                     // 2:0 Base Select
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICBASESEL_REG {
    Uint32  all;
    struct  HICBASESEL_BITS  bit;
};

struct HICHOSTCR_BITS {                       // bits description
    Uint32 EALLOW_EN:1;                       // 0 EALLOW Enable
    Uint32 ACCSIZE:1;                         // 1 Access Size
    Uint32 PAGESEL:1;                         // 2 Page Select
    Uint32 rsvd1:5;                           // 7:3 Reserved
    Uint32 HKEY:8;                            // 15:8 Host Key
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICHOSTCR_REG {
    Uint32  all;
    struct  HICHOSTCR_BITS  bit;
};

struct HICERRADDR_BITS {                      // bits description
    Uint32 H2D_ERR_ADDR:8;                    // 7:0 Address of the Host bus captured upon an error for Device
    Uint32 rsvd1:4;                           // 11:8 Reserved
    Uint32 H2D_BASE_SEL:3;                    // 14:12 Base Select corresponding to H2D error event
    Uint32 rsvd2:1;                           // 15 Reserved
    Uint32 D2H_ERR_ADDR:8;                    // 23:16 Address of the Host bus captured upon an error for Host
    Uint32 rsvd3:4;                           // 27:24 Reserved
    Uint32 D2H_BASE_SEL:3;                    // 30:28 Base Select corresponding to D2H error event
    Uint32 rsvd4:1;                           // 31 Reserved
};

union HICERRADDR_REG {
    Uint32  all;
    struct  HICERRADDR_BITS  bit;
};

struct HICDBADDR0_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR0_REG {
    Uint32  all;
    struct  HICDBADDR0_BITS  bit;
};

struct HICDBADDR1_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR1_REG {
    Uint32  all;
    struct  HICDBADDR1_BITS  bit;
};

struct HICDBADDR2_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR2_REG {
    Uint32  all;
    struct  HICDBADDR2_BITS  bit;
};

struct HICDBADDR3_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR3_REG {
    Uint32  all;
    struct  HICDBADDR3_BITS  bit;
};

struct HICDBADDR4_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR4_REG {
    Uint32  all;
    struct  HICDBADDR4_BITS  bit;
};

struct HICDBADDR5_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR5_REG {
    Uint32  all;
    struct  HICDBADDR5_BITS  bit;
};

struct HICDBADDR6_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR6_REG {
    Uint32  all;
    struct  HICDBADDR6_BITS  bit;
};

struct HICDBADDR7_BITS {                      // bits description
    Uint32 rsvd1:7;                           // 6:0 Reserved
    Uint32 BASE_ADDR:25;                      // 31:7 Base address of device region
};

union HICDBADDR7_REG {
    Uint32  all;
    struct  HICDBADDR7_BITS  bit;
};

struct HICH2DINTEN_BITS {                     // bits description
    Uint32 H2D_INTEN:1;                       // 0 Host To Device Interrupt Enable
    Uint32 BUSERR_INTEN:1;                    // 1 BusError Interrupt Enable
    Uint32 ILLWR_INTEN:1;                     // 2 Illegal Write event interrupt enable
    Uint32 ILLRD_INTEN:1;                     // 3 Illegal Read event interrupt enable
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICH2DINTEN_REG {
    Uint32  all;
    struct  HICH2DINTEN_BITS  bit;
};

struct HICH2DINTFLG_BITS {                    // bits description
    Uint32 H2D_FLG:1;                         // 0 Host To Device Interrupt Flag
    Uint32 BUSERR_FLG:1;                      // 1 BusError Interrupt Flag
    Uint32 ILLWR_FLG:1;                       // 2 Illegal write event interrupt flag
    Uint32 ILLRD_FLG:1;                       // 3 Illegal read event interrupt flag
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICH2DINTFLG_REG {
    Uint32  all;
    struct  HICH2DINTFLG_BITS  bit;
};

struct HICH2DINTCLR_BITS {                    // bits description
    Uint32 H2D_CLR:1;                         // 0 Host To Device Interrupt Clear
    Uint32 BUSERR_CLR:1;                      // 1 BusError Interrupt Clear
    Uint32 ILLWR_CLR:1;                       // 2 Illegal Write Interrupt Clear
    Uint32 ILLRD_CLR:1;                       // 3 Illegal Read Interrupt Clear
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICH2DINTCLR_REG {
    Uint32  all;
    struct  HICH2DINTCLR_BITS  bit;
};

struct HICH2DINTFRC_BITS {                    // bits description
    Uint32 H2D_INTFRC:1;                      // 0 Host To Device Force Set
    Uint32 BUSERR_INTFRC:1;                   // 1 BusError Interrupt Force Set
    Uint32 ILLWR_INTFRC:1;                    // 2 Illegal Write Interrupt Force Set
    Uint32 ILLRD_INTFRC:1;                    // 3 Illegal Read Interrupt Force Set
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HICH2DINTFRC_REG {
    Uint32  all;
    struct  HICH2DINTFRC_BITS  bit;
};

struct HICD2HINTEN_BITS {                     // bits description
    Uint32 D2H_INTEN:1;                       // 0 Device to Host Data Ready Interrupt Enable
    Uint32 BUSERR_INTEN:1;                    // 1 BusError Interrupt Enable
    Uint32 ILLWR_INTEN:1;                     // 2 Illegal Write event Interrupt Enable
    Uint32 ILLRD_INTEN:1;                     // 3 Illegal Read event Interrupt Enable
    Uint32 ACCVIO_INTEN:1;                    // 4 Access Violation Interrupt Enable
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 EVTRIG_INTEN:16;                   // 31:16 Event Trigger Interrupt Enable
};

union HICD2HINTEN_REG {
    Uint32  all;
    struct  HICD2HINTEN_BITS  bit;
};

struct HICD2HINTFLG_BITS {                    // bits description
    Uint32 D2H_FLG:1;                         // 0 Device to Host Data Ready Flag
    Uint32 BUSERR_FLG:1;                      // 1 BusError Flag
    Uint32 ILLWR_FLG:1;                       // 2 Illegal Write event Flag
    Uint32 ILLRD_FLG:1;                       // 3 Illegal Read event Flag
    Uint32 ACCVIO_FLG:1;                      // 4 Access Violation Flag
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 EVTRIG_FLG:16;                     // 31:16 Event Trigger Flag
};

union HICD2HINTFLG_REG {
    Uint32  all;
    struct  HICD2HINTFLG_BITS  bit;
};

struct HICD2HINTCLR_BITS {                    // bits description
    Uint32 D2H_CLR:1;                         // 0 Device to Host Interrupt Clear
    Uint32 BUSERR_CLR:1;                      // 1 BusError Interrupt Clear
    Uint32 ILLWR_CLR:1;                       // 2 Illegal Write Interrupt Clear
    Uint32 ILLRD_CLR:1;                       // 3 Illegal Read Interrupt Clear
    Uint32 ACCVIO_CLR:1;                      // 4 Access Violation Interrupt Clear
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 EVTRIG_CLR:16;                     // 31:16 Event Trigger Interrupt Clear
};

union HICD2HINTCLR_REG {
    Uint32  all;
    struct  HICD2HINTCLR_BITS  bit;
};

struct HICD2HINTFRC_BITS {                    // bits description
    Uint32 D2H_INTFRC:1;                      // 0 Device to Host Force Set
    Uint32 BUSERR_INTFRC:1;                   // 1 BusError Interrupt Force Set
    Uint32 ILLWR_INTFRC:1;                    // 2 Illegal Write Interrupt Force Set
    Uint32 ILLRD_INTFRC:1;                    // 3 Illegal Read Interrupt Force Set
    Uint32 ACCVIO_INTFRC:1;                   // 4 Access Violation Interrupt Force Set
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 EVTRIG_INTFRC:16;                  // 31:16 Event Trigger Interrupt Force Set
};

union HICD2HINTFRC_REG {
    Uint32  all;
    struct  HICD2HINTFRC_BITS  bit;
};

struct  HIC_CFG_REGS {
    union   HICREV_REG                       HICREV;                      // 0x0 Module Revision Register
    union   HICGCR_REG                       HICGCR;                      // 0x4 Global Control Register
    union   HICLOCK_REG                      HICLOCK;                     // 0x8 Lock Register
    union   HICMODECR_REG                    HICMODECR;                   // 0xc Mode Control Register
    union   HICPINPOLCR_REG                  HICPINPOLCR;                 // 0x10 Pin Polarity Control Register
    union   HICBASESEL_REG                   HICBASESEL;                  // 0x14 Base Select Register
    union   HICHOSTCR_REG                    HICHOSTCR;                   // 0x18 Host Control Register
    union   HICERRADDR_REG                   HICERRADDR;                  // 0x1c Host Error Address register
    Uint32                                   HICH2DTOKEN;                 // 0x20 Host to Device Token Register
    Uint32                                   HICD2HTOKEN;                 // 0x24 Devie to Host Token Register
    union   HICDBADDR0_REG                   HICDBADDR0;                  // 0x28 Device Base Address Register 0
    union   HICDBADDR1_REG                   HICDBADDR1;                  // 0x2c Device Base Address Register 1
    union   HICDBADDR2_REG                   HICDBADDR2;                  // 0x30 Device Base Address Register 2
    union   HICDBADDR3_REG                   HICDBADDR3;                  // 0x34 Device Base Address Register 3
    union   HICDBADDR4_REG                   HICDBADDR4;                  // 0x38 Device Base Address Register 4
    union   HICDBADDR5_REG                   HICDBADDR5;                  // 0x3c Device Base Address Register 5
    union   HICDBADDR6_REG                   HICDBADDR6;                  // 0x40 Device Base Address Register 6
    union   HICDBADDR7_REG                   HICDBADDR7;                  // 0x44 Device Base Address Register 7
    Uint32                                   rsvd1[2];                    // 0x48 Reserved
    union   HICH2DINTEN_REG                  HICH2DINTEN;                 // 0x50 H2D Interrupt Enable
    union   HICH2DINTFLG_REG                 HICH2DINTFLG;                // 0x54 H2D Interrupt status Flag
    union   HICH2DINTCLR_REG                 HICH2DINTCLR;                // 0x58 H2D Interrupt status Clear
    union   HICH2DINTFRC_REG                 HICH2DINTFRC;                // 0x5c H2D Interrupt Set Force
    union   HICD2HINTEN_REG                  HICD2HINTEN;                 // 0x60 D2H Interrupt Enable
    union   HICD2HINTFLG_REG                 HICD2HINTFLG;                // 0x64 D2H Interrupt status Flag
    union   HICD2HINTCLR_REG                 HICD2HINTCLR;                // 0x68 D2H Interrupt status Clear
    union   HICD2HINTFRC_REG                 HICD2HINTFRC;                // 0x6c D2H Interrupt Set Force
    Uint32                                   HICACCVIOADDR;               // 0x70 Access Violation Address
    Uint32                                   rsvd2[3];                    // 0x74 Reserved
    Uint32                                   H2D_BUF0;                    // 0x80 Host to Device Buffer 0
    Uint32                                   H2D_BUF1;                    // 0x84 Host to Device Buffer 1
    Uint32                                   H2D_BUF2;                    // 0x88 Host to Device Buffer 2
    Uint32                                   H2D_BUF3;                    // 0x8c Host to Device Buffer 3
    Uint32                                   H2D_BUF4;                    // 0x90 Host to Device Buffer 4
    Uint32                                   H2D_BUF5;                    // 0x94 Host to Device Buffer 5
    Uint32                                   H2D_BUF6;                    // 0x98 Host to Device Buffer 6
    Uint32                                   H2D_BUF7;                    // 0x9c Host to Device Buffer 7
    Uint32                                   H2D_BUF8;                    // 0xa0 Host to Device Buffer 8
    Uint32                                   H2D_BUF9;                    // 0xa4 Host to Device Buffer 9
    Uint32                                   H2D_BUF10;                   // 0xa8 Host to Device Buffer 10
    Uint32                                   H2D_BUF11;                   // 0xac Host to Device Buffer 11
    Uint32                                   H2D_BUF12;                   // 0xb0 Host to Device Buffer 12
    Uint32                                   H2D_BUF13;                   // 0xb4 Host to Device Buffer 13
    Uint32                                   H2D_BUF14;                   // 0xb8 Host to Device Buffer 14
    Uint32                                   H2D_BUF15;                   // 0xbc Host to Device Buffer 15
    Uint32                                   D2H_BUF0;                    // 0xc0 Device to Host Buffer 0
    Uint32                                   D2H_BUF1;                    // 0xc4 Device to Host Buffer 1
    Uint32                                   D2H_BUF2;                    // 0xc8 Device to Host Buffer 2
    Uint32                                   D2H_BUF3;                    // 0xcc Device to Host Buffer 3
    Uint32                                   D2H_BUF4;                    // 0xd0 Device to Host Buffer 4
    Uint32                                   D2H_BUF5;                    // 0xd4 Device to Host Buffer 5
    Uint32                                   D2H_BUF6;                    // 0xd8 Device to Host Buffer 6
    Uint32                                   D2H_BUF7;                    // 0xdc Device to Host Buffer 7
    Uint32                                   D2H_BUF8;                    // 0xe0 Device to Host Buffer 8
    Uint32                                   D2H_BUF9;                    // 0xe4 Device to Host Buffer 9
    Uint32                                   D2H_BUF10;                   // 0xe8 Device to Host Buffer 10
    Uint32                                   D2H_BUF11;                   // 0xec Device to Host Buffer 11
    Uint32                                   D2H_BUF12;                   // 0xf0 Device to Host Buffer 12
    Uint32                                   D2H_BUF13;                   // 0xf4 Device to Host Buffer 13
    Uint32                                   D2H_BUF14;                   // 0xf8 Device to Host Buffer 14
    Uint32                                   D2H_BUF15;                   // 0xfc Device to Host Buffer 15
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================