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


#ifndef F28002X_EQEP_H
#define F28002X_EQEP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EQEP Individual Register Bit Definitions:

struct QDECCTL_BITS {                         // bits description
    Uint32 QIDIRE:1;                          // 0 Qep Index Direction Enhancement enable
    Uint32 rsvd1:4;                           // 4:1 Reserved
    Uint32 QSP:1;                             // 5 QEPS input polarity
    Uint32 QIP:1;                             // 6 QEPI input polarity
    Uint32 QBP:1;                             // 7 QEPB input polarity
    Uint32 QAP:1;                             // 8 QEPA input polarity
    Uint32 IGATE:1;                           // 9 Index pulse gating option
    Uint32 SWAP:1;                            // 10 CLK/DIR Signal Source for Position Counter
    Uint32 XCR:1;                             // 11 External Clock Rate
    Uint32 SPSEL:1;                           // 12 Sync output pin selection
    Uint32 SOEN:1;                            // 13 Sync output-enable
    Uint32 QSRC:2;                            // 15:14 Position-counter source selection
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union QDECCTL_REG {
    Uint32  all;
    struct  QDECCTL_BITS  bit;
};

struct QEPCTL_BITS {                          // bits description
    Uint32 WDE:1;                             // 0 QEP watchdog enable
    Uint32 UTE:1;                             // 1 QEP unit timer enable
    Uint32 QCLM:1;                            // 2 QEP capture latch mode
    Uint32 QPEN:1;                            // 3 Quadrature postotion counter enable
    Uint32 IEL:2;                             // 5:4 Index event latch
    Uint32 SEL:1;                             // 6 Strobe event latch
    Uint32 SWI:1;                             // 7 Software init position counter
    Uint32 IEI:2;                             // 9:8 Index event init of position count
    Uint32 SEI:2;                             // 11:10 Strobe event init
    Uint32 PCRM:2;                            // 13:12 Postion counter reset
    Uint32 FREE_SOFT:2;                       // 15:14 Emulation mode
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union QEPCTL_REG {
    Uint32  all;
    struct  QEPCTL_BITS  bit;
};

struct QCAPCTL_BITS {                         // bits description
    Uint32 UPPS:4;                            // 3:0 Unit position event prescaler
    Uint32 CCPS:3;                            // 6:4 eQEP capture timer clock prescaler
    Uint32 rsvd1:8;                           // 14:7 Reserved
    Uint32 CEN:1;                             // 15 Enable eQEP capture
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union QCAPCTL_REG {
    Uint32  all;
    struct  QCAPCTL_BITS  bit;
};

struct QPOSCTL_BITS {                         // bits description
    Uint32 PCSPW:12;                          // 11:0 Position compare sync pulse width
    Uint32 PCE:1;                             // 12 Position compare enable/disable
    Uint32 PCPOL:1;                           // 13 Polarity of sync output
    Uint32 PCLOAD:1;                          // 14 Position compare of shadow load
    Uint32 PCSHDW:1;                          // 15 Position compare of shadow enable
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union QPOSCTL_REG {
    Uint32  all;
    struct  QPOSCTL_BITS  bit;
};

struct QEINT_BITS {                           // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 PCE:1;                             // 1 Position counter error interrupt enable
    Uint32 QPE:1;                             // 2 Quadrature phase error interrupt enable
    Uint32 QDC:1;                             // 3 Quadrature direction change interrupt enable
    Uint32 WTO:1;                             // 4 Watchdog time out interrupt enable
    Uint32 PCU:1;                             // 5 Position counter underflow interrupt enable
    Uint32 PCO:1;                             // 6 Position counter overflow interrupt enable
    Uint32 PCR:1;                             // 7 Position-compare ready interrupt enable
    Uint32 PCM:1;                             // 8 Position-compare match interrupt enable
    Uint32 SEL:1;                             // 9 Strobe event latch interrupt enable
    Uint32 IEL:1;                             // 10 Index event latch interrupt enable
    Uint32 UTO:1;                             // 11 Unit time out interrupt enable
    Uint32 QMAE:1;                            // 12 QMA error interrupt enable
    Uint32 rsvd2:19;                          // 31:13 Reserved
};

union QEINT_REG {
    Uint32  all;
    struct  QEINT_BITS  bit;
};

struct QFLG_BITS {                            // bits description
    Uint32 INT:1;                             // 0 Global interrupt status flag
    Uint32 PCE:1;                             // 1 Position counter error interrupt flag
    Uint32 PHE:1;                             // 2 Quadrature phase error interrupt flag
    Uint32 QDC:1;                             // 3 Quadrature direction change interrupt flag
    Uint32 WTO:1;                             // 4 Watchdog timeout interrupt flag
    Uint32 PCU:1;                             // 5 Position counter underflow interrupt flag
    Uint32 PCO:1;                             // 6 Position counter overflow interrupt flag
    Uint32 PCR:1;                             // 7 Position-compare ready interrupt flag
    Uint32 PCM:1;                             // 8 eQEP compare match event interrupt flag
    Uint32 SEL:1;                             // 9 Strobe event latch interrupt flag
    Uint32 IEL:1;                             // 10 Index event latch interrupt flag
    Uint32 UTO:1;                             // 11 Unit time out interrupt flag
    Uint32 QMAE:1;                            // 12 QMA error interrupt flag
    Uint32 rsvd1:19;                          // 31:13 Reserved
};

union QFLG_REG {
    Uint32  all;
    struct  QFLG_BITS  bit;
};

struct QCLR_BITS {                            // bits description
    Uint32 INT:1;                             // 0 Global interrupt clear flag
    Uint32 PCE:1;                             // 1 Clear position counter error interrupt flag
    Uint32 PHE:1;                             // 2 Clear quadrature phase error interrupt flag
    Uint32 QDC:1;                             // 3 Clear quadrature direction change interrupt flag
    Uint32 WTO:1;                             // 4 Clear watchdog timeout interrupt flag
    Uint32 PCU:1;                             // 5 Clear position counter underflow interrupt flag
    Uint32 PCO:1;                             // 6 Clear position counter overflow interrupt flag
    Uint32 PCR:1;                             // 7 Clear position-compare ready interrupt flag
    Uint32 PCM:1;                             // 8 Clear eQEP compare match event interrupt flag
    Uint32 SEL:1;                             // 9 Clear strobe event latch interrupt flag
    Uint32 IEL:1;                             // 10 Clear index event latch interrupt flag
    Uint32 UTO:1;                             // 11 Clear unit time out interrupt flag
    Uint32 QMAE:1;                            // 12 Clear QMA error interrupt flag
    Uint32 rsvd1:19;                          // 31:13 Reserved
};

union QCLR_REG {
    Uint32  all;
    struct  QCLR_BITS  bit;
};

struct QFRC_BITS {                            // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 PCE:1;                             // 1 Force position counter error interrupt
    Uint32 PHE:1;                             // 2 Force quadrature phase error interrupt
    Uint32 QDC:1;                             // 3 Force quadrature direction change interrupt
    Uint32 WTO:1;                             // 4 Force watchdog time out interrupt
    Uint32 PCU:1;                             // 5 Force position counter underflow interrupt
    Uint32 PCO:1;                             // 6 Force position counter overflow interrupt
    Uint32 PCR:1;                             // 7 Force position-compare ready interrupt
    Uint32 PCM:1;                             // 8 Force position-compare match interrupt
    Uint32 SEL:1;                             // 9 Force strobe event latch interrupt
    Uint32 IEL:1;                             // 10 Force index event latch interrupt
    Uint32 UTO:1;                             // 11 Force unit time out interrupt
    Uint32 QMAE:1;                            // 12 Force QMA error interrupt
    Uint32 rsvd2:19;                          // 31:13 Reserved
};

union QFRC_REG {
    Uint32  all;
    struct  QFRC_BITS  bit;
};

struct QEPSTS_BITS {                          // bits description
    Uint32 PCEF:1;                            // 0 Position counter error flag.
    Uint32 FIMF:1;                            // 1 First index marker flag
    Uint32 CDEF:1;                            // 2 Capture direction error flag
    Uint32 COEF:1;                            // 3 Capture overflow error flag
    Uint32 QDLF:1;                            // 4 eQEP direction latch flag
    Uint32 QDF:1;                             // 5 Quadrature direction flag
    Uint32 FIDF:1;                            // 6 The first index marker
    Uint32 UPEVNT:1;                          // 7 Unit position event flag
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union QEPSTS_REG {
    Uint32  all;
    struct  QEPSTS_BITS  bit;
};

struct REV_BITS {                             // bits description
    Uint32 MAJOR:3;                           // 2:0 Major Revision Number
    Uint32 MINOR:3;                           // 5:3 Minor Revision Number
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union REV_REG {
    Uint32  all;
    struct  REV_BITS  bit;
};

struct QEPSTROBESEL_BITS {                    // bits description
    Uint32 STROBESEL:2;                       // 1:0 QMA Mode Select
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union QEPSTROBESEL_REG {
    Uint32  all;
    struct  QEPSTROBESEL_BITS  bit;
};

struct QMACTRL_BITS {                         // bits description
    Uint32 MODE:3;                            // 2:0 QMA Mode Select
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union QMACTRL_REG {
    Uint32  all;
    struct  QMACTRL_BITS  bit;
};

struct QEPSRCSEL_BITS {                       // bits description
    Uint32 QEPASEL:4;                         // 3:0 QEPA Source select
    Uint32 QEPBSEL:4;                         // 7:4 QEPB Source select
    Uint32 QEPISEL:4;                         // 11:8 QEPI Source select
    Uint32 QEPSSEL:4;                         // 15:12 QEPS Source select
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union QEPSRCSEL_REG {
    Uint32  all;
    struct  QEPSRCSEL_BITS  bit;
};

struct  EQEP_REGS {
    Uint32                                   QPOSCNT;                     // 0x0 Position Counter
    Uint32                                   QPOSINIT;                    // 0x4 Position Counter Init
    Uint32                                   QPOSMAX;                     // 0x8 Maximum Position Count
    Uint32                                   QPOSCMP;                     // 0xc Position Compare
    Uint32                                   QPOSILAT;                    // 0x10 Index Position Latch
    Uint32                                   QPOSSLAT;                    // 0x14 Strobe Position Latch
    Uint32                                   QPOSLAT;                     // 0x18 Position Latch
    Uint32                                   QUTMR;                       // 0x1c QEP Unit Timer
    Uint32                                   QUPRD;                       // 0x20 QEP Unit Period
    Uint32                                   QWDTMR;                      // 0x24 QEP Watchdog Timer
    Uint32                                   QWDPRD;                      // 0x28 QEP Watchdog Period
    union   QDECCTL_REG                      QDECCTL;                     // 0x2c Quadrature Decoder Control
    union   QEPCTL_REG                       QEPCTL;                      // 0x30 QEP Control
    union   QCAPCTL_REG                      QCAPCTL;                     // 0x34 Qaudrature Capture Control
    union   QPOSCTL_REG                      QPOSCTL;                     // 0x38 Position Compare Control
    union   QEINT_REG                        QEINT;                       // 0x3c QEP Interrupt Control
    union   QFLG_REG                         QFLG;                        // 0x40 QEP Interrupt Flag
    union   QCLR_REG                         QCLR;                        // 0x44 QEP Interrupt Clear
    union   QFRC_REG                         QFRC;                        // 0x48 QEP Interrupt Force
    union   QEPSTS_REG                       QEPSTS;                      // 0x4c QEP Status
    Uint32                                   QCTMR;                       // 0x50 QEP Capture Timer
    Uint32                                   QCPRD;                       // 0x54 QEP Capture Period
    Uint32                                   QCTMRLAT;                    // 0x58 QEP Capture Latch
    Uint32                                   QCPRDLAT;                    // 0x5c QEP Capture Period Latch
    union   REV_REG                          REV;                         // 0x60 QEP Revision Number
    union   QEPSTROBESEL_REG                 QEPSTROBESEL;                // 0x64 QEP Strobe select register
    union   QMACTRL_REG                      QMACTRL;                     // 0x68 QMA Control register
    union   QEPSRCSEL_REG                    QEPSRCSEL;                   // 0x6c QEP Source Select Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================