//###########################################################################
//
// FILE:   memcfg.c
//
// TITLE:  H28x RAM config driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "memcfg.h"


#define MEMCFG_O_LSXACCPROT0       (MEMCFG_O_LSXACCPROT1 - 2U)

//*****************************************************************************
//
// MemCfg_lockConfig
//
//*****************************************************************************
void
MemCfg_lockConfig(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           (memSections == MEMCFG_SECT_ALL));

    //
    // Set the bit that blocks writes to the sections' configuration registers.
    //
    EALLOW;

    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXLOCK)  |= MEMCFG_SECT_NUM_MASK &
                                                     memSections;
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXLOCK) |= MEMCFG_SECT_NUM_MASK &
                                                     memSections;
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXLOCK) |= MEMCFG_SECT_NUM_MASK &
                                                     memSections;
            break;

        case MEMCFG_SECT_TYPE_MASK:
            //
            // Lock configuration for all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXLOCK)   |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_DX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXLOCK)  |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_LSX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXLOCK)  |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_GSX_ALL;
            break;

        default:
            //
            // Do nothing. Invalid memSections. Make sure you aren't OR-ing
            // values for two different types of memory sections.
            //
            break;
    }

    EDIS;
}

//*****************************************************************************
//
// MemCfg_unlockConfig
//
//*****************************************************************************
void
MemCfg_unlockConfig(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           (memSections == MEMCFG_SECT_ALL));

    //
    // Clear the bit that blocks writes to the sections' configuration
    // registers.
    //
    EALLOW;

    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXLOCK)  &= ~(MEMCFG_SECT_NUM_MASK &
                                                       memSections);
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXLOCK) &= ~(MEMCFG_SECT_NUM_MASK &
                                                       memSections);
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXLOCK) &= ~(MEMCFG_SECT_NUM_MASK &
                                                       memSections);
            break;


        case MEMCFG_SECT_TYPE_MASK:
            //
            // Unlock configuration for all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXLOCK) &=
                ~((uint32_t)(MEMCFG_SECT_NUM_MASK & MEMCFG_SECT_DX_ALL));
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXLOCK) &=
                ~((uint32_t)(MEMCFG_SECT_NUM_MASK & MEMCFG_SECT_LSX_ALL));
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXLOCK) &=
                ~((uint32_t)(MEMCFG_SECT_NUM_MASK & MEMCFG_SECT_GSX_ALL));
            break;

        default:
            //
            // Do nothing. Invalid memSections. Make sure you aren't OR-ing
            // values for two different types of memory sections.
            //
            break;
    }

    EDIS;
}

//*****************************************************************************
//
// MemCfg_commitConfig
//
//*****************************************************************************
void
MemCfg_commitConfig(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           (memSections == MEMCFG_SECT_ALL));

    //
    // Set the bit that permanently blocks writes to the sections'
    // configuration registers.
    //
    EALLOW;

    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXCOMMIT)  |= MEMCFG_SECT_NUM_MASK &
                                                       memSections;
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXCOMMIT) |= MEMCFG_SECT_NUM_MASK &
                                                       memSections;
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXCOMMIT) |= MEMCFG_SECT_NUM_MASK &
                                                       memSections;
            break;


        case MEMCFG_SECT_TYPE_MASK:
            //
            // Commit configuration for all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXCOMMIT)   |= MEMCFG_SECT_NUM_MASK &
                                                        MEMCFG_SECT_DX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXCOMMIT)  |= MEMCFG_SECT_NUM_MASK &
                                                        MEMCFG_SECT_LSX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXCOMMIT)  |= MEMCFG_SECT_NUM_MASK &
                                                        MEMCFG_SECT_GSX_ALL;
            break;

        default:
            //
            // Do nothing. Invalid memSections. Make sure you aren't OR-ing
            // values for two different types of RAM.
            //
            break;
    }

    EDIS;
}

