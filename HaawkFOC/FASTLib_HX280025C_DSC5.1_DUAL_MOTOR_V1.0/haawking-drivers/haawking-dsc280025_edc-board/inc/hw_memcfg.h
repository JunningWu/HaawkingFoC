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
// Release for HXS320F280025CEDC, Hal DriverLib, 1.0.0
//
// Release time: 2024-01-25 15:09:27.423271
//
//#############################################################################


#ifndef HW_MEMCFG_H
#define HW_MEMCFG_H

//*************************************************************************************************
//
// The following are defines for the MEMCFG register offsets
//
//*************************************************************************************************
#define MEMCFG_O_DXLOCK            0x0U    // Dedicated RAM Config Lock Register
#define MEMCFG_O_DXCOMMIT          0x4U    // Dedicated RAM Config Lock Commit Register
#define MEMCFG_O_DXTEST            0x8U    // Dedicated RAM TEST Register
#define MEMCFG_O_DXINIT            0xCU    // Dedicated RAM Init Register
#define MEMCFG_O_DXINITDONE        0x10U   // Dedicated RAM InitDone Status Register
#define MEMCFG_O_DXRAMTEST_LOCK    0x14U   // Lock register to Dx RAM TEST registers
#define MEMCFG_O_LSXLOCK           0x18U   // Local Shared RAM Config Lock Register
#define MEMCFG_O_LSXCOMMIT         0x1CU   // Local Shared RAM Config Lock Commit Register
#define MEMCFG_O_LSXACCPROT1       0x20U   // Local Shared RAM Config Register 1
#define MEMCFG_O_LSXTEST           0x24U   // Local Shared RAM TEST Register
#define MEMCFG_O_LSXINIT           0x28U   // Local Shared RAM Init Register
#define MEMCFG_O_LSXINITDONE       0x2CU   // Local Shared RAM InitDone Status Register
#define MEMCFG_O_LSXRAMTEST_LOCK   0x30U   // Lock register to LSx RAM TEST registers
#define MEMCFG_O_GSXLOCK           0x34U   // Global Shared RAM Config Lock Register
#define MEMCFG_O_GSXCOMMIT         0x38U   // Global Shared RAM Config Lock Commit Register
#define MEMCFG_O_GSXACCPROT0       0x3CU   // Global Shared RAM Config Register 0
#define MEMCFG_O_GSXTEST           0x40U   // Global Shared RAM TEST Register
#define MEMCFG_O_GSXINIT           0x44U   // Global Shared RAM Init Register
#define MEMCFG_O_GSXINITDONE       0x48U   // Global Shared RAM InitDone Status Register
#define MEMCFG_O_GSXRAMTEST_LOCK   0x4CU   // Lock register to GSx RAM TEST registers
#define MEMCFG_O_ROM_LOCK          0x50U   // ROM Config Lock Register
#define MEMCFG_O_ROM_TEST          0x54U   // ROM TEST Register
#define MEMCFG_O_ROM_FORCE_ERROR   0x58U   // ROM Force Error register

#define MEMCFG_O_MAVFLG          0x0U    // Master Access Violation Flag Register
#define MEMCFG_O_MAVSET          0x4U    // Master Access Violation Flag Set Register
#define MEMCFG_O_MAVCLR          0x8U    // Master Access Violation Flag Clear Register
#define MEMCFG_O_MAVINTEN        0xCU    // Master Access Violation Interrupt Enable Register
#define MEMCFG_O_MCPUFAVADDR     0x10U   // Master CPU Fetch Access Violation Address
#define MEMCFG_O_MCPUWRAVADDR    0x14U   // Master CPU Write Access Violation Address
#define MEMCFG_O_MDMAWRAVADDR    0x18U   // Master DMA Write Access Violation Address
#define MEMCFG_O_MHICWRAVADDR    0x1CU   // Master HIC Write Access Violation Address
#define MEMCFG_O_NMHICRDAVADDR   0x20U   // Non-Master HIC Read Access Violation Address
#define MEMCFG_O_NMHICWRAVADDR   0x24U   // Non-Master HIC Write Access Violation Address
#define MEMCFG_O_NMAVFLG         0x30U   // Non-Master Access Violation Flag Register
#define MEMCFG_O_NMAVSET         0x34U   // Non-Master Access Violation Flag Set Register
#define MEMCFG_O_NMAVCLR         0x38U   // Non-Master Access Violation Flag Clear Register
#define MEMCFG_O_NMAVINTEN       0x3CU   // Non-Master Access Violation Interrupt Enable Register
#define MEMCFG_O_NMCPURDAVADDR   0x40U   // Non-Master CPU Read Access Violation Address
#define MEMCFG_O_NMCPUWRAVADDR   0x44U   // Non-Master CPU Write Access Violation Address
#define MEMCFG_O_NMCPUFAVADDR    0x48U   // Non-Master CPU Fetch Access Violation Address
#define MEMCFG_O_NMDMARDAVADDR   0x4CU   // Non-Master DMA Read Access Violation Address

