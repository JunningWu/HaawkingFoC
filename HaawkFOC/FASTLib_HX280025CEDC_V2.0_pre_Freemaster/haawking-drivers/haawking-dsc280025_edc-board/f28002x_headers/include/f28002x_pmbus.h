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


#ifndef F28002X_PMBUS_H
#define F28002X_PMBUS_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PMBUS Individual Register Bit Definitions:

struct PMBMC_BITS {                           // bits description
    Uint32 RW:1;                              // 0 RnW bit of the Message
    Uint32 SLAVE_ADDR:7;                      // 7:1 Slave Address
    Uint32 BYTE_COUNT:8;                      // 15:8 Number of Bytes Transmitted
    Uint32 CMD_ENA:1;                         // 16 Master Command Code Enable
    Uint32 EXT_CMD:1;                         // 17 Master Extended Command Code Enable
    Uint32 PEC_ENA:1;                         // 18 Master PEC Processing Enable
    Uint32 GRP_CMD:1;                         // 19 Master Group Command Message Enable
    Uint32 PRC_CALL:1;                        // 20 Master Process Call Message Enable
    Uint32 rsvd1:11;                          // 31:21 Reserved
};

union PMBMC_REG {
    Uint32  all;
    struct  PMBMC_BITS  bit;
};

struct PMBACK_BITS {                          // bits description
    Uint32 ACK:1;                             // 0 Allows firmware to ack/nack received data
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBACK_REG {
    Uint32  all;
    struct  PMBACK_BITS  bit;
};

struct PMBSTS_BITS {                          // bits description
    Uint32 RD_BYTE_COUNT:3;                   // 2:0 Number of Data Bytes available in Receive Data Register
    Uint32 DATA_READY:1;                      // 3 Data Ready Flag
    Uint32 DATA_REQUEST:1;                    // 4 Data Request Flag
    Uint32 EOM:1;                             // 5 End of Message Indicator
    Uint32 NACK:1;                            // 6 Not Acknowledge Flag Status
    Uint32 PEC_VALID:1;                       // 7 PEC Valid Indicator
    Uint32 CLK_LOW_TIMEOUT:1;                 // 8 Clock Low Timeout Status
    Uint32 CLK_HIGH_DETECTED:1;               // 9 Clock High Detection Status
    Uint32 SLAVE_ADDR_READY:1;                // 10 Slave Address Ready
    Uint32 RPT_START:1;                       // 11 Repeated Start Flag
    Uint32 UNIT_BUSY:1;                       // 12 PMBus Busy Indicator
    Uint32 BUS_FREE:1;                        // 13 PMBus Free Indicator
    Uint32 LOST_ARB:1;                        // 14 Lost Arbitration Flag
    Uint32 MASTER:1;                          // 15 Master Indicator
    Uint32 ALERT_EDGE:1;                      // 16 Alert Edge Detection Status
    Uint32 CONTROL_EDGE:1;                    // 17 Control Edge Detection Status
    Uint32 ALERT_RAW:1;                       // 18 Alert Pin Real Time Status
    Uint32 CONTROL_RAW:1;                     // 19 Control Pin Real Time Status
    Uint32 SDA_RAW:1;                         // 20 PMBus Data Pin Real Time Status
    Uint32 SCL_RAW:1;                         // 21 PMBus Clock Pin Real Time Status
    Uint32 rsvd1:10;                          // 31:22 Reserved
};

union PMBSTS_REG {
    Uint32  all;
    struct  PMBSTS_BITS  bit;
};

struct PMBINTM_BITS {                         // bits description
    Uint32 BUS_FREE:1;                        // 0 Bus Free Interrupt Mask
    Uint32 BUS_LOW_TIMEOUT:1;                 // 1 Clock Low Timeout Interrupt Mask
    Uint32 DATA_READY:1;                      // 2 Data Ready Interrupt Mask
    Uint32 DATA_REQUEST:1;                    // 3 Data Request Interrupt Mask
    Uint32 SLAVE_ADDR_READY:1;                // 4 Slave Address Ready Interrupt Mask
    Uint32 EOM:1;                             // 5 End of Message Interrupt Mask
    Uint32 ALERT:1;                           // 6 Alert Detection Interrupt Mask
    Uint32 CONTROL:1;                         // 7 Control Detection Interrupt Mask
    Uint32 LOST_ARB:1;                        // 8 Lost Arbitration Interrupt Mask
    Uint32 CLK_HIGH_DETECT:1;                 // 9 Clock High Detection Interrupt Mask
    Uint32 rsvd1:6;                           // 15:10 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBINTM_REG {
    Uint32  all;
    struct  PMBINTM_BITS  bit;
};

struct PMBSC_BITS {                           // bits description
    Uint32 SLAVE_ADDR:7;                      // 6:0 Configures the current device address of the slave.
    Uint32 MAN_SLAVE_ACK:1;                   // 7 Manual Slave Address Acknowledgement Mode
    Uint32 SLAVE_MASK:7;                      // 14:8 Slave address mask
    Uint32 PEC_ENA:1;                         // 15 PEC Processing Enable
    Uint32 TX_COUNT:3;                        // 18:16 Number of valid bytes in Transmit Data Register
    Uint32 TX_PEC:1;                          // 19 send a PEC byte at end of message
    Uint32 MAN_CMD:1;                         // 20 Manual Command Acknowledgement Mode
    Uint32 RX_BYTE_ACK_CNT:2;                 // 22:21 Number of data bytes to automatically acknowledge
    Uint32 rsvd1:9;                           // 31:23 Reserved
};

union PMBSC_REG {
    Uint32  all;
    struct  PMBSC_BITS  bit;
};

struct PMBHSA_BITS {                          // bits description
    Uint32 SLAVE_RW:1;                        // 0 Stored R/W bit
    Uint32 SLAVE_ADDR:7;                      // 7:1 Stored device address
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBHSA_REG {
    Uint32  all;
    struct  PMBHSA_BITS  bit;
};

struct PMBCTRL_BITS {                         // bits description
    Uint32 RESET:1;                           // 0 PMBus Interface Synchronous Reset
    Uint32 ALERT_EN:1;                        // 1 Slave Alert Enable
    Uint32 BUS_LO_INT_EDGE:1;                 // 2 Clock Low Timeout Interrupt Edge Select
    Uint32 FAST_MODE:1;                       // 3 Fast Mode Enable
    Uint32 rsvd1:1;                           // 4 Reserved
    Uint32 CNTL_INT_EDGE:1;                   // 5 Control Interrupt Edge Select
    Uint32 ALERT_MODE:1;                      // 6 Configures mode of Alert pin
    Uint32 ALERT_VALUE:1;                     // 7 Configures output value of Alert pin in GPIO Mode
    Uint32 ALERT_DIR:1;                       // 8 Configures direction of Alert pin in GPIO mode
    Uint32 CNTL_MODE:1;                       // 9 Configures mode of Control pin
    Uint32 CNTL_VALUE:1;                      // 10 Configures output value of Control pin in GPIO Mode
    Uint32 CNTL_DIR:1;                        // 11 Configures direction of Control pin in GPIO mode
    Uint32 SDA_MODE:1;                        // 12 Configures mode of PMBus Data pin
    Uint32 SDA_VALUE:1;                       // 13 Configures output value of PMBus data pin in GPIO Mode
    Uint32 SDA_DIR:1;                         // 14 Configures direction of PMBus data pin in GPIO mode
    Uint32 SCL_MODE:1;                        // 15 Configures mode of PMBus Clock pin
    Uint32 SCL_VALUE:1;                       // 16 Configures output value of PMBus clock pin in GPIO Mode
    Uint32 SCL_DIR:1;                         // 17 Configures direction of PMBus clock pin in GPIO mode
    Uint32 IBIAS_A_EN:1;                      // 18 PMBus Current Source A Control
    Uint32 IBIAS_B_EN:1;                      // 19 PMBus Current Source B Control
    Uint32 CLK_LO_DIS:1;                      // 20 Clock Low Timeout Disable
    Uint32 SLAVE_EN:1;                        // 21 PMBus Slave Enable
    Uint32 MASTER_EN:1;                       // 22 PMBus Master Enable
    Uint32 CLKDIV:5;                          // 27:23 PMBUS Clock Divide Value
    Uint32 rsvd2:3;                           // 30:28 Reserved
    Uint32 I2CMODE:1;                         // 31 Bit to enable I2C mode
};

union PMBCTRL_REG {
    Uint32  all;
    struct  PMBCTRL_BITS  bit;
};

struct PMBTIMCTL_BITS {                       // bits description
    Uint32 TIM_OVERRIDE:1;                    // 0 Overide the default settings of the timing parameters.
    Uint32 rsvd1:15;                          // 15:1 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBTIMCTL_REG {
    Uint32  all;
    struct  PMBTIMCTL_BITS  bit;
};

struct PMBTIMCLK_BITS {                       // bits description
    Uint32 CLK_HIGH_LIMIT:8;                  // 7:0 Determines the PMBUS master clock high pulse width.
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 CLK_FREQ:8;                        // 23:16 Determines the PMBUS master clock frequency.
    Uint32 rsvd2:8;                           // 31:24 Reserved
};

union PMBTIMCLK_REG {
    Uint32  all;
    struct  PMBTIMCLK_BITS  bit;
};

struct PMBTIMSTSETUP_BITS {                   // bits description
    Uint32 TSU_STA:8;                         // 7:0 Setup time, rise edge of PMBUS master clock to start edge.
    Uint32 rsvd1:8;                           // 15:8 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBTIMSTSETUP_REG {
    Uint32  all;
    struct  PMBTIMSTSETUP_BITS  bit;
};

struct PMBTIMBIDLE_BITS {                     // bits description
    Uint32 BUSIDLE:10;                        // 9:0 Determines the Bus Idle Limit
    Uint32 rsvd1:6;                           // 15:10 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBTIMBIDLE_REG {
    Uint32  all;
    struct  PMBTIMBIDLE_BITS  bit;
};

struct PMBTIMLOWTIMOUT_BITS {                 // bits description
    Uint32 CLKLOWTIMOUT:20;                   // 19:0 Determines the clock low timeout value
    Uint32 rsvd1:12;                          // 31:20 Reserved
};

union PMBTIMLOWTIMOUT_REG {
    Uint32  all;
    struct  PMBTIMLOWTIMOUT_BITS  bit;
};

struct PMBTIMHIGHTIMOUT_BITS {                // bits description
    Uint32 CLKHIGHTIMOUT:10;                  // 9:0 Determines the clock high timeout value
    Uint32 rsvd1:6;                           // 15:10 Reserved
    Uint32 rsvd2:16;                          // 31:16 Reserved
};

union PMBTIMHIGHTIMOUT_REG {
    Uint32  all;
    struct  PMBTIMHIGHTIMOUT_BITS  bit;
};

struct  PMBUS_REGS {
    union   PMBMC_REG                        PMBMC;                       // 0x0 PMBUS Master Mode Control Register
    Uint32                                   PMBTXBUF;                    // 0x4 PMBUS Transmit Buffer
    Uint32                                   PMBRXBUF;                    // 0x8 PMBUS Receive buffer
    union   PMBACK_REG                       PMBACK;                      // 0xc PMBUS Acknowledge Register
    union   PMBSTS_REG                       PMBSTS;                      // 0x10 PMBUS Status Register
    union   PMBINTM_REG                      PMBINTM;                     // 0x14 PMBUS Interrupt Mask Register
    union   PMBSC_REG                        PMBSC;                       // 0x18 PMBUS Slave Mode Configuration Register
    union   PMBHSA_REG                       PMBHSA;                      // 0x1c PMBUS Hold Slave Address Register
    union   PMBCTRL_REG                      PMBCTRL;                     // 0x20 PMBUS Control Register
    union   PMBTIMCTL_REG                    PMBTIMCTL;                   // 0x24 PMBUS Timing Control Register
    union   PMBTIMCLK_REG                    PMBTIMCLK;                   // 0x28 PMBUS Clock Timing Register
    union   PMBTIMSTSETUP_REG                PMBTIMSTSETUP;               // 0x2c PMBUS Start Setup Time Register
    union   PMBTIMBIDLE_REG                  PMBTIMBIDLE;                 // 0x30 PMBUS Bus Idle Time Register
    union   PMBTIMLOWTIMOUT_REG              PMBTIMLOWTIMOUT;             // 0x34 PMBUS Clock Low Timeout Value Register
    union   PMBTIMHIGHTIMOUT_REG             PMBTIMHIGHTIMOUT;            // 0x38 PMBUS Clock High Timeout Value Register
};


#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================