//*****************************************************************************
//
// MemCfg_setProtection
//
//*****************************************************************************
void
MemCfg_setProtection(uint32_t memSection, uint32_t protectMode)
{
    uint32_t shiftVal = 0U;
    uint32_t maskVal;
    uint32_t regVal;
    uint32_t sectionNum;
    uint32_t regOffset;

    //
    // Check the arguments.
    //
    ASSERT(((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)   ||
           ((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS));

    //
    // Calculate how far the protect mode value needs to be shifted. Each
    // section number is represented by a bit in the lower word of memSection
    // and 8 bits in the corresponding ACCPROT register.
    //
    sectionNum = memSection & MEMCFG_SECT_NUM_MASK;

    while(sectionNum != 1U)
    {
        sectionNum = sectionNum >> 1U;
        shiftVal += 8U;
    }

    //
    // Calculate register offset. Also, make sure the shift value is no greater
    // than 31.
    //
    regOffset = (shiftVal & ~(0x1FU)) >> 3U;
    shiftVal &= 0x0001FU;
    maskVal = (uint32_t)MEMCFG_XACCPROTX_M << shiftVal;
    regVal = protectMode << shiftVal;

    //
    // Write the access protection mode into the appropriate field
    //
    EALLOW;

    switch(memSection & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXACCPROT0 + regOffset) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXACCPROT0 + regOffset) |= regVal;
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXACCPROT0 + regOffset) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXACCPROT0 + regOffset) |= regVal;
            break;


        default:
            //
            // Do nothing. Invalid memSection.
            //
            break;
    }

    EDIS;
}
//*****************************************************************************
//
// MemCfg_lockTestConfig
//
//*****************************************************************************
void
MemCfg_lockTestConfig(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_ROM) ||
           (memSections == MEMCFG_SECT_ALL));

    //
    // Set the bit that blocks writes to the sections' configuration registers.
    //
    EALLOW;

    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
             HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK)   |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_LS:
             HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK)   |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_GS:
             HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK)   |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_ROM:
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK)           |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            break;


        case MEMCFG_SECT_TYPE_MASK:
            //
            // Lock configuration for all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK)     |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK)    |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK)    |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK)           |=
                  (MEMCFG_TESTLOCK_KEY | (MEMCFG_SECT_NUM_MASK & memSections));
            break;

        default:
            //
            // Do nothing. Invalid ramSections. Make sure you aren't OR-ing
            // values for two different types of memory sections.
            //
            break;
    }

    EDIS;
}
//*****************************************************************************
//
// MemCfg_unlockTestConfig
//
//*****************************************************************************
void
MemCfg_unlockTestConfig(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           ((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_ROM) ||
           (memSections == MEMCFG_SECT_ALL));


    //
    // Clear the bit that blocks writes to the sections' configuration
    // registers.
    //
    EALLOW;

    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK) =
                               MEMCFG_TESTLOCK_KEY |
                               (HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK) &
                                ~(MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK) =
                               MEMCFG_TESTLOCK_KEY |
                               (HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK) &
                                ~(MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK) =
                               MEMCFG_TESTLOCK_KEY |
                               (HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK) &
                                ~(MEMCFG_SECT_NUM_MASK & memSections));
            break;

        case MEMCFG_SECT_TYPE_ROM:
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK) = (MEMCFG_TESTLOCK_KEY |
                                  (HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK) &
                                   ~(MEMCFG_SECT_NUM_MASK & memSections)));
            break;


        case MEMCFG_SECT_TYPE_MASK:
            //
            // Unlock configuration for all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK)   =
                 HWREG(MEMCFG_BASE + MEMCFG_O_DXRAMTEST_LOCK)   |
                 (MEMCFG_TESTLOCK_KEY | ~(MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK)  =
                 HWREG(MEMCFG_BASE + MEMCFG_O_LSXRAMTEST_LOCK)  |
                 (MEMCFG_TESTLOCK_KEY | ~(MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK)  =
                 HWREG(MEMCFG_BASE + MEMCFG_O_GSXRAMTEST_LOCK)  |
                 (MEMCFG_TESTLOCK_KEY | ~(MEMCFG_SECT_NUM_MASK & memSections));
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK)   =
                 HWREG(MEMCFG_BASE + MEMCFG_O_ROM_LOCK)   |
                 (MEMCFG_TESTLOCK_KEY | ~(MEMCFG_SECT_NUM_MASK & memSections));
            break;

        default:
            //
            // Do nothing. Invalid memSections. Make sure you aren't OR-ing
            // values for two different types of RAM.
            //
            break;
    }

    EDIS;

}
//*****************************************************************************
//
// MemCfg_setTestMode
//
//*****************************************************************************
void
MemCfg_setTestMode(uint32_t memSection, MemCfg_TestMode testMode)
{
    uint32_t shiftVal = 0U;
    uint32_t maskVal;
    uint32_t regVal;
    uint32_t sectionNum;

    //
    // Check the arguments.
    //
    ASSERT(((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)    ||
           ((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)   ||
           ((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)   ||
           ((memSection & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_ROM));

    //
    // Calculate how far the protect mode value needs to be shifted. Each
    // section number is represented by a bit in the lower word of memSection
    // and 2 bits in the corresponding TEST register.
    //
    sectionNum = memSection & MEMCFG_SECT_NUM_MASK;

    while(sectionNum != 1U)
    {
        sectionNum = sectionNum >> 1U;
        shiftVal += 2U;
    }

    maskVal = (uint32_t)MEMCFG_XTEST_M << shiftVal;
    regVal = (uint32_t)testMode << shiftVal;

    //
    // Write the test mode into the appropriate field
    //
    EALLOW;

    switch(memSection & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXTEST) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_DXTEST) |= regVal;
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXTEST) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXTEST) |= regVal;
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXTEST) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXTEST) |= regVal;
            break;

        case MEMCFG_SECT_TYPE_ROM:
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_TEST) &= ~maskVal;
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_TEST) |= regVal;
            break;

        default:
            //
            // Do nothing. Invalid memSection.
            //
            break;
    }

    EDIS;
}

