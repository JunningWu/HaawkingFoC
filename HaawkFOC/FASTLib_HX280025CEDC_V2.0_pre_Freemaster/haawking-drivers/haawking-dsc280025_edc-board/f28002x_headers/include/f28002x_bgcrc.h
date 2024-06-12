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


#ifndef F28002X_BGCRC_H
#define F28002X_BGCRC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// BGCRC Individual Register Bit Definitions:

struct BGCRC_EN_BITS {                        // bits description
    Uint32 START:4;                           // 3:0 Start Bit used to Kick-off CRC calculations
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:15;                          // 30:16 Reserved
    Uint32 RUN_STS:1;                         // 31 CRC module activity monitor
};

union BGCRC_EN_REG {
    Uint32  all;
    struct  BGCRC_EN_BITS  bit;
};

struct BGCRC_CTRL1_BITS {                     // bits description
    Uint32 rsvd1:4;                           // 3:0 Reserved
    Uint32 FREE_SOFT:1;                       // 4 emulation control bit
    Uint32 rsvd2:11;                          // 15:5 Reserved
    Uint32 NMIDIS:4;                          // 19:16 NMI disable configuration
    Uint32 rsvd3:12;                          // 31:20 Reserved
};

union BGCRC_CTRL1_REG {
    Uint32  all;
    struct  BGCRC_CTRL1_BITS  bit;
};

struct BGCRC_CTRL2_BITS {                     // bits description
    Uint32 BLOCK_SIZE:10;                     // 9:0 block size for memory check
    Uint32 rsvd1:2;                           // 11:10 Reserved
    Uint32 TEST_HALT:4;                       // 15:12 TEST_HALT configuration
    Uint32 SCRUB_MODE:4;                      // 19:16 Scrub mode configuration
    Uint32 rsvd2:12;                          // 31:20 Reserved
};

union BGCRC_CTRL2_REG {
    Uint32  all;
    struct  BGCRC_CTRL2_BITS  bit;
};

struct BGCRC_WD_CFG_BITS {                    // bits description
    Uint32 WDDIS:4;                           // 3:0 CRC Watchdog disable
    Uint32 rsvd1:12;                          // 15:4 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union BGCRC_WD_CFG_REG {
    Uint32  all;
    struct  BGCRC_WD_CFG_BITS  bit;
};

struct BGCRC_NMIFLG_BITS {                    // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 CRC_FAIL:1;                        // 2 CRC computation failed
    Uint32 UNCORRECTABLE_ERR:1;               // 3 Uncorrectable error obtained during memory data read.
    Uint32 CORRECTABLE_ERR:1;                 // 4 Correctable ECC error obtained during memory data read.
    Uint32 WD_UNDERFLOW:1;                    // 5 CRC/scrubbing completed before BGCRC_WD_MIN
    Uint32 WD_OVERFLOW:1;                     // 6 CRC/scrubbing did not complete within BGCRC_WD_MAX
    Uint32 rsvd3:9;                           // 15:7 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union BGCRC_NMIFLG_REG {
    Uint32  all;
    struct  BGCRC_NMIFLG_BITS  bit;
};

struct BGCRC_NMICLR_BITS {                    // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 CRC_FAIL:1;                        // 2 CRC_FAIL NMI flag clear
    Uint32 UNCORRECTABLE_ERR:1;               // 3 UNCORRECTABLE_ERR NMI flag clear
    Uint32 CORRECTABLE_ERR:1;                 // 4 CORRECTABLE_ERR NMI flag clear
    Uint32 WD_UNDERFLOW:1;                    // 5 WD_UNDERFLOW NMI flag clear
    Uint32 WD_OVERFLOW:1;                     // 6 WD_OVERFLOW NMI flag clear
    Uint32 rsvd3:9;                           // 15:7 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union BGCRC_NMICLR_REG {
    Uint32  all;
    struct  BGCRC_NMICLR_BITS  bit;
};

