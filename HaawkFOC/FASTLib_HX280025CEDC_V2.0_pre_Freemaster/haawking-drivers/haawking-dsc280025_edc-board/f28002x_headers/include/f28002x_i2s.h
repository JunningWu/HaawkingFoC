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


#ifndef F28002X_I2S_H
#define F28002X_I2S_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// I2S Individual Register Bit Definitions:

struct I2SSCTRL_BITS {                        // bits description
    Uint32 FRMT:2;                            // 1:0 Set The Serializer Data Format
    Uint32 MODE:1;                            // 2 Set The Serializer In Master Or Slave Mode
    Uint32 WDLEN:4;                           // 6:3 Choose Serializer Word Length
    Uint32 PACK:1;                            // 7 Enable Data Packing
    Uint32 DATDLY:2;                          // 9:8 Set The I2S Receive and Transmit Date Delay
    Uint32 CLKPOL:1;                          // 10 Controls I2S Clock Polarity
    Uint32 FSPOL:1;                           // 11 Inverts I2S Frame-Synchronization Polarity
    Uint32 LOOPBACK:1;                        // 12 Routes Data From Transmit Shift Register Back To Receive Shift Register
    Uint32 MONO:1;                            // 13 Set I2S Into Mono Or Stereo Mode
    Uint32 rsvd1:2;                           // 15:14 Reserved
    Uint32 ENABLE:1;                          // 16 Resets Or Enables The Serializer transmission Or Reception
    Uint32 SLTLEN:4;                          // 20:17 Choose Serializer Slot Length
    Uint32 FRLEN:2;                           // 22:21 Frame Length 1
    Uint32 RESERVEBITOUT:1;                   // 23 Reserve Bit Output Control
    Uint32 RSVPADEN:1;                        // 24 I2S_DX PAD Output Enable Control For Reserve Bit
    Uint32 rsvd2:7;                           // 31:25 Reserved
};

union I2SSCTRL_REG {
    Uint32  all;
    struct  I2SSCTRL_BITS  bit;
};

struct I2SSRATE_BITS {                        // bits description
    Uint32 CLKDIV:8;                          // 7:0 Divider To Generate I2Sn_CLK
    Uint32 FSDIV:4;                           // 11:8 Divider To Generate I2Sn_FS
    Uint32 FWID:8;                            // 19:12 Frame-Synchronization Pulse Width Bits For I2Sn_FS
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union I2SSRATE_REG {
    Uint32  all;
    struct  I2SSRATE_BITS  bit;
};

struct I2SINTFL_BITS {                        // bits description
    Uint32 RCVOUERRFL:1;                      // 0 Receive Overrun Or Underrun Condition
    Uint32 XMITOUERRFL:1;                     // 1 Transmit Overrun Or Underrun Condition
    Uint32 FERRFL:1;                          // 2 Frame-Synchornization Error Flag
    Uint32 RCVMONFL:1;                        // 3 Mono Data Receive Flag
    Uint32 RCVSTFL:1;                         // 4 Stereo Data Receive Flag
    Uint32 XMITMONFL:1;                       // 5 Mono Data Transmit Flag
    Uint32 XMITSTFL:1;                        // 6 Stereo Data Transmit Flag
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union I2SINTFL_REG {
    Uint32  all;
    struct  I2SINTFL_BITS  bit;
};

struct I2SINTMASK_BITS {                      // bits description
    Uint32 RCVOUERR:1;                        // 0 Enable Receive Overrun Or Underrun Condition
    Uint32 XMITOUERR:1;                       // 1 Enable Transmit Overrun Or Underrun Condition
    Uint32 FERR:1;                            // 2 Enable Frame Sync Error
    Uint32 RCVMON:1;                          // 3 Enable Mono Left Receive Data Interrupt
    Uint32 RCVST:1;                           // 4 Enable Stereo Left Right Receive Data Interrupt
    Uint32 XMITMON:1;                         // 5 Enable Mono Left Transmit Data Interrupt
    Uint32 XMITST:1;                          // 6 Enable Stereo Left Right Transmit Data Interrupt
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union I2SINTMASK_REG {
    Uint32  all;
    struct  I2SINTMASK_BITS  bit;
};

struct I2SMCR1_BITS {                         // bits description
    Uint32 RMCM:1;                            // 0 Receive Multichannel Selection Mode Bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union I2SMCR1_REG {
    Uint32  all;
    struct  I2SMCR1_BITS  bit;
};

struct I2SMCR2_BITS {                         // bits description
    Uint32 XMCM:2;                            // 1:0 Transmit Multichannel Selection Mode Bit
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union I2SMCR2_REG {
    Uint32  all;
    struct  I2SMCR2_BITS  bit;
};

struct I2SRCERA_BITS {                        // bits description
    Uint32 RCE:16;                            // 15:0 Receive Channel Enable Bit
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union I2SRCERA_REG {
    Uint32  all;
    struct  I2SRCERA_BITS  bit;
};

struct I2SXCERA_BITS {                        // bits description
    Uint32 XCE:16;                            // 15:0 Transmit Channel Enable Bit
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union I2SXCERA_REG {
    Uint32  all;
    struct  I2SXCERA_BITS  bit;
};

struct I2SRXDRP_BITS {                        // bits description
    Uint32 DROPNUM:5;                         // 4:0 Drop Data Number
    Uint32 DROPEN:1;                          // 5 Receive Drop Data Function Enable
    Uint32 DROPVALID:1;                       // 6  
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union I2SRXDRP_REG {
    Uint32  all;
    struct  I2SRXDRP_BITS  bit;
};

struct I2STXTDMDRP_BITS {                     // bits description
    Uint32 TXTDMDROPEN:1;                     // 0 Transmit Drop Data Function Enable In TDM Mode
    Uint32 TXTDMDROPVALID:1;                  // 1  
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union I2STXTDMDRP_REG {
    Uint32  all;
    struct  I2STXTDMDRP_BITS  bit;
};

struct  I2S_REGS {
    union   I2SSCTRL_REG                     I2SSCTRL;                    // 0x0 I2S Serializer Control Register
    union   I2SSRATE_REG                     I2SSRATE;                    // 0x4 I2S Sample Rate Generator Register
    Uint32                                   I2STXLT0;                    // 0x8 I2S Transmit Left Data 0 Register
    Uint32                                   I2STXRT0;                    // 0xc I2S Transmit Right Data 0 Register
    union   I2SINTFL_REG                     I2SINTFL;                    // 0x10 I2S Interrupt Flag Register
    union   I2SINTMASK_REG                   I2SINTMASK;                  // 0x14 I2S Interrupt Mask Register
    Uint32                                   I2SRXLT0;                    // 0x18 I2S Receive Left Data 0 Register
    Uint32                                   I2SRXRT0;                    // 0x1c I2S Receive Right Data 0 Register
    union   I2SMCR1_REG                      I2SMCR1;                     // 0x20 I2S Multichannel Control 1 Register
    union   I2SMCR2_REG                      I2SMCR2;                     // 0x24 I2S Multichannel Control 2 Register
    union   I2SRCERA_REG                     I2SRCERA;                    // 0x28 I2S Receive Channel Enable Register
    union   I2SXCERA_REG                     I2SXCERA;                    // 0x2c I2S Transmi Channel Enable Register
    union   I2SRXDRP_REG                     I2SRXDRP;                    // 0x30 I2S RX Drop Data Function Control Register
    union   I2STXTDMDRP_REG                  I2STXTDMDRP;                 // 0x34 I2S Tx TDM Mode Drop Data Function Control Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================