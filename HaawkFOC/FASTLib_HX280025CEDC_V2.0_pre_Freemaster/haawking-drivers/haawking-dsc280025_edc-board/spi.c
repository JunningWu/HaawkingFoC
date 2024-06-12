//###########################################################################
//
// FILE:   spi.c
//
// TITLE:  H28x SPI driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.3 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "spi.h"

//*****************************************************************************
//
// SPI_setConfig
//
//*****************************************************************************
void
SPI_setConfig(uint32_t base, uint32_t lspclkHz, SPI_TransferProtocol protocol,
              SPI_Mode mode, uint32_t bitRate, uint32_t dataWidth)
{
    uint32_t regValue;
    uint32_t baud;

    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));
    ASSERT(bitRate <= (lspclkHz / 4U));
    ASSERT((lspclkHz / bitRate) <= 128U);
    ASSERT((dataWidth >= 1U) && (dataWidth <= 16U));
    ASSERT((HWREG(base + SPI_O_CCR) & SPI_CCR_SPISWRESET) == 0U);

    //
    // Set polarity and data width.
    //
    regValue = (((uint32_t)protocol << 6U) & SPI_CCR_CLKPOLARITY) |
               (dataWidth - 1U);

    HWREG(base + SPI_O_CCR) = (HWREG(base + SPI_O_CCR) &
                                ~(SPI_CCR_CLKPOLARITY | SPI_CCR_SPICHAR_M)) |
                               regValue;

    //
    // Set the mode and phase.
    //
    regValue = (uint32_t)mode | (((uint32_t)protocol << 2U) &
                                 SPI_CTL_CLK_PHASE);

    HWREG(base + SPI_O_CTL) = (HWREG(base + SPI_O_CTL) &
                                ~(SPI_CTL_TALK | SPI_CTL_CONTROLLER_PERIPHERAL |
                                  SPI_CTL_CLK_PHASE)) | regValue;

    //
    // Set the clock.
    //
    baud = (lspclkHz / bitRate) - 1U;
    HWREG(base + SPI_O_BRR) = (uint32_t)baud;
}

//*****************************************************************************
//
// SPI_setBaudRate
//
//*****************************************************************************
void
SPI_setBaudRate(uint32_t base, uint32_t lspclkHz, uint32_t bitRate)
{
    uint32_t baud;

    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));
    ASSERT(bitRate <= (lspclkHz / 4U));
    ASSERT((lspclkHz / bitRate) <= 128U);

    //
    // Set the clock.
    //
    baud = (lspclkHz / bitRate) - 1U;
    HWREG(base + SPI_O_BRR) = (uint32_t)baud;
}

