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
// Release for HXS320F280025CEDC, Hal DriverLib, 1.0.0
//
// Release time: 2024-01-25 15:09:27.423271
//
//#############################################################################


#ifndef HW_SYSCTL_H
#define HW_SYSCTL_H

//*************************************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*************************************************************************************************
#define SYSCTL_O_REVID        0x18U    // Device Revision Number
#define SYSCTL_O_DC21         0x74U    // Device Capability: CLB
#define SYSCTL_O_FUSEERR      0xE8U    // e-Fuse error Status register
#define SYSCTL_O_SOFTPRES0    0x104U   // Processing Block Software Reset register
#define SYSCTL_O_SOFTPRES2    0x10CU   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES3    0x110U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES4    0x114U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES7    0x120U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES8    0x124U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES9    0x128U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES10   0x12CU   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES13   0x138U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES14   0x13CU   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES17   0x148U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES18   0x14CU   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES19   0x150U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES20   0x154U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES21   0x158U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES25   0x168U   // Peripheral Software Reset register
#define SYSCTL_O_SOFTPRES26   0x16CU   // Peripheral Software Reset register
#define SYSCTL_O_TAP_STATUS   0x260U   // Status of JTAG State machine & Debugger Connect
#define SYSCTL_O_ECAPTYPE     0x338U   // Configures ECAP Type for the device

#define SYSCTL_O_CLKCFGLOCK1     0x4U    // Lock bit for CLKCFG registers
#define SYSCTL_O_CLKSRCCTL1      0x10U   // Clock Source Control register-1
#define SYSCTL_O_CLKSRCCTL2      0x14U   // Clock Source Control register-2
#define SYSCTL_O_CLKSRCCTL3      0x18U   // Clock Source Control register-3
#define SYSCTL_O_SYSPLLCTL1      0x1CU   // SYSPLL Control register-1
#define SYSCTL_O_SYSPLLMULT      0x28U   // SYSPLL Multiplier register
#define SYSCTL_O_SYSPLLSTS       0x2CU   // SYSPLL Status register
#define SYSCTL_O_SYSCLKDIVSEL    0x44U   // System Clock Divider Select register
#define SYSCTL_O_XCLKOUTDIVSEL   0x50U   // XCLKOUT Divider Select register
#define SYSCTL_O_CLBCLKCTL       0x54U   // CLB Clocking Control Register
#define SYSCTL_O_LOSPCP          0x58U   // Low Speed Clock Source Prescalar
#define SYSCTL_O_MCDCR           0x5CU   // Missing Clock Detect Control Register
#define SYSCTL_O_X1CNT           0x60U   // 10-bit Counter on X1 Clock
#define SYSCTL_O_XTALCR          0x64U   // XTAL Control Register
#define SYSCTL_O_XTALCR2         0x74U   // XTAL Control Register for pad init
#define SYSCTL_O_CLKFAILCFG      0x78U   // Clock Fail cause Configuration
#define SYSCTL_O_HRCAPDIV        0x7CU   // Clock for Hrcap Div
#define SYSCTL_O_SYSPLLSWCFG     0x80U   // SYSPLL Externel Register

#define SYSCTL_O_CPUSYSLOCK1   0x0U     // Lock bit for CPUSYS registers
#define SYSCTL_O_CPUSYSLOCK2   0x4U     // Lock bit for CPUSYS registers
#define SYSCTL_O_PIEVERRADDR   0x14U    // PIE Vector Fetch Error Address register
#define SYSCTL_O_PCLKCR0       0x44U    // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR2       0x48U    // Peripheral Clock Gating Register - ETPWM
#define SYSCTL_O_PCLKCR3       0x4CU    // Peripheral Clock Gating Register - ECAP
#define SYSCTL_O_PCLKCR4       0x50U    // Peripheral Clock Gating Register - EQEP
#define SYSCTL_O_PCLKCR7       0x60U    // Peripheral Clock Gating Register - SCI
#define SYSCTL_O_PCLKCR8       0x64U    // Peripheral Clock Gating Register - SPI
#define SYSCTL_O_PCLKCR9       0x68U    // Peripheral Clock Gating Register - I2C
#define SYSCTL_O_PCLKCR10      0x6CU    // Peripheral Clock Gating Register - CAN
#define SYSCTL_O_PCLKCR13      0x78U    // Peripheral Clock Gating Register - ADC
#define SYSCTL_O_PCLKCR14      0x7CU    // Peripheral Clock Gating Register - CMPSS
#define SYSCTL_O_PCLKCR17      0x88U    // Peripheral Clock Gating Register - CLB
#define SYSCTL_O_PCLKCR18      0x8CU    // Peripheral Clock Gating Register - FSI
#define SYSCTL_O_PCLKCR19      0x90U    // Peripheral Clock Gating Register - LIN
#define SYSCTL_O_PCLKCR20      0x94U    // Peripheral Clock Gating Register - PMBUS
#define SYSCTL_O_PCLKCR21      0x98U    // Peripheral Clock Gating Register - DCC
#define SYSCTL_O_PCLKCR22      0x9CU    // Peripheral Clock Gating Register - MPOST
#define SYSCTL_O_PCLKCR25      0xA8U    // Peripheral Clock Gating Register - HIC
#define SYSCTL_O_SIMRESET      0xE0U    // Simulated Reset Register
#define SYSCTL_O_LPMCR         0xECU    // LPM Control Register
#define SYSCTL_O_GPIOLPMSEL0   0xF0U    // GPIO LPM Wakeup select registers
#define SYSCTL_O_GPIOLPMSEL1   0xF4U    // GPIO LPM Wakeup select registers
#define SYSCTL_O_TMR2CLKCTL    0xF8U    // Timer2 Clock Measurement functionality control register
#define SYSCTL_O_RESCCLR       0xFCU    // Reset Cause Clear Register
#define SYSCTL_O_RESC          0x100U   // Reset Cause register
#define SYSCTL_O_PCLKCR26      0x104U   // Peripheral Clock Gating Register - I2S

