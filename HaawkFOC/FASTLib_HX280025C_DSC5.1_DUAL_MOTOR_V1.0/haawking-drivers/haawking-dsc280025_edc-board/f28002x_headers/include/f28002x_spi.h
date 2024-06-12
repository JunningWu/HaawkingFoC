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


#ifndef F28002X_SPI_H
#define F28002X_SPI_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SPI Individual Register Bit Definitions:

struct SPICCR_BITS {                          // bits description
    Uint32 SPICHAR:4;                         // 3:0 Character Length Control
    Uint32 SPILBK:1;                          // 4 SPI Loopback
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 CLKPOLARITY:1;                     // 6 Shift Clock Polarity
    Uint32 SPISWRESET:1;                      // 7 SPI Software Reset
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union SPICCR_REG {
    Uint32  all;
    struct  SPICCR_BITS  bit;
};

struct SPICTL_BITS {                          // bits description
    Uint32 SPIINTENA:1;                       // 0 SPI Interupt Enable
    Uint32 TALK:1;                            // 1 Master/Slave Transmit Enable
    Uint32 MASTER_SLAVE:1;                    // 2 SPI Network Mode Control
    Uint32 CLK_PHASE:1;                       // 3 SPI Clock Phase
    Uint32 OVERRUNINTENA:1;                   // 4 Overrun Interrupt Enable
    Uint32 MODE_DMA:1;                        // 5 DMA Mode Enable
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union SPICTL_REG {
    Uint32  all;
    struct  SPICTL_BITS  bit;
};

struct SPISTS_BITS {                          // bits description
    Uint32 rsvd1:5;                           // 4:0 Reserved
    Uint32 BUFFULL_FLAG:1;                    // 5 SPI Transmit Buffer Full Flag
    Uint32 INT_FLAG:1;                        // 6 SPI Interrupt Flag
    Uint32 OVERRUN_FLAG:1;                    // 7 SPI Receiver Overrun Flag
    Uint32 rsvd2:24;                          // 31:8 Reserved
};

union SPISTS_REG {
    Uint32  all;
    struct  SPISTS_BITS  bit;
};

struct SPIBRR_BITS {                          // bits description
    Uint32 SPI_BIT_RATE:7;                    // 6:0 SPI Bit Rate Control
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union SPIBRR_REG {
    Uint32  all;
    struct  SPIBRR_BITS  bit;
};

struct SPIFFTX_BITS {                         // bits description
    Uint32 TXFFIL:5;                          // 4:0 TXFIFO Interrupt Level
    Uint32 TXFFIENA:1;                        // 5 TXFIFO Interrupt Enable
    Uint32 TXFFINTCLR:1;                      // 6 TXFIFO Interrupt Clear
    Uint32 TXFFINT:1;                         // 7 TXFIFO Interrupt Flag
    Uint32 TXFFST:5;                          // 12:8 Transmit FIFO Status
    Uint32 TXFIFO:1;                          // 13 TXFIFO Reset
    Uint32 SPIFFENA:1;                        // 14 FIFO Enhancements Enable
    Uint32 SPIRST:1;                          // 15 SPI Reset
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union SPIFFTX_REG {
    Uint32  all;
    struct  SPIFFTX_BITS  bit;
};

struct SPIFFRX_BITS {                         // bits description
    Uint32 RXFFIL:5;                          // 4:0 RXFIFO Interrupt Level
    Uint32 RXFFIENA:1;                        // 5 RXFIFO Interrupt Enable
    Uint32 RXFFINTCLR:1;                      // 6 RXFIFO Interupt Clear
    Uint32 RXFFINT:1;                         // 7 RXFIFO Interrupt Flag
    Uint32 RXFFST:5;                          // 12:8 Receive FIFO Status
    Uint32 RXFIFORESET:1;                     // 13 RXFIFO Reset
    Uint32 RXFFOVFCLR:1;                      // 14 Receive FIFO Overflow Clear
    Uint32 RXFFOVF:1;                         // 15 Receive FIFO Overflow Flag
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union SPIFFRX_REG {
    Uint32  all;
    struct  SPIFFRX_BITS  bit;
};

struct SPIFFCT_BITS {                         // bits description
    Uint32 TXDLY:8;                           // 7:0 FIFO Transmit Delay Bits
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union SPIFFCT_REG {
    Uint32  all;
    struct  SPIFFCT_BITS  bit;
};

struct SPIPRI_BITS {                          // bits description
    Uint32 TRIWIRE:1;                         // 0 3-wire mode select bit
    Uint32 STEINV:1;                          // 1 SPISTE inversion bit
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 FREE:1;                            // 4 Free emulation mode
    Uint32 SOFT:1;                            // 5 Soft emulation mode
    Uint32 rsvd2:1;                           // 6 Reserved
    Uint32 rsvd3:25;                          // 31:7 Reserved
};

union SPIPRI_REG {
    Uint32  all;
    struct  SPIPRI_BITS  bit;
};

struct  SPI_REGS {
    union   SPICCR_REG                       SPICCR;                      // 0x0 SPI Configuration Control Register
    union   SPICTL_REG                       SPICTL;                      // 0x4 SPI Operation Control Register
    union   SPISTS_REG                       SPISTS;                      // 0x8 SPI Status Register
    union   SPIBRR_REG                       SPIBRR;                      // 0xc SPI Baud Rate Register
    Uint32                                   SPIRXEMU;                    // 0x10 SPI Emulation Buffer Register
    Uint32                                   SPIRXBUF;                    // 0x14 SPI Serial Input Buffer Register
    Uint32                                   SPITXBUF;                    // 0x18 SPI Serial Output Buffer Register
    Uint32                                   SPIDAT;                      // 0x1c SPI Serial Data Register
    union   SPIFFTX_REG                      SPIFFTX;                     // 0x20 SPI FIFO Transmit Register
    union   SPIFFRX_REG                      SPIFFRX;                     // 0x24 SPI FIFO Receive Register
    union   SPIFFCT_REG                      SPIFFCT;                     // 0x28 SPI FIFO Control Register
    union   SPIPRI_REG                       SPIPRI;                      // 0x2c SPI Priority Control Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================