#define MEMCFG_O_UCERRFLG       0x0U    // Uncorrectable Error Flag Register
#define MEMCFG_O_UCERRSET       0x4U    // Uncorrectable Error Flag Set Register
#define MEMCFG_O_UCERRCLR       0x8U    // Uncorrectable Error Flag Clear Register
#define MEMCFG_O_UCCPUREADDR    0xCU    // Uncorrectable CPU Read Error Address
#define MEMCFG_O_UCDMAREADDR    0x10U   // Uncorrectable DMA Read Error Address
#define MEMCFG_O_UCHICAREADDR   0x14U   // Uncorrectable HICA Read Error Address
#define MEMCFG_O_CERRFLG        0x18U   // Correctable Error Flag Register
#define MEMCFG_O_CERRSET        0x1CU   // Correctable Error Flag Set Register
#define MEMCFG_O_CERRCLR        0x20U   // Correctable Error Flag Clear Register
#define MEMCFG_O_CCPUREADDR     0x24U   // Correctable CPU Read Error Address
#define MEMCFG_O_CERRCNT        0x28U   // Correctable Error Count Register
#define MEMCFG_O_CERRTHRES      0x2CU   // Correctable Error Threshold Value Register
#define MEMCFG_O_CEINTFLG       0x30U   // Correctable Error Interrupt Flag Status Register
#define MEMCFG_O_CEINTCLR       0x34U   // Correctable Error Interrupt Flag Clear Register
#define MEMCFG_O_CEINTSET       0x38U   // Correctable Error Interrupt Flag Set Register
#define MEMCFG_O_CEINTEN        0x3CU   // Correctable Error Interrupt Enable Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the DxLOCK register
//
//*************************************************************************************************
#define MEMCFG_DXLOCK_LOCK_M0   0x1U   // M0 RAM Lock bits
#define MEMCFG_DXLOCK_LOCK_M1   0x2U   // M1 RAM Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the DxCOMMIT register
//
//*************************************************************************************************
#define MEMCFG_DXCOMMIT_COMMIT_M0   0x1U   // M0 RAM Permanent Lock bits
#define MEMCFG_DXCOMMIT_COMMIT_M1   0x2U   // M1 RAM Permanent Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the DxTEST register
//
//*************************************************************************************************
#define MEMCFG_DXTEST_TEST_M0_S   0U
#define MEMCFG_DXTEST_TEST_M0_M   0x3U   // Selects the different modes for M0 RAM
#define MEMCFG_DXTEST_TEST_M1_S   2U
#define MEMCFG_DXTEST_TEST_M1_M   0xCU   // Selects the different modes for M1 RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the DxINIT register
//
//*************************************************************************************************
#define MEMCFG_DXINIT_INIT_M0   0x1U   // RAM Initialization control for M0 RAM.
#define MEMCFG_DXINIT_INIT_M1   0x2U   // RAM Initialization control for M1 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the DxINITDONE register
//
//*************************************************************************************************
#define MEMCFG_DXINITDONE_INITDONE_M0   0x1U   // RAM Initialization status for M0 RAM.
#define MEMCFG_DXINITDONE_INITDONE_M1   0x2U   // RAM Initialization status for M1 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the DxRAMTEST_LOCK register
//
//*************************************************************************************************
#define MEMCFG_DXRAMTEST_LOCK_M0      0x1U          // DxTEST.TEST_M0 LOCK
#define MEMCFG_DXRAMTEST_LOCK_M1      0x2U          // DxTEST.TEST_M1 LOCK
#define MEMCFG_DXRAMTEST_LOCK_KEY_S   16U
#define MEMCFG_DXRAMTEST_LOCK_KEY_M   0xFFFF0000U   // Key for writing DxRAMTEST_LOCK

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxLOCK register
//
//*************************************************************************************************
#define MEMCFG_LSXLOCK_LOCK_LS4   0x10U   // LS4 RAM Lock bits
#define MEMCFG_LSXLOCK_LOCK_LS5   0x20U   // LS5 RAM Lock bits
#define MEMCFG_LSXLOCK_LOCK_LS6   0x40U   // LS6 RAM Lock bits
#define MEMCFG_LSXLOCK_LOCK_LS7   0x80U   // LS7 RAM Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxCOMMIT register
//
//*************************************************************************************************
#define MEMCFG_LSXCOMMIT_COMMIT_LS4   0x10U   // LS4 RAM Permanent Lock bits
#define MEMCFG_LSXCOMMIT_COMMIT_LS5   0x20U   // LS5 RAM Permanent Lock bits
#define MEMCFG_LSXCOMMIT_COMMIT_LS6   0x40U   // LS6 RAM Permanent Lock bits
#define MEMCFG_LSXCOMMIT_COMMIT_LS7   0x80U   // LS7 RAM Permanent Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxACCPROT1 register
//
//*************************************************************************************************
#define MEMCFG_LSXACCPROT1_FETCHPROT_LS4   0x1U         // Fetch Protection For LS4 RAM
#define MEMCFG_LSXACCPROT1_CPUWRPROT_LS4   0x2U         // CPU WR Protection For LS4 RAM
#define MEMCFG_LSXACCPROT1_FETCHPROT_LS5   0x100U       // Fetch Protection For LS5 RAM
#define MEMCFG_LSXACCPROT1_CPUWRPROT_LS5   0x200U       // CPU WR Protection For LS5 RAM
#define MEMCFG_LSXACCPROT1_FETCHPROT_LS6   0x10000U     // Fetch Protection For LS6 RAM
#define MEMCFG_LSXACCPROT1_CPUWRPROT_LS6   0x20000U     // CPU WR Protection For LS6 RAM
#define MEMCFG_LSXACCPROT1_FETCHPROT_LS7   0x1000000U   // Fetch Protection For LS7 RAM
#define MEMCFG_LSXACCPROT1_CPUWRPROT_LS7   0x2000000U   // CPU WR Protection For LS7 RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxTEST register
//
//*************************************************************************************************
#define MEMCFG_LSXTEST_TEST_LS4_S   8U
#define MEMCFG_LSXTEST_TEST_LS4_M   0x300U    // Selects the different modes for LS4 RAM
#define MEMCFG_LSXTEST_TEST_LS5_S   10U
#define MEMCFG_LSXTEST_TEST_LS5_M   0xC00U    // Selects the different modes for LS5 RAM
#define MEMCFG_LSXTEST_TEST_LS6_S   12U
#define MEMCFG_LSXTEST_TEST_LS6_M   0x3000U   // Selects the different modes for LS6 RAM
#define MEMCFG_LSXTEST_TEST_LS7_S   14U
#define MEMCFG_LSXTEST_TEST_LS7_M   0xC000U   // Selects the different modes for LS7 RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxINIT register
//
//*************************************************************************************************
#define MEMCFG_LSXINIT_INIT_LS4   0x10U   // RAM Initialization control for LS4 RAM.
#define MEMCFG_LSXINIT_INIT_LS5   0x20U   // RAM Initialization control for LS5 RAM.
#define MEMCFG_LSXINIT_INIT_LS6   0x40U   // RAM Initialization control for LS6 RAM.
#define MEMCFG_LSXINIT_INIT_LS7   0x80U   // RAM Initialization control for LS7 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxINITDONE register
//
//*************************************************************************************************
#define MEMCFG_LSXINITDONE_INITDONE_LS4   0x10U   // RAM Initialization status for LS4 RAM.
#define MEMCFG_LSXINITDONE_INITDONE_LS5   0x20U   // RAM Initialization status for LS5 RAM.
#define MEMCFG_LSXINITDONE_INITDONE_LS6   0x40U   // RAM Initialization status for LS6 RAM.
#define MEMCFG_LSXINITDONE_INITDONE_LS7   0x80U   // RAM Initialization status for LS7 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSxRAMTEST_LOCK register
//
//*************************************************************************************************
#define MEMCFG_LSXRAMTEST_LOCK_LS4     0x10U         // LSxTEST.TEST_LS4 LOCK
#define MEMCFG_LSXRAMTEST_LOCK_LS5     0x20U         // LSxTEST.TEST_LS5 LOCK
#define MEMCFG_LSXRAMTEST_LOCK_LS6     0x40U         // LSxTEST.TEST_LS6 LOCK
#define MEMCFG_LSXRAMTEST_LOCK_LS7     0x80U         // LSxTEST.TEST_LS7 LOCK
#define MEMCFG_LSXRAMTEST_LOCK_KEY_S   16U
#define MEMCFG_LSXRAMTEST_LOCK_KEY_M   0xFFFF0000U   // KEY to enable write to lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxLOCK register
//
//*************************************************************************************************
#define MEMCFG_GSXLOCK_LOCK_GS0   0x1U   // GS0 RAM Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxCOMMIT register
//
//*************************************************************************************************
#define MEMCFG_GSXCOMMIT_COMMIT_GS0   0x1U   // GS0 RAM Permanent Lock bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxACCPROT0 register
//
//*************************************************************************************************
#define MEMCFG_GSXACCPROT0_FETCHPROT_GS0   0x1U   // Fetch Protection For GS0 RAM
#define MEMCFG_GSXACCPROT0_CPUWRPROT_GS0   0x2U   // CPU WR Protection For GS0 RAM
#define MEMCFG_GSXACCPROT0_DMAWRPROT_GS0   0x4U   // DMA WR Protection For GS0 RAM
#define MEMCFG_GSXACCPROT0_HICWRPROT_GS0   0x8U   // HIC WR Protection For GS0 RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxTEST register
//
//*************************************************************************************************
#define MEMCFG_GSXTEST_TEST_GS0_S   0U
#define MEMCFG_GSXTEST_TEST_GS0_M   0x3U   // Selects the different modes for GS0 RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxINIT register
//
//*************************************************************************************************
#define MEMCFG_GSXINIT_INIT_GS0   0x1U   // RAM Initialization control for GS0 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxINITDONE register
//
//*************************************************************************************************
#define MEMCFG_GSXINITDONE_INITDONE_GS0   0x1U   // RAM Initialization status for GS0 RAM.

