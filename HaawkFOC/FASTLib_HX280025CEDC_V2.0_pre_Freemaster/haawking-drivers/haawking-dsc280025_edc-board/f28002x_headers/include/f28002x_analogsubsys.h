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


#ifndef F28002X_ANALOGSUBSYS_H
#define F28002X_ANALOGSUBSYS_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ANALOGSUBSYS Individual Register Bit Definitions:

struct TSNSCTL_BITS {                         // bits description
    Uint32 ENABLE:1;                          // 0 Temperature Sensor Enable
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union TSNSCTL_REG {
    Uint32  all;
    struct  TSNSCTL_BITS  bit;
};

struct ANAREFCTL_BITS {                       // bits description
    Uint32 ANAREFSEL:1;                       // 0 ADCVREF_ADC input voltage Select
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 ANAREF2P5SEL:1;                    // 2 Control PGA magnification
    Uint32 rsvd2:4;                           // 6:3 Reserved
    Uint32 ANAREFASEL:1;                      // 7 Analog Reference A Select
    Uint32 rsvd3:7;                           // 14:8 Reserved
    Uint32 ANAREFCSEL:1;                      // 15 Analog Reference C Select
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union ANAREFCTL_REG {
    Uint32  all;
    struct  ANAREFCTL_BITS  bit;
};

struct VMONCTL_BITS {                         // bits description
    Uint32 BORLEVEL:3;                        // 2:0 BOR Trigger Point Voltage Bits
    Uint32 rsvd1:5;                           // 7:3 Reserved
    Uint32 BORLVMONDIS:1;                     // 8 Disable BORL(ow) feature on VDDIO
    Uint32 rsvd2:23;                          // 31:9 Reserved
};

union VMONCTL_REG {
    Uint32  all;
    struct  VMONCTL_BITS  bit;
};

struct CMPHPMXSEL_BITS {                      // bits description
    Uint32 CMP1HPMXSEL:3;                     // 2:0 CMP1HPMXSEL bits
    Uint32 CMP2HPMXSEL:3;                     // 5:3 CMP2HPMXSEL bits
    Uint32 CMP3HPMXSEL:3;                     // 8:6 CMP3HPMXSEL bits
    Uint32 CMP4HPMXSEL:3;                     // 11:9 CMP4HPMXSEL bits
    Uint32 rsvd1:3;                           // 14:12 Reserved
    Uint32 rsvd2:1;                           // 15 Reserved
    Uint32 rsvd3:3;                           // 18:16 Reserved
    Uint32 rsvd4:3;                           // 21:19 Reserved
    Uint32 rsvd5:10;                          // 31:22 Reserved
};

union CMPHPMXSEL_REG {
    Uint32  all;
    struct  CMPHPMXSEL_BITS  bit;
};

struct CMPLPMXSEL_BITS {                      // bits description
    Uint32 CMP1LPMXSEL:3;                     // 2:0 CMP1LPMXSEL bits
    Uint32 CMP2LPMXSEL:3;                     // 5:3 CMP2LPMXSEL bits
    Uint32 CMP3LPMXSEL:3;                     // 8:6 CMP3LPMXSEL bits
    Uint32 CMP4LPMXSEL:3;                     // 11:9 CMP4LPMXSEL bits
    Uint32 rsvd1:3;                           // 14:12 Reserved
    Uint32 rsvd2:1;                           // 15 Reserved
    Uint32 rsvd3:3;                           // 18:16 Reserved
    Uint32 rsvd4:3;                           // 21:19 Reserved
    Uint32 rsvd5:10;                          // 31:22 Reserved
};

union CMPLPMXSEL_REG {
    Uint32  all;
    struct  CMPLPMXSEL_BITS  bit;
};

struct CMPHNMXSEL_BITS {                      // bits description
    Uint32 CMP1HNMXSEL:1;                     // 0 CMP1HNMXSEL bits
    Uint32 CMP2HNMXSEL:1;                     // 1 CMP2HNMXSEL bits
    Uint32 CMP3HNMXSEL:1;                     // 2 CMP3HNMXSEL bits
    Uint32 CMP4HNMXSEL:1;                     // 3 CMP4HNMXSEL bits
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:25;                          // 31:7 Reserved
};

union CMPHNMXSEL_REG {
    Uint32  all;
    struct  CMPHNMXSEL_BITS  bit;
};

struct CMPLNMXSEL_BITS {                      // bits description
    Uint32 CMP1LNMXSEL:1;                     // 0 CMP1LNMXSEL bits
    Uint32 CMP2LNMXSEL:1;                     // 1 CMP2LNMXSEL bits
    Uint32 CMP3LNMXSEL:1;                     // 2 CMP3LNMXSEL bits
    Uint32 CMP4LNMXSEL:1;                     // 3 CMP4LNMXSEL bits
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 rsvd4:25;                          // 31:7 Reserved
};

union CMPLNMXSEL_REG {
    Uint32  all;
    struct  CMPLNMXSEL_BITS  bit;
};

struct ADCDACLOOPBACK_BITS {                  // bits description
    Uint32 ENLB2ADCA:1;                       // 0 Enable DACA loopback to ADCA
    Uint32 rsvd1:1;                           // 1 Reserved
    Uint32 ENLB2ADCC:1;                       // 2 Enable DACA loopback to ADCC
    Uint32 rsvd2:13;                          // 15:3 Reserved
    Uint32 KEY:16;                            // 31:16 Key to enable writes
};

union ADCDACLOOPBACK_REG {
    Uint32  all;
    struct  ADCDACLOOPBACK_BITS  bit;
};

struct LOCK_BITS {                            // bits description
    Uint32 TSNSCTL:1;                         // 0 TSNSCTL Register lock bit
    Uint32 ANAREFCTL:1;                       // 1 ANAREFCTL Register lock bit
    Uint32 VMONCTL:1;                         // 2 VMONCTL Register lock bit
    Uint32 rsvd1:1;                           // 3 Reserved
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 CMPHPMXSEL:1;                      // 5 CMPHPMXSEL Register lock bit
    Uint32 CMPLPMXSEL:1;                      // 6 CMPLPMXSEL Register lock bit
    Uint32 CMPHNMXSEL:1;                      // 7 CMPHNMXSEL Register lock bit
    Uint32 CMPLNMXSEL:1;                      // 8 CMPLNMXSEL Register lock bit
    Uint32 VREGCTL:1;                         // 9 VREGCTL Register lock bit
    Uint32 rsvd3:6;                           // 15:10 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union LOCK_REG {
    Uint32  all;
    struct  LOCK_BITS  bit;
};

struct  ANALOG_SUBSYS_REGS {
    union   TSNSCTL_REG                      TSNSCTL;                     // 0x0 Temperature Sensor Control Register
    union   ANAREFCTL_REG                    ANAREFCTL;                   // 0x4 Analog Reference Control Register
    union   VMONCTL_REG                      VMONCTL;                     // 0x8 Voltage Monitor Control Register
    union   CMPHPMXSEL_REG                   CMPHPMXSEL;                  // 0xc Bits to select one of the many sources on CopmHP inputs. Refer to Pimux diagram for details.
    union   CMPLPMXSEL_REG                   CMPLPMXSEL;                  // 0x10 Bits to select one of the many sources on CopmLP inputs. Refer to Pimux diagram for details.
    union   CMPHNMXSEL_REG                   CMPHNMXSEL;                  // 0x14 Bits to select one of the many sources on CopmHN inputs. Refer to Pimux diagram for details.
    union   CMPLNMXSEL_REG                   CMPLNMXSEL;                  // 0x18 Bits to select one of the many sources on CopmLN inputs. Refer to Pimux diagram for details.
    union   ADCDACLOOPBACK_REG               ADCDACLOOPBACK;              // 0x1c Enabble loopback from DAC to ADCs
    union   LOCK_REG                         LOCK;                        // 0x20 Lock Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
