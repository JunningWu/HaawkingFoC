//###########################################################################
//
// FILE:   can.c
//
// TITLE:  H28x CAN driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################




#include "can.h"

//*****************************************************************************
//
// CAN_initModule
//
//*****************************************************************************
void
CAN_initModule(uint32_t base)
{
    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));

    //
    // Place CAN controller in init state, regardless of previous state.  This
    // will put controller in idle, and allow the message object RAM to be
    // programmed.
    //
    HWREG(base + CAN_O_CTL) |= ((uint32_t)CAN_CTL_INIT |
                                 (uint32_t)CAN_INIT_PARITY_DISABLE);

    //
    // Initialize the message RAM before using it.
    //
    CAN_initRAM(base);

    //
    // Force module to reset state
    //
    EALLOW;

    HWREG(base + CAN_O_CTL) |=  CAN_CTL_SWR;
    EDIS;

    //
    // Delay for 14 cycles
    //
    SysCtl_delay(1U);

    //
    // Enable write access to the configuration registers
    //
    HWREG(base + CAN_O_CTL) |= CAN_CTL_CCE;
}

//*****************************************************************************
//
// CAN_setBitRate
//
//*****************************************************************************
void
CAN_setBitRate(uint32_t base, uint32_t clock, uint32_t bitRate,
               uint32_t bitTime)
{
    uint32_t brp;
    uint32_t tPhase;
    uint32_t phaseSeg2;
    uint32_t tSync = 1U;
    uint32_t tProp = 2U;
    uint32_t tSeg1;
    uint32_t tSeg2;
    uint32_t sjw;
    uint32_t prescaler;
    uint32_t prescalerExtension;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((bitTime > 7U) && (bitTime < 26U));
    ASSERT(bitRate <= 1000000U);

    //
    // Calculate bit timing values
    //
    brp = (uint32_t)(clock / (bitRate * bitTime));
    tPhase = bitTime - (tSync + tProp);
    if((tPhase / 2U) <= 8U)
    {
        phaseSeg2 = tPhase / 2U;
    }
    else
    {
        phaseSeg2 = 8U;
    }
    tSeg1 = ((tPhase - phaseSeg2) + tProp) - 1U;
    tSeg2 = phaseSeg2 - 1U;
    if(phaseSeg2 > 4U)
    {
        sjw = 3U;
    }
    else
    {
        sjw = tSeg2;
    }
    prescalerExtension = ((brp - 1U) / 64U);
    prescaler = ((brp - 1U) % 64U);

    //
    // Set the calculated timing parameters
    //
    CAN_setBitTiming(base, prescaler, prescalerExtension, tSeg1, tSeg2, sjw);
}

//*****************************************************************************
//
// CAN_setBitTiming
//
//*****************************************************************************
void
CAN_setBitTiming(uint32_t base, uint32_t prescaler,
                 uint32_t prescalerExtension, uint32_t tSeg1, uint32_t tSeg2,
                 uint32_t sjw)
{
    uint32_t savedInit;
    uint32_t bitReg;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT(prescaler < 64U);
    ASSERT((tSeg1 > 0U) && (tSeg1 < 16U));
    ASSERT(tSeg2 < 8U);
    ASSERT(sjw < 4U);
    ASSERT(prescalerExtension < 16U);

    //
    // To set the bit timing register, the controller must be placed in init
    // mode (if not already), and also configuration change bit enabled.
    // State of the init bit should be saved so it can be restored at the end.
    //
    savedInit = HWREG(base + CAN_O_CTL);
    HWREG(base + CAN_O_CTL) = savedInit | CAN_CTL_INIT | CAN_CTL_CCE;

    //
    // Set the bit fields of the bit timing register
    //
    bitReg = (uint32_t)((uint32_t)prescaler & CAN_BTR_BRP_M);
    bitReg |= (uint32_t)(((uint32_t)sjw << CAN_BTR_SJW_S) & CAN_BTR_SJW_M);
    bitReg |= (uint32_t)(((uint32_t)tSeg1 << CAN_BTR_TSEG1_S) &
                         CAN_BTR_TSEG1_M);
    bitReg |= (uint32_t)(((uint32_t)tSeg2 << CAN_BTR_TSEG2_S) &
                         CAN_BTR_TSEG2_M);
    bitReg |= (uint32_t)(((uint32_t)prescalerExtension << CAN_BTR_BRPE_S) &
                         CAN_BTR_BRPE_M);

    HWREG(base + CAN_O_BTR) = bitReg;

    //
    // Clear the config change bit, and restore the init bit.
    //
    savedInit &= ~((uint32_t)CAN_CTL_CCE);


    HWREG(base + CAN_O_CTL) = savedInit;
}