struct BGCRC_NMIFRC_BITS {                    // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 rsvd2:1;                           // 1 Reserved
    Uint32 CRC_FAIL:1;                        // 2 CRC_FAIL NMI force
    Uint32 UNCORRECTABLE_ERR:1;               // 3 UNCORRECTABLE_ERR NMI force
    Uint32 CORRECTABLE_ERR:1;                 // 4 CORRECTABLE_ERR NMI force
    Uint32 WD_UNDERFLOW:1;                    // 5 WD_UNDERFLOW NMI force
    Uint32 WD_OVERFLOW:1;                     // 6 WD_OVERFLOW NMI force
    Uint32 rsvd3:9;                           // 15:7 Reserved
    Uint32 rsvd4:16;                          // 31:16 Reserved
};

union BGCRC_NMIFRC_REG {
    Uint32  all;
    struct  BGCRC_NMIFRC_BITS  bit;
};

struct BGCRC_INTEN_BITS {                     // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 TEST_DONE:1;                       // 1 TEST_DONE interrupt enable register
    Uint32 CRC_FAIL:1;                        // 2 CRC_FAIL interrupt enable register
    Uint32 UNCORRECTABLE_ERR:1;               // 3 UNCORRECTABLE_ERR interrupt enable register
    Uint32 CORRECTABLE_ERR:1;                 // 4 CORRECTABLE_ERR interrupt enable register
    Uint32 WD_UNDERFLOW:1;                    // 5 WD_UNDERFLOW interrupt enable register
    Uint32 WD_OVERFLOW:1;                     // 6 WD_OVERFLOW interrupt enable register
    Uint32 rsvd2:9;                           // 15:7 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union BGCRC_INTEN_REG {
    Uint32  all;
    struct  BGCRC_INTEN_BITS  bit;
};

struct BGCRC_INTFLG_BITS {                    // bits description
    Uint32 INT:1;                             // 0 Global Interrupt status flag
    Uint32 TEST_DONE:1;                       // 1 TEST_DONE Interrupt status flag
    Uint32 CRC_FAIL:1;                        // 2 CRC computation failed
    Uint32 UNCORRECTABLE_ERR:1;               // 3 Uncorrectable error obtained during memory data read.
    Uint32 CORRECTABLE_ERR:1;                 // 4 Correctable ECC error obtained during memory data read.
    Uint32 WD_UNDERFLOW:1;                    // 5 CRC/scrubbing completed before BGCRC_WD_MIN
    Uint32 WD_OVERFLOW:1;                     // 6 CRC/scrubbing did not complete within BGCRC_WD_MAX
    Uint32 rsvd1:9;                           // 15:7 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union BGCRC_INTFLG_REG {
    Uint32  all;
    struct  BGCRC_INTFLG_BITS  bit;
};

struct BGCRC_INTCLR_BITS {                    // bits description
    Uint32 INT:1;                             // 0 Global Interrupt clear
    Uint32 TEST_DONE:1;                       // 1 TEST_DONE Interrupt clear
    Uint32 CRC_FAIL:1;                        // 2 CRC_FAIL interrupt clear
    Uint32 UNCORRECTABLE_ERR:1;               // 3 UNCORRECTABLE_ERR interrupt clear
    Uint32 CORRECTABLE_ERR:1;                 // 4 CORRECTABLE_ERR interrupt clear
    Uint32 WD_UNDERFLOW:1;                    // 5 WD_UNDERFLOW interrupt clear
    Uint32 WD_OVERFLOW:1;                     // 6 WD_OVERFLOW interrupt clear
    Uint32 rsvd1:9;                           // 15:7 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union BGCRC_INTCLR_REG {
    Uint32  all;
    struct  BGCRC_INTCLR_BITS  bit;
};

struct BGCRC_INTFRC_BITS {                    // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 TEST_DONE:1;                       // 1 TEST_DONE Interrupt force
    Uint32 CRC_FAIL:1;                        // 2 CRC_FAIL interrupt force
    Uint32 UNCORRECTABLE_ERR:1;               // 3 UNCORRECTABLE_ERR interrupt force
    Uint32 CORRECTABLE_ERR:1;                 // 4 CORRECTABLE_ERR interrupt force
    Uint32 WD_UNDERFLOW:1;                    // 5 WD_UNDERFLOW interrupt force
    Uint32 WD_OVERFLOW:1;                     // 6 WD_OVERFLOW interrupt force
    Uint32 rsvd2:9;                           // 15:7 Reserved
    Uint32 rsvd3:16;                          // 31:16 Reserved
};