//*************************************************************************************************
//
// The following are defines for the bit fields in the GSxRAMTEST_LOCK register
//
//*************************************************************************************************
#define MEMCFG_GSXRAMTEST_LOCK_GS0     0x1U          // GSxTEST.TEST_GS0 LOCK
#define MEMCFG_GSXRAMTEST_LOCK_KEY_S   16U
#define MEMCFG_GSXRAMTEST_LOCK_KEY_M   0xFFFF0000U   // KEY to enable write to lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the ROM_LOCK register
//
//*************************************************************************************************
#define MEMCFG_ROM_LOCK_LOCK_BOOTROM     0x1U          // BOOTROM Lock bits
#define MEMCFG_ROM_LOCK_LOCK_SECUREROM   0x2U          // SECUREROM Lock bits
#define MEMCFG_ROM_LOCK_KEY_S            16U
#define MEMCFG_ROM_LOCK_KEY_M            0xFFFF0000U   // Key for writing ROM LOCK

//*************************************************************************************************
//
// The following are defines for the bit fields in the ROM_TEST register
//
//*************************************************************************************************
#define MEMCFG_ROM_TEST_TEST_BOOTROM_S     0U
#define MEMCFG_ROM_TEST_TEST_BOOTROM_M     0x3U   // Selects the different modes for BOOTROM
#define MEMCFG_ROM_TEST_TEST_SECUREROM_S   2U
#define MEMCFG_ROM_TEST_TEST_SECUREROM_M   0xCU   // Selects the different modes for SECUREROM

