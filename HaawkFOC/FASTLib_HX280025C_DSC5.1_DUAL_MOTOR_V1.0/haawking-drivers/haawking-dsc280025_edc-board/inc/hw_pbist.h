//#################################################################################################################
//
// FILE:    hw_pbist.h
//
// TITLE:   Definitions for the PBIST registers.
//
//#################################################################################################################
// $HAAWKING Release: Hal Driver Library V1.0.0 $
// $Release Date: 2024.01.25 16:42:29 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//#################################################################################################################

#ifndef HW_PBIST_H
#define HW_PBIST_H

//*****************************************************************************
//
// The following are defines for the PBIST register offsets
//
//*****************************************************************************
#define PBIST_O_BISTCFG				0xC
#define PBIST_O_BISTREN				0x10
#define PBIST_O_BISTSTS				0x14
#define PBIST_O_BISTRESULT			0x18



//*****************************************************************************
//
// The following are defines for the bit fields in the BISTCFG register
//
//*****************************************************************************
#define PBIST_BISTCFG_M0_ENABLE                0x1U         // M0 MPOST BIST ENABLE
#define PBIST_BISTCFG_M0_DISABLE               0x0U         // M0 MPOST BIST ENABLE
#define PBIST_BISTCFG_M1_ENABLE                0x2U         // M1 MPOST BIST ENABLE
#define PBIST_BISTCFG_M1_DISABLE               0x0U         // M1 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS4_ENABLE            0x1000U         // LS4 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS4_DISABLE              0x0U         // LS4 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS5_ENABLE            0x2000U         // LS5 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS5_DISABLE              0x0U         // LS5 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS6_ENABLE            0x4000U         // LS6 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS6_DISABLE              0x0U         // LS6 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS7_ENABLE            0x8000U         // LS7 MPOST BIST ENABLE
#define PBIST_BISTCFG_LS7_DISABLE              0x0U         // LS7 MPOST BIST ENABLE
#define PBIST_BISTCFG_GS0_ENABLE           0x10000U         // GS0 MPOST BIST ENABLE
#define PBIST_BISTCFG_GS0_DISABLE              0x0U         // GS0 MPOST BIST ENABLE
#define PBIST_BISTCFG_BROM_ENABLE        0x1000000U         // BOOTROM MPOST BIST ENABLE
#define PBIST_BISTCFG_BROM_DISABLE             0x0U         // BOOTROM MPOST BIST ENABLE
#define PBIST_BISTCFG_SROM_ENABLE        0x2000000U         // Secure ROM MPOST BIST ENABLE
#define PBIST_BISTCFG_SROM_DISABLE             0x0U         // Secure ROM MPOST BIST ENABLE
#define PBIST_BISTCFG_CAN_SRAM_ENABLE    0x4000000U         // Secure ROM MPOST BIST ENABLE
#define PBIST_BISTCFG_CAN_SRAM_DISABLE         0x0U         // Secure ROM MPOST BIST ENABLE
#define PBIST_BISTCFG_PIE_SRAM1_ENABLE   0x8000000U         // PIE SRAM1 MPOST BIST ENABLE
#define PBIST_BISTCFG_PIE_SRAM1_DISABLE        0x0U         // PIE SRAM1 MPOST BIST ENABLE
#define PBIST_BISTCFG_PIE_SRAM2_ENABLE  0x10000000U         // PIE SRAM2 MPOST BIST ENABLE
#define PBIST_BISTCFG_PIE_SRAM2_DISABLE        0x0U         // PIE SRAM2 MPOST BIST ENABLE

