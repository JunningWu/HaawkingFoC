//###########################################################################
//
// FILE:   interrupt.c
//
// TITLE:  H28x Interrupt (PIE) driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#include "interrupt.h"

volatile uint32_t  CODE_SECTION(".ifr_register")  IFR;
volatile uint32_t  CODE_SECTION(".ier_register")  IER;
//*****************************************************************************
//
//! \internal
//! Clears the IFR flag in the CPU.
//!
//! \param group specifies the interrupt group to be cleared.
//!
//! This function clears the IFR flag.  This switch is needed because the
//! clearing of the IFR can only be done with a constant.
//
//*****************************************************************************
static void Interrupt_clearIFR(uint32_t group)
{
    switch(group)
    {
        case 0x0001U:
            IFR &= ~(uint32_t)0x0001U;
            break;
        case 0x0002U:
            IFR &= ~(uint32_t)0x0002U;
            break;
        case 0x0004U:
            IFR &= ~(uint32_t)0x0004U;
            break;
        case 0x0008U:
            IFR &= ~(uint32_t)0x0008U;
            break;
        case 0x0010U:
            IFR &= ~(uint32_t)0x0010U;
            break;
        case 0x0020U:
            IFR &= ~(uint32_t)0x0020U;
            break;
        case 0x0040U:
            IFR &= ~(uint32_t)0x0040U;
            break;
        case 0x0080U:
            IFR &= ~(uint32_t)0x0080U;
            break;
        case 0x0100U:
            IFR &= ~(uint32_t)0x0100U;
            break;
        case 0x0200U:
            IFR &= ~(uint32_t)0x0200U;
            break;
        case 0x0400U:
            IFR &= ~(uint32_t)0x0400U;
            break;
        case 0x0800U:
            IFR &= ~(uint32_t)0x0800U;
            break;
        case 0x1000U:
            IFR &= ~(uint32_t)0x1000U;
            break;
        case 0x2000U:
            IFR &= ~(uint32_t)0x2000U;
            break;
        case 0x4000U:
            IFR &= ~(uint32_t)0x4000U;
            break;
        case 0x8000U:
            IFR &= ~(uint32_t)0x8000U;
            break;
        default:
            //
            // Invalid group mask.
            //
            ASSERT((bool)false);
            break;
    }
}

//*****************************************************************************
//
// Interrupt_initModule
//
//*****************************************************************************
void
Interrupt_initModule(void)
{
    //
    // Disable and clear all interrupts at the CPU
    //
    (void)Interrupt_disableGlobal();
    IER = 0x0000U;
    IFR = 0x0000U;

    //
    // Clear all PIEIER registers
    //
    HWREG(PIECTRL_BASE + PIE_O_IER1) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER2) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER3) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER4) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER5) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER6) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER7) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER8) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER9) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER10) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER11) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IER12) = 0U;

    //
    // Clear all PIEIFR registers
    //
    HWREG(PIECTRL_BASE + PIE_O_IFR1) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR2) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR3) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR4) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR5) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR6) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR7) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR8) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR9) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR10) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR11) = 0U;
    HWREG(PIECTRL_BASE + PIE_O_IFR12) = 0U;

    //
    // Enable vector fetching from PIE block
    //
    HWREG(PIECTRL_BASE + PIE_O_CTRL) |= PIE_CTRL_ENPIE;

}

//*****************************************************************************
//
// Interrupt_initVectorTable
//
//*****************************************************************************
void
Interrupt_initVectorTable(void)
{
    uint32_t i;

    EALLOW;

    //
    // We skip the first three locations because they are initialized by Boot
    // ROM with boot variables.
    //
    for(i = 3U; i < 224U; i++)
    {
        HWREG(PIEVECTTABLE_BASE + (4U * i)) =
            (uint32_t)Interrupt_defaultHandler;
    }

    //
    // NMI and ITRAP get their own handlers.
    //
    HWREG(PIEVECTTABLE_BASE + ((INT_NMI >> 16U) * 4U)) =
        (uint32_t)Interrupt_nmiHandler;
		
    EDIS;
}

//*****************************************************************************
//
//Interrupt_enable
//
//*****************************************************************************
void
Interrupt_enable(uint32_t interruptNumber)
{
    bool intsDisabled;
    uint32_t intGroup;
    uint32_t groupMask;
    uint32_t vectID;

    vectID = (uint32_t)(interruptNumber >> 16U);

    //
    // Globally disable interrupts but save status
    //
    intsDisabled = Interrupt_disableGlobal();

    //
    // PIE Interrupts
    //
    if(vectID >= 0x20U)
    {
        intGroup = (uint32_t)(((interruptNumber & 0xFF00UL) >> 8U) - 1U);
        groupMask = (uint32_t)1U << intGroup;

        HWREG((PIECTRL_BASE + PIE_O_IER1 + (intGroup * 8U))) |=
        		(uint32_t)1U << ((uint32_t)(interruptNumber & 0xFFU) - 1U);

        //
        // Enable PIE Group Interrupt
        //
        IER |= groupMask;
    }

    //
    // INT13, INT14, DLOGINT, & RTOSINT
    //
    else if((vectID >= 0xDU) && (vectID <= 0x10U))
    {
        IER |= (uint32_t)1U << (vectID - 1U);
    }
    else
    {
        //
        // Other interrupts
        //
    }

    //
    // Re-enable interrupts if they were enabled
    //
    if(!intsDisabled)
    {
        (void)Interrupt_enableGlobal();
    }
}

//*****************************************************************************
//
// Interrupt_disable
//
//*****************************************************************************
void
Interrupt_disable(uint32_t interruptNumber)
{
    bool intsDisabled;
    uint32_t intGroup;
    uint32_t groupMask;
    uint32_t vectID;

    vectID = (uint32_t)(interruptNumber >> 16U);

    intsDisabled = Interrupt_disableGlobal();

    //
    // PIE Interrupts
    //
    if(vectID >= 0x20U)
    {
        intGroup = (uint32_t)(((interruptNumber & 0xFF00UL) >> 8U) - 1U);
        groupMask = (uint32_t)1U << intGroup;

        //
        // Disable individual PIE interrupt
        //
        HWREG(PIECTRL_BASE + PIE_O_IER1 + (intGroup * 8U)) &=
            ~(1U << ((uint32_t)(interruptNumber & 0xFFU) - 1U));

        //
        // Wait for any pending interrupts to get to the CPU
        //
        NOP;
        NOP;
        NOP;
        NOP;
        NOP;

        Interrupt_clearIFR(groupMask);

        //
        // Acknowledge any interrupts
        //
        HWREG(PIECTRL_BASE + PIE_O_ACK) = groupMask;
    }

    //
    // INT13, INT14, DLOGINT, & RTOSINT
    //
    else if((vectID >= 0x0DU) && (vectID <= 0x10U))
    {
        IER &= ~((uint32_t)1U << (vectID - 1U));

        //
        // Wait for any pending interrupts to get to the CPU
        //
        NOP;
        NOP;
        NOP;
        NOP;
        NOP;

        Interrupt_clearIFR((uint32_t)1U << (vectID - 1U));
    }
    else
    {
        //
        // Other interrupts
        //
    }

    //
    // Re-enable interrupts if they were enabled
    //
    if(!intsDisabled)
    {
        (void)Interrupt_enableGlobal();
    }
}