//*************************************************************************************************
//
// The following are defines for the bit fields in the ROM_FORCE_ERROR register
//
//*************************************************************************************************
#define MEMCFG_ROM_FORCE_ERROR_FORCE_BOOTROM_ERROR     0x1U   // Force Bootrom Parity Error
#define MEMCFG_ROM_FORCE_ERROR_FORCE_SECUREROM_ERROR   0x2U   // Force SECUREROM Parity Error

//*************************************************************************************************
//
// The following are defines for the bit fields in the MAVFLG register
//
//*************************************************************************************************
#define MEMCFG_MAVFLG_CPUFETCH    0x1U   // Master CPU Fetch Access Violation Flag
#define MEMCFG_MAVFLG_CPUWRITE    0x2U   // Master CPU Write Access Violation Flag
#define MEMCFG_MAVFLG_DMAWRITE    0x4U   // Master DMA Write Access Violation Flag
#define MEMCFG_MAVFLG_HICAWRITE   0x8U   // Master HICA Write Access Violation Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the MAVSET register
//
//*************************************************************************************************
#define MEMCFG_MAVSET_CPUFETCH    0x1U   // Master CPU Fetch Access Violation Flag Set
#define MEMCFG_MAVSET_CPUWRITE    0x2U   // Master CPU Write Access Violation Flag Set
#define MEMCFG_MAVSET_DMAWRITE    0x4U   // Master DMA Write Access Violation Flag Set
#define MEMCFG_MAVSET_HICAWRITE   0x8U   // Master HICA Write Access Violation Flag Set

