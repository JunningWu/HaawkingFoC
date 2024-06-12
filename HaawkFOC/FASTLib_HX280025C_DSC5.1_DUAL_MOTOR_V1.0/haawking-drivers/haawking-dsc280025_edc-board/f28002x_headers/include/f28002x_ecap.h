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


#ifndef F28002X_ECAP_H
#define F28002X_ECAP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ECAP Individual Register Bit Definitions:

struct ECCTL0_BITS {                          // bits description
    Uint32 INPUTSEL:7;                        // 6:0 INPUT source select
    Uint32 rsvd1:9;                           // 15:7 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ECCTL0_REG {
    Uint32  all;
    struct  ECCTL0_BITS  bit;
};

struct ECCTL1_BITS {                          // bits description
    Uint32 CAP1POL:1;                         // 0 Capture Event 1 Polarity select
    Uint32 CTRRST1:1;                         // 1 Counter Reset on Capture Event 1
    Uint32 CAP2POL:1;                         // 2 Capture Event 2 Polarity select
    Uint32 CTRRST2:1;                         // 3 Counter Reset on Capture Event 2
    Uint32 CAP3POL:1;                         // 4 Capture Event 3 Polarity select
    Uint32 CTRRST3:1;                         // 5 Counter Reset on Capture Event 3
    Uint32 CAP4POL:1;                         // 6 Capture Event 4 Polarity select
    Uint32 CTRRST4:1;                         // 7 Counter Reset on Capture Event 4
    Uint32 CAPLDEN:1;                         // 8 Enable Loading CAP1-4 regs on a Cap Event
    Uint32 PRESCALE:5;                        // 13:9 Event Filter prescale select
    Uint32 FREE_SOFT:2;                       // 15:14 Emulation mode
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ECCTL1_REG {
    Uint32  all;
    struct  ECCTL1_BITS  bit;
};

struct ECCTL2_BITS {                          // bits description
    Uint32 CONT_ONESHT:1;                     // 0 Continuous or one-shot
    Uint32 STOP_WRAP:2;                       // 2:1 Stop value for one-shot, Wrap for continuous
    Uint32 REARM:1;                           // 3 One-shot re-arm
    Uint32 TSCTRSTOP:1;                       // 4 TSCNT counter stop
    Uint32 SYNCI_EN:1;                        // 5 Counter sync-in select
    Uint32 SYNCO_SEL:2;                       // 7:6 Sync-out mode
    Uint32 SWSYNC:1;                          // 8 SW forced counter sync
    Uint32 CAP_APWM:1;                        // 9 CAP/APWM operating mode select
    Uint32 APWMPOL:1;                         // 10 APWM output polarity select
    Uint32 CTRFILTRESET:1;                    // 11 Reset event filter, modulus counter, and interrupt flags.
    Uint32 DMAEVTSEL:2;                       // 13:12 DMA event select
    Uint32 MODCNTRSTS:2;                      // 15:14 modulo counter status
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ECCTL2_REG {
    Uint32  all;
    struct  ECCTL2_BITS  bit;
};

struct ECEINT_BITS {                          // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CEVT1:1;                           // 1 Capture Event 1 Interrupt Enable
    Uint32 CEVT2:1;                           // 2 Capture Event 2 Interrupt Enable
    Uint32 CEVT3:1;                           // 3 Capture Event 3 Interrupt Enable
    Uint32 CEVT4:1;                           // 4 Capture Event 4 Interrupt Enable
    Uint32 CTROVF:1;                          // 5 Counter Overflow Interrupt Enable
    Uint32 CTR_EQ_PRD:1;                      // 6 Period Equal Interrupt Enable
    Uint32 CTR_EQ_CMP:1;                      // 7 Compare Equal Interrupt Enable
    Uint32 rsvd2:1;                           // 8 Reserved
    Uint32 rsvd3:23;                          // 31:9 Reserved
};

union ECEINT_REG {
    Uint32  all;
    struct  ECEINT_BITS  bit;
};

struct ECFLG_BITS {                           // bits description
    Uint32 INT:1;                             // 0 Global Flag
    Uint32 CEVT1:1;                           // 1 Capture Event 1 Interrupt Flag
    Uint32 CEVT2:1;                           // 2 Capture Event 2 Interrupt Flag
    Uint32 CEVT3:1;                           // 3 Capture Event 3 Interrupt Flag
    Uint32 CEVT4:1;                           // 4 Capture Event 4 Interrupt Flag
    Uint32 CTROVF:1;                          // 5 Counter Overflow Interrupt Flag
    Uint32 CTR_PRD:1;                         // 6 Period Equal Interrupt Flag
    Uint32 CTR_CMP:1;                         // 7 Compare Equal Interrupt Flag
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:23;                          // 31:9 Reserved
};

union ECFLG_REG {
    Uint32  all;
    struct  ECFLG_BITS  bit;
};

struct ECCLR_BITS {                           // bits description
    Uint32 INT:1;                             // 0 ECAP Global Interrupt Status Clear
    Uint32 CEVT1:1;                           // 1 Capture Event 1 Status Clear
    Uint32 CEVT2:1;                           // 2 Capture Event 2 Status Clear
    Uint32 CEVT3:1;                           // 3 Capture Event 3 Status Clear
    Uint32 CEVT4:1;                           // 4 Capture Event 4 Status Clear
    Uint32 CTROVF:1;                          // 5 Counter Overflow Status Clear
    Uint32 CTR_PRD:1;                         // 6 Period Equal Status Clear
    Uint32 CTR_CMP:1;                         // 7 Compare Equal Status Clear
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:23;                          // 31:9 Reserved
};

union ECCLR_REG {
    Uint32  all;
    struct  ECCLR_BITS  bit;
};

struct ECFRC_BITS {                           // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CEVT1:1;                           // 1 Capture Event 1 Force Interrupt
    Uint32 CEVT2:1;                           // 2 Capture Event 2 Force Interrupt
    Uint32 CEVT3:1;                           // 3 Capture Event 3 Force Interrupt
    Uint32 CEVT4:1;                           // 4 Capture Event 4 Force Interrupt
    Uint32 CTROVF:1;                          // 5 Counter Overflow Force Interrupt
    Uint32 CTR_PRD:1;                         // 6 Period Equal Force Interrupt
    Uint32 CTR_CMP:1;                         // 7 Compare Equal Force Interrupt
    Uint32 rsvd2:1;                           // 8 Reserved
    Uint32 rsvd3:23;                          // 31:9 Reserved
};

union ECFRC_REG {
    Uint32  all;
    struct  ECFRC_BITS  bit;
};

struct ECAPSYNCINSEL_BITS {                   // bits description
    Uint32 SEL:5;                             // 4:0 SYNCIN source select
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ECAPSYNCINSEL_REG {
    Uint32  all;
    struct  ECAPSYNCINSEL_BITS  bit;
};

struct  ECAP_REGS {
    Uint32                                   TSCTR;                       // 0x0 Time-Stamp Counter
    Uint32                                   CTRPHS;                      // 0x4 Counter Phase Offset Value Register
    Uint32                                   CAP1;                        // 0x8 Capture 1 Register
    Uint32                                   CAP2;                        // 0xc Capture 2 Register
    Uint32                                   CAP3;                        // 0x10 Capture 3 Register
    Uint32                                   CAP4;                        // 0x14 Capture 4 Register
    Uint32                                   rsvd1[2];                    // 0x18 Reserved
    union   ECCTL0_REG                       ECCTL0;                      // 0x20 Capture Control Register 0
    union   ECCTL1_REG                       ECCTL1;                      // 0x24 Capture Control Register 1
    union   ECCTL2_REG                       ECCTL2;                      // 0x28 Capture Control Register 2
    union   ECEINT_REG                       ECEINT;                      // 0x2c Capture Interrupt Enable Register
    union   ECFLG_REG                        ECFLG;                       // 0x30 Capture Interrupt Flag Register
    union   ECCLR_REG                        ECCLR;                       // 0x34 Capture Interrupt Clear Register
    union   ECFRC_REG                        ECFRC;                       // 0x38 Capture Interrupt Force Register
    union   ECAPSYNCINSEL_REG                ECAPSYNCINSEL;               // 0x3c SYNC source select register
};

struct HCCTL_BITS {                           // bits description
    Uint32 SOFTRESET:1;                       // 0 Writing 1 to this bit will clear HCCOUNTER
    Uint32 RISEINTE:1;                        // 1 High Resolution Clock Enable
    Uint32 FALLINTE:1;                        // 2 Calibration Period Match
    Uint32 OVFINTE:1;                         // 3 Calibration start
    Uint32 rsvd1:4;                           // 7:4 Reserved
    Uint32 HCCAPCLKSEL:1;                     // 8 Calibration status
    Uint32 rsvd2:23;                          // 31:9 Reserved
};

union HCCTL_REG {
    Uint32  all;
    struct  HCCTL_BITS  bit;
};

struct HCIFR_BITS {                           // bits description
    Uint32 INT:1;                             // 0 Global interrupt flag
    Uint32 RISE:1;                            // 1 Rising edge capture interrupt flag
    Uint32 FALL:1;                            // 2 Falling edge capture interrupt flag
    Uint32 COUNTEROVF:1;                      // 3 Counter overflow interrupt flag
    Uint32 RISEOVF:1;                         // 4 Rising edge interrupt overflow event flag
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union HCIFR_REG {
    Uint32  all;
    struct  HCIFR_BITS  bit;
};

struct HCICLR_BITS {                          // bits description
    Uint32 INT:1;                             // 0 Global clear flag
    Uint32 RISE:1;                            // 1 Rising edge capture clear flag
    Uint32 FALL:1;                            // 2 Falling edge capture clear flag
    Uint32 COUNTEROVF:1;                      // 3 Counter overflow interrupt clear bit
    Uint32 RISEOVF:1;                         // 4 Rising edge interrupt overflow clear bit
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union HCICLR_REG {
    Uint32  all;
    struct  HCICLR_BITS  bit;
};

struct HCIFRC_BITS {                          // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 RISE:1;                            // 1 Rising edge interrupt forcing bit
    Uint32 FALL:1;                            // 2 Falling edge interrupt forcing bit
    Uint32 COUNTEROVF:1;                      // 3 Counter overflow interrupt forcing bit
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union HCIFRC_REG {
    Uint32  all;
    struct  HCIFRC_BITS  bit;
};

struct HCCOUNTER_BITS {                       // bits description
    Uint32 CALIBINT:1;                        // 0 Clear Global calibration Interrupt Flag
    Uint32 CALIBDONE:1;                       // 1 Clear Calibration Done Interrupt Flag Bit
    Uint32 CALPRDCHKSTS:1;                    // 2 Clear Calibration period check status Flag Bit
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HCCOUNTER_REG {
    Uint32  all;
    struct  HCCOUNTER_BITS  bit;
};

struct HCCAL_BITS {                           // bits description
    Uint32 DLL_START_POINTS:8;                // 7:0 Dll initial value
    Uint32 PHASE_DETECT_SEL:3;                // 10:8 And DLL START Point is used together to calculate
    Uint32 rsvd1:3;                           // 13:11 Reserved
    Uint32 HRCAPMODE:1;                       // 14 When HRPWMSEL is equal to 1, HRCAP belongs to
    Uint32 HRPWMSEL:1;                        // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union HCCAL_REG {
    Uint32  all;
    struct  HCCAL_BITS  bit;
};

struct HCMEPSTATUS_BITS {                     // bits description
    Uint32 LOCK:2;                            // 1:0 Lock status bit
    Uint32 MEP_SCALE_FACTOR:8;                // 9:2 MEP Scale Factor bit
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union HCMEPSTATUS_REG {
    Uint32  all;
    struct  HCMEPSTATUS_BITS  bit;
};

struct  HRCAP_REGS {
    union   HCCTL_REG                        HCCTL;                       // 0x0 none
    union   HCIFR_REG                        HCIFR;                       // 0x4 none
    union   HCICLR_REG                       HCICLR;                      // 0x8 none
    union   HCIFRC_REG                       HCIFRC;                      // 0xc none
    union   HCCOUNTER_REG                    HCCOUNTER;                   // 0x10 none
    union   HCCAL_REG                        HCCAL;                       // 0x14 none
    Uint32                                   HCCALMEP;                    // 0x18 none
    union   HCMEPSTATUS_REG                  HCMEPSTATUS;                 // 0x1c none
    Uint32                                   rsvd1[8];                    // 0x20 Reserved
    Uint32                                   HCCAPCNTRISE0;               // 0x40 none
    Uint32                                   rsvd2;                       // 0x44 Reserved
    Uint32                                   HCCAPCNTFALL0;               // 0x48 none
    Uint32                                   rsvd3[5];                    // 0x4c Reserved
    Uint32                                   HCCAPCNTRISE1;               // 0x60 none
    Uint32                                   rsvd4;                       // 0x64 Reserved
    Uint32                                   HCCAPCNTFALL1;               // 0x68 none
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================