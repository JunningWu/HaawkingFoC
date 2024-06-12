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


#ifndef HW_I2S_H
#define HW_I2S_H

//*************************************************************************************************
//
// The following are defines for the I2S register offsets
//
//*************************************************************************************************
#define I2S_O_SCTRL      0x0U    // I2S Serializer Control Register
#define I2S_O_SRATE      0x4U    // I2S Sample Rate Generator Register
#define I2S_O_TXLT0      0x8U    // I2S Transmit Left Data 0 Register
#define I2S_O_TXRT0      0xCU    // I2S Transmit Right Data 0 Register
#define I2S_O_INTFL      0x10U   // I2S Interrupt Flag Register
#define I2S_O_INTMASK    0x14U   // I2S Interrupt Mask Register
#define I2S_O_RXLT0      0x18U   // I2S Receive Left Data 0 Register
#define I2S_O_RXRT0      0x1CU   // I2S Receive Right Data 0 Register
#define I2S_O_MCR1       0x20U   // I2S Multichannel Control 1 Register
#define I2S_O_MCR2       0x24U   // I2S Multichannel Control 2 Register
#define I2S_O_RCERA      0x28U   // I2S Receive Channel Enable Register
#define I2S_O_XCERA      0x2CU   // I2S Transmi Channel Enable Register
#define I2S_O_RXDRP      0x30U   // I2S RX Drop Data Function Control Register
#define I2S_O_TXTDMDRP   0x34U   // I2S Tx TDM Mode Drop Data Function Control Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SSCTRL register
//
//*************************************************************************************************
#define I2S_SCTRL_FRMT_S          0U
#define I2S_SCTRL_FRMT_M          0x3U         // Set The Serializer Data Format
#define I2S_SCTRL_MODE            0x4U         // Set The Serializer In Master Or Slave Mode
#define I2S_SCTRL_WDLEN_S         3U
#define I2S_SCTRL_WDLEN_M         0x78U        // Choose Serializer Word Length
#define I2S_SCTRL_PACK            0x80U        // Enable Data Packing
#define I2S_SCTRL_DATDLY_S        8U
#define I2S_SCTRL_DATDLY_M        0x300U       // Set The I2S Receive and Transmit Date Delay
#define I2S_SCTRL_CLKPOL          0x400U       // Controls I2S Clock Polarity
#define I2S_SCTRL_FSPOL           0x800U       // Inverts I2S Frame-Synchronization Polarity
#define I2S_SCTRL_LOOPBACK        0x1000U      // Routes Data From Transmit Shift Register Back To Receive Shift Register
#define I2S_SCTRL_MONO            0x2000U      // Set I2S Into Mono Or Stereo Mode
#define I2S_SCTRL_ENABLE          0x10000U     // Resets Or Enables The Serializer transmission Or Reception
#define I2S_SCTRL_SLTLEN_S        17U
#define I2S_SCTRL_SLTLEN_M        0x1E0000U    // Choose Serializer Slot Length
#define I2S_SCTRL_FRLEN_S         21U
#define I2S_SCTRL_FRLEN_M         0x600000U    // Frame Length 1
#define I2S_SCTRL_RESERVEBITOUT   0x800000U    // Reserve Bit Output Control
#define I2S_SCTRL_RSVPADEN        0x1000000U   // I2S_DX PAD Output Enable Control For Reserve Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SSRATE register
//
//*************************************************************************************************
#define I2S_SRATE_CLKDIV_S   0U
#define I2S_SRATE_CLKDIV_M   0xFFU      // Divider To Generate I2Sn_CLK
#define I2S_SRATE_FSDIV_S    8U
#define I2S_SRATE_FSDIV_M    0xF00U     // Divider To Generate I2Sn_FS
#define I2S_SRATE_FWID_S     12U
#define I2S_SRATE_FWID_M     0xFF000U   // Frame-Synchronization Pulse Width Bits For I2Sn_FS

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SINTFL register
//
//*************************************************************************************************
#define I2S_INTFL_RCVOUERRFL    0x1U    // Receive Overrun Or Underrun Condition
#define I2S_INTFL_XMITOUERRFL   0x2U    // Transmit Overrun Or Underrun Condition
#define I2S_INTFL_FERRFL        0x4U    // Frame-Synchornization Error Flag
#define I2S_INTFL_RCVMONFL      0x8U    // Mono Data Receive Flag
#define I2S_INTFL_RCVSTFL       0x10U   // Stereo Data Receive Flag
#define I2S_INTFL_XMITMONFL     0x20U   // Mono Data Transmit Flag
#define I2S_INTFL_XMITSTFL      0x40U   // Stereo Data Transmit Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SINTMASK register
//
//*************************************************************************************************
#define I2S_INTMASK_RCVOUERR    0x1U    // Enable Receive Overrun Or Underrun Condition
#define I2S_INTMASK_XMITOUERR   0x2U    // Enable Transmit Overrun Or Underrun Condition
#define I2S_INTMASK_FERR        0x4U    // Enable Frame Sync Error
#define I2S_INTMASK_RCVMON      0x8U    // Enable Mono Left Receive Data Interrupt
#define I2S_INTMASK_RCVST       0x10U   // Enable Stereo Left Right Receive Data Interrupt
#define I2S_INTMASK_XMITMON     0x20U   // Enable Mono Left Transmit Data Interrupt
#define I2S_INTMASK_XMITST      0x40U   // Enable Stereo Left Right Transmit Data Interrupt

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SMCR1 register
//
//*************************************************************************************************
#define I2S_MCR1_RMCM   0x1U   // Receive Multichannel Selection Mode Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SMCR2 register
//
//*************************************************************************************************
#define I2S_MCR2_XMCM_S   0U
#define I2S_MCR2_XMCM_M   0x3U   // Transmit Multichannel Selection Mode Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SRCERA register
//
//*************************************************************************************************
#define I2S_RCERA_RCE_S   0U
#define I2S_RCERA_RCE_M   0xFFFFU   // Receive Channel Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SXCERA register
//
//*************************************************************************************************
#define I2S_XCERA_XCE_S   0U
#define I2S_XCERA_XCE_M   0xFFFFU   // Transmit Channel Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2SRXDRP register
//
//*************************************************************************************************
#define I2S_RXDRP_DROPNUM_S   0U
#define I2S_RXDRP_DROPNUM_M   0x1FU   // Drop Data Number
#define I2S_RXDRP_DROPEN      0x20U   // Receive Drop Data Function Enable
#define I2S_RXDRP_DROPVALID   0x40U   //  

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2STXTDMDRP register
//
//*************************************************************************************************
#define I2S_TXTDMDRP_TXTDMDROPEN      0x1U   // Transmit Drop Data Function Enable In TDM Mode
#define I2S_TXTDMDRP_TXTDMDROPVALID   0x2U   //  



#endif