//*************************************************************************************************
//
// The following are defines for the bit fields in the MAVCLR register
//
//*************************************************************************************************
#define MEMCFG_MAVCLR_CPUFETCH    0x1U   // Master CPU Fetch Access Violation Flag Clear
#define MEMCFG_MAVCLR_CPUWRITE    0x2U   // Master CPU Write Access Violation Flag Clear
#define MEMCFG_MAVCLR_DMAWRITE    0x4U   // Master DMA Write Access Violation Flag Clear
#define MEMCFG_MAVCLR_HICAWRITE   0x8U   // Master HICA Write Access Violation Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the MAVINTEN register
//
//*************************************************************************************************
#define MEMCFG_MAVINTEN_CPUFETCH    0x1U   // Master CPU Fetch Access Violation Interrupt Enable
#define MEMCFG_MAVINTEN_CPUWRITE    0x2U   // Master CPU Write Access Violation Interrupt Enable
#define MEMCFG_MAVINTEN_DMAWRITE    0x4U   // Master DMA Write Access Violation Interrupt Enable
#define MEMCFG_MAVINTEN_HICAWRITE   0x8U   // Master HICA Write Access Violation Interrupt Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMAVFLG register
//
//*************************************************************************************************
#define MEMCFG_NMAVFLG_CPUREAD    0x1U      // Non Master CPU Read Access Violation Flag
#define MEMCFG_NMAVFLG_CPUWRITE   0x2U      // Non Master CPU Write Access Violation Flag
#define MEMCFG_NMAVFLG_CPUFETCH   0x4U      // Non Master CPU Fetch Access Violation Flag
#define MEMCFG_NMAVFLG_DMAWRITE   0x8U      // Non Master DMA Write Access Violation Flag
#define MEMCFG_NMAVFLG_DMAREAD    0x400U    // Non Master DMA Read Access Violation Flag
#define MEMCFG_NMAVFLG_HICREAD    0x800U    // Non Master HIC Read Access Violation Flag
#define MEMCFG_NMAVFLG_HICWRITE   0x1000U   // Non Master HIC Write Access Violation Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMAVSET register
//
//*************************************************************************************************
#define MEMCFG_NMAVSET_CPUREAD    0x1U      // Non Master CPU Read Access Violation Flag Set
#define MEMCFG_NMAVSET_CPUWRITE   0x2U      // Non Master CPU Write Access Violation Flag Set
#define MEMCFG_NMAVSET_CPUFETCH   0x4U      // Non Master CPU Fetch Access Violation Flag Set
#define MEMCFG_NMAVSET_DMAWRITE   0x8U      // Non Master DMA Write Access Violation Flag Set
#define MEMCFG_NMAVSET_DMAREAD    0x400U    // Non Master DMA Read Access Violation Flag Set
#define MEMCFG_NMAVSET_HICREAD    0x800U    // Non Master HIC Read Access Violation Flag Set
#define MEMCFG_NMAVSET_HICWRITE   0x1000U   // Non Master HIC Write Access Violation Flag Set

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMAVCLR register
//
//*************************************************************************************************
#define MEMCFG_NMAVCLR_CPUREAD    0x1U      // Non Master CPU Read Access Violation Flag Clear
#define MEMCFG_NMAVCLR_CPUWRITE   0x2U      // Non Master CPU Write Access Violation Flag Clear
#define MEMCFG_NMAVCLR_CPUFETCH   0x4U      // Non Master CPU Fetch Access Violation Flag Clear
#define MEMCFG_NMAVCLR_DMAWRITE   0x8U      // Non Master DMA Write Access Violation Flag Clear
#define MEMCFG_NMAVCLR_DMAREAD    0x400U    // Non Master DMA Read Access Violation Flag Clear
#define MEMCFG_NMAVCLR_HICREAD    0x800U    // Non Master HIC Read Access Violation Flag Clear
#define MEMCFG_NMAVCLR_HICWRITE   0x1000U   // Non Master HIC Write Access Violation Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMAVINTEN register
//
//*************************************************************************************************
#define MEMCFG_NMAVINTEN_CPUREAD    0x1U      // Non Master CPU Read Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_CPUWRITE   0x2U      // Non Master CPU Write Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_CPUFETCH   0x4U      // Non Master CPU Fetch Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_DMAWRITE   0x8U      // Non Master DMA Write Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_DMAREAD    0x400U    // Non Master DMA Read Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_HICREAD    0x800U    // Non Master HIC Read Access Violation Interrupt Enable
#define MEMCFG_NMAVINTEN_HICWRITE   0x1000U   // Non Master HIC Write Access Violation Interrupt Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the UCERRFLG register
//
//*************************************************************************************************
#define MEMCFG_UCERRFLG_CPURDERR    0x1U    // CPU Uncorrectable Read Error Flag
#define MEMCFG_UCERRFLG_DMARDERR    0x2U    // DMA Uncorrectable Read Error Flag
#define MEMCFG_UCERRFLG_HICARDERR   0x20U   // HICA Uncorrectable Read Error Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the UCERRSET register
//
//*************************************************************************************************
#define MEMCFG_UCERRSET_CPURDERR    0x1U    // CPU Uncorrectable Read Error Flag Set
#define MEMCFG_UCERRSET_DMARDERR    0x2U    // DMA Uncorrectable Read Error Flag Set
#define MEMCFG_UCERRSET_HICARDERR   0x20U   // HICA Uncorrectable Read Error Flag Set