#define SYSCTL_O_WDKEY    0x40U   // Watchdog Reset Key Register
#define SYSCTL_O_SCSR     0x44U   // System Control & Status Register
#define SYSCTL_O_WDCNTR   0x48U   // Watchdog Counter Register
#define SYSCTL_O_WDCR     0x50U   // Watchdog Control Register
#define SYSCTL_O_WDWCR    0x54U   // Watchdog Windowed Control Register

#define SYSCTL_O_DMACHSRCSELLOCK   0x8U    // DMA Channel Triger Source Select Lock Register
#define SYSCTL_O_DMACHSRCSEL1      0x2CU   // DMA Channel Trigger Source Select Register-1
#define SYSCTL_O_DMACHSRCSEL2      0x30U   // DMA Channel Trigger Source Select Register-2

#define SYSCTL_O_ADCA_AC          0x0U     // ADCA Master Access Control Register
#define SYSCTL_O_ADCC_AC          0x8U     // ADCC Master Access Control Register
#define SYSCTL_O_CMPSS1_AC        0x20U    // CMPSS1 Master Access Control Register
#define SYSCTL_O_CMPSS2_AC        0x24U    // CMPSS2 Master Access Control Register
#define SYSCTL_O_CMPSS3_AC        0x28U    // CMPSS3 Master Access Control Register
#define SYSCTL_O_CMPSS4_AC        0x2CU    // CMPSS4 Master Access Control Register
#define SYSCTL_O_EPWM1_AC         0x30U    // EPWM1 Master Access Control Register
#define SYSCTL_O_EPWM2_AC         0x34U    // EPWM2 Master Access Control Register
#define SYSCTL_O_EPWM3_AC         0x38U    // EPWM3 Master Access Control Register
#define SYSCTL_O_EPWM4_AC         0x3CU    // EPWM4 Master Access Control Register
#define SYSCTL_O_EPWM5_AC         0x40U    // EPWM5 Master Access Control Register
#define SYSCTL_O_EPWM6_AC         0x44U    // EPWM6 Master Access Control Register
#define SYSCTL_O_EPWM7_AC         0x48U    // EPWM7 Master Access Control Register
#define SYSCTL_O_EQEP1_AC         0xE0U    // EQEP1 Master Access Control Register
#define SYSCTL_O_EQEP2_AC         0xE4U    // EQEP2 Master Access Control Register
#define SYSCTL_O_ECAP1_AC         0x100U   // ECAP1 Master Access Control Register
#define SYSCTL_O_ECAP2_AC         0x104U   // ECAP2 Master Access Control Register
#define SYSCTL_O_ECAP3_AC         0x108U   // ECAP3 Master Access Control Register
#define SYSCTL_O_CLB1_AC          0x160U   // CLB1 Master Access Control Register
#define SYSCTL_O_CLB2_AC          0x164U   // CLB2 Master Access Control Register
#define SYSCTL_O_SCIA_AC          0x200U   // SCIA Master Access Control Register
#define SYSCTL_O_SPIA_AC          0x220U   // SPIA Master Access Control Register
#define SYSCTL_O_SPIB_AC          0x224U   // SPIB Master Access Control Register
#define SYSCTL_O_I2CA_AC          0x240U   // I2CA Master Access Control Register
#define SYSCTL_O_I2CB_AC          0x244U   // I2CB Master Access Control Register
#define SYSCTL_O_PMBUS_A_AC       0x260U   // PMBUSA Master Access Control Register
#define SYSCTL_O_LIN_A_AC         0x270U   // LINA Master Access Control Register
#define SYSCTL_O_LIN_B_AC         0x274U   // LINB Master Access Control Register
#define SYSCTL_O_DCANA_AC         0x280U   // DCANA Master Access Control Register
#define SYSCTL_O_FSIATX_AC        0x2B0U   // FSIA Master Access Control Register
#define SYSCTL_O_FSIARX_AC        0x2B4U   // FSIB Master Access Control Register
#define SYSCTL_O_HRPWM_A_AC       0x354U   // HRPWM Master Access Control Register
#define SYSCTL_O_HIC_A_AC         0x358U   // HIC Master Access Control Register
#define SYSCTL_O_I2S_A_AC         0x35CU   // I2S Master Access Control Register
#define SYSCTL_O_PERIPH_AC_LOCK   0x3FCU   // Lock Register to stop Write access to peripheral Access register.

#define SYSCTL_O_SYNCSELECT        0x0U   // Sync Input and Output Select Register
#define SYSCTL_O_ADCSOCOUTSELECT   0x4U   // External ADCSOC Select Register
#define SYSCTL_O_SYNCSOCLOCK       0x8U   // SYNCSEL and EXTADCSOC Select Lock register


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVID register
//
//*************************************************************************************************
#define SYSCTL_REVID_REVID_S   0U
#define SYSCTL_REVID_REVID_M   0xFFFFU   // Device Revision ID. This is specific to the Device