//*****************************************************************************
//
// CAN_clearInterruptStatus
//
//*****************************************************************************
void
CAN_clearInterruptStatus(uint32_t base, uint32_t intClr)
{
    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((intClr == CAN_INT_INT0ID_STATUS) ||
           ((intClr >= 1U) && (intClr <= 32U)));

    if(intClr == (uint32_t)CAN_INT_INT0ID_STATUS)
    {
        //
        // Simply read and discard the status to clear the interrupt.
        //
        HWREG(base + CAN_O_ES);
    }
    else
    {
        //
        // Wait to be sure that this interface is not busy.
        //
        while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) ==
              CAN_IF1CMD_BUSY)
        {
        }

        //
        // Only change the interrupt pending state by setting only the
        // CAN_IF1CMD_CLRINTPND bit.
        //
        // Send the clear pending interrupt command to the CAN controller.
        //
        HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CLRINTPND |
                                        (intClr & CAN_IF1CMD_MSG_NUM_M));

        //
        // Wait to be sure that this interface is not busy.
        //
        while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) ==
              CAN_IF1CMD_BUSY)
        {
        }
    }
}

//*****************************************************************************
//
// CAN_setupMessageObject
//
//*****************************************************************************
void
CAN_setupMessageObject(uint32_t base, uint32_t objID, uint32_t msgID,
                       CAN_MsgFrameType frame, CAN_MsgObjType msgType,
                       uint32_t msgIDMask, uint32_t flags, uint32_t msgLen)
{
    uint32_t cmdMaskReg = 0U;
    uint32_t maskReg = 0U;
    uint32_t arbReg = 0U;
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));
    ASSERT(msgLen <= 8U);

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    switch(msgType)
    {
        //
        // Transmit message object.
        //
        case CAN_MSG_OBJ_TYPE_TX:
        {
            //
            // Set message direction to transmit.
            //
            arbReg = CAN_IF1ARB_DIR;
            break;
        }

        //
        // Remote frame receive remote, with auto-transmit message object.
        //
        case CAN_MSG_OBJ_TYPE_RXTX_REMOTE:
        {
            //
            // Set message direction to Tx for remote receivers.
            //
            arbReg = CAN_IF1ARB_DIR;

            //
            // Set this object to auto answer if a matching identifier is seen.
            //
            msgCtrl = (uint32_t)((uint32_t)CAN_IF1MCTL_RMTEN |
                                 (uint32_t)CAN_IF1MCTL_UMASK);

            break;
        }

        //
        // Transmit remote request message object (CAN_MSG_OBJ_TYPE_TX_REMOTE)
        // or Receive message object (CAN_MSG_OBJ_TYPE_RX).
        //
        default:
        {
           //
           // Set message direction to read.
           //
           arbReg = 0U;

           break;
        }
    }

    //
    // Set values based on Extended Frame or Standard Frame
    //
    if(frame == CAN_MSG_FRAME_EXT)
    {
        //
        // Configure the Mask Registers for 29 bit Identifier mask.
        //
        if((flags & CAN_MSG_OBJ_USE_ID_FILTER) == CAN_MSG_OBJ_USE_ID_FILTER)
        {
            maskReg = msgIDMask & CAN_IF1MSK_MSK_M;
        }

        //
        // Set the 29 bit version of the Identifier for this message
        // object. Mark the message as valid and set the extended ID bit.
        //
        arbReg |= (msgID & CAN_IF1ARB_ID_M) | CAN_IF1ARB_MSGVAL |
                  CAN_IF1ARB_XTD;
    }
    else
    {
        //
        // Configure the Mask Registers for 11 bit Identifier mask.
        //
        if((flags & CAN_MSG_OBJ_USE_ID_FILTER) == CAN_MSG_OBJ_USE_ID_FILTER)
        {
           maskReg = ((msgIDMask << CAN_IF1ARB_STD_ID_S) &
                      CAN_IF1ARB_STD_ID_M);
        }

        //
        // Set the 11 bit version of the Identifier for this message
        // object. The lower 18 bits are set to zero. Mark the message as
        // valid.
        //
        arbReg |= ((msgID << CAN_IF1ARB_STD_ID_S) & CAN_IF1ARB_STD_ID_M) |
                  CAN_IF1ARB_MSGVAL;
    }

    //
    // If the caller wants to filter on the extended ID bit then set it.
    //
    maskReg |= (flags & CAN_MSG_OBJ_USE_EXT_FILTER);

    //
    // The caller wants to filter on the message direction field.
    //
    maskReg |= (flags & CAN_MSG_OBJ_USE_DIR_FILTER);

    //
    // If any filtering is requested, set the UMASK bit to use mask register
    //
    if(((flags & CAN_MSG_OBJ_USE_ID_FILTER) |
        (flags & CAN_MSG_OBJ_USE_DIR_FILTER) |
        (flags & CAN_MSG_OBJ_USE_EXT_FILTER)) != 0U)
    {
        msgCtrl |= CAN_IF1MCTL_UMASK;
    }

    //
    // Set the data length for the transfers. This is applicable only for
    // Tx mailboxes. For Rx mailboxes, dlc is updated on receving a frame.
    //
    if((msgType == CAN_MSG_OBJ_TYPE_TX) ||
        (msgType == CAN_MSG_OBJ_TYPE_RXTX_REMOTE))
    {
        msgCtrl |= ((uint32_t)msgLen & CAN_IF1MCTL_DLC_M);
    }

    //
    // If this is a single transfer or the last mailbox of a FIFO, set EOB bit.
    // If this is not the last entry in a FIFO, leave the EOB bit as 0.
    //
    if((flags & CAN_MSG_OBJ_FIFO) == 0U)
    {
        msgCtrl |= CAN_IF1MCTL_EOB;
    }

    //
    // Enable transmit interrupts if they should be enabled.
    //
    msgCtrl |= (flags & CAN_MSG_OBJ_TX_INT_ENABLE);

    //
    // Enable receive interrupts if they should be enabled.
    //
    msgCtrl |= (flags & CAN_MSG_OBJ_RX_INT_ENABLE);

    //
    // Set the Control, Arb, and Mask bit so that they get transferred to the
    // Message object.
    //
    cmdMaskReg |= CAN_IF1CMD_ARB;
    cmdMaskReg |= CAN_IF1CMD_CONTROL;
    cmdMaskReg |= CAN_IF1CMD_MASK;
    cmdMaskReg |= CAN_IF1CMD_DIR;

    //
    // Write out the registers to program the message object.
    //
    HWREG(base + CAN_O_IF1MSK) = maskReg;
    HWREG(base + CAN_O_IF1ARB) = arbReg;
    HWREG(base + CAN_O_IF1MCTL) = msgCtrl;

    //
    // Transfer data to message object RAM
    //
    HWREG(base + CAN_O_IF1CMD) =
    cmdMaskReg | (objID & CAN_IF1CMD_MSG_NUM_M);
}

