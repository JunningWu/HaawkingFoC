//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:26 CDT 2021 $
// $Copyright:
// Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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
//   Neither the name of Texas Instruments Incorporated nor the names of
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
// $
//#############################################################################

//! \file   libraries/drvic/drv8323/source/drv8323s.c
//! \brief  Contains the various functions related to the DRV8323 object
//!

// **************************************************************************
// the includes

#include <math.h>

// **************************************************************************
// drivers
#include "drv8323s.h"

// **************************************************************************
// modules

// **************************************************************************
// platforms

// **************************************************************************
// the defines

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

DRV8323_Handle DRV8323_init(void *pMemory)
{
    DRV8323_Handle handle;

    // assign the handle
    handle = (DRV8323_Handle)pMemory;

    DRV8323_resetRxTimeout(handle);
    DRV8323_resetEnableTimeout(handle);

    return(handle);
} // end of DRV8323_init() function

void DRV8323_enable(DRV8323_Handle handle)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;
    volatile uint16_t enableWaitTimeOut;
    uint16_t n = 0;

    // Enable the DRV8323
    GPIO_writePin(obj->gpioNumber_EN, 1);
    GPIO_writePin(obj->gpioNumber_EN, 1);

    enableWaitTimeOut = 0;

    // Wait for the DRV8323 to go through start up sequence
    for(n = 0; n < 0x3FFF; n++)
    {
        __asm(" NOP");
    }

    // Make sure the FAULT bit is not set during startup
    while(((DRV8323_readSPI(handle, DRV8323_ADDRESS_STATUS_0) &
            DRV8323_STATUS00_FAULT_BITS) != 0) && (enableWaitTimeOut < 1000))
    {
        if(++enableWaitTimeOut > 999)
        {
            obj->enableTimeOut = true;
        }
    }

    // Wait for the DRV8323 to go through start up sequence
    for(n = 0; n < 0x7FFF; n++)
    {
        __asm(" NOP");
    }

    return;
} // end of DRV8323_enable() function


DRV8323_CTRL03_PeakSourCurHS_e DRV8323_getPeakSourCurHS(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_3);

    // mask the bits
    data &= DRV8323_CTRL03_IDRIVEP_HS_BITS;

    return((DRV8323_CTRL03_PeakSourCurHS_e)data);
} // end of DRV8323_getPeakSourCurHS function

DRV8323_CTRL03_PeakSinkCurHS_e DRV8323_getPeakSinkCurHS(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_3);

    // mask the bits
    data &= DRV8323_CTRL03_IDRIVEN_HS_BITS;

    return((DRV8323_CTRL03_PeakSinkCurHS_e)data);
} // end of DRV8323_getPeakSinkCurHS function

DRV8323_CTRL04_PeakTime_e DRV8323_getPeakSourTime(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_4);

    // mask the bits
    data &= DRV8323_CTRL04_TDRIVE_BITS;

    return((DRV8323_CTRL04_PeakTime_e)data);
} // end of DRV8323_getPeakSourTime function

DRV8323_CTRL04_PeakSourCurLS_e DRV8323_getPeakSourCurLS(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_4);

    // mask the bits
    data &= DRV8323_CTRL04_IDRIVEP_LS_BITS;

    return((DRV8323_CTRL04_PeakSourCurLS_e)data);
} // end of DRV8323_getPeakSourCurLS function

DRV8323_CTRL04_PeakSinkCurLS_e DRV8323_getPeakSinkCurLS(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_4);

    // mask the bits
    data &= DRV8323_CTRL04_IDRIVEN_LS_BITS;

    return((DRV8323_CTRL04_PeakSinkCurLS_e)data);
} // end of DRV8323_getPeakSinkCurLS function

DRV8323_CTRL05_OcpDeg_e DRV8323_getVDSDeglitch(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_5);

    // mask the bits
    data &= DRV8323_CTRL05_OCP_DEG_BITS;

    return((DRV8323_CTRL05_OcpDeg_e)data);
} // end of DRV8323_getVDSDeglitch function

DRV8323_CTRL05_DeadTime_e DRV8323_getDeadTime(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_5);

    // mask the bits
    data &= DRV8323_CTRL05_DEAD_TIME_BITS;

    return((DRV8323_CTRL05_DeadTime_e)data);
} // end of DRV8323_getDeadTime function

DRV8323_CTRL02_PWMMode_e DRV8323_getPWMMode(DRV8323_Handle handle)
{
    uint16_t data;

    // read data
    data = DRV8323_readSPI(handle, DRV8323_ADDRESS_CONTROL_2);

    // mask the bits
    data &= DRV8323_CTRL02_PWM_MODE_BITS;

    return((DRV8323_CTRL02_PWMMode_e)data);
} // end of DRV8323_getPWMMode function

void DRV8323_setSPIHandle(DRV8323_Handle handle, uint32_t spiHandle)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;

    // initialize the serial peripheral interface object
    obj->spiHandle = spiHandle;

    return;
} // end of DRV8323_setSPIHandle() function

