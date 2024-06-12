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


#ifndef F28002X_LIN_H
#define F28002X_LIN_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// LIN Individual Register Bit Definitions:

struct SCIGCR0_BITS {                         // bits description
    Uint32 RESET:1;                           // 0 LIN Module reset bit
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIGCR0_REG {
    Uint32  all;
    struct  SCIGCR0_BITS  bit;
};

struct SCIGCR1_BITS {                         // bits description
    Uint32 COMMMODE:1;                        // 0 SCI/LIN communications mode bit
    Uint32 TIMINGMODE:1;                      // 1 SCI timing mode bit. Should be set to 1 for SCI mode.
    Uint32 PARITYENA:1;                       // 2 Parity enable
    Uint32 PARITY:1;                          // 3 SCI parity odd/even selection
    Uint32 STOP:1;                            // 4 SCI number of stop bits
    Uint32 CLK_MASTER:1;                      // 5 LIN Master/Slave selection and SCI clock enable
    Uint32 LINMODE:1;                         // 6 LIN Mode enable/disable
    Uint32 SWnRST:1;                          // 7 Software reset
    Uint32 SLEEP:1;                           // 8 SCI sleep (SCI compatibility mode)
    Uint32 ADAPT:1;                           // 9 Automatic baudrate adjustment control(LIN mode)
    Uint32 MBUFMODE:1;                        // 10 Multi-buffer mode
    Uint32 CTYPE:1;                           // 11 Checksum type (LIN mode)
    Uint32 HGENCTRL:1;                        // 12 Mask filtering comparison control (LIN mode)
    Uint32 STOPEXTFRAME:1;                    // 13 Stop extended frame communication (LIN mode)
    Uint32 rsvd1:2;                           // 15:14 Reserved
    Uint32 LOOPBACK:1;                        // 16 Digital loopback mode
    Uint32 CONT:1;                            // 17 Continue on suspend
    Uint32 rsvd2:6;                           // 23:18 Reserved
    Uint32 RXENA:1;                           // 24 Receive enable
    Uint32 TXENA:1;                           // 25 Transmit enable
    Uint32 rsvd3:6;                           // 31:26 Reserved
};

union SCIGCR1_REG {
    Uint32  all;
    struct  SCIGCR1_BITS  bit;
};

struct SCIGCR2_BITS {                         // bits description
    Uint32 POWERDOWN:1;                       // 0 Low-power mode PowerDown bit
    Uint32 rsvd1:7;                           // 7:1 Reserved
    Uint32 GENWU:1;                           // 8 Generate Wakeup
    Uint32 rsvd2:7;                           // 15:9 Reserved
    Uint32 SC:1;                              // 16 Send Checksum (LIN mode)
    Uint32 CC:1;                              // 17 Compare Checksum (LIN mode)
    Uint32 rsvd3:14;                          // 31:18 Reserved
};

union SCIGCR2_REG {
    Uint32  all;
    struct  SCIGCR2_BITS  bit;
};

struct SCISETINT_BITS {                       // bits description
    Uint32 SETBRKDTINT:1;                     // 0 Set Break-detect Interrupt (SCI compatible mode)
    Uint32 SETWAKEUPINT:1;                    // 1 Set Wake-up Interrupt
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 SETTIMEOUTINT:1;                   // 4 Set Timeout Interrupt (LIN only)
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 SETTOAWUSINT:1;                    // 6 Set Timeout After Wakeup Signal Interrupt (LIN only)
    Uint32 SETTOA3WUSINT:1;                   // 7 Set Timeout After 3 Wakeup Signals Interrupt (LIN only)
    Uint32 SETTXINT:1;                        // 8 Set Transmitter Interrupt
    Uint32 SETRXINT:1;                        // 9 Se Receiver Interrupt
    Uint32 rsvd3:3;                           // 12:10 Reserved
    Uint32 SETIDINT:1;                        // 13 Set Identifier Interrupt (LIN only)
    Uint32 rsvd4:2;                           // 15:14 Reserved
    Uint32 SET_TX_DMA:1;                      // 16 Set transmit DMA
    Uint32 SET_RX_DMA:1;                      // 17 Set receiver DMA
    Uint32 SET_RX_DMA_ALL:1;                  // 18 Set receiver DMA for Address & Data frames
    Uint32 rsvd5:5;                           // 23:19 Reserved
    Uint32 SETPEINT:1;                        // 24 Set Parity Interrupt
    Uint32 SETOEINT:1;                        // 25 Set Overrun-Error Interrupt
    Uint32 SETFEINT:1;                        // 26 Set Framing-Error Interrupt
    Uint32 SETNREINT:1;                       // 27 Set No-Response-Error Interrupt (LIN only)
    Uint32 SETISFEINT:1;                      // 28 Set Inconsistent-Sync-Field-Error Interrupt (LIN only)
    Uint32 SETCEINT:1;                        // 29 Set Checksum-error Interrupt (LIN only)
    Uint32 SETPBEINT:1;                       // 30 Set Physical Bus Error Interrupt (LIN only)
    Uint32 SETBEINT:1;                        // 31 Set Bit Error Interrupt (LIN only)
};

union SCISETINT_REG {
    Uint32  all;
    struct  SCISETINT_BITS  bit;
};

struct SCICLEARINT_BITS {                     // bits description
    Uint32 CLRBRKDTINT:1;                     // 0 Clear Break-detect Interrupt (SCI compatible mode
    Uint32 CLRWAKEUPINT:1;                    // 1 Clear Wake-up Interrupt
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 CLRTIMEOUTINT:1;                   // 4 Clear Timeout Interrupt (LIN only)
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 CLRTOAWUSINT:1;                    // 6 Clear Timeout After Wakeup Signal Interrupt (LIN only)
    Uint32 CLRTOA3WUSINT:1;                   // 7 Clear Timeout After 3 Wakeup Signals Interrupt (LIN only)
    Uint32 CLRTXINT:1;                        // 8 Clear Transmitter Interrupt
    Uint32 CLRRXINT:1;                        // 9 Clear Receiver Interrupt
    Uint32 rsvd3:3;                           // 12:10 Reserved
    Uint32 CLRIDINT:1;                        // 13 Clear Identifier Interrupt (LIN only)
    Uint32 rsvd4:2;                           // 15:14 Reserved
    Uint32 CLRTXDMA:1;                        // 16 Clear transmit DMA
    Uint32 SETRXDMA:1;                        // 17 Clear receiver DMA
    Uint32 rsvd5:1;                           // 18 Reserved
    Uint32 rsvd6:5;                           // 23:19 Reserved
    Uint32 CLRPEINT:1;                        // 24 Clear Parity Interrupt
    Uint32 CLROEINT:1;                        // 25 Clear Overrun-Error Interrupt
    Uint32 CLRFEINT:1;                        // 26 Clear Framing-Error Interrupt
    Uint32 CLRNREINT:1;                       // 27 Clear No-Response-Error Interrupt (LIN only)
    Uint32 CLRISFEINT:1;                      // 28 Clear Inconsistent-Sync-Field-Error Interrupt (LIN only)
    Uint32 CLRCEINT:1;                        // 29 Clear Checksum-error Interrupt (LIN only)
    Uint32 CLRPBEINT:1;                       // 30 Clear Physical Bus Error Interrupt (LIN only)
    Uint32 CLRBEINT:1;                        // 31 Clear Bit Error Interrupt (LIN only)
};

union SCICLEARINT_REG {
    Uint32  all;
    struct  SCICLEARINT_BITS  bit;
};

struct SCISETINTLVL_BITS {                    // bits description
    Uint32 SETBRKDTINTLVL:1;                  // 0 Set Break-detect Interrupt Level (SCI compatible mode)
    Uint32 SETWAKEUPINTLVL:1;                 // 1 Set Wake-up Interrupt Level
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 SETTIMEOUTINTLVL:1;                // 4 Set Timeout Interrupt Level (LIN only)
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 SETTOAWUSINTLVL:1;                 // 6 Set Timeout After Wakeup Signal Interrupt Level (LIN only)
    Uint32 SETTOA3WUSINTLVL:1;                // 7 Set Timeout After 3 Wakeup Signals Interrupt Level
    Uint32 SETTXINTLVL:1;                     // 8 Set Transmitter Interrupt Level
    Uint32 SETRXINTOVO:1;                     // 9 Receiver Interrupt Enable Level
    Uint32 rsvd3:3;                           // 12:10 Reserved
    Uint32 SETIDINTLVL:1;                     // 13 Set Identifier Interrupt Level (LIN only)
    Uint32 rsvd4:2;                           // 15:14 Reserved
    Uint32 rsvd5:2;                           // 17:16 Reserved
    Uint32 rsvd6:1;                           // 18 Reserved
    Uint32 rsvd7:5;                           // 23:19 Reserved
    Uint32 SETPEINTLVL:1;                     // 24 Set Parity Interrupt Level
    Uint32 SETOEINTLVL:1;                     // 25 Set Overrun-Error Interrupt Level
    Uint32 SETFEINTLVL:1;                     // 26 Set Framing-Error Interrupt Level
    Uint32 SETNREINTLVL:1;                    // 27 Set No-Response-Error Interrupt Level (LIN only)
    Uint32 SETISFEINTLVL:1;                   // 28 Set Inconsistent-Sync-Field-Error Interrupt Level
    Uint32 SETCEINTLVL:1;                     // 29 Set Checksum-error Interrupt Level (LIN only)
    Uint32 SETPBEINTLVL:1;                    // 30 Set Physical Bus Error Interrupt Level (LIN only)
    Uint32 SETBEINTLVL:1;                     // 31 Set Bit Error Interrupt Level (LIN only)
};

union SCISETINTLVL_REG {
    Uint32  all;
    struct  SCISETINTLVL_BITS  bit;
};

struct SCICLEARINTLVL_BITS {                  // bits description
    Uint32 CLRBRKDTINTLVL:1;                  // 0 Clear Break-detect Interrupt Level (SCI compatible mode)
    Uint32 CLRWAKEUPINTLVL:1;                 // 1 Clear Wake-up Interrupt Level
    Uint32 rsvd1:2;                           // 3:2 Reserved
    Uint32 CLRTIMEOUTINTLVL:1;                // 4 Clear Timeout Interrupt Level (LIN only)
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 CLRTOAWUSINTLVL:1;                 // 6 Clear Timeout After Wakeup Signal Interrupt Level (LIN only)
    Uint32 CLRTOA3WUSINTLVL:1;                // 7 Clear Timeout After 3 Wakeup Signals
    Uint32 CLRTXINTLVL:1;                     // 8 Clear Transmitter Interrupt Level
    Uint32 CLRRXINTLVL:1;                     // 9 Clear Receiver interrupt Level.
    Uint32 rsvd3:3;                           // 12:10 Reserved
    Uint32 CLRIDINTLVL:1;                     // 13 Clear Identifier Interrupt Level (LIN only)
    Uint32 rsvd4:2;                           // 15:14 Reserved
    Uint32 rsvd5:2;                           // 17:16 Reserved
    Uint32 rsvd6:1;                           // 18 Reserved
    Uint32 rsvd7:5;                           // 23:19 Reserved
    Uint32 CLRPEINTLVL:1;                     // 24 Clear Parity Interrupt Level
    Uint32 CLROEINTLVL:1;                     // 25 Clear Overrun-Error Interrupt Level
    Uint32 CLRFEINTLVL:1;                     // 26 Clear Framing-Error Interrupt Level
    Uint32 CLRNREINTLVL:1;                    // 27 Clear No-Response-Error Interrupt Level (LIN only)
    Uint32 CLRISFEINTLVL:1;                   // 28 Clear Inconsistent-Sync-Field-Error
    Uint32 CLRCEINTLVL:1;                     // 29 Clear Checksum-error Interrupt Level (LIN only)
    Uint32 CLRPBEINTLVL:1;                    // 30 Clear Physical Bus Error Interrupt Level (LIN only)
    Uint32 CLRBEINTLVL:1;                     // 31 Clear Bit Error Interrupt Level (LIN only)
};

union SCICLEARINTLVL_REG {
    Uint32  all;
    struct  SCICLEARINTLVL_BITS  bit;
};

struct SCIFLR_BITS {                          // bits description
    Uint32 BRKDT:1;                           // 0 Break-detect Flag (SCI compatible mode)
    Uint32 WAKEUP:1;                          // 1 Wake-up Flag
    Uint32 IDLE1:1;                            // 2 SCI receiver in idle state (SCI compatible mode)
    Uint32 BUSY:1;                            // 3 Busy Flag
    Uint32 TIMEOUT:1;                         // 4 LIN Bus IDLE timeout Flag (LIN only)
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 TOAWUS:1;                          // 6 Timeout After Wakeup Signal Flag (LIN only)
    Uint32 TOA3WUS:1;                         // 7 Timeout After 3 Wakeup Signals Flag (LIN only)
    Uint32 TXRDY:1;                           // 8 Transmitter Buffer Ready Flag
    Uint32 RXRDY:1;                           // 9 Receiver Buffer Ready Flag
    Uint32 TXWAKE:1;                          // 10 SCI Transmitter Wakeup Method Select
    Uint32 TXEMPTY:1;                         // 11 Transmitter Empty Flag
    Uint32 RXWAKE:1;                          // 12 Receiver Wakeup Detect Flag
    Uint32 IDTXFLAG:1;                        // 13 Identifier On Transmit Flag (LIN only)
    Uint32 IDRXFLAG:1;                        // 14 Identifier on Receive Flag
    Uint32 rsvd2:1;                           // 15 Reserved
    Uint32 rsvd3:8;                           // 23:16 Reserved
    Uint32 PE:1;                              // 24 Parity Error Flag
    Uint32 OE:1;                              // 25 Overrun Error Flag
    Uint32 FE:1;                              // 26 Framing Error Flag
    Uint32 NRE:1;                             // 27 No-Response Error Flag (LIN only)
    Uint32 ISFE:1;                            // 28 Inconsistent Sync Field Error Flag (LIN only)
    Uint32 CE:1;                              // 29 Checksum Error Flag (LIN only)
    Uint32 PBE:1;                             // 30 Physical Bus Error Flag (LIN only)
    Uint32 BE:1;                              // 31 Bit Error Flag (LIN only)
};

union SCIFLR_REG {
    Uint32  all;
    struct  SCIFLR_BITS  bit;
};

struct SCIINTVECT0_BITS {                     // bits description
    Uint32 INTVECT0:5;                        // 4:0 LIN Module reset bit
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIINTVECT0_REG {
    Uint32  all;
    struct  SCIINTVECT0_BITS  bit;
};

struct SCIINTVECT1_BITS {                     // bits description
    Uint32 INTVECT1:5;                        // 4:0 LIN Module reset bit
    Uint32 rsvd1:11;                          // 15:5 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIINTVECT1_REG {
    Uint32  all;
    struct  SCIINTVECT1_BITS  bit;
};

struct SCIFORMAT_BITS {                       // bits description
    Uint32 CHAR:3;                            // 2:0 Character Length Control Bits
    Uint32 rsvd1:13;                          // 15:3 Reserved
    Uint32 LENGTH:3;                          // 18:16 Frame Length Control Bits
    Uint32 rsvd2:13;                          // 31:19 Reserved
};

union SCIFORMAT_REG {
    Uint32  all;
    struct  SCIFORMAT_BITS  bit;
};

struct BRSR_BITS {                            // bits description
    Uint32 SCI_LIN_PSL:16;                    // 15:0 24-Bit Integer Prescaler Select (Low Bits)
    Uint32 SCI_LIN_PSH:8;                     // 23:16 24-Bit Integer Prescaler Select (High Bits)
    Uint32 M:4;                               // 27:24 M 4-bit Fractional Divider selection
    Uint32 U:3;                               // 30:28 U Superfractional divider Selection
    Uint32 rsvd1:1;                           // 31 Reserved
};

union BRSR_REG {
    Uint32  all;
    struct  BRSR_BITS  bit;
};

struct SCIED_BITS {                           // bits description
    Uint32 ED:8;                              // 7:0 Receiver Emulation Data.
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIED_REG {
    Uint32  all;
    struct  SCIED_BITS  bit;
};

struct SCIRD_BITS {                           // bits description
    Uint32 RD:8;                              // 7:0 Received Data.
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCIRD_REG {
    Uint32  all;
    struct  SCIRD_BITS  bit;
};

struct SCITD_BITS {                           // bits description
    Uint32 TD:8;                              // 7:0 Transmit data
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union SCITD_REG {
    Uint32  all;
    struct  SCITD_BITS  bit;
};

struct SCIPIO2_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 RXIN:1;                            // 1 SCIRX pin value
    Uint32 TXIN:1;                            // 2 SCITX pin value
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union SCIPIO2_REG {
    Uint32  all;
    struct  SCIPIO2_BITS  bit;
};

struct LINCOMP_BITS {                         // bits description
    Uint32 SBREAK:3;                          // 2:0 Sync Break Extend
    Uint32 rsvd1:5;                           // 7:3 Reserved
    Uint32 SDEL:2;                            // 9:8 Sync Delimiter Compare
    Uint32 rsvd2:6;                           // 15:10 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union LINCOMP_REG {
    Uint32  all;
    struct  LINCOMP_BITS  bit;
};

struct LINRD0_BITS {                          // bits description
    Uint32 RD3:8;                             // 7:0 Receive Buffer 3
    Uint32 RD2:8;                             // 15:8 Receive Buffer 2
    Uint32 RD1:8;                             // 23:16 Receive Buffer 1
    Uint32 RD0:8;                             // 31:24 Receive Buffer 0
};

union LINRD0_REG {
    Uint32  all;
    struct  LINRD0_BITS  bit;
};

struct LINRD1_BITS {                          // bits description
    Uint32 RD7:8;                             // 7:0 Receive Buffer 3
    Uint32 RD6:8;                             // 15:8 Receive Buffer 2
    Uint32 RD5:8;                             // 23:16 Receive Buffer 1
    Uint32 RD4:8;                             // 31:24 Receive Buffer 0
};

union LINRD1_REG {
    Uint32  all;
    struct  LINRD1_BITS  bit;
};

struct LINMASK_BITS {                         // bits description
    Uint32 TXIDMASK:8;                        // 7:0 TX ID Mask bits (LIN only)
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 RXIDMASK:8;                        // 23:16 RX ID Mask bits (LIN only)
    Uint32 rsvd2:8;                           // 31:24 Reserved
};

union LINMASK_REG {
    Uint32  all;
    struct  LINMASK_BITS  bit;
};

struct LINID_BITS {                           // bits description
    Uint32 IDBYTE:8;                          // 7:0 LIN message ID (LIN only)
    Uint32 IDSLAVETASKBYTE:8;                 // 15:8 ID Slave Task byte (LIN only)
    Uint32 RECEIVEDID:8;                      // 23:16 Current Message ID (LIN only)
    Uint32 rsvd1:8;                           // 31:24 Reserved
};

union LINID_REG {
    Uint32  all;
    struct  LINID_BITS  bit;
};

struct LINTD0_BITS {                          // bits description
    Uint32 TD3:8;                             // 7:0 TRANSMIT Buffer 3
    Uint32 TD2:8;                             // 15:8 TRANSMIT Buffer 2
    Uint32 TD1:8;                             // 23:16 TRANSMIT Buffer 1
    Uint32 TD0:8;                             // 31:24 TRANSMIT Buffer 0
};

union LINTD0_REG {
    Uint32  all;
    struct  LINTD0_BITS  bit;
};

struct LINTD1_BITS {                          // bits description
    Uint32 TD7:8;                             // 7:0 TRANSMIT Buffer 7
    Uint32 TD6:8;                             // 15:8 TRANSMIT Buffer 6
    Uint32 TD5:8;                             // 23:16 TRANSMIT Buffer 5
    Uint32 TD4:8;                             // 31:24 TRANSMIT Buffer 4
};

union LINTD1_REG {
    Uint32  all;
    struct  LINTD1_BITS  bit;
};

struct MBRSR_BITS {                           // bits description
    Uint32 MBR:13;                            // 12:0 Received Data.
    Uint32 rsvd1:3;                           // 15:13 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union MBRSR_REG {
    Uint32  all;
    struct  MBRSR_BITS  bit;
};

struct IODFTCTRL_BITS {                       // bits description
    Uint32 RXPENA:1;                          // 0 Analog Loopback Via Receive Pin Enable
    Uint32 LPBENA:1;                          // 1 Module Loopback Enable
    Uint32 rsvd1:6;                           // 7:2 Reserved
    Uint32 IODFTENA:4;                        // 11:8 IO DFT Enable Key
    Uint32 rsvd2:4;                           // 15:12 Reserved
    Uint32 TXSHIFT:3;                         // 18:16 Transmit Delay Shift
    Uint32 PINSAMPLEMASK:2;                   // 20:19 TX Pin Sample Mask
    Uint32 rsvd3:3;                           // 23:21 Reserved
    Uint32 BRKDTERRENA:1;                     // 24 Break Detect Error Enable (SCI compatibility mode)
    Uint32 PERRENA:1;                         // 25 Parity Error Enable (SCI compatibility mode)
    Uint32 FERRENA:1;                         // 26 Frame Error Enable (SCI compatibility mode)
    Uint32 rsvd4:1;                           // 27 Reserved
    Uint32 ISFERRENA:1;                       // 28 Inconsistent Sync Field Error Enable (LIN mode)
    Uint32 CERRENA:1;                         // 29 Checksum Error Enable(LIN mode)
    Uint32 PBERRENA:1;                        // 30 Physical Bus Error Enable (LIN mode)
    Uint32 BERRENA:1;                         // 31 Bit Error Enable (LIN mode)
};

union IODFTCTRL_REG {
    Uint32  all;
    struct  IODFTCTRL_BITS  bit;
};

struct SCIPIO0_BITS {                         // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 RXFUNC:1;                          // 1 LINRX pin function
    Uint32 TXFUNC:1;                          // 2 LINTX pin function
    Uint32 rsvd2:29;                          // 31:3 Reserved
};

union SCIPIO0_REG {
    Uint32  all;
    struct  SCIPIO0_BITS  bit;
};

struct LIN_GLB_INT_EN_BITS {                  // bits description
    Uint32 GLBINT0_EN:1;                      // 0 Global Interrupt Enable for LIN INT0
    Uint32 GLBINT1_EN:1;                      // 1 Global Interrupt Enable for LIN INT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union LIN_GLB_INT_EN_REG {
    Uint32  all;
    struct  LIN_GLB_INT_EN_BITS  bit;
};

struct LIN_GLB_INT_FLG_BITS {                 // bits description
    Uint32 INT0_FLG:1;                        // 0 Global Interrupt Flag for LIN INT0
    Uint32 INT1_FLG:1;                        // 1 Global Interrupt Flag for LIN INT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union LIN_GLB_INT_FLG_REG {
    Uint32  all;
    struct  LIN_GLB_INT_FLG_BITS  bit;
};

struct LIN_GLB_INT_CLR_BITS {                 // bits description
    Uint32 INT0_FLG_CLR:1;                    // 0 Global Interrupt flag clear for LIN INT0
    Uint32 INT1_FLG_CLR:1;                    // 1 Global Interrupt flag clear for LIN INT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union LIN_GLB_INT_CLR_REG {
    Uint32  all;
    struct  LIN_GLB_INT_CLR_BITS  bit;
};

struct  LIN_REGS {
    union   SCIGCR0_REG                      SCIGCR0;                     // 0x0 Global Control Register 0
    union   SCIGCR1_REG                      SCIGCR1;                     // 0x4 Global Control Register 1
    union   SCIGCR2_REG                      SCIGCR2;                     // 0x8 Global Control Register 2
    union   SCISETINT_REG                    SCISETINT;                   // 0xc Interrupt Enable Register
    union   SCICLEARINT_REG                  SCICLEARINT;                 // 0x10 Interrupt Disable Register
    union   SCISETINTLVL_REG                 SCISETINTLVL;                // 0x14 Set Interrupt Level Register
    union   SCICLEARINTLVL_REG               SCICLEARINTLVL;              // 0x18 Clear Interrupt Level Register
    union   SCIFLR_REG                       SCIFLR;                      // 0x1c Flag Register
    union   SCIINTVECT0_REG                  SCIINTVECT0;                 // 0x20 Interrupt Vector Offset Register 0
    union   SCIINTVECT1_REG                  SCIINTVECT1;                 // 0x24 Interrupt Vector Offset Register 1
    union   SCIFORMAT_REG                    SCIFORMAT;                   // 0x28 Length Control Register
    union   BRSR_REG                         BRSR;                        // 0x2c Baud Rate Selection Register
    union   SCIED_REG                        SCIED;                       // 0x30 Emulation buffer Register
    union   SCIRD_REG                        SCIRD;                       // 0x34 Receiver data buffer Register
    union   SCITD_REG                        SCITD;                       // 0x38 Transmit data buffer Register
    union   SCIPIO2_REG                      SCIPIO2;                     // 0x3c Pin control Register 2
    union   LINCOMP_REG                      LINCOMP;                     // 0x40 Compare register
    union   LINRD0_REG                       LINRD0;                      // 0x44 Receive data register 0
    union   LINRD1_REG                       LINRD1;                      // 0x48 Receive data register 1
    union   LINMASK_REG                      LINMASK;                     // 0x4c Acceptance mask register
    union   LINID_REG                        LINID;                       // 0x50 LIN ID Register
    union   LINTD0_REG                       LINTD0;                      // 0x54 Transmit Data Register 0
    union   LINTD1_REG                       LINTD1;                      // 0x58 Transmit Data Register 1
    union   MBRSR_REG                        MBRSR;                       // 0x5c Maximum Baud Rate Selection Register
    union   IODFTCTRL_REG                    IODFTCTRL;                   // 0x60 IODFT for LIN
    union   SCIPIO0_REG                      SCIPIO0;                     // 0x64 Pin control Register 0
    union   LIN_GLB_INT_EN_REG               LIN_GLB_INT_EN;              // 0x68 LIN Global Interrupt Enable Register
    union   LIN_GLB_INT_FLG_REG              LIN_GLB_INT_FLG;             // 0x6c LIN Global Interrupt Flag Register
    union   LIN_GLB_INT_CLR_REG              LIN_GLB_INT_CLR;             // 0x70 LIN Global Interrupt Clear Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
