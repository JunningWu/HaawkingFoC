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


#ifndef F28002X_CLB_H
#define F28002X_CLB_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CLB Individual Register Bit Definitions:

struct CLB_COUNT_RESET_BITS {                 // bits description
    Uint32 SEL_0:5;                           // 4:0 Count Reset Select 0
    Uint32 SEL_1:5;                           // 9:5 Count Reset Select 1
    Uint32 SEL_2:5;                           // 14:10 Count Reset Select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_COUNT_RESET_REG {
    Uint32  all;
    struct  CLB_COUNT_RESET_BITS  bit;
};

struct CLB_COUNT_MODE_1_BITS {                // bits description
    Uint32 SEL_0:5;                           // 4:0 Counter mode 1 select 0
    Uint32 SEL_1:5;                           // 9:5 Counter mode 1 select 1
    Uint32 SEL_2:5;                           // 14:10 Counter mode 1 select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_COUNT_MODE_1_REG {
    Uint32  all;
    struct  CLB_COUNT_MODE_1_BITS  bit;
};

struct CLB_COUNT_MODE_0_BITS {                // bits description
    Uint32 SEL_0:5;                           // 4:0 Counter mode 0 select 0
    Uint32 SEL_1:5;                           // 9:5 Counter mode 0 select 1
    Uint32 SEL_2:5;                           // 14:10 Counter mode 0 select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_COUNT_MODE_0_REG {
    Uint32  all;
    struct  CLB_COUNT_MODE_0_BITS  bit;
};

struct CLB_COUNT_EVENT_BITS {                 // bits description
    Uint32 SEL_0:5;                           // 4:0 Counter event select 0
    Uint32 SEL_1:5;                           // 9:5 Counter event select 1
    Uint32 SEL_2:5;                           // 14:10 Counter event select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_COUNT_EVENT_REG {
    Uint32  all;
    struct  CLB_COUNT_EVENT_BITS  bit;
};

struct CLB_FSM_EXTRA_IN0_BITS {               // bits description
    Uint32 SEL_0:5;                           // 4:0 FSM extra ext input select 0
    Uint32 SEL_1:5;                           // 9:5 FSM extra ext input select 1
    Uint32 SEL_2:5;                           // 14:10 FSM extra ext input select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_FSM_EXTRA_IN0_REG {
    Uint32  all;
    struct  CLB_FSM_EXTRA_IN0_BITS  bit;
};

struct CLB_FSM_EXTERNAL_IN0_BITS {            // bits description
    Uint32 SEL_0:5;                           // 4:0 FSM EXT_IN0 select input for unit 0
    Uint32 SEL_1:5;                           // 9:5 FSM EXT_IN0 select input for unit 1
    Uint32 SEL_2:5;                           // 14:10 FSM EXT_IN0 select input for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_FSM_EXTERNAL_IN0_REG {
    Uint32  all;
    struct  CLB_FSM_EXTERNAL_IN0_BITS  bit;
};

struct CLB_FSM_EXTERNAL_IN1_BITS {            // bits description
    Uint32 SEL_0:5;                           // 4:0 FSM EXT_IN1 select input for unit 0
    Uint32 SEL_1:5;                           // 9:5 FSM EXT_IN1 select input for unit 1
    Uint32 SEL_2:5;                           // 14:10 FSM EXT_IN1 select input for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_FSM_EXTERNAL_IN1_REG {
    Uint32  all;
    struct  CLB_FSM_EXTERNAL_IN1_BITS  bit;
};

struct CLB_FSM_EXTRA_IN1_BITS {               // bits description
    Uint32 SEL_0:5;                           // 4:0 FSM extra ext input select 0
    Uint32 SEL_1:5;                           // 9:5 FSM extra ext input select 1
    Uint32 SEL_2:5;                           // 14:10 FSM extra ext input select 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_FSM_EXTRA_IN1_REG {
    Uint32  all;
    struct  CLB_FSM_EXTRA_IN1_BITS  bit;
};

struct CLB_LUT4_IN0_BITS {                    // bits description
    Uint32 SEL_0:5;                           // 4:0 Select inputs for unit 0
    Uint32 SEL_1:5;                           // 9:5 Select inputs for unit 1
    Uint32 SEL_2:5;                           // 14:10 Select inputs for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_LUT4_IN0_REG {
    Uint32  all;
    struct  CLB_LUT4_IN0_BITS  bit;
};

struct CLB_LUT4_IN1_BITS {                    // bits description
    Uint32 SEL_0:5;                           // 4:0 Select inputs for unit 0
    Uint32 SEL_1:5;                           // 9:5 Select inputs for unit 1
    Uint32 SEL_2:5;                           // 14:10 Select inputs for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_LUT4_IN1_REG {
    Uint32  all;
    struct  CLB_LUT4_IN1_BITS  bit;
};

struct CLB_LUT4_IN2_BITS {                    // bits description
    Uint32 SEL_0:5;                           // 4:0 Select inputs for unit 0
    Uint32 SEL_1:5;                           // 9:5 Select inputs for unit 1
    Uint32 SEL_2:5;                           // 14:10 Select inputs for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_LUT4_IN2_REG {
    Uint32  all;
    struct  CLB_LUT4_IN2_BITS  bit;
};