void DRV8323_setGPIOCSNumber(DRV8323_Handle handle, uint32_t gpioNumber)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;

    // initialize the gpio interface object
    obj->gpioNumber_CS = gpioNumber;

    return;
} // end of DRV8323_setGPIOCSNumber() function

void DRV8323_setGPIOENNumber(DRV8323_Handle handle, uint32_t gpioNumber)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;

    // initialize the gpio interface object
    obj->gpioNumber_EN = gpioNumber;

    return;
} // end of DRV8323_setGPIOENNumber() function

void DRV8323_setupSPI(DRV8323_Handle handle,
                      DRV8323_VARS_t *drv8323Vars)
{
    DRV8323_Address_e drvRegAddr;
    uint16_t drvDataNew;

    // Set Default Values
    // Manual Read/Write
    drv8323Vars->manReadAddr  = 0;
    drv8323Vars->manReadData  = 0;
    drv8323Vars->manReadCmd = false;
    drv8323Vars->manWriteAddr = 0;
    drv8323Vars->manWriteData = 0;
    drv8323Vars->manWriteCmd = false;

    // Read/Write
    drv8323Vars->readCmd  = false;
    drv8323Vars->writeCmd = false;

    // Read registers for default values
    // Read Status Register 0
    drvRegAddr = DRV8323_ADDRESS_STATUS_0;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->statReg00.all = drvDataNew;

    // Read Status Register 1
    drvRegAddr = DRV8323_ADDRESS_STATUS_1;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->statReg01.all = drvDataNew;

      // Read Control Register 2
    // all bit default value are 0, 6*PWM Mode
    drvRegAddr = DRV8323_ADDRESS_CONTROL_2;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->ctrlReg02.all = drvDataNew;

    // Read Control Register 3
    // all bit default value are 1, IDRIVEP_HS=1000mA, IDRIVEN_HS = 2000mA
    drvRegAddr = DRV8323_ADDRESS_CONTROL_3;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->ctrlReg03.all = drvDataNew;

    // Read Control Register 4
    // all bit default value are 1, TDRIVE=400ns, IDRIVEP_LS=1000mA, IDRIVEN_LS = 2000mA
    drvRegAddr = DRV8323_ADDRESS_CONTROL_4;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->ctrlReg04.all = drvDataNew;

    // Read Control Register 5
    // DEAD_TIME=100ns, OCP_DEG=4us, VDS_LVL=0.75V
    drvRegAddr = DRV8323_ADDRESS_CONTROL_5;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->ctrlReg05.all = drvDataNew;

    // Read Control Register 6
    // DEAD_TIME=100ns, OCP_DEG=4us, VDS_LVL=0.75V
    drvRegAddr = DRV8323_ADDRESS_CONTROL_6;
    drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
    drv8323Vars->ctrlReg06.all = drvDataNew;

    return;
} // end of DRV8323_setupSPI() function

uint16_t DRV8323_readSPI(DRV8323_Handle handle,
                         const DRV8323_Address_e regAddr)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;
    uint16_t ctrlWord;
    uint16_t n;
    const uint16_t data = 0;
    volatile uint16_t readWord;
    volatile uint16_t WaitTimeOut = 0;

    volatile SPI_RxFIFOLevel RxFifoCnt = SPI_FIFO_RXEMPTY;

    // build the control word
    ctrlWord = (uint16_t)DRV8323_buildCtrlWord(DRV8323_CTRLMODE_READ, regAddr, data);

#ifdef DRV_CS_GPIO
    GPIO_writePin(obj->gpioNumber_CS, 0);
    GPIO_writePin(obj->gpioNumber_CS, 0);
#endif  // DRV_CS_GPIO

    // wait for registers to update
    for(n = 0; n < 0x08; n++)
    {
        __asm(" NOP");
    }

    // reset the Rx fifo pointer to zero
    SPI_resetRxFIFO(obj->spiHandle);
    SPI_enableFIFO(obj->spiHandle);

    // wait for registers to update
    for(n = 0; n < 0x20; n++)
    {
        __asm(" NOP");
    }

    // write the command
    SPI_writeDataBlockingNonFIFO(obj->spiHandle, ctrlWord);

    // wait for two words to populate the RX fifo, or a wait timeout will occur
    while(RxFifoCnt < SPI_FIFO_RX1)
    {
        RxFifoCnt = SPI_getRxFIFOStatus(obj->spiHandle);

        if(++WaitTimeOut > 0xfffe)
        {
            obj->rxTimeOut = true;
        }
    }

    WaitTimeOut = 0xffff;

    // wait for registers to update
    for(n = 0; n < 0x100; n++)
    {
        __asm(" NOP");
    }

#ifdef DRV_CS_GPIO
    GPIO_writePin(obj->gpioNumber_CS, 1);
    GPIO_writePin(obj->gpioNumber_CS, 1);
#endif  // DRV_CS_GPIO

    // Read the word
    readWord = SPI_readDataNonBlocking(obj->spiHandle);

    return(readWord & DRV8323_DATA_MASK);
} // end of DRV8323_readSPI() function


