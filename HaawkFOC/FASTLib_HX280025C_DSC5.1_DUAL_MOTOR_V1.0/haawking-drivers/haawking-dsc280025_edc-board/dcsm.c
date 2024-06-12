//###########################################################################
//
// FILE:   dcsm.c
//
// TITLE:  H28x Driver for the DCSM security module.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "dcsm.h"

//*****************************************************************************
//
// DCSM_unlockZone1CSM
//
//*****************************************************************************
void
DCSM_unlockZone1CSM(const DCSM_CSMPasswordKey * const psCMDKey)
{
    uint32_t linkPointer;
    uint32_t zsbBase = (DCSMBANK0_Z1OTP_BASE + 0x40); //base address of the ZSB
    int32_t bitPos = 28;
    int32_t zeroFound = 0;

    linkPointer = HWREG(DCSMBANK0_Z1_BASE + DCSM_O_B0_Z1_LINKPOINTER);

    //
    // Bits 31 and 30 as most-significant 0 are invalid LinkPointer options
    //
    linkPointer = linkPointer << 3;

    while((zeroFound == 0) && (bitPos > -1))
    {
        if( (linkPointer & 0x80000000U) == 0U)
        {
            zeroFound = 1;
            zsbBase = (DCSMBANK0_Z1OTP_BASE +
                      (((uint32_t)bitPos + 3U) * 0x20U));
        }
        else
        {
            bitPos--;
            linkPointer = linkPointer << 1;
        }
    }

    //
    // Perform dummy reads on the 128-bit password
    // Using linkPointer because it is no longer needed
    //
    linkPointer = HWREG(zsbBase + DCSM_O_Z1_CSMPSWD0);
    linkPointer = HWREG(zsbBase + DCSM_O_Z1_CSMPSWD1);
    linkPointer = HWREG(zsbBase + DCSM_O_Z1_CSMPSWD2);
    linkPointer = HWREG(zsbBase + DCSM_O_Z1_CSMPSWD3);

    HWREG(DCSMBANK0_Z1_BASE + DCSM_O_Z1_CSMKEY0) = psCMDKey->csmKey0;
    HWREG(DCSMBANK0_Z1_BASE + DCSM_O_Z1_CSMKEY1) = psCMDKey->csmKey1;
    HWREG(DCSMBANK0_Z1_BASE + DCSM_O_Z1_CSMKEY2) = psCMDKey->csmKey2;
    HWREG(DCSMBANK0_Z1_BASE + DCSM_O_Z1_CSMKEY3) = psCMDKey->csmKey3;
}

//*****************************************************************************
//
// DCSM_unlockZone2CSM
//
//*****************************************************************************
void
DCSM_unlockZone2CSM(const DCSM_CSMPasswordKey * const psCMDKey)
{
    uint32_t linkPointer;
    uint32_t zsbBase = (DCSMBANK0_Z2OTP_BASE + 0x40U); //base address of the ZSB
    int32_t bitPos = 28;
    int32_t zeroFound = 0;

    linkPointer = HWREG(DCSMBANK0_Z2_BASE + DCSM_O_B0_Z2_LINKPOINTER);

    //
    // Bits 31 and 30 as most-sigificant 0 are invalid LinkPointer options
    //
    linkPointer = linkPointer << 3;
    while((zeroFound == 0) && (bitPos > -1))
    {
        if( (linkPointer & 0x80000000U) == 0U)
        {
            zeroFound = 1;
            zsbBase = (DCSMBANK0_Z2OTP_BASE +
                      (((uint32_t)bitPos + 3U) * 0x20U));
        }
        else
        {
            bitPos--;
            linkPointer = linkPointer << 1;
        }
    }

    //
    // Perform dummy reads on the 128-bit password
    // Using linkPointer because it is no longer needed
    //
    linkPointer = HWREG(zsbBase + DCSM_O_Z2_CSMPSWD0);
    linkPointer = HWREG(zsbBase + DCSM_O_Z2_CSMPSWD1);
    linkPointer = HWREG(zsbBase + DCSM_O_Z2_CSMPSWD2);
    linkPointer = HWREG(zsbBase + DCSM_O_Z2_CSMPSWD3);

    HWREG(DCSMBANK0_Z2_BASE + DCSM_O_Z2_CSMKEY0) = psCMDKey->csmKey0;
    HWREG(DCSMBANK0_Z2_BASE + DCSM_O_Z2_CSMKEY1) = psCMDKey->csmKey1;
    HWREG(DCSMBANK0_Z2_BASE + DCSM_O_Z2_CSMKEY2) = psCMDKey->csmKey2;
    HWREG(DCSMBANK0_Z2_BASE + DCSM_O_Z2_CSMKEY3) = psCMDKey->csmKey3;
}

