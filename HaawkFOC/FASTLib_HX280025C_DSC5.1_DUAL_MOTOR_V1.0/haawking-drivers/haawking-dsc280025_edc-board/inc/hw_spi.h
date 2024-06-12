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


#ifndef HW_SPI_H
#define HW_SPI_H

//*************************************************************************************************
//
// The following are defines for the SPI register offsets
//
//*************************************************************************************************
#define SPI_O_CCR     0x0U    // SPI Configuration Control Register
#define SPI_O_CTL     0x4U    // SPI Operation Control Register
#define SPI_O_STS     0x8U    // SPI Status Register
#define SPI_O_BRR     0xCU    // SPI Baud Rate Register
#define SPI_O_RXEMU   0x10U   // SPI Emulation Buffer Register
#define SPI_O_RXBUF   0x14U   // SPI Serial Input Buffer Register
#define SPI_O_TXBUF   0x18U   // SPI Serial Output Buffer Register
#define SPI_O_DAT     0x1CU   // SPI Serial Data Register
#define SPI_O_FFTX    0x20U   // SPI FIFO Transmit Register
#define SPI_O_FFRX    0x24U   // SPI FIFO Receive Register
#define SPI_O_FFCT    0x28U   // SPI FIFO Control Register
#define SPI_O_PRI     0x2CU   // SPI Priority Control Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the SPICCR register
//
//*************************************************************************************************
#define SPI_CCR_SPICHAR_S     0U
#define SPI_CCR_SPICHAR_M     0xFU    // Character Length Control
#define SPI_CCR_SPILBK        0x10U   // SPI Loopback
#define SPI_CCR_CLKPOLARITY   0x40U   // Shift Clock Polarity
#define SPI_CCR_SPISWRESET    0x80U   // SPI Software Reset

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPICTL register
//
//*************************************************************************************************
#define SPI_CTL_SPIINTENA       0x1U    // SPI Interupt Enable
#define SPI_CTL_TALK            0x2U    // Master/Slave Transmit Enable
#define SPI_CTL_MASTER_SLAVE    0x4U    // SPI Network Mode Control
#define SPI_CTL_CLK_PHASE       0x8U    // SPI Clock Phase
#define SPI_CTL_OVERRUNINTENA   0x10U   // Overrun Interrupt Enable
#define SPI_CTL_MODE_DMA        0x20U   // DMA Mode Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPISTS register
//
//*************************************************************************************************
#define SPI_STS_BUFFULL_FLAG   0x20U   // SPI Transmit Buffer Full Flag
#define SPI_STS_INT_FLAG       0x40U   // SPI Interrupt Flag
#define SPI_STS_OVERRUN_FLAG   0x80U   // SPI Receiver Overrun Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIBRR register
//
//*************************************************************************************************
#define SPI_BRR_SPI_BIT_RATE_S   0U
#define SPI_BRR_SPI_BIT_RATE_M   0x7FU   // SPI Bit Rate Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIFFTX register
//
//*************************************************************************************************
#define SPI_FFTX_TXFFIL_S     0U
#define SPI_FFTX_TXFFIL_M     0x1FU     // TXFIFO Interrupt Level
#define SPI_FFTX_TXFFIENA     0x20U     // TXFIFO Interrupt Enable
#define SPI_FFTX_TXFFINTCLR   0x40U     // TXFIFO Interrupt Clear
#define SPI_FFTX_TXFFINT      0x80U     // TXFIFO Interrupt Flag
#define SPI_FFTX_TXFFST_S     8U
#define SPI_FFTX_TXFFST_M     0x1F00U   // Transmit FIFO Status
#define SPI_FFTX_TXFIFO       0x2000U   // TXFIFO Reset
#define SPI_FFTX_SPIFFENA     0x4000U   // FIFO Enhancements Enable
#define SPI_FFTX_SPIRST       0x8000U   // SPI Reset

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIFFRX register
//
//*************************************************************************************************
#define SPI_FFRX_RXFFIL_S      0U
#define SPI_FFRX_RXFFIL_M      0x1FU     // RXFIFO Interrupt Level
#define SPI_FFRX_RXFFIENA      0x20U     // RXFIFO Interrupt Enable
#define SPI_FFRX_RXFFINTCLR    0x40U     // RXFIFO Interupt Clear
#define SPI_FFRX_RXFFINT       0x80U     // RXFIFO Interrupt Flag
#define SPI_FFRX_RXFFST_S      8U
#define SPI_FFRX_RXFFST_M      0x1F00U   // Receive FIFO Status
#define SPI_FFRX_RXFIFORESET   0x2000U   // RXFIFO Reset
#define SPI_FFRX_RXFFOVFCLR    0x4000U   // Receive FIFO Overflow Clear
#define SPI_FFRX_RXFFOVF       0x8000U   // Receive FIFO Overflow Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIFFCT register
//
//*************************************************************************************************
#define SPI_FFCT_TXDLY_S   0U
#define SPI_FFCT_TXDLY_M   0xFFU   // FIFO Transmit Delay Bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIPRI register
//
//*************************************************************************************************
#define SPI_PRI_TRIWIRE   0x1U    // 3-wire mode select bit
#define SPI_PRI_STEINV    0x2U    // SPISTE inversion bit
#define SPI_PRI_FREE      0x10U   // Free emulation mode
#define SPI_PRI_SOFT      0x20U   // Soft emulation mode



#endif