void DRV8323_writeSPI(DRV8323_Handle handle, const DRV8323_Address_e regAddr,
                      const uint16_t data)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;
    uint16_t ctrlWord;
    uint16_t n;

    // build the control word
    ctrlWord = (uint16_t)DRV8323_buildCtrlWord(DRV8323_CTRLMODE_WRITE, regAddr, data);

#ifdef DRV_CS_GPIO
    GPIO_writePin(obj->gpioNumber_CS, 0);
    GPIO_writePin(obj->gpioNumber_CS, 0);
#endif  // DRV_CS_GPIO

    // wait for GPIO
    for(n = 0; n < 0x08; n++)
    {
        __asm(" NOP");
    }

    // reset the Rx fifo pointer to zero
    SPI_resetRxFIFO(obj->spiHandle);
    SPI_enableFIFO(obj->spiHandle);

    // wait for registers to update
    for(n = 0; n < 0x40; n++)
    {
        __asm(" NOP");
    }

    // write the command
    SPI_writeDataBlockingNonFIFO(obj->spiHandle, ctrlWord);

    // wait for registers to update
    for(n = 0; n < 0x100; n++)
    {
        __asm(" NOP");
    }

#ifdef DRV_CS_GPIO
    GPIO_writePin(obj->gpioNumber_CS, 1);
    GPIO_writePin(obj->gpioNumber_CS, 1);
#endif  // DRV_CS_GPIO

    return;
}  // end of DRV8323_writeSPI() function


void DRV8323_writeData(DRV8323_Handle handle, DRV8323_VARS_t *drv8323Vars)
{
    DRV8323_Address_e drvRegAddr;
    uint16_t drvDataNew;

    if(drv8323Vars->writeCmd)
    {
        // Write Control Register 2
        drvRegAddr = DRV8323_ADDRESS_CONTROL_2;
        drvDataNew = drv8323Vars->ctrlReg02.all & DRV8323_DATA_MASK;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        // Write Control Register 3
        drvRegAddr = DRV8323_ADDRESS_CONTROL_3;
        drvDataNew = drv8323Vars->ctrlReg03.all & DRV8323_DATA_MASK;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        // Write Control Register 4
        drvRegAddr = DRV8323_ADDRESS_CONTROL_4;
        drvDataNew = drv8323Vars->ctrlReg04.all & DRV8323_DATA_MASK;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        // Write Control Register 5
        drvRegAddr = DRV8323_ADDRESS_CONTROL_5;
        drvDataNew = drv8323Vars->ctrlReg05.all & DRV8323_DATA_MASK;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        // Write Control Register 5
        drvRegAddr = DRV8323_ADDRESS_CONTROL_6;
        drvDataNew = drv8323Vars->ctrlReg06.all & DRV8323_DATA_MASK;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        drv8323Vars->writeCmd = false;
    }

    // Manual write to the DRV8323
    if(drv8323Vars->manWriteCmd)
    {
        // Custom Write
        drvRegAddr = (DRV8323_Address_e)(drv8323Vars->manWriteAddr << 11);
        drvDataNew = drv8323Vars->manWriteData;
        DRV8323_writeSPI(handle, drvRegAddr, drvDataNew);

        drv8323Vars->manWriteCmd = false;
    }

    return;
}  // end of DRV8323_writeData() function

void DRV8323_readData(DRV8323_Handle handle, DRV8323_VARS_t *drv8323Vars)
{
    DRV8323_Address_e drvRegAddr;
    uint16_t drvDataNew;

    if(drv8323Vars->readCmd)
    {
        // Read registers for default values
        // Read Status Register 0
        drvRegAddr = DRV8323_ADDRESS_STATUS_0;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->statReg00.all  = drvDataNew;

        // Read Status Register 1
        drvRegAddr = DRV8323_ADDRESS_STATUS_1;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->statReg01.all  = drvDataNew;

        // Read Control Register 2
        drvRegAddr = DRV8323_ADDRESS_CONTROL_2;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->ctrlReg02.all  = drvDataNew;

        // Read Control Register 3
        drvRegAddr = DRV8323_ADDRESS_CONTROL_3;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->ctrlReg03.all  = drvDataNew;

        // Read Control Register 4
        drvRegAddr = DRV8323_ADDRESS_CONTROL_4;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->ctrlReg04.all  = drvDataNew;

        // Read Control Register 5
        drvRegAddr = DRV8323_ADDRESS_CONTROL_5;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->ctrlReg05.all  = drvDataNew;

        // Read Control Register 6
        drvRegAddr = DRV8323_ADDRESS_CONTROL_6;
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->ctrlReg06.all  = drvDataNew;

        drv8323Vars->readCmd = false;
    }

    // Manual read from the DRV8323
    if(drv8323Vars->manReadCmd)
    {
        // Custom Read
        drvRegAddr = (DRV8323_Address_e)(drv8323Vars->manReadAddr << 11);
        drvDataNew = DRV8323_readSPI(handle, drvRegAddr);
        drv8323Vars->manReadData = drvDataNew;

        drv8323Vars->manReadCmd = false;
    }

    return;
}  // end of DRV8323_readData() function

// end of file
