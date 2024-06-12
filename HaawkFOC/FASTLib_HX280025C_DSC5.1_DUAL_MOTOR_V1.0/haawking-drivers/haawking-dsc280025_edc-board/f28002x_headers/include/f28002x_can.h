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


#ifndef F28002X_CAN_H
#define F28002X_CAN_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CAN Individual Register Bit Definitions:

struct CAN_CTL_BITS {                         // bits description
    Uint32 Init:1;                            // 0 Initialization
    Uint32 IE0:1;                             // 1 Interrupt line 0 Enable
    Uint32 SIE:1;                             // 2 Status Change Interrupt Enable
    Uint32 EIE:1;                             // 3 Error Interrupt Enable
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 DAR:1;                             // 5 Disable Automatic Retransmission
    Uint32 CCE:1;                             // 6 Configuration Change Enable
    Uint32 Test:1;                            // 7 Test Mode Enable
    Uint32 IDS:1;                             // 8 Interruption Debug Support Enable
    Uint32 ABO:1;                             // 9 Auto-Bus-On Enable
    Uint32 PMD:4;                             // 13:10 Parity on/off
    Uint32 rsvd2:1;                           // 14 Reserved
    Uint32 SWR:1;                             // 15 SW Reset Enable
    Uint32 INITDBG:1;                         // 16 Debug Mode Status
    Uint32 IE1:1;                             // 17 Interrupt line 1 Enable Disabled
    Uint32 DE1:1;                             // 18 Enable DMA request line
    Uint32 DE2:1;                             // 19 Enable DMA request line
    Uint32 DE3:1;                             // 20 Enable DMA request line
    Uint32 rsvd3:3;                           // 23:21 Reserved
    Uint32 rsvd4:1;                           // 24 Reserved
    Uint32 rsvd5:1;                           // 25 Reserved
    Uint32 rsvd6:6;                           // 31:26 Reserved
};

union CAN_CTL_REG {
    Uint32  all;
    struct  CAN_CTL_BITS  bit;
};

struct CAN_ES_BITS {                          // bits description
    Uint32 LEC:3;                             // 2:0 Last Error Code
    Uint32 TxOk:1;                            // 3 Transmission status
    Uint32 RxOk:1;                            // 4 Reception status
    Uint32 EPass:1;                           // 5 Error Passive State
    Uint32 EWarn:1;                           // 6 Warning State
    Uint32 BOff:1;                            // 7 Bus-Off State
    Uint32 PER:1;                             // 8 Parity Error Detected
    Uint32 rsvd1:1;                           // 9 Reserved
    Uint32 rsvd2:1;                           // 10 Reserved
    Uint32 rsvd3:5;                           // 15:11 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union CAN_ES_REG {
    Uint32  all;
    struct  CAN_ES_BITS  bit;
};

