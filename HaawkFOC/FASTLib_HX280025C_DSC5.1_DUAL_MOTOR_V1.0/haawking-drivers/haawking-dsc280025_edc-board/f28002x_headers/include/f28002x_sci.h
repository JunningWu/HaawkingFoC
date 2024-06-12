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


#ifndef F28002X_SCI_H
#define F28002X_SCI_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SCI Individual Register Bit Definitions:

struct SCICCR_BITS {                          // bits description
    Uint32 SCICHAR:3;                         // 2:0 Character length control
    Uint32 ADDRIDLE_MODE:1;                   // 3 ADDR/IDLE Mode control
    Uint32 LOOPBKENA:1;                       // 4 Loop Back enable
    Uint32 PARITYENA:1;                       // 5 Parity enable
    Uint32 PARITY:1;                          // 6 Even or Odd Parity
    Uint32 STOPBITS:1;                        // 7 Number of Stop Bits
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SCICCR_REG {
    Uint32  all;
    struct  SCICCR_BITS  bit;
};

struct SCICTL1_BITS {                         // bits description
    Uint32 RXENA:1;                           // 0 SCI receiver enable
    Uint32 TXENA:1;                           // 1 SCI transmitter enable
    Uint32 SLEEP:1;                           // 2 SCI sleep
    Uint32 TXWAKE:1;                          // 3 Transmitter wakeup method
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 SWRESET:1;                         // 5 Software reset
    Uint32 RXERRINTENA:1;                     // 6 Receive error interrupt enable
    Uint32 rsvd2:25;                          // 31:7 Reserved
};

union SCICTL1_REG {
    Uint32  all;
    struct  SCICTL1_BITS  bit;
};

struct SCIHBAUD_BITS {                        // bits description
    Uint32 BAUD:8;                            // 7:0 SCI 16-bit baud selection Registers SCIHBAUD
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SCIHBAUD_REG {
    Uint32  all;
    struct  SCIHBAUD_BITS  bit;
};

struct SCILBAUD_BITS {                        // bits description
    Uint32 BAUD:8;                            // 7:0 SCI 16-bit baud selection Registers SCILBAUD
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SCILBAUD_REG {
    Uint32  all;
    struct  SCILBAUD_BITS  bit;
};

struct SCICTL2_BITS {                         // bits description
    Uint32 TXINTENA:1;                        // 0 Transmit __interrupt enable
    Uint32 RXBKINTENA:1;                      // 1 Receiver-buffer break enable
    Uint32 rsvd1:4;                           // 5:2 Reserved
    Uint32 TXEMPTY:1;                         // 6 Transmitter empty flag
    Uint32 TXRDY:1;                           // 7 Transmitter ready flag
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union SCICTL2_REG {
    Uint32  all;
    struct  SCICTL2_BITS  bit;
};

struct SCIRXST_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 RXWAKE:1;                          // 1 Receiver wakeup detect flag
    Uint32 PE:1;                              // 2 Parity error flag
    Uint32 OE:1;                              // 3 Overrun error flag
    Uint32 FE:1;                              // 4 Framing error flag
    Uint32 BRKDT:1;                           // 5 Break-detect flag
    Uint32 RXRDY:1;                           // 6 Receiver ready flag
    Uint32 RXERROR:1;                         // 7 Receiver error flag
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union SCIRXST_REG {
    Uint32  all;
    struct  SCIRXST_BITS  bit;
};

struct SCIRXEMU_BITS {                        // bits description
    Uint32 ERXDT:8;                           // 7:0 Receive emulation buffer data
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SCIRXEMU_REG {
    Uint32  all;
    struct  SCIRXEMU_BITS  bit;
};

struct SCIRXBUF_BITS {                        // bits description
    Uint32 SAR:8;                             // 7:0 Receive Character bits
    Uint32 rsvd1:6;                           // 13:8 Reserved
    Uint32 SCIFFPE:1;                         // 14 Receiver error flag
    Uint32 SCIFFFE:1;                         // 15 Receiver error flag
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIRXBUF_REG {
    Uint32  all;
    struct  SCIRXBUF_BITS  bit;
};

struct SCITXBUF_BITS {                        // bits description
    Uint32 TXDT:8;                            // 7:0 Transmit data buffer
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SCITXBUF_REG {
    Uint32  all;
    struct  SCITXBUF_BITS  bit;
};

struct SCIFFTX_BITS {                         // bits description
    Uint32 TXFFIL:5;                          // 4:0 Interrupt level
    Uint32 TXFFIENA:1;                        // 5 Interrupt enable
    Uint32 TXFFINTCLR:1;                      // 6 Clear INT flag
    Uint32 TXFFINT:1;                         // 7 INT flag
    Uint32 TXFFST:5;                          // 12:8 FIFO status
    Uint32 TXFIFORESET:1;                     // 13 FIFO reset
    Uint32 SCIFFENA:1;                        // 14 Enhancement enable
    Uint32 SCIRST:1;                          // 15 SCI reset rx/tx channels
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union SCIFFTX_REG {
    Uint32  all;
    struct  SCIFFTX_BITS  bit;
};

struct SCIFFRX_BITS {                         // bits description
    Uint32 RXFFIL:5;                          // 4:0 Interrupt level
    Uint32 RXFFIENA:1;                        // 5 Interrupt enable
    Uint32 RXFFINTCLR:1;                      // 6 Clear INT flag
    Uint32 RXFFINT:1;                         // 7 INT flag
    Uint32 RXFFST:5;                          // 12:8 FIFO status
    Uint32 RXFIFORESET:1;                     // 13 FIFO reset
    Uint32 RXFFOVRCLR:1;                      // 14 Clear overflow
    Uint32 RXFFOVF:1;                         // 15 FIFO overflow
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union SCIFFRX_REG {
    Uint32  all;
    struct  SCIFFRX_BITS  bit;
};

struct SCIFFCT_BITS {                         // bits description
    Uint32 FFTXDLY:8;                         // 7:0 FIFO transmit delay
    Uint32 rsvd1:5;                           // 12:8 Reserved
    Uint32 CDC:1;                             // 13 Auto baud mode enable
    Uint32 ABDCLR:1;                          // 14 Auto baud clear
    Uint32 ABD:1;                             // 15 Auto baud detect
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIFFCT_REG {
    Uint32  all;
    struct  SCIFFCT_BITS  bit;
};

struct SCIPRI_BITS {                          // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 FREESOFT:2;                        // 4:3 Emulation modes
    Uint32 rsvd2:27;                          // 31:5 Reserved
};

union SCIPRI_REG {
    Uint32  all;
    struct  SCIPRI_BITS  bit;
};

struct  SCI_REGS {
    union   SCICCR_REG                       SCICCR;                      // 0x0 Communications control register
    union   SCICTL1_REG                      SCICTL1;                     // 0x4 Control register 1
    union   SCIHBAUD_REG                     SCIHBAUD;                    // 0x8 Baud rate (high) register
    union   SCILBAUD_REG                     SCILBAUD;                    // 0xc Baud rate (low) register
    union   SCICTL2_REG                      SCICTL2;                     // 0x10 Control register 2
    union   SCIRXST_REG                      SCIRXST;                     // 0x14 Receive status register
    union   SCIRXEMU_REG                     SCIRXEMU;                    // 0x18 Receive emulation buffer register
    union   SCIRXBUF_REG                     SCIRXBUF;                    // 0x1c Receive data buffer
    union   SCITXBUF_REG                     SCITXBUF;                    // 0x20 Transmit data buffer
    union   SCIFFTX_REG                      SCIFFTX;                     // 0x24 FIFO transmit register
    union   SCIFFRX_REG                      SCIFFRX;                     // 0x28 FIFO receive register
    union   SCIFFCT_REG                      SCIFFCT;                     // 0x2c FIFO control register
    union   SCIPRI_REG                       SCIPRI;                      // 0x30 SCI priority control
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================