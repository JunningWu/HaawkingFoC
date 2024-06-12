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


#ifndef HW_DMA_H
#define HW_DMA_H

//*************************************************************************************************
//
// The following are defines for the DMA register offsets
//
//*************************************************************************************************
#define DMA_O_MODE                  0x0U    // Mode Register
#define DMA_O_CONTROL               0x4U    // Control Register
#define DMA_O_BURST_SIZE            0x8U    // Burst Size Register
#define DMA_O_BURST_COUNT           0xCU    // Burst Count Register
#define DMA_O_SRC_BURST_STEP        0x10U   // Source Burst Step Register
#define DMA_O_DST_BURST_STEP        0x14U   // Destination Burst Step Register
#define DMA_O_TRANSFER_SIZE         0x18U   // Transfer Size Register
#define DMA_O_TRANSFER_COUNT        0x1CU   // Transfer Count Register
#define DMA_O_SRC_TRANSFER_STEP     0x20U   // Source Transfer Step Register
#define DMA_O_DST_TRANSFER_STEP     0x24U   // Destination Transfer Step Register
#define DMA_O_SRC_WRAP_SIZE         0x28U   // Source Wrap Size Register
#define DMA_O_SRC_WRAP_COUNT        0x2CU   // Source Wrap Count Register
#define DMA_O_SRC_WRAP_STEP         0x30U   // Source Wrap Step Register
#define DMA_O_DST_WRAP_SIZE         0x34U   // Destination Wrap Size Register
#define DMA_O_DST_WRAP_COUNT        0x38U   // Destination Wrap Count Register
#define DMA_O_DST_WRAP_STEP         0x3CU   // Destination Wrap Step Register
#define DMA_O_SRC_BEG_ADDR_SHADOW   0x40U   // Source Begin Address Shadow Register
#define DMA_O_SRC_ADDR_SHADOW       0x44U   // Source Address Shadow Register
#define DMA_O_SRC_BEG_ADDR_ACTIVE   0x48U   // Source Begin Address Active Register
#define DMA_O_SRC_ADDR_ACTIVE       0x4CU   // Source Address Active Register
#define DMA_O_DST_BEG_ADDR_SHADOW   0x50U   // Destination Begin Address Shadow Register
#define DMA_O_DST_ADDR_SHADOW       0x54U   // Destination Address Shadow Register
#define DMA_O_DST_BEG_ADDR_ACTIVE   0x58U   // Destination Begin Address Active Register
#define DMA_O_DST_ADDR_ACTIVE       0x5CU   // Destination Address Active Register

#define DMA_O_CTRL            0x0U     // DMA Control Register
#define DMA_O_DEBUGCTRL       0x4U     // Debug Control Register
#define DMA_O_REVSION         0x8U     // Revsion Register
#define DMA_O_PRIORITYCTRL1   0xCU     // Priority Control 1 Register
#define DMA_O_PRIORITYSTAT    0x10U    // Priority Status Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the MODE register
//
//*************************************************************************************************
#define DMA_MODE_PERINTSEL_S   0U
#define DMA_MODE_PERINTSEL_M   0x1FU     // Peripheral Interrupt and Sync Select
#define DMA_MODE_OVRINTE       0x80U     // Overflow Interrupt Enable
#define DMA_MODE_PERINTE       0x100U    // Peripheral Interrupt Enable
#define DMA_MODE_CHINTMODE     0x200U    // Channel Interrupt Mode
#define DMA_MODE_ONESHOT       0x400U    // One Shot Mode Bit
#define DMA_MODE_CONTINUOUS    0x800U    // Continuous Mode Bit
#define DMA_MODE_DATASIZE      0x4000U   // Data Size Mode Bit
#define DMA_MODE_CHINTE        0x8000U   // Channel Interrupt Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONTROL register
//
//*************************************************************************************************
#define DMA_CONTROL_RUN           0x1U      // Run Bit
#define DMA_CONTROL_HALT          0x2U      // Halt Bit
#define DMA_CONTROL_SOFTRESET     0x4U      // Soft Reset Bit
#define DMA_CONTROL_PERINTFRC     0x8U      // Interrupt Force Bit
#define DMA_CONTROL_PERINTCLR     0x10U     // Interrupt Clear Bit
#define DMA_CONTROL_ERRCLR        0x80U     // Error Clear Bit
#define DMA_CONTROL_PERINTFLG     0x100U    // Interrupt Flag Bit
#define DMA_CONTROL_TRANSFERSTS   0x800U    // Transfer Status Bit
#define DMA_CONTROL_BURSTSTS      0x1000U   // Burst Status Bit
#define DMA_CONTROL_RUNSTS        0x2000U   // Run Status Bit
#define DMA_CONTROL_OVRFLG        0x4000U   // Overflow Flag Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the BURST_SIZE register
//
//*************************************************************************************************
#define DMA_BURST_SIZE_BURSTSIZE_S   0U
#define DMA_BURST_SIZE_BURSTSIZE_M   0x1FU   // Burst Transfer Size

//*************************************************************************************************
//
// The following are defines for the bit fields in the BURST_COUNT register
//
//*************************************************************************************************
#define DMA_BURST_COUNT_BURSTCOUNT_S   0U
#define DMA_BURST_COUNT_BURSTCOUNT_M   0x1FU   // Burst Transfer Size

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACTRL register
//
//*************************************************************************************************
#define DMA_CTRL_HARDRESET       0x1U   // Hard Reset Bit
#define DMA_CTRL_PRIORITYRESET   0x2U   // Priority Reset Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUGCTRL register
//
//*************************************************************************************************
#define DMA_DEBUGCTRL_FREE   0x8000U   // Debug Mode Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PRIORITYCTRL1 register
//
//*************************************************************************************************
#define DMA_PRIORITYCTRL1_CH1PRIORITY   0x1U   // Ch1 Priority Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PRIORITYSTAT register
//
//*************************************************************************************************
#define DMA_PRIORITYSTAT_ACTIVESTS_S          0U
#define DMA_PRIORITYSTAT_ACTIVESTS_M          0x7U    // Active Channel Status Bits
#define DMA_PRIORITYSTAT_ACTIVESTS_SHADOW_S   4U
#define DMA_PRIORITYSTAT_ACTIVESTS_SHADOW_M   0x70U   // Active Channel Status Shadow Bits



#endif