struct CAN_ERRC_BITS {                        // bits description
    Uint32 TEC:8;                             // 7:0 Transmit Error Counter
    Uint32 REC:7;                             // 14:8 Receive Error Counter
    Uint32 RP:1;                              // 15 Receive Error Passive
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CAN_ERRC_REG {
    Uint32  all;
    struct  CAN_ERRC_BITS  bit;
};

struct CAN_BTR_BITS {                         // bits description
    Uint32 BRP:6;                             // 5:0 Baud Rate Prescaler
    Uint32 SJW:2;                             // 7:6 Synchronization Jump Width
    Uint32 TSEG1:4;                           // 11:8 Time segment
    Uint32 TSEG2:3;                           // 14:12 Time segment
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 BRPE:4;                            // 19:16 Baud Rate Prescaler Extension
    Uint32 rsvd2:12;                          // 31:20 Reserved
};

union CAN_BTR_REG {
    Uint32  all;
    struct  CAN_BTR_BITS  bit;
};

struct CAN_INT_BITS {                         // bits description
    Uint32 INT0ID:16;                         // 15:0 Interrupt Identifier
    Uint32 INT1ID:8;                          // 23:16 Interrupt 1 Identifier
    Uint32 rsvd1:8;                           // 31:24 Reserved
};

union CAN_INT_REG {
    Uint32  all;
    struct  CAN_INT_BITS  bit;
};

struct CAN_TEST_BITS {                        // bits description
    Uint32 rsvd1:3;                           // 2:0 Reserved
    Uint32 SILENT:1;                          // 3 Silent Mode
    Uint32 LBACK:1;                           // 4 Loopback Mode
    Uint32 TX:2;                              // 6:5 CANTX Pin Control
    Uint32 RX:1;                              // 7 CANRX Pin Status
    Uint32 EXL:1;                             // 8 External Loopback Mode
    Uint32 RDA:1;                             // 9 RAM Direct Access Enable:
    Uint32 rsvd2:6;                           // 15:10 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CAN_TEST_REG {
    Uint32  all;
    struct  CAN_TEST_BITS  bit;
};

struct CAN_PERR_BITS {                        // bits description
    Uint32 MSG_NUM:8;                         // 7:0 Message Number
    Uint32 WORD_NUM:3;                        // 10:8 Word Number
    Uint32 rsvd1:5;                           // 15:11 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_PERR_REG {
    Uint32  all;
    struct  CAN_PERR_BITS  bit;
};

struct CAN_RAM_INIT_BITS {                    // bits description
    Uint32 KEY0:1;                            // 0 KEY0
    Uint32 KEY1:1;                            // 1 KEY1
    Uint32 KEY2:1;                            // 2 KEY2
    Uint32 KEY3:1;                            // 3 KEY3
    Uint32 CAN_RAM_INIT:1;                    // 4 Initialize CAN Mailbox RAM
    Uint32 RAM_INIT_DONE:1;                   // 5 CAN RAM initialization complete
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_RAM_INIT_REG {
    Uint32  all;
    struct  CAN_RAM_INIT_BITS  bit;
};

struct CAN_GLB_INT_EN_BITS {                  // bits description
    Uint32 GLBINT0_EN:1;                      // 0 Global Interrupt Enable for CANINT0
    Uint32 GLBINT1_EN:1;                      // 1 Global Interrupt Enable for CANINT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_GLB_INT_EN_REG {
    Uint32  all;
    struct  CAN_GLB_INT_EN_BITS  bit;
};

struct CAN_GLB_INT_FLG_BITS {                 // bits description
    Uint32 INT0_FLG:1;                        // 0 Global Interrupt Flag for CANINT0
    Uint32 INT1_FLG:1;                        // 1 Global Interrupt Flag for CANINT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_GLB_INT_FLG_REG {
    Uint32  all;
    struct  CAN_GLB_INT_FLG_BITS  bit;
};

struct CAN_GLB_INT_CLR_BITS {                 // bits description
    Uint32 INT0_FLG_CLR:1;                    // 0 Global Interrupt flag clear for CANINT0
    Uint32 INT1_FLG_CLR:1;                    // 1 Global Interrupt flag clear for CANINT1
    Uint32 rsvd1:14;                          // 15:2 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_GLB_INT_CLR_REG {
    Uint32  all;
    struct  CAN_GLB_INT_CLR_BITS  bit;
};

struct CAN_TXRQ_X_BITS {                      // bits description
    Uint32 TxRqstReg1:2;                      // 1:0 Transmit Request Register 1
    Uint32 TxRqstReg2:2;                      // 3:2 Transmit Request Register 2
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_TXRQ_X_REG {
    Uint32  all;
    struct  CAN_TXRQ_X_BITS  bit;
};

struct CAN_NDAT_X_BITS {                      // bits description
    Uint32 NewDatReg1:2;                      // 1:0 New Data Register 1
    Uint32 NewDatReg2:2;                      // 3:2 New Data Register 2
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_NDAT_X_REG {
    Uint32  all;
    struct  CAN_NDAT_X_BITS  bit;
};

struct CAN_IPEN_X_BITS {                      // bits description
    Uint32 IntPndReg1:2;                      // 1:0 Interrupt Pending Register 1
    Uint32 IntPndReg2:2;                      // 3:2 Interrupt Pending Register 2
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_IPEN_X_REG {
    Uint32  all;
    struct  CAN_IPEN_X_BITS  bit;
};

struct CAN_MVAL_X_BITS {                      // bits description
    Uint32 MsgValReg1:2;                      // 1:0 Message Valid Register 1
    Uint32 MsgValReg2:2;                      // 3:2 Message Valid Register 2
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_MVAL_X_REG {
    Uint32  all;
    struct  CAN_MVAL_X_BITS  bit;
};

struct CAN_IF1CMD_BITS {                      // bits description
    Uint32 MSG_NUM:8;                         // 7:0 Message Number
    Uint32 rsvd1:6;                           // 13:8 Reserved
    Uint32 DMAactive:1;                       // 14 DMA Status
    Uint32 Busy:1;                            // 15 Busy Flag
    Uint32 DATA_B:1;                          // 16 Access Data Bytes 4-7
    Uint32 DATA_A:1;                          // 17 Access Data Bytes 0-3
    Uint32 TXRQST:1;                          // 18 Access Transmission Request Bit
    Uint32 ClrIntPnd:1;                       // 19 Clear Interrupt Pending Bit
    Uint32 Control:1;                         // 20 Access Control Bits
    Uint32 Arb:1;                             // 21 Access Arbitration Bits
    Uint32 Mask:1;                            // 22 Access Mask Bits
    Uint32 DIR:1;                             // 23 Write/Read Direction
    Uint32 rsvd2:8;                           // 31:24 Reserved
};

union CAN_IF1CMD_REG {
    Uint32  all;
    struct  CAN_IF1CMD_BITS  bit;
};

struct CAN_IF1MSK_BITS {                      // bits description
    Uint32 Msk:29;                            // 28:0 Identifier Mask
    Uint32 rsvd1:1;                           // 29 Reserved
    Uint32 MDir:1;                            // 30 Mask Message Direction
    Uint32 MXtd:1;                            // 31 Mask Extended Identifier
};

union CAN_IF1MSK_REG {
    Uint32  all;
    struct  CAN_IF1MSK_BITS  bit;
};

struct CAN_IF1ARB_BITS {                      // bits description
    Uint32 ID:29;                             // 28:0  
    Uint32 Dir:1;                             // 29 Message Direction
    Uint32 Xtd:1;                             // 30 Extended Identifier
    Uint32 MsgVal:1;                          // 31 Message Valid
};

union CAN_IF1ARB_REG {
    Uint32  all;
    struct  CAN_IF1ARB_BITS  bit;
};

struct CAN_IF1MCTL_BITS {                     // bits description
    Uint32 DLC:4;                             // 3:0 Data length code
    Uint32 rsvd1:3;                           // 6:4 Reserved
    Uint32 EoB:1;                             // 7 End of Block
    Uint32 TxRqst:1;                          // 8 Transmit Request
    Uint32 RmtEn:1;                           // 9 Remote Enable
    Uint32 RxIE:1;                            // 10 Receive Interrupt Enable
    Uint32 TxIE:1;                            // 11 Transmit Interrupt Enable
    Uint32 UMask:1;                           // 12 Use Acceptance Mask
    Uint32 IntPnd:1;                          // 13 Interrupt Pending
    Uint32 MsgLst:1;                          // 14 Message Lost
    Uint32 NewDat:1;                          // 15 New Data
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_IF1MCTL_REG {
    Uint32  all;
    struct  CAN_IF1MCTL_BITS  bit;
};

struct CAN_IF1DATA_BITS {                     // bits description
    Uint32 Data_0:8;                          // 7:0 Data Byte 0
    Uint32 Data_1:8;                          // 15:8 Data Byte 1
    Uint32 Data_2:8;                          // 23:16 Data Byte 2
    Uint32 Data_3:8;                          // 31:24 Data Byte 3
};

union CAN_IF1DATA_REG {
    Uint32  all;
    struct  CAN_IF1DATA_BITS  bit;
};

struct CAN_IF1DATB_BITS {                     // bits description
    Uint32 Data_4:8;                          // 7:0 Data Byte 4
    Uint32 Data_5:8;                          // 15:8 Data Byte 5
    Uint32 Data_6:8;                          // 23:16 Data Byte 6
    Uint32 Data_7:8;                          // 31:24 Data Byte 7
};

union CAN_IF1DATB_REG {
    Uint32  all;
    struct  CAN_IF1DATB_BITS  bit;
};

struct CAN_IF2CMD_BITS {                      // bits description
    Uint32 MSG_NUM:8;                         // 7:0 Message Number
    Uint32 rsvd1:6;                           // 13:8 Reserved
    Uint32 DMAactive:1;                       // 14 DMA Status
    Uint32 Busy:1;                            // 15 Busy Flag
    Uint32 DATA_B:1;                          // 16 Access Data Bytes 4-7
    Uint32 DATA_A:1;                          // 17 Access Data Bytes 0-3
    Uint32 TxRqst:1;                          // 18 Access Transmission Request Bit
    Uint32 ClrIntPnd:1;                       // 19 Clear Interrupt Pending Bit
    Uint32 Control:1;                         // 20 Access Control Bits
    Uint32 Arb:1;                             // 21 Access Arbitration Bits
    Uint32 Mask:1;                            // 22 Access Mask Bits
    Uint32 DIR:1;                             // 23 Write/Read Direction
    Uint32 rsvd2:8;                           // 31:24 Reserved
};

union CAN_IF2CMD_REG {
    Uint32  all;
    struct  CAN_IF2CMD_BITS  bit;
};

struct CAN_IF2MSK_BITS {                      // bits description
    Uint32 Msk:29;                            // 28:0 Identifier Mask
    Uint32 rsvd1:1;                           // 29 Reserved
    Uint32 MDir:1;                            // 30 Mask Message Direction
    Uint32 MXtd:1;                            // 31 Mask Extended Identifier
};

union CAN_IF2MSK_REG {
    Uint32  all;
    struct  CAN_IF2MSK_BITS  bit;
};

struct CAN_IF2ARB_BITS {                      // bits description
    Uint32 ID:29;                             // 28:0 Message Identifier
    Uint32 Dir:1;                             // 29 Message Direction
    Uint32 Xtd:1;                             // 30 Extended Identifier
    Uint32 MsgVal:1;                          // 31 Message Valid
};

union CAN_IF2ARB_REG {
    Uint32  all;
    struct  CAN_IF2ARB_BITS  bit;
};

struct CAN_IF2MCTL_BITS {                     // bits description
    Uint32 DLC:4;                             // 3:0 Data length code
    Uint32 rsvd1:3;                           // 6:4 Reserved
    Uint32 EoB:1;                             // 7 End of Block
    Uint32 TxRqst:1;                          // 8 Transmit Request
    Uint32 RmtEn:1;                           // 9 Remote Enable
    Uint32 RxIE:1;                            // 10 Receive Interrupt Enable
    Uint32 TxIE:1;                            // 11 Transmit Interrupt Enable
    Uint32 UMask:1;                           // 12 Use Acceptance Mask
    Uint32 IntPnd:1;                          // 13 Interrupt Pending
    Uint32 MsgLst:1;                          // 14 Message Lost
    Uint32 NewDat:1;                          // 15 New Data
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_IF2MCTL_REG {
    Uint32  all;
    struct  CAN_IF2MCTL_BITS  bit;
};

struct CAN_IF2DATA_BITS {                     // bits description
    Uint32 Data_0:8;                          // 7:0 Data Byte 0
    Uint32 Data_1:8;                          // 15:8 Data Byte 1
    Uint32 Data_2:8;                          // 23:16 Data Byte 2
    Uint32 Data_3:8;                          // 31:24 Data Byte 3
};

union CAN_IF2DATA_REG {
    Uint32  all;
    struct  CAN_IF2DATA_BITS  bit;
};

struct CAN_IF2DATB_BITS {                     // bits description
    Uint32 Data_4:8;                          // 7:0 Data Byte 4
    Uint32 Data_5:8;                          // 15:8 Data Byte 5
    Uint32 Data_6:8;                          // 23:16 Data Byte 6
    Uint32 Data_7:8;                          // 31:24 Data Byte 7
};

union CAN_IF2DATB_REG {
    Uint32  all;
    struct  CAN_IF2DATB_BITS  bit;
};

struct CAN_IF3OBS_BITS {                      // bits description
    Uint32 Mask:1;                            // 0 Mask data read observation
    Uint32 Arb:1;                             // 1 Arbitration data read observation
    Uint32 Ctrl:1;                            // 2 Ctrl read observation
    Uint32 Data_A:1;                          // 3 Data A read observation
    Uint32 Data_B:1;                          // 4 Data B read observation
    Uint32 rsvd1:3;                           // 7:5 Reserved
    Uint32 IF3SM:1;                           // 8 IF3 Status of Mask data read access
    Uint32 IF3SA:1;                           // 9 IF3 Status of Arbitration data read access
    Uint32 IF3SC:1;                           // 10 IF3 Status of Control bits read access
    Uint32 IF3SDA:1;                          // 11 IF3 Status of Data A read access
    Uint32 IF3SDB:1;                          // 12 IF3 Status of Data B read access
    Uint32 rsvd2:2;                           // 14:13 Reserved
    Uint32 IF3Upd:1;                          // 15 IF3 Update Data
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union CAN_IF3OBS_REG {
    Uint32  all;
    struct  CAN_IF3OBS_BITS  bit;
};

struct CAN_IF3MSK_BITS {                      // bits description
    Uint32 Msk:29;                            // 28:0 Mask
    Uint32 rsvd1:1;                           // 29 Reserved
    Uint32 MDir:1;                            // 30 Mask Message Direction
    Uint32 MXtd:1;                            // 31 Mask Extended Identifier
};

union CAN_IF3MSK_REG {
    Uint32  all;
    struct  CAN_IF3MSK_BITS  bit;
};

struct CAN_IF3ARB_BITS {                      // bits description
    Uint32 ID:29;                             // 28:0 Message Identifier
    Uint32 Dir:1;                             // 29 Message Direction
    Uint32 Xtd:1;                             // 30 Extended Identifier
    Uint32 MsgVal:1;                          // 31 Message Valid
};

union CAN_IF3ARB_REG {
    Uint32  all;
    struct  CAN_IF3ARB_BITS  bit;
};

struct CAN_IF3MCTL_BITS {                     // bits description
    Uint32 DLC:4;                             // 3:0 Data length code
    Uint32 rsvd1:3;                           // 6:4 Reserved
    Uint32 EoB:1;                             // 7 End of Block
    Uint32 TxRqst:1;                          // 8 Transmit Request
    Uint32 RmtEn:1;                           // 9 Remote Enable
    Uint32 RxIE:1;                            // 10 Receive Interrupt Enable
    Uint32 TxIE:1;                            // 11 Transmit Interrupt Enable
    Uint32 UMask:1;                           // 12 Use Acceptance Mask
    Uint32 IntPnd:1;                          // 13 Interrupt Pending
    Uint32 MsgLst:1;                          // 14 Message Lost
    Uint32 NewDat:1;                          // 15 New Data
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CAN_IF3MCTL_REG {
    Uint32  all;
    struct  CAN_IF3MCTL_BITS  bit;
};

struct CAN_IF3DATA_BITS {                     // bits description
    Uint32 Data_0:8;                          // 7:0 Data Byte 0
    Uint32 Data_1:8;                          // 15:8 Data Byte 1
    Uint32 Data_2:8;                          // 23:16 Data Byte 2
    Uint32 Data_3:8;                          // 31:24 Data Byte 3
};

union CAN_IF3DATA_REG {
    Uint32  all;
    struct  CAN_IF3DATA_BITS  bit;
};

struct CAN_IF3DATB_BITS {                     // bits description
    Uint32 Data_4:8;                          // 7:0 Data Byte 4
    Uint32 Data_5:8;                          // 15:8 Data Byte 5
    Uint32 Data_6:8;                          // 23:16 Data Byte 6
    Uint32 Data_7:8;                          // 31:24 Data Byte 7
};

union CAN_IF3DATB_REG {
    Uint32  all;
    struct  CAN_IF3DATB_BITS  bit;
};

struct  CAN_REGS {
    union   CAN_CTL_REG                      CAN_CTL;                     // 0x0 CAN Control Register
    union   CAN_ES_REG                       CAN_ES;                      // 0x4 Error and Status Register
    union   CAN_ERRC_REG                     CAN_ERRC;                    // 0x8 Error Counter Register
    union   CAN_BTR_REG                      CAN_BTR;                     // 0xc Bit Timing Register
    union   CAN_INT_REG                      CAN_INT;                     // 0x10 Interrupt Register
    union   CAN_TEST_REG                     CAN_TEST;                    // 0x14 Test Register
    Uint32                                   rsvd1;                       // 0x18 Reserved
    union   CAN_PERR_REG                     CAN_PERR;                    // 0x1c CAN Parity Error Code Register
    Uint32                                   rsvd2[8];                    // 0x20 Reserved
    union   CAN_RAM_INIT_REG                 CAN_RAM_INIT;                // 0x40 CAN RAM Initialization Register
    Uint32                                   rsvd3[3];                    // 0x44 Reserved
    union   CAN_GLB_INT_EN_REG               CAN_GLB_INT_EN;              // 0x50 CAN Global Interrupt Enable Register
    union   CAN_GLB_INT_FLG_REG              CAN_GLB_INT_FLG;             // 0x54 CAN Global Interrupt Flag Register
    union   CAN_GLB_INT_CLR_REG              CAN_GLB_INT_CLR;             // 0x58 CAN Global Interrupt Clear Register
    Uint32                                   rsvd4[9];                    // 0x5c Reserved
    Uint32                                   CAN_ABOTR;                   // 0x80 Auto-Bus-On Time Register
    union   CAN_TXRQ_X_REG                   CAN_TXRQ_X;                  // 0x84 CAN Transmission Request Register
    Uint32                                   CAN_TXRQ_21;                 // 0x88 CAN Transmission Request 2_1 Register
    Uint32                                   rsvd5[3];                    // 0x8c Reserved
    union   CAN_NDAT_X_REG                   CAN_NDAT_X;                  // 0x98 CAN New Data Register
    Uint32                                   CAN_NDAT_21;                 // 0x9c CAN New Data 2_1 Register
    Uint32                                   rsvd6[3];                    // 0xa0 Reserved
    union   CAN_IPEN_X_REG                   CAN_IPEN_X;                  // 0xac CAN Interrupt Pending Register
    Uint32                                   CAN_IPEN_21;                 // 0xb0 CAN Interrupt Pending 2_1 Register
    Uint32                                   rsvd7[3];                    // 0xb4 Reserved
    union   CAN_MVAL_X_REG                   CAN_MVAL_X;                  // 0xc0 CAN Message Valid Register
    Uint32                                   CAN_MVAL_21;                 // 0xc4 CAN Message Valid 2_1 Register
    Uint32                                   rsvd8[4];                    // 0xc8 Reserved
    Uint32                                   CAN_IP_MUX21;                // 0xd8 CAN Interrupt Multiplexer 2_1 Register
    Uint32                                   rsvd9[9];                    // 0xdc Reserved
    union   CAN_IF1CMD_REG                   CAN_IF1CMD;                  // 0x100 IF1 Command Register
    union   CAN_IF1MSK_REG                   CAN_IF1MSK;                  // 0x104 IF1 Mask Register
    union   CAN_IF1ARB_REG                   CAN_IF1ARB;                  // 0x108 IF1 Arbitration Register
    union   CAN_IF1MCTL_REG                  CAN_IF1MCTL;                 // 0x10c IF1 Message Control Register
    union   CAN_IF1DATA_REG                  CAN_IF1DATA;                 // 0x110 IF1 Data A Register
    union   CAN_IF1DATB_REG                  CAN_IF1DATB;                 // 0x114 IF1 Data B Register
    Uint32                                   rsvd10[2];                   // 0x118 Reserved
    union   CAN_IF2CMD_REG                   CAN_IF2CMD;                  // 0x120 IF2 Command Register
    union   CAN_IF2MSK_REG                   CAN_IF2MSK;                  // 0x124 IF2 Mask Register
    union   CAN_IF2ARB_REG                   CAN_IF2ARB;                  // 0x128 IF2 Arbitration Register
    union   CAN_IF2MCTL_REG                  CAN_IF2MCTL;                 // 0x12c IF2 Message Control Register
    union   CAN_IF2DATA_REG                  CAN_IF2DATA;                 // 0x130 IF2 Data A Register
    union   CAN_IF2DATB_REG                  CAN_IF2DATB;                 // 0x134 IF2 Data B Register
    Uint32                                   rsvd11[2];                   // 0x138 Reserved
    union   CAN_IF3OBS_REG                   CAN_IF3OBS;                  // 0x140 IF3 Observation Register
    union   CAN_IF3MSK_REG                   CAN_IF3MSK;                  // 0x144 IF3 Mask Register
    union   CAN_IF3ARB_REG                   CAN_IF3ARB;                  // 0x148 IF3 Arbitration Register
    union   CAN_IF3MCTL_REG                  CAN_IF3MCTL;                 // 0x14c IF3 Message Control Register
    union   CAN_IF3DATA_REG                  CAN_IF3DATA;                 // 0x150 IF3 Data A Register
    union   CAN_IF3DATB_REG                  CAN_IF3DATB;                 // 0x154 IF3 Data B Register
    Uint32                                   rsvd12[2];                   // 0x158 Reserved
    Uint32                                   CAN_IF3UPD;                  // 0x160 IF3 Update Enable Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================