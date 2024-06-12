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


#ifndef F28002X_EPWM_XBAR_H
#define F28002X_EPWM_XBAR_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// EPWM_XBAR Individual Register Bit Definitions:

struct TRIP4MUX0TO15CFG_BITS {                // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP4 of EPWM-XBAR
};

union TRIP4MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP4MUX0TO15CFG_BITS  bit;
};

struct TRIP4MUX16TO31CFG_BITS {               // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP4 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP4 of EPWM-XBAR
};

union TRIP4MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP4MUX16TO31CFG_BITS  bit;
};

struct TRIP5MUX0TO15CFG_BITS {                // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP5 of EPWM-XBAR
};

union TRIP5MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP5MUX0TO15CFG_BITS  bit;
};

struct TRIP5MUX16TO31CFG_BITS {               // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP5 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP5 of EPWM-XBAR
};

union TRIP5MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP5MUX16TO31CFG_BITS  bit;
};

struct TRIP7MUX0TO15CFG_BITS {                // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP7 of EPWM-XBAR
};

union TRIP7MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP7MUX0TO15CFG_BITS  bit;
};

struct TRIP7MUX16TO31CFG_BITS {               // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP7 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP7 of EPWM-XBAR
};

union TRIP7MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP7MUX16TO31CFG_BITS  bit;
};

struct TRIP8MUX0TO15CFG_BITS {                // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP8 of EPWM-XBAR
};

union TRIP8MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP8MUX0TO15CFG_BITS  bit;
};

struct TRIP8MUX16TO31CFG_BITS {               // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP8 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP8 of EPWM-XBAR
};

union TRIP8MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP8MUX16TO31CFG_BITS  bit;
};

struct TRIP9MUX0TO15CFG_BITS {                // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP9 of EPWM-XBAR
};

union TRIP9MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP9MUX0TO15CFG_BITS  bit;
};

struct TRIP9MUX16TO31CFG_BITS {               // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP9 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP9 of EPWM-XBAR
};

union TRIP9MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP9MUX16TO31CFG_BITS  bit;
};

struct TRIP10MUX0TO15CFG_BITS {               // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP10 of EPWM-XBAR
};

union TRIP10MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP10MUX0TO15CFG_BITS  bit;
};

struct TRIP10MUX16TO31CFG_BITS {              // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP10 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP10 of EPWM-XBAR
};

union TRIP10MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP10MUX16TO31CFG_BITS  bit;
};

struct TRIP11MUX0TO15CFG_BITS {               // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP11 of EPWM-XBAR
};

union TRIP11MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP11MUX0TO15CFG_BITS  bit;
};

struct TRIP11MUX16TO31CFG_BITS {              // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP11 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP11 of EPWM-XBAR
};

union TRIP11MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP11MUX16TO31CFG_BITS  bit;
};

struct TRIP12MUX0TO15CFG_BITS {               // bits description
    Uint32 MUX0:2;                            // 1:0 Mux0 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX1:2;                            // 3:2 Mux1 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX2:2;                            // 5:4 Mux2 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX3:2;                            // 7:6 Mux3 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX4:2;                            // 9:8 Mux4 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX5:2;                            // 11:10 Mux5 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX6:2;                            // 13:12 Mux6 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX7:2;                            // 15:14 Mux7 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX8:2;                            // 17:16 Mux8 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX9:2;                            // 19:18 Mux9 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX10:2;                           // 21:20 Mux10 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX11:2;                           // 23:22 Mux11 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX12:2;                           // 25:24 Mux12 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX13:2;                           // 27:26 Mux13 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX14:2;                           // 29:28 Mux14 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX15:2;                           // 31:30 Mux15 Configuration for TRIP12 of EPWM-XBAR
};

union TRIP12MUX0TO15CFG_REG {
    Uint32  all;
    struct  TRIP12MUX0TO15CFG_BITS  bit;
};

struct TRIP12MUX16TO31CFG_BITS {              // bits description
    Uint32 MUX16:2;                           // 1:0 Mux16 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX17:2;                           // 3:2 Mux17 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX18:2;                           // 5:4 Mux18 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX19:2;                           // 7:6 Mux19 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX20:2;                           // 9:8 Mux20 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX21:2;                           // 11:10 Mux21 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX22:2;                           // 13:12 Mux22 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX23:2;                           // 15:14 Mux23 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX24:2;                           // 17:16 Mux24 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX25:2;                           // 19:18 Mux25 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX26:2;                           // 21:20 Mux26 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX27:2;                           // 23:22 Mux27 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX28:2;                           // 25:24 Mux28 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX29:2;                           // 27:26 Mux29 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX30:2;                           // 29:28 Mux30 Configuration for TRIP12 of EPWM-XBAR
    Uint32 MUX31:2;                           // 31:30 Mux31 Configuration for TRIP12 of EPWM-XBAR
};