//*************************************************************************************************
//
// The following are defines for the bit fields in the DC21 register
//
//*************************************************************************************************
#define SYSCTL_DC21_CLB1   0x1U   // CLB1 Present
#define SYSCTL_DC21_CLB2   0x2U   // CLB2 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the FUSEERR register
//
//*************************************************************************************************
#define SYSCTL_FUSEERR_ALERR_S   0U
#define SYSCTL_FUSEERR_ALERR_M   0x1FU   // Efuse Autoload Error Status
#define SYSCTL_FUSEERR_ERR       0x20U   // Efuse Self Test Error Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES0 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES0_CPU1_CPUBGCRC   0x2000U      // CPUBGCRC Module reset bit
#define SYSCTL_SOFTPRES0_CPU1_ERAD       0x1000000U   // ERAD Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES2 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES2_EPWM1   0x1U    // EPWM1 software reset bit
#define SYSCTL_SOFTPRES2_EPWM2   0x2U    // EPWM2 software reset bit
#define SYSCTL_SOFTPRES2_EPWM3   0x4U    // EPWM3 software reset bit
#define SYSCTL_SOFTPRES2_EPWM4   0x8U    // EPWM4 software reset bit
#define SYSCTL_SOFTPRES2_EPWM5   0x10U   // EPWM5 software reset bit
#define SYSCTL_SOFTPRES2_EPWM6   0x20U   // EPWM6 software reset bit
#define SYSCTL_SOFTPRES2_EPWM7   0x40U   // EPWM7 software reset bit
#define SYSCTL_SOFTPRES2_EPWM8   0x80U   // EPWM8 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES3 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES3_ECAP1   0x1U   // ECAP1 software reset bit
#define SYSCTL_SOFTPRES3_ECAP2   0x2U   // ECAP2 software reset bit
#define SYSCTL_SOFTPRES3_ECAP3   0x4U   // ECAP3 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES4 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES4_EQEP1   0x1U   // EQEP1 software reset bit
#define SYSCTL_SOFTPRES4_EQEP2   0x2U   // EQEP2 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES7 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES7_SCI_A   0x1U   // SCI_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES8 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES8_SPI_A   0x1U   // SPI_A software reset bit
#define SYSCTL_SOFTPRES8_SPI_B   0x2U   // SPI_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES9 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES9_I2C_A   0x1U   // I2C_A software reset bit
#define SYSCTL_SOFTPRES9_I2C_B   0x2U   // I2C_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES10 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES10_CAN_A   0x1U   // CAN_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES13 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES13_ADC_A   0x1U   // ADC_A software reset bit
#define SYSCTL_SOFTPRES13_ADC_C   0x4U   // ADC_C software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES14 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES14_CMPSS1   0x1U   // CMPSS1 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS2   0x2U   // CMPSS2 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS3   0x4U   // CMPSS3 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS4   0x8U   // CMPSS4 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES17 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES17_CLB1   0x1U   // CLB1 software reset bit
#define SYSCTL_SOFTPRES17_CLB2   0x2U   // CLB2 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES18 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES18_FSITX_A   0x1U   // FSITX_A software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_A   0x2U   // FSIRX_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES19 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES19_LIN_A   0x1U   // LIN_A software reset bit
#define SYSCTL_SOFTPRES19_LIN_B   0x2U   // LIN_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES20 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES20_PMBUS_A   0x1U   // PMBUS_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES21 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES21_DCC0   0x1U   // DCC Module reset bit
#define SYSCTL_SOFTPRES21_DCC1   0x2U   // DCC Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES25 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES25_HIC_A   0x1U   // HIC Slave & Host controller Reset Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES26 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES26_I2S_A   0x1U   // I2S_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAP_STATUS register
//
//*************************************************************************************************
#define SYSCTL_TAP_STATUS_TAP_STATE_S   0U
#define SYSCTL_TAP_STATUS_TAP_STATE_M   0xFFFFU       // Present TAP State
#define SYSCTL_TAP_STATUS_DCON          0x80000000U   // Debugger Connect Indication

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAPTYPE register
//
//*************************************************************************************************
#define SYSCTL_ECAPTYPE_TYPE_S   0U
#define SYSCTL_ECAPTYPE_TYPE_M   0x3U      // Configure ECAP type
#define SYSCTL_ECAPTYPE_LOCK     0x8000U   // Lock bit for the register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKCFGLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL1     0x1U       // Lock bit for CLKSRCCTL1 register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL2     0x2U       // Lock bit for CLKSRCCTL2 register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL3     0x4U       // Lock bit for CLKSRCCTL3 register
#define SYSCTL_CLKCFGLOCK1_SYSPLLCTL1     0x8U       // Lock bit for SYSPLLCTL1 register
#define SYSCTL_CLKCFGLOCK1_SYSPLLMULT     0x40U      // Lock bit for SYSPLLMULT register
#define SYSCTL_CLKCFGLOCK1_SYSCLKDIVSEL   0x800U     // Lock bit for SYSCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_PERCLKDIVSEL   0x2000U    // Lock bit for PERCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_CLBCLKCTL      0x4000U    // Lock bit for CLBCLKCTL register
#define SYSCTL_CLKCFGLOCK1_LOSPCP         0x8000U    // Lock bit for LOSPCP register
#define SYSCTL_CLKCFGLOCK1_XTALCR         0x10000U   // Lock bit for XTALCR & XTALCR2 register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL1 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_S            0U
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M            0x3U    // OSCCLK Source Select Bit
#define SYSCTL_CLKSRCCTL1_INTOSC2OFF_NOTSUPPORTED   0x8U    // Internal Oscillator 2 Off Bit
#define SYSCTL_CLKSRCCTL1_WDHALTI                   0x20U   // Watchdog HALT Mode Ignore Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL2 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL2_CANABCLKSEL_S   2U
#define SYSCTL_CLKSRCCTL2_CANABCLKSEL_M   0xCU   // CANA Bit Clock Source Select Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL3 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_S   0U
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_M   0xFU   // XCLKOUT Source Select Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLCTL1 register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLCTL1_PLLEN      0x1U   // SYSPLL enable/disable bit
#define SYSCTL_SYSPLLCTL1_PLLCLKEN   0x2U   // SYSPLL bypassed or included in the PLLSYSCLK path

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLMULT register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLMULT_IMULT_S    0U
#define SYSCTL_SYSPLLMULT_IMULT_M    0xFFU         // SYSPLL Integer Multiplier
#define SYSCTL_SYSPLLMULT_VCO_S      8U
#define SYSCTL_SYSPLLMULT_VCO_M      0x700U        // The VCO oscillating frequency adjust signals
#define SYSCTL_SYSPLLMULT_ODIV_S     16U
#define SYSCTL_SYSPLLMULT_ODIV_M     0x3F0000U     // Output Clock Divider
#define SYSCTL_SYSPLLMULT_REFDIV_S   24U
#define SYSCTL_SYSPLLMULT_REFDIV_M   0x3F000000U   // Reference Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLSTS register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLSTS_LOCKS                0x1U   // SYSPLL Lock Status Bit
#define SYSCTL_SYSPLLSTS_SLIPS_NOTSUPPORTED   0x2U   // SYSPLL Slip Status Bit
#define SYSCTL_SYSPLLSTS_REF_LOSTS            0x8U   // SYSPLL Reference Lost Status Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSCLKDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_S     0U
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M     0x3FU    // PLLSYSCLK Divide Select
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_LSB   0x100U   // This bit allows the odd division for the sys clock divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the XCLKOUTDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_S   0U
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_M   0x3U   // XCLKOUT Divide Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBCLKCTL register
//
//*************************************************************************************************
#define SYSCTL_CLBCLKCTL_CLBCLKDIV_S   0U
#define SYSCTL_CLBCLKCTL_CLBCLKDIV_M   0x7U       // CLB clock divider configuration.
#define SYSCTL_CLBCLKCTL_TILECLKDIV    0x10U      // CLB Tile clock divider configuration.
#define SYSCTL_CLBCLKCTL_CLKMODECLB1   0x10000U   // Clock mode of CLB1
#define SYSCTL_CLBCLKCTL_CLKMODECLB2   0x20000U   // Clock mode of CLB2

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOSPCP register
//
//*************************************************************************************************
#define SYSCTL_LOSPCP_LSPCLKDIV_S   0U
#define SYSCTL_LOSPCP_LSPCLKDIV_M   0x7U   // LSPCLK Divide Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCDCR register
//
//*************************************************************************************************
#define SYSCTL_MCDCR_MCLKSTS              0x1U    // Missing Clock Status Bit
#define SYSCTL_MCDCR_MCLKCLR              0x2U    // Missing Clock Clear Bit
#define SYSCTL_MCDCR_MCLKOFF              0x4U    // Missing Clock Detect Off Bit
#define SYSCTL_MCDCR_OSCOFF               0x8U    // Oscillator Clock Off Bit
#define SYSCTL_MCDCR_SYSREF_LOSTS         0x10U   // SYSPLL Reference Lost Status Bit
#define SYSCTL_MCDCR_SYSREF_LOSTSCLR      0x20U   // Clear for Ref clock lost status
#define SYSCTL_MCDCR_SYSREF_LOST_MCD_EN   0x40U   // Enable for PLL REF_CLK_LOST as MCD cause