struct CLB_LUT4_IN3_BITS {                    // bits description
    Uint32 SEL_0:5;                           // 4:0 Select inputs for unit 0
    Uint32 SEL_1:5;                           // 9:5 Select inputs for unit 1
    Uint32 SEL_2:5;                           // 14:10 Select inputs for unit 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_LUT4_IN3_REG {
    Uint32  all;
    struct  CLB_LUT4_IN3_BITS  bit;
};

struct CLB_FSM_LUT_FN1_0_BITS {               // bits description
    Uint32 FN0:16;                            // 15:0 FSM LUT output function for unit 0
    Uint32 FN1:16;                            // 31:16 FSM LUT output function for unit 1
};

union CLB_FSM_LUT_FN1_0_REG {
    Uint32  all;
    struct  CLB_FSM_LUT_FN1_0_BITS  bit;
};

struct CLB_FSM_LUT_FN2_BITS {                 // bits description
    Uint32 FN1:16;                            // 15:0 FSM LUT output function for unit 2
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CLB_FSM_LUT_FN2_REG {
    Uint32  all;
    struct  CLB_FSM_LUT_FN2_BITS  bit;
};

struct CLB_LUT4_FN1_0_BITS {                  // bits description
    Uint32 FN0:16;                            // 15:0 LUT4 output function for unit 0
    Uint32 FN1:16;                            // 31:16 LUT4 output function for unit 1
};

union CLB_LUT4_FN1_0_REG {
    Uint32  all;
    struct  CLB_LUT4_FN1_0_BITS  bit;
};

struct CLB_LUT4_FN2_BITS {                    // bits description
    Uint32 FN1:16;                            // 15:0 LUT4 output function for unit 2
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CLB_LUT4_FN2_REG {
    Uint32  all;
    struct  CLB_LUT4_FN2_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_0_BITS {            // bits description
    Uint32 S0:16;                             // 15:0 FSM next state function for S0
    Uint32 S1:16;                             // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_0_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_0_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_1_BITS {            // bits description
    Uint32 S0:16;                             // 15:0 FSM next state function for S0
    Uint32 S1:16;                             // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_1_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_1_BITS  bit;
};

struct CLB_FSM_NEXT_STATE_2_BITS {            // bits description
    Uint32 S0:16;                             // 15:0 FSM next state function for S0
    Uint32 S1:16;                             // 31:16 FSM next state function for S1
};

union CLB_FSM_NEXT_STATE_2_REG {
    Uint32  all;
    struct  CLB_FSM_NEXT_STATE_2_BITS  bit;
};

struct CLB_MISC_CONTROL_BITS {                // bits description
    Uint32 COUNT_ADD_SHIFT_0:1;               // 0 Add/Shift for counter 0
    Uint32 COUNT_DIR_0:1;                     // 1 Direction for counter 0
    Uint32 COUNT_EVENT_CTRL_0:1;              // 2 Event control for counter 0
    Uint32 COUNT_ADD_SHIFT_1:1;               // 3 Add/Shift for counter 1
    Uint32 COUNT_DIR_1:1;                     // 4 Direction for counter 1
    Uint32 COUNT_EVENT_CTRL_1:1;              // 5 Event control for counter 1
    Uint32 COUNT_ADD_SHIFT_2:1;               // 6 Add/Shift for counter 2
    Uint32 COUNT_DIR_2:1;                     // 7 Direction for counter 2
    Uint32 COUNT_EVENT_CTRL_2:1;              // 8 Event control for counter 2
    Uint32 COUNT_SERIALIZER_0:1;              // 9 Serializer enable 0
    Uint32 COUNT_SERIALIZER_1:1;              // 10 Serializer enable 1
    Uint32 COUNT_SERIALIZER_2:1;              // 11 Serializer enable 2
    Uint32 FSM_EXTRA_SEL0_0:1;                // 12 FSM extra_sel0 for 0
    Uint32 FSM_EXTRA_SEL1_0:1;                // 13 FSM extra_sel1 for 0
    Uint32 FSM_EXTRA_SEL0_1:1;                // 14 FSM extra_sel0 for 1
    Uint32 FSM_EXTRA_SEL1_1:1;                // 15 FSM extra_sel1 for 1
    Uint32 FSM_EXTRA_SEL0_2:1;                // 16 FSM extra_sel0 for 2
    Uint32 FSM_EXTRA_SEL1_2:1;                // 17 FSM extra_sel1 for 2
    Uint32 COUNT0_MATCH1_TAP_EN:1;            // 18 Match1 Tap Enable for Counter 0
    Uint32 COUNT1_MATCH1_TAP_EN:1;            // 19 Match1 Tap Enable for Counter 1
    Uint32 COUNT2_MATCH1_TAP_EN:1;            // 20 Match1 Tap Enable for Counter 2
    Uint32 COUNT0_MATCH2_TAP_EN:1;            // 21 Match2 Tap Enable for Counter 0
    Uint32 COUNT1_MATCH2_TAP_EN:1;            // 22 Match2 Tap Enable for Counter 1
    Uint32 COUNT2_MATCH2_TAP_EN:1;            // 23 Match2 Tap Enable for Counter 2
    Uint32 COUNT0_LFSR_EN:1;                  // 24 Enable LFSR mode for Counter 0
    Uint32 COUNT1_LFSR_EN:1;                  // 25 Enable LFSR mode for Counter 1
    Uint32 COUNT2_LFSR_EN:1;                  // 26 Enable LFSR mode for Counter 2
    Uint32 rsvd1:5;                           // 31:27 Reserved
};

union CLB_MISC_CONTROL_REG {
    Uint32  all;
    struct  CLB_MISC_CONTROL_BITS  bit;
};

struct CLB_OUTPUT_LUT_0_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_0_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_0_BITS  bit;
};

struct CLB_OUTPUT_LUT_1_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_1_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_1_BITS  bit;
};

struct CLB_OUTPUT_LUT_2_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_2_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_2_BITS  bit;
};