//*****************************************************************************
//
// MemCfg_initSections
//
//*****************************************************************************
void
MemCfg_initSections(uint32_t ramSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           (ramSections == MEMCFG_SECT_ALL));

    //
    // Set the bit in the various initialization registers that starts
    // initialization.
    //
    EALLOW;

    switch(ramSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            HWREG(MEMCFG_BASE + MEMCFG_O_DXINIT)   |= MEMCFG_SECT_NUM_MASK &
                                                      ramSections;
            break;

        case MEMCFG_SECT_TYPE_LS:
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXINIT)  |= MEMCFG_SECT_NUM_MASK &
                                                      ramSections;
            break;

        case MEMCFG_SECT_TYPE_GS:
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXINIT)  |= MEMCFG_SECT_NUM_MASK &
                                                      ramSections;
            break;

        case MEMCFG_SECT_TYPE_MASK:
            //
            // Initialize all sections.
            //
            HWREG(MEMCFG_BASE + MEMCFG_O_DXINIT)   |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_DX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_LSXINIT)  |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_LSX_ALL;
            HWREG(MEMCFG_BASE + MEMCFG_O_GSXINIT)  |= MEMCFG_SECT_NUM_MASK &
                                                      MEMCFG_SECT_GSX_ALL;
            break;

        default:
            //
            // Do nothing. Invalid ramSections. Make sure you aren't OR-ing
            // values for two different types of RAM.
            //
            break;
    }

    EDIS;
}

