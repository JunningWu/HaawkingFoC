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


#ifndef F28002X_NMIINTRUPT_H
#define F28002X_NMIINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// NMIINTRUPT Individual Register Bit Definitions:

struct NMICFG_BITS {                          // bits description
    Uint32 NMIE:1;                            // 0 Global NMI Enable
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union NMICFG_REG {
    Uint32  all;
    struct  NMICFG_BITS  bit;
};

struct NMIFLG_BITS {                          // bits description
    Uint32 NMIINT:1;                          // 0 NMI Interrupt Flag
    Uint32 CLOCKFAIL:1;                       // 1 Clock Fail Interrupt Flag
    Uint32 RAMUNCERR:1;                       // 2 RAM Uncorrectable Error NMI Flag
    Uint32 FLUNCERR:1;                        // 3 Flash Uncorrectable Error NMI Flag
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 SYSDBGNMI:1;                       // 7 System Debug Module NMI Flag
    Uint32 CLBNMI:1;                          // 8 Reconfigurable Logic NMI Flag
    Uint32 rsvd4:1;                           // 9 Reserved
    Uint32 rsvd5:1;                           // 10 Reserved
    Uint32 rsvd6:1;                           // 11 Reserved
    Uint32 rsvd7:1;                           // 12 Reserved
    Uint32 SWERR:1;                           // 13 SW Error Force NMI Flag
    Uint32 CRC_FAIL:1;                        // 14 BGCRC calculation failed.
    Uint32 rsvd8:17;                          // 31:15 Reserved
};

union NMIFLG_REG {
    Uint32  all;
    struct  NMIFLG_BITS  bit;
};

struct NMIFLGCLR_BITS {                       // bits description
    Uint32 NMIINT:1;                          // 0 NMIINT Flag Clear
    Uint32 CLOCKFAIL:1;                       // 1 CLOCKFAIL Flag Clear
    Uint32 RAMUNCERR:1;                       // 2 RAMUNCERR Flag Clear
    Uint32 FLUNCERR:1;                        // 3 FLUNCERR Flag Clear
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 rsvd2:1;                           // 5 Reserved
    Uint32 rsvd3:1;                           // 6 Reserved
    Uint32 SYSDBGNMI:1;                       // 7 SYSDBGNMI Flag Clear
    Uint32 CLBNMI:1;                          // 8 CLBNMI Flag Clear
    Uint32 rsvd4:1;                           // 9 Reserved
    Uint32 rsvd5:1;                           // 10 Reserved
    Uint32 rsvd6:1;                           // 11 Reserved
    Uint32 rsvd7:1;                           // 12 Reserved
    Uint32 SWERR:1;                           // 13 SW Error Flag Clear
    Uint32 CRC_FAIL:1;                        // 14 CRC_FAIL flag clear
    Uint32 rsvd8:17;                          // 31:15 Reserved
};

union NMIFLGCLR_REG {
    Uint32  all;
    struct  NMIFLGCLR_BITS  bit;
};

struct NMIFLGFRC_BITS {                       // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CLOCKFAIL:1;                       // 1 CLOCKFAIL Flag Force
    Uint32 RAMUNCERR:1;                       // 2 RAMUNCERR Flag Force
    Uint32 FLUNCERR:1;                        // 3 FLUNCERR Flag Force
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 SYSDBGNMI:1;                       // 7 SYSDBGNMI Flag Force
    Uint32 CLBNMI:1;                          // 8 CLBNMI Flag Force
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 rsvd6:1;                           // 10 Reserved
    Uint32 rsvd7:1;                           // 11 Reserved
    Uint32 rsvd8:1;                           // 12 Reserved
    Uint32 SWERR:1;                           // 13 SW Error Flag Force
    Uint32 CRC_FAIL:1;                        // 14 CRC_FAIL flag force
    Uint32 rsvd9:17;                          // 31:15 Reserved
};

union NMIFLGFRC_REG {
    Uint32  all;
    struct  NMIFLGFRC_BITS  bit;
};

struct NMISHDFLG_BITS {                       // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 CLOCKFAIL:1;                       // 1 Shadow CLOCKFAIL Flag
    Uint32 RAMUNCERR:1;                       // 2 Shadow RAMUNCERR Flag
    Uint32 FLUNCERR:1;                        // 3 Shadow FLUNCERR Flag
    Uint32 rsvd2:1;                           // 4 Reserved
    Uint32 rsvd3:1;                           // 5 Reserved
    Uint32 rsvd4:1;                           // 6 Reserved
    Uint32 SYSDBGNMI:1;                       // 7 Shadow SYSDBGNMI Flag
    Uint32 CLBNMI:1;                          // 8 Shadow CLBNMI Flag
    Uint32 rsvd5:1;                           // 9 Reserved
    Uint32 rsvd6:1;                           // 10 Reserved
    Uint32 rsvd7:1;                           // 11 Reserved
    Uint32 rsvd8:1;                           // 12 Reserved
    Uint32 SWERR:1;                           // 13 Shadow SW Error Flag
    Uint32 CRC_FAIL:1;                        // 14 CRC_FAIL flag
    Uint32 rsvd9:17;                          // 31:15 Reserved
};

union NMISHDFLG_REG {
    Uint32  all;
    struct  NMISHDFLG_BITS  bit;
};

struct ERRORSTS_BITS {                        // bits description
    Uint32 ERROR:1;                           // 0 Error flag.
    Uint32 PINSTS:1;                          // 1 Error pin status.
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union ERRORSTS_REG {
    Uint32  all;
    struct  ERRORSTS_BITS  bit;
};

struct ERRORSTSCLR_BITS {                     // bits description
    Uint32 ERROR:1;                           // 0 ERRORFLG.ERROR clear bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union ERRORSTSCLR_REG {
    Uint32  all;
    struct  ERRORSTSCLR_BITS  bit;
};

struct ERRORSTSFRC_BITS {                     // bits description
    Uint32 ERROR:1;                           // 0 ERRORSTS.ERROR pin force.
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union ERRORSTSFRC_REG {
    Uint32  all;
    struct  ERRORSTSFRC_BITS  bit;
};

struct ERRORCTL_BITS {                        // bits description
    Uint32 ERRORPOLSEL:1;                     // 0 ERROR pin polarity select
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union ERRORCTL_REG {
    Uint32  all;
    struct  ERRORCTL_BITS  bit;
};

struct ERRORLOCK_BITS {                       // bits description
    Uint32 ERRORCTL:1;                        // 0 ERRORCTL Lock bit
    Uint32 rsvd1:31;                          // 31:1 Reserved
};

union ERRORLOCK_REG {
    Uint32  all;
    struct  ERRORLOCK_BITS  bit;
};

struct  NMI_INTRUPT_REGS {
    union   NMICFG_REG                       NMICFG;                      // 0x0 NMI Configuration Register
    union   NMIFLG_REG                       NMIFLG;                      // 0x4 NMI Flag Register (SYSRsn Clear)
    union   NMIFLGCLR_REG                    NMIFLGCLR;                   // 0x8 NMI Flag Clear Register
    union   NMIFLGFRC_REG                    NMIFLGFRC;                   // 0xc NMI Flag Force Register
    Uint32                                   NMIWDCNT;                    // 0x10 NMI Watchdog Counter Register
    Uint32                                   NMIWDPRD;                    // 0x14 NMI Watchdog Period Register
    union   NMISHDFLG_REG                    NMISHDFLG;                   // 0x18 NMI Shadow Flag Register
    union   ERRORSTS_REG                     ERRORSTS;                    // 0x1c Error pin status
    union   ERRORSTSCLR_REG                  ERRORSTSCLR;                 // 0x20 ERRORSTS clear register
    union   ERRORSTSFRC_REG                  ERRORSTSFRC;                 // 0x24 ERRORSTS force register
    union   ERRORCTL_REG                     ERRORCTL;                    // 0x28 Error pin control register
    union   ERRORLOCK_REG                    ERRORLOCK;                   // 0x2c Lock register to Error pin registers.
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================