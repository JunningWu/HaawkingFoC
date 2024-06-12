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

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H


//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define M0_RAM_BASE               0x00000000U
#define M1_RAM_BASE               0x00000800U
#define ADCARESULT_BASE           0x00001940U
#define ADCCRESULT_BASE           0x00001D40U
#define CPUTIMER0_BASE            0x00005000U
#define CPUTIMER1_BASE            0x00005010U
#define CPUTIMER2_BASE            0x00005020U
#define PIECTRL_BASE              0x00005100U
#define PIEVECTTABLE_BASE         0x00005800U
#define DMA_BASE                  0x00003000U
#define DMA_CH1_BASE              0x00003080U
#define DMA_CH2_BASE              0x00003100U
#define DMA_CH3_BASE              0x00003180U
#define DMA_CH4_BASE              0x00003200U
#define DMA_CH5_BASE              0x00003280U
#define DMA_CH6_BASE              0x00003300U
#define CLB1_BASE                 0x0000C000U
#define CLB1_LOGICCFG_BASE        0x0000C000U
#define CLB1_LOGICCTRL_BASE       0x0000C100U
#define CLB1_DATAEXCH_BASE        0x0000C180U
#define CLB2_BASE                 0x0000C400U
#define CLB2_LOGICCFG_BASE        0x0000C400U
#define CLB2_LOGICCTRL_BASE       0x0000C500U
#define CLB2_DATAEXCH_BASE        0x0000C580U
#define EPWM1_BASE                0x0000A000U
#define EPWM2_BASE                0x0000A400U
#define EPWM3_BASE                0x0000A800U
#define EPWM4_BASE                0x0000AC00U
#define EPWM5_BASE                0x0000B000U
#define EPWM6_BASE                0x0000B400U
#define EPWM7_BASE                0x0000B800U
#define EPWM8_BASE                0x0000BC00U
#define EQEP1_BASE                0x0000D000U
#define EQEP2_BASE                0x0000D140U
#define ECAP1_BASE                0x0000D400U
#define ECAP2_BASE                0x0000D480U
#define ECAP3_BASE                0x0000D500U
#define HRCAP3_BASE               0x0000D780U
#define CMPSS1_BASE               0x0000D800U
#define CMPSS2_BASE               0x0000D880U
#define CMPSS3_BASE               0x0000D900U
#define CMPSS4_BASE               0x0000D980U
#define SPIA_BASE                 0x0000E000U
#define SPIB_BASE                 0x0000E080U
#define I2S_BASE                  0x0000EC00U
#define BGCRC_CPU_BASE            0x00003400U
#define PMBUSA_BASE               0x0000E400U
#define HIC_BASE                  0x00002800U
#define FSITXA_BASE               0x0000Ea00U
#define FSIRXA_BASE               0x0000E800U   
#define LINA_BASE                 0x00034000U
#define LINB_BASE                 0x00034080U
#define WD_BASE                   0x00038E00U
#define NMI_BASE                  0x00005300U
#define XINT_BASE                 0x00005200U
#define SCIA_BASE                 0x00034400U
#define I2CA_BASE                 0x00034800U
#define I2CB_BASE                 0x00034880U
#define ADCA_BASE                 0x00001800U
#define ADCC_BASE                 0x00001C00U
#define INPUTXBAR_BASE            0x00031000U
#define XBAR_BASE                 0x00031080U
#define SYNCSOC_BASE              0x00038C00U
#define CLBINPUTXBAR_BASE         0x00031180U
#define DMACLASRCSEL_BASE         0x00038D00U
#define EPWMXBAR_BASE             0x00031400U
#define CLBXBAR_BASE              0x00031500U
#define OUTPUTXBAR_BASE           0x00031600U
#define CLBOUTPUTXBAR_BASE        0x00031B00U
#define GPIOCTRL_BASE             0x00033800U
#define GPIODATA_BASE             0x00033E00U
#define GPIODATAREAD_BASE         0x00033F00U
#define LS4_RAM_BASE              0x00010000U
#define LS5_RAM_BASE              0x00012000U
#define LS6_RAM_BASE              0x00014000U
#define LS7_RAM_BASE              0x00016000U
#define GS0_RAM_BASE              0x00018000U
#define CANA_BASE                 0x00006000U
#define CANA_MSG_RAM_BASE         0x00006400U
#define DEVCFG_BASE               0x00038400U
#define CLKCFG_BASE               0x00038000U
#define CPUSYS_BASE               0x00038200U
#define PERIPHAC_BASE             0x00038800U
#define ANALOGSUBSYS_BASE         0x00039000U
#define PBIST_BASE                0x000038B0U
#define DCC0_BASE                 0x00033000U
#define DCC1_BASE                 0x00033080U
#define ERAD_GLOBAL_BASE          0x00032800U
#define ERAD_HWBP1_BASE           0x000328FCU
#define ERAD_HWBP2_BASE           0x00032910U
#define ERAD_HWBP3_BASE           0x00032924U
#define ERAD_HWBP4_BASE           0x00032938U
#define ERAD_HWBP5_BASE           0x0003294CU
#define ERAD_HWBP6_BASE           0x00032960U
#define ERAD_HWBP7_BASE           0x00032974U
#define ERAD_HWBP8_BASE           0x00032988U
#define ERAD_COUNTER1_BASE        0x0003299CU
#define ERAD_COUNTER2_BASE        0x000329C0U
#define ERAD_COUNTER3_BASE        0x000329E4U
#define ERAD_COUNTER4_BASE        0x00032A08U
#define ERAD_CRC_GLOBAL_BASE      0x00032A2CU
#define ERAD_CRC1_BASE            0x00032A30U
#define ERAD_CRC2_BASE            0x00032A3CU
#define ERAD_CRC3_BASE            0x00032A48U
#define ERAD_CRC4_BASE            0x00032A54U
#define ERAD_CRC5_BASE            0x00032A60U
#define ERAD_CRC6_BASE            0x00032A6CU
#define ERAD_CRC7_BASE            0x00032A78U
#define ERAD_CRC8_BASE            0x00032A84U
#define DCSMBANK0_Z1_BASE         0x00039400U
#define DCSMBANK0_Z2_BASE         0x00039450U
#define DCSMCOMMON_BASE           0x000394A0U
#define MEMCFG_BASE               0x00003800U
#define ACCESSPROTECTION_BASE     0x0000389CU
#define MEMORYERROR_BASE          0x0000385CU
#define FLASH0CTRL_BASE           0x007AF000U
#define FLASH0ECC_BASE            0x007AF200U
#define DCSMBANK0_Z1OTP_BASE      0x007A0000U
#define DCSMBANK0_Z2OTP_BASE      0x007A0400U
#endif
