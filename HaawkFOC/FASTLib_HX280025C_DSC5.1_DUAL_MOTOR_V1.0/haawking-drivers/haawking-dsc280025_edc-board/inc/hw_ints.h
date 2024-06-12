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
// Release for HXS320F280025CEDC, Hal DriverLib, 1.0.0
//
// Release time: 2024-01-25 15:09:27.423271
//
//#############################################################################


#ifndef HW_INTS_H
#define HW_INTS_H

//*****************************************************************************
//
// PIE Interrupt Numbers
//
// 0x00FF = PIE Table Row #
// 0xFF00 = PIE Table Column #
// 0xFFFF0000 = PIE Vector ID
//
//*****************************************************************************
#define INT_TIMER1                  0x000D0000U // CPU Timer 1 Interrupt
#define INT_TIMER2                  0x000E0000U // CPU Timer 2 Interrupt
#define INT_RTOS                    0x000F0000U // RTOS Interrupt from ERAD
#define INT_NMI                     0x00120000U // Non-Maskable Interrupt
#define INT_USER1                   0x00140000U // User Defined Trap 1
#define INT_USER2                   0x00150000U // User Defined Trap 2
#define INT_USER3                   0x00160000U // User Defined Trap 3
#define INT_USER4                   0x00170000U // User Defined Trap 4
#define INT_USER5                   0x00180000U // User Defined Trap 5
#define INT_USER6                   0x00190000U // User Defined Trap 6
#define INT_USER7                   0x001A0000U // User Defined Trap 7
#define INT_USER8                   0x001B0000U // User Defined Trap 8
#define INT_USER9                   0x001C0000U // User Defined Trap 9
#define INT_USER10                  0x001D0000U // User Defined Trap 10
#define INT_USER11                  0x001E0000U // User Defined Trap 11
#define INT_USER12                  0x001F0000U // User Defined Trap 12
#define INT_ADCA1                   0x00200101U // 1.1 - ADCA Interrupt 1
#define INT_ADCC1                   0x00220103U // 1.3 - ADCC Interrupt 1
#define INT_XINT1                   0x00230104U // 1.4 - XINT1 Interrupt
#define INT_XINT2                   0x00240105U // 1.5 - XINT2 Interrupt
#define INT_TIMER0                  0x00260107U // 1.7 - Timer 0 Interrupt
#define INT_WAKE                    0x00270108U // 1.8 - Standby and Halt Wakeup Interrupt
#define INT_EPWM1_TZ                0x00300201U // 2.1 - ePWM1 Trip Zone Interrupt
#define INT_EPWM2_TZ                0x00310202U // 2.2 - ePWM2 Trip Zone Interrupt
#define INT_EPWM3_TZ                0x00320203U // 2.3 - ePWM3 Trip Zone Interrupt
#define INT_EPWM4_TZ                0x00330204U // 2.4 - ePWM4 Trip Zone Interrupt
#define INT_EPWM5_TZ                0x00340205U // 2.5 - ePWM5 Trip Zone Interrupt
#define INT_EPWM6_TZ                0x00350206U // 2.6 - ePWM6 Trip Zone Interrupt
#define INT_EPWM7_TZ                0x00360207U // 2.7 - ePWM7 Trip Zone Interrupt
#define INT_EPWM8_TZ                0x00370208U // 2.8 - ePWM8 Trip Zone Interrupt
#define INT_EPWM1                   0x00400301U // 3.1 - ePWM1 Interrupt
#define INT_EPWM2                   0x00410302U // 3.2 - ePWM2 Interrupt
#define INT_EPWM3                   0x00420303U // 3.3 - ePWM3 Interrupt
#define INT_EPWM4                   0x00430304U // 3.4 - ePWM4 Interrupt
#define INT_EPWM5                   0x00440305U // 3.5 - ePWM5 Interrupt
#define INT_EPWM6                   0x00450306U // 3.6 - ePWM6 Interrupt
#define INT_EPWM7                   0x00460307U // 3.7 - ePWM7 Interrupt
#define INT_EPWM8                   0x00470308U // 3.8 - ePWM8 Interrupt
#define INT_ECAP1                   0x00500401U // 4.1 - eCAP1 Interrupt
#define INT_ECAP2                   0x00510402U // 4.2 - eCAP2 Interrupt
#define INT_ECAP3                   0x00520403U // 4.3 - eCAP3 Interrupt
#define INT_EQEP1                   0x00600501U // 5.1 - eQEP1 Interrupt
#define INT_EQEP2                   0x00610502U // 5.2 - eQEP2 Interrupt
#define INT_CLB1                    0x00640505U // 5.5 - CLB1 (Reconfigurable Logic) Interrupt
#define INT_CLB2                    0x00650506U // 5.6 - CLB2 (Reconfigurable Logic) Interrupt
#define INT_SPIA_RX                 0x00700601U // 6.1 - SPIA Receive Interrupt
#define INT_SPIA_TX                 0x00710602U // 6.2 - SPIA Transmit Interrupt
#define INT_SPIB_RX                 0x00720603U // 6.3 - SPIB Receive Interrupt
#define INT_SPIB_TX                 0x00730604U // 6.4 - SPIB Transmit Interrupt
#define INT_DMA_CH1                 0x00800701U // 7.1 - DMA Channel 1 Interrupt
#define INT_DMA_CH2                 0x00810702U // 7.2 - DMA Channel 2 Interrupt
#define INT_DMA_CH3                 0x00820703U // 7.3 - DMA Channel 3 Interrupt
#define INT_DMA_CH4                 0x00830704U // 7.4 - DMA Channel 4 Interrupt
#define INT_DMA_CH5                 0x00840705U // 7.5 - DMA Channel 5 Interrupt
#define INT_DMA_CH6                 0x00850706U // 7.6 - DMA Channel 6 Interrupt
#define INT_I2CA                    0x00900801U // 8.1 - I2CA Interrupt 1
#define INT_I2CA_FIFO               0x00910802U // 8.2 - I2CA Interrupt 2
#define INT_I2CB                    0x00920803U // 8.3 - I2CB Interrupt 1
#define INT_I2CB_FIFO               0x00930804U // 8.4 - I2CB Interrupt 2
#define INT_SCIA_RX                 0x00A00901U // 9.1 - SCIA Receive Interrupt
#define INT_SCIA_TX                 0x00A10902U // 9.2 - SCIA Transmit Interrupt
#define INT_CANA0                   0x00A40905U // 9.5 - CANA Interrupt 0
#define INT_CANA1                   0x00A50906U // 9.6 - CANA Interrupt 1
#define INT_ADCA_EVT                0x00B00A01U // 10.1 - ADCA Event Interrupt
#define INT_ADCA2                   0x00B10A02U // 10.2 - ADCA Interrupt 2
#define INT_ADCA3                   0x00B20A03U // 10.3 - ADCA Interrupt 3
#define INT_ADCA4                   0x00B30A04U // 10.4 - ADCA Interrupt 4
#define INT_XINT3                   0x00D00C01U // 12.1 - XINT3 Interrupt
#define INT_XINT4                   0x00D10C02U // 12.2 - XINT4 Interrupt
#define INT_XINT5                   0x00D20C03U // 12.3 - XINT5 Interrupt
#define INT_MPOST                   0x00D30C04U // 12.4 - MPOST Interrupt
#define INT_FMC                     0x00D40C05U // 12.5 - Flash Wrapper Operation Done Interrupt
#define INT_FPU_OVERFLOW            0x00D60C07U // 12.7 - FPU Overflow Interrupt
#define INT_FPU_UNDERFLOW           0x00D70C08U // 12.8 - FPU Underflow Interrupt
#define INT_ECAP3_2                 0x005A040BU // 4.11 - eCAP3 Interrupt 2
#define INT_I2STXINT                0x00880709U // 7.9 - I2STX Interrupt
#define INT_I2SRXINT                0x0089070AU // 7.10 - I2SRX Interrupt
#define INT_FSITXA1                 0x008A070BU // 7.11 - FSITXA_INT1 Interrupt
#define INT_FSITXA2                 0x008B070CU // 7.12 - FSITXA_INT2 Interrupt
#define INT_FSIRXA1                 0x008C070DU // 7.13 - FSIRXA_INT1 Interrupt
#define INT_FSIRXA2                 0x008D070EU // 7.14 - FSIRXA_INT2 Interrupt
#define INT_DCC0                    0x008F0710U // 7.16 - DCC0 Interrupt
#define INT_LINA_0                  0x00980809U // 8.9 - LINA interrupt 0
#define INT_LINA_1                  0x0099080AU // 8.10 - LINA interrupt 1
#define INT_LINB_0                  0x009A080BU // 8.11 - LINB interrupt 0
#define INT_LINB_1                  0x009B080CU // 8.12 - LINB interrupt 1
#define INT_PMBUSA                  0x009C080DU // 8.13 - PMBUSA interrupt
#define INT_DCC1                    0x009F0810U // 8.16 - DCC1 interrupt
#define INT_BGCRC                   0x00AC090DU // 9.13 - BGCRC interrupt
#define INT_HICA                    0x00AF0910U // 9.16 - HICA interrupt
#define INT_ADCC_EVT                0x00B00A09U // 10.9 - ADCC event interrupt
#define INT_ADCC2                   0x00B90A0AU // 10.10 - ADCC interrupt 2
#define INT_ADCC3                   0x00BA0A0BU // 10.11 - ADCC interrupt 3
#define INT_ADCC4                   0x00BB0A0CU // 10.12 - ADCC interrupt 4
#define INT_RAM_CORR_ERR            0x00D90C0AU // 12.10 - RAM Correctable Error Interrupt
#define INT_FLASH_CORR_ERR          0x00DA0C0BU // 12.11 - Flash Correctable Error Interrupt
#define INT_RAM_ACC_VIOL            0x00DB0C0CU // 12.12 - RAM Access Violation Interrupt
#define INT_SYS_PLL_SLIP            0x00DC0C0DU // 12.13 - System PLL Interrupt


#endif // HW_INTS_H