//*****************************************************************************
//
// CAN_sendMessage
//
//*****************************************************************************
void
CAN_sendMessage(uint32_t base, uint32_t objID, uint32_t msgLen,
                const uint16_t *msgData)
{
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));
    ASSERT(msgLen <= 8U);

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Check provided DLC size with actual Message DLC size
    //
    ASSERT((msgCtrl & CAN_IF1MCTL_DLC_M) == msgLen);

    //
    // Write the data out to the CAN Data registers.
    //
    CAN_writeDataReg(msgData, (base + CAN_O_IF1DATA),
                     (msgCtrl & CAN_IF1MCTL_DLC_M));

    //
    //  Set Data to be transferred from IF
    //
    if(msgLen > 0U)
    {
        msgCtrl = CAN_IF1CMD_DATA_B | CAN_IF1CMD_DATA_A;
    }
    else
    {
        msgCtrl = 0U;
    }

    //
    // Set Direction to write
    //
    // Set Tx Request Bit
    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    HWREG(base + CAN_O_IF1CMD) = (msgCtrl | (uint32_t)CAN_IF1CMD_DIR |
                                     (uint32_t)CAN_IF1CMD_TXRQST |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));
}

//*****************************************************************************
//
// CAN_sendMessage_16bit
//
//*****************************************************************************
void
CAN_sendMessage_16bit(uint32_t base, uint32_t objID, uint16_t msgLen,
                const uint16_t *msgData)
{
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));
    ASSERT(msgLen <= 8U);

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Check provided DLC size with actual Message DLC size
    //
    ASSERT((msgCtrl & CAN_IF1MCTL_DLC_M) == msgLen);

    //
    // Write the data out to the CAN Data registers.
    //
    CAN_writeDataReg_16bit(msgData, (base + CAN_O_IF1DATA),
                     (msgCtrl & CAN_IF1MCTL_DLC_M));

    //
    //  Set Data to be transferred from IF
    //
    if(msgLen > 0U)
    {
        msgCtrl = CAN_IF1CMD_DATA_B | CAN_IF1CMD_DATA_A;
    }
    else
    {
        msgCtrl = 0U;
    }

    //
    // Set Direction to write
    //
    // Set Tx Request Bit
    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    HWREG(base + CAN_O_IF1CMD) = (msgCtrl | (uint32_t)CAN_IF1CMD_DIR |
                                     (uint32_t)CAN_IF1CMD_TXRQST |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));
}

