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


#ifndef F28002X_I2C_H
#define F28002X_I2C_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// I2C Individual Register Bit Definitions:

struct I2COAR_BITS {                          // bits description
    Uint32 OAR:10;                            // 9:0 I2C Own address
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union I2COAR_REG {
    Uint32  all;
    struct  I2COAR_BITS  bit;
};

struct I2CIER_BITS {                          // bits description
    Uint32 ARBL:1;                            // 0 Arbitration-lost interrupt enable
    Uint32 NACK:1;                            // 1 No-acknowledgment interrupt enable
    Uint32 ARDY:1;                            // 2 Register-access-ready interrupt enable
    Uint32 RRDY:1;                            // 3 Receive-data-ready interrupt enable
    Uint32 XRDY:1;                            // 4 Transmit-data-ready interrupt enable
    Uint32 SCD:1;                             // 5 Stop condition detected interrupt enable
    Uint32 AAS:1;                             // 6 Addressed as slave interrupt enable
    Uint32 rsvd1:25;                          // 31:7 Reserved
};

union I2CIER_REG {
    Uint32  all;
    struct  I2CIER_BITS  bit;
};

struct I2CSTR_BITS {                          // bits description
    Uint32 ARBL:1;                            // 0 Arbitration-lost interrupt flag bit
    Uint32 NACK:1;                            // 1 No-acknowledgment interrupt flag bit.
    Uint32 ARDY:1;                            // 2 Register-access-ready interrupt flag bit
    Uint32 RRDY:1;                            // 3 Receive-data-ready interrupt flag bit.
    Uint32 XRDY:1;                            // 4 Transmit-data-ready interrupt flag bit.
    Uint32 SCD:1;                             // 5 Stop condition detected bit.
    Uint32 BYTESENT:1;                        // 6 Byte transmit over indication
    Uint32 rsvd1:1;                           // 7 Reserved
    Uint32 AD0:1;                             // 8 Address 0 bits
    Uint32 AAS:1;                             // 9 Addressed-as-slave bit
    Uint32 XSMT:1;                            // 10 Transmit shift register empty bit.
    Uint32 RSFULL:1;                          // 11 Receive shift register full bit.
    Uint32 BB:1;                              // 12 Bus busy bit.
    Uint32 NACKSNT:1;                         // 13 NACK sent bit.
    Uint32 SDIR:1;                            // 14 Slave direction bit
    Uint32 rsvd2:17;                          // 31:15 Reserved
};

union I2CSTR_REG {
    Uint32  all;
    struct  I2CSTR_BITS  bit;
};

struct I2CDRR_BITS {                          // bits description
    Uint32 DATA:8;                            // 7:0 Receive data
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union I2CDRR_REG {
    Uint32  all;
    struct  I2CDRR_BITS  bit;
};

struct I2CSAR_BITS {                          // bits description
    Uint32 SAR:10;                            // 9:0 Slave Address
    Uint32 rsvd1:22;                          // 31:10 Reserved
};

union I2CSAR_REG {
    Uint32  all;
    struct  I2CSAR_BITS  bit;
};

struct I2CDXR_BITS {                          // bits description
    Uint32 DATA:8;                            // 7:0 Transmit data
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union I2CDXR_REG {
    Uint32  all;
    struct  I2CDXR_BITS  bit;
};

struct I2CMDR_BITS {                          // bits description
    Uint32 BC:3;                              // 2:0 Bit count bits.
    Uint32 FDF:1;                             // 3 Free Data Format
    Uint32 STB:1;                             // 4 START Byte Mode
    Uint32 IRS:1;                             // 5 I2C Module Reset
    Uint32 DLB:1;                             // 6 Digital Loopback Mode
    Uint32 RM:1;                              // 7 Repeat Mode
    Uint32 XA:1;                              // 8 Expanded Address Mode
    Uint32 TRX:1;                             // 9 Transmitter Mode
    Uint32 MST:1;                             // 10 Master Mode
    Uint32 STP:1;                             // 11 STOP Condition
    Uint32 rsvd1:1;                           // 12 Reserved
    Uint32 STT:1;                             // 13 START condition bit
    Uint32 FREE:1;                            // 14 Debug Action
    Uint32 NACKMOD:1;                         // 15 NACK mode bit
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union I2CMDR_REG {
    Uint32  all;
    struct  I2CMDR_BITS  bit;
};

struct I2CISRC_BITS {                         // bits description
    Uint32 INTCODE:3;                         // 2:0 Interrupt code bits.
    Uint32 rsvd1:5;                           // 7:3 Reserved
    Uint32 WRITE_ZEROS:4;                     // 11:8 Always write all 0s to this field
    Uint32 rsvd2:20;                          // 31:12 Reserved
};

union I2CISRC_REG {
    Uint32  all;
    struct  I2CISRC_BITS  bit;
};

struct I2CEMDR_BITS {                         // bits description
    Uint32 BC:1;                              // 0 Backwards compatibility mode
    Uint32 FCM:1;                             // 1 Forward Compatibility for Tx behav in Type1
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union I2CEMDR_REG {
    Uint32  all;
    struct  I2CEMDR_BITS  bit;
};

struct I2CPSC_BITS {                          // bits description
    Uint32 IPSC:8;                            // 7:0 I2C Prescaler Divide Down
    Uint32 rsvd1:24;                          // 31:8 Reserved
};

union I2CPSC_REG {
    Uint32  all;
    struct  I2CPSC_BITS  bit;
};

struct I2CFFTX_BITS {                         // bits description
    Uint32 TXFFIL:5;                          // 4:0 Transmit FIFO Interrupt Level
    Uint32 TXFFIENA:1;                        // 5 Transmit FIFO Interrupt Enable
    Uint32 TXFFINTCLR:1;                      // 6 Transmit FIFO Interrupt Flag Clear
    Uint32 TXFFINT:1;                         // 7 Transmit FIFO Interrupt Flag
    Uint32 TXFFST:5;                          // 12:8 Transmit FIFO Status
    Uint32 TXFFRST:1;                         // 13 Transmit FIFO Reset
    Uint32 I2CFFEN:1;                         // 14 Transmit FIFO Enable
    Uint32 rsvd1:17;                          // 31:15 Reserved
};

union I2CFFTX_REG {
    Uint32  all;
    struct  I2CFFTX_BITS  bit;
};

struct I2CFFRX_BITS {                         // bits description
    Uint32 RXFFIL:5;                          // 4:0 Receive FIFO Interrupt Level
    Uint32 RXFFIENA:1;                        // 5 Receive FIFO Interrupt Enable
    Uint32 RXFFINTCLR:1;                      // 6 Receive FIFO Interrupt Flag Clear
    Uint32 RXFFINT:1;                         // 7 Receive FIFO Interrupt Flag
    Uint32 RXFFST:5;                          // 12:8 Receive FIFO Status
    Uint32 RXFFRST:1;                         // 13 Receive FIFO Reset
    Uint32 rsvd1:18;                          // 31:14 Reserved
};

union I2CFFRX_REG {
    Uint32  all;
    struct  I2CFFRX_BITS  bit;
};

struct  I2C_REGS {
    union   I2COAR_REG                       I2COAR;                      // 0x0 I2C Own address
    union   I2CIER_REG                       I2CIER;                      // 0x4 I2C Interrupt Enable
    union   I2CSTR_REG                       I2CSTR;                      // 0x8 I2C Status
    Uint32                                   I2CCLKL;                     // 0xc I2C Clock low-time divider
    Uint32                                   I2CCLKH;                     // 0x10 I2C Clock high-time divider
    Uint32                                   I2CCNT;                      // 0x14 I2C Data count
    union   I2CDRR_REG                       I2CDRR;                      // 0x18 I2C Data receive
    union   I2CSAR_REG                       I2CSAR;                      // 0x1c I2C Slave address
    union   I2CDXR_REG                       I2CDXR;                      // 0x20 I2C Data Transmit
    union   I2CMDR_REG                       I2CMDR;                      // 0x24 I2C Mode
    union   I2CISRC_REG                      I2CISRC;                     // 0x28 I2C Interrupt Source
    union   I2CEMDR_REG                      I2CEMDR;                     // 0x2c I2C Extended Mode
    union   I2CPSC_REG                       I2CPSC;                      // 0x30 I2C Prescaler
    union   I2CFFTX_REG                      I2CFFTX;                     // 0x34 I2C FIFO Transmit
    union   I2CFFRX_REG                      I2CFFRX;                     // 0x38 I2C FIFO Receive
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================