struct CLB_OUTPUT_LUT_3_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_3_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_3_BITS  bit;
};

struct CLB_OUTPUT_LUT_4_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_4_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_4_BITS  bit;
};

struct CLB_OUTPUT_LUT_5_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_5_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_5_BITS  bit;
};

struct CLB_OUTPUT_LUT_6_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_6_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_6_BITS  bit;
};

struct CLB_OUTPUT_LUT_7_BITS {                // bits description
    Uint32 IN0:5;                             // 4:0 Select value for IN0 of output LUT
    Uint32 IN1:5;                             // 9:5 Select value for IN1 of output LUT
    Uint32 IN2:5;                             // 14:10 Select value for IN2 of output LUT
    Uint32 FN:8;                              // 22:15 Output function for output LUT
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union CLB_OUTPUT_LUT_7_REG {
    Uint32  all;
    struct  CLB_OUTPUT_LUT_7_BITS  bit;
};

struct CLB_HLC_EVENT_SEL_BITS {               // bits description
    Uint32 EVENT0_SEL:5;                      // 4:0 Event Select 0
    Uint32 EVENT1_SEL:5;                      // 9:5 Event Select 1
    Uint32 EVENT2_SEL:5;                      // 14:10 Event Select 2
    Uint32 EVENT3_SEL:5;                      // 19:15 Event Select 3
    Uint32 ALT_EVENT0_SEL:1;                  // 20 Event Select 3
    Uint32 ALT_EVENT1_SEL:1;                  // 21 Event Select 3
    Uint32 ALT_EVENT2_SEL:1;                  // 22 Event Select 3
    Uint32 ALT_EVENT3_SEL:1;                  // 23 Event Select 3
    Uint32 rsvd1:8;                           // 31:24 Reserved
};

union CLB_HLC_EVENT_SEL_REG {
    Uint32  all;
    struct  CLB_HLC_EVENT_SEL_BITS  bit;
};

struct CLB_COUNT_MATCH_TAP_SEL_BITS {         // bits description
    Uint32 COUNT0_MATCH1:5;                   // 4:0 Match1 tap select for Counter 0
    Uint32 COUNT1_MATCH1:5;                   // 9:5 Match1 tap select for Counter 1
    Uint32 COUNT2_MATCH1:5;                   // 14:10 Match1 tap select for Counter 2
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 COUNT0_MATCH2:5;                   // 20:16 Match2 tap select for Counter 0
    Uint32 COUNT1_MATCH2:5;                   // 25:21 Match2 tap select for Counter 1
    Uint32 COUNT2_MATCH2:5;                   // 30:26 Match2 tap select for Counter 2
    Uint32 rsvd2:1;                           // 31 Reserved
};

union CLB_COUNT_MATCH_TAP_SEL_REG {
    Uint32  all;
    struct  CLB_COUNT_MATCH_TAP_SEL_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_0_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_0_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_0_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_1_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_1_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_1_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_2_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_2_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_2_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_3_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_3_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_3_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_4_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_4_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_4_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_5_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_5_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_5_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_6_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_6_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_6_BITS  bit;
};

struct CLB_OUTPUT_COND_CTRL_7_BITS {          // bits description
    Uint32 LEVEL_1_SEL:1;                     // 0 Level 1 Mux Select
    Uint32 LEVEL_2_SEL:2;                     // 2:1 Level 2 Mux Select
    Uint32 LEVEL_3_SEL:2;                     // 4:3 Level 3 Mux Select
    Uint32 SEL_GATING_CTRL:3;                 // 7:5 Gating control mux select
    Uint32 SEL_RELEASE_CTRL:3;                // 10:8 Releast control mux select
    Uint32 HW_GATING_CTRL_SEL:1;              // 11 Select HW for gating control
    Uint32 HW_RLS_CTRL_SEL:1;                 // 12 Select HW for release control
    Uint32 SEL_RAW_IN:1;                      // 13 Select input mode for the CLB AOC
    Uint32 ASYNC_COND_EN:1;                   // 14 Enable for conditioning
    Uint32 rsvd1:1;                           // 15 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_OUTPUT_COND_CTRL_7_REG {
    Uint32  all;
    struct  CLB_OUTPUT_COND_CTRL_7_BITS  bit;
};

struct CLB_MISC_ACCESS_CTRL_BITS {            // bits description
    Uint32 SPIEN:1;                           // 0 Enable CLB SPI Buffer feature
    Uint32 BLKEN:1;                           // 1 Block Register write
    Uint32 rsvd1:30;                          // 31:2 Reserved
};

union CLB_MISC_ACCESS_CTRL_REG {
    Uint32  all;
    struct  CLB_MISC_ACCESS_CTRL_BITS  bit;
};

struct CLB_SPI_DATA_CTRL_HI_BITS {            // bits description
    Uint32 STRB:5;                            // 4:0 Select value for strobe
    Uint32 rsvd1:3;                           // 7:5 Reserved
    Uint32 SHIFT:5;                           // 12:8 Shift value select
    Uint32 rsvd2:19;                          // 31:13 Reserved
};

union CLB_SPI_DATA_CTRL_HI_REG {
    Uint32  all;
    struct  CLB_SPI_DATA_CTRL_HI_BITS  bit;
};

struct CLB_HLC_EVENT_CTRL_BITS {              // bits description
    Uint32 EVENT0_EDGE_SEL:1;                 // 0 HLC event 0 edge select
    Uint32 EVENT1_EDGE_SEL:1;                 // 1 HLC event 1 edge select
    Uint32 EVENT2_EDGE_SEL:1;                 // 2 HLC event 2 edge select
    Uint32 EVENT3_EDGE_SEL:1;                 // 3 HLC event 3 edge select
    Uint32 SPI_DATA_STRB_EXTND:1;             // 4 Choosing the alternate MUX options for the HLC module
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union CLB_HLC_EVENT_CTRL_REG {
    Uint32  all;
    struct  CLB_HLC_EVENT_CTRL_BITS  bit;
};

struct  CLB_LOGIC_CONFIG_REGS {
    Uint32                                   rsvd1;                       // 0x0 Reserved
    union   CLB_COUNT_RESET_REG              CLB_COUNT_RESET;             // 0x4 Counter Block RESET
    union   CLB_COUNT_MODE_1_REG             CLB_COUNT_MODE_1;            // 0x8 Counter Block MODE_1
    union   CLB_COUNT_MODE_0_REG             CLB_COUNT_MODE_0;            // 0xc Counter Block MODE_0
    union   CLB_COUNT_EVENT_REG              CLB_COUNT_EVENT;             // 0x10 Counter Block EVENT
    union   CLB_FSM_EXTRA_IN0_REG            CLB_FSM_EXTRA_IN0;           // 0x14 FSM Extra EXT_IN0
    union   CLB_FSM_EXTERNAL_IN0_REG         CLB_FSM_EXTERNAL_IN0;        // 0x18 FSM EXT_IN0
    union   CLB_FSM_EXTERNAL_IN1_REG         CLB_FSM_EXTERNAL_IN1;        // 0x1c FSM_EXT_IN1
    union   CLB_FSM_EXTRA_IN1_REG            CLB_FSM_EXTRA_IN1;           // 0x20 FSM Extra_EXT_IN1
    union   CLB_LUT4_IN0_REG                 CLB_LUT4_IN0;                // 0x24 LUT4_0/1/2 IN0 input source
    union   CLB_LUT4_IN1_REG                 CLB_LUT4_IN1;                // 0x28 LUT4_0/1/2 IN1 input source
    union   CLB_LUT4_IN2_REG                 CLB_LUT4_IN2;                // 0x2c LUT4_0/1/2 IN2 input source
    union   CLB_LUT4_IN3_REG                 CLB_LUT4_IN3;                // 0x30 LUT4_0/1/2 IN3 input source
    Uint32                                   rsvd2;                       // 0x34 Reserved
    union   CLB_FSM_LUT_FN1_0_REG            CLB_FSM_LUT_FN1_0;           // 0x38 LUT function for FSM Unit 1 and Unit 0
    union   CLB_FSM_LUT_FN2_REG              CLB_FSM_LUT_FN2;             // 0x3c LUT function for FSM Unit 2
    union   CLB_LUT4_FN1_0_REG               CLB_LUT4_FN1_0;              // 0x40 LUT function for LUT4 block of Unit 1 and 0
    union   CLB_LUT4_FN2_REG                 CLB_LUT4_FN2;                // 0x44 LUT function for LUT4 block of Unit 2
    union   CLB_FSM_NEXT_STATE_0_REG         CLB_FSM_NEXT_STATE_0;        // 0x48 FSM Next state equations for Unit 0
    union   CLB_FSM_NEXT_STATE_1_REG         CLB_FSM_NEXT_STATE_1;        // 0x4c FSM Next state equations for Unit 1
    union   CLB_FSM_NEXT_STATE_2_REG         CLB_FSM_NEXT_STATE_2;        // 0x50 FSM Next state equations for Unit 2
    union   CLB_MISC_CONTROL_REG             CLB_MISC_CONTROL;            // 0x54 Static controls for Ctr,FSM
    union   CLB_OUTPUT_LUT_0_REG             CLB_OUTPUT_LUT_0;            // 0x58 Inp Sel, LUT fns for Out0
    union   CLB_OUTPUT_LUT_1_REG             CLB_OUTPUT_LUT_1;            // 0x5c Inp Sel, LUT fns for Out1
    union   CLB_OUTPUT_LUT_2_REG             CLB_OUTPUT_LUT_2;            // 0x60 Inp Sel, LUT fns for Out2
    union   CLB_OUTPUT_LUT_3_REG             CLB_OUTPUT_LUT_3;            // 0x64 Inp Sel, LUT fns for Out3
    union   CLB_OUTPUT_LUT_4_REG             CLB_OUTPUT_LUT_4;            // 0x68 Inp Sel, LUT fns for Out4
    union   CLB_OUTPUT_LUT_5_REG             CLB_OUTPUT_LUT_5;            // 0x6c Inp Sel, LUT fns for Out5
    union   CLB_OUTPUT_LUT_6_REG             CLB_OUTPUT_LUT_6;            // 0x70 Inp Sel, LUT fns for Out6
    union   CLB_OUTPUT_LUT_7_REG             CLB_OUTPUT_LUT_7;            // 0x74 Inp Sel, LUT fns for Out7
    union   CLB_HLC_EVENT_SEL_REG            CLB_HLC_EVENT_SEL;           // 0x78 Event Selector register for the High Level controller
    union   CLB_COUNT_MATCH_TAP_SEL_REG      CLB_COUNT_MATCH_TAP_SEL;     // 0x7c Counter tap values for match1 and match2 outputs
    union   CLB_OUTPUT_COND_CTRL_0_REG       CLB_OUTPUT_COND_CTRL_0;      // 0x80 Output conditioning control for output 0
    union   CLB_OUTPUT_COND_CTRL_1_REG       CLB_OUTPUT_COND_CTRL_1;      // 0x84 Output conditioning control for output 1
    union   CLB_OUTPUT_COND_CTRL_2_REG       CLB_OUTPUT_COND_CTRL_2;      // 0x88 Output conditioning control for output 2
    union   CLB_OUTPUT_COND_CTRL_3_REG       CLB_OUTPUT_COND_CTRL_3;      // 0x8c Output conditioning control for output 3
    union   CLB_OUTPUT_COND_CTRL_4_REG       CLB_OUTPUT_COND_CTRL_4;      // 0x90 Output conditioning control for output 4
    union   CLB_OUTPUT_COND_CTRL_5_REG       CLB_OUTPUT_COND_CTRL_5;      // 0x94 Output conditioning control for output 5
    union   CLB_OUTPUT_COND_CTRL_6_REG       CLB_OUTPUT_COND_CTRL_6;      // 0x98 Output conditioning control for output 6
    union   CLB_OUTPUT_COND_CTRL_7_REG       CLB_OUTPUT_COND_CTRL_7;      // 0x9c Output conditioning control for output 7
    union   CLB_MISC_ACCESS_CTRL_REG         CLB_MISC_ACCESS_CTRL;        // 0xa0 Miscellaneous Access and enable control
    union   CLB_SPI_DATA_CTRL_HI_REG         CLB_SPI_DATA_CTRL_HI;        // 0xa4 CLB to SPI buffer control High
    union   CLB_HLC_EVENT_CTRL_REG           CLB_HLC_EVENT_CTRL;          // 0xa8 HLC event edge and spi data strb extend register
};

struct CLB_LOAD_EN_BITS {                     // bits description
    Uint32 LOAD_EN:1;                         // 0 Load Enable
    Uint32 GLOBAL_EN:1;                       // 1 Global Enable
    Uint32 STOP:1;                            // 2 Debug stop control
    Uint32 NMI_EN:1;                          // 3 NMI output enable
    Uint32 PIPELINE_EN:1;                     // 4 Enable input pipelining
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union CLB_LOAD_EN_REG {
    Uint32  all;
    struct  CLB_LOAD_EN_BITS  bit;
};

struct CLB_LOAD_ADDR_BITS {                   // bits description
    Uint32 ADDR:6;                            // 5:0 Indirect Address
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_LOAD_ADDR_REG {
    Uint32  all;
    struct  CLB_LOAD_ADDR_BITS  bit;
};

struct CLB_INPUT_FILTER_BITS {                // bits description
    Uint32 FIN0:2;                            // 1:0 Input filter control 0
    Uint32 FIN1:2;                            // 3:2 Input filter control 1
    Uint32 FIN2:2;                            // 5:4 Input filter control 2
    Uint32 FIN3:2;                            // 7:6 Input filter control 3
    Uint32 FIN4:2;                            // 9:8 Input filter control 4
    Uint32 FIN5:2;                            // 11:10 Input filter control 5
    Uint32 FIN6:2;                            // 13:12 Input filter control 6
    Uint32 FIN7:2;                            // 15:14 Input filter control 7
    Uint32 SYNC0:1;                           // 16 Synchronizer control 0
    Uint32 SYNC1:1;                           // 17 Synchronizer control 1
    Uint32 SYNC2:1;                           // 18 Synchronizer control 2
    Uint32 SYNC3:1;                           // 19 Synchronizer control 3
    Uint32 SYNC4:1;                           // 20 Synchronizer control 4
    Uint32 SYNC5:1;                           // 21 Synchronizer control 5
    Uint32 SYNC6:1;                           // 22 Synchronizer control 6
    Uint32 SYNC7:1;                           // 23 Synchronizer control 7
    Uint32 PIPE0:1;                           // 24 Enable pipeline 0
    Uint32 PIPE1:1;                           // 25 Enable pipeline 1
    Uint32 PIPE2:1;                           // 26 Enable pipeline 2
    Uint32 PIPE3:1;                           // 27 Enable pipeline 3
    Uint32 PIPE4:1;                           // 28 Enable pipeline 4
    Uint32 PIPE5:1;                           // 29 Enable pipeline 5
    Uint32 PIPE6:1;                           // 30 Enable pipeline 6
    Uint32 PIPE7:1;                           // 31 Enable pipeline 7
};

union CLB_INPUT_FILTER_REG {
    Uint32  all;
    struct  CLB_INPUT_FILTER_BITS  bit;
};

struct CLB_IN_MUX_SEL_0_BITS {                // bits description
    Uint32 SEL_GP_IN_0:1;                     // 0 Select GP register 0
    Uint32 SEL_GP_IN_1:1;                     // 1 Select GP register 1
    Uint32 SEL_GP_IN_2:1;                     // 2 Select GP register 2
    Uint32 SEL_GP_IN_3:1;                     // 3 Select GP register 3
    Uint32 SEL_GP_IN_4:1;                     // 4 Select GP register 4
    Uint32 SEL_GP_IN_5:1;                     // 5 Select GP register 5
    Uint32 SEL_GP_IN_6:1;                     // 6 Select GP register 6
    Uint32 SEL_GP_IN_7:1;                     // 7 Select GP register 7
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union CLB_IN_MUX_SEL_0_REG {
    Uint32  all;
    struct  CLB_IN_MUX_SEL_0_BITS  bit;
};

struct CLB_LCL_MUX_SEL_1_BITS {               // bits description
    Uint32 LCL_MUX_SEL_IN_0:5;                // 4:0 Local Mux select 0
    Uint32 LCL_MUX_SEL_IN_1:5;                // 9:5 Local Mux select 1
    Uint32 LCL_MUX_SEL_IN_2:5;                // 14:10 Local Mux select 2
    Uint32 LCL_MUX_SEL_IN_3:5;                // 19:15 Local Mux select 3
    Uint32 rsvd1:8;                           // 27:20 Reserved
    Uint32 MISC_INPUT_SEL_0:1;                // 28 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_1:1;                // 29 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_2:1;                // 30 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_3:1;                // 31 Select MISC_INPUT
};

union CLB_LCL_MUX_SEL_1_REG {
    Uint32  all;
    struct  CLB_LCL_MUX_SEL_1_BITS  bit;
};

struct CLB_LCL_MUX_SEL_2_BITS {               // bits description
    Uint32 LCL_MUX_SEL_IN_4:5;                // 4:0 Local Mux select 4
    Uint32 LCL_MUX_SEL_IN_5:5;                // 9:5 Local Mux select 5
    Uint32 LCL_MUX_SEL_IN_6:5;                // 14:10 Local Mux select 6
    Uint32 LCL_MUX_SEL_IN_7:5;                // 19:15 Local Mux select 7
    Uint32 rsvd1:8;                           // 27:20 Reserved
    Uint32 MISC_INPUT_SEL_4:1;                // 28 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_5:1;                // 29 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_6:1;                // 30 Select MISC_INPUT
    Uint32 MISC_INPUT_SEL_7:1;                // 31 Select MISC_INPUT
};

union CLB_LCL_MUX_SEL_2_REG {
    Uint32  all;
    struct  CLB_LCL_MUX_SEL_2_BITS  bit;
};

struct CLB_BUF_PTR_BITS {                     // bits description
    Uint32 PULL:8;                            // 7:0 Data pointer for pull
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 PUSH:8;                            // 23:16 Data pointer for pull
    Uint32 rsvd2:8;                           // 31:24 Reserved
};

union CLB_BUF_PTR_REG {
    Uint32  all;
    struct  CLB_BUF_PTR_BITS  bit;
};

struct CLB_GP_REG_BITS {                      // bits description
    Uint32 REG:8;                             // 7:0 General Purpose bit register
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 SW_GATING_CTRL_0:1;                // 16 Software gating control 0
    Uint32 SW_GATING_CTRL_1:1;                // 17 Software gating control 1
    Uint32 SW_GATING_CTRL_2:1;                // 18 Software gating control 2
    Uint32 SW_GATING_CTRL_3:1;                // 19 Software gating control 3
    Uint32 SW_GATING_CTRL_4:1;                // 20 Software gating control 4
    Uint32 SW_GATING_CTRL_5:1;                // 21 Software gating control 5
    Uint32 SW_GATING_CTRL_6:1;                // 22 Software gating control 6
    Uint32 SW_GATING_CTRL_7:1;                // 23 Software gating control 7
    Uint32 SW_RLS_CTRL_0:1;                   // 24 Software release control 0
    Uint32 SW_RLS_CTRL_1:1;                   // 25 Software release control 1
    Uint32 SW_RLS_CTRL_2:1;                   // 26 Software release control 2
    Uint32 SW_RLS_CTRL_3:1;                   // 27 Software release control 3
    Uint32 SW_RLS_CTRL_4:1;                   // 28 Software release control 4
    Uint32 SW_RLS_CTRL_5:1;                   // 29 Software release control 5
    Uint32 SW_RLS_CTRL_6:1;                   // 30 Software release control 6
    Uint32 SW_RLS_CTRL_7:1;                   // 31 Software release control 7
};

union CLB_GP_REG_REG {
    Uint32  all;
    struct  CLB_GP_REG_BITS  bit;
};

struct CLB_GLBL_MUX_SEL_1_BITS {              // bits description
    Uint32 GLBL_MUX_SEL_IN_0:7;               // 6:0 Global Mux select 0
    Uint32 GLBL_MUX_SEL_IN_1:7;               // 13:7 Global Mux select 1
    Uint32 GLBL_MUX_SEL_IN_2:7;               // 20:14 Global Mux select 2
    Uint32 GLBL_MUX_SEL_IN_3:7;               // 27:21 Global Mux select 3
    Uint32 rsvd1:4;                           // 31:28 Reserved
};

union CLB_GLBL_MUX_SEL_1_REG {
    Uint32  all;
    struct  CLB_GLBL_MUX_SEL_1_BITS  bit;
};

struct CLB_GLBL_MUX_SEL_2_BITS {              // bits description
    Uint32 GLBL_MUX_SEL_IN_4:7;               // 6:0 Global Mux select 4
    Uint32 GLBL_MUX_SEL_IN_5:7;               // 13:7 Global Mux select 5
    Uint32 GLBL_MUX_SEL_IN_6:7;               // 20:14 Global Mux select 6
    Uint32 GLBL_MUX_SEL_IN_7:7;               // 27:21 Global Mux select 7
    Uint32 rsvd1:4;                           // 31:28 Reserved
};

union CLB_GLBL_MUX_SEL_2_REG {
    Uint32  all;
    struct  CLB_GLBL_MUX_SEL_2_BITS  bit;
};

struct CLB_PRESCALE_CTRL_BITS {               // bits description
    Uint32 CLKEN:1;                           // 0 Enable the prescale clock generator
    Uint32 STRB:1;                            // 1 Enable the Strobe mode of operation
    Uint32 TAP:4;                             // 5:2 TAP Select value
    Uint32 rsvd1:10;                          // 15:6 Reserved
    Uint32 PRESCALE:16;                       // 31:16 Value of prescale register
};

union CLB_PRESCALE_CTRL_REG {
    Uint32  all;
    struct  CLB_PRESCALE_CTRL_BITS  bit;
};

struct CLB_INTR_TAG_REG_BITS {                // bits description
    Uint32 TAG:6;                             // 5:0 Interrupt tag
    Uint32 rsvd1:26;                          // 31:6 Reserved
};

union CLB_INTR_TAG_REG_REG {
    Uint32  all;
    struct  CLB_INTR_TAG_REG_BITS  bit;
};

struct CLB_LOCK_BITS {                        // bits description
    Uint32 LOCK:1;                            // 0 LOCK enable
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 KEY:16;                            // 31:16 Key for enabling write
};

union CLB_LOCK_REG {
    Uint32  all;
    struct  CLB_LOCK_BITS  bit;
};

struct CLB_HLC_INSTR_READ_PTR_BITS {          // bits description
    Uint32 READ_PTR:5;                        // 4:0 HLC instruction read pointer
    Uint32 rsvd1:27;                          // 31:5 Reserved
};

union CLB_HLC_INSTR_READ_PTR_REG {
    Uint32  all;
    struct  CLB_HLC_INSTR_READ_PTR_BITS  bit;
};

struct CLB_HLC_INSTR_VALUE_BITS {             // bits description
    Uint32 INSTR:12;                          // 11:0 HLC instruction value
    Uint32 rsvd1:20;                          // 31:12 Reserved
};

union CLB_HLC_INSTR_VALUE_REG {
    Uint32  all;
    struct  CLB_HLC_INSTR_VALUE_BITS  bit;
};

struct CLB_DBG_OUT_2_BITS {                   // bits description
    Uint32 OUT:8;                             // 7:0 Outputs of CLB Async block
    Uint32 IN:8;                              // 15:8 CLB CELL Inputs
    Uint32 rsvd1:16;                          // 31:16 Reserved
};

union CLB_DBG_OUT_2_REG {
    Uint32  all;
    struct  CLB_DBG_OUT_2_BITS  bit;
};

struct CLB_DBG_OUT_BITS {                     // bits description
    Uint32 rsvd1:1;                           // 0 Reserved
    Uint32 COUNT0_MATCH2:1;                   // 1 COUNT_MATCH2 UNIT 0
    Uint32 COUNT0_ZERO:1;                     // 2 COUNT_ZERO UNIT 0
    Uint32 COUNT0_MATCH1:1;                   // 3 COUNT_MATCH1 UNIT 0
    Uint32 FSM0_S0:1;                         // 4 FSM_S0 UNIT 0
    Uint32 FSM0_S1:1;                         // 5 FSM_S1 UNIT 0
    Uint32 FSM0_LUTOUT:1;                     // 6 FSM_LUT_OUT UNIT 0
    Uint32 LUT40_OUT:1;                       // 7 LUT4_OUT UNIT 0
    Uint32 rsvd2:1;                           // 8 Reserved
    Uint32 COUNT1_MATCH2:1;                   // 9 COUNT_MATCH2 UNIT 1
    Uint32 COUNT1_ZERO:1;                     // 10 COUNT_ZERO UNIT 1
    Uint32 COUNT1_MATCH1:1;                   // 11 COUNT_MATCH1 UNIT 1
    Uint32 FSM1_S0:1;                         // 12 FSM_S0 UNIT 1
    Uint32 FSM1_S1:1;                         // 13 FSM_S1 UNIT 1
    Uint32 FSM1_LUTOUT:1;                     // 14 FSM_LUT_OUT UNIT 1
    Uint32 LUT41_OUT:1;                       // 15 LUT4_OUT UNIT 1
    Uint32 rsvd3:1;                           // 16 Reserved
    Uint32 COUNT2_MATCH2:1;                   // 17 COUNT_MATCH2 UNIT 2
    Uint32 COUNT2_ZERO:1;                     // 18 COUNT_ZERO UNIT 2
    Uint32 COUNT2_MATCH1:1;                   // 19 COUNT_MATCH1 UNIT 2
    Uint32 FSM2_S0:1;                         // 20 FSM_S0 UNIT 2
    Uint32 FSM2_S1:1;                         // 21 FSM_S1 UNIT 2
    Uint32 FSM2_LUTOUT:1;                     // 22 FSM_LUT_OUT UNIT 2
    Uint32 LUT42_OUT:1;                       // 23 LUT4_OUT UNIT 2
    Uint32 OUT0:1;                            // 24 CELL Output 0
    Uint32 OUT1:1;                            // 25 CELL Output 1
    Uint32 OUT2:1;                            // 26 CELL Output 2
    Uint32 OUT3:1;                            // 27 CELL Output 3
    Uint32 OUT4:1;                            // 28 CELL Output 4
    Uint32 OUT5:1;                            // 29 CELL Output 5
    Uint32 OUT6:1;                            // 30 CELL Output 6
    Uint32 OUT7:1;                            // 31 CELL Output 7
};

union CLB_DBG_OUT_REG {
    Uint32  all;
    struct  CLB_DBG_OUT_BITS  bit;
};

struct  CLB_LOGIC_CONTROL_REGS {
    union   CLB_LOAD_EN_REG                  CLB_LOAD_EN;                 // 0x0 Global enable & indirect load enable control
    union   CLB_LOAD_ADDR_REG                CLB_LOAD_ADDR;               // 0x4 Indirect address
    Uint32                                   CLB_LOAD_DATA;               // 0x8 Data for indirect loads
    union   CLB_INPUT_FILTER_REG             CLB_INPUT_FILTER;            // 0xc Input filter selection for both edge detection and synchronizers
    union   CLB_IN_MUX_SEL_0_REG             CLB_IN_MUX_SEL_0;            // 0x10 Input selection to decide between Signals and GP register
    union   CLB_LCL_MUX_SEL_1_REG            CLB_LCL_MUX_SEL_1;           // 0x14 Input Mux selection for local mux
    union   CLB_LCL_MUX_SEL_2_REG            CLB_LCL_MUX_SEL_2;           // 0x18 Input Mux selection for local mux
    union   CLB_BUF_PTR_REG                  CLB_BUF_PTR;                 // 0x1c PUSH and PULL pointers
    union   CLB_GP_REG_REG                   CLB_GP_REG;                  // 0x20 General purpose register for CELL inputs
    Uint32                                   CLB_OUT_EN;                  // 0x24 CELL output enable register
    union   CLB_GLBL_MUX_SEL_1_REG           CLB_GLBL_MUX_SEL_1;          // 0x28 Global Mux select for CELL inputs
    union   CLB_GLBL_MUX_SEL_2_REG           CLB_GLBL_MUX_SEL_2;          // 0x2c Global Mux select for CELL inputs
    union   CLB_PRESCALE_CTRL_REG            CLB_PRESCALE_CTRL;           // 0x30 Prescaler register control
    Uint32                                   rsvd1[3];                    // 0x34 Reserved
    union   CLB_INTR_TAG_REG_REG             CLB_INTR_TAG_REG;            // 0x40 Interrupt Tag register
    union   CLB_LOCK_REG                     CLB_LOCK;                    // 0x44 Lock control register
    union   CLB_HLC_INSTR_READ_PTR_REG       CLB_HLC_INSTR_READ_PTR;      // 0x48 HLC instruction read pointer
    union   CLB_HLC_INSTR_VALUE_REG          CLB_HLC_INSTR_VALUE;         // 0x4c HLC instruction read value
    Uint32                                   rsvd2[3];                    // 0x50 Reserved
    union   CLB_DBG_OUT_2_REG                CLB_DBG_OUT_2;               // 0x5c Visibility for CLB inputs and final asynchronous outputs
    Uint32                                   CLB_DBG_R0;                  // 0x60 R0 of High level Controller
    Uint32                                   CLB_DBG_R1;                  // 0x64 R1 of High level Controller
    Uint32                                   CLB_DBG_R2;                  // 0x68 R2 of High level Controller
    Uint32                                   CLB_DBG_R3;                  // 0x6c R3 of High level Controller
    Uint32                                   CLB_DBG_C0;                  // 0x70 Count of Unit 0
    Uint32                                   CLB_DBG_C1;                  // 0x74 Count of Unit 1
    Uint32                                   CLB_DBG_C2;                  // 0x78 Count of Unit 2
    union   CLB_DBG_OUT_REG                  CLB_DBG_OUT;                 // 0x7c Outputs of various units in the Cell
};

struct  CLB_DATA_EXCHANGE_REGS {
    Uint32                                   CLB_PUSH[4];                 // 0x0 CLB_PUSH FIFO Registers (from HLC)
    Uint32                                   rsvd1[12];                   // 0x10 Reserved
    Uint32                                   CLB_PULL[4];                 // 0x40 CLB_PULL FIFO Registers (TO HLC)
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================