union TRIP12MUX16TO31CFG_REG {
    Uint32  all;
    struct  TRIP12MUX16TO31CFG_BITS  bit;
};

struct TRIP4MUXENABLE_BITS {                  // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP4 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP4 of EPWM-XBAR
};

union TRIP4MUXENABLE_REG {
    Uint32  all;
    struct  TRIP4MUXENABLE_BITS  bit;
};

struct TRIP5MUXENABLE_BITS {                  // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP5 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP5 of EPWM-XBAR
};

union TRIP5MUXENABLE_REG {
    Uint32  all;
    struct  TRIP5MUXENABLE_BITS  bit;
};

struct TRIP7MUXENABLE_BITS {                  // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP7 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP7 of EPWM-XBAR
};

union TRIP7MUXENABLE_REG {
    Uint32  all;
    struct  TRIP7MUXENABLE_BITS  bit;
};

struct TRIP8MUXENABLE_BITS {                  // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP8 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP8 of EPWM-XBAR
};

union TRIP8MUXENABLE_REG {
    Uint32  all;
    struct  TRIP8MUXENABLE_BITS  bit;
};

struct TRIP9MUXENABLE_BITS {                  // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP9 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP9 of EPWM-XBAR
};

union TRIP9MUXENABLE_REG {
    Uint32  all;
    struct  TRIP9MUXENABLE_BITS  bit;
};

struct TRIP10MUXENABLE_BITS {                 // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP10 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP10 of EPWM-XBAR
};

union TRIP10MUXENABLE_REG {
    Uint32  all;
    struct  TRIP10MUXENABLE_BITS  bit;
};

struct TRIP11MUXENABLE_BITS {                 // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP11 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP11 of EPWM-XBAR
};

union TRIP11MUXENABLE_REG {
    Uint32  all;
    struct  TRIP11MUXENABLE_BITS  bit;
};

struct TRIP12MUXENABLE_BITS {                 // bits description
    Uint32 MUX0:1;                            // 0 mux0 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX1:1;                            // 1 Mux1 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX2:1;                            // 2 Mux2 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX3:1;                            // 3 Mux3 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX4:1;                            // 4 Mux4 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX5:1;                            // 5 Mux5 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX6:1;                            // 6 Mux6 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX7:1;                            // 7 Mux7 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX8:1;                            // 8 Mux8 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX9:1;                            // 9 Mux9 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX10:1;                           // 10 Mux10 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX11:1;                           // 11 Mux11 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX12:1;                           // 12 Mux12 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX13:1;                           // 13 Mux13 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX14:1;                           // 14 Mux14 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX15:1;                           // 15 Mux15 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX16:1;                           // 16 Mux16 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX17:1;                           // 17 Mux17 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX18:1;                           // 18 Mux18 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX19:1;                           // 19 Mux19 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX20:1;                           // 20 Mux20 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX21:1;                           // 21 Mux21 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX22:1;                           // 22 Mux22 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX23:1;                           // 23 Mux23 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX24:1;                           // 24 Mux24 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX25:1;                           // 25 Mux25 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX26:1;                           // 26 Mux26 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX27:1;                           // 27 Mux27 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX28:1;                           // 28 Mux28 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX29:1;                           // 29 Mux29 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX30:1;                           // 30 Mux30 to drive TRIP12 of EPWM-XBAR
    Uint32 MUX31:1;                           // 31 Mux31 to drive TRIP12 of EPWM-XBAR
};

union TRIP12MUXENABLE_REG {
    Uint32  all;
    struct  TRIP12MUXENABLE_BITS  bit;
};