union BGCRC_INTFRC_REG {
    Uint32  all;
    struct  BGCRC_INTFRC_BITS  bit;
};

struct BGCRC_LOCK_BITS {                      // bits description
    Uint32 BGCRC_EN:1;                        // 0 Register lock configuration
    Uint32 BGCRC_CTRL1:1;                     // 1 Register lock configuration
    Uint32 BGCRC_CTRL2:1;                     // 2 Register lock configuration
    Uint32 BGCRC_START_ADDR:1;                // 3 Register lock configuration
    Uint32 BGCRC_SEED:1;                      // 4 Register lock configuration
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 rsvd2:1;                           // 6 Reserved
    Uint32 BGCRC_GOLDEN:1;                    // 7 Register lock configuration
    Uint32 rsvd3:1;                           // 8 Reserved
    Uint32 rsvd4:1;                           // 9 Reserved
    Uint32 rsvd5:1;                           // 10 Reserved
    Uint32 rsvd6:1;                           // 11 Reserved
    Uint32 rsvd7:1;                           // 12 Reserved
    Uint32 rsvd8:1;                           // 13 Reserved
    Uint32 BGCRC_WD_CFG:1;                    // 14 Register lock configuration
    Uint32 BGCRC_WD_MIN:1;                    // 15 Register lock configuration
    Uint32 BGCRC_WD_MAX:1;                    // 16 Register lock configuration
    Uint32 rsvd9:1;                           // 17 Reserved
    Uint32 rsvd10:1;                          // 18 Reserved
    Uint32 rsvd11:1;                          // 19 Reserved
    Uint32 rsvd12:1;                          // 20 Reserved
    Uint32 rsvd13:1;                          // 21 Reserved
    Uint32 rsvd14:1;                          // 22 Reserved
    Uint32 BGCRC_NMIFRC:1;                    // 23 Register lock configuration
    Uint32 rsvd15:1;                          // 24 Reserved
    Uint32 rsvd16:1;                          // 25 Reserved
    Uint32 BGCRC_INTEN:1;                     // 26 Register lock configuration
    Uint32 rsvd17:1;                          // 27 Reserved
    Uint32 rsvd18:1;                          // 28 Reserved
    Uint32 BGCRC_INTFRC:1;                    // 29 Register lock configuration
    Uint32 rsvd19:1;                          // 30 Reserved
    Uint32 rsvd20:1;                          // 31 Reserved
};

union BGCRC_LOCK_REG {
    Uint32  all;
    struct  BGCRC_LOCK_BITS  bit;
};

