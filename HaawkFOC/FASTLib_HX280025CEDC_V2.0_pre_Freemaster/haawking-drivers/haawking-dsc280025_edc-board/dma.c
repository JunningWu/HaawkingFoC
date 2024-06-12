//###########################################################################
//
// FILE:   dma.c
//
// TITLE:  H28x DMA driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "dma.h"

//*****************************************************************************
//
// DMA_configAddresses
//
//*****************************************************************************
void DMA_configAddresses(uint32_t base, const void *destAddr,
                         const void *srcAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));

    EALLOW;

    //
    // Set up SOURCE address.
    //
    HWREG(base + DMA_O_SRC_BEG_ADDR_SHADOW) = (uint32_t)srcAddr;
    HWREG(base + DMA_O_SRC_ADDR_SHADOW)     = (uint32_t)srcAddr;

    //
    // Set up DESTINATION address.
    //
    HWREG(base + DMA_O_DST_BEG_ADDR_SHADOW) = (uint32_t)destAddr;
    HWREG(base + DMA_O_DST_ADDR_SHADOW)     = (uint32_t)destAddr;

    EDIS;
}

//*****************************************************************************
//
// DMA_configBurst
//
//*****************************************************************************
void DMA_configBurst(uint32_t base, uint32_t size, int32_t srcStep,
                     int16_t destStep)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));
    ASSERT((size >= 1U) && (size <= 32U));
    ASSERT(((srcStep >= -4096) && (srcStep <= 4095)) &&
                  ((destStep >= -4096) && (destStep <= 4095)));

    EALLOW;

    //
    // Set up BURST registers.
    //
    HWREG(base + DMA_O_BURST_SIZE)     = size - 1U;
    HWREG(base + DMA_O_SRC_BURST_STEP) = srcStep;
    HWREG(base + DMA_O_DST_BURST_STEP) = destStep;

    EDIS;
}

//*****************************************************************************
//
// DMA_configTransfer
//
//*****************************************************************************
void DMA_configTransfer(uint32_t base, uint32_t transferSize, int16_t srcStep,
                        int16_t destStep)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));
    ASSERT(transferSize <= 0x10000U);
    ASSERT(((srcStep >= -4096) && (srcStep <= 4095)) &&
                  ((destStep >= -4096) && (destStep <= 4095)));

    EALLOW;

    //
    // Set up TRANSFER registers.
    //
    HWREG(base + DMA_O_TRANSFER_SIZE)     = (uint32_t)(transferSize - 1U);
    HWREG(base + DMA_O_SRC_TRANSFER_STEP) = srcStep;
    HWREG(base + DMA_O_DST_TRANSFER_STEP) = destStep;

    EDIS;
}

//*****************************************************************************
//
// DMA_configWrap
//
//*****************************************************************************
void DMA_configWrap(uint32_t base, uint32_t srcWrapSize, int16_t srcStep,
                    uint32_t destWrapSize, int16_t destStep)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));
    ASSERT((srcWrapSize <= 0x10000U) || (destWrapSize <= 0x10000U));
    ASSERT(((srcStep >= -4096) && (srcStep <= 4095)) &&
                  ((destStep >= -4096) && (destStep <= 4095)));

    EALLOW;

    //
    // Set up WRAP registers.
    //
    HWREG(base + DMA_O_SRC_WRAP_SIZE) = (uint32_t)(srcWrapSize - 1U);
    HWREG(base + DMA_O_SRC_WRAP_STEP) = srcStep;

    HWREG(base + DMA_O_DST_WRAP_SIZE) = (uint32_t)(destWrapSize - 1U);
    HWREG(base + DMA_O_DST_WRAP_STEP) = destStep;

    EDIS;
}

