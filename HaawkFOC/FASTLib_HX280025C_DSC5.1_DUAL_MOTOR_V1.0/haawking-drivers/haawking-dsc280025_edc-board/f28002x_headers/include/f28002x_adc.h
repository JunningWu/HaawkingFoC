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
// Release for HXS320F280025CEDC, Bitfield DriverLib, 1.0.0
//
// Release time: 2024-02-06 14:28:52.107326
//
//#############################################################################


#ifndef F28002X_ADC_H
#define F28002X_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCCTL1_BITS {                         // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 INTPULSEPOS:1;                     // 2 ADC Interrupt Pulse Position
    Uint32 rsvd2:4;                           // 6:3 Reserved
    Uint32 ADCPWDNZ:1;                        // 7 ADC Power Down
    Uint32 ADCBSYCHN:4;                       // 11:8 ADC Busy Channel
    Uint32 rsvd3:1;                           // 12 Reserved
    Uint32 ADCBSY:1;                          // 13 ADC Busy
    Uint32 rsvd4:1;                           // 14 Reserved
    Uint32 PGADIS:1;                          // 15 PGA Gain Enable
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union ADCCTL1_REG {
    Uint32  all;
    struct  ADCCTL1_BITS  bit;
};

struct ADCCTL2_BITS {                         // bits description
    Uint32 PRESCALE:4;                        // 3:0 ADC Clock Prescaler
    Uint32 DISH:1;                            // 4 Perform Calibration
    Uint32 SDIF:1;                            // 5  
    Uint32 GCMP:1;                            // 6 IP Comes With Comparison Gain
    Uint32 OFFSET:6;                          // 12:7 IP With Offset Calibration
    Uint32 IPP5UCAL:3;                        // 15:13 Current Calibration Value
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCCTL2_REG {
    Uint32  all;
    struct  ADCCTL2_BITS  bit;
};

struct ADCBURSTCTL_BITS {                     // bits description
    Uint32 BURSTTRIGSEL:6;                    // 5:0 SOC Burst Trigger Source Select
    Uint32 rsvd1:2;                           // 7:6 Reserved
    Uint32 BURSTSIZE:4;                       // 11:8 SOC Burst Size Select
    Uint32 rsvd2:3;                           // 14:12 Reserved
    Uint32 BURSTEN:1;                         // 15 SOC Burst Mode Enable
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ADCBURSTCTL_REG {
    Uint32  all;
    struct  ADCBURSTCTL_BITS  bit;
};

struct ADCINTFLG_BITS {                       // bits description
    Uint32 ADCINT1:1;                         // 0 ADC Interrupt 1 Flag
    Uint32 ADCINT2:1;                         // 1 ADC Interrupt 2 Flag
    Uint32 ADCINT3:1;                         // 2 ADC Interrupt 3 Flag
    Uint32 ADCINT4:1;                         // 3 ADC Interrupt 4 Flag
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union ADCINTFLG_REG {
    Uint32  all;
    struct  ADCINTFLG_BITS  bit;
};

struct ADCINTFLGCLR_BITS {                    // bits description
    Uint32 ADCINT1:1;                         // 0 ADC Interrupt 1 Flag Clear
    Uint32 ADCINT2:1;                         // 1 ADC Interrupt 2 Flag Clear
    Uint32 ADCINT3:1;                         // 2 ADC Interrupt 3 Flag Clear
    Uint32 ADCINT4:1;                         // 3 ADC Interrupt 4 Flag Clear
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union ADCINTFLGCLR_REG {
    Uint32  all;
};

struct ADCINTOVF_BITS {                       // bits description
    Uint32 ADCINT1:1;                         // 0 ADC Interrupt 1 Overflow Flags
    Uint32 ADCINT2:1;                         // 1 ADC Interrupt 2 Overflow Flags
    Uint32 ADCINT3:1;                         // 2 ADC Interrupt 3 Overflow Flags
    Uint32 ADCINT4:1;                         // 3 ADC Interrupt 4 Overflow Flags
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union ADCINTOVF_REG {
    Uint32  all;
    struct  ADCINTOVF_BITS  bit;
};

struct ADCINTOVFCLR_BITS {                    // bits description
    Uint32 ADCINT1:1;                         // 0 ADC Interrupt 1 Overflow Clear Bits
    Uint32 ADCINT2:1;                         // 1 ADC Interrupt 2 Overflow Clear Bits
    Uint32 ADCINT3:1;                         // 2 ADC Interrupt 3 Overflow Clear Bits
    Uint32 ADCINT4:1;                         // 3 ADC Interrupt 4 Overflow Clear Bits
    Uint32 rsvd1:28;                          // 31:4 Reserved
};

union ADCINTOVFCLR_REG {
    Uint32  all;
};

struct ADCINTSEL1N2_BITS {                    // bits description
    Uint32 INT1SEL:4;                         // 3:0 ADCINT1 EOC Source Select
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 INT1E:1;                           // 5 ADCINT1 Interrupt Enable
    Uint32 INT1CONT:1;                        // 6 ADCINT1 Continue to Interrupt Mode
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 INT2SEL:4;                         // 11:8 ADCINT2 EOC Source Select
    Uint32 rsvd3:1;                           // 12 Reserved
    Uint32 INT2E:1;                           // 13 ADCINT2 Interrupt Enable
    Uint32 INT2CONT:1;                        // 14 ADCINT2 Continue to Interrupt Mode
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCINTSEL1N2_REG {
    Uint32  all;
    struct  ADCINTSEL1N2_BITS  bit;
};

struct ADCINTSEL3N4_BITS {                    // bits description
    Uint32 INT3SEL:4;                         // 3:0 ADCINT3 EOC Source Select
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 INT3E:1;                           // 5 ADCINT3 Interrupt Enable
    Uint32 INT3CONT:1;                        // 6 ADCINT3 Continue to Interrupt Mode
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 INT4SEL:4;                         // 11:8 ADCINT4 EOC Source Select
    Uint32 rsvd3:1;                           // 12 Reserved
    Uint32 INT4E:1;                           // 13 ADCINT4 Interrupt Enable
    Uint32 INT4CONT:1;                        // 14 ADCINT4 Continue to Interrupt Mode
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCINTSEL3N4_REG {
    Uint32  all;
    struct  ADCINTSEL3N4_BITS  bit;
};

struct ADCSOCPRICTL_BITS {                    // bits description
    Uint32 SOCPRIORITY:5;                     // 4:0 SOC Priority
    Uint32 RRPOINTER:5;                       // 9:5 Round Robin Pointer
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union ADCSOCPRICTL_REG {
    Uint32  all;
    struct  ADCSOCPRICTL_BITS  bit;
};

struct ADCINTSOCSEL1_BITS {                   // bits description
    Uint32 SOC0:2;                            // 1:0 SOC0 ADC Interrupt Trigger Select
    Uint32 SOC1:2;                            // 3:2 SOC1 ADC Interrupt Trigger Select
    Uint32 SOC2:2;                            // 5:4 SOC2 ADC Interrupt Trigger Select
    Uint32 SOC3:2;                            // 7:6 SOC3 ADC Interrupt Trigger Select
    Uint32 SOC4:2;                            // 9:8 SOC4 ADC Interrupt Trigger Select
    Uint32 SOC5:2;                            // 11:10 SOC5 ADC Interrupt Trigger Select
    Uint32 SOC6:2;                            // 13:12 SOC6 ADC Interrupt Trigger Select
    Uint32 SOC7:2;                            // 15:14 SOC7 ADC Interrupt Trigger Select
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCINTSOCSEL1_REG {
    Uint32  all;
    struct  ADCINTSOCSEL1_BITS  bit;
};

struct ADCINTSOCSEL2_BITS {                   // bits description
    Uint32 SOC8:2;                            // 1:0 SOC8 ADC Interrupt Trigger Select
    Uint32 SOC9:2;                            // 3:2 SOC9 ADC Interrupt Trigger Select
    Uint32 SOC10:2;                           // 5:4 SOC10 ADC Interrupt Trigger Select
    Uint32 SOC11:2;                           // 7:6 SOC11 ADC Interrupt Trigger Select
    Uint32 SOC12:2;                           // 9:8 SOC12 ADC Interrupt Trigger Select
    Uint32 SOC13:2;                           // 11:10 SOC13 ADC Interrupt Trigger Select
    Uint32 SOC14:2;                           // 13:12 SOC14 ADC Interrupt Trigger Select
    Uint32 SOC15:2;                           // 15:14 SOC15 ADC Interrupt Trigger Select
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCINTSOCSEL2_REG {
    Uint32  all;
    struct  ADCINTSOCSEL2_BITS  bit;
};

struct ADCSOCFLG1_BITS {                      // bits description
    Uint32 SOC0:1;                            // 0 SOC0 Start of Conversion Flag
    Uint32 SOC1:1;                            // 1 SOC1 Start of Conversion Flag
    Uint32 SOC2:1;                            // 2 SOC2 Start of Conversion Flag
    Uint32 SOC3:1;                            // 3 SOC3 Start of Conversion Flag
    Uint32 SOC4:1;                            // 4 SOC4 Start of Conversion Flag
    Uint32 SOC5:1;                            // 5 SOC5 Start of Conversion Flag
    Uint32 SOC6:1;                            // 6 SOC6 Start of Conversion Flag
    Uint32 SOC7:1;                            // 7 SOC7 Start of Conversion Flag
    Uint32 SOC8:1;                            // 8 SOC8 Start of Conversion Flag
    Uint32 SOC9:1;                            // 9 SOC9 Start of Conversion Flag
    Uint32 SOC10:1;                           // 10 SOC10 Start of Conversion Flag
    Uint32 SOC11:1;                           // 11 SOC11 Start of Conversion Flag
    Uint32 SOC12:1;                           // 12 SOC12 Start of Conversion Flag
    Uint32 SOC13:1;                           // 13 SOC13 Start of Conversion Flag
    Uint32 SOC14:1;                           // 14 SOC14 Start of Conversion Flag
    Uint32 SOC15:1;                           // 15 SOC15 Start of Conversion Flag
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCSOCFLG1_REG {
    Uint32  all;
    struct  ADCSOCFLG1_BITS  bit;
};

struct ADCSOCFRC1_BITS {                      // bits description
    Uint32 SOC0:1;                            // 0 SOC0 Force Start of Conversion Bit
    Uint32 SOC1:1;                            // 1 SOC1 Force Start of Conversion Bit
    Uint32 SOC2:1;                            // 2 SOC2 Force Start of Conversion Bit
    Uint32 SOC3:1;                            // 3 SOC3 Force Start of Conversion Bit
    Uint32 SOC4:1;                            // 4 SOC4 Force Start of Conversion Bit
    Uint32 SOC5:1;                            // 5 SOC5 Force Start of Conversion Bit
    Uint32 SOC6:1;                            // 6 SOC6 Force Start of Conversion Bit
    Uint32 SOC7:1;                            // 7 SOC7 Force Start of Conversion Bit
    Uint32 SOC8:1;                            // 8 SOC8 Force Start of Conversion Bit
    Uint32 SOC9:1;                            // 9 SOC9 Force Start of Conversion Bit
    Uint32 SOC10:1;                           // 10 SOC10 Force Start of Conversion Bit
    Uint32 SOC11:1;                           // 11 SOC11 Force Start of Conversion Bit
    Uint32 SOC12:1;                           // 12 SOC12 Force Start of Conversion Bit
    Uint32 SOC13:1;                           // 13 SOC13 Force Start of Conversion Bit
    Uint32 SOC14:1;                           // 14 SOC14 Force Start of Conversion Bit
    Uint32 SOC15:1;                           // 15 SOC15 Force Start of Conversion Bit
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCSOCFRC1_REG {
    Uint32  all;
};

struct ADCSOCOVF1_BITS {                      // bits description
    Uint32 SOC0:1;                            // 0 SOC0 Start of Conversion Overflow Flag
    Uint32 SOC1:1;                            // 1 SOC1 Start of Conversion Overflow Flag
    Uint32 SOC2:1;                            // 2 SOC2 Start of Conversion Overflow Flag
    Uint32 SOC3:1;                            // 3 SOC3 Start of Conversion Overflow Flag
    Uint32 SOC4:1;                            // 4 SOC4 Start of Conversion Overflow Flag
    Uint32 SOC5:1;                            // 5 SOC5 Start of Conversion Overflow Flag
    Uint32 SOC6:1;                            // 6 SOC6 Start of Conversion Overflow Flag
    Uint32 SOC7:1;                            // 7 SOC7 Start of Conversion Overflow Flag
    Uint32 SOC8:1;                            // 8 SOC8 Start of Conversion Overflow Flag
    Uint32 SOC9:1;                            // 9 SOC9 Start of Conversion Overflow Flag
    Uint32 SOC10:1;                           // 10 SOC10 Start of Conversion Overflow Flag
    Uint32 SOC11:1;                           // 11 SOC11 Start of Conversion Overflow Flag
    Uint32 SOC12:1;                           // 12 SOC12 Start of Conversion Overflow Flag
    Uint32 SOC13:1;                           // 13 SOC13 Start of Conversion Overflow Flag
    Uint32 SOC14:1;                           // 14 SOC14 Start of Conversion Overflow Flag
    Uint32 SOC15:1;                           // 15 SOC15 Start of Conversion Overflow Flag
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCSOCOVF1_REG {
    Uint32  all;
    struct  ADCSOCOVF1_BITS  bit;
};

struct ADCSOCOVFCLR1_BITS {                   // bits description
    Uint32 SOC0:1;                            // 0 SOC0 Clear Start of Conversion Overflow Bit
    Uint32 SOC1:1;                            // 1 SOC1 Clear Start of Conversion Overflow Bit
    Uint32 SOC2:1;                            // 2 SOC2 Clear Start of Conversion Overflow Bit
    Uint32 SOC3:1;                            // 3 SOC3 Clear Start of Conversion Overflow Bit
    Uint32 SOC4:1;                            // 4 SOC4 Clear Start of Conversion Overflow Bit
    Uint32 SOC5:1;                            // 5 SOC5 Clear Start of Conversion Overflow Bit
    Uint32 SOC6:1;                            // 6 SOC6 Clear Start of Conversion Overflow Bit
    Uint32 SOC7:1;                            // 7 SOC7 Clear Start of Conversion Overflow Bit
    Uint32 SOC8:1;                            // 8 SOC8 Clear Start of Conversion Overflow Bit
    Uint32 SOC9:1;                            // 9 SOC9 Clear Start of Conversion Overflow Bit
    Uint32 SOC10:1;                           // 10 SOC10 Clear Start of Conversion Overflow Bit
    Uint32 SOC11:1;                           // 11 SOC11 Clear Start of Conversion Overflow Bit
    Uint32 SOC12:1;                           // 12 SOC12 Clear Start of Conversion Overflow Bit
    Uint32 SOC13:1;                           // 13 SOC13 Clear Start of Conversion Overflow Bit
    Uint32 SOC14:1;                           // 14 SOC14 Clear Start of Conversion Overflow Bit
    Uint32 SOC15:1;                           // 15 SOC15 Clear Start of Conversion Overflow Bit
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCSOCOVFCLR1_REG {
    Uint32  all;
};

struct ADCSOC0CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC0 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC0 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC0 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC0CTL_REG {
    Uint32  all;
    struct  ADCSOC0CTL_BITS  bit;
};

struct ADCSOC1CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC1 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC1 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC1 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC1CTL_REG {
    Uint32  all;
    struct  ADCSOC1CTL_BITS  bit;
};

struct ADCSOC2CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC2 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC2 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC2 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC2CTL_REG {
    Uint32  all;
    struct  ADCSOC2CTL_BITS  bit;
};

struct ADCSOC3CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC3 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC3 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC3 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC3CTL_REG {
    Uint32  all;
    struct  ADCSOC3CTL_BITS  bit;
};

struct ADCSOC4CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC4 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC4 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC4 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC4CTL_REG {
    Uint32  all;
    struct  ADCSOC4CTL_BITS  bit;
};

struct ADCSOC5CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC5 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC5 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC5 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC5CTL_REG {
    Uint32  all;
    struct  ADCSOC5CTL_BITS  bit;
};

struct ADCSOC6CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC6 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC6 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC6 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC6CTL_REG {
    Uint32  all;
    struct  ADCSOC6CTL_BITS  bit;
};

struct ADCSOC7CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC7 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC7 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC7 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC7CTL_REG {
    Uint32  all;
    struct  ADCSOC7CTL_BITS  bit;
};

struct ADCSOC8CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC8 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC8 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC8 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC8CTL_REG {
    Uint32  all;
    struct  ADCSOC8CTL_BITS  bit;
};

struct ADCSOC9CTL_BITS {                      // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC9 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC9 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC9 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC9CTL_REG {
    Uint32  all;
    struct  ADCSOC9CTL_BITS  bit;
};

struct ADCSOC10CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC10 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC10 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC10 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC10CTL_REG {
    Uint32  all;
    struct  ADCSOC10CTL_BITS  bit;
};

struct ADCSOC11CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC11 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC11 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC11 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC11CTL_REG {
    Uint32  all;
    struct  ADCSOC11CTL_BITS  bit;
};

struct ADCSOC12CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC12 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC12 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC12 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC12CTL_REG {
    Uint32  all;
    struct  ADCSOC12CTL_BITS  bit;
};

struct ADCSOC13CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC13 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC13 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC13 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC13CTL_REG {
    Uint32  all;
    struct  ADCSOC13CTL_BITS  bit;
};

struct ADCSOC14CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC14 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC14 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC14 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC14CTL_REG {
    Uint32  all;
    struct  ADCSOC14CTL_BITS  bit;
};

struct ADCSOC15CTL_BITS {                     // bits description
    Uint32 ACQPS:9;                           // 8:0 SOC15 Acquisition Prescale
    Uint32 rsvd1:6;                           // 14:9 Reserved
    Uint32 CHSEL:5;                           // 19:15 SOC15 Channel Select
    Uint32 TRIGSEL:5;                         // 24:20 SOC15 Trigger Source Select
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union ADCSOC15CTL_REG {
    Uint32  all;
    struct  ADCSOC15CTL_BITS  bit;
};

struct ADCEVTSTAT_BITS {                      // bits description
    Uint32 PPB1TRIPHI:1;                      // 0 Post Processing Block 1 Trip High Flag
    Uint32 PPB1TRIPLO:1;                      // 1 Post Processing Block 1 Trip Low Flag
    Uint32 PPB1ZERO:1;                        // 2 Post Processing Block 1 Zero Crossing Flag
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 PPB2TRIPHI:1;                      // 4 Post Processing Block 2 Trip High Flag
    Uint32 PPB2TRIPLO:1;                      // 5 Post Processing Block 2 Trip Low Flag
    Uint32 PPB2ZERO:1;                        // 6 Post Processing Block 2 Zero Crossing Flag
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 PPB3TRIPHI:1;                      // 8 Post Processing Block 3 Trip High Flag
    Uint32 PPB3TRIPLO:1;                      // 9 Post Processing Block 3 Trip Low Flag
    Uint32 PPB3ZERO:1;                        // 10 Post Processing Block 3 Zero Crossing Flag
    Uint32 rsvd3:1;                           // 11 Reserved
    Uint32 PPB4TRIPHI:1;                      // 12 Post Processing Block 4 Trip High Flag
    Uint32 PPB4TRIPLO:1;                      // 13 Post Processing Block 4 Trip Low Flag
    Uint32 PPB4ZERO:1;                        // 14 Post Processing Block 4 Zero Crossing Flag
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCEVTSTAT_REG {
    Uint32  all;
    struct  ADCEVTSTAT_BITS  bit;
};

struct ADCEVTCLR_BITS {                       // bits description
    Uint32 PPB1TRIPHI:1;                      // 0 Post Processing Block 1 Trip High Clear
    Uint32 PPB1TRIPLO:1;                      // 1 Post Processing Block 1 Trip Low Clear
    Uint32 PPB1ZERO:1;                        // 2 Post Processing Block 1 Zero Crossing Clear
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 PPB2TRIPHI:1;                      // 4 Post Processing Block 2 Trip High Clear
    Uint32 PPB2TRIPLO:1;                      // 5 Post Processing Block 2 Trip Low Clear
    Uint32 PPB2ZERO:1;                        // 6 Post Processing Block 2 Zero Crossing Clear
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 PPB3TRIPHI:1;                      // 8 Post Processing Block 3 Trip High Clear
    Uint32 PPB3TRIPLO:1;                      // 9 Post Processing Block 3 Trip Low Clear
    Uint32 PPB3ZERO:1;                        // 10 Post Processing Block 3 Zero Crossing Clear
    Uint32 rsvd3:1;                           // 11 Reserved
    Uint32 PPB4TRIPHI:1;                      // 12 Post Processing Block 4 Trip High Clear
    Uint32 PPB4TRIPLO:1;                      // 13 Post Processing Block 4 Trip Low Clear
    Uint32 PPB4ZERO:1;                        // 14 Post Processing Block 4 Zero Crossing Clear
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCEVTCLR_REG {
    Uint32  all;
    struct  ADCEVTCLR_BITS  bit;
};

struct ADCEVTSEL_BITS {                       // bits description
    Uint32 PPB1TRIPHI:1;                      // 0 Post Processing Block 1 Trip High Event Enable
    Uint32 PPB1TRIPLO:1;                      // 1 Post Processing Block 1 Trip Low Event Enable
    Uint32 PPB1ZERO:1;                        // 2 Post Processing Block 1 Zero Crossing Event Enable
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 PPB2TRIPHI:1;                      // 4 Post Processing Block 2 Trip High Event Enable
    Uint32 PPB2TRIPLO:1;                      // 5 Post Processing Block 2 Trip Low Event Enable
    Uint32 PPB2ZERO:1;                        // 6 Post Processing Block 2 Zero Crossing Event Enable
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 PPB3TRIPHI:1;                      // 8 Post Processing Block 3 Trip High Event Enable
    Uint32 PPB3TRIPLO:1;                      // 9 Post Processing Block 3 Trip Low Event Enable
    Uint32 PPB3ZERO:1;                        // 10 Post Processing Block 3 Zero Crossing Event Enable
    Uint32 rsvd3:1;                           // 11 Reserved
    Uint32 PPB4TRIPHI:1;                      // 12 Post Processing Block 4 Trip High Event Enable
    Uint32 PPB4TRIPLO:1;                      // 13 Post Processing Block 4 Trip Low Event Enable
    Uint32 PPB4ZERO:1;                        // 14 Post Processing Block 4 Zero Crossing Event Enable
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCEVTSEL_REG {
    Uint32  all;
    struct  ADCEVTSEL_BITS  bit;
};

struct ADCEVTINTSEL_BITS {                    // bits description
    Uint32 PPB1TRIPHI:1;                      // 0 Post Processing Block 1 Trip High Interrupt Enable
    Uint32 PPB1TRIPLO:1;                      // 1 Post Processing Block 1 Trip Low Interrupt Enable
    Uint32 PPB1ZERO:1;                        // 2 Post Processing Block 1 Zero Crossing Interrupt Enable
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 PPB2TRIPHI:1;                      // 4 Post Processing Block 2 Trip High Interrupt Enable
    Uint32 PPB2TRIPLO:1;                      // 5 Post Processing Block 2 Trip Low Interrupt Enable
    Uint32 PPB2ZERO:1;                        // 6 Post Processing Block 2 Zero Crossing Interrupt Enable
    Uint32 rsvd2:1;                           // 7 Reserved
    Uint32 PPB3TRIPHI:1;                      // 8 Post Processing Block 3 Trip High Interrupt Enable
    Uint32 PPB3TRIPLO:1;                      // 9 Post Processing Block 3 Trip Low Interrupt Enable
    Uint32 PPB3ZERO:1;                        // 10 Post Processing Block 3 Zero Crossing Interrupt Enable
    Uint32 rsvd3:1;                           // 11 Reserved
    Uint32 PPB4TRIPHI:1;                      // 12 Post Processing Block 4 Trip High Interrupt Enable
    Uint32 PPB4TRIPLO:1;                      // 13 Post Processing Block 4 Trip Low Interrupt Enable
    Uint32 PPB4ZERO:1;                        // 14 Post Processing Block 4 Zero Crossing Interrupt Enable
    Uint32 rsvd4:17;                          // 31:15 Reserved
};

union ADCEVTINTSEL_REG {
    Uint32  all;
    struct  ADCEVTINTSEL_BITS  bit;
};

struct ADCOSDETECT_BITS {                     // bits description
    Uint32 DETECTCFG:3;                       // 2:0 ADC Opens and Shorts Detect Configuration
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union ADCOSDETECT_REG {
    Uint32  all;
    struct  ADCOSDETECT_BITS  bit;
};

struct ADCCOUNTER_BITS {                      // bits description
    Uint32 FREECOUNT:12;                      // 11:0 ADC Free Running Counter Value
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ADCCOUNTER_REG {
    Uint32  all;
    struct  ADCCOUNTER_BITS  bit;
};

struct ADCREV_BITS {                          // bits description
    Uint32 TYPE:8;                            // 7:0 ADC Type
    Uint32 REV:8;                             // 15:8 ADC Revision
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union ADCREV_REG {
    Uint32  all;
    struct  ADCREV_BITS  bit;
};

struct ADCOFFTRIM_BITS {                      // bits description
    Uint32 OFFTRIM:8;                         // 7:0 ADC Offset Trim
    Uint32 rsvd1:4;                           // 11:8 Reserved
    Uint32 rsvd2:20;                          // 31:12 Reserved
};

union ADCOFFTRIM_REG {
    Uint32  all;
    struct  ADCOFFTRIM_BITS  bit;
};

struct ADCPPB1CONFIG_BITS {                   // bits description
    Uint32 CONFIG:4;                          // 3:0 ADC Post Processing Block 1 Configuration
    Uint32 TWOSCOMPEN:1;                      // 4 ADC Post Processing Block 1 Two's Complement Enable
    Uint32 CBCEN:1;                           // 5 Cycle By Cycle Enable
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union ADCPPB1CONFIG_REG {
    Uint32  all;
    struct  ADCPPB1CONFIG_BITS  bit;
};

struct ADCPPB1STAMP_BITS {                    // bits description
    Uint32 DLYSTAMP:12;                       // 11:0 ADC Post Processing Block 1 Delay Time Stamp
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ADCPPB1STAMP_REG {
    Uint32  all;
    struct  ADCPPB1STAMP_BITS  bit;
};

struct ADCPPB1OFFCAL_BITS {                   // bits description
    Uint32 OFFCAL:10;                         // 9:0 ADC Post Processing Block Offset Correction
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union ADCPPB1OFFCAL_REG {
    Uint32  all;
    struct  ADCPPB1OFFCAL_BITS  bit;
};

struct ADCPPB1TRIPHI_BITS {                   // bits description
    Uint32 LIMITHI:16;                        // 15:0 ADC Post Processing Block 1 Trip High Limit
    Uint32 HSIGN:1;                           // 16 High Limit Sign Bit
    Uint32 rsvd1:15;                          // 31:17 Reserved
};

union ADCPPB1TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB1TRIPHI_BITS  bit;
};

struct ADCPPB1TRIPLO_BITS {                   // bits description
    Uint32 LIMITLO:16;                        // 15:0 ADC Post Processing Block 1 Trip Low Limit
    Uint32 LSIGN:1;                           // 16 Low Limit Sign Bit
    Uint32 rsvd1:3;                           // 19:17 Reserved
    Uint32 REQSTAMP:12;                       // 31:20 ADC Post Processing Block 1 Request Time Stamp
};

union ADCPPB1TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB1TRIPLO_BITS  bit;
};

struct ADCPPB2CONFIG_BITS {                   // bits description
    Uint32 CONFIG:4;                          // 3:0 ADC Post Processing Block 2 Configuration
    Uint32 TWOSCOMPEN:1;                      // 4 ADC Post Processing Block 2 Two's Complement Enable
    Uint32 CBCEN:1;                           // 5 Cycle By Cycle Enable
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union ADCPPB2CONFIG_REG {
    Uint32  all;
    struct  ADCPPB2CONFIG_BITS  bit;
};

struct ADCPPB2STAMP_BITS {                    // bits description
    Uint32 DLYSTAMP:12;                       // 11:0 ADC Post Processing Block 2 Delay Time Stamp
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ADCPPB2STAMP_REG {
    Uint32  all;
    struct  ADCPPB2STAMP_BITS  bit;
};

struct ADCPPB2OFFCAL_BITS {                   // bits description
    Uint32 OFFCAL:10;                         // 9:0 ADC Post Processing Block Offset Correction
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union ADCPPB2OFFCAL_REG {
    Uint32  all;
    struct  ADCPPB2OFFCAL_BITS  bit;
};

struct ADCPPB2TRIPHI_BITS {                   // bits description
    Uint32 LIMITHI:16;                        // 15:0 ADC Post Processing Block 2 Trip High Limit
    Uint32 HSIGN:1;                           // 16 High Limit Sign Bit
    Uint32 rsvd1:15;                          // 31:17 Reserved
};

union ADCPPB2TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB2TRIPHI_BITS  bit;
};

struct ADCPPB2TRIPLO_BITS {                   // bits description
    Uint32 LIMITLO:16;                        // 15:0 ADC Post Processing Block 2 Trip Low Limit
    Uint32 LSIGN:1;                           // 16 Low Limit Sign Bit
    Uint32 rsvd1:3;                           // 19:17 Reserved
    Uint32 REQSTAMP:12;                       // 31:20 ADC Post Processing Block 2 Request Time Stamp
};

union ADCPPB2TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB2TRIPLO_BITS  bit;
};

struct ADCPPB3CONFIG_BITS {                   // bits description
    Uint32 CONFIG:4;                          // 3:0 ADC Post Processing Block 3 Configuration
    Uint32 TWOSCOMPEN:1;                      // 4 ADC Post Processing Block 3 Two's Complement Enable
    Uint32 CBCEN:1;                           // 5 Cycle By Cycle Enable
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union ADCPPB3CONFIG_REG {
    Uint32  all;
    struct  ADCPPB3CONFIG_BITS  bit;
};

struct ADCPPB3STAMP_BITS {                    // bits description
    Uint32 DLYSTAMP:12;                       // 11:0 ADC Post Processing Block 3 Delay Time Stamp
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ADCPPB3STAMP_REG {
    Uint32  all;
    struct  ADCPPB3STAMP_BITS  bit;
};

struct ADCPPB3OFFCAL_BITS {                   // bits description
    Uint32 OFFCAL:10;                         // 9:0 ADC Post Processing Block Offset Correction
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union ADCPPB3OFFCAL_REG {
    Uint32  all;
    struct  ADCPPB3OFFCAL_BITS  bit;
};

struct ADCPPB3TRIPHI_BITS {                   // bits description
    Uint32 LIMITHI:16;                        // 15:0 ADC Post Processing Block 3 Trip High Limit
    Uint32 HSIGN:1;                           // 16 High Limit Sign Bit
    Uint32 rsvd1:15;                          // 31:17 Reserved
};

union ADCPPB3TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB3TRIPHI_BITS  bit;
};

struct ADCPPB3TRIPLO_BITS {                   // bits description
    Uint32 LIMITLO:16;                        // 15:0 ADC Post Processing Block 3 Trip Low Limit
    Uint32 LSIGN:1;                           // 16 Low Limit Sign Bit
    Uint32 rsvd1:3;                           // 19:17 Reserved
    Uint32 REQSTAMP:12;                       // 31:20 ADC Post Processing Block 3 Request Time Stamp
};

union ADCPPB3TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB3TRIPLO_BITS  bit;
};

struct ADCPPB4CONFIG_BITS {                   // bits description
    Uint32 CONFIG:4;                          // 3:0 ADC Post Processing Block 4 Configuration
    Uint32 TWOSCOMPEN:1;                      // 4 ADC Post Processing Block 4 Two's Complement Enable
    Uint32 CBCEN:1;                           // 5 Cycle By Cycle Enable
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union ADCPPB4CONFIG_REG {
    Uint32  all;
    struct  ADCPPB4CONFIG_BITS  bit;
};

struct ADCPPB4STAMP_BITS {                    // bits description
    Uint32 DLYSTAMP:12;                       // 11:0 ADC Post Processing Block 4 Delay Time Stamp
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union ADCPPB4STAMP_REG {
    Uint32  all;
    struct  ADCPPB4STAMP_BITS  bit;
};

struct ADCPPB4OFFCAL_BITS {                   // bits description
    Uint32 OFFCAL:10;                         // 9:0 ADC Post Processing Block Offset Correction
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union ADCPPB4OFFCAL_REG {
    Uint32  all;
    struct  ADCPPB4OFFCAL_BITS  bit;
};

struct ADCPPB4TRIPHI_BITS {                   // bits description
    Uint32 LIMITHI:16;                        // 15:0 ADC Post Processing Block 4 Trip High Limit
    Uint32 HSIGN:1;                           // 16 High Limit Sign Bit
    Uint32 rsvd1:15;                          // 31:17 Reserved
};

union ADCPPB4TRIPHI_REG {
    Uint32  all;
    struct  ADCPPB4TRIPHI_BITS  bit;
};

struct ADCPPB4TRIPLO_BITS {                   // bits description
    Uint32 LIMITLO:16;                        // 15:0 ADC Post Processing Block 4 Trip Low Limit
    Uint32 LSIGN:1;                           // 16 Low Limit Sign Bit
    Uint32 rsvd1:3;                           // 19:17 Reserved
    Uint32 REQSTAMP:12;                       // 31:20 ADC Post Processing Block 4 Request Time Stamp
};

union ADCPPB4TRIPLO_REG {
    Uint32  all;
    struct  ADCPPB4TRIPLO_BITS  bit;
};

struct  ADC_REGS {
    union   ADCCTL1_REG                      ADCCTL1;                     // 0x0 ADC Control 1 Register
    union   ADCCTL2_REG                      ADCCTL2;                     // 0x4 ADC Control 2 Register
    union   ADCBURSTCTL_REG                  ADCBURSTCTL;                 // 0x8 ADC Burst Control Register
    union   ADCINTFLG_REG                    ADCINTFLG;                   // 0xc ADC Interrupt Flag Register
    union   ADCINTFLGCLR_REG                 ADCINTFLGCLR;                // 0x10 ADC Interrupt Flag Clear Register
    union   ADCINTOVF_REG                    ADCINTOVF;                   // 0x14 ADC Interrupt Overflow Register
    union   ADCINTOVFCLR_REG                 ADCINTOVFCLR;                // 0x18 ADC Interrupt Overflow Clear Register
    union   ADCINTSEL1N2_REG                 ADCINTSEL1N2;                // 0x1c ADC Interrupt 1 and 2 Selection Register
    union   ADCINTSEL3N4_REG                 ADCINTSEL3N4;                // 0x20 ADC Interrupt 3 and 4 Selection Register
    union   ADCSOCPRICTL_REG                 ADCSOCPRICTL;                // 0x24 ADC SOC Priority Control Register
    union   ADCINTSOCSEL1_REG                ADCINTSOCSEL1;               // 0x28 ADC Interrupt SOC Selection 1 Register
    union   ADCINTSOCSEL2_REG                ADCINTSOCSEL2;               // 0x2c ADC Interrupt SOC Selection 2 Register
    union   ADCSOCFLG1_REG                   ADCSOCFLG1;                  // 0x30 ADC SOC Flag 1 Register
    union   ADCSOCFRC1_REG                   ADCSOCFRC1;                  // 0x34 ADC SOC Force 1 Register
    union   ADCSOCOVF1_REG                   ADCSOCOVF1;                  // 0x38 ADC SOC Overflow 1 Register
    union   ADCSOCOVFCLR1_REG                ADCSOCOVFCLR1;               // 0x3c ADC SOC Overflow Clear 1 Register
    union   ADCSOC0CTL_REG                   ADCSOC0CTL;                  // 0x40 ADC SOC0 Control Register
    union   ADCSOC1CTL_REG                   ADCSOC1CTL;                  // 0x44 ADC SOC1 Control Register
    union   ADCSOC2CTL_REG                   ADCSOC2CTL;                  // 0x48 ADC SOC2 Control Register
    union   ADCSOC3CTL_REG                   ADCSOC3CTL;                  // 0x4c ADC SOC3 Control Register
    union   ADCSOC4CTL_REG                   ADCSOC4CTL;                  // 0x50 ADC SOC4 Control Register
    union   ADCSOC5CTL_REG                   ADCSOC5CTL;                  // 0x54 ADC SOC5 Control Register
    union   ADCSOC6CTL_REG                   ADCSOC6CTL;                  // 0x58 ADC SOC6 Control Register
    union   ADCSOC7CTL_REG                   ADCSOC7CTL;                  // 0x5c ADC SOC7 Control Register
    union   ADCSOC8CTL_REG                   ADCSOC8CTL;                  // 0x60 ADC SOC8 Control Register
    union   ADCSOC9CTL_REG                   ADCSOC9CTL;                  // 0x64 ADC SOC9 Control Register
    union   ADCSOC10CTL_REG                  ADCSOC10CTL;                 // 0x68 ADC SOC10 Control Register
    union   ADCSOC11CTL_REG                  ADCSOC11CTL;                 // 0x6c ADC SOC11 Control Register
    union   ADCSOC12CTL_REG                  ADCSOC12CTL;                 // 0x70 ADC SOC12 Control Register
    union   ADCSOC13CTL_REG                  ADCSOC13CTL;                 // 0x74 ADC SOC13 Control Register
    union   ADCSOC14CTL_REG                  ADCSOC14CTL;                 // 0x78 ADC SOC14 Control Register
    union   ADCSOC15CTL_REG                  ADCSOC15CTL;                 // 0x7c ADC SOC15 Control Register
    union   ADCEVTSTAT_REG                   ADCEVTSTAT;                  // 0x80 ADC Event Status Register
    union   ADCEVTCLR_REG                    ADCEVTCLR;                   // 0x84 ADC Event Clear Register
    union   ADCEVTSEL_REG                    ADCEVTSEL;                   // 0x88 ADC Event Selection Register
    union   ADCEVTINTSEL_REG                 ADCEVTINTSEL;                // 0x8c ADC Event Interrupt Selection Register
    union   ADCOSDETECT_REG                  ADCOSDETECT;                 // 0x90 ADC Open and Shorts Detect Register
    union   ADCCOUNTER_REG                   ADCCOUNTER;                  // 0x94 ADC Counter Register
    union   ADCREV_REG                       ADCREV;                      // 0x98 ADC Revision Register
    union   ADCOFFTRIM_REG                   ADCOFFTRIM;                  // 0x9c ADC Offset Trim Register
    union   ADCPPB1CONFIG_REG                ADCPPB1CONFIG;               // 0xa0 ADC PPB1 Config Register
    union   ADCPPB1STAMP_REG                 ADCPPB1STAMP;                // 0xa4 ADC PPB1 Sample Delay Time Stamp Register
    union   ADCPPB1OFFCAL_REG                ADCPPB1OFFCAL;               // 0xa8 ADC PPB1 Offset Calibration Register
    Uint32                                   ADCPPB1OFFREF;               // 0xac ADC PPB1 Offset Reference Register
    union   ADCPPB1TRIPHI_REG                ADCPPB1TRIPHI;               // 0xb0 ADC PPB1 Trip High Register
    union   ADCPPB1TRIPLO_REG                ADCPPB1TRIPLO;               // 0xb4 ADC PPB1 Trip Low/Trigger Time Stamp Register
    union   ADCPPB2CONFIG_REG                ADCPPB2CONFIG;               // 0xb8 ADC PPB2 Config Register
    union   ADCPPB2STAMP_REG                 ADCPPB2STAMP;                // 0xbc ADC PPB2 Sample Delay Time Stamp Register
    union   ADCPPB2OFFCAL_REG                ADCPPB2OFFCAL;               // 0xc0 ADC PPB2 Offset Calibration Register
    Uint32                                   ADCPPB2OFFREF;               // 0xc4 ADC PPB2 Offset Reference Register
    union   ADCPPB2TRIPHI_REG                ADCPPB2TRIPHI;               // 0xc8 ADC PPB2 Trip High Register
    union   ADCPPB2TRIPLO_REG                ADCPPB2TRIPLO;               // 0xcc ADC PPB2 Trip Low/Trigger Time Stamp Register
    union   ADCPPB3CONFIG_REG                ADCPPB3CONFIG;               // 0xd0 ADC PPB3 Config Register
    union   ADCPPB3STAMP_REG                 ADCPPB3STAMP;                // 0xd4 ADC PPB3 Sample Delay Time Stamp Register
    union   ADCPPB3OFFCAL_REG                ADCPPB3OFFCAL;               // 0xd8 ADC PPB3 Offset Calibration Register
    Uint32                                   ADCPPB3OFFREF;               // 0xdc ADC PPB3 Offset Reference Register
    union   ADCPPB3TRIPHI_REG                ADCPPB3TRIPHI;               // 0xe0 ADC PPB3 Trip High Register
    union   ADCPPB3TRIPLO_REG                ADCPPB3TRIPLO;               // 0xe4 ADC PPB3 Trip Low/Trigger Time Stamp Register
    union   ADCPPB4CONFIG_REG                ADCPPB4CONFIG;               // 0xe8 ADC PPB4 Config Register
    union   ADCPPB4STAMP_REG                 ADCPPB4STAMP;                // 0xec ADC PPB4 Sample Delay Time Stamp Register
    union   ADCPPB4OFFCAL_REG                ADCPPB4OFFCAL;               // 0xf0 ADC PPB4 Offset Calibration Register
    Uint32                                   ADCPPB4OFFREF;               // 0xf4 ADC PPB4 Offset Reference Register
    union   ADCPPB4TRIPHI_REG                ADCPPB4TRIPHI;               // 0xf8 ADC PPB4 Trip High Register
    union   ADCPPB4TRIPLO_REG                ADCPPB4TRIPLO;               // 0xfc ADC PPB4 Trip Low/Trigger Time Stamp Register
    Uint32                                   ADCINTCYCLE;                 // 0x100 ADC Early Interrupt Generation Cycle
    Uint32                                   ADCINLTRIM1;                 // 0x104 ADC Linearity Trim 1 Register
    Uint32                                   ADCINLTRIM2;                 // 0x108 ADC Linearity Trim 2 Register
    Uint32                                   ADCINLTRIM3;                 // 0x10c ADC Linearity Trim 3 Register
};

struct ADCPPB1RESULT_BITS {                   // bits description
    Uint32 PPBRESULT:16;                      // 15:0 ADC Post Processing Block Result
    Uint32 SIGN:16;                           // 31:16 Sign Extended Bits
};

union ADCPPB1RESULT_REG {
    Uint32  all;
    struct  ADCPPB1RESULT_BITS  bit;
};

struct ADCPPB2RESULT_BITS {                   // bits description
    Uint32 PPBRESULT:16;                      // 15:0 ADC Post Processing Block Result
    Uint32 SIGN:16;                           // 31:16 Sign Extended Bits
};

union ADCPPB2RESULT_REG {
    Uint32  all;
    struct  ADCPPB2RESULT_BITS  bit;
};

struct ADCPPB3RESULT_BITS {                   // bits description
    Uint32 PPBRESULT:16;                      // 15:0 ADC Post Processing Block Result
    Uint32 SIGN:16;                           // 31:16 Sign Extended Bits
};

union ADCPPB3RESULT_REG {
    Uint32  all;
    struct  ADCPPB3RESULT_BITS  bit;
};

struct ADCPPB4RESULT_BITS {                   // bits description
    Uint32 PPBRESULT:16;                      // 15:0 ADC Post Processing Block Result
    Uint32 SIGN:16;                           // 31:16 Sign Extended Bits
};

union ADCPPB4RESULT_REG {
    Uint32  all;
    struct  ADCPPB4RESULT_BITS  bit;
};

struct  ADC_RESULT_REGS {
    Uint32                                   ADCRESULT0;                  // 0x0 ADC Result 0 Register
    Uint32                                   ADCRESULT1;                  // 0x4 ADC Result 1 Register
    Uint32                                   ADCRESULT2;                  // 0x8 ADC Result 2 Register
    Uint32                                   ADCRESULT3;                  // 0xc ADC Result 3 Register
    Uint32                                   ADCRESULT4;                  // 0x10 ADC Result 4 Register
    Uint32                                   ADCRESULT5;                  // 0x14 ADC Result 5 Register
    Uint32                                   ADCRESULT6;                  // 0x18 ADC Result 6 Register
    Uint32                                   ADCRESULT7;                  // 0x1c ADC Result 7 Register
    Uint32                                   ADCRESULT8;                  // 0x20 ADC Result 8 Register
    Uint32                                   ADCRESULT9;                  // 0x24 ADC Result 9 Register
    Uint32                                   ADCRESULT10;                 // 0x28 ADC Result 10 Register
    Uint32                                   ADCRESULT11;                 // 0x2c ADC Result 11 Register
    Uint32                                   ADCRESULT12;                 // 0x30 ADC Result 12 Register
    Uint32                                   ADCRESULT13;                 // 0x34 ADC Result 13 Register
    Uint32                                   ADCRESULT14;                 // 0x38 ADC Result 14 Register
    Uint32                                   ADCRESULT15;                 // 0x3c ADC Result 15 Register
    union   ADCPPB1RESULT_REG                ADCPPB1RESULT;               // 0x40 ADC Post Processing Block 1 Result Register
    union   ADCPPB2RESULT_REG                ADCPPB2RESULT;               // 0x44 ADC Post Processing Block 2 Result Register
    union   ADCPPB3RESULT_REG                ADCPPB3RESULT;               // 0x48 ADC Post Processing Block 3 Result Register
    union   ADCPPB4RESULT_REG                ADCPPB4RESULT;               // 0x4c ADC Post Processing Block 4 Result Register
};

struct ADCCTL3_BITS {                         // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 SEL_VREFBI:2;                      // 3:2 Built-in reference voltage selected
    Uint32 ADJVREFO:5;                        // 8:4 Built-Inreference voltage output control
    Uint32 rsvd2:7;                           // 15:9 Reserved
    Uint32 EN_TS:1;                           // 16 Temperature sensor enable signal, high active.
    Uint32 TTRIM:4;                           // 20:17 Built-Inreference voltage temperature ratio control
    Uint32 ALG_MEAN:2;                        // 22:21 Sampling points selection for mean algor
    Uint32 rsvd3:1;                           // 23 Reserved
    Uint32 ADJ_TD_OS:4;                       // 27:24 Temperature sensor offset adjustment signal
    Uint32 ADJ_TD_GA:4;                       // 31:28 Temperature sensor gain adjustment signal
};

union ADCCTL3_REG {
    Uint32  all;
    struct  ADCCTL3_BITS  bit;
};

struct  ADC_CTL3_REGS {
    union   ADCCTL3_REG                      ADCCTL3;                     // 0x0 ADC Control 3 Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================