//*************************************************************************************************
//
// The following are defines for the bit fields in the X1CNT register
//
//*************************************************************************************************
#define SYSCTL_X1CNT_X1CNT_S   0U
#define SYSCTL_X1CNT_X1CNT_M   0x7FFU     // X1 Counter
#define SYSCTL_X1CNT_CLR       0x10000U   // X1 Counter Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the XTALCR register
//
//*************************************************************************************************
#define SYSCTL_XTALCR_OSCOFF   0x1U   // XTAL Oscillator powered-down
#define SYSCTL_XTALCR_SE       0x2U   // XTAL Oscilator in Single-Ended mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the XTALCR2 register
//
//*************************************************************************************************
#define SYSCTL_XTALCR2_XIF   0x1U   // XI Initial value deposited before XOSC start
#define SYSCTL_XTALCR2_XOF   0x2U   // XO Initial value deposited before XOSC start
#define SYSCTL_XTALCR2_FEN   0x4U   // XOSC pads initialisation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKFAILCFG register
//
//*************************************************************************************************
#define SYSCTL_CLKFAILCFG_DCC0_ERROR_EN   0x1U   // DCC0 Error causes Clock fail NMI, ERROR
#define SYSCTL_CLKFAILCFG_DCC1_ERROR_EN   0x2U   // DCC1 Error causes Clock fail NMI, ERROR

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRCAPDIV register
//
//*************************************************************************************************
#define SYSCTL_HRCAPDIV_HRCAPDIV_S   0U
#define SYSCTL_HRCAPDIV_HRCAPDIV_M   0x7U   // Clock for Hrcap Div

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLSWCFG register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLSWCFG_SW_REG_S   0U
#define SYSCTL_SYSPLLSWCFG_SW_REG_M   0x3U   // The registers which are used to controlling the output voltage ofinternal regulator
#define SYSCTL_SYSPLLSWCFG_SW_ICP_S   2U
#define SYSCTL_SYSPLLSWCFG_SW_ICP_M   0xCU   // The registers used to controlling the current of charge pump

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUSYSLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_CPUSYSLOCK1_PIEVERRADDR   0x4U          // Lock bit for PIEVERRADDR Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR0       0x8U          // Lock bit for PCLKCR0 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR2       0x20U         // Lock bit for PCLKCR2 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR3       0x40U         // Lock bit for PCLKCR3 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR4       0x80U         // Lock bit for PCLKCR4 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR7       0x400U        // Lock bit for PCLKCR7 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR8       0x800U        // Lock bit for PCLKCR8 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR9       0x1000U       // Lock bit for PCLKCR9 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR10      0x2000U       // Lock bit for PCLKCR10 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR13      0x10000U      // Lock bit for PCLKCR13 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR14      0x20000U      // Lock bit for PCLKCR14 Register
#define SYSCTL_CPUSYSLOCK1_LPMCR         0x200000U     // Lock bit for LPMCR Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL0   0x400000U     // Lock bit for GPIOLPMSEL0 Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL1   0x800000U     // Lock bit for GPIOLPMSEL1 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR17      0x1000000U    // Lock bit for PCLKCR17 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR18      0x2000000U    // Lock bit for PCLKCR18 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR19      0x4000000U    // Lock bit for PCLKCR19 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR20      0x8000000U    // Lock bit for PCLKCR20 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR21      0x10000000U   // Lock bit for PCLKCR21 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR22      0x20000000U   // Lock bit for PCLKCR22 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR24      0x80000000U   // Lock bit for PCLKCR24 Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUSYSLOCK2 register
//
//*************************************************************************************************
#define SYSCTL_CPUSYSLOCK2_PCLKCR25   0x2U   // Lock bit for PCLKCR25 Register
#define SYSCTL_CPUSYSLOCK2_PCLKCR26   0x4U   // Lock bit for PCLKCR26 Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the PIEVERRADDR register
//
//*************************************************************************************************
#define SYSCTL_PIEVERRADDR_ADDR_S   0U
#define SYSCTL_PIEVERRADDR_ADDR_M   0x3FFFFFU   // PIE Vector Fetch Error Handler Routine Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR0_DMA         0x4U         // DMA Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER0   0x8U         // CPUTIMER0 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER1   0x10U        // CPUTIMER1 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER2   0x20U        // CPUTIMER2 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUBGCRC    0x2000U      // CPUBGCRC Clock Enable Bit
#define SYSCTL_PCLKCR0_HRCAL       0x10000U     // HRCAL Clock Enable Bit
#define SYSCTL_PCLKCR0_TBCLKSYNC   0x40000U     // EPWM Time Base Clock sync
#define SYSCTL_PCLKCR0_ERAD        0x1000000U   // ERAD module clock enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR2 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR2_EPWM1   0x1U    // EPWM1 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM2   0x2U    // EPWM2 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM3   0x4U    // EPWM3 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM4   0x8U    // EPWM4 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM5   0x10U   // EPWM5 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM6   0x20U   // EPWM6 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM7   0x40U   // EPWM7 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM8   0x80U   // EPWM8 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR3 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR3_ECAP1   0x1U   // ECAP1 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP2   0x2U   // ECAP2 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP3   0x4U   // ECAP3 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR4 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR4_EQEP1   0x1U   // EQEP1 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP2   0x2U   // EQEP2 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR7 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR7_SCI_A   0x1U   // SCI_A Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR8 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR8_SPI_A   0x1U   // SPI_A Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_B   0x2U   // SPI_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR9 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR9_I2C_A   0x1U   // I2C_A Clock Enable bit
#define SYSCTL_PCLKCR9_I2C_B   0x2U   // I2C_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR10 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR10_CAN_A   0x1U   // CAN_A Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR13 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR13_ADC_A   0x1U   // ADC_A Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_C   0x4U   // ADC_C Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR14 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR14_CMPSS1   0x1U   // CMPSS1 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS2   0x2U   // CMPSS2 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS3   0x4U   // CMPSS3 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS4   0x8U   // CMPSS4 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR17 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR17_CLB1   0x1U   // CLB1 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB2   0x2U   // CLB2 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR18 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR18_FSITX_A   0x1U   // FSITX_A Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_A   0x2U   // FSIRX_A Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR19 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR19_LIN_A   0x1U   // LIN_A Clock Enable bit
#define SYSCTL_PCLKCR19_LIN_B   0x2U   // LIN_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR20 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR20_PMBUS_A   0x1U   // PMBUS_A Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR21 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR21_DCC0   0x1U   // DCC0 Clock Enable Bit
#define SYSCTL_PCLKCR21_DCC1   0x2U   // DCC1 Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR22 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR22_MPOST0   0x1U   // MPOSTCLK_0 Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR25 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR25_HICA   0x1U   // HICA Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIMRESET register
//
//*************************************************************************************************
#define SYSCTL_SIMRESET_CPU1RSN   0x1U          // Generates a reset to CPU
#define SYSCTL_SIMRESET_XRSN      0x2U          // Generates a simulated XRSn
#define SYSCTL_SIMRESET_KEY_S     16U
#define SYSCTL_SIMRESET_KEY_M     0xFFFF0000U   // Key value to enable write

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPMCR register
//
//*************************************************************************************************
#define SYSCTL_LPMCR_LPM_S         0U
#define SYSCTL_LPMCR_LPM_M         0x3U      // Low Power Mode setting
#define SYSCTL_LPMCR_QUALSTDBY_S   2U
#define SYSCTL_LPMCR_QUALSTDBY_M   0xFCU     // STANDBY Wakeup Pin Qualification Setting
#define SYSCTL_LPMCR_WDINTE        0x8000U   // Enable for WDINT wakeup from STANDBY

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL0 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL0_GPIO0    0x1U          // GPIO0 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO1    0x2U          // GPIO1 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO2    0x4U          // GPIO2 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO3    0x8U          // GPIO3 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO4    0x10U         // GPIO4 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO5    0x20U         // GPIO5 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO6    0x40U         // GPIO6 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO7    0x80U         // GPIO7 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO8    0x100U        // GPIO8 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO9    0x200U        // GPIO9 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO10   0x400U        // GPIO10 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO11   0x800U        // GPIO11 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO12   0x1000U       // GPIO12 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO13   0x2000U       // GPIO13 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO14   0x4000U       // GPIO14 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO15   0x8000U       // GPIO15 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO16   0x10000U      // GPIO16 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO17   0x20000U      // GPIO17 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO18   0x40000U      // GPIO18 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO19   0x80000U      // GPIO19 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO22   0x400000U     // GPIO22 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO23   0x800000U     // GPIO23 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO24   0x1000000U    // GPIO24 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO25   0x2000000U    // GPIO25 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO26   0x4000000U    // GPIO26 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO27   0x8000000U    // GPIO27 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO28   0x10000000U   // GPIO28 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO29   0x20000000U   // GPIO29 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO30   0x40000000U   // GPIO30 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO31   0x80000000U   // GPIO31 Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL1 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL1_GPIO32   0x1U          // GPIO32 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO33   0x2U          // GPIO33 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO34   0x4U          // GPIO34 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO35   0x8U          // GPIO35 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO37   0x20U         // GPIO37 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO39   0x80U         // GPIO39 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO40   0x100U        // GPIO40 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO41   0x200U        // GPIO41 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO42   0x400U        // GPIO42 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO43   0x800U        // GPIO43 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO44   0x1000U       // GPIO44 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO45   0x2000U       // GPIO45 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO46   0x4000U       // GPIO46 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO61   0x20000000U   // GPIO61 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO62   0x40000000U   // GPIO62 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO63   0x80000000U   // GPIO63 Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the TMR2CLKCTL register
//
//*************************************************************************************************
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_S     0U
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_M     0x7U    // CPU Timer 2 Clock Source Select Bit
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S   3U
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M   0x38U   // CPU Timer 2 Clock Pre-Scale Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the RESCCLR register
//
//*************************************************************************************************
#define SYSCTL_RESCCLR_POR                0x1U     // POR Reset Cause Indication Bit
#define SYSCTL_RESCCLR_XRSN               0x2U     // XRSn Reset Cause Indication Bit
#define SYSCTL_RESCCLR_WDRSN              0x4U     // WDRSn Reset Cause Indication Bit
#define SYSCTL_RESCCLR_NMIWDRSN           0x8U     // NMIWDRSn Reset Cause Indication Bit
#define SYSCTL_RESCCLR_SCCRESETN          0x100U   // SCCRESETn Reset Cause Indication Bit
#define SYSCTL_RESCCLR_SIMRESET_CPU1RSN   0x400U   // SIMRESET_CPU1RSn Reset Cause Indication Bit
#define SYSCTL_RESCCLR_SIMRESET_XRSN      0x800U   // SIMRESET_XRSn Reset Cause Indication Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the RESC register
//
//*************************************************************************************************
#define SYSCTL_RESC_POR                0x1U          // POR Reset Cause Indication Bit
#define SYSCTL_RESC_XRSN               0x2U          // XRSn Reset Cause Indication Bit
#define SYSCTL_RESC_WDRSN              0x4U          // WDRSn Reset Cause Indication Bit
#define SYSCTL_RESC_NMIWDRSN           0x8U          // NMIWDRSn Reset Cause Indication Bit
#define SYSCTL_RESC_SCCRESETN          0x100U        // SCCRESETn Reset Cause Indication Bit
#define SYSCTL_RESC_SIMRESET_CPU1RSN   0x400U        // SIMRESET_CPU1RSn Reset Cause Indication Bit
#define SYSCTL_RESC_SIMRESET_XRSN      0x800U        // SIMRESET_XRSn Reset Cause Indication Bit
#define SYSCTL_RESC_XRSN_PIN_STATUS    0x40000000U   // XRSN Pin Status
#define SYSCTL_RESC_DCON               0x80000000U   // Debugger conntion status to C28x

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR26 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR26_I2S_A   0x1U   // I2S_A Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDKEY register
//
//*************************************************************************************************
#define SYSCTL_WDKEY_WDKEY_S   0U
#define SYSCTL_WDKEY_WDKEY_M   0xFFU   // Key to pet the watchdog timer.

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCSR register
//
//*************************************************************************************************
#define SYSCTL_SCSR_WDOVERRIDE   0x1U   // WD Override for WDDIS bit
#define SYSCTL_SCSR_WDENINT      0x2U   // WD Interrupt Enable
#define SYSCTL_SCSR_WDINTS       0x4U   // WD Interrupt Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCNTR register
//
//*************************************************************************************************
#define SYSCTL_WDCNTR_WDCNTR_S   0U
#define SYSCTL_WDCNTR_WDCNTR_M   0xFFU   // WD Counter

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCR register
//
//*************************************************************************************************
#define SYSCTL_WDCR_WDPS_S          0U
#define SYSCTL_WDCR_WDPS_M          0x7U     // WD Clock Prescalar
#define SYSCTL_WDCR_WDCHK_S         3U
#define SYSCTL_WDCR_WDCHK_M         0x38U    // WD Check Bits
#define SYSCTL_WDCR_WDDIS           0x40U    // WD Disable
#define SYSCTL_WDCR_WDPRECLKDIV_S   8U
#define SYSCTL_WDCR_WDPRECLKDIV_M   0xF00U   // WD Pre Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDWCR register
//
//*************************************************************************************************
#define SYSCTL_WDWCR_MIN_S   0U
#define SYSCTL_WDWCR_MIN_M   0xFFU   // WD Min Threshold setting for Windowed Watchdog functionality

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSELLOCK register
//
//*************************************************************************************************
#define SYSCTL_DMACHSRCSELLOCK_DMACHSRCSEL1   0x1U   // DMACHSRCSEL1 Register Lock bit
#define SYSCTL_DMACHSRCSELLOCK_DMACHSRCSEL2   0x2U   // DMACHSRCSEL2 Register Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSEL1 register
//
//*************************************************************************************************
#define SYSCTL_DMACHSRCSEL1_CH1_S   0U
#define SYSCTL_DMACHSRCSEL1_CH1_M   0xFFU         // Selects the Trigger and Sync Source CH1 of DMA
#define SYSCTL_DMACHSRCSEL1_CH2_S   8U
#define SYSCTL_DMACHSRCSEL1_CH2_M   0xFF00U       // Selects the Trigger and Sync Source CH2 of DMA
#define SYSCTL_DMACHSRCSEL1_CH3_S   16U
#define SYSCTL_DMACHSRCSEL1_CH3_M   0xFF0000U     // Selects the Trigger and Sync Source CH3 of DMA
#define SYSCTL_DMACHSRCSEL1_CH4_S   24U
#define SYSCTL_DMACHSRCSEL1_CH4_M   0xFF000000U   // Selects the Trigger and Sync Source CH4 of DMA

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSEL2 register
//
//*************************************************************************************************
#define SYSCTL_DMACHSRCSEL2_CH5_S   0U
#define SYSCTL_DMACHSRCSEL2_CH5_M   0xFFU     // Selects the Trigger and Sync Source CH5 of DMA
#define SYSCTL_DMACHSRCSEL2_CH6_S   8U
#define SYSCTL_DMACHSRCSEL2_CH6_M   0xFF00U   // Selects the Trigger and Sync Source CH6 of DMA

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCA_AC register
//
//*************************************************************************************************
#define SYSCTL_ADCA_AC_CPU1_ACC_S   0U
#define SYSCTL_ADCA_AC_CPU1_ACC_M   0x3U   // CPU1 Access conditions to peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCC_AC register
//
//*************************************************************************************************
#define SYSCTL_ADCC_AC_CPU1_ACC_S   0U
#define SYSCTL_ADCC_AC_CPU1_ACC_M   0x3U   // CPU1 Access conditions to peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS1_AC register
//
//*************************************************************************************************
#define SYSCTL_CMPSS1_AC_CPU1_ACC_S   0U
#define SYSCTL_CMPSS1_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CMPSS1_AC_DMA1_ACC_S   4U
#define SYSCTL_CMPSS1_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_CMPSS1_AC_HICA_ACC_S   6U
#define SYSCTL_CMPSS1_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS2_AC register
//
//*************************************************************************************************
#define SYSCTL_CMPSS2_AC_CPU1_ACC_S   0U
#define SYSCTL_CMPSS2_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CMPSS2_AC_DMA1_ACC_S   4U
#define SYSCTL_CMPSS2_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_CMPSS2_AC_HICA_ACC_S   6U
#define SYSCTL_CMPSS2_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS3_AC register
//
//*************************************************************************************************
#define SYSCTL_CMPSS3_AC_CPU1_ACC_S   0U
#define SYSCTL_CMPSS3_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CMPSS3_AC_DMA1_ACC_S   4U
#define SYSCTL_CMPSS3_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_CMPSS3_AC_HICA_ACC_S   6U
#define SYSCTL_CMPSS3_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS4_AC register
//
//*************************************************************************************************
#define SYSCTL_CMPSS4_AC_CPU1_ACC_S   0U
#define SYSCTL_CMPSS4_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CMPSS4_AC_DMA1_ACC_S   4U
#define SYSCTL_CMPSS4_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_CMPSS4_AC_HICA_ACC_S   6U
#define SYSCTL_CMPSS4_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM1_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM1_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM1_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM1_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM1_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM1_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM1_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM2_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM2_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM2_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM2_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM2_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM2_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM2_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM3_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM3_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM3_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM3_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM3_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM3_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM3_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM4_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM4_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM4_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM4_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM4_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM4_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM4_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM5_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM5_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM5_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM5_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM5_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM5_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM5_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM6_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM6_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM6_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM6_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM6_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM6_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM6_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM7_AC register
//
//*************************************************************************************************
#define SYSCTL_EPWM7_AC_CPU1_ACC_S   0U
#define SYSCTL_EPWM7_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EPWM7_AC_DMA1_ACC_S   4U
#define SYSCTL_EPWM7_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EPWM7_AC_HICA_ACC_S   6U
#define SYSCTL_EPWM7_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP1_AC register
//
//*************************************************************************************************
#define SYSCTL_EQEP1_AC_CPU1_ACC_S   0U
#define SYSCTL_EQEP1_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EQEP1_AC_DMA1_ACC_S   4U
#define SYSCTL_EQEP1_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EQEP1_AC_HICA_ACC_S   6U
#define SYSCTL_EQEP1_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP2_AC register
//
//*************************************************************************************************
#define SYSCTL_EQEP2_AC_CPU1_ACC_S   0U
#define SYSCTL_EQEP2_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_EQEP2_AC_DMA1_ACC_S   4U
#define SYSCTL_EQEP2_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_EQEP2_AC_HICA_ACC_S   6U
#define SYSCTL_EQEP2_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP1_AC register
//
//*************************************************************************************************
#define SYSCTL_ECAP1_AC_CPU1_ACC_S   0U
#define SYSCTL_ECAP1_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_ECAP1_AC_DMA1_ACC_S   4U
#define SYSCTL_ECAP1_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_ECAP1_AC_HICA_ACC_S   6U
#define SYSCTL_ECAP1_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP2_AC register
//
//*************************************************************************************************
#define SYSCTL_ECAP2_AC_CPU1_ACC_S   0U
#define SYSCTL_ECAP2_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_ECAP2_AC_DMA1_ACC_S   4U
#define SYSCTL_ECAP2_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_ECAP2_AC_HICA_ACC_S   6U
#define SYSCTL_ECAP2_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP3_AC register
//
//*************************************************************************************************
#define SYSCTL_ECAP3_AC_CPU1_ACC_S   0U
#define SYSCTL_ECAP3_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_ECAP3_AC_DMA1_ACC_S   4U
#define SYSCTL_ECAP3_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_ECAP3_AC_HICA_ACC_S   6U
#define SYSCTL_ECAP3_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB1_AC register
//
//*************************************************************************************************
#define SYSCTL_CLB1_AC_CPU1_ACC_S   0U
#define SYSCTL_CLB1_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CLB1_AC_HICA_ACC_S   6U
#define SYSCTL_CLB1_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB2_AC register
//
//*************************************************************************************************
#define SYSCTL_CLB2_AC_CPU1_ACC_S   0U
#define SYSCTL_CLB2_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_CLB2_AC_HICA_ACC_S   6U
#define SYSCTL_CLB2_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the SCIA_AC register
//
//*************************************************************************************************
#define SYSCTL_SCIA_AC_CPU1_ACC_S   0U
#define SYSCTL_SCIA_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_SCIA_AC_HICA_ACC_S   6U
#define SYSCTL_SCIA_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIA_AC register
//
//*************************************************************************************************
#define SYSCTL_SPIA_AC_CPU1_ACC_S   0U
#define SYSCTL_SPIA_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_SPIA_AC_DMA1_ACC_S   4U
#define SYSCTL_SPIA_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_SPIA_AC_HICA_ACC_S   6U
#define SYSCTL_SPIA_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIB_AC register
//
//*************************************************************************************************
#define SYSCTL_SPIB_AC_CPU1_ACC_S   0U
#define SYSCTL_SPIB_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_SPIB_AC_DMA1_ACC_S   4U
#define SYSCTL_SPIB_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_SPIB_AC_HICA_ACC_S   6U
#define SYSCTL_SPIB_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2CA_AC register
//
//*************************************************************************************************
#define SYSCTL_I2CA_AC_CPU1_ACC_S   0U
#define SYSCTL_I2CA_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_I2CA_AC_HICA_ACC_S   6U
#define SYSCTL_I2CA_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2CB_AC register
//
//*************************************************************************************************
#define SYSCTL_I2CB_AC_CPU1_ACC_S   0U
#define SYSCTL_I2CB_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_I2CB_AC_HICA_ACC_S   6U
#define SYSCTL_I2CB_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the PMBUS_A_AC register
//
//*************************************************************************************************
#define SYSCTL_PMBUS_A_AC_CPU1_ACC_S   0U
#define SYSCTL_PMBUS_A_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_PMBUS_A_AC_DMA1_ACC_S   4U
#define SYSCTL_PMBUS_A_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_PMBUS_A_AC_HICA_ACC_S   6U
#define SYSCTL_PMBUS_A_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the LIN_A_AC register
//
//*************************************************************************************************
#define SYSCTL_LIN_A_AC_CPU1_ACC_S   0U
#define SYSCTL_LIN_A_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_LIN_A_AC_DMA1_ACC_S   4U
#define SYSCTL_LIN_A_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_LIN_A_AC_HICA_ACC_S   6U
#define SYSCTL_LIN_A_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the LIN_B_AC register
//
//*************************************************************************************************
#define SYSCTL_LIN_B_AC_CPU1_ACC_S   0U
#define SYSCTL_LIN_B_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_LIN_B_AC_DMA1_ACC_S   4U
#define SYSCTL_LIN_B_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_LIN_B_AC_HICA_ACC_S   6U
#define SYSCTL_LIN_B_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCANA_AC register
//
//*************************************************************************************************
#define SYSCTL_DCANA_AC_CPU1_ACC_S   0U
#define SYSCTL_DCANA_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_DCANA_AC_DMA1_ACC_S   4U
#define SYSCTL_DCANA_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_DCANA_AC_HICA_ACC_S   6U
#define SYSCTL_DCANA_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIATX_AC register
//
//*************************************************************************************************
#define SYSCTL_FSIATX_AC_CPU1_ACC_S   0U
#define SYSCTL_FSIATX_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_FSIATX_AC_DMA1_ACC_S   4U
#define SYSCTL_FSIATX_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_FSIATX_AC_HICA_ACC_S   6U
#define SYSCTL_FSIATX_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIARX_AC register
//
//*************************************************************************************************
#define SYSCTL_FSIARX_AC_CPU1_ACC_S   0U
#define SYSCTL_FSIARX_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_FSIARX_AC_DMA1_ACC_S   4U
#define SYSCTL_FSIARX_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_FSIARX_AC_HICA_ACC_S   6U
#define SYSCTL_FSIARX_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRPWM_A_AC register
//
//*************************************************************************************************
#define SYSCTL_HRPWM_A_AC_CPU1_ACC_S   0U
#define SYSCTL_HRPWM_A_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_HRPWM_A_AC_DMA1_ACC_S   4U
#define SYSCTL_HRPWM_A_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_HRPWM_A_AC_HICA_ACC_S   6U
#define SYSCTL_HRPWM_A_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the HIC_A_AC register
//
//*************************************************************************************************
#define SYSCTL_HIC_A_AC_CPU1_ACC_S   0U
#define SYSCTL_HIC_A_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_HIC_A_AC_DMA1_ACC_S   4U
#define SYSCTL_HIC_A_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2S_A_AC register
//
//*************************************************************************************************
#define SYSCTL_I2S_A_AC_CPU1_ACC_S   0U
#define SYSCTL_I2S_A_AC_CPU1_ACC_M   0x3U    // CPU1 Access conditions to peripheral
#define SYSCTL_I2S_A_AC_DMA1_ACC_S   4U
#define SYSCTL_I2S_A_AC_DMA1_ACC_M   0x30U   // DMA1 Access Conditions to Peripheral
#define SYSCTL_I2S_A_AC_HICA_ACC_S   6U
#define SYSCTL_I2S_A_AC_HICA_ACC_M   0xC0U   // HICA Access Contions to Peripheral