//*****************************************************************************
//
// DMA_configMode
//
//*****************************************************************************
void DMA_configMode(uint32_t base, DMA_Trigger trigger, uint32_t config)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));

    EALLOW;

    //
    // Set up trigger selection in the CMA/CLA trigger source selection
    // registers. These are considered part of system control.
    //
    switch(base)
    {
        case DMA_CH1_BASE:
            //
            // Channel 1
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL1_CH1_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL1_CH1_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH1_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH1_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 1U;
            break;

        case DMA_CH2_BASE:
            //
            // Channel 2
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL1_CH2_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL1_CH2_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH2_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH2_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 2U;
            break;

        case DMA_CH3_BASE:
            //
            // Channel 3
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL1_CH3_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL1_CH3_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH3_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH3_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 3U;
            break;

        case DMA_CH4_BASE:
            //
            // Channel 4
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL1) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL1_CH4_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL1_CH4_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH4_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH4_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 4U;
            break;

        case DMA_CH5_BASE:
            //
            // Channel 5
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL2) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL2) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL2_CH5_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL2_CH5_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH5_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH5_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 5U;
            break;

        case DMA_CH6_BASE:
            //
            // Channel 6
            //
            HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL2) =
                (HWREG(DMACLASRCSEL_BASE + SYSCTL_O_DMACHSRCSEL2) &
                 ~((uint32_t)SYSCTL_DMACHSRCSEL2_CH6_M)) |
                ((uint32_t)trigger << SYSCTL_DMACHSRCSEL2_CH6_S);

            //
            // Set peripheral interrupt select bits to the channel number.
            //
            HWREG(DMA_CH6_BASE + DMA_O_MODE) =
               (HWREG(DMA_CH6_BASE + DMA_O_MODE) & ~DMA_MODE_PERINTSEL_M) | 6U;
            break;

        default:
            //
            // Invalid base.
            //
            break;
    }

    //
    // Write the configuration to the mode register.
    //
    HWREG(base + DMA_O_MODE) &= ~(DMA_MODE_DATASIZE | DMA_MODE_CONTINUOUS |
                                   DMA_MODE_ONESHOT);
    HWREG(base + DMA_O_MODE) |= config;

    EDIS;
}

//*****************************************************************************
//
// DMA_configChannel
//
//*****************************************************************************
void DMA_configChannel(uint32_t base, const DMA_ConfigParams *transfParams)
{
    //
    // Check the arguments.
    //
    ASSERT(DMA_isBaseValid(base));
    ASSERT(((transfParams->configSize == DMA_CFG_SIZE_16BIT) ||
                  (transfParams->configSize == DMA_CFG_SIZE_32BIT)) &&
                  ((transfParams->transferMode == DMA_CFG_ONESHOT_DISABLE) ||
                  (transfParams->transferMode == DMA_CFG_ONESHOT_ENABLE)) &&
                  ((transfParams->reinitMode == DMA_CFG_CONTINUOUS_DISABLE) ||
                  (transfParams->reinitMode == DMA_CFG_CONTINUOUS_ENABLE)));

    //
    // Configure DMA Channel
    //
    DMA_configAddresses(base, (const void *)transfParams->destAddr,
                        (const void *)transfParams->srcAddr);

    //
    // Configure the size of each burst and the address step size
    //
    DMA_configBurst(base, transfParams->burstSize, transfParams->srcBurstStep,
                    transfParams->destBurstStep);

    //
    // Configure the transfer size and the address step that is
    // made after each burst.
    //
    DMA_configTransfer(base, transfParams->transferSize,
                       transfParams->srcTransferStep,
                       transfParams->destTransferStep);

    //
    // Configure the DMA channel's wrap settings
    //
    DMA_configWrap(base, transfParams->srcWrapSize, transfParams->srcWrapStep,
                   transfParams->destWrapSize, transfParams->destWrapStep);

    //
    // Configure the DMA channel's trigger and mode
    //
    DMA_configMode(base, transfParams->transferTrigger,
                   transfParams->transferMode | transfParams->reinitMode |
                   transfParams->configSize);

    //
    // Enable the selected peripheral trigger to start a DMA transfer
    //
    DMA_enableTrigger(base);

    if(transfParams->enableInterrupt)
    {
        //
        // Set the channel interrupt mode
        //
        DMA_setInterruptMode(base, transfParams->interruptMode);

        //
        // Enable the indicated DMA channel interrupt source
        //
        DMA_enableInterrupt(base);
    }
    else
    {
        //
        // Disable the indicated DMA channel interrupt source
        //
        DMA_disableInterrupt(base);
    }
}
