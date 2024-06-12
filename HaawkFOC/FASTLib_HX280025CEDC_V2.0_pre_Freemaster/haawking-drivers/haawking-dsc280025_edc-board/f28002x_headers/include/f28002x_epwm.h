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


#ifndef F28002X_EPWM_H
#define F28002X_EPWM_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EPWM Individual Register Bit Definitions:

struct TBCTL_BITS {                           // bits description
    Uint32 CTRMODE:2;                         // 1:0 Counter Mode
    Uint32 PHSEN:1;                           // 2 Phase Load Enable
    Uint32 PRDLD:1;                           // 3 Active Period Load
    Uint32 rsvd1:2;                           // 5:4 Reserved
    Uint32 SWFSYNC:1;                         // 6 Software Force Sync Pulse
    Uint32 HSPCLKDIV:3;                       // 9:7 High Speed TBCLK Pre-scaler
    Uint32 CLKDIV:3;                          // 12:10 Time Base Clock Pre-scaler
    Uint32 PHSDIR:1;                          // 13 Phase Direction Bit
    Uint32 FREE_SOFT:2;                       // 15:14 Emulation Mode Bits
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union TBCTL_REG {
    Uint32  all;
    struct  TBCTL_BITS  bit;
};

struct TBCTL2_BITS {                          // bits description
    Uint32 rsvd1:5;                           // 4:0 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 OSHTSYNCMODE:1;                    // 6 One shot sync mode
    Uint32 OSHTSYNC:1;                        // 7 One shot sync
    Uint32 rsvd3:4;                           // 11:8 Reserved
    Uint32 rsvd4:2;                           // 13:12 Reserved
    Uint32 PRDLDSYNC:2;                       // 15:14 PRD Shadow to Active Load on SYNC Event
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union TBCTL2_REG {
    Uint32  all;
    struct  TBCTL2_BITS  bit;
};

struct EPWMSYNCINSEL_BITS {                   // bits description
    Uint32 SEL:5;                             // 4:0 EPWMxSYNCI source select
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union EPWMSYNCINSEL_REG {
    Uint32  all;
    struct  EPWMSYNCINSEL_BITS  bit;
};

struct TBSTS_BITS {                           // bits description
    Uint32 CTRDIR:1;                          // 0 Counter Direction Status
    Uint32 SYNCI:1;                           // 1 External Input Sync Status
    Uint32 CTRMAX:1;                          // 2 Counter Max Latched Status
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union TBSTS_REG {
    Uint32  all;
    struct  TBSTS_BITS  bit;
};

struct EPWMSYNCOUTEN_BITS {                   // bits description
    Uint32 SWEN:1;                            // 0 EPWMxSYNCO Software Force Enable
    Uint32 ZEROEN:1;                          // 1 EPWMxSYNCO Zero Count Event Enable
    Uint32 CMPBEN:1;                          // 2 EPWMxSYNCO Compare B Event Enable
    Uint32 CMPCEN:1;                          // 3 EPWMxSYNCO Compare C Event Enable
    Uint32 CMPDEN:1;                          // 4 EPWMxSYNCO Compare D Event Enable
    Uint32 DCAEVT1EN:1;                       // 5 EPWMxSYNCO Digital Compare A Event 1 Sync Enable
    Uint32 DCBEVT1EN:1;                       // 6 EPWMxSYNCO Digital Compare B Event 1 Sync Enable
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union EPWMSYNCOUTEN_REG {
    Uint32  all;
    struct  EPWMSYNCOUTEN_BITS  bit;
};

struct TBCTL3_BITS {                          // bits description
    Uint32 OSSFRCEN:1;                        // 0 One Shot Sync Force Enable
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union TBCTL3_REG {
    Uint32  all;
    struct  TBCTL3_BITS  bit;
};

struct CMPCTL_BITS {                          // bits description
    Uint32 LOADAMODE:2;                       // 1:0 Active Compare A Load
    Uint32 LOADBMODE:2;                       // 3:2 Active Compare B Load
    Uint32 SHDWAMODE:1;                       // 4 Compare A Register Block Operating Mode
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 SHDWBMODE:1;                       // 6 Compare B Register Block Operating Mode
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 SHDWAFULL:1;                       // 8 Compare A Shadow Register Full Status
    Uint32 SHDWBFULL:1;                       // 9 Compare B Shadow Register Full Status
    Uint32 LOADASYNC:2;                       // 11:10 Active Compare A Load on SYNC
    Uint32 LOADBSYNC:2;                       // 13:12 Active Compare B Load on SYNC
    Uint32 rsvd3:18;                          // 31:14 Reserved
};

union CMPCTL_REG {
    Uint32  all;
    struct  CMPCTL_BITS  bit;
};

struct CMPCTL2_BITS {                         // bits description
    Uint32 LOADCMODE:2;                       // 1:0 Active Compare C Load
    Uint32 LOADDMODE:2;                       // 3:2 Active Compare D load
    Uint32 SHDWCMODE:1;                       // 4 Compare C Block Operating Mode
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 SHDWDMODE:1;                       // 6 Compare D Block Operating Mode
    Uint32 rsvd2:3;                           // 9:7 Reserved
    Uint32 LOADCSYNC:2;                       // 11:10 Active Compare C Load on SYNC
    Uint32 LOADDSYNC:2;                       // 13:12 Active Compare D Load on SYNC
    Uint32 rsvd3:18;                          // 31:14 Reserved
};

union CMPCTL2_REG {
    Uint32  all;
    struct  CMPCTL2_BITS  bit;
};

struct DBCTL_BITS {                           // bits description
    Uint32 OUT_MODE:2;                        // 1:0 Dead Band Output Mode Control
    Uint32 POLSEL:2;                          // 3:2 Polarity Select Control
    Uint32 IN_MODE:2;                         // 5:4 Dead Band Input Select Mode Control
    Uint32 LOADREDMODE:2;                     // 7:6 Active DBRED Load Mode
    Uint32 LOADFEDMODE:2;                     // 9:8 Active DBFED Load Mode
    Uint32 SHDWDBREDMODE:1;                   // 10 DBRED Block Operating Mode
    Uint32 SHDWDBFEDMODE:1;                   // 11 DBFED Block Operating Mode
    Uint32 OUTSWAP:2;                         // 13:12 Dead Band Output Swap Control
    Uint32 DEDB_MODE:1;                       // 14 Dead Band Dual-Edge B Mode Control
    Uint32 HALFCYCLE:1;                       // 15 Half Cycle Clocking Enable
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DBCTL_REG {
    Uint32  all;
    struct  DBCTL_BITS  bit;
};

struct DBCTL2_BITS {                          // bits description
    Uint32 LOADDBCTLMODE:2;                   // 1:0 DBCTL Load from Shadow Mode Select
    Uint32 SHDWDBCTLMODE:1;                   // 2 DBCTL Load mode Select
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union DBCTL2_REG {
    Uint32  all;
    struct  DBCTL2_BITS  bit;
};

struct AQCTL_BITS {                           // bits description
    Uint32 LDAQAMODE:2;                       // 1:0 Action Qualifier A Load Select
    Uint32 LDAQBMODE:2;                       // 3:2 Action Qualifier B Load Select
    Uint32 SHDWAQAMODE:1;                     // 4 Action Qualifer A Operating Mode
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 SHDWAQBMODE:1;                     // 6 Action Qualifier B Operating Mode
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 LDAQASYNC:2;                       // 9:8 AQCTLA Register Load on SYNC
    Uint32 LDAQBSYNC:2;                       // 11:10 AQCTLB Register Load on SYNC
    Uint32 rsvd3:20;                          // 31:12 Reserved
};

union AQCTL_REG {
    Uint32  all;
    struct  AQCTL_BITS  bit;
};

struct AQTSRCSEL_BITS {                       // bits description
    Uint32 T1SEL:4;                           // 3:0 T1 Event Source Select Bits
    Uint32 T2SEL:4;                           // 7:4 T2 Event Source Select Bits
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union AQTSRCSEL_REG {
    Uint32  all;
    struct  AQTSRCSEL_BITS  bit;
};

struct PCCTL_BITS {                           // bits description
    Uint32 CHPEN:1;                           // 0 PWM chopping enable
    Uint32 OSHTWTH:4;                         // 4:1 One-shot pulse width
    Uint32 CHPFREQ:3;                         // 7:5 Chopping clock frequency
    Uint32 CHPDUTY:3;                         // 10:8 Chopping clock Duty cycle
    Uint32 rsvd1:21;                          // 31:11 Reserved
};

union PCCTL_REG {
    Uint32  all;
    struct  PCCTL_BITS  bit;
};

struct VCAPCTL_BITS {                         // bits description
    Uint32 VCAPE:1;                           // 0 Valley Capture mode
    Uint32 VCAPSTART:1;                       // 1 Valley Capture Start
    Uint32 TRIGSEL:3;                         // 4:2 Capture Trigger Select
    Uint32 rsvd1:2;                           // 6:5 Reserved
    Uint32 VDELAYDIV:3;                       // 9:7 Valley Delay Mode Divide Enable
    Uint32 EDGEFILTDLYSEL:1;                  // 10 Valley Switching Mode Delay Select
    Uint32 rsvd2:21;                          // 31:11 Reserved
};

union VCAPCTL_REG {
    Uint32  all;
    struct  VCAPCTL_BITS  bit;
};

struct VCNTCFG_BITS {                         // bits description
    Uint32 STARTEDGE:4;                       // 3:0 Counter Start Edge Selection
    Uint32 rsvd1:3;                           // 6:4 Reserved
    Uint32 STARTEDGESTS:1;                    // 7 Start Edge Status Bit
    Uint32 STOPEDGE:4;                        // 11:8 Counter Start Edge Selection
    Uint32 rsvd2:3;                           // 14:12 Reserved
    Uint32 STOPEDGESTS:1;                     // 15 Stop Edge Status Bit
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union VCNTCFG_REG {
    Uint32  all;
    struct  VCNTCFG_BITS  bit;
};

struct HRCNFG_BITS {                          // bits description
    Uint32 EDGMODE:2;                         // 1:0 ePWMxA Edge Mode Select Bits
    Uint32 CTLMODE:1;                         // 2 ePWMxA Control Mode Select Bits
    Uint32 HRLOAD:2;                          // 4:3 ePWMxA Shadow Mode Select Bits
    Uint32 SELOUTB:1;                         // 5 EPWMB Output Selection Bit
    Uint32 AUTOCONV:1;                        // 6 Autoconversion Bit
    Uint32 SWAPAB:1;                          // 7 Swap EPWMA and EPWMB Outputs Bit
    Uint32 EDGMODEB:2;                        // 9:8 ePWMxB Edge Mode Select Bits
    Uint32 CTLMODEB:1;                        // 10 ePWMxB Control Mode Select Bits
    Uint32 HRLOADB:2;                         // 12:11 ePWMxB Shadow Mode Select Bits
    Uint32 rsvd1:1;                           // 13 Reserved
    Uint32 rsvd2:2;                           // 15:14 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union HRCNFG_REG {
    Uint32  all;
    struct  HRCNFG_BITS  bit;
};

struct HRPWR_BITS {                           // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:1;                           // 4 Reserved
    Uint32 rsvd5:1;                           // 5 Reserved
    Uint32 rsvd6:4;                           // 9:6 Reserved
    Uint32 rsvd7:5;                           // 14:10 Reserved
    Uint32 CALPWRON:1;                        // 15 Calibration Power On
    Uint32 rsvd8:16;                          // 31:16 Reserved
};

union HRPWR_REG {
    Uint32  all;
    struct  HRPWR_BITS  bit;
};

struct HRMSTEP_BITS {                         // bits description
    Uint32 HRMSTEP:9;                         // 8:0 High Resolution Micro Step Value
    Uint32 rsvd1:23;                          // 31:9 Reserved
};

union HRMSTEP_REG {
    Uint32  all;
    struct  HRMSTEP_BITS  bit;
};

struct HRCNFG2_BITS {                         // bits description
    Uint32 EDGMODEDB:2;                       // 1:0 Dead-Band Edge-Mode Select Bits
    Uint32 CTLMODEDBRED:2;                    // 3:2 DBRED Control Mode Select Bits
    Uint32 CTLMODEDBFED:2;                    // 5:4 DBFED Control Mode Select Bits
    Uint32 rsvd1:8;                           // 13:6 Reserved
    Uint32 rsvd2:1;                           // 14 Reserved
    Uint32 rsvd3:17;                          // 31:15 Reserved
};

union HRCNFG2_REG {
    Uint32  all;
    struct  HRCNFG2_BITS  bit;
};

struct HRPCTL_BITS {                          // bits description
    Uint32 HRPE:1;                            // 0 High Resolution Period Enable
    Uint32 PWMSYNCSEL:1;                      // 1 EPWMSYNCPER Source Select
    Uint32 TBPHSHRLOADE:1;                    // 2 TBPHSHR Load Enable
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 PWMSYNCSELX:3;                     // 6:4 EPWMSYNCPER Extended Source Select Bit:
    Uint32 rsvd2:25;                          // 31:7 Reserved
};

union HRPCTL_REG {
    Uint32  all;
    struct  HRPCTL_BITS  bit;
};

struct TRREM_BITS {                           // bits description
    Uint32 TRREM:11;                          // 10:0 HRPWM Remainder Bits
    Uint32 rsvd1:21;                          // 31:11 Reserved
};

union TRREM_REG {
    Uint32  all;
    struct  TRREM_BITS  bit;
};

struct GLDCTL_BITS {                          // bits description
    Uint32 GLD:1;                             // 0 Global Shadow to Active load event control
    Uint32 GLDMODE:4;                         // 4:1 Shadow to Active Global Load Pulse Selection
    Uint32 OSHTMODE:1;                        // 5 One Shot Load mode control bit
    Uint32 rsvd1:1;                           // 6 Reserved
    Uint32 GLDPRD:3;                          // 9:7 Global Load Strobe Period Select Register
    Uint32 GLDCNT:3;                          // 12:10 Global Load Strobe Counter Register
    Uint32 rsvd2:19;                          // 31:13 Reserved
};

union GLDCTL_REG {
    Uint32  all;
    struct  GLDCTL_BITS  bit;
};

struct GLDCFG_BITS {                          // bits description
    Uint32 TBPRD_TBPRDHR:1;                   // 0 Global load event configuration for TBPRD:TBPRDHR
    Uint32 CMPA_CMPAHR:1;                     // 1 Global load event configuration for CMPA:CMPAHR
    Uint32 CMPB_CMPBHR:1;                     // 2 Global load event configuration for CMPB:CMPBHR
    Uint32 CMPC:1;                            // 3 Global load event configuration for CMPC
    Uint32 CMPD:1;                            // 4 Global load event configuration for CMPD
    Uint32 DBRED_DBREDHR:1;                   // 5 Global load event configuration for DBRED:DBREDHR
    Uint32 DBFED_DBFEDHR:1;                   // 6 Global load event configuration for DBFED:DBFEDHR
    Uint32 DBCTL:1;                           // 7 Global load event configuration for DBCTL
    Uint32 AQCTLA_AQCTLA2:1;                  // 8 Global load event configuration for AQCTLA/A2
    Uint32 AQCTLB_AQCTLB2:1;                  // 9 Global load event configuration for AQCTLB/B2
    Uint32 AQCSFRC:1;                         // 10 Global load event configuration for AQCSFRC
    Uint32 rsvd1:21;                          // 31:11 Reserved
};

union GLDCFG_REG {
    Uint32  all;
    struct  GLDCFG_BITS  bit;
};

struct EPWMXLINK_BITS {                       // bits description
    Uint32 TBPRDLINK:4;                       // 3:0 TBPRD:TBPRDHR Link
    Uint32 CMPALINK:4;                        // 7:4 CMPA:CMPAHR Link
    Uint32 CMPBLINK:4;                        // 11:8 CMPB:CMPBHR Link
    Uint32 CMPCLINK:4;                        // 15:12 CMPC Link
    Uint32 CMPDLINK:4;                        // 19:16 CMPD Link
    Uint32 rsvd1:8;                           // 27:20 Reserved
    Uint32 GLDCTL2LINK:4;                     // 31:28 GLDCTL2 Link
};

union EPWMXLINK_REG {
    Uint32  all;
    struct  EPWMXLINK_BITS  bit;
};

struct AQCTLA_BITS {                          // bits description
    Uint32 ZRO:2;                             // 1:0 Action Counter = Zero
    Uint32 PRD:2;                             // 3:2 Action Counter = Period
    Uint32 CAU:2;                             // 5:4 Action Counter = Compare A Up
    Uint32 CAD:2;                             // 7:6 Action Counter = Compare A Down
    Uint32 CBU:2;                             // 9:8 Action Counter = Compare B Up
    Uint32 CBD:2;                             // 11:10 Action Counter = Compare B Down
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union AQCTLA_REG {
    Uint32  all;
    struct  AQCTLA_BITS  bit;
};

struct AQCTLA2_BITS {                         // bits description
    Uint32 T1U:2;                             // 1:0 Action when event occurs on T1 in UP-Count
    Uint32 T1D:2;                             // 3:2 Action when event occurs on T1 in DOWN-Count
    Uint32 T2U:2;                             // 5:4 Action when event occurs on T2 in UP-Count
    Uint32 T2D:2;                             // 7:6 Action when event occurs on T2 in DOWN-Count
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union AQCTLA2_REG {
    Uint32  all;
    struct  AQCTLA2_BITS  bit;
};

struct AQCTLB_BITS {                          // bits description
    Uint32 ZRO:2;                             // 1:0 Action Counter = Zero
    Uint32 PRD:2;                             // 3:2 Action Counter = Period
    Uint32 CAU:2;                             // 5:4 Action Counter = Compare A Up
    Uint32 CAD:2;                             // 7:6 Action Counter = Compare A Down
    Uint32 CBU:2;                             // 9:8 Action Counter = Compare B Up
    Uint32 CBD:2;                             // 11:10 Action Counter = Compare B Down
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union AQCTLB_REG {
    Uint32  all;
    struct  AQCTLB_BITS  bit;
};

struct AQCTLB2_BITS {                         // bits description
    Uint32 T1U:2;                             // 1:0 Action when event occurs on T1 in UP-Count
    Uint32 T1D:2;                             // 3:2 Action when event occurs on T1 in DOWN-Count
    Uint32 T2U:2;                             // 5:4 Action when event occurs on T2 in UP-Count
    Uint32 T2D:2;                             // 7:6 Action when event occurs on T2 in DOWN-Count
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union AQCTLB2_REG {
    Uint32  all;
    struct  AQCTLB2_BITS  bit;
};

struct AQSFRC_BITS {                          // bits description
    Uint32 ACTSFA:2;                          // 1:0 Action when One-time SW Force A Invoked
    Uint32 OTSFA:1;                           // 2 One-time SW Force A Output
    Uint32 ACTSFB:2;                          // 4:3 Action when One-time SW Force B Invoked
    Uint32 OTSFB:1;                           // 5 One-time SW Force A Output
    Uint32 RLDCSF:2;                          // 7:6 Reload from Shadow Options
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union AQSFRC_REG {
    Uint32  all;
    struct  AQSFRC_BITS  bit;
};

struct AQCSFRC_BITS {                         // bits description
    Uint32 CSFA:2;                            // 1:0 Continuous Software Force on output A
    Uint32 CSFB:2;                            // 3:2 Continuous Software Force on output B
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union AQCSFRC_REG {
    Uint32  all;
    struct  AQCSFRC_BITS  bit;
};

struct DBREDHR_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:7;                           // 7:1 Reserved
    Uint32 rsvd3:1;                           // 8 Reserved
    Uint32 DBREDHR:7;                         // 15:9 DBREDHR High Resolution Bits
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DBREDHR_REG {
    Uint32  all;
    struct  DBREDHR_BITS  bit;
};

struct DBRED_BITS {                           // bits description
    Uint32 DBRED:14;                          // 13:0 Rising edge delay value
    Uint32 rsvd1:18;                          // 31:14 Reserved
};

union DBRED_REG {
    Uint32  all;
    struct  DBRED_BITS  bit;
};

struct DBFEDHR_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:7;                           // 7:1 Reserved
    Uint32 rsvd3:1;                           // 8 Reserved
    Uint32 DBFEDHR:7;                         // 15:9 DBFEDHR High Resolution Bits
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DBFEDHR_REG {
    Uint32  all;
    struct  DBFEDHR_BITS  bit;
};

struct DBFED_BITS {                           // bits description
    Uint32 DBFED:14;                          // 13:0 Falling edge delay value
    Uint32 rsvd1:18;                          // 31:14 Reserved
};

union DBFED_REG {
    Uint32  all;
    struct  DBFED_BITS  bit;
};

struct TBPHS_BITS {                           // bits description
    Uint32 TBPHSHR:16;                        // 15:0 Extension Register for HRPWM Phase (8-bits)
    Uint32 TBPHS:16;                          // 31:16 Phase Offset Register
};

union TBPHS_REG {
    Uint32  all;
    struct  TBPHS_BITS  bit;
};

struct CMPA_BITS {                            // bits description
    Uint32 CMPAHR:16;                         // 15:0 Compare A HRPWM Extension Register
    Uint32 CMPA:16;                           // 31:16 Compare A Register
};

union CMPA_REG {
    Uint32  all;
    struct  CMPA_BITS  bit;
};

struct CMPB_BITS {                            // bits description
    Uint32 CMPBHR:16;                         // 15:0 Compare B High Resolution Bits
    Uint32 CMPB:16;                           // 31:16 Compare B Register
};

union CMPB_REG {
    Uint32  all;
    struct  CMPB_BITS  bit;
};

struct GLDCTL2_BITS {                         // bits description
    Uint32 OSHTLD:1;                          // 0 Enable reload event in one shot mode
    Uint32 GFRCLD:1;                          // 1 Force reload event in one shot mode
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union GLDCTL2_REG {
    Uint32  all;
    struct  GLDCTL2_BITS  bit;
};

struct TZSEL_BITS {                           // bits description
    Uint32 CBC1:1;                            // 0 TZ1 CBC select
    Uint32 CBC2:1;                            // 1 TZ2 CBC select
    Uint32 CBC3:1;                            // 2 TZ3 CBC select
    Uint32 CBC4:1;                            // 3 TZ4 CBC select
    Uint32 CBC5:1;                            // 4 TZ5 CBC select
    Uint32 CBC6:1;                            // 5 TZ6 CBC select
    Uint32 DCAEVT2:1;                         // 6 DCAEVT2 CBC select
    Uint32 DCBEVT2:1;                         // 7 DCBEVT2 CBC select
    Uint32 OSHT1:1;                           // 8 One-shot TZ1 select
    Uint32 OSHT2:1;                           // 9 One-shot TZ2 select
    Uint32 OSHT3:1;                           // 10 One-shot TZ3 select
    Uint32 OSHT4:1;                           // 11 One-shot TZ4 select
    Uint32 OSHT5:1;                           // 12 One-shot TZ5 select
    Uint32 OSHT6:1;                           // 13 One-shot TZ6 select
    Uint32 DCAEVT1:1;                         // 14 One-shot DCAEVT1 select
    Uint32 DCBEVT1:1;                         // 15 One-shot DCBEVT1 select
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union TZSEL_REG {
    Uint32  all;
    struct  TZSEL_BITS  bit;
};

struct TZDCSEL_BITS {                         // bits description
    Uint32 DCAEVT1:3;                         // 2:0 Digital Compare Output A Event 1
    Uint32 DCAEVT2:3;                         // 5:3 Digital Compare Output A Event 2
    Uint32 DCBEVT1:3;                         // 8:6 Digital Compare Output B Event 1
    Uint32 DCBEVT2:3;                         // 11:9 Digital Compare Output B Event 2
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union TZDCSEL_REG {
    Uint32  all;
    struct  TZDCSEL_BITS  bit;
};

struct TZCTL_BITS {                           // bits description
    Uint32 TZA:2;                             // 1:0 TZ1 to TZ6 Trip Action On EPWMxA
    Uint32 TZB:2;                             // 3:2 TZ1 to TZ6 Trip Action On EPWMxB
    Uint32 DCAEVT1:2;                         // 5:4 EPWMxA action on DCAEVT1
    Uint32 DCAEVT2:2;                         // 7:6 EPWMxA action on DCAEVT2
    Uint32 DCBEVT1:2;                         // 9:8 EPWMxB action on DCBEVT1
    Uint32 DCBEVT2:2;                         // 11:10 EPWMxB action on DCBEVT2
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union TZCTL_REG {
    Uint32  all;
    struct  TZCTL_BITS  bit;
};

struct TZCTL2_BITS {                          // bits description
    Uint32 TZAU:3;                            // 2:0 Trip Action On EPWMxA while Count direction is UP
    Uint32 TZAD:3;                            // 5:3 Trip Action On EPWMxA while Count direction is DOWN
    Uint32 TZBU:3;                            // 8:6 Trip Action On EPWMxB while Count direction is UP
    Uint32 TZBD:3;                            // 11:9 Trip Action On EPWMxB while Count direction is DOWN
    Uint32 rsvd1:3;                           // 14:12 Reserved
    Uint32 ETZE:1;                            // 15 TZCTL2 Enable
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union TZCTL2_REG {
    Uint32  all;
    struct  TZCTL2_BITS  bit;
};

struct TZCTLDCA_BITS {                        // bits description
    Uint32 DCAEVT1U:3;                        // 2:0 DCAEVT1 Action On EPWMxA while Count direction is UP
    Uint32 DCAEVT1D:3;                        // 5:3 DCAEVT1 Action On EPWMxA while Count direction is DOWN
    Uint32 DCAEVT2U:3;                        // 8:6 DCAEVT2 Action On EPWMxA while Count direction is UP
    Uint32 DCAEVT2D:3;                        // 11:9 DCAEVT2 Action On EPWMxA while Count direction is DOWN
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union TZCTLDCA_REG {
    Uint32  all;
    struct  TZCTLDCA_BITS  bit;
};

struct TZCTLDCB_BITS {                        // bits description
    Uint32 DCBEVT1U:3;                        // 2:0 DCBEVT1 Action On EPWMxA while Count direction is UP
    Uint32 DCBEVT1D:3;                        // 5:3 DCBEVT1 Action On EPWMxA while Count direction is DOWN
    Uint32 DCBEVT2U:3;                        // 8:6 DCBEVT2 Action On EPWMxA while Count direction is UP
    Uint32 DCBEVT2D:3;                        // 11:9 DCBEVT2 Action On EPWMxA while Count direction is DOWN
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union TZCTLDCB_REG {
    Uint32  all;
    struct  TZCTLDCB_BITS  bit;
};

struct TZEINT_BITS {                          // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CBC:1;                             // 1 Trip Zones Cycle By Cycle Int Enable
    Uint32 OST:1;                             // 2 Trip Zones One Shot Int Enable
    Uint32 DCAEVT1:1;                         // 3 Digital Compare A Event 1 Int Enable
    Uint32 DCAEVT2:1;                         // 4 Digital Compare A Event 2 Int Enable
    Uint32 DCBEVT1:1;                         // 5 Digital Compare B Event 1 Int Enable
    Uint32 DCBEVT2:1;                         // 6 Digital Compare B Event 2 Int Enable
    Uint32 rsvd2:25;                          // 31:7 Reserved
};

union TZEINT_REG {
    Uint32  all;
    struct  TZEINT_BITS  bit;
};

struct TZFLG_BITS {                           // bits description
    Uint32 INT:1;                             // 0 Global Int Status Flag
    Uint32 CBC:1;                             // 1 Trip Zones Cycle By Cycle Flag
    Uint32 OST:1;                             // 2 Trip Zones One Shot Flag
    Uint32 DCAEVT1:1;                         // 3 Digital Compare A Event 1 Flag
    Uint32 DCAEVT2:1;                         // 4 Digital Compare A Event 2 Flag
    Uint32 DCBEVT1:1;                         // 5 Digital Compare B Event 1 Flag
    Uint32 DCBEVT2:1;                         // 6 Digital Compare B Event 2 Flag
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union TZFLG_REG {
    Uint32  all;
    struct  TZFLG_BITS  bit;
};

struct TZCBCFLG_BITS {                        // bits description
    Uint32 CBC1:1;                            // 0 Latched Status Flag for CBC1 Trip Latch
    Uint32 CBC2:1;                            // 1 Latched Status Flag for CBC2 Trip Latch
    Uint32 CBC3:1;                            // 2 Latched Status Flag for CBC3 Trip Latch
    Uint32 CBC4:1;                            // 3 Latched Status Flag for CBC4 Trip Latch
    Uint32 CBC5:1;                            // 4 Latched Status Flag for CBC5 Trip Latch
    Uint32 CBC6:1;                            // 5 Latched Status Flag for CBC6 Trip Latch
    Uint32 DCAEVT2:1;                         // 6 Latched Status Flag for Digital Compare Output A Event 2
    Uint32 DCBEVT2:1;                         // 7 Latched Status Flag for Digital Compare Output B Event 2
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union TZCBCFLG_REG {
    Uint32  all;
    struct  TZCBCFLG_BITS  bit;
};

struct TZOSTFLG_BITS {                        // bits description
    Uint32 OST1:1;                            // 0 Latched Status Flag for OST1 Trip Latch
    Uint32 OST2:1;                            // 1 Latched Status Flag for OST2 Trip Latch
    Uint32 OST3:1;                            // 2 Latched Status Flag for OST3 Trip Latch
    Uint32 OST4:1;                            // 3 Latched Status Flag for OST4 Trip Latch
    Uint32 OST5:1;                            // 4 Latched Status Flag for OST5 Trip Latch
    Uint32 OST6:1;                            // 5 Latched Status Flag for OST6 Trip Latch
    Uint32 DCAEVT1:1;                         // 6 Latched Status Flag for Digital Compare Output A Event 1
    Uint32 DCBEVT1:1;                         // 7 Latched Status Flag for Digital Compare Output B Event 1
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union TZOSTFLG_REG {
    Uint32  all;
    struct  TZOSTFLG_BITS  bit;
};

struct TZCLR_BITS {                           // bits description
    Uint32 INT:1;                             // 0 Global Interrupt Clear Flag
    Uint32 CBC:1;                             // 1 Cycle-By-Cycle Flag Clear
    Uint32 OST:1;                             // 2 One-Shot Flag Clear
    Uint32 DCAEVT1:1;                         // 3 DCAVET1 Flag Clear
    Uint32 DCAEVT2:1;                         // 4 DCAEVT2 Flag Clear
    Uint32 DCBEVT1:1;                         // 5 DCBEVT1 Flag Clear
    Uint32 DCBEVT2:1;                         // 6 DCBEVT2 Flag Clear
    Uint32 rsvd1:7;                           // 13:7 Reserved
    Uint32 CBCPULSE:2;                        // 15:14 Clear Pulse for CBC Trip Latch
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union TZCLR_REG {
    Uint32  all;
    struct  TZCLR_BITS  bit;
};

struct TZCBCCLR_BITS {                        // bits description
    Uint32 CBC1:1;                            // 0 Clear Flag for Cycle-By-Cycle (CBC1) Trip Latch
    Uint32 CBC2:1;                            // 1 Clear Flag for Cycle-By-Cycle (CBC2) Trip Latch
    Uint32 CBC3:1;                            // 2 Clear Flag for Cycle-By-Cycle (CBC3) Trip Latch
    Uint32 CBC4:1;                            // 3 Clear Flag for Cycle-By-Cycle (CBC4) Trip Latch
    Uint32 CBC5:1;                            // 4 Clear Flag for Cycle-By-Cycle (CBC5) Trip Latch
    Uint32 CBC6:1;                            // 5 Clear Flag for Cycle-By-Cycle (CBC6) Trip Latch
    Uint32 DCAEVT2:1;                         // 6 Clear Flag forDCAEVT2 selected for CBC
    Uint32 DCBEVT2:1;                         // 7 Clear Flag for DCBEVT2 selected for CBC
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union TZCBCCLR_REG {
    Uint32  all;
    struct  TZCBCCLR_BITS  bit;
};

struct TZOSTCLR_BITS {                        // bits description
    Uint32 OST1:1;                            // 0 Clear Flag for Oneshot (OST1) Trip Latch
    Uint32 OST2:1;                            // 1 Clear Flag for Oneshot (OST2) Trip Latch
    Uint32 OST3:1;                            // 2 Clear Flag for Oneshot (OST3) Trip Latch
    Uint32 OST4:1;                            // 3 Clear Flag for Oneshot (OST4) Trip Latch
    Uint32 OST5:1;                            // 4 Clear Flag for Oneshot (OST5) Trip Latch
    Uint32 OST6:1;                            // 5 Clear Flag for Oneshot (OST6) Trip Latch
    Uint32 DCAEVT1:1;                         // 6 Clear Flag for DCAEVT1 selected for OST
    Uint32 DCBEVT1:1;                         // 7 Clear Flag for DCBEVT1 selected for OST
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union TZOSTCLR_REG {
    Uint32  all;
    struct  TZOSTCLR_BITS  bit;
};

struct TZFRC_BITS {                           // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CBC:1;                             // 1 Force Trip Zones Cycle By Cycle Event
    Uint32 OST:1;                             // 2 Force Trip Zones One Shot Event
    Uint32 DCAEVT1:1;                         // 3 Force Digital Compare A Event 1
    Uint32 DCAEVT2:1;                         // 4 Force Digital Compare A Event 2
    Uint32 DCBEVT1:1;                         // 5 Force Digital Compare B Event 1
    Uint32 DCBEVT2:1;                         // 6 Force Digital Compare B Event 2
    Uint32 rsvd2:25;                          // 31:7 Reserved
};

union TZFRC_REG {
    Uint32  all;
    struct  TZFRC_BITS  bit;
};

struct ETSEL_BITS {                           // bits description
    Uint32 INTSEL:3;                          // 2:0 EPWMxINTn Select
    Uint32 INTEN:1;                           // 3 EPWMxINTn Enable
    Uint32 SOCASELCMP:1;                      // 4 EPWMxSOCA Compare Select
    Uint32 SOCBSELCMP:1;                      // 5 EPWMxSOCB Compare Select
    Uint32 INTSELCMP:1;                       // 6 EPWMxINT Compare Select
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 SOCASEL:3;                         // 10:8 Start of Conversion A Select
    Uint32 SOCAEN:1;                          // 11 Start of Conversion A Enable
    Uint32 SOCBSEL:3;                         // 14:12 Start of Conversion B Select
    Uint32 SOCBEN:1;                          // 15 Start of Conversion B Enable
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ETSEL_REG {
    Uint32  all;
    struct  ETSEL_BITS  bit;
};

struct ETPS_BITS {                            // bits description
    Uint32 INTPRD:2;                          // 1:0 EPWMxINTn Period Select
    Uint32 INTCNT:2;                          // 3:2 EPWMxINTn Counter Register
    Uint32 INTPSSEL:1;                        // 4 EPWMxINTn Pre-Scale Selection Bits
    Uint32 SOCPSSEL:1;                        // 5 EPWMxSOC A/B Pre-Scale Selection Bits
    Uint32 rsvd1:2;                           // 7:6 Reserved
    Uint32 SOCAPRD:2;                         // 9:8 EPWMxSOCA Period Select
    Uint32 SOCACNT:2;                         // 11:10 EPWMxSOCA Counter Register
    Uint32 SOCBPRD:2;                         // 13:12 EPWMxSOCB Period Select
    Uint32 SOCBCNT:2;                         // 15:14 EPWMxSOCB Counter
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ETPS_REG {
    Uint32  all;
    struct  ETPS_BITS  bit;
};

struct ETFLG_BITS {                           // bits description
    Uint32 INT:1;                             // 0 EPWMxINTn Flag
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 SOCA:1;                            // 2 EPWMxSOCA Flag
    Uint32 SOCB:1;                            // 3 EPWMxSOCB Flag
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union ETFLG_REG {
    Uint32  all;
    struct  ETFLG_BITS  bit;
};

struct ETCLR_BITS {                           // bits description
    Uint32 INT:1;                             // 0 EPWMxINTn Clear
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 SOCA:1;                            // 2 EPWMxSOCA Clear
    Uint32 SOCB:1;                            // 3 EPWMxSOCB Clear
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union ETCLR_REG {
    Uint32  all;
    struct  ETCLR_BITS  bit;
};

struct ETFRC_BITS {                           // bits description
    Uint32 INT:1;                             // 0 EPWMxINTn Force
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 SOCA:1;                            // 2 EPWMxSOCA Force
    Uint32 SOCB:1;                            // 3 EPWMxSOCB Force
    Uint32 rsvd2:28;                          // 31:4 Reserved
};

union ETFRC_REG {
    Uint32  all;
    struct  ETFRC_BITS  bit;
};

struct ETINTPS_BITS {                         // bits description
    Uint32 INTPRD2:4;                         // 3:0 EPWMxINTn Period Select
    Uint32 INTCNT2:4;                         // 7:4 EPWMxINTn Counter Register
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union ETINTPS_REG {
    Uint32  all;
    struct  ETINTPS_BITS  bit;
};

struct ETSOCPS_BITS {                         // bits description
    Uint32 SOCAPRD2:4;                        // 3:0 EPWMxSOCA Period Select
    Uint32 SOCACNT2:4;                        // 7:4 EPWMxSOCA Counter Register
    Uint32 SOCBPRD2:4;                        // 11:8 EPWMxSOCB Period Select
    Uint32 SOCBCNT2:4;                        // 15:12 EPWMxSOCB Counter Register
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ETSOCPS_REG {
    Uint32  all;
    struct  ETSOCPS_BITS  bit;
};

struct ETCNTINITCTL_BITS {                    // bits description
    Uint32 rsvd1:10;                          // 9:0 Reserved
    Uint32 INTINITFRC:1;                      // 10 EPWMxINT Counter Initialization Force
    Uint32 SOCAINITFRC:1;                     // 11 EPWMxSOCA Counter Initialization Force
    Uint32 SOCBINITFRC:1;                     // 12 EPWMxSOCB Counter Initialization Force
    Uint32 INTINITEN:1;                       // 13 EPWMxINT Counter Initialization Enable
    Uint32 SOCAINITEN:1;                      // 14 EPWMxSOCA Counter Initialization Enable
    Uint32 SOCBINITEN:1;                      // 15 EPWMxSOCB Counter Initialization Enable
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ETCNTINITCTL_REG {
    Uint32  all;
    struct  ETCNTINITCTL_BITS  bit;
};

struct ETCNTINIT_BITS {                       // bits description
    Uint32 INTINIT:4;                         // 3:0 EPWMxINT Counter Initialization Bits
    Uint32 SOCAINIT:4;                        // 7:4 EPWMxSOCA Counter Initialization Bits
    Uint32 SOCBINIT:4;                        // 11:8 EPWMxSOCB Counter Initialization Bits
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ETCNTINIT_REG {
    Uint32  all;
    struct  ETCNTINIT_BITS  bit;
};

struct DCTRIPSEL_BITS {                       // bits description
    Uint32 DCAHCOMPSEL:4;                     // 3:0 Digital Compare A High COMP Input Select
    Uint32 DCALCOMPSEL:4;                     // 7:4 Digital Compare A Low COMP Input Select
    Uint32 DCBHCOMPSEL:4;                     // 11:8 Digital Compare B High COMP Input Select
    Uint32 DCBLCOMPSEL:4;                     // 15:12 Digital Compare B Low COMP Input Select
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DCTRIPSEL_REG {
    Uint32  all;
    struct  DCTRIPSEL_BITS  bit;
};

struct DCACTL_BITS {                          // bits description
    Uint32 EVT1SRCSEL:1;                      // 0 DCAEVT1 Source Signal
    Uint32 EVT1FRCSYNCSEL:1;                  // 1 DCAEVT1 Force Sync Signal
    Uint32 EVT1SOCE:1;                        // 2 DCAEVT1 SOC Enable
    Uint32 EVT1SYNCE:1;                       // 3 DCAEVT1 SYNC Enable
    Uint32 EVT1LATSEL:1;                      // 4 DCAEVT1 Latched signal select
    Uint32 EVT1LATCLRSEL:2;                   // 6:5 DCAEVT1 Latched clear source select
    Uint32 EVT1LAT:1;                         // 7 Indicates the status of DCAEVT1LAT signal.
    Uint32 EVT2SRCSEL:1;                      // 8 DCAEVT2 Source Signal
    Uint32 EVT2FRCSYNCSEL:1;                  // 9 DCAEVT2 Force Sync Signal
    Uint32 rsvd1:2;                           // 11:10 Reserved
    Uint32 EVT2LATSEL:1;                      // 12 DCAEVT2 Latched signal select
    Uint32 EVT2LATCLRSEL:2;                   // 14:13 DCAEVT2 Latched clear source select
    Uint32 EVT2LAT:1;                         // 15 Indicates the status of DCAEVT2LAT signal.
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCACTL_REG {
    Uint32  all;
    struct  DCACTL_BITS  bit;
};

struct DCBCTL_BITS {                          // bits description
    Uint32 EVT1SRCSEL:1;                      // 0 DCBEVT1 Source Signal
    Uint32 EVT1FRCSYNCSEL:1;                  // 1 DCBEVT1 Force Sync Signal
    Uint32 EVT1SOCE:1;                        // 2 DCBEVT1 SOC Enable
    Uint32 EVT1SYNCE:1;                       // 3 DCBEVT1 SYNC Enable
    Uint32 EVT1LATSEL:1;                      // 4 DCBEVT1 Latched signal select
    Uint32 EVT1LATCLRSEL:2;                   // 6:5 DCBEVT1 Latched clear source select
    Uint32 EVT1LAT:1;                         // 7 Indicates the status of DCBEVT1LAT signal.
    Uint32 EVT2SRCSEL:1;                      // 8 DCBEVT2 Source Signal
    Uint32 EVT2FRCSYNCSEL:1;                  // 9 DCBEVT2 Force Sync Signal
    Uint32 rsvd1:2;                           // 11:10 Reserved
    Uint32 EVT2LATSEL:1;                      // 12 DCBEVT2 Latched signal select
    Uint32 EVT2LATCLRSEL:2;                   // 14:13 DCBEVT2 Latched clear source select
    Uint32 EVT2LAT:1;                         // 15 Indicates the status of DCBEVT2LAT signal.
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCBCTL_REG {
    Uint32  all;
    struct  DCBCTL_BITS  bit;
};

struct DCFCTL_BITS {                          // bits description
    Uint32 SRCSEL:2;                          // 1:0 Filter Block Signal Source Select
    Uint32 BLANKE:1;                          // 2 Blanking Enable/Disable
    Uint32 BLANKINV:1;                        // 3 Blanking Window Inversion
    Uint32 PULSESEL:2;                        // 5:4 Pulse Select for Blanking & Capture Alignment
    Uint32 EDGEFILTSEL:1;                     // 6 Edge Filter Select
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 EDGEMODE:2;                        // 9:8 Edge Mode
    Uint32 EDGECOUNT:3;                       // 12:10 Edge Count
    Uint32 EDGESTATUS:3;                      // 15:13 Edge Status
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCFCTL_REG {
    Uint32  all;
    struct  DCFCTL_BITS  bit;
};

struct DCCAPCTL_BITS {                        // bits description
    Uint32 CAPE:1;                            // 0 Counter Capture Enable
    Uint32 SHDWMODE:1;                        // 1 Counter Capture Mode
    Uint32 rsvd1:11;                          // 12:2 Reserved
    Uint32 CAPSTS:1;                          // 13 Latched Status Flag for Capture Event
    Uint32 CAPCLR:1;                          // 14 DC Capture Latched Status Clear Flag
    Uint32 CAPMODE:1;                         // 15 Counter Capture Mode
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DCCAPCTL_REG {
    Uint32  all;
    struct  DCCAPCTL_BITS  bit;
};

struct DCAHTRIPSEL_BITS {                     // bits description
    Uint32 TRIPINPUT1:1;                      // 0 Trip Input 1 Select to DCAH Mux
    Uint32 TRIPINPUT2:1;                      // 1 Trip Input 2 Select to DCAH Mux
    Uint32 TRIPINPUT3:1;                      // 2 Trip Input 3 Select to DCAH Mux
    Uint32 TRIPINPUT4:1;                      // 3 Trip Input 4 Select to DCAH Mux
    Uint32 TRIPINPUT5:1;                      // 4 Trip Input 5 Select to DCAH Mux
    Uint32 TRIPINPUT6:1;                      // 5 Trip Input 6 Select to DCAH Mux
    Uint32 TRIPINPUT7:1;                      // 6 Trip Input 7 Select to DCAH Mux
    Uint32 TRIPINPUT8:1;                      // 7 Trip Input 8 Select to DCAH Mux
    Uint32 TRIPINPUT9:1;                      // 8 Trip Input 9 Select to DCAH Mux
    Uint32 TRIPINPUT10:1;                     // 9 Trip Input 10 Select to DCAH Mux
    Uint32 TRIPINPUT11:1;                     // 10 Trip Input 11 Select to DCAH Mux
    Uint32 TRIPINPUT12:1;                     // 11 Trip Input 12 Select to DCAH Mux
    Uint32 rsvd1:1;                           // 12 Reserved
    Uint32 TRIPINPUT14:1;                     // 13 Trip Input 14 Select to DCAH Mux
    Uint32 TRIPINPUT15:1;                     // 14 Trip Input 15 Select to DCAH Mux
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union DCAHTRIPSEL_REG {
    Uint32  all;
    struct  DCAHTRIPSEL_BITS  bit;
};

struct DCALTRIPSEL_BITS {                     // bits description
    Uint32 TRIPINPUT1:1;                      // 0 Trip Input 1 Select to DCAL Mux
    Uint32 TRIPINPUT2:1;                      // 1 Trip Input 2 Select to DCAL Mux
    Uint32 TRIPINPUT3:1;                      // 2 Trip Input 3 Select to DCAL Mux
    Uint32 TRIPINPUT4:1;                      // 3 Trip Input 4 Select to DCAL Mux
    Uint32 TRIPINPUT5:1;                      // 4 Trip Input 5 Select to DCAL Mux
    Uint32 TRIPINPUT6:1;                      // 5 Trip Input 6 Select to DCAL Mux
    Uint32 TRIPINPUT7:1;                      // 6 Trip Input 7 Select to DCAL Mux
    Uint32 TRIPINPUT8:1;                      // 7 Trip Input 8 Select to DCAL Mux
    Uint32 TRIPINPUT9:1;                      // 8 Trip Input 9 Select to DCAL Mux
    Uint32 TRIPINPUT10:1;                     // 9 Trip Input 10 Select to DCAL Mux
    Uint32 TRIPINPUT11:1;                     // 10 Trip Input 11 Select to DCAL Mux
    Uint32 TRIPINPUT12:1;                     // 11 Trip Input 12 Select to DCAL Mux
    Uint32 rsvd1:1;                           // 12 Reserved
    Uint32 TRIPINPUT14:1;                     // 13 Trip Input 14 Select to DCAL Mux
    Uint32 TRIPINPUT15:1;                     // 14 Trip Input 15 Select to DCAL Mux
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union DCALTRIPSEL_REG {
    Uint32  all;
    struct  DCALTRIPSEL_BITS  bit;
};

struct DCBHTRIPSEL_BITS {                     // bits description
    Uint32 TRIPINPUT1:1;                      // 0 Trip Input 1 Select to DCBH Mux
    Uint32 TRIPINPUT2:1;                      // 1 Trip Input 2 Select to DCBH Mux
    Uint32 TRIPINPUT3:1;                      // 2 Trip Input 3 Select to DCBH Mux
    Uint32 TRIPINPUT4:1;                      // 3 Trip Input 4 Select to DCBH Mux
    Uint32 TRIPINPUT5:1;                      // 4 Trip Input 5 Select to DCBH Mux
    Uint32 TRIPINPUT6:1;                      // 5 Trip Input 6 Select to DCBH Mux
    Uint32 TRIPINPUT7:1;                      // 6 Trip Input 7 Select to DCBH Mux
    Uint32 TRIPINPUT8:1;                      // 7 Trip Input 8 Select to DCBH Mux
    Uint32 TRIPINPUT9:1;                      // 8 Trip Input 9 Select to DCBH Mux
    Uint32 TRIPINPUT10:1;                     // 9 Trip Input 10 Select to DCBH Mux
    Uint32 TRIPINPUT11:1;                     // 10 Trip Input 11 Select to DCBH Mux
    Uint32 TRIPINPUT12:1;                     // 11 Trip Input 12 Select to DCBH Mux
    Uint32 rsvd1:1;                           // 12 Reserved
    Uint32 TRIPINPUT14:1;                     // 13 Trip Input 14 Select to DCBH Mux
    Uint32 TRIPINPUT15:1;                     // 14 Trip Input 15 Select to DCBH Mux
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union DCBHTRIPSEL_REG {
    Uint32  all;
    struct  DCBHTRIPSEL_BITS  bit;
};

struct DCBLTRIPSEL_BITS {                     // bits description
    Uint32 TRIPINPUT1:1;                      // 0 Trip Input 1 Select to DCBL Mux
    Uint32 TRIPINPUT2:1;                      // 1 Trip Input 2 Select to DCBL Mux
    Uint32 TRIPINPUT3:1;                      // 2 Trip Input 3 Select to DCBL Mux
    Uint32 TRIPINPUT4:1;                      // 3 Trip Input 4 Select to DCBL Mux
    Uint32 TRIPINPUT5:1;                      // 4 Trip Input 5 Select to DCBL Mux
    Uint32 TRIPINPUT6:1;                      // 5 Trip Input 6 Select to DCBL Mux
    Uint32 TRIPINPUT7:1;                      // 6 Trip Input 7 Select to DCBL Mux
    Uint32 TRIPINPUT8:1;                      // 7 Trip Input 8 Select to DCBL Mux
    Uint32 TRIPINPUT9:1;                      // 8 Trip Input 9 Select to DCBL Mux
    Uint32 TRIPINPUT10:1;                     // 9 Trip Input 10 Select to DCBL Mux
    Uint32 TRIPINPUT11:1;                     // 10 Trip Input 11 Select to DCBL Mux
    Uint32 TRIPINPUT12:1;                     // 11 Trip Input 12 Select to DCBL Mux
    Uint32 rsvd1:1;                           // 12 Reserved
    Uint32 TRIPINPUT14:1;                     // 13 Trip Input 14 Select to DCBL Mux
    Uint32 TRIPINPUT15:1;                     // 14 Trip Input 15 Select to DCBL Mux
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union DCBLTRIPSEL_REG {
    Uint32  all;
    struct  DCBLTRIPSEL_BITS  bit;
};

struct EPWMLOCK_BITS {                        // bits description
    Uint32 HRLOCK:1;                          // 0 HRPWM Register Set Lock
    Uint32 GLLOCK:1;                          // 1 Global Load Register Set Lock
    Uint32 TZCFGLOCK:1;                       // 2 TripZone Register Set Lock
    Uint32 TZCLRLOCK:1;                       // 3 TripZone Clear Register Set Lock
    Uint32 DCLOCK:1;                          // 4 Digital Compare Register Set Lock
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 KEY:16;                            // 31:16 Key to write to this register
};

union EPWMLOCK_REG {
    Uint32  all;
    struct  EPWMLOCK_BITS  bit;
};

struct  EPWM_REGS {
    union   TBCTL_REG                        TBCTL;                       // 0x0 Time Base Control Register
    union   TBCTL2_REG                       TBCTL2;                      // 0x4 Time Base Control Register 2
    Uint32                                   rsvd1;                       // 0x8 Reserved
    union   EPWMSYNCINSEL_REG                EPWMSYNCINSEL;               // 0xc EPWMxSYNCIN Source Select Register
    Uint32                                   TBCTR;                       // 0x10 Time Base Counter Register
    union   TBSTS_REG                        TBSTS;                       // 0x14 Time Base Status Register
    union   EPWMSYNCOUTEN_REG                EPWMSYNCOUTEN;               // 0x18 EPWMxSYNCOUT Source Enable Register
    union   TBCTL3_REG                       TBCTL3;                      // 0x1c Time Base Control Register 3
    union   CMPCTL_REG                       CMPCTL;                      // 0x20 Counter Compare Control Register
    union   CMPCTL2_REG                      CMPCTL2;                     // 0x24 Counter Compare Control Register 2
    Uint32                                   rsvd2[2];                    // 0x28 Reserved
    union   DBCTL_REG                        DBCTL;                       // 0x30 Dead-Band Generator Control Register
    union   DBCTL2_REG                       DBCTL2;                      // 0x34 Dead-Band Generator Control Register 2
    Uint32                                   rsvd3[2];                    // 0x38 Reserved
    union   AQCTL_REG                        AQCTL;                       // 0x40 Action Qualifier Control Register
    union   AQTSRCSEL_REG                    AQTSRCSEL;                   // 0x44 Action Qualifier Trigger Event Source Select Register
    Uint32                                   rsvd4[2];                    // 0x48 Reserved
    union   PCCTL_REG                        PCCTL;                       // 0x50 PWM Chopper Control Register
    Uint32                                   rsvd5[3];                    // 0x54 Reserved
    union   VCAPCTL_REG                      VCAPCTL;                     // 0x60 Valley Capture Control Register
    union   VCNTCFG_REG                      VCNTCFG;                     // 0x64 Valley Counter Config Register
    Uint32                                   rsvd6[6];                    // 0x68 Reserved
    union   HRCNFG_REG                       HRCNFG;                      // 0x80 HRPWM Configuration Register
    union   HRPWR_REG                        HRPWR;                       // 0x84 HRPWM Power Register
    Uint32                                   rsvd7[4];                    // 0x88 Reserved
    union   HRMSTEP_REG                      HRMSTEP;                     // 0x98 HRPWM MEP Step Register
    union   HRCNFG2_REG                      HRCNFG2;                     // 0x9c HRPWM Configuration 2 Register
    Uint32                                   rsvd8[5];                    // 0xa0 Reserved
    union   HRPCTL_REG                       HRPCTL;                      // 0xb4 High Resolution Period Control Register
    union   TRREM_REG                        TRREM;                       // 0xb8 HRPWM High Resolution Remainder Register
    Uint32                                   rsvd9[5];                    // 0xbc Reserved
    union   GLDCTL_REG                       GLDCTL;                      // 0xd0 Global PWM Load Control Register
    union   GLDCFG_REG                       GLDCFG;                      // 0xd4 Global PWM Load Config Register
    Uint32                                   rsvd10[2];                   // 0xd8 Reserved
    union   EPWMXLINK_REG                    EPWMXLINK;                   // 0xe0 EPWMx Link Register
    Uint32                                   rsvd11[7];                   // 0xe4 Reserved
    union   AQCTLA_REG                       AQCTLA;                      // 0x100 Action Qualifier Control Register For Output A
    union   AQCTLA2_REG                      AQCTLA2;                     // 0x104 Additional Action Qualifier Control Register For Output A
    union   AQCTLB_REG                       AQCTLB;                      // 0x108 Action Qualifier Control Register For Output B
    union   AQCTLB2_REG                      AQCTLB2;                     // 0x10c Additional Action Qualifier Control Register For Output B
    Uint32                                   rsvd12[3];                   // 0x110 Reserved
    union   AQSFRC_REG                       AQSFRC;                      // 0x11c Action Qualifier Software Force Register
    Uint32                                   rsvd13;                      // 0x120 Reserved
    union   AQCSFRC_REG                      AQCSFRC;                     // 0x124 Action Qualifier Continuous S/W Force Register
    Uint32                                   rsvd14[6];                   // 0x128 Reserved
    union   DBREDHR_REG                      DBREDHR;                     // 0x140 Dead-Band Generator Rising Edge Delay High Resolution Mirror Register
    union   DBRED_REG                        DBRED;                       // 0x144 Dead-Band Generator Rising Edge Delay High Resolution Mirror Register
    union   DBFEDHR_REG                      DBFEDHR;                     // 0x148 Dead-Band Generator Falling Edge Delay High Resolution Register
    union   DBFED_REG                        DBFED;                       // 0x14c Dead-Band Generator Falling Edge Delay Count Register
    Uint32                                   rsvd15[12];                  // 0x150 Reserved
    union   TBPHS_REG                        TBPHS;                       // 0x180 Time Base Phase High
    Uint32                                   rsvd16;                      // 0x184 Reserved
    Uint32                                   TBPRDHR;                     // 0x188 Time Base Period High Resolution Register
    Uint32                                   TBPRD;                       // 0x18c Time Base Period Register
    Uint32                                   rsvd17[6];                   // 0x190 Reserved
    union   CMPA_REG                         CMPA;                        // 0x1a8 Counter Compare A Register
    Uint32                                   rsvd18;                      // 0x1ac Reserved
    union   CMPB_REG                         CMPB;                        // 0x1b0 Compare B Register
    Uint32                                   rsvd19[2];                   // 0x1b4 Reserved
    Uint32                                   CMPC;                        // 0x1bc Counter Compare C Register
    Uint32                                   rsvd20;                      // 0x1c0 Reserved
    Uint32                                   CMPD;                        // 0x1c4 Counter Compare D Register
    Uint32                                   rsvd21[2];                   // 0x1c8 Reserved
    union   GLDCTL2_REG                      GLDCTL2;                     // 0x1d0 Global PWM Load Control Register 2
    Uint32                                   rsvd22[2];                   // 0x1d4 Reserved
    Uint32                                   SWVDELVAL;                   // 0x1dc Software Valley Mode Delay Register
    Uint32                                   rsvd23[8];                   // 0x1e0 Reserved
    union   TZSEL_REG                        TZSEL;                       // 0x200 Trip Zone Select Register
    Uint32                                   rsvd24;                      // 0x204 Reserved
    union   TZDCSEL_REG                      TZDCSEL;                     // 0x208 Trip Zone Digital Comparator Select Register
    Uint32                                   rsvd25;                      // 0x20c Reserved
    union   TZCTL_REG                        TZCTL;                       // 0x210 Trip Zone Control Register
    union   TZCTL2_REG                       TZCTL2;                      // 0x214 Additional Trip Zone Control Register
    union   TZCTLDCA_REG                     TZCTLDCA;                    // 0x218 Trip Zone Control Register Digital Compare A
    union   TZCTLDCB_REG                     TZCTLDCB;                    // 0x21c Trip Zone Control Register Digital Compare B
    Uint32                                   rsvd26[5];                   // 0x220 Reserved
    union   TZEINT_REG                       TZEINT;                      // 0x234 Trip Zone Enable Interrupt Register
    Uint32                                   rsvd27[5];                   // 0x238 Reserved
    union   TZFLG_REG                        TZFLG;                       // 0x24c Trip Zone Flag Register
    union   TZCBCFLG_REG                     TZCBCFLG;                    // 0x250 Trip Zone CBC Flag Register
    union   TZOSTFLG_REG                     TZOSTFLG;                    // 0x254 Trip Zone OST Flag Register
    Uint32                                   rsvd28;                      // 0x258 Reserved
    union   TZCLR_REG                        TZCLR;                       // 0x25c Trip Zone Clear Register
    union   TZCBCCLR_REG                     TZCBCCLR;                    // 0x260 Trip Zone CBC Clear Register
    union   TZOSTCLR_REG                     TZOSTCLR;                    // 0x264 Trip Zone OST Clear Register
    Uint32                                   rsvd29;                      // 0x268 Reserved
    union   TZFRC_REG                        TZFRC;                       // 0x26c Trip Zone Force Register
    Uint32                                   rsvd30[8];                   // 0x270 Reserved
    union   ETSEL_REG                        ETSEL;                       // 0x290 Event Trigger Selection Register
    Uint32                                   rsvd31;                      // 0x294 Reserved
    union   ETPS_REG                         ETPS;                        // 0x298 Event Trigger Pre-Scale Register
    Uint32                                   rsvd32;                      // 0x29c Reserved
    union   ETFLG_REG                        ETFLG;                       // 0x2a0 Event Trigger Flag Register
    Uint32                                   rsvd33;                      // 0x2a4 Reserved
    union   ETCLR_REG                        ETCLR;                       // 0x2a8 Event Trigger Clear Register
    Uint32                                   rsvd34;                      // 0x2ac Reserved
    union   ETFRC_REG                        ETFRC;                       // 0x2b0 Event Trigger Force Register
    Uint32                                   rsvd35;                      // 0x2b4 Reserved
    union   ETINTPS_REG                      ETINTPS;                     // 0x2b8 Event-Trigger Interrupt Pre-Scale Register
    Uint32                                   rsvd36;                      // 0x2bc Reserved
    union   ETSOCPS_REG                      ETSOCPS;                     // 0x2c0 Event-Trigger SOC Pre-Scale Register
    Uint32                                   rsvd37;                      // 0x2c4 Reserved
    union   ETCNTINITCTL_REG                 ETCNTINITCTL;                // 0x2c8 Event-Trigger Counter Initialization Control Register
    Uint32                                   rsvd38;                      // 0x2cc Reserved
    union   ETCNTINIT_REG                    ETCNTINIT;                   // 0x2d0 Event-Trigger Counter Initialization Register
    Uint32                                   rsvd39[11];                  // 0x2d4 Reserved
    union   DCTRIPSEL_REG                    DCTRIPSEL;                   // 0x300 Digital Compare Trip Select Register
    Uint32                                   rsvd40[2];                   // 0x304 Reserved
    union   DCACTL_REG                       DCACTL;                      // 0x30c Digital Compare A Control Register
    union   DCBCTL_REG                       DCBCTL;                      // 0x310 Digital Compare B Control Register
    Uint32                                   rsvd41[2];                   // 0x314 Reserved
    union   DCFCTL_REG                       DCFCTL;                      // 0x31c Digital Compare Filter Control Register
    union   DCCAPCTL_REG                     DCCAPCTL;                    // 0x320 Digital Compare Capture Control Register
    Uint32                                   DCFOFFSET;                   // 0x324 Digital Compare Filter Offset Register
    Uint32                                   DCFOFFSETCNT;                // 0x328 Digital Compare Filter Offset Counter Register
    Uint32                                   DCFWINDOW;                   // 0x32c Digital Compare Filter Window Register
    Uint32                                   DCFWINDOWCNT;                // 0x330 Digital Compare Filter Window Counter Register
    Uint32                                   rsvd42[2];                   // 0x334 Reserved
    Uint32                                   DCCAP;                       // 0x33c Digital Compare Counter Capture Register
    Uint32                                   rsvd43[2];                   // 0x340 Reserved
    union   DCAHTRIPSEL_REG                  DCAHTRIPSEL;                 // 0x348 Digital Compare AH Trip Select
    union   DCALTRIPSEL_REG                  DCALTRIPSEL;                 // 0x34c Digital Compare AL Trip Select
    union   DCBHTRIPSEL_REG                  DCBHTRIPSEL;                 // 0x350 Digital Compare BH Trip Select
    union   DCBLTRIPSEL_REG                  DCBLTRIPSEL;                 // 0x354 Digital Compare BL Trip Select
    Uint32                                   rsvd44[36];                  // 0x358 Reserved
    union   EPWMLOCK_REG                     EPWMLOCK;                    // 0x3e8 EPWM Lock Register
    Uint32                                   rsvd45[2];                   // 0x3ec Reserved
    Uint32                                   HWVDELVAL;                   // 0x3f4 Hardware Valley Mode Delay Register
    Uint32                                   VCNTVAL;                     // 0x3f8 Hardware Valley Counter Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================