struct BGCRC_COMMIT_BITS {                    // bits description
    Uint32 BGCRC_EN:1;                        // 0 Register lock committed
    Uint32 BGCRC_CTRL1:1;                     // 1 Register lock committed
    Uint32 BGCRC_CTRL2:1;                     // 2 Register lock committed
    Uint32 BGCRC_START_ADDR:1;                // 3 Register lock committed
    Uint32 BGCRC_SEED:1;                      // 4 Register lock committed
    Uint32 rsvd1:1;                           // 5 Reserved
    Uint32 rsvd2:1;                           // 6 Reserved
    Uint32 BGCRC_GOLDEN:1;                    // 7 Register lock committed
    Uint32 rsvd3:1;                           // 8 Reserved
    Uint32 rsvd4:1;                           // 9 Reserved
    Uint32 rsvd5:1;                           // 10 Reserved
    Uint32 rsvd6:1;                           // 11 Reserved
    Uint32 rsvd7:1;                           // 12 Reserved
    Uint32 rsvd8:1;                           // 13 Reserved
    Uint32 BGCRC_WD_CFG:1;                    // 14 Register lock committed
    Uint32 BGCRC_WD_MIN:1;                    // 15 Register lock committed
    Uint32 BGCRC_WD_MAX:1;                    // 16 Register lock committed
    Uint32 rsvd9:1;                           // 17 Reserved
    Uint32 rsvd10:1;                          // 18 Reserved
    Uint32 rsvd11:1;                          // 19 Reserved
    Uint32 rsvd12:1;                          // 20 Reserved
    Uint32 rsvd13:1;                          // 21 Reserved
    Uint32 rsvd14:1;                          // 22 Reserved
    Uint32 BGCRC_NMIFRC:1;                    // 23 Register lock committed
    Uint32 rsvd15:1;                          // 24 Reserved
    Uint32 rsvd16:1;                          // 25 Reserved
    Uint32 BGCRC_INTEN:1;                     // 26 Register lock committed
    Uint32 rsvd17:1;                          // 27 Reserved
    Uint32 rsvd18:1;                          // 28 Reserved
    Uint32 BGCRC_INTFRC:1;                    // 29 Register lock committed
    Uint32 rsvd19:1;                          // 30 Reserved
    Uint32 rsvd20:1;                          // 31 Reserved
};

union BGCRC_COMMIT_REG {
    Uint32  all;
    struct  BGCRC_COMMIT_BITS  bit;
};

struct  BGCRC_REGS {
    union   BGCRC_EN_REG                     BGCRC_EN;                    // 0x0 BGCRC Enable
    union   BGCRC_CTRL1_REG                  BGCRC_CTRL1;                 // 0x4 BGCRC Control register 1
    union   BGCRC_CTRL2_REG                  BGCRC_CTRL2;                 // 0x8 BGCRC Control register 2
    Uint32                                   BGCRC_START_ADDR;            // 0xc Start address for the BGCRC check
    Uint32                                   BGCRC_SEED;                  // 0x10 Seed for CRC calculation
    Uint32                                   rsvd1[2];                    // 0x14 Reserved
    Uint32                                   BGCRC_GOLDEN;                // 0x1c Golden CRC to be compared against
    Uint32                                   BGCRC_RESULT;                // 0x20 CRC calculated
    Uint32                                   BGCRC_CURR_ADDR;             // 0x24 Current address regsiter
    Uint32                                   rsvd2[4];                    // 0x28 Reserved
    union   BGCRC_WD_CFG_REG                 BGCRC_WD_CFG;                // 0x38 BGCRC windowed watchdog configuration
    Uint32                                   BGCRC_WD_MIN;                // 0x3c BGCRC windowed watchdog min value
    Uint32                                   BGCRC_WD_MAX;                // 0x40 BGCRC windowed watchdog max value
    Uint32                                   BGCRC_WD_CNT;                // 0x44 BGCRC windowed watchdog count
    Uint32                                   rsvd3[3];                    // 0x48 Reserved
    union   BGCRC_NMIFLG_REG                 BGCRC_NMIFLG;                // 0x54 BGCRC NMI flag register
    union   BGCRC_NMICLR_REG                 BGCRC_NMICLR;                // 0x58 BGCRC NMI flag clear register
    union   BGCRC_NMIFRC_REG                 BGCRC_NMIFRC;                // 0x5c BGCRC NMI flag force register
    Uint32                                   rsvd4[2];                    // 0x60 Reserved
    union   BGCRC_INTEN_REG                  BGCRC_INTEN;                 // 0x68 Interrupt enable
    union   BGCRC_INTFLG_REG                 BGCRC_INTFLG;                // 0x6c Interrupt flag
    union   BGCRC_INTCLR_REG                 BGCRC_INTCLR;                // 0x70 Interrupt flag clear
    union   BGCRC_INTFRC_REG                 BGCRC_INTFRC;                // 0x74 Interrupt flag force
    union   BGCRC_LOCK_REG                   BGCRC_LOCK;                  // 0x78 BGCRC register map lockconfiguration
    union   BGCRC_COMMIT_REG                 BGCRC_COMMIT;                // 0x7c BGCRC register map commit configuration
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================