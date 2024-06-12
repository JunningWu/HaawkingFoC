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


#ifndef HW_FLASH_H
#define HW_FLASH_H

//*************************************************************************************************
//
// The following are defines for the FLASH register offsets
//
//*************************************************************************************************
#define FLASH_O_INIT            0x0U     // flash init Register No configuration required,automatic initialzation after power-on
#define FLASH_O_FRDCNTL         0x4U     // Flash Read Control Register
#define FLASH_O_FBFALLBACK      0x8U     // Flash Bank Fallback Power Register
#define FLASH_O_FBAC2           0xCU     // Flash Bank Access Control Register
#define FLASH_O_FMSTAT          0x10U    // FLASH status register
#define FLASH_O_FRD_INTF_CTRL   0x14U    // Flash Read Interface Control Register
#define FLASH_O_FT100N          0x80U    // 100ns Control Word
#define FLASH_O_FT4U            0x84U    // 4us Control Word
#define FLASH_O_FT5U            0x88U    // 5us Control Word
#define FLASH_O_FT9U            0x8CU    // 9us Control Word
#define FLASH_O_FT20U           0x90U    // 20us Control Word
#define FLASH_O_FT25U           0x94U    // 25us Control Word
#define FLASH_O_FT50U           0x98U    // 50us Control Word
#define FLASH_O_FT900U          0x9CU    // 900us Control Word
#define FLASH_O_FT4M            0xA0U    // 3600us Control Word
#define FLASH_O_FT9M            0xA4U    // 9ms Control Word

#define FLASH_O_ECC_ENABLE             0x0U    // ECC Enable
#define FLASH_O_SINGLE_ERR_ADDR_LOW    0x4U    // Single Error Address Low
#define FLASH_O_SINGLE_ERR_ADDR_HIGH   0x8U    // Single Error Address High
#define FLASH_O_UNC_ERR_ADDR_LOW       0xCU    // Uncorrectable Error Address Low
#define FLASH_O_UNC_ERR_ADDR_HIGH      0x10U   // Uncorrectable Error Address High
#define FLASH_O_ERR_STATUS             0x14U   // Error Status
#define FLASH_O_ERR_STATUS_CLR         0x1CU   // Error Status Clear
#define FLASH_O_ERR_CNT                0x20U   // Error Control
#define FLASH_O_ERR_THRESHOLD          0x24U   // Error Threshold
#define FLASH_O_ERR_INTFLG             0x28U   // Error Interrupt Flag
#define FLASH_O_ERR_INTCLR             0x2CU   // Error Interrupt Flag Clear
#define FLASH_O_FDATAH_TEST            0x30U   // Data High Test
#define FLASH_O_FDATAL_TEST            0x34U   // Data Low Test
#define FLASH_O_FADDR_TEST             0x38U   // ECC Test Address
#define FLASH_O_FECC_TEST              0x3CU   // ECC Test Address
#define FLASH_O_FECC_CTRL              0x40U   // ECC Control
#define FLASH_O_FOUTH_TEST             0x44U   // Test Data Out High
#define FLASH_O_FOUTL_TEST             0x48U   // Test Data Out Low
#define FLASH_O_FECC_STATUS            0x4CU   // ECC Status


//*************************************************************************************************
//
// The following are defines for the bit fields in the FRDCNTL register
//
//*************************************************************************************************
#define FLASH_FRDCNTL_RWAIT_S   0U
#define FLASH_FRDCNTL_RWAIT_M   0x7U   // Flash Read Control Word

//*************************************************************************************************
//
// The following are defines for the bit fields in the FBFALLBACK register
//
//*************************************************************************************************
#define FLASH_FBFALLBACK_BNKPWR0_S   0U
#define FLASH_FBFALLBACK_BNKPWR0_M   0x3U   // Bank Power Mode of BANK0

//*************************************************************************************************
//
// The following are defines for the bit fields in the FBAC2 register
//
//*************************************************************************************************
#define FLASH_FBAC2_PAGP_S   0U
#define FLASH_FBAC2_PAGP_M   0xFFFFU   // Control continuous access to flash time