struct TRIPOUTINV_BITS {                      // bits description
    Uint32 TRIP4:1;                           // 0 Selects polarity for TRIP4 of EPWM-XBAR
    Uint32 TRIP5:1;                           // 1 Selects polarity for TRIP5 of EPWM-XBAR
    Uint32 TRIP7:1;                           // 2 Selects polarity for TRIP7 of EPWM-XBAR
    Uint32 TRIP8:1;                           // 3 Selects polarity for TRIP8 of EPWM-XBAR
    Uint32 TRIP9:1;                           // 4 Selects polarity for TRIP9 of EPWM-XBAR
    Uint32 TRIP10:1;                          // 5 Selects polarity for TRIP10 of EPWM-XBAR
    Uint32 TRIP11:1;                          // 6 Selects polarity for TRIP11 of EPWM-XBAR
    Uint32 TRIP12:1;                          // 7 Selects polarity for TRIP12 of EPWM-XBAR
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union TRIPOUTINV_REG {
    Uint32  all;
    struct  TRIPOUTINV_BITS  bit;
};

struct TRIPLOCK_BITS {                        // bits description
    Uint32 LOCK:1;                            // 0 Locks the configuration for EPWM-XBAR
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 KEY:16;                            // 31:16 Write protection KEY
};

union TRIPLOCK_REG {
    Uint32  all;
    struct  TRIPLOCK_BITS  bit;
};

struct  EPWM_XBAR_REGS {
    union   TRIP4MUX0TO15CFG_REG             TRIP4MUX0TO15CFG;            // 0x0 ePWM XBAR Mux Configuration for TRIP4
    union   TRIP4MUX16TO31CFG_REG            TRIP4MUX16TO31CFG;           // 0x4 ePWM XBAR Mux Configuration for TRIP4
    union   TRIP5MUX0TO15CFG_REG             TRIP5MUX0TO15CFG;            // 0x8 ePWM XBAR Mux Configuration for TRIP5
    union   TRIP5MUX16TO31CFG_REG            TRIP5MUX16TO31CFG;           // 0xc ePWM XBAR Mux Configuration for TRIP5
    union   TRIP7MUX0TO15CFG_REG             TRIP7MUX0TO15CFG;            // 0x10 ePWM XBAR Mux Configuration for TRIP7
    union   TRIP7MUX16TO31CFG_REG            TRIP7MUX16TO31CFG;           // 0x14 ePWM XBAR Mux Configuration for TRIP7
    union   TRIP8MUX0TO15CFG_REG             TRIP8MUX0TO15CFG;            // 0x18 ePWM XBAR Mux Configuration for TRIP8
    union   TRIP8MUX16TO31CFG_REG            TRIP8MUX16TO31CFG;           // 0x1c ePWM XBAR Mux Configuration for TRIP8
    union   TRIP9MUX0TO15CFG_REG             TRIP9MUX0TO15CFG;            // 0x20 ePWM XBAR Mux Configuration for TRIP9
    union   TRIP9MUX16TO31CFG_REG            TRIP9MUX16TO31CFG;           // 0x24 ePWM XBAR Mux Configuration for TRIP9
    union   TRIP10MUX0TO15CFG_REG            TRIP10MUX0TO15CFG;           // 0x28 ePWM XBAR Mux Configuration for TRIP10
    union   TRIP10MUX16TO31CFG_REG           TRIP10MUX16TO31CFG;          // 0x2c ePWM XBAR Mux Configuration for TRIP10
    union   TRIP11MUX0TO15CFG_REG            TRIP11MUX0TO15CFG;           // 0x30 ePWM XBAR Mux Configuration for TRIP11
    union   TRIP11MUX16TO31CFG_REG           TRIP11MUX16TO31CFG;          // 0x34 ePWM XBAR Mux Configuration for TRIP11
    union   TRIP12MUX0TO15CFG_REG            TRIP12MUX0TO15CFG;           // 0x38 ePWM XBAR Mux Configuration for TRIP12
    union   TRIP12MUX16TO31CFG_REG           TRIP12MUX16TO31CFG;          // 0x3c ePWM XBAR Mux Configuration for TRIP12
    union   TRIP4MUXENABLE_REG               TRIP4MUXENABLE;              // 0x40 ePWM XBAR Mux Enable for TRIP4
    union   TRIP5MUXENABLE_REG               TRIP5MUXENABLE;              // 0x44 ePWM XBAR Mux Enable for TRIP5
    union   TRIP7MUXENABLE_REG               TRIP7MUXENABLE;              // 0x48 ePWM XBAR Mux Enable for TRIP7
    union   TRIP8MUXENABLE_REG               TRIP8MUXENABLE;              // 0x4c ePWM XBAR Mux Enable for TRIP8
    union   TRIP9MUXENABLE_REG               TRIP9MUXENABLE;              // 0x50 ePWM XBAR Mux Enable for TRIP9
    union   TRIP10MUXENABLE_REG              TRIP10MUXENABLE;             // 0x54 ePWM XBAR Mux Enable for TRIP10
    union   TRIP11MUXENABLE_REG              TRIP11MUXENABLE;             // 0x58 ePWM XBAR Mux Enable for TRIP11
    union   TRIP12MUXENABLE_REG              TRIP12MUXENABLE;             // 0x5c ePWM XBAR Mux Enable for TRIP12
    Uint32                                   rsvd1[4];                    // 0x60 Reserved
    union   TRIPOUTINV_REG                   TRIPOUTINV;                  // 0x70 ePWM XBAR Output Inversion Register
    union   TRIPLOCK_REG                     TRIPLOCK;                    // 0x74 ePWM XBAR Configuration Lock register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================