//*************************************************************************************************
//
// The following are defines for the bit fields in the PERIPH_AC_LOCK register
//
//*************************************************************************************************
#define SYSCTL_PERIPH_AC_LOCK_LOCK_AC_WR   0x1U   // Lock control for Access control registers write.

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSELECT register
//
//*************************************************************************************************
#define SYSCTL_SYNCSELECT_SYNCOUT_S   24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M   0x1F000000U   // Select Syncout Source

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*************************************************************************************************
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCAEN   0x1U        // PWM1SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCAEN   0x2U        // PWM2SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCAEN   0x4U        // PWM3SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCAEN   0x8U        // PWM4SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCAEN   0x10U       // PWM5SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCAEN   0x20U       // PWM6SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCAEN   0x40U       // PWM7SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCAEN   0x80U       // PWM8SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCBEN   0x10000U    // PWM1SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCBEN   0x20000U    // PWM2SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCBEN   0x40000U    // PWM3SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCBEN   0x80000U    // PWM4SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCBEN   0x100000U   // PWM5SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCBEN   0x200000U   // PWM6SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCBEN   0x400000U   // PWM7SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCBEN   0x800000U   // PWM8SOCBEN Enable for ADCSOCBOn

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*************************************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT        0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT   0x2U   // ADCSOCOUTSELECT Register Lock bit



#endif