//*****************************************************************************
//
// SPI_enableInterrupt
//
//*****************************************************************************
void
SPI_enableInterrupt(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Enable the specified non-FIFO interrupts.
    //
    if((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0U)
    {
        HWREG(base + SPI_O_CTL) |= SPI_CTL_SPIINTENA;
    }

    if((intFlags & SPI_INT_RX_OVERRUN) != 0U)
    {
        HWREG(base + SPI_O_CTL) |= SPI_CTL_OVERRUNINTENA;
    }

    //
    // Enable the specified FIFO-mode interrupts.
    //
    if((intFlags & SPI_INT_TXFF) != 0U)
    {
        HWREG(base + SPI_O_FFTX) |= SPI_FFTX_TXFFIENA;
    }

    if((intFlags & (SPI_INT_RXFF | SPI_INT_RXFF_OVERFLOW)) != 0U)
    {
        HWREG(base + SPI_O_FFRX) |= SPI_FFRX_RXFFIENA;
    }
}

//*****************************************************************************
//
// SPI_disableInterrupt
//
//*****************************************************************************
void
SPI_disableInterrupt(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Disable the specified non-FIFO interrupts.
    //
    if((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0U)
    {
        HWREG(base + SPI_O_CTL) &= ~(SPI_CTL_SPIINTENA);
    }

    if((intFlags & SPI_INT_RX_OVERRUN) != 0U)
    {
        HWREG(base + SPI_O_CTL) &= ~(SPI_CTL_OVERRUNINTENA);
    }

    //
    // Disable the specified FIFO-mode interrupts.
    //
    if((intFlags & SPI_INT_TXFF) != 0U)
    {
        HWREG(base + SPI_O_FFTX) &= ~(SPI_FFTX_TXFFIENA);
    }

    if((intFlags & (SPI_INT_RXFF | SPI_INT_RXFF_OVERFLOW)) != 0U)
    {
        HWREG(base + SPI_O_FFRX) &= ~(SPI_FFRX_RXFFIENA);
    }
}

//*****************************************************************************
//
// SPI_getInterruptStatus
//
//*****************************************************************************
uint32_t
SPI_getInterruptStatus(uint32_t base)
{
    uint32_t temp = 0;

    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    if((HWREG(base + SPI_O_STS) & SPI_STS_INT_FLAG) != 0U)
    {
        temp |= SPI_INT_RX_DATA_TX_EMPTY;
    }

    if((HWREG(base + SPI_O_STS) & SPI_STS_OVERRUN_FLAG) != 0U)
    {
        temp |= SPI_INT_RX_OVERRUN;
    }

    if((HWREG(base + SPI_O_FFTX) & SPI_FFTX_TXFFINT) != 0U)
    {
        temp |= SPI_INT_TXFF;
    }

    if((HWREG(base + SPI_O_FFRX) & SPI_FFRX_RXFFINT) != 0U)
    {
        temp |= SPI_INT_RXFF;
    }

    if((HWREG(base + SPI_O_FFRX) & SPI_FFRX_RXFFOVF) != 0U)
    {
        temp |= SPI_INT_RXFF_OVERFLOW;
    }

    return(temp);
}

//*****************************************************************************
//
// SPI_clearInterruptStatus
//
//*****************************************************************************
void
SPI_clearInterruptStatus(uint32_t base, uint32_t intFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SPI_isBaseValid(base));

    //
    // Clear the specified non-FIFO interrupt sources.
    //
    if((intFlags & SPI_INT_RX_DATA_TX_EMPTY) != 0U)
    {
        HWREG(base + SPI_O_CCR) &= ~(SPI_CCR_SPISWRESET);
        HWREG(base + SPI_O_CCR) |= SPI_CCR_SPISWRESET;
    }

    if((intFlags & SPI_INT_RX_OVERRUN) != 0U)
    {
        HWREG(base + SPI_O_STS) |= SPI_STS_OVERRUN_FLAG;
    }

    //
    // Clear the specified FIFO-mode interrupt sources.
    //
    if((intFlags & SPI_INT_TXFF) != 0U)
    {
        HWREG(base + SPI_O_FFTX) |= SPI_FFTX_TXFFINTCLR;
    }

    if((intFlags & SPI_INT_RXFF) != 0U)
    {
        HWREG(base + SPI_O_FFRX) |= SPI_FFRX_RXFFINTCLR;
    }

    if((intFlags & SPI_INT_RXFF_OVERFLOW) != 0U)
    {
        HWREG(base + SPI_O_FFRX) |= SPI_FFRX_RXFFOVFCLR;
    }
}

//*****************************************************************************
//
// SPI_pollingNonFIFOTransaction
//
//*****************************************************************************
uint16_t
SPI_pollingNonFIFOTransaction(uint32_t base, uint16_t charLength, uint16_t data)
{
    uint16_t rxData;

    ASSERT((charLength >= 1U) && (charLength <= 16U));
    ASSERT(data < ((uint32_t)1U << charLength));

    //
    // Set the character length
    //
    SPI_setcharLength(base, charLength);

    //
    // Write to SPI Transmit buffer
    //
    SPI_writeDataBlockingNonFIFO(base, data << (16U - charLength));

    //
    // Read SPI Receive buffer
    //
    rxData = SPI_readDataBlockingNonFIFO(base);

    return(rxData);
}

//*****************************************************************************
//
// SPI_pollingFIFOTransaction
//
//*****************************************************************************

void
SPI_pollingFIFOTransaction(uint32_t base, uint16_t charLength,
                           uint16_t *pTxBuffer, uint16_t *pRxBuffer,
                           uint16_t numOfWords, uint16_t txDelay)
{
    ASSERT((charLength >= 1U) && (charLength <= 16U));
    SPI_setcharLength(base, charLength);

    //
    // Reset the TX / RX FIFO buffers to default state
    //
    SPI_disableFIFO(base); // Disable FIFO register
    SPI_enableFIFO(base);  // Enable FIFO register

    //
    // Configure the FIFO Transmit Delay
    //
    SPI_setTxFifoTransmitDelay(base, txDelay);

    //
    // Determine the number of 16-level words from number of words to be
    // transmitted / received
    //
    uint16_t numOfSixteenWords = numOfWords / (uint16_t)SPI_FIFO_TXFULL;

    //
    // Determine the number of remaining words from number of words to be
    // transmitted / received
    //
    uint16_t remainingWords = numOfWords % (uint16_t)SPI_FIFO_TXFULL;

    uint16_t count = 0;
    uint16_t i = 0;
    uint16_t txBuffer_pos = 0;
    uint16_t rxBuffer_pos = 0;

    //
    // Number of transactions is based on numOfSixteenWords
    // Each transaction will transmit and receive 16 words.
    //
    while(count < numOfSixteenWords)
    {
        //
        // Fill-up the SPI Transmit FIFO buffers
        //
        for(i = 1; i <= (uint16_t)SPI_FIFO_TXFULL; i++)
        {
            SPI_writeDataBlockingFIFO(base, pTxBuffer[txBuffer_pos] <<
                                            (16U - charLength));
            txBuffer_pos++;
        }

        //
        // Wait till SPI Receive FIFO buffer is full
        //
        while(SPI_getRxFIFOStatus(base) < SPI_FIFO_RXFULL)
        {
        }

        //
        // Read the SPI Receive FIFO buffers
        //
        for(i = 1U; i <= (uint16_t)SPI_FIFO_RXFULL; i++)
        {
            if(pRxBuffer == NULL)
            {
                SPI_readDataBlockingFIFO(base);
            }
            else
            {
                pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFIFO(base);
                rxBuffer_pos++;
            }
        }

        count++;
    }

    //
    // Number of transactions is based on remainingWords
    //
    for(i = 0U; i < remainingWords; i++)
    {
        SPI_writeDataBlockingFIFO(base, pTxBuffer[txBuffer_pos] <<
                                        (16U - charLength));
        txBuffer_pos++;
    }

    //
    // Wait till SPI Receive FIFO buffer remaining words
    //
    while((uint16_t)SPI_getRxFIFOStatus(base) < remainingWords)
    {
    }

    //
    // Read the SPI Receive FIFO buffers
    //
    for(i = 0; i < remainingWords; i++)
    {
        if(pRxBuffer == NULL)
        {
            SPI_readDataBlockingFIFO(base);
        }
        else
        {
            pRxBuffer[rxBuffer_pos] = SPI_readDataBlockingFIFO(base);
            rxBuffer_pos++;
        }
    }

    //
    // Disable SPI FIFO
    //
    SPI_disableFIFO(base);
}

//*****************************************************************************
//
// SPI_transmit24Bits
//
//*****************************************************************************
void
SPI_transmit24Bits(uint32_t base, uint32_t data, uint16_t txDelay)
{
    uint16_t i;
    uint16_t rxBuffer[3];
    uint16_t txBuffer[3];

    ASSERT(data < ((uint32_t)1U << 24U));

    //
    // Empty Receive buffer
    //
    for(i = 0U; i < 3U; i++)
    {
        rxBuffer[i] = 0U;
    }

    //
    // Fill Transmit buffer with appropriate data
    //
    txBuffer[0] = (uint16_t)(data >> 16U);   // data[23:16]
    txBuffer[1] = (uint16_t)(data) >> 8U;    // data[15:8]
    txBuffer[2] = (uint16_t)(data) & 0x00FFU; // data[7:0]

    //
    // Three 8-bits make a 24-bit
    // Character length = 8
    // number of bytes = 3
    //
    SPI_pollingFIFOTransaction(base, 8U, txBuffer, rxBuffer, 3U, txDelay);
}
//*****************************************************************************
//
// SPI_receive16Bits
//
//*****************************************************************************

uint16_t
SPI_receive16Bits(uint32_t base, SPI_endianess endianness, uint16_t dummyData,
                  uint16_t txDelay)
{
    uint16_t i;
    uint16_t txBuffer[2];
    uint16_t rxBuffer[2];
    uint16_t rxData = 0U;

    ASSERT(dummyData <= 0xFFU);

    //
    // Empty Transmit buffer
    //
    for(i = 0U; i < 2U; i++)
    {
        txBuffer[i] = dummyData;
        rxBuffer[i] = 0U;
    }

    //
    // Send dummy words to receive data from PERIPHERAL
    //
    SPI_pollingFIFOTransaction(base, 8U, txBuffer, rxBuffer, 2U, txDelay);

    if(endianness == SPI_DATA_LITTLE_ENDIAN)
    {
        //
        // LITTLE_ENDIAN
        //
        rxData = (rxBuffer[1] << 8) | rxBuffer[0];
    }
    else
    {
        //
        // BIG_ENDIAN
        //
        rxData = (rxBuffer[0] << 8) | rxBuffer[1];
    }

    return(rxData);
}
//*****************************************************************************
//
// SPI_receive24Bits
//
//*****************************************************************************

uint32_t
SPI_receive24Bits(uint32_t base, SPI_endianess endianness, uint16_t dummyData,
                           uint16_t txDelay)
{
    uint16_t i;
    uint16_t txBuffer[3];
    uint16_t rxBuffer[3];
    uint32_t rxData = 0;

    ASSERT(dummyData <= 0xFFU);

    //
    // Empty Transmit buffer
    //
    for(i = 0U; i < 3U; i++)
    {
        txBuffer[i] = dummyData;
        rxBuffer[i] = 0U;
    }

    //
    // Send dummy words to receive data from PERIPHERAL
    // Two 8-bits make a 16-bit
    // Character length = 8
    // number of bytes = 2
    //
    SPI_pollingFIFOTransaction(base, 8U, txBuffer, rxBuffer, 3U, txDelay);

    if(endianness == SPI_DATA_LITTLE_ENDIAN)
    {
        //
        // LITTLE_ENDIAN
        //
        rxData = ((uint32_t)rxBuffer[2] << 16) |
                 ((uint32_t)rxBuffer[1] << 8)  |
                 (uint32_t)rxBuffer[0];
    }
    else
    {
        //
        // BIG_ENDIAN
        //
        rxData = ((uint32_t)rxBuffer[0] << 16) |
                 ((uint32_t)rxBuffer[1] << 8)  |
                 (uint32_t)rxBuffer[2];
    }

    return(rxData);
}
//*****************************************************************************
//
// SPI_transmit32Bits
//
//*****************************************************************************

void
SPI_transmit32Bits(uint32_t base, uint32_t data, uint16_t txDelay)
{
    uint16_t i;
    uint16_t txBuffer[2];
    uint16_t rxBuffer[2];

    //
    // Empty Receive buffer
    //
    for(i = 0U; i < 2U; i++)
    {
        rxBuffer[i] = 0U;
    }

    //
    // Fill Transmit buffer with appropriate data
    //
    txBuffer[0] = (uint16_t)(data >> 16U);  // data[31:16]
    txBuffer[1] = (uint16_t)(data);         // data[15:0]

    //
    // Two 16-bits make a 32-bit
    // Character length = 16
    // number of bytes = 2
    //
    SPI_pollingFIFOTransaction(base, 16U, txBuffer, rxBuffer, 2U, txDelay);
}
//*****************************************************************************
//
// SPI_receive32Bits
//
//*****************************************************************************

uint32_t
SPI_receive32Bits(uint32_t base, SPI_endianess endianness, uint16_t dummyData,
                  uint16_t txDelay)
{
    uint16_t i;
    uint16_t txBuffer[4];
    uint16_t rxBuffer[4];
    uint32_t rxData = 0U;

    ASSERT(dummyData <= 0xFFU);

    //
    // Empty Transmit buffer
    //
    for(i = 0U; i < 4U; i++)
    {
        txBuffer[i] = dummyData;
        rxBuffer[i] = 0U;
    }

    //
    // Send dummy words to receive data from PERIPHERAL
    // Four 8-bits make a 32-bit
    // Character length = 8
    // number of bytes = 4
    //
    SPI_pollingFIFOTransaction(base, 8U, txBuffer, rxBuffer, 4U, txDelay);

    if(endianness == SPI_DATA_LITTLE_ENDIAN)
    {
        //
        // LITTLE_ENDIAN
        //
        rxData = ((uint32_t)rxBuffer[3] << 24U) |
                 ((uint32_t)rxBuffer[2] << 16U) |
                 ((uint32_t)rxBuffer[1] << 8U)  |
                 (uint32_t)rxBuffer[0];
    }
    else
    {
        //
        // BIG_ENDIAN
        //
        rxData = ((uint32_t)rxBuffer[0] << 24U) |
                 ((uint32_t)rxBuffer[1] << 16U) |
                 ((uint32_t)rxBuffer[2] << 8U)  |
                 (uint32_t)rxBuffer[3];
    }

    return(rxData);
}