//*************************************************************************************************
//
// The following are defines for the bit fields in the UCERRCLR register
//
//*************************************************************************************************
#define MEMCFG_UCERRCLR_CPURDERR    0x1U    // CPU Uncorrectable Read Error Flag Clear
#define MEMCFG_UCERRCLR_DMARDERR    0x2U    // DMA Uncorrectable Read Error Flag Clear
#define MEMCFG_UCERRCLR_HICARDERR   0x20U   // HICA Uncorrectable Read Error Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the CERRFLG register
//
//*************************************************************************************************
#define MEMCFG_CERRFLG_CPURDERR   0x1U   // CPU Correctable Read Error Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CERRSET register
//
//*************************************************************************************************
#define MEMCFG_CERRSET_CPURDERR   0x1U   // CPU Correctable Read Error Flag Set

//*************************************************************************************************
//
// The following are defines for the bit fields in the CERRCLR register
//
//*************************************************************************************************
#define MEMCFG_CERRCLR_CPURDERR   0x1U   // CPU Correctable Read Error Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the CERRTHRES register
//
//*************************************************************************************************
#define MEMCFG_CERRTHRES_CERRTHRES_S   0U
#define MEMCFG_CERRTHRES_CERRTHRES_M   0xFFFFU   // Correctable error threshold.

//*************************************************************************************************
//
// The following are defines for the bit fields in the CEINTFLG register
//
//*************************************************************************************************
#define MEMCFG_CEINTFLG_CEINTFLAG   0x1U   // Total corrected error count exceeded threshold flag.

//*************************************************************************************************
//
// The following are defines for the bit fields in the CEINTCLR register
//
//*************************************************************************************************
#define MEMCFG_CEINTCLR_CEINTCLR   0x1U   // CPU Corrected Error Threshold Exceeded Error Clear.

//*************************************************************************************************
//
// The following are defines for the bit fields in the CEINTSET register
//
//*************************************************************************************************
#define MEMCFG_CEINTSET_CEINTSET   0x1U   // Total corrected error count exceeded flag set.

//*************************************************************************************************
//
// The following are defines for the bit fields in the CEINTEN register
//
//*************************************************************************************************
#define MEMCFG_CEINTEN_CEINTEN   0x1U   // CPU/DMA Correctable Error Interrupt Enable.



#endif