//*****************************************************************************
//
// DCSM_getZone1FlashEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone1FlashEXEStatus(DCSM_Sector sector)
{
    uint32_t regValue, statusBitShift;
    DCSM_EXEOnlyStatus status;

    //
    // Check if sector belongs to this zone
    //
    if(DCSM_getFlashSectorZone(sector) != DCSM_MEMORY_ZONE1)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status register for bank 0
        //
        regValue = HWREG(DCSMBANK0_Z1_BASE + DCSM_O_B0_Z1_EXEONLYSECTR);
        statusBitShift = (uint32_t)sector;

        //
        // Get the EXE status of the Flash Sector
        //
        status = (DCSM_EXEOnlyStatus)((uint32_t)((regValue >> statusBitShift) &
                                    (uint32_t)0x01U));
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_getZone1RAMEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone1RAMEXEStatus(DCSM_RAMModule module)
{
    DCSM_EXEOnlyStatus status;

    //
    // Check if module belongs to this zone
    //
    if(DCSM_getRAMZone(module) != DCSM_MEMORY_ZONE1)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status of the RAM Module
        //
        status = (DCSM_EXEOnlyStatus)((HWREG(DCSMBANK0_Z1_BASE +
               DCSM_O_Z1_EXEONLYRAMR) >> (uint32_t)module) & (uint32_t)0x01U);
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_getZone2FlashEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone2FlashEXEStatus(DCSM_Sector sector)
{
    uint32_t regValue, statusBitShift;
    DCSM_EXEOnlyStatus status;

    //
    // Check if sector belongs to this zone
    //
    if(DCSM_getFlashSectorZone(sector) != DCSM_MEMORY_ZONE2)
    {
        status = DCSM_INCORRECT_ZONE;
    }

    //
    // Get the EXE status register for the specific bank
    //
    else
    {
        regValue = HWREG(DCSMBANK0_Z2_BASE + DCSM_O_B0_Z2_EXEONLYSECTR);
        statusBitShift = (uint32_t)sector;

        //
        // Get the EXE status of the Flash Sector
        //
        status = (DCSM_EXEOnlyStatus)((regValue >> statusBitShift) &
                                (uint32_t)0x01U);
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_getZone2RAMEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone2RAMEXEStatus(DCSM_RAMModule module)
{
    DCSM_EXEOnlyStatus status;

    //
    // Check if module belongs to this zone
    //
    if(DCSM_getRAMZone(module) != DCSM_MEMORY_ZONE2)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status of the RAM Module
        //
        status = (DCSM_EXEOnlyStatus)((HWREG(DCSMBANK0_Z2_BASE +
               DCSM_O_Z2_EXEONLYRAMR) >> (uint32_t)module) & (uint32_t)0x01U);
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_claimZoneSemaphore
//
//*****************************************************************************
bool
DCSM_claimZoneSemaphore(DCSM_SemaphoreZone zone)
{
    //
    // FLSEM register address.
    //
    uint32_t regAddress = DCSMCOMMON_BASE + DCSM_O_FLSEM;

    EALLOW;

    //
    // Write 0xA5 to the key and write the zone that is attempting to claim the
    // Flash Pump Semaphore to the semaphore bits.
    //
    HWREG(regAddress) = ((uint32_t)FLSEM_KEY << DCSM_FLSEM_KEY_S) |
                         (uint32_t)zone;
    EDIS;

    //
    // If the calling function was unable to claim the zone semaphore, then
    // return false
    //
    return(((HWREG(regAddress) & DCSM_FLSEM_SEM_M) == (uint32_t)zone) ?
                true : false);
}

//*****************************************************************************
//
// DCSM_releaseZoneSemaphore
//
//*****************************************************************************
bool
DCSM_releaseZoneSemaphore(void)
{
    //
    // FLSEM register address.
    //
    uint32_t regAddress = DCSMCOMMON_BASE + DCSM_O_FLSEM;

    EALLOW;

    //
    // Write 0xA5 to the key and write the zone that is attempting to claim the
    // Flash Pump Semaphore to the semaphore bits.
    //
    HWREG(regAddress) = ((uint32_t)FLSEM_KEY << DCSM_FLSEM_KEY_S);
    EDIS;

    //
    // If the calling function was unable to release the zone semaphore, then
    // return false
    //
    return(((HWREG(regAddress) & DCSM_FLSEM_SEM_M) == 0x0U) ? true : false);
}

//*****************************************************************************
//
// DCSM_modifyZone1BlockConfig
//
//*****************************************************************************

uint32 DCSM_modifyZone1BlockConfig(uint32_t block,uint32_t * userOtpData)
{
     uint32_t * UserOtpAddr;
     uint32_t TempBuffer[8];
     uint32_t UserOtpbuffer[8];
     uint32_t status,status_temp;
     uint32_t i;

     ASSERT((block <= 29U) && (block >= 0U));

     UserOtpAddr = (uint32_t *)(0x7A0040 + block*0x20);
     for(i = 0;i < 8;i++)
     {
    	 UserOtpbuffer[i] = *(uint32_t *)((uint32_t *)0x7A07E0 + i);
     }
     (*  Fapi_initializeAPI)(160);
     status = (* UserOTP_Program)(UserOtpAddr,userOtpData,8,TempBuffer,1,NULL);
     status_temp = (* UserOTP_Program)((uint32_t *)0x7A07E0,UserOtpbuffer,8,TempBuffer,1,NULL);

     return ((status_temp<<16)|status);
}

//*****************************************************************************
//
// DCSM_modifyZone2BlockConfig
//
//*****************************************************************************

uint32 DCSM_modifyZone2BlockConfig(uint32_t block,uint32_t * userOtpData)
{
     uint32_t * UserOtpAddr;
     uint32_t TempBuffer[8];
     uint32_t UserOtpbuffer[8];
     uint32_t status,status_temp;
     uint32_t i;
     status = 0;
     ASSERT((block <= 29U) && (block >= 0U));

     (*  Fapi_initializeAPI)(160);
     UserOtpAddr = (uint32_t *)(0x7A0440 + block*0x20);
     if((block <= 28U) && (block >= 0U))
     {
        for(i = 0;i < 8;i++)
        {
    	 UserOtpbuffer[i] = *(uint32_t *)((uint32_t *)0x7A07E0 + i);
        }
        status = (* UserOTP_Program)(UserOtpAddr,userOtpData,8,TempBuffer,2,NULL);
        status_temp = (* UserOTP_Program)((uint32_t *)0x7A07E0,UserOtpbuffer,8,TempBuffer,2,NULL);
     }
     else
     {
         for(i = 0;i < 8;i++)
         {
     	   UserOtpbuffer[i] = (*(uint32_t *)((uint32_t *)0x7A07E0 + i)&userOtpData[i]);
         }
        status_temp = (* UserOTP_Program)((uint32_t *)0x7A07E0,UserOtpbuffer,8,TempBuffer,2,NULL);
     }

     return ((status_temp<<16)|status);
}