//*****************************************************************************
//
// CAN_sendMessage_32bit
//
//*****************************************************************************
void
CAN_sendMessage_32bit(uint32_t base, uint32_t objID, uint16_t msgLen,
                const uint32_t *msgData)
{
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));
    ASSERT(msgLen <= 8U);

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Check provided DLC size with actual Message DLC size
    //
    ASSERT((msgCtrl & CAN_IF1MCTL_DLC_M) == msgLen);

    //
    // Write the data out to the CAN Data registers.
    //
    CAN_writeDataReg_32bit(msgData, (base + CAN_O_IF1DATA),
                     (msgCtrl & CAN_IF1MCTL_DLC_M));

    //
    //  Set Data to be transferred from IF
    //
    if(msgLen > 0U)
    {
        msgCtrl = CAN_IF1CMD_DATA_B | CAN_IF1CMD_DATA_A;
    }
    else
    {
        msgCtrl = 0U;
    }

    //
    // Set Direction to write
    //
    // Set Tx Request Bit
    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    HWREG(base + CAN_O_IF1CMD) = (msgCtrl | (uint32_t)CAN_IF1CMD_DIR |
                                     (uint32_t)CAN_IF1CMD_TXRQST |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));
}


//*****************************************************************************
//
// CAN_sendMessage_updateDLC
//
//*****************************************************************************
void
CAN_sendMessage_updateDLC(uint32_t base, uint32_t objID, uint16_t msgLen,
                  const uint16_t *msgData)
{
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));
    ASSERT(msgLen <= 8U);

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Update to the new data length
    //
    msgCtrl &= ~CAN_IF1MCTL_DLC_M;
    msgCtrl |= (msgLen & CAN_IF1MCTL_DLC_M);

    //
    // Write out to the register to program the message object
    //
    HWREG(base + CAN_O_IF1MCTL) = msgCtrl;

    //
    // Transfer data to message object RAM
    //
    HWREG(base + CAN_O_IF1CMD) =
        (CAN_IF1CMD_CONTROL | CAN_IF1CMD_DIR | (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Check provided DLC size with actual Message DLC size
    //
    ASSERT((msgCtrl & CAN_IF1MCTL_DLC_M) == msgLen);

    //
    // Write the data out to the CAN Data registers.
    //
    CAN_writeDataReg(msgData, (base + CAN_O_IF1DATA),
                     (msgCtrl & CAN_IF1MCTL_DLC_M));

    //
    //  Set Data to be transferred from IF
    //
    if(msgLen > 0U)
    {
        msgCtrl = CAN_IF1CMD_DATA_B | CAN_IF1CMD_DATA_A;
    }
    else
    {
        msgCtrl = 0U;
    }

    //
    // Set Direction to write
    //
    // Set Tx Request Bit
    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    HWREG(base + CAN_O_IF1CMD) = (msgCtrl | (uint32_t)CAN_IF1CMD_DIR |
                                     (uint32_t)CAN_IF1CMD_TXRQST |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));
}