//*****************************************************************************
//
// The following are defines for the bit fields in the BISTSTS register
//
//*****************************************************************************
#define PBIST_BISTSTS_M0_DONE                0x1U         // M0 MPOST BIST is done
#define PBIST_BISTSTS_M0_TEST                0x0U         // M0 MPOST BIST is testing
#define PBIST_BISTSTS_M1_DONE                0x2U         // M1 MPOST BIST is done
#define PBIST_BISTSTS_M1_TEST                0x0U         // M1 MPOST BIST is testing
#define PBIST_BISTSTS_LS4_DONE            0x1000U         // LS4 MPOST BIST is done
#define PBIST_BISTSTS_LS4_TEST               0x0U         // LS4 MPOST BIST is testing
#define PBIST_BISTSTS_LS5_DONE            0x2000U         // LS5 MPOST BIST is done
#define PBIST_BISTSTS_LS5_TEST               0x0U         // LS5 MPOST BIST is testing
#define PBIST_BISTSTS_LS6_DONE            0x4000U         // LS6 MPOST BIST is done
#define PBIST_BISTSTS_LS6_TEST               0x0U         // LS6 MPOST BIST is testing
#define PBIST_BISTSTS_LS7_DONE            0x8000U         // LS7 MPOST BIST is done
#define PBIST_BISTSTS_LS7_TEST               0x0U         // LS7 MPOST BIST is testing
#define PBIST_BISTSTS_GS0_DONE           0x10000U         // GS0 MPOST BIST is done
#define PBIST_BISTSTS_GS0_TEST               0x0U         // GS0 MPOST BIST is testing
#define PBIST_BISTSTS_BROM_DONE        0x1000000U         // BOOTROM MPOST BIST is done
#define PBIST_BISTSTS_BROM_TEST              0x0U         // BOOTROM MPOST BIST is testing
#define PBIST_BISTSTS_SROM_DONE        0x2000000U         // Secure ROM MPOST BIST is done
#define PBIST_BISTSTS_SROM_TEST              0x0U         // Secure ROM MPOST BIST is testing
#define PBIST_BISTSTS_CAN_SRAM_DONE    0x4000000U         // Secure ROM MPOST BIST is done
#define PBIST_BISTSTS_CAN_SRAM_TEST          0x0U         // Secure ROM MPOST BIST is testing
#define PBIST_BISTSTS_PIE_SRAM1_DONE   0x8000000U         // PIE SRAM1 MPOST BIST is done
#define PBIST_BISTSTS_PIE_SRAM1_TEST         0x0U         // PIE SRAM1 MPOST BIST is testing
#define PBIST_BISTSTS_PIE_SRAM2_DONE  0x10000000U         // PIE SRAM2 MPOST BIST is done
#define PBIST_BISTSTS_PIE_SRAM2_TEST         0x0U         // PIE SRAM2 MPOST BIST is testing

//*****************************************************************************
//
// The following are defines for the bit fields in the BISTRESULT register
//
//*****************************************************************************
#define PBIST_BISTRESULT_M0_DONE                0x1U         // M0 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_M0_FAIL                0x0U         // M0 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_M1_DONE                0x2U         // M1 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_M1_FAIL                0x0U         // M1 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_LS4_DONE            0x1000U         // LS4 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_LS4_FAIL               0x0U         // LS4 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_LS5_DONE            0x2000U         // LS5 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_LS5_FAIL               0x0U         // LS5 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_LS6_DONE            0x4000U         // LS6 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_LS6_FAIL               0x0U         // LS6 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_LS7_DONE            0x8000U         // LS7 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_LS7_FAIL               0x0U         // LS7 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_GS0_DONE           0x10000U         // GS0 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_GS0_FAIL               0x0U         // GS0 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_BROM_DONE        0x1000000U         // BOOTROM MPOST BIST RESULT is done
#define PBIST_BISTRESULT_BROM_FAIL              0x0U         // BOOTROM MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_SROM_DONE        0x2000000U         // Secure ROM MPOST BIST RESULT is done
#define PBIST_BISTRESULT_SROM_FAIL              0x0U         // Secure ROM MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_CAN_SRAM_DONE    0x4000000U         // Secure ROM MPOST BIST RESULT is done
#define PBIST_BISTRESULT_CAN_SRAM_FAIL          0x0U         // Secure ROM MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_PIE_SRAM1_DONE   0x8000000U         // PIE SRAM1 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_PIE_SRAM1_FAIL         0x0U         // PIE SRAM1 MPOST BIST RESULT is fail
#define PBIST_BISTRESULT_PIE_SRAM2_DONE  0x10000000U         // PIE SRAM2 MPOST BIST RESULT is done
#define PBIST_BISTRESULT_PIE_SRAM2_FAIL         0x0U         // PIE SRAM2 MPOST BIST RESULT is fail



//*****************************************************************************
//
// The following are defines for the bit fields in the BISTREN register
//
//*****************************************************************************
#define PBIST_BISTREN_ENABLE         0x1U         // PBIST RUN Enable


#endif
