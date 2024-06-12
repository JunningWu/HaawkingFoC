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
// Release time: 2024-01-23 15:23:22.144640
//
//#############################################################################


#ifndef F28002X_SYSCTRL_H
#define F28002X_SYSCTRL_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SYSCTRL Individual Register Bit Definitions:

struct REVID_BITS {                           // bits description
    Uint32 REVID:16;                          // 15:0 Device Revision ID. This is specific to the Device
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union REVID_REG {
    Uint32  all;
    struct  REVID_BITS  bit;
};

struct DC21_BITS {                            // bits description
    Uint32 CLB1:1;                            // 0 CLB1 Present
    Uint32 CLB2:1;                            // 1 CLB2 Present
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union DC21_REG {
    Uint32  all;
    struct  DC21_BITS  bit;
};

struct FUSEERR_BITS {                         // bits description
    Uint32 ALERR:5;                           // 4:0 Efuse Autoload Error Status
    Uint32 ERR:1;                             // 5 Efuse Self Test Error Status
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union FUSEERR_REG {
    Uint32  all;
    struct  FUSEERR_BITS  bit;
};

struct SOFTPRES0_BITS {                       // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 rsvd3:1;                           // 2 Reserved
    Uint32 rsvd4:1;                           // 3 Reserved
    Uint32 rsvd5:9;                           // 12:4 Reserved
    Uint32 CPU1_CPUBGCRC:1;                   // 13 CPUBGCRC Module reset bit
    Uint32 rsvd6:2;                           // 15:14 Reserved
    Uint32 rsvd7:8;                           // 23:16 Reserved
    Uint32 CPU1_ERAD:1;                       // 24 ERAD Module reset bit
    Uint32 rsvd8:7;                           // 31:25 Reserved
};

union SOFTPRES0_REG {
    Uint32  all;
    struct  SOFTPRES0_BITS  bit;
};

struct SOFTPRES2_BITS {                       // bits description
    Uint32 EPWM1:1;                           // 0 EPWM1 software reset bit
    Uint32 EPWM2:1;                           // 1 EPWM2 software reset bit
    Uint32 EPWM3:1;                           // 2 EPWM3 software reset bit
    Uint32 EPWM4:1;                           // 3 EPWM4 software reset bit
    Uint32 EPWM5:1;                           // 4 EPWM5 software reset bit
    Uint32 EPWM6:1;                           // 5 EPWM6 software reset bit
    Uint32 EPWM7:1;                           // 6 EPWM7 software reset bit
    Uint32 EPWM8:1;                           // 7 EPWM8 software reset bit
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:1;                           // 9 Reserved
    Uint32 rsvd3:1;                           // 10 Reserved
    Uint32 rsvd4:1;                           // 11 Reserved
    Uint32 rsvd5:1;                           // 12 Reserved
    Uint32 rsvd6:1;                           // 13 Reserved
    Uint32 rsvd7:1;                           // 14 Reserved
    Uint32 rsvd8:1;                           // 15 Reserved
    Uint32 rsvd9:16;                          // 31:16 Reserved
};

union SOFTPRES2_REG {
    Uint32  all;
    struct  SOFTPRES2_BITS  bit;
};

struct SOFTPRES3_BITS {                       // bits description
    Uint32 ECAP1:1;                           // 0 ECAP1 software reset bit
    Uint32 ECAP2:1;                           // 1 ECAP2 software reset bit
    Uint32 ECAP3:1;                           // 2 ECAP3 software reset bit
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 rsvd5:1;                           // 7 Reserved
    Uint32 rsvd6:8;                           // 15:8 Reserved
    Uint32 rsvd7:16;                          // 31:16 Reserved
};

union SOFTPRES3_REG {
    Uint32  all;
    struct  SOFTPRES3_BITS  bit;
};

struct SOFTPRES4_BITS {                       // bits description
    Uint32 EQEP1:1;                           // 0 EQEP1 software reset bit
    Uint32 EQEP2:1;                           // 1 EQEP2 software reset bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SOFTPRES4_REG {
    Uint32  all;
    struct  SOFTPRES4_BITS  bit;
};

struct SOFTPRES7_BITS {                       // bits description
    Uint32 SCI_A:1;                           // 0 SCI_A software reset bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union SOFTPRES7_REG {
    Uint32  all;
    struct  SOFTPRES7_BITS  bit;
};

struct SOFTPRES8_BITS {                       // bits description
    Uint32 SPI_A:1;                           // 0 SPI_A software reset bit
    Uint32 SPI_B:1;                           // 1 SPI_B software reset bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:1;                           // 16 Reserved
    Uint32 rsvd5:1;                           // 17 Reserved
    Uint32 rsvd6:14;                          // 31:18 Reserved
};

union SOFTPRES8_REG {
    Uint32  all;
    struct  SOFTPRES8_BITS  bit;
};

struct SOFTPRES9_BITS {                       // bits description
    Uint32 I2C_A:1;                           // 0 I2C_A software reset bit
    Uint32 I2C_B:1;                           // 1 I2C_B software reset bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SOFTPRES9_REG {
    Uint32  all;
    struct  SOFTPRES9_BITS  bit;
};

struct SOFTPRES10_BITS {                      // bits description
    Uint32 CAN_A:1;                           // 0 CAN_A software reset bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union SOFTPRES10_REG {
    Uint32  all;
    struct  SOFTPRES10_BITS  bit;
};

struct SOFTPRES13_BITS {                      // bits description
    Uint32 ADC_A:1;                           // 0 ADC_A software reset bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 ADC_C:1;                           // 2 ADC_C software reset bit
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SOFTPRES13_REG {
    Uint32  all;
    struct  SOFTPRES13_BITS  bit;
};

struct SOFTPRES14_BITS {                      // bits description
    Uint32 CMPSS1:1;                          // 0 CMPSS1 software reset bit
    Uint32 CMPSS2:1;                          // 1 CMPSS2 software reset bit
    Uint32 CMPSS3:1;                          // 2 CMPSS3 software reset bit
    Uint32 CMPSS4:1;                          // 3 CMPSS4 software reset bit
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union SOFTPRES14_REG {
    Uint32  all;
    struct  SOFTPRES14_BITS  bit;
};

struct SOFTPRES17_BITS {                      // bits description
    Uint32 CLB1:1;                            // 0 CLB1 software reset bit
    Uint32 CLB2:1;                            // 1 CLB2 software reset bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SOFTPRES17_REG {
    Uint32  all;
    struct  SOFTPRES17_BITS  bit;
};

struct SOFTPRES18_BITS {                      // bits description
    Uint32 FSITX_A:1;                         // 0 FSITX_A software reset bit
    Uint32 FSIRX_A:1;                         // 1 FSIRX_A software reset bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SOFTPRES18_REG {
    Uint32  all;
    struct  SOFTPRES18_BITS  bit;
};

struct SOFTPRES19_BITS {                      // bits description
    Uint32 LIN_A:1;                           // 0 LIN_A software reset bit
    Uint32 LIN_B:1;                           // 1 LIN_B software reset bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SOFTPRES19_REG {
    Uint32  all;
    struct  SOFTPRES19_BITS  bit;
};

struct SOFTPRES20_BITS {                      // bits description
    Uint32 PMBUS_A:1;                         // 0 PMBUS_A software reset bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:14;                          // 15:2 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union SOFTPRES20_REG {
    Uint32  all;
    struct  SOFTPRES20_BITS  bit;
};

struct SOFTPRES21_BITS {                      // bits description
    Uint32 DCC0:1;                            // 0 DCC Module reset bit
    Uint32 DCC1:1;                            // 1 DCC Module reset bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SOFTPRES21_REG {
    Uint32  all;
    struct  SOFTPRES21_BITS  bit;
};

struct SOFTPRES25_BITS {                      // bits description
    Uint32 HIC_A:1;                           // 0 HIC Slave & Host controller Reset Bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SOFTPRES25_REG {
    Uint32  all;
    struct  SOFTPRES25_BITS  bit;
};

struct SOFTPRES26_BITS {                      // bits description
    Uint32 I2S_A:1;                           // 0 I2S_A software reset bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union SOFTPRES26_REG {
    Uint32  all;
    struct  SOFTPRES26_BITS  bit;
};

struct TAP_STATUS_BITS {                      // bits description
    Uint32 TAP_STATE:16;                      // 15:0 Present TAP State
    Uint32 rsvd1:15;                          // 30:16 Reserved
    Uint32 DCON:1;                            // 31 Debugger Connect Indication
};

union TAP_STATUS_REG {
    Uint32  all;
    struct  TAP_STATUS_BITS  bit;
};

struct ECAPTYPE_BITS {                        // bits description
    Uint32 TYPE:2;                            // 1:0 Configure ECAP type
    Uint32 rsvd1:13;                          // 14:2 Reserved
    Uint32 LOCK:1;                            // 15 Lock bit for the register
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union ECAPTYPE_REG {
    Uint32  all;
    struct  ECAPTYPE_BITS  bit;
};

struct  DEV_CFG_REGS {
    Uint32                                   rsvd1[6];                    // 0x0 Reserved
    union   REVID_REG                        REVID;                       // 0x18 Device Revision Number
    Uint32                                   rsvd2[22];                   // 0x1c Reserved
    union   DC21_REG                         DC21;                        // 0x74 Device Capability: CLB
    Uint32                                   rsvd3[28];                   // 0x78 Reserved
    union   FUSEERR_REG                      FUSEERR;                     // 0xe8 e-Fuse error Status register
    Uint32                                   rsvd4[6];                    // 0xec Reserved
    union   SOFTPRES0_REG                    SOFTPRES0;                   // 0x104 Processing Block Software Reset register
    Uint32                                   rsvd5;                       // 0x108 Reserved
    union   SOFTPRES2_REG                    SOFTPRES2;                   // 0x10c Peripheral Software Reset register
    union   SOFTPRES3_REG                    SOFTPRES3;                   // 0x110 Peripheral Software Reset register
    union   SOFTPRES4_REG                    SOFTPRES4;                   // 0x114 Peripheral Software Reset register
    Uint32                                   rsvd6[2];                    // 0x118 Reserved
    union   SOFTPRES7_REG                    SOFTPRES7;                   // 0x120 Peripheral Software Reset register
    union   SOFTPRES8_REG                    SOFTPRES8;                   // 0x124 Peripheral Software Reset register
    union   SOFTPRES9_REG                    SOFTPRES9;                   // 0x128 Peripheral Software Reset register
    union   SOFTPRES10_REG                   SOFTPRES10;                  // 0x12c Peripheral Software Reset register
    Uint32                                   rsvd7[2];                    // 0x130 Reserved
    union   SOFTPRES13_REG                   SOFTPRES13;                  // 0x138 Peripheral Software Reset register
    union   SOFTPRES14_REG                   SOFTPRES14;                  // 0x13c Peripheral Software Reset register
    Uint32                                   rsvd8[2];                    // 0x140 Reserved
    union   SOFTPRES17_REG                   SOFTPRES17;                  // 0x148 Peripheral Software Reset register
    union   SOFTPRES18_REG                   SOFTPRES18;                  // 0x14c Peripheral Software Reset register
    union   SOFTPRES19_REG                   SOFTPRES19;                  // 0x150 Peripheral Software Reset register
    union   SOFTPRES20_REG                   SOFTPRES20;                  // 0x154 Peripheral Software Reset register
    union   SOFTPRES21_REG                   SOFTPRES21;                  // 0x158 Peripheral Software Reset register
    Uint32                                   rsvd9[3];                    // 0x15c Reserved
    union   SOFTPRES25_REG                   SOFTPRES25;                  // 0x168 Peripheral Software Reset register
    union   SOFTPRES26_REG                   SOFTPRES26;                  // 0x16c Peripheral Software Reset register
    Uint32                                   rsvd10[60];                  // 0x170 Reserved
    union   TAP_STATUS_REG                   TAP_STATUS;                  // 0x260 Status of JTAG State machine & Debugger Connect
    Uint32                                   rsvd11[53];                  // 0x264 Reserved
    union   ECAPTYPE_REG                     ECAPTYPE;                    // 0x338 Configures ECAP Type for the device
};

struct CLKCFGLOCK1_BITS {                     // bits description
    Uint32 CLKSRCCTL1:1;                      // 0 Lock bit for CLKSRCCTL1 register
    Uint32 CLKSRCCTL2:1;                      // 1 Lock bit for CLKSRCCTL2 register
    Uint32 CLKSRCCTL3:1;                      // 2 Lock bit for CLKSRCCTL3 register
    Uint32 SYSPLLCTL1:1;                      // 3 Lock bit for SYSPLLCTL1 register
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 SYSPLLMULT:1;                      // 6 Lock bit for SYSPLLMULT register
    Uint32 rsvd3:1;                           // 7 Reserved
    Uint32 rsvd4:1;                           // 8 Reserved
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 rsvd6:1;                           // 10 Reserved
    Uint32 SYSCLKDIVSEL:1;                    // 11 Lock bit for SYSCLKDIVSEL register
    Uint32 rsvd7:1;                           // 12 Reserved
    Uint32 PERCLKDIVSEL:1;                    // 13 Lock bit for PERCLKDIVSEL register
    Uint32 CLBCLKCTL:1;                       // 14 Lock bit for CLBCLKCTL register
    Uint32 LOSPCP:1;                          // 15 Lock bit for LOSPCP register
    Uint32 XTALCR:1;                          // 16 Lock bit for XTALCR & XTALCR2 register
    Uint32 rsvd8:15;                          // 31:17 Reserved
};

union CLKCFGLOCK1_REG {
    Uint32  all;
    struct  CLKCFGLOCK1_BITS  bit;
};

struct CLKSRCCTL1_BITS {                      // bits description
    Uint32 OSCCLKSRCSEL:2;                    // 1:0 OSCCLK Source Select Bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 INTOSC2OFF_NOTSUPPORTED:1;         // 3 Internal Oscillator 2 Off Bit
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 WDHALTI:1;                         // 5 Watchdog HALT Mode Ignore Bit
    Uint32 rsvd3:10;                          // 15:6 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union CLKSRCCTL1_REG {
    Uint32  all;
    struct  CLKSRCCTL1_BITS  bit;
};

struct CLKSRCCTL2_BITS {                      // bits description
    Uint32 rsvd1:2;                           // 1:0 Reserved
    Uint32 CANABCLKSEL:2;                     // 3:2 CANA Bit Clock Source Select Bit
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 rsvd3:2;                           // 7:6 Reserved
    Uint32 rsvd4:2;                           // 9:8 Reserved
    Uint32 rsvd5:6;                           // 15:10 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union CLKSRCCTL2_REG {
    Uint32  all;
    struct  CLKSRCCTL2_BITS  bit;
};

struct CLKSRCCTL3_BITS {                      // bits description
    Uint32 XCLKOUTSEL:4;                      // 3:0 XCLKOUT Source Select Bit
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLKSRCCTL3_REG {
    Uint32  all;
    struct  CLKSRCCTL3_BITS  bit;
};

struct SYSPLLCTL1_BITS {                      // bits description
    Uint32 PLLEN:1;                           // 0 SYSPLL enable/disable bit
    Uint32 PLLCLKEN:1;                        // 1 SYSPLL bypassed or included in the PLLSYSCLK path
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:1;                           // 4 Reserved
    Uint32 rsvd4:1;                           // 5 Reserved
    Uint32 rsvd5:10;                          // 15:6 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union SYSPLLCTL1_REG {
    Uint32  all;
    struct  SYSPLLCTL1_BITS  bit;
};

struct SYSPLLMULT_BITS {                      // bits description
    Uint32 IMULT:8;                           // 7:0 SYSPLL Integer Multiplier
    Uint32 VCO:3;                             // 10:8 The VCO oscillating frequency adjust signals
    Uint32 rsvd1:1;                           // 11 Reserved
    Uint32 rsvd2:2;                           // 13:12 Reserved
    Uint32 rsvd3:2;                           // 15:14 Reserved
    Uint32 ODIV:6;                            // 21:16 Output Clock Divider
    Uint32 rsvd4:2;                           // 23:22 Reserved
    Uint32 REFDIV:6;                          // 29:24 Reference Clock Divider
    Uint32 rsvd5:2;                           // 31:30 Reserved
};

union SYSPLLMULT_REG {
    Uint32  all;
    struct  SYSPLLMULT_BITS  bit;
};

struct SYSPLLSTS_BITS {                       // bits description
    Uint32 LOCKS:1;                           // 0 SYSPLL Lock Status Bit
    Uint32 SLIPS_NOTSUPPORTED:1;              // 1 SYSPLL Slip Status Bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 REF_LOSTS:1;                       // 3 SYSPLL Reference Lost Status Bit
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:10;                          // 15:6 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union SYSPLLSTS_REG {
    Uint32  all;
    struct  SYSPLLSTS_BITS  bit;
};

struct SYSCLKDIVSEL_BITS {                    // bits description
    Uint32 PLLSYSCLKDIV:6;                    // 5:0 PLLSYSCLK Divide Select
    Uint32 rsvd1:2;                           // 7:6 Reserved
    Uint32 PLLSYSCLKDIV_LSB:1;                // 8 This bit allows the odd division for the sys clock divider
    Uint32 rsvd2:7;                           // 15:9 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union SYSCLKDIVSEL_REG {
    Uint32  all;
    struct  SYSCLKDIVSEL_BITS  bit;
};

struct XCLKOUTDIVSEL_BITS {                   // bits description
    Uint32 XCLKOUTDIV:2;                      // 1:0 XCLKOUT Divide Select
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union XCLKOUTDIVSEL_REG {
    Uint32  all;
    struct  XCLKOUTDIVSEL_BITS  bit;
};

struct CLBCLKCTL_BITS {                       // bits description
    Uint32 CLBCLKDIV:3;                       // 2:0 CLB clock divider configuration.
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 TILECLKDIV:1;                      // 4 CLB Tile clock divider configuration.
    Uint32 rsvd2:11;                          // 15:5 Reserved
    Uint32 CLKMODECLB1:1;                     // 16 Clock mode of CLB1
    Uint32 CLKMODECLB2:1;                     // 17 Clock mode of CLB2
    Uint32 rsvd3:1;                           // 18 Reserved
    Uint32 rsvd4:1;                           // 19 Reserved
    Uint32 rsvd5:1;                           // 20 Reserved
    Uint32 rsvd6:1;                           // 21 Reserved
    Uint32 rsvd7:1;                           // 22 Reserved
    Uint32 rsvd8:1;                           // 23 Reserved
    Uint32 rsvd9:8;                           // 31:24 Reserved
};

union CLBCLKCTL_REG {
    Uint32  all;
    struct  CLBCLKCTL_BITS  bit;
};

struct LOSPCP_BITS {                          // bits description
    Uint32 LSPCLKDIV:3;                       // 2:0 LSPCLK Divide Select
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union LOSPCP_REG {
    Uint32  all;
    struct  LOSPCP_BITS  bit;
};

struct MCDCR_BITS {                           // bits description
    Uint32 MCLKSTS:1;                         // 0 Missing Clock Status Bit
    Uint32 MCLKCLR:1;                         // 1 Missing Clock Clear Bit
    Uint32 MCLKOFF:1;                         // 2 Missing Clock Detect Off Bit
    Uint32 OSCOFF:1;                          // 3 Oscillator Clock Off Bit
    Uint32 SYSREF_LOSTS:1;                    // 4 SYSPLL Reference Lost Status Bit
    Uint32 SYSREF_LOSTSCLR:1;                 // 5 Clear for Ref clock lost status
    Uint32 SYSREF_LOST_MCD_EN:1;              // 6 Enable for PLL REF_CLK_LOST as MCD cause
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 rsvd2:1;                           // 8 Reserved
    Uint32 rsvd3:1;                           // 9 Reserved
    Uint32 rsvd4:6;                           // 15:10 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union MCDCR_REG {
    Uint32  all;
    struct  MCDCR_BITS  bit;
};

struct X1CNT_BITS {                           // bits description
    Uint32 X1CNT:11;                          // 10:0 X1 Counter
    Uint32 rsvd1:5;                           // 15:11 Reserved
    Uint32 CLR:1;                             // 16 X1 Counter Clear
    Uint32 rsvd2:15;                          // 31:17 Reserved
};

union X1CNT_REG {
    Uint32  all;
    struct  X1CNT_BITS  bit;
};

struct XTALCR_BITS {                          // bits description
    Uint32 OSCOFF:1;                          // 0 XTAL Oscillator powered-down
    Uint32 SE:1;                              // 1 XTAL Oscilator in Single-Ended mode
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union XTALCR_REG {
    Uint32  all;
    struct  XTALCR_BITS  bit;
};

struct XTALCR2_BITS {                         // bits description
    Uint32 XIF:1;                             // 0 XI Initial value deposited before XOSC start
    Uint32 XOF:1;                             // 1 XO Initial value deposited before XOSC start
    Uint32 FEN:1;                             // 2 XOSC pads initialisation enable
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union XTALCR2_REG {
    Uint32  all;
    struct  XTALCR2_BITS  bit;
};

struct CLKFAILCFG_BITS {                      // bits description
    Uint32 DCC0_ERROR_EN:1;                   // 0 DCC0 Error causes Clock fail NMI, ERROR
    Uint32 DCC1_ERROR_EN:1;                   // 1 DCC1 Error causes Clock fail NMI, ERROR
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLKFAILCFG_REG {
    Uint32  all;
    struct  CLKFAILCFG_BITS  bit;
};

struct HRCAPDIV_BITS {                        // bits description
    Uint32 HRCAPDIV:3;                        // 2:0 Clock for Hrcap Div
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union HRCAPDIV_REG {
    Uint32  all;
    struct  HRCAPDIV_BITS  bit;
};

struct  CLK_CFG_REGS {
    Uint32                                   rsvd1;                       // 0x0 Reserved
    union   CLKCFGLOCK1_REG                  CLKCFGLOCK1;                 // 0x4 Lock bit for CLKCFG registers
    Uint32                                   rsvd2[2];                    // 0x8 Reserved
    union   CLKSRCCTL1_REG                   CLKSRCCTL1;                  // 0x10 Clock Source Control register-1
    union   CLKSRCCTL2_REG                   CLKSRCCTL2;                  // 0x14 Clock Source Control register-2
    union   CLKSRCCTL3_REG                   CLKSRCCTL3;                  // 0x18 Clock Source Control register-3
    union   SYSPLLCTL1_REG                   SYSPLLCTL1;                  // 0x1c SYSPLL Control register-1
    Uint32                                   rsvd3[2];                    // 0x20 Reserved
    union   SYSPLLMULT_REG                   SYSPLLMULT;                  // 0x28 SYSPLL Multiplier register
    union   SYSPLLSTS_REG                    SYSPLLSTS;                   // 0x2c SYSPLL Status register
    Uint32                                   rsvd4[5];                    // 0x30 Reserved
    union   SYSCLKDIVSEL_REG                 SYSCLKDIVSEL;                // 0x44 System Clock Divider Select register
    Uint32                                   rsvd5[2];                    // 0x48 Reserved
    union   XCLKOUTDIVSEL_REG                XCLKOUTDIVSEL;               // 0x50 XCLKOUT Divider Select register
    union   CLBCLKCTL_REG                    CLBCLKCTL;                   // 0x54 CLB Clocking Control Register
    union   LOSPCP_REG                       LOSPCP;                      // 0x58 Low Speed Clock Source Prescalar
    union   MCDCR_REG                        MCDCR;                       // 0x5c Missing Clock Detect Control Register
    union   X1CNT_REG                        X1CNT;                       // 0x60 10-bit Counter on X1 Clock
    union   XTALCR_REG                       XTALCR;                      // 0x64 XTAL Control Register
    Uint32                                   rsvd6[3];                    // 0x68 Reserved
    union   XTALCR2_REG                      XTALCR2;                     // 0x74 XTAL Control Register for pad init
    union   CLKFAILCFG_REG                   CLKFAILCFG;                  // 0x78 Clock Fail cause Configuration
    union   HRCAPDIV_REG                     HRCAPDIV;                    // 0x7c Clock for Hrcap Div
};

struct CPUSYSLOCK1_BITS {                     // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 PIEVERRADDR:1;                     // 2 Lock bit for PIEVERRADDR Register
    Uint32 PCLKCR0:1;                         // 3 Lock bit for PCLKCR0 Register
    Uint32 rsvd3:1;                           // 4 Reserved
    Uint32 PCLKCR2:1;                         // 5 Lock bit for PCLKCR2 Register
    Uint32 PCLKCR3:1;                         // 6 Lock bit for PCLKCR3 Register
    Uint32 PCLKCR4:1;                         // 7 Lock bit for PCLKCR4 Register
    Uint32 rsvd4:1;                           // 8 Reserved
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 PCLKCR7:1;                         // 10 Lock bit for PCLKCR7 Register
    Uint32 PCLKCR8:1;                         // 11 Lock bit for PCLKCR8 Register
    Uint32 PCLKCR9:1;                         // 12 Lock bit for PCLKCR9 Register
    Uint32 PCLKCR10:1;                        // 13 Lock bit for PCLKCR10 Register
    Uint32 rsvd6:1;                           // 14 Reserved
    Uint32 rsvd7:1;                           // 15 Reserved
    Uint32 PCLKCR13:1;                        // 16 Lock bit for PCLKCR13 Register
    Uint32 PCLKCR14:1;                        // 17 Lock bit for PCLKCR14 Register
    Uint32 rsvd8:1;                           // 18 Reserved
    Uint32 rsvd9:1;                           // 19 Reserved
    Uint32 rsvd10:1;                          // 20 Reserved
    Uint32 LPMCR:1;                           // 21 Lock bit for LPMCR Register
    Uint32 GPIOLPMSEL0:1;                     // 22 Lock bit for GPIOLPMSEL0 Register
    Uint32 GPIOLPMSEL1:1;                     // 23 Lock bit for GPIOLPMSEL1 Register
    Uint32 PCLKCR17:1;                        // 24 Lock bit for PCLKCR17 Register
    Uint32 PCLKCR18:1;                        // 25 Lock bit for PCLKCR18 Register
    Uint32 PCLKCR19:1;                        // 26 Lock bit for PCLKCR19 Register
    Uint32 PCLKCR20:1;                        // 27 Lock bit for PCLKCR20 Register
    Uint32 PCLKCR21:1;                        // 28 Lock bit for PCLKCR21 Register
    Uint32 PCLKCR22:1;                        // 29 Lock bit for PCLKCR22 Register
    Uint32 rsvd11:1;                          // 30 Reserved
    Uint32 PCLKCR24:1;                        // 31 Lock bit for PCLKCR24 Register
};

union CPUSYSLOCK1_REG {
    Uint32  all;
    struct  CPUSYSLOCK1_BITS  bit;
};

struct CPUSYSLOCK2_BITS {                     // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 PCLKCR25:1;                        // 1 Lock bit for PCLKCR25 Register
    Uint32 PCLKCR26:1;                        // 2 Lock bit for PCLKCR26 Register
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CPUSYSLOCK2_REG {
    Uint32  all;
    struct  CPUSYSLOCK2_BITS  bit;
};

struct PIEVERRADDR_BITS {                     // bits description
    Uint32 ADDR:22;                           // 21:0 PIE Vector Fetch Error Handler Routine Address
    Uint32 rsvd1:10;                          // 31:22 Reserved
};

union PIEVERRADDR_REG {
    Uint32  all;
    struct  PIEVERRADDR_BITS  bit;
};

struct PCLKCR0_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 DMA:1;                             // 2 DMA Clock Enable bit
    Uint32 CPUTIMER0:1;                       // 3 CPUTIMER0 Clock Enable bit
    Uint32 CPUTIMER1:1;                       // 4 CPUTIMER1 Clock Enable bit
    Uint32 CPUTIMER2:1;                       // 5 CPUTIMER2 Clock Enable bit
    Uint32 rsvd3:7;                           // 12:6 Reserved
    Uint32 CPUBGCRC:1;                        // 13 CPUBGCRC Clock Enable Bit
    Uint32 rsvd4:2;                           // 15:14 Reserved
    Uint32 HRCAL:1;                           // 16 HRCAL Clock Enable Bit
    Uint32 rsvd5:1;                           // 17 Reserved
    Uint32 TBCLKSYNC:1;                       // 18 EPWM Time Base Clock sync
    Uint32 rsvd6:1;                           // 19 Reserved
    Uint32 rsvd7:4;                           // 23:20 Reserved
    Uint32 ERAD:1;                            // 24 ERAD module clock enable
    Uint32 rsvd8:7;                           // 31:25 Reserved
};

union PCLKCR0_REG {
    Uint32  all;
    struct  PCLKCR0_BITS  bit;
};

struct PCLKCR2_BITS {                         // bits description
    Uint32 EPWM1:1;                           // 0 EPWM1 Clock Enable bit
    Uint32 EPWM2:1;                           // 1 EPWM2 Clock Enable bit
    Uint32 EPWM3:1;                           // 2 EPWM3 Clock Enable bit
    Uint32 EPWM4:1;                           // 3 EPWM4 Clock Enable bit
    Uint32 EPWM5:1;                           // 4 EPWM5 Clock Enable bit
    Uint32 EPWM6:1;                           // 5 EPWM6 Clock Enable bit
    Uint32 EPWM7:1;                           // 6 EPWM7 Clock Enable bit
    Uint32 EPWM8:1;                           // 7 EPWM8 Clock Enable bit
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:1;                           // 9 Reserved
    Uint32 rsvd3:1;                           // 10 Reserved
    Uint32 rsvd4:1;                           // 11 Reserved
    Uint32 rsvd5:1;                           // 12 Reserved
    Uint32 rsvd6:1;                           // 13 Reserved
    Uint32 rsvd7:1;                           // 14 Reserved
    Uint32 rsvd8:1;                           // 15 Reserved
    Uint32 rsvd9:16;                          // 31:16 Reserved
};

union PCLKCR2_REG {
    Uint32  all;
    struct  PCLKCR2_BITS  bit;
};

struct PCLKCR3_BITS {                         // bits description
    Uint32 ECAP1:1;                           // 0 ECAP1 Clock Enable bit
    Uint32 ECAP2:1;                           // 1 ECAP2 Clock Enable bit
    Uint32 ECAP3:1;                           // 2 ECAP3 Clock Enable bit
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 rsvd5:1;                           // 7 Reserved
    Uint32 rsvd6:8;                           // 15:8 Reserved
    Uint32 rsvd7:16;                          // 31:16 Reserved
};

union PCLKCR3_REG {
    Uint32  all;
    struct  PCLKCR3_BITS  bit;
};

struct PCLKCR4_BITS {                         // bits description
    Uint32 EQEP1:1;                           // 0 EQEP1 Clock Enable bit
    Uint32 EQEP2:1;                           // 1 EQEP2 Clock Enable bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union PCLKCR4_REG {
    Uint32  all;
    struct  PCLKCR4_BITS  bit;
};

struct PCLKCR7_BITS {                         // bits description
    Uint32 SCI_A:1;                           // 0 SCI_A Clock Enable bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union PCLKCR7_REG {
    Uint32  all;
    struct  PCLKCR7_BITS  bit;
};

struct PCLKCR8_BITS {                         // bits description
    Uint32 SPI_A:1;                           // 0 SPI_A Clock Enable bit
    Uint32 SPI_B:1;                           // 1 SPI_B Clock Enable bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:1;                           // 16 Reserved
    Uint32 rsvd5:1;                           // 17 Reserved
    Uint32 rsvd6:14;                          // 31:18 Reserved
};

union PCLKCR8_REG {
    Uint32  all;
    struct  PCLKCR8_BITS  bit;
};

struct PCLKCR9_BITS {                         // bits description
    Uint32 I2C_A:1;                           // 0 I2C_A Clock Enable bit
    Uint32 I2C_B:1;                           // 1 I2C_B Clock Enable bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PCLKCR9_REG {
    Uint32  all;
    struct  PCLKCR9_BITS  bit;
};

struct PCLKCR10_BITS {                        // bits description
    Uint32 CAN_A:1;                           // 0 CAN_A Clock Enable bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:1;                           // 2 Reserved
    Uint32 rsvd3:1;                           // 3 Reserved
    Uint32 rsvd4:12;                          // 15:4 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union PCLKCR10_REG {
    Uint32  all;
    struct  PCLKCR10_BITS  bit;
};

struct PCLKCR13_BITS {                        // bits description
    Uint32 ADC_A:1;                           // 0 ADC_A Clock Enable bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 ADC_C:1;                           // 2 ADC_C Clock Enable bit
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union PCLKCR13_REG {
    Uint32  all;
    struct  PCLKCR13_BITS  bit;
};

struct PCLKCR14_BITS {                        // bits description
    Uint32 CMPSS1:1;                          // 0 CMPSS1 Clock Enable bit
    Uint32 CMPSS2:1;                          // 1 CMPSS2 Clock Enable bit
    Uint32 CMPSS3:1;                          // 2 CMPSS3 Clock Enable bit
    Uint32 CMPSS4:1;                          // 3 CMPSS4 Clock Enable bit
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 rsvd5:8;                           // 15:8 Reserved
    Uint32 rsvd6:16;                          // 31:16 Reserved
};

union PCLKCR14_REG {
    Uint32  all;
    struct  PCLKCR14_BITS  bit;
};

struct PCLKCR17_BITS {                        // bits description
    Uint32 CLB1:1;                            // 0 CLB1 Clock Enable bit
    Uint32 CLB2:1;                            // 1 CLB2 Clock Enable bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union PCLKCR17_REG {
    Uint32  all;
    struct  PCLKCR17_BITS  bit;
};

struct PCLKCR18_BITS {                        // bits description
    Uint32 FSITX_A:1;                         // 0 FSITX_A Clock Enable bit
    Uint32 FSIRX_A:1;                         // 1 FSIRX_A Clock Enable bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union PCLKCR18_REG {
    Uint32  all;
    struct  PCLKCR18_BITS  bit;
};

struct PCLKCR19_BITS {                        // bits description
    Uint32 LIN_A:1;                           // 0 LIN_A Clock Enable bit
    Uint32 LIN_B:1;                           // 1 LIN_B Clock Enable bit
    Uint32 rsvd1:1;                           // 2 Reserved
    Uint32 rsvd2:1;                           // 3 Reserved
    Uint32 rsvd3:12;                          // 15:4 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union PCLKCR19_REG {
    Uint32  all;
    struct  PCLKCR19_BITS  bit;
};

struct PCLKCR20_BITS {                        // bits description
    Uint32 PMBUS_A:1;                         // 0 PMBUS_A Clock Enable bit
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 rsvd2:14;                          // 15:2 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union PCLKCR20_REG {
    Uint32  all;
    struct  PCLKCR20_BITS  bit;
};

struct PCLKCR21_BITS {                        // bits description
    Uint32 DCC0:1;                            // 0 DCC0 Clock Enable Bit
    Uint32 DCC1:1;                            // 1 DCC1 Clock Enable Bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PCLKCR21_REG {
    Uint32  all;
    struct  PCLKCR21_BITS  bit;
};

struct PCLKCR22_BITS {                        // bits description
    Uint32 MPOST0:1;                          // 0 MPOSTCLK_0 Clock Enable Bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PCLKCR22_REG {
    Uint32  all;
    struct  PCLKCR22_BITS  bit;
};

struct PCLKCR25_BITS {                        // bits description
    Uint32 HICA:1;                            // 0 HICA Clock Enable Bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PCLKCR25_REG {
    Uint32  all;
    struct  PCLKCR25_BITS  bit;
};

struct SIMRESET_BITS {                        // bits description
    Uint32 CPU1RSn:1;                         // 0 Generates a reset to CPU
    Uint32 XRSn:1;                            // 1 Generates a simulated XRSn
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 KEY:16;                            // 31:16 Key value to enable write
};

union SIMRESET_REG {
    Uint32  all;
    struct  SIMRESET_BITS  bit;
};

struct LPMCR_BITS {                           // bits description
    Uint32 LPM:2;                             // 1:0 Low Power Mode setting
    Uint32 QUALSTDBY:6;                       // 7:2 STANDBY Wakeup Pin Qualification Setting
    Uint32 rsvd1:7;                           // 14:8 Reserved
    Uint32 WDINTE:1;                          // 15 Enable for WDINT wakeup from STANDBY
    Uint32 rsvd2:2;                           // 17:16 Reserved
    Uint32 rsvd3:13;                          // 30:18 Reserved
    Uint32 rsvd4:1;                           // 31 Reserved
};

union LPMCR_REG {
    Uint32  all;
    struct  LPMCR_BITS  bit;
};

struct GPIOLPMSEL0_BITS {                     // bits description
    Uint32 GPIO0:1;                           // 0 GPIO0 Enable for LPM Wakeup
    Uint32 GPIO1:1;                           // 1 GPIO1 Enable for LPM Wakeup
    Uint32 GPIO2:1;                           // 2 GPIO2 Enable for LPM Wakeup
    Uint32 GPIO3:1;                           // 3 GPIO3 Enable for LPM Wakeup
    Uint32 GPIO4:1;                           // 4 GPIO4 Enable for LPM Wakeup
    Uint32 GPIO5:1;                           // 5 GPIO5 Enable for LPM Wakeup
    Uint32 GPIO6:1;                           // 6 GPIO6 Enable for LPM Wakeup
    Uint32 GPIO7:1;                           // 7 GPIO7 Enable for LPM Wakeup
    Uint32 GPIO8:1;                           // 8 GPIO8 Enable for LPM Wakeup
    Uint32 GPIO9:1;                           // 9 GPIO9 Enable for LPM Wakeup
    Uint32 GPIO10:1;                          // 10 GPIO10 Enable for LPM Wakeup
    Uint32 GPIO11:1;                          // 11 GPIO11 Enable for LPM Wakeup
    Uint32 GPIO12:1;                          // 12 GPIO12 Enable for LPM Wakeup
    Uint32 GPIO13:1;                          // 13 GPIO13 Enable for LPM Wakeup
    Uint32 GPIO14:1;                          // 14 GPIO14 Enable for LPM Wakeup
    Uint32 GPIO15:1;                          // 15 GPIO15 Enable for LPM Wakeup
    Uint32 GPIO16:1;                          // 16 GPIO16 Enable for LPM Wakeup
    Uint32 GPIO17:1;                          // 17 GPIO17 Enable for LPM Wakeup
    Uint32 GPIO18:1;                          // 18 GPIO18 Enable for LPM Wakeup
    Uint32 GPIO19:1;                          // 19 GPIO19 Enable for LPM Wakeup
    Uint32 rsvd1:1;                           // 20 Reserved
    Uint32 rsvd2:1;                           // 21 Reserved
    Uint32 GPIO22:1;                          // 22 GPIO22 Enable for LPM Wakeup
    Uint32 GPIO23:1;                          // 23 GPIO23 Enable for LPM Wakeup
    Uint32 GPIO24:1;                          // 24 GPIO24 Enable for LPM Wakeup
    Uint32 GPIO25:1;                          // 25 GPIO25 Enable for LPM Wakeup
    Uint32 GPIO26:1;                          // 26 GPIO26 Enable for LPM Wakeup
    Uint32 GPIO27:1;                          // 27 GPIO27 Enable for LPM Wakeup
    Uint32 GPIO28:1;                          // 28 GPIO28 Enable for LPM Wakeup
    Uint32 GPIO29:1;                          // 29 GPIO29 Enable for LPM Wakeup
    Uint32 GPIO30:1;                          // 30 GPIO30 Enable for LPM Wakeup
    Uint32 GPIO31:1;                          // 31 GPIO31 Enable for LPM Wakeup
};

union GPIOLPMSEL0_REG {
    Uint32  all;
    struct  GPIOLPMSEL0_BITS  bit;
};

struct GPIOLPMSEL1_BITS {                     // bits description
    Uint32 GPIO32:1;                          // 0 GPIO32 Enable for LPM Wakeup
    Uint32 GPIO33:1;                          // 1 GPIO33 Enable for LPM Wakeup
    Uint32 GPIO34:1;                          // 2 GPIO34 Enable for LPM Wakeup
    Uint32 GPIO35:1;                          // 3 GPIO35 Enable for LPM Wakeup
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 GPIO37:1;                          // 5 GPIO37 Enable for LPM Wakeup
    Uint32 rsvd2:1;                           // 6 Reserved
    Uint32 GPIO39:1;                          // 7 GPIO39 Enable for LPM Wakeup
    Uint32 GPIO40:1;                          // 8 GPIO40 Enable for LPM Wakeup
    Uint32 GPIO41:1;                          // 9 GPIO41 Enable for LPM Wakeup
    Uint32 GPIO42:1;                          // 10 GPIO42 Enable for LPM Wakeup
    Uint32 GPIO43:1;                          // 11 GPIO43 Enable for LPM Wakeup
    Uint32 GPIO44:1;                          // 12 GPIO44 Enable for LPM Wakeup
    Uint32 GPIO45:1;                          // 13 GPIO45 Enable for LPM Wakeup
    Uint32 GPIO46:1;                          // 14 GPIO46 Enable for LPM Wakeup
    Uint32 rsvd3:1;                           // 15 Reserved
    Uint32 rsvd4:1;                           // 16 Reserved
    Uint32 rsvd5:1;                           // 17 Reserved
    Uint32 rsvd6:1;                           // 18 Reserved
    Uint32 rsvd7:1;                           // 19 Reserved
    Uint32 rsvd8:1;                           // 20 Reserved
    Uint32 rsvd9:1;                           // 21 Reserved
    Uint32 rsvd10:1;                          // 22 Reserved
    Uint32 rsvd11:1;                          // 23 Reserved
    Uint32 rsvd12:1;                          // 24 Reserved
    Uint32 rsvd13:1;                          // 25 Reserved
    Uint32 rsvd14:1;                          // 26 Reserved
    Uint32 rsvd15:1;                          // 27 Reserved
    Uint32 rsvd16:1;                          // 28 Reserved
    Uint32 GPIO61:1;                          // 29 GPIO61 Enable for LPM Wakeup
    Uint32 GPIO62:1;                          // 30 GPIO62 Enable for LPM Wakeup
    Uint32 GPIO63:1;                          // 31 GPIO63 Enable for LPM Wakeup
};

union GPIOLPMSEL1_REG {
    Uint32  all;
    struct  GPIOLPMSEL1_BITS  bit;
};

struct TMR2CLKCTL_BITS {                      // bits description
    Uint32 TMR2CLKSRCSEL:3;                   // 2:0 CPU Timer 2 Clock Source Select Bit
    Uint32 TMR2CLKPRESCALE:3;                 // 5:3 CPU Timer 2 Clock Pre-Scale Value
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union TMR2CLKCTL_REG {
    Uint32  all;
    struct  TMR2CLKCTL_BITS  bit;
};

struct RESCCLR_BITS {                         // bits description
    Uint32 POR:1;                             // 0 POR Reset Cause Indication Bit
    Uint32 XRSn:1;                            // 1 XRSn Reset Cause Indication Bit
    Uint32 WDRSn:1;                           // 2 WDRSn Reset Cause Indication Bit
    Uint32 NMIWDRSn:1;                        // 3 NMIWDRSn Reset Cause Indication Bit
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 SCCRESETn:1;                       // 8 SCCRESETn Reset Cause Indication Bit
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 SIMRESET_CPU1RSn:1;                // 10 SIMRESET_CPU1RSn Reset Cause Indication Bit
    Uint32 SIMRESET_XRSn:1;                   // 11 SIMRESET_XRSn Reset Cause Indication Bit
    Uint32 rsvd6:4;                           // 15:12 Reserved
    Uint32 rsvd7:16;                          // 31:16 Reserved
};

union RESCCLR_REG {
    Uint32  all;
    struct  RESCCLR_BITS  bit;
};

struct RESC_BITS {                            // bits description
    Uint32 POR:1;                             // 0 POR Reset Cause Indication Bit
    Uint32 XRSn:1;                            // 1 XRSn Reset Cause Indication Bit
    Uint32 WDRSn:1;                           // 2 WDRSn Reset Cause Indication Bit
    Uint32 NMIWDRSn:1;                        // 3 NMIWDRSn Reset Cause Indication Bit
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:1;                           // 7 Reserved
    Uint32 SCCRESETn:1;                       // 8 SCCRESETn Reset Cause Indication Bit
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 SIMRESET_CPU1RSn:1;                // 10 SIMRESET_CPU1RSn Reset Cause Indication Bit
    Uint32 SIMRESET_XRSn:1;                   // 11 SIMRESET_XRSn Reset Cause Indication Bit
    Uint32 rsvd6:4;                           // 15:12 Reserved
    Uint32 rsvd7:14;                          // 29:16 Reserved
    Uint32 XRSn_pin_status:1;                 // 30 XRSN Pin Status
    Uint32 DCON:1;                            // 31 Debugger conntion status to C28x
};

union RESC_REG {
    Uint32  all;
    struct  RESC_BITS  bit;
};

struct PCLKCR26_BITS {                        // bits description
    Uint32 I2S_A:1;                           // 0 I2S_A Clock Enable Bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union PCLKCR26_REG {
    Uint32  all;
    struct  PCLKCR26_BITS  bit;
};

struct  CPU_SYS_REGS {
    union   CPUSYSLOCK1_REG                  CPUSYSLOCK1;                 // 0x0 Lock bit for CPUSYS registers
    union   CPUSYSLOCK2_REG                  CPUSYSLOCK2;                 // 0x4 Lock bit for CPUSYS registers
    Uint32                                   rsvd1[3];                    // 0x8 Reserved
    union   PIEVERRADDR_REG                  PIEVERRADDR;                 // 0x14 PIE Vector Fetch Error Address register
    Uint32                                   rsvd2[11];                   // 0x18 Reserved
    union   PCLKCR0_REG                      PCLKCR0;                     // 0x44 Peripheral Clock Gating Registers
    union   PCLKCR2_REG                      PCLKCR2;                     // 0x48 Peripheral Clock Gating Register - ETPWM
    union   PCLKCR3_REG                      PCLKCR3;                     // 0x4c Peripheral Clock Gating Register - ECAP
    union   PCLKCR4_REG                      PCLKCR4;                     // 0x50 Peripheral Clock Gating Register - EQEP
    Uint32                                   rsvd3[3];                    // 0x54 Reserved
    union   PCLKCR7_REG                      PCLKCR7;                     // 0x60 Peripheral Clock Gating Register - SCI
    union   PCLKCR8_REG                      PCLKCR8;                     // 0x64 Peripheral Clock Gating Register - SPI
    union   PCLKCR9_REG                      PCLKCR9;                     // 0x68 Peripheral Clock Gating Register - I2C
    union   PCLKCR10_REG                     PCLKCR10;                    // 0x6c Peripheral Clock Gating Register - CAN
    Uint32                                   rsvd4[2];                    // 0x70 Reserved
    union   PCLKCR13_REG                     PCLKCR13;                    // 0x78 Peripheral Clock Gating Register - ADC
    union   PCLKCR14_REG                     PCLKCR14;                    // 0x7c Peripheral Clock Gating Register - CMPSS
    Uint32                                   rsvd5[2];                    // 0x80 Reserved
    union   PCLKCR17_REG                     PCLKCR17;                    // 0x88 Peripheral Clock Gating Register - CLB
    union   PCLKCR18_REG                     PCLKCR18;                    // 0x8c Peripheral Clock Gating Register - FSI
    union   PCLKCR19_REG                     PCLKCR19;                    // 0x90 Peripheral Clock Gating Register - LIN
    union   PCLKCR20_REG                     PCLKCR20;                    // 0x94 Peripheral Clock Gating Register - PMBUS
    union   PCLKCR21_REG                     PCLKCR21;                    // 0x98 Peripheral Clock Gating Register - DCC
    union   PCLKCR22_REG                     PCLKCR22;                    // 0x9c Peripheral Clock Gating Register - MPOST
    Uint32                                   rsvd6[2];                    // 0xa0 Reserved
    union   PCLKCR25_REG                     PCLKCR25;                    // 0xa8 Peripheral Clock Gating Register - HIC
    Uint32                                   rsvd7[13];                   // 0xac Reserved
    union   SIMRESET_REG                     SIMRESET;                    // 0xe0 Simulated Reset Register
    Uint32                                   rsvd8[2];                    // 0xe4 Reserved
    union   LPMCR_REG                        LPMCR;                       // 0xec LPM Control Register
    union   GPIOLPMSEL0_REG                  GPIOLPMSEL0;                 // 0xf0 GPIO LPM Wakeup select registers
    union   GPIOLPMSEL1_REG                  GPIOLPMSEL1;                 // 0xf4 GPIO LPM Wakeup select registers
    union   TMR2CLKCTL_REG                   TMR2CLKCTL;                  // 0xf8 Timer2 Clock Measurement functionality control register
    union   RESCCLR_REG                      RESCCLR;                     // 0xfc Reset Cause Clear Register
    union   RESC_REG                         RESC;                        // 0x100 Reset Cause register
    union   PCLKCR26_REG                     PCLKCR26;                    // 0x104 Peripheral Clock Gating Register - I2S
};

struct WDKEY_BITS {                           // bits description
    Uint32 WDKEY:8;                           // 7:0 Key to pet the watchdog timer.
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union WDKEY_REG {
    Uint32  all;
    struct  WDKEY_BITS  bit;
};

struct SCSR_BITS {                            // bits description
    Uint32 WDOVERRIDE:1;                      // 0 WD Override for WDDIS bit
    Uint32 WDENINT:1;                         // 1 WD Interrupt Enable
    Uint32 WDINTS:1;                          // 2 WD Interrupt Status
    Uint32 rsvd1:29;                          // 31:3 Reserved
};

union SCSR_REG {
    Uint32  all;
};

struct WDCNTR_BITS {                          // bits description
    Uint32 WDCNTR:8;                          // 7:0 WD Counter
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union WDCNTR_REG {
    Uint32  all;
    struct  WDCNTR_BITS  bit;
};

struct WDCR_BITS {                            // bits description
    Uint32 WDPS:3;                            // 2:0 WD Clock Prescalar
    Uint32 WDCHK:3;                           // 5:3 WD Check Bits
    Uint32 WDDIS:1;                           // 6 WD Disable
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 WDPRECLKDIV:4;                     // 11:8 WD Pre Clock Divider
    Uint32 rsvd2:20;                          // 31:12 Reserved
};

union WDCR_REG {
    Uint32  all;
    struct  WDCR_BITS  bit;
};

struct WDWCR_BITS {                           // bits description
    Uint32 MIN:8;                             // 7:0 WD Min Threshold setting for Windowed Watchdog functionality
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:23;                          // 31:9 Reserved
};

union WDWCR_REG {
    Uint32  all;
    struct  WDWCR_BITS  bit;
};

struct  WD_REGS {
    Uint32                                   rsvd1[16];                   // 0x0 Reserved
    union   WDKEY_REG                        WDKEY;                       // 0x40 Watchdog Reset Key Register
    union   SCSR_REG                         SCSR;                        // 0x44 System Control & Status Register
    union   WDCNTR_REG                       WDCNTR;                      // 0x48 Watchdog Counter Register
    Uint32                                   rsvd2;                       // 0x4c Reserved
    union   WDCR_REG                         WDCR;                        // 0x50 Watchdog Control Register
    union   WDWCR_REG                        WDWCR;                       // 0x54 Watchdog Windowed Control Register
};

struct DMACHSRCSELLOCK_BITS {                 // bits description
    Uint32 DMACHSRCSEL1:1;                    // 0 DMACHSRCSEL1 Register Lock bit
    Uint32 DMACHSRCSEL2:1;                    // 1 DMACHSRCSEL2 Register Lock bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union DMACHSRCSELLOCK_REG {
    Uint32  all;
    struct  DMACHSRCSELLOCK_BITS  bit;
};

struct DMACHSRCSEL1_BITS {                    // bits description
    Uint32 CH1:8;                             // 7:0 Selects the Trigger and Sync Source CH1 of DMA
    Uint32 CH2:8;                             // 15:8 Selects the Trigger and Sync Source CH2 of DMA
    Uint32 CH3:8;                             // 23:16 Selects the Trigger and Sync Source CH3 of DMA
    Uint32 CH4:8;                             // 31:24 Selects the Trigger and Sync Source CH4 of DMA
};

union DMACHSRCSEL1_REG {
    Uint32  all;
    struct  DMACHSRCSEL1_BITS  bit;
};

struct DMACHSRCSEL2_BITS {                    // bits description
    Uint32 CH5:8;                             // 7:0 Selects the Trigger and Sync Source CH5 of DMA
    Uint32 CH6:8;                             // 15:8 Selects the Trigger and Sync Source CH6 of DMA
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union DMACHSRCSEL2_REG {
    Uint32  all;
    struct  DMACHSRCSEL2_BITS  bit;
};

struct  DMA_CLA_SRC_SEL_REGS {
    Uint32                                   rsvd1[2];                    // 0x0 Reserved
    union   DMACHSRCSELLOCK_REG              DMACHSRCSELLOCK;             // 0x8 DMA Channel Triger Source Select Lock Register
    Uint32                                   rsvd2[8];                    // 0xc Reserved
    union   DMACHSRCSEL1_REG                 DMACHSRCSEL1;                // 0x2c DMA Channel Trigger Source Select Register-1
    union   DMACHSRCSEL2_REG                 DMACHSRCSEL2;                // 0x30 DMA Channel Trigger Source Select Register-2
};

struct ADCA_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 rsvd3:2;                           // 7:6 Reserved
    Uint32 rsvd4:8;                           // 15:8 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union ADCA_AC_REG {
    Uint32  all;
    struct  ADCA_AC_BITS  bit;
};

struct ADCC_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 rsvd3:2;                           // 7:6 Reserved
    Uint32 rsvd4:8;                           // 15:8 Reserved
    Uint32 rsvd5:16;                          // 31:16 Reserved
};

union ADCC_AC_REG {
    Uint32  all;
    struct  ADCC_AC_BITS  bit;
};

struct CMPSS1_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CMPSS1_AC_REG {
    Uint32  all;
    struct  CMPSS1_AC_BITS  bit;
};

struct CMPSS2_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CMPSS2_AC_REG {
    Uint32  all;
    struct  CMPSS2_AC_BITS  bit;
};

struct CMPSS3_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CMPSS3_AC_REG {
    Uint32  all;
    struct  CMPSS3_AC_BITS  bit;
};

struct CMPSS4_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CMPSS4_AC_REG {
    Uint32  all;
    struct  CMPSS4_AC_BITS  bit;
};

struct EPWM1_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM1_AC_REG {
    Uint32  all;
    struct  EPWM1_AC_BITS  bit;
};

struct EPWM2_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM2_AC_REG {
    Uint32  all;
    struct  EPWM2_AC_BITS  bit;
};

struct EPWM3_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM3_AC_REG {
    Uint32  all;
    struct  EPWM3_AC_BITS  bit;
};

struct EPWM4_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM4_AC_REG {
    Uint32  all;
    struct  EPWM4_AC_BITS  bit;
};

struct EPWM5_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM5_AC_REG {
    Uint32  all;
    struct  EPWM5_AC_BITS  bit;
};

struct EPWM6_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM6_AC_REG {
    Uint32  all;
    struct  EPWM6_AC_BITS  bit;
};

struct EPWM7_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EPWM7_AC_REG {
    Uint32  all;
    struct  EPWM7_AC_BITS  bit;
};

struct EQEP1_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EQEP1_AC_REG {
    Uint32  all;
    struct  EQEP1_AC_BITS  bit;
};

struct EQEP2_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union EQEP2_AC_REG {
    Uint32  all;
    struct  EQEP2_AC_BITS  bit;
};

struct ECAP1_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ECAP1_AC_REG {
    Uint32  all;
    struct  ECAP1_AC_BITS  bit;
};

struct ECAP2_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ECAP2_AC_REG {
    Uint32  all;
    struct  ECAP2_AC_BITS  bit;
};

struct ECAP3_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union ECAP3_AC_REG {
    Uint32  all;
    struct  ECAP3_AC_BITS  bit;
};

struct CLB1_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union CLB1_AC_REG {
    Uint32  all;
    struct  CLB1_AC_BITS  bit;
};

struct CLB2_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union CLB2_AC_REG {
    Uint32  all;
    struct  CLB2_AC_BITS  bit;
};

struct SCIA_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union SCIA_AC_REG {
    Uint32  all;
    struct  SCIA_AC_BITS  bit;
};

struct SPIA_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union SPIA_AC_REG {
    Uint32  all;
    struct  SPIA_AC_BITS  bit;
};

struct SPIB_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union SPIB_AC_REG {
    Uint32  all;
    struct  SPIB_AC_BITS  bit;
};

struct I2CA_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union I2CA_AC_REG {
    Uint32  all;
    struct  I2CA_AC_BITS  bit;
};

struct I2CB_AC_BITS {                         // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 rsvd2:2;                           // 5:4 Reserved
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union I2CB_AC_REG {
    Uint32  all;
    struct  I2CB_AC_BITS  bit;
};

struct PMBUS_A_AC_BITS {                      // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union PMBUS_A_AC_REG {
    Uint32  all;
    struct  PMBUS_A_AC_BITS  bit;
};

struct LIN_A_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union LIN_A_AC_REG {
    Uint32  all;
    struct  LIN_A_AC_BITS  bit;
};

struct LIN_B_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union LIN_B_AC_REG {
    Uint32  all;
    struct  LIN_B_AC_BITS  bit;
};

struct DCANA_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union DCANA_AC_REG {
    Uint32  all;
    struct  DCANA_AC_BITS  bit;
};

struct FSIATX_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union FSIATX_AC_REG {
    Uint32  all;
    struct  FSIATX_AC_BITS  bit;
};

struct FSIARX_AC_BITS {                       // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union FSIARX_AC_REG {
    Uint32  all;
    struct  FSIARX_AC_BITS  bit;
};

struct HRPWM_A_AC_BITS {                      // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:8;                           // 15:8 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union HRPWM_A_AC_REG {
    Uint32  all;
    struct  HRPWM_A_AC_BITS  bit;
};

struct HIC_A_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 rsvd2:2;                           // 7:6 Reserved
    Uint32 rsvd3:8;                           // 15:8 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union HIC_A_AC_REG {
    Uint32  all;
    struct  HIC_A_AC_BITS  bit;
};

struct I2S_A_AC_BITS {                        // bits description
    Uint32 CPU1_ACC:2;                        // 1:0 CPU1 Access conditions to peripheral
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 DMA1_ACC:2;                        // 5:4 DMA1 Access Conditions to Peripheral
    Uint32 HICA_ACC:2;                        // 7:6 HICA Access Contions to Peripheral
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union I2S_A_AC_REG {
    Uint32  all;
    struct  I2S_A_AC_BITS  bit;
};

struct PERIPH_AC_LOCK_BITS {                  // bits description
    Uint32 LOCK_AC_WR:1;                      // 0 Lock control for Access control registers write.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PERIPH_AC_LOCK_REG {
    Uint32  all;
    struct  PERIPH_AC_LOCK_BITS  bit;
};

struct  PERIPH_AC_REGS {
    union   ADCA_AC_REG                      ADCA_AC;                     // 0x0 ADCA Master Access Control Register
    Uint32                                   rsvd1;                       // 0x4 Reserved
    union   ADCC_AC_REG                      ADCC_AC;                     // 0x8 ADCC Master Access Control Register
    Uint32                                   rsvd2[5];                    // 0xc Reserved
    union   CMPSS1_AC_REG                    CMPSS1_AC;                   // 0x20 CMPSS1 Master Access Control Register
    union   CMPSS2_AC_REG                    CMPSS2_AC;                   // 0x24 CMPSS2 Master Access Control Register
    union   CMPSS3_AC_REG                    CMPSS3_AC;                   // 0x28 CMPSS3 Master Access Control Register
    union   CMPSS4_AC_REG                    CMPSS4_AC;                   // 0x2c CMPSS4 Master Access Control Register
    union   EPWM1_AC_REG                     EPWM1_AC;                    // 0x30 EPWM1 Master Access Control Register
    union   EPWM2_AC_REG                     EPWM2_AC;                    // 0x34 EPWM2 Master Access Control Register
    union   EPWM3_AC_REG                     EPWM3_AC;                    // 0x38 EPWM3 Master Access Control Register
    union   EPWM4_AC_REG                     EPWM4_AC;                    // 0x3c EPWM4 Master Access Control Register
    union   EPWM5_AC_REG                     EPWM5_AC;                    // 0x40 EPWM5 Master Access Control Register
    union   EPWM6_AC_REG                     EPWM6_AC;                    // 0x44 EPWM6 Master Access Control Register
    union   EPWM7_AC_REG                     EPWM7_AC;                    // 0x48 EPWM7 Master Access Control Register
    Uint32                                   rsvd3[37];                   // 0x4c Reserved
    union   EQEP1_AC_REG                     EQEP1_AC;                    // 0xe0 EQEP1 Master Access Control Register
    union   EQEP2_AC_REG                     EQEP2_AC;                    // 0xe4 EQEP2 Master Access Control Register
    Uint32                                   rsvd4[6];                    // 0xe8 Reserved
    union   ECAP1_AC_REG                     ECAP1_AC;                    // 0x100 ECAP1 Master Access Control Register
    union   ECAP2_AC_REG                     ECAP2_AC;                    // 0x104 ECAP2 Master Access Control Register
    union   ECAP3_AC_REG                     ECAP3_AC;                    // 0x108 ECAP3 Master Access Control Register
    Uint32                                   rsvd5[21];                   // 0x10c Reserved
    union   CLB1_AC_REG                      CLB1_AC;                     // 0x160 CLB1 Master Access Control Register
    union   CLB2_AC_REG                      CLB2_AC;                     // 0x164 CLB2 Master Access Control Register
    Uint32                                   rsvd6[38];                   // 0x168 Reserved
    union   SCIA_AC_REG                      SCIA_AC;                     // 0x200 SCIA Master Access Control Register
    Uint32                                   rsvd7[7];                    // 0x204 Reserved
    union   SPIA_AC_REG                      SPIA_AC;                     // 0x220 SPIA Master Access Control Register
    union   SPIB_AC_REG                      SPIB_AC;                     // 0x224 SPIB Master Access Control Register
    Uint32                                   rsvd8[6];                    // 0x228 Reserved
    union   I2CA_AC_REG                      I2CA_AC;                     // 0x240 I2CA Master Access Control Register
    union   I2CB_AC_REG                      I2CB_AC;                     // 0x244 I2CB Master Access Control Register
    Uint32                                   rsvd9[6];                    // 0x248 Reserved
    union   PMBUS_A_AC_REG                   PMBUS_A_AC;                  // 0x260 PMBUSA Master Access Control Register
    Uint32                                   rsvd10[3];                   // 0x264 Reserved
    union   LIN_A_AC_REG                     LIN_A_AC;                    // 0x270 LINA Master Access Control Register
    union   LIN_B_AC_REG                     LIN_B_AC;                    // 0x274 LINB Master Access Control Register
    Uint32                                   rsvd11[2];                   // 0x278 Reserved
    union   DCANA_AC_REG                     DCANA_AC;                    // 0x280 DCANA Master Access Control Register
    Uint32                                   rsvd12[11];                  // 0x284 Reserved
    union   FSIATX_AC_REG                    FSIATX_AC;                   // 0x2b0 FSIA Master Access Control Register
    union   FSIARX_AC_REG                    FSIARX_AC;                   // 0x2b4 FSIB Master Access Control Register
    Uint32                                   rsvd13[39];                  // 0x2b8 Reserved
    union   HRPWM_A_AC_REG                   HRPWM_A_AC;                  // 0x354 HRPWM Master Access Control Register
    union   HIC_A_AC_REG                     HIC_A_AC;                    // 0x358 HIC Master Access Control Register
    union   I2S_A_AC_REG                     I2S_A_AC;                    // 0x35c I2S Master Access Control Register
    Uint32                                   rsvd14[39];                  // 0x360 Reserved
    union   PERIPH_AC_LOCK_REG               PERIPH_AC_LOCK;              // 0x3fc Lock Register to stop Write access to peripheral Access register.
};

struct SYNCSELECT_BITS {                      // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 rsvd2:3;                           // 5:3 Reserved
    Uint32 rsvd3:3;                           // 8:6 Reserved
    Uint32 rsvd4:3;                           // 11:9 Reserved
    Uint32 rsvd5:3;                           // 14:12 Reserved
    Uint32 rsvd6:1;                           // 15 Reserved
    Uint32 rsvd7:2;                           // 17:16 Reserved
    Uint32 rsvd8:6;                           // 23:18 Reserved
    Uint32 SYNCOUT:5;                         // 28:24 Select Syncout Source
    Uint32 rsvd9:3;                           // 31:29 Reserved
};

union SYNCSELECT_REG {
    Uint32  all;
    struct  SYNCSELECT_BITS  bit;
};

struct ADCSOCOUTSELECT_BITS {                 // bits description
    Uint32 PWM1SOCAEN:1;                      // 0 PWM1SOCAEN Enable for ADCSOCAOn
    Uint32 PWM2SOCAEN:1;                      // 1 PWM2SOCAEN Enable for ADCSOCAOn
    Uint32 PWM3SOCAEN:1;                      // 2 PWM3SOCAEN Enable for ADCSOCAOn
    Uint32 PWM4SOCAEN:1;                      // 3 PWM4SOCAEN Enable for ADCSOCAOn
    Uint32 PWM5SOCAEN:1;                      // 4 PWM5SOCAEN Enable for ADCSOCAOn
    Uint32 PWM6SOCAEN:1;                      // 5 PWM6SOCAEN Enable for ADCSOCAOn
    Uint32 PWM7SOCAEN:1;                      // 6 PWM7SOCAEN Enable for ADCSOCAOn
    Uint32 PWM8SOCAEN:1;                      // 7 PWM8SOCAEN Enable for ADCSOCAOn
    Uint32 rsvd1:1;                           // 8 Reserved
    Uint32 rsvd2:1;                           // 9 Reserved
    Uint32 rsvd3:1;                           // 10 Reserved
    Uint32 rsvd4:1;                           // 11 Reserved
    Uint32 rsvd5:4;                           // 15:12 Reserved
    Uint32 PWM1SOCBEN:1;                      // 16 PWM1SOCBEN Enable for ADCSOCBOn
    Uint32 PWM2SOCBEN:1;                      // 17 PWM2SOCBEN Enable for ADCSOCBOn
    Uint32 PWM3SOCBEN:1;                      // 18 PWM3SOCBEN Enable for ADCSOCBOn
    Uint32 PWM4SOCBEN:1;                      // 19 PWM4SOCBEN Enable for ADCSOCBOn
    Uint32 PWM5SOCBEN:1;                      // 20 PWM5SOCBEN Enable for ADCSOCBOn
    Uint32 PWM6SOCBEN:1;                      // 21 PWM6SOCBEN Enable for ADCSOCBOn
    Uint32 PWM7SOCBEN:1;                      // 22 PWM7SOCBEN Enable for ADCSOCBOn
    Uint32 PWM8SOCBEN:1;                      // 23 PWM8SOCBEN Enable for ADCSOCBOn
    Uint32 rsvd6:1;                           // 24 Reserved
    Uint32 rsvd7:1;                           // 25 Reserved
    Uint32 rsvd8:1;                           // 26 Reserved
    Uint32 rsvd9:1;                           // 27 Reserved
    Uint32 rsvd10:4;                          // 31:28 Reserved
};

union ADCSOCOUTSELECT_REG {
    Uint32  all;
    struct  ADCSOCOUTSELECT_BITS  bit;
};

struct SYNCSOCLOCK_BITS {                     // bits description
    Uint32 SYNCSELECT:1;                      // 0 SYNCSEL Register Lock bit
    Uint32 ADCSOCOUTSELECT:1;                 // 1 ADCSOCOUTSELECT Register Lock bit
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SYNCSOCLOCK_REG {
    Uint32  all;
    struct  SYNCSOCLOCK_BITS  bit;
};

struct  SYNC_SOC_REGS {
    union   SYNCSELECT_REG                   SYNCSELECT;                  // 0x0 Sync Input and Output Select Register
    union   ADCSOCOUTSELECT_REG              ADCSOCOUTSELECT;             // 0x4 External ADCSOC Select Register
    union   SYNCSOCLOCK_REG                  SYNCSOCLOCK;                 // 0x8 SYNCSEL and EXTADCSOC Select Lock register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================