//*****************************************************************************
//
// CAN_sendRemoteRequestMessage
//
//*****************************************************************************
void
CAN_sendRemoteRequestMessage(uint32_t base, uint32_t objID)
{
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID > 0U));

    //
    // Set IF command to read message object control value
    //
    // Set up the request for data from the message object.
    // Transfer the message object to the IF register.
    //
    HWREG(base + CAN_O_IF1CMD) = ((uint32_t)CAN_IF1CMD_CONTROL |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Read IF message control
    //
    msgCtrl = HWREG(base + CAN_O_IF1MCTL);

    //
    // Check configured DLC size with 0 as this is a remote frame
    //
    ASSERT((msgCtrl & CAN_IF1MCTL_DLC_M) == 0U);

    //
    // Set Direction to write
    //
    // Set Tx Request Bit for this remote frame
    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    HWREG(base + CAN_O_IF1CMD) = (msgCtrl | (uint32_t)CAN_IF1CMD_DIR |
                                     (uint32_t)CAN_IF1CMD_TXRQST |
                                     (objID & CAN_IF1CMD_MSG_NUM_M));
}
//*****************************************************************************
//
// CAN_readMessage
//
//*****************************************************************************
bool
CAN_readMessage(uint32_t base, uint32_t objID,
                uint16_t *msgData)
{
    bool status;
    uint32_t msgCtrl = 0U;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID <= 32U) && (objID != 0U));

    //
    // Set the Message Data A, Data B, and control values to be read
    // on request for data from the message object.
    //
    // Transfer the message object to the message object IF register.
    //
    HWREG(base + CAN_O_IF2CMD) =
    ((uint32_t)CAN_IF2CMD_DATA_A | (uint32_t)CAN_IF2CMD_DATA_B |
     (uint32_t)CAN_IF2CMD_CONTROL | (objID & CAN_IF2CMD_MSG_NUM_M) |
	 (uint32_t)CAN_IF2CMD_ARB);

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF2CMD) & CAN_IF2CMD_BUSY) == CAN_IF2CMD_BUSY)
    {
    }

    //
    // Read out the IF control Register.
    //
    msgCtrl = HWREG(base + CAN_O_IF2MCTL);

    //
    // See if there is new data available.
    //
    if((msgCtrl & CAN_IF2MCTL_NEWDAT) == CAN_IF2MCTL_NEWDAT)
    {
        //
        // Read out the data from the CAN registers.
        //
        CAN_readDataReg(msgData, (base + CAN_O_IF2DATA),
                        (msgCtrl & CAN_IF2MCTL_DLC_M));

        status = true;

        //
        // Now clear out the new data flag
        //
        HWREG(base + CAN_O_IF2CMD) = ((uint32_t)CAN_IF2CMD_TXRQST |
                                        (objID & CAN_IF2CMD_MSG_NUM_M));

        //
        // Wait for busy bit to clear
        //
        while((HWREG(base + CAN_O_IF2CMD) & CAN_IF2CMD_BUSY) ==
               CAN_IF2CMD_BUSY)
        {
        }
    }
    else
    {
        status = false;
    }

    return(status);
}

//*****************************************************************************
//
// CAN_readMessageWithID
//
//*****************************************************************************