//*************************************************************************************************
//
// The following are defines for the bit fields in the FMSTAT register
//
//*************************************************************************************************
#define FLASH_FMSTAT_STATUS_S      0U
#define FLASH_FMSTAT_STATUS_M      0x3FU   // Status register
#define FLASH_FMSTAT_INIT_FINISH   0x40U   // Power on initialization completion flag signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRD_INTF_CTRL register
//
//*************************************************************************************************
#define FLASH_FRD_INTF_CTRL_PREFETCH_EN     0x1U   // Prefetch Enable
#define FLASH_FRD_INTF_CTRL_DATA_CACHE_EN   0x2U   // Data Cache Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECC_ENABLE register
//
//*************************************************************************************************
#define FLASH_ECC_ENABLE_ENABLE_S   0U
#define FLASH_ECC_ENABLE_ENABLE_M   0xFU   // Enable ECC

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_STATUS register
//
//*************************************************************************************************
#define FLASH_ERR_STATUS_UNC_ERR_L   0x4U       // Lower 64 bits Uncorrectable error occurred
#define FLASH_ERR_STATUS_UNC_ERR_H   0x40000U   // Upper 64 bits Uncorrectable error occurred

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_STATUS_CLR register
//
//*************************************************************************************************
#define FLASH_ERR_STATUS_CLR_UNC_ERR_L_CLR   0x4U       // Lower 64 bits Uncorrectable error occurred Clear
#define FLASH_ERR_STATUS_CLR_UNC_ERR_H_CLR   0x40000U   // Upper 64 bits Uncorrectable error occurred Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_CNT register
//
//*************************************************************************************************
#define FLASH_ERR_CNT_ERR_CNT_S   0U
#define FLASH_ERR_CNT_ERR_CNT_M   0xFFFFU   // Error counter

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_THRESHOLD register
//
//*************************************************************************************************
#define FLASH_ERR_THRESHOLD_ERR_THRESHOLD_S   0U
#define FLASH_ERR_THRESHOLD_ERR_THRESHOLD_M   0xFFFFU   // Error Threshold

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_INTFLG register
//
//*************************************************************************************************
#define FLASH_ERR_INTFLG_SINGLE_ERR_INTFLG   0x1U   // Single Error Interrupt Flag
#define FLASH_ERR_INTFLG_UNC_ERR_INTFLG      0x2U   // Uncorrectable Interrupt Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERR_INTCLR register
//
//*************************************************************************************************
#define FLASH_ERR_INTCLR_SINGLE_ERR_INTCLR   0x1U   // Single Error Interrupt Flag Clear
#define FLASH_ERR_INTCLR_UNC_ERR_INTCLR      0x2U   // Uncorrectable Interrupt Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the FADDR_TEST register
//
//*************************************************************************************************
#define FLASH_FADDR_TEST_ADDRL_S   3U
#define FLASH_FADDR_TEST_ADDRL_M   0xFFF8U     // ECC Address Low
#define FLASH_FADDR_TEST_ADDRH_S   16U
#define FLASH_FADDR_TEST_ADDRH_M   0x3F0000U   // ECC Address High

//*************************************************************************************************
//
// The following are defines for the bit fields in the FECC_TEST register
//
//*************************************************************************************************
#define FLASH_FECC_TEST_ECC_S   0U
#define FLASH_FECC_TEST_ECC_M   0xFFU   // ECC Control Bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the FECC_CTRL register
//
//*************************************************************************************************
#define FLASH_FECC_CTRL_ECC_TEST_EN   0x1U   // Enable ECC Test Logic
#define FLASH_FECC_CTRL_ECC_SELECT    0x2U   // ECC Bit Select
#define FLASH_FECC_CTRL_DO_ECC_CALC   0x4U   // Enable ECC Calculation

//*************************************************************************************************
//
// The following are defines for the bit fields in the FECC_STATUS register
//
//*************************************************************************************************
#define FLASH_FECC_STATUS_SINGLE_ERR   0x1U   // Test Result is Single Bit Error
#define FLASH_FECC_STATUS_UNC_ERR      0x2U   // Test Result is Uncorrectable Error



#endif
