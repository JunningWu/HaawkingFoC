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


#ifndef F28002X_PIEVECT_H
#define F28002X_PIEVECT_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PIEVECT Individual Register Bit Definitions:

struct  PIE_VECT_TABLE {
    PINT                                     rsvd1[13];                   // 0x0 Reserved
    PINT                                     TIMER1_INT;                  // 0x34 CPU Timer 1 Interrupt
    PINT                                     TIMER2_INT;                  // 0x38 CPU Timer 2 Interrupt
    PINT                                     rsvd2;                       // 0x3c Reserved
    PINT                                     RTOS_INT;                    // 0x40 RTOS Interrupt from ERAD
    PINT                                     rsvd3;                       // 0x44 Reserved
    PINT                                     NMI_INT;                     // 0x48 Non-Maskable Interrupt
    PINT                                     rsvd4[13];                   // 0x4c Reserved
    PINT                                     ADCA1_INT;                   // 0x80 1.1 - ADCA Interrupt 1
    PINT                                     PIE14_RESERVED_INT;          // 0x84 1.2 - Reserved
    PINT                                     ADCC1_INT;                   // 0x88 1.3 - ADCC Interrupt 1
    PINT                                     XINT1_INT;                   // 0x8c 1.4 - XINT1 Interrupt
    PINT                                     XINT2_INT;                   // 0x90 1.5 - XINT2 Interrupt
    PINT                                     PIE15_RESERVED_INT;          // 0x94 1.6 - Reserved
    PINT                                     TIMER0_INT;                  // 0x98 1.7 - Timer 0 Interrupt
    PINT                                     WAKE_INT;                    // 0x9c 1.8 - Standby and Halt Wakeup Interrupt
    PINT                                     PIE54_RESERVED_INT;          // 0xa0 1.9 - Reserved
    PINT                                     PIE55_RESERVED_INT;          // 0xa4 1.10 - Reserved
    PINT                                     PIE56_RESERVED_INT;          // 0xa8 1.11 - Reserved
    PINT                                     PIE57_RESERVED_INT;          // 0xac 1.12 - Reserved
    PINT                                     PIE58_RESERVED_INT;          // 0xb0 1.13 - Reserved
    PINT                                     PIE59_RESERVED_INT;          // 0xb4 1.14 - Reserved
    PINT                                     PIE60_RESERVED_INT;          // 0xb8 1.15 - Reserved
    PINT                                     PIE61_RESERVED_INT;          // 0xbc 1.16 - Reserved
    PINT                                     EPWM1_TZ_INT;                // 0xc0 2.1 - ePWM1 Trip Zone Interrupt
    PINT                                     EPWM2_TZ_INT;                // 0xc4 2.2 - ePWM2 Trip Zone Interrupt
    PINT                                     EPWM3_TZ_INT;                // 0xc8 2.3 - ePWM3 Trip Zone Interrupt
    PINT                                     EPWM4_TZ_INT;                // 0xcc 2.4 - ePWM4 Trip Zone Interrupt
    PINT                                     EPWM5_TZ_INT;                // 0xd0 2.5 - ePWM5 Trip Zone Interrupt
    PINT                                     EPWM6_TZ_INT;                // 0xd4 2.6 - ePWM6 Trip Zone Interrupt
    PINT                                     EPWM7_TZ_INT;                // 0xd8 2.7 - ePWM7 Trip Zone Interrupt
    PINT                                     EPWM8_TZ_INT;                // 0xdc 2.8 - ePWM8 Trip Zone Interrupt
    PINT                                     PIE62_RESERVED_INT;          // 0xe0 2.9 - Reserved
    PINT                                     PIE63_RESERVED_INT;          // 0xe4 2.10 - Reserved
    PINT                                     PIE64_RESERVED_INT;          // 0xe8 2.11 - Reserved
    PINT                                     PIE65_RESERVED_INT;          // 0xec 2.12 - Reserved
    PINT                                     PIE66_RESERVED_INT;          // 0xf0 2.13 - Reserved
    PINT                                     PIE67_RESERVED_INT;          // 0xf4 2.14 - Reserved
    PINT                                     PIE68_RESERVED_INT;          // 0xf8 2.15 - Reserved
    PINT                                     PIE69_RESERVED_INT;          // 0xfc 2.16 - Reserved
    PINT                                     EPWM1_INT;                   // 0x100 3.1 - ePWM1 Interrupt
    PINT                                     EPWM2_INT;                   // 0x104 3.2 - ePWM2 Interrupt
    PINT                                     EPWM3_INT;                   // 0x108 3.3 - ePWM3 Interrupt
    PINT                                     EPWM4_INT;                   // 0x10c 3.4 - ePWM4 Interrupt
    PINT                                     EPWM5_INT;                   // 0x110 3.5 - ePWM5 Interrupt
    PINT                                     EPWM6_INT;                   // 0x114 3.6 - ePWM6 Interrupt
    PINT                                     EPWM7_INT;                   // 0x118 3.7 - ePWM7 Interrupt
    PINT                                     EPWM8_INT;                   // 0x11c 3.8 - ePWM8 Interrupt
    PINT                                     PIE70_RESERVED_INT;          // 0x120 3.9 - Reserved
    PINT                                     PIE71_RESERVED_INT;          // 0x124 3.10 - Reserved
    PINT                                     PIE72_RESERVED_INT;          // 0x128 3.11 - Reserved
    PINT                                     PIE73_RESERVED_INT;          // 0x12c 3.12 - Reserved
    PINT                                     PIE74_RESERVED_INT;          // 0x130 3.13 - Reserved
    PINT                                     PIE75_RESERVED_INT;          // 0x134 3.14 - Reserved
    PINT                                     PIE76_RESERVED_INT;          // 0x138 3.15 - Reserved
    PINT                                     PIE77_RESERVED_INT;          // 0x13c 3.16 - Reserved
    PINT                                     ECAP1_INT;                   // 0x140 4.1 - eCAP1 Interrupt
    PINT                                     ECAP2_INT;                   // 0x144 4.2 - eCAP2 Interrupt
    PINT                                     ECAP3_INT;                   // 0x148 4.3 - eCAP3 Interrupt
    PINT                                     PIE18_RESERVED_INT;          // 0x14c 4.4 - Reserved
    PINT                                     PIE19_RESERVED_INT;          // 0x150 4.5 - Reserved
    PINT                                     PIE20_RESERVED_INT;          // 0x154 4.6 - Reserved
    PINT                                     PIE21_RESERVED_INT;          // 0x158 4.7 - Reserved
    PINT                                     PIE22_RESERVED_INT;          // 0x15c 4.8 - Reserved
    PINT                                     PIE78_RESERVED_INT;          // 0x160 4.9 - Reserved
    PINT                                     PIE79_RESERVED_INT;          // 0x164 4.10 - Reserved
    PINT                                     ECAP3_2_INT;                 // 0x168 4.11 - eCAP3_2 Interrupt
    PINT                                     PIE80_RESERVED_INT;          // 0x16c 4.12 - Reserved
    PINT                                     PIE81_RESERVED_INT;          // 0x170 4.13 - Reserved
    PINT                                     PIE82_RESERVED_INT;          // 0x174 4.14 - Reserved
    PINT                                     PIE83_RESERVED_INT;          // 0x178 4.15 - Reserved
    PINT                                     PIE84_RESERVED_INT;          // 0x17c 4.16 - Reserved
    PINT                                     EQEP1_INT;                   // 0x180 5.1 - eQEP1 Interrupt
    PINT                                     EQEP2_INT;                   // 0x184 5.2 - eQEP2 Interrupt
    PINT                                     PIE23_RESERVED_INT;          // 0x188 5.3 - Reserved
    PINT                                     PIE24_RESERVED_INT;          // 0x18c 5.4 - Reserved
    PINT                                     CLB1_INT;                    // 0x190 5.5 - CLB1 (Reconfigurable Logic) Interrupt
    PINT                                     CLB2_INT;                    // 0x194 5.6 - CLB2 (Reconfigurable Logic) Interrupt
    PINT                                     PIE25_RESERVED_INT;          // 0x198 5.7 - Reserved
    PINT                                     PIE26_RESERVED_INT;          // 0x19c 5.8 - Reserved
    PINT                                     PIE85_RESERVED_INT;          // 0x1a0 5.9 - Reserved
    PINT                                     PIE86_RESERVED_INT;          // 0x1a4 5.10 - Reserved
    PINT                                     PIE87_RESERVED_INT;          // 0x1a8 5.11 - Reserved
    PINT                                     PIE88_RESERVED_INT;          // 0x1ac 5.12 - Reserved
    PINT                                     PIE89_RESERVED_INT;          // 0x1b0 5.13 - Reserved
    PINT                                     PIE90_RESERVED_INT;          // 0x1b4 5.14 - Reserved
    PINT                                     PIE91_RESERVED_INT;          // 0x1b8 5.15 - Reserved
    PINT                                     PIE92_RESERVED_INT;          // 0x1bc 5.16 - Reserved
    PINT                                     SPIA_RX_INT;                 // 0x1c0 6.1 - SPIA Receive Interrupt
    PINT                                     SPIA_TX_INT;                 // 0x1c4 6.2 - SPIA Transmit Interrupt
    PINT                                     SPIB_RX_INT;                 // 0x1c8 6.3 - SPIB Receive Interrupt
    PINT                                     SPIB_TX_INT;                 // 0x1cc 6.4 - SPIB Transmit Interrupt
    PINT                                     PIE27_RESERVED_INT;          // 0x1d0 6.5 - Reserved
    PINT                                     PIE28_RESERVED_INT;          // 0x1d4 6.6 - Reserved
    PINT                                     PIE29_RESERVED_INT;          // 0x1d8 6.7 - Reserved
    PINT                                     PIE30_RESERVED_INT;          // 0x1dc 6.8 - Reserved
    PINT                                     PIE93_RESERVED_INT;          // 0x1e0 6.9 - Reserved
    PINT                                     PIE94_RESERVED_INT;          // 0x1e4 6.10 - Reserved
    PINT                                     PIE95_RESERVED_INT;          // 0x1e8 6.11 - Reserved
    PINT                                     PIE96_RESERVED_INT;          // 0x1ec 6.12 - Reserved
    PINT                                     PIE97_RESERVED_INT;          // 0x1f0 6.13 - Reserved
    PINT                                     PIE98_RESERVED_INT;          // 0x1f4 6.14 - Reserved
    PINT                                     PIE99_RESERVED_INT;          // 0x1f8 6.15 - Reserved
    PINT                                     PIE100_RESERVED_INT;         // 0x1fc 6.16 - Reserved
    PINT                                     DMA_CH1_INT;                 // 0x200 7.1 - DMA Channel 1 Interrupt
    PINT                                     DMA_CH2_INT;                 // 0x204 7.2 - DMA Channel 2 Interrupt
    PINT                                     DMA_CH3_INT;                 // 0x208 7.3 - DMA Channel 3 Interrupt
    PINT                                     DMA_CH4_INT;                 // 0x20c 7.4 - DMA Channel 4 Interrupt
    PINT                                     DMA_CH5_INT;                 // 0x210 7.5 - DMA Channel 5 Interrupt
    PINT                                     DMA_CH6_INT;                 // 0x214 7.6 - DMA Channel 6 Interrupt
    PINT                                     PIE31_RESERVED_INT;          // 0x218 7.7 - Reserved
    PINT                                     PIE32_RESERVED_INT;          // 0x21c 7.8 - Reserved
    PINT                                     PIE101_RESERVED_INT;         // 0x220 7.9 - Reserved
    PINT                                     PIE102_RESERVED_INT;         // 0x224 7.10 - Reserved
    PINT                                     FSITXA1_INT;                 // 0x228 7.11 - FSITXA_INT1 Interrupt
    PINT                                     FSITXA2_INT;                 // 0x22c 7.12 - FSITXA_INT2 Interrupt
    PINT                                     FSIRXA1_INT;                 // 0x230 7.13 - FSIRXA_INT1 Interrupt
    PINT                                     FSIRXA2_INT;                 // 0x234 7.14 - FSIRXA_INT2 Interrupt
    PINT                                     PIE103_RESERVED_INT;         // 0x238 7.15 - Reserved
    PINT                                     DCC0_INT;                    // 0x23c 7.16 - DCC0 Interrupt
    PINT                                     I2CA_INT;                    // 0x240 8.1 - I2CA Interrupt 1
    PINT                                     I2CA_FIFO_INT;               // 0x244 8.2 - I2CA Interrupt 2
    PINT                                     I2CB_INT;                    // 0x248 8.3 - I2CB Interrupt 1
    PINT                                     I2CB_FIFO_INT;               // 0x24c 8.4 - I2CB Interrupt 2
    PINT                                     PIE33_RESERVED_INT;          // 0x250 8.5 - Reserved
    PINT                                     PIE34_RESERVED_INT;          // 0x254 8.6 - Reserved
    PINT                                     PIE35_RESERVED_INT;          // 0x258 8.7 - Reserved
    PINT                                     PIE36_RESERVED_INT;          // 0x25c 8.8 - Reserved
    PINT                                     LINA_0_INT;                  // 0x260 8.9 - LINA Interrupt0
    PINT                                     LINA_1_INT;                  // 0x264 8.10 - LINA Interrupt1
    PINT                                     LINB_0_INT;                  // 0x268 8.11 - LINB Interrupt0
    PINT                                     LINB_1_INT;                  // 0x26c 8.12 - LINB Interrupt1
    PINT                                     PMBUSA_INT;                  // 0x270 8.13 - PMBUSA Interrupt
    PINT                                     PIE104_RESERVED_INT;         // 0x274 8.14 - Reserved
    PINT                                     PIE105_RESERVED_INT;         // 0x278 8.15 - Reserved
    PINT                                     DCC1_INT;                    // 0x27c 8.16 - DCC1 Interrupt
    PINT                                     SCIA_RX_INT;                 // 0x280 9.1 - SCIA Receive Interrupt
    PINT                                     SCIA_TX_INT;                 // 0x284 9.2 - SCIA Transmit Interrupt
    PINT                                     PIE37_RESERVED_INT;          // 0x288 9.3 - Reserved
    PINT                                     PIE38_RESERVED_INT;          // 0x28c 9.4 - Reserved
    PINT                                     CANA0_INT;                   // 0x290 9.5 - CANA Interrupt 0
    PINT                                     CANA1_INT;                   // 0x294 9.6 - CANA Interrupt 1
    PINT                                     PIE39_RESERVED_INT;          // 0x298 9.7 - Reserved
    PINT                                     PIE40_RESERVED_INT;          // 0x29c 9.8 - Reserved
    PINT                                     PIE106_RESERVED_INT;         // 0x2a0 9.9 - Reserved
    PINT                                     PIE107_RESERVED_INT;         // 0x2a4 9.10 - Reserved
    PINT                                     PIE108_RESERVED_INT;         // 0x2a8 9.11 - Reserved
    PINT                                     PIE109_RESERVED_INT;         // 0x2ac 9.12 - Reserved
    PINT                                     BGCRC_INT;                   // 0x2b0 9.13 - BGCRC
    PINT                                     PIE110_RESERVED_INT;         // 0x2b4 9.14 - Reserved
    PINT                                     PIE111_RESERVED_INT;         // 0x2b8 9.15 - Reserved
    PINT                                     HICA_INT;                    // 0x2bc 9.16 - HICA Interrupt
    PINT                                     ADCA_EVT_INT;                // 0x2c0 10.1 - ADCA Event Interrupt
    PINT                                     ADCA2_INT;                   // 0x2c4 10.2 - ADCA Interrupt 2
    PINT                                     ADCA3_INT;                   // 0x2c8 10.3 - ADCA Interrupt 3
    PINT                                     ADCA4_INT;                   // 0x2cc 10.4 - ADCA Interrupt 4
    PINT                                     PIE41_RESERVED_INT;          // 0x2d0 10.5 - Reserved
    PINT                                     PIE42_RESERVED_INT;          // 0x2d4 10.6 - Reserved
    PINT                                     PIE43_RESERVED_INT;          // 0x2d8 10.7 - Reserved
    PINT                                     PIE44_RESERVED_INT;          // 0x2dc 10.8 - Reserved
    PINT                                     ADCC_EVT_INT;                // 0x2e0 10.9 - ADCC Event Interrupt
    PINT                                     ADCC2_INT;                   // 0x2e4 10.10 - ADCC Interrupt 2
    PINT                                     ADCC3_INT;                   // 0x2e8 10.11 - ADCC Interrupt 3
    PINT                                     ADCC4_INT;                   // 0x2ec 10.12 - ADCC Interrupt 4
    PINT                                     PIE112_RESERVED_INT;         // 0x2f0 10.13 - Reserved
    PINT                                     PIE113_RESERVED_INT;         // 0x2f4 10.14 - Reserved
    PINT                                     PIE114_RESERVED_INT;         // 0x2f8 10.15 - Reserved
    PINT                                     PIE115_RESERVED_INT;         // 0x2fc 10.16 - Reserved
    PINT                                     PIE45_RESERVED_INT;          // 0x300 11.1 - Reserved
    PINT                                     PIE46_RESERVED_INT;          // 0x304 11.2 - Reserved
    PINT                                     PIE47_RESERVED_INT;          // 0x308 11.3 - Reserved
    PINT                                     PIE48_RESERVED_INT;          // 0x30c 11.4 - Reserved
    PINT                                     PIE49_RESERVED_INT;          // 0x310 11.5 - Reserved
    PINT                                     PIE50_RESERVED_INT;          // 0x314 11.6 - Reserved
    PINT                                     PIE51_RESERVED_INT;          // 0x318 11.7 - Reserved
    PINT                                     PIE52_RESERVED_INT;          // 0x31c 11.8 - Reserved
    PINT                                     PIE116_RESERVED_INT;         // 0x320 11.9 - Reserved
    PINT                                     PIE117_RESERVED_INT;         // 0x324 11.10 - Reserved
    PINT                                     PIE118_RESERVED_INT;         // 0x328 11.11 - Reserved
    PINT                                     PIE119_RESERVED_INT;         // 0x32c 11.12 - Reserved
    PINT                                     PIE120_RESERVED_INT;         // 0x330 11.13 - Reserved
    PINT                                     PIE121_RESERVED_INT;         // 0x334 11.14 - Reserved
    PINT                                     PIE122_RESERVED_INT;         // 0x338 11.15 - Reserved
    PINT                                     PIE123_RESERVED_INT;         // 0x33c 11.16 - Reserved
    PINT                                     XINT3_INT;                   // 0x340 12.1 - XINT3 Interrupt
    PINT                                     XINT4_INT;                   // 0x344 12.2 - XINT4 Interrupt
    PINT                                     XINT5_INT;                   // 0x348 12.3 - XINT5 Interrupt
    PINT                                     MPOST_INT;                   // 0x34c 12.4 - MPOST Interrupt
    PINT                                     FMC_INT;                     // 0x350 12.5 - Flash Wrapper Operation Done Interrupt
    PINT                                     PIE53_RESERVED_INT;          // 0x354 12.6 - Reserved
    PINT                                     FPU_OVERFLOW_INT;            // 0x358 12.7 - FPU Overflow Interrupt
    PINT                                     FPU_UNDERFLOW_INT;           // 0x35c 12.8 - FPU Underflow Interrupt
    PINT                                     PIE124_RESERVED_INT;         // 0x360 12.9 - Reserved
    PINT                                     RAM_CORR_ERR_INT;            // 0x364 12.10 - RAM Correctable Error Interrupt
    PINT                                     FLASH_CORR_ERR_INT;          // 0x368 12.11 - Flash Correctable Error Interrupt
    PINT                                     RAM_ACC_VIOL_INT;            // 0x36c 12.12 - RAM Access Violation Interrupt
    PINT                                     SYS_PLL_SLIP_INT;            // 0x370 12.13 - System PLL Interrupt
    PINT                                     PIE125_RESERVED_INT;         // 0x374 12.14 - Reserved
    PINT                                     PIE126_RESERVED_INT;         // 0x378 12.15 - Reserved
    PINT                                     PIE127_RESERVED_INT;         // 0x37c 12.16 - Reserved
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================