bool CAN_readMessageWithID(uint32_t base,
                           uint32_t objID,
                           CAN_MsgFrameType *frameType,
                           uint32_t *msgID,
                           uint16_t *msgData)
{
    bool status;


    //
    // Check the arguments.
    //
    ASSERT(msgID != 0U);
    ASSERT(frameType != 0U);

    //
    //Read the message first this fills the IF2 registers
    //with received message for that mailbox
    //
    status = CAN_readMessage(base, objID, msgData);
    //
    // See if there is new data available.
    //
    if(status == true)
    {
        if((HWREG(base + CAN_O_IF2ARB) & CAN_IF2ARB_XTD) != 0U)
        {
            *frameType = CAN_MSG_FRAME_EXT;
            *msgID = ((HWREG(base + CAN_O_IF2ARB)) & CAN_IF2ARB_ID_M);
        }
        else
        {
            *frameType = CAN_MSG_FRAME_STD;
            *msgID = (((HWREG(base + CAN_O_IF2ARB)) &
                       CAN_IF2ARB_STD_ID_M) >>
                      CAN_IF2ARB_STD_ID_S);
        }
    }
    return(status);
}
//*****************************************************************************
//
// CAN_transferMessage
//
//*****************************************************************************
void
CAN_transferMessage(uint32_t base, uint32_t interface, uint32_t objID,
                    bool direction, bool dmaRequest)
{
    uint32_t cmdMaskReg;

    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID >= 1U) && (objID <= 32U));
    ASSERT((interface == 1U) || (interface == 2U));

    //
    // This is always a read to the Message object as this call is setting a
    // message object.
    //
    cmdMaskReg =
    ((uint32_t)CAN_IF1CMD_DATA_A | (uint32_t)CAN_IF1CMD_DATA_B |
     (uint32_t)CAN_IF1CMD_TXRQST | (uint32_t)CAN_IF1CMD_CONTROL |
     (uint32_t)CAN_IF1CMD_MASK | (uint32_t)CAN_IF1CMD_ARB) |
    (direction ? CAN_IF1CMD_DIR : 0U) |
    (dmaRequest ? CAN_IF1CMD_DMAACTIVE : 0U);

    //
    // Ensure this IF isn't busy
    //
    while((HWREG(base + ((interface == 2U) ? CAN_O_IF2CMD : CAN_O_IF1CMD)) &
          CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Set up the request for data from the message object. Transfer the
    // message object to the message object specified by objID.
    //
    HWREG(base + ((interface == 2U) ? CAN_O_IF2CMD : CAN_O_IF1CMD)) =
                                (cmdMaskReg | (objID & CAN_IF1CMD_MSG_NUM_M));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + ((interface == 2U) ? CAN_O_IF2CMD : CAN_O_IF1CMD)) &
          CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }
}


//*****************************************************************************
//
// CAN_clearMessage
//
//*****************************************************************************
void
CAN_clearMessage(uint32_t base, uint32_t objID)
{
    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID >= 1U) && (objID <= 32U));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Clear the message valid bit in the arbitration register. This disables
    // the mailbox.
    //
    HWREG(base + CAN_O_IF1ARB) = 0U;

    //
    // Initiate programming the message object
    //
    HWREG(base + CAN_O_IF1CMD) =
    (((uint32_t)CAN_IF1CMD_DIR | (uint32_t)CAN_IF1CMD_ARB) |
     (objID & CAN_IF1CMD_MSG_NUM_M));
}
//*****************************************************************************
//
// CAN_disableMessageObject
//
//*****************************************************************************
void
CAN_disableMessageObject(uint32_t base, uint32_t objID)
{
    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));
    ASSERT((objID >= 1U) && (objID <= 32U));

    //
    // Wait for busy bit to clear
    //
    while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Clear the message valid bit in the arbitration register. This disables
    // the mailbox.
    //
    HWREG(base + CAN_O_IF1ARB) = 0U;

    //
    // Initiate programming the message object
    //
    HWREG(base + CAN_O_IF1CMD) =
    (((uint32_t)CAN_IF1CMD_DIR | (uint32_t)CAN_IF1CMD_ARB) |
     (objID & CAN_IF1CMD_MSG_NUM_M));
}

//*****************************************************************************
//
// CAN_disableAllMessageObjects
//
//*****************************************************************************
void
CAN_disableAllMessageObjects(uint32_t base)
{
    uint32_t objID;

    //
    // Check the arguments.
    //
    ASSERT(CAN_isBaseValid(base));

    //
    // Loop to disable all valid message objects
    //
    for(objID = 0x01; objID <= 0x20; objID++)
    {
      //
      // Wait for busy bit to clear
      //
      while((HWREG(base + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
      {
      }

      //
      // Clear the message valid bit in the arbitration register. This disables
      // the mailbox.
      //
      HWREG(base + CAN_O_IF1ARB) = 0U;

      //
      // Initiate programming the message object
      //
      HWREG(base + CAN_O_IF1CMD) =
      (((uint32_t)CAN_IF1CMD_DIR | (uint32_t)CAN_IF1CMD_ARB) |
       (objID & CAN_IF1CMD_MSG_NUM_M));
    }
}