//*****************************************************************************
//
// MemCfg_getInitStatus
//
//*****************************************************************************
bool
MemCfg_getInitStatus(uint32_t ramSections)
{
    uint32_t status;

    //
    // Check the arguments.
    //
    ASSERT(((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_D)   ||
           ((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_LS)  ||
           ((ramSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_GS)  ||
           (ramSections == MEMCFG_SECT_ALL));

    //
    // Read registers containing the initialization complete status.
    //
    switch(ramSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_D:
            status = HWREG(MEMCFG_BASE + MEMCFG_O_DXINITDONE);
            break;

        case MEMCFG_SECT_TYPE_LS:
            status = HWREG(MEMCFG_BASE + MEMCFG_O_LSXINITDONE);
            break;

        case MEMCFG_SECT_TYPE_GS:
            status = HWREG(MEMCFG_BASE + MEMCFG_O_GSXINITDONE);
            break;

        case MEMCFG_SECT_TYPE_MASK:
            //
            // Return the overall status.
            //
            if((HWREG(MEMCFG_BASE + MEMCFG_O_DXINITDONE) ==
                MEMCFG_SECT_DX_ALL) &&
               (HWREG(MEMCFG_BASE + MEMCFG_O_LSXINITDONE) ==
                MEMCFG_SECT_LSX_ALL) &&
               (HWREG(MEMCFG_BASE + MEMCFG_O_GSXINITDONE) ==
                MEMCFG_SECT_GSX_ALL))
            {
                status = MEMCFG_SECT_NUM_MASK;
            }
            else
            {
                status = 0U;
            }
            break;

        default:
            //
            // Invalid ramSections. Make sure you aren't OR-ing values for two
            // different types of RAM.
            //
            status = 0U;
            break;
    }

    return((ramSections & status) == (ramSections & MEMCFG_SECT_NUM_MASK));
}

//*****************************************************************************
//
// MemCfg_getViolationAddress
//
//*****************************************************************************
uint32_t
MemCfg_getViolationAddress(uint32_t intFlag)
{
    uint32_t address = 0;

    //
    // Calculate the the address of the desired violation address register.
    //
    if((intFlag & MEMCFG_MVIOL_MASK) != 0U)
    {
        address = ACCESSPROTECTION_BASE + MEMCFG_O_MCPUFAVADDR;
    }

    //
    // Read and return the access violation address at the calculated location.
    //
    return(HWREG(address));
}

//*****************************************************************************
//
// MemCfg_getCorrErrorAddress
//
//*****************************************************************************
uint32_t
MemCfg_getCorrErrorAddress(uint32_t stsFlag)
{
    //
    // Check the arguments.
    //
    if(stsFlag != MEMCFG_CERR_CPUREAD)
    {
        //
        // Currently, the only correctable error address that can be read
        // from a register is one for a CPU read error (MEMCFG_CERR_CPUREAD).
        // For the sake of keeping this function portable to possible future
        // devices with other error types, it still takes a stsFlag parameter.
        //
        ASSERT(false);
    }

    //
    // Read and return the error address.
    //
    return(HWREG(MEMORYERROR_BASE + MEMCFG_O_CCPUREADDR));
}

//*****************************************************************************
//
// MemCfg_getUncorrErrorAddress
//
//*****************************************************************************
uint32_t
MemCfg_getUncorrErrorAddress(uint32_t stsFlag)
{
    uint32_t address;
    uint32_t temp;

    //
    // Calculate the the address of the desired error address register.
    //
    address = MEMORYERROR_BASE + MEMCFG_O_UCCPUREADDR;

    temp = stsFlag;

    while(temp > 1U)
    {
        temp = temp >> 1U;
        address += (uint32_t)(MEMCFG_O_UCDMAREADDR - MEMCFG_O_UCCPUREADDR);
    }

    //
    // Read and return the error address at the calculated location.
    //
    return(HWREG(address));
}

//*****************************************************************************
//
// MemCfg_forceMemError
//
//*****************************************************************************
void
MemCfg_forceMemError(uint32_t memSections)
{
    //
    // Check the arguments.
    //
    ASSERT(((memSections & MEMCFG_SECT_TYPE_MASK) == MEMCFG_SECT_TYPE_ROM) ||
           (memSections == MEMCFG_SECT_ALL));

    //
    // Forces error in the selected memory.
    //
    switch(memSections & MEMCFG_SECT_TYPE_MASK)
    {
        case MEMCFG_SECT_TYPE_ROM:
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_FORCE_ERROR)       |=
                                          (MEMCFG_SECT_NUM_MASK & memSections);
            break;

        case MEMCFG_SECT_TYPE_MASK:
            HWREG(MEMCFG_BASE + MEMCFG_O_ROM_FORCE_ERROR)       |=
                                          (MEMCFG_SECT_NUM_MASK & memSections);
            break;

        default:
            //
            // Do nothing. Invalid memory.
            //
            break;
    }
}
