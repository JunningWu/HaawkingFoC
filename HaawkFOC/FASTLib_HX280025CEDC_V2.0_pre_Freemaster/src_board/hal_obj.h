//#############################################################################
// $TI Release: MotorControl SDK v3.03.00.00 $
// $Release Date: Tue Sep 21 16:33:28 CDT 2021 $
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

#ifndef HAL_OBJ_H
#define HAL_OBJ_H

//
//! \file   \solutions\fast_uni_lab\f28002x\drivers\include\hal_obj.h
//! \brief  Defines the structures for the HAL object
//

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************


//*****************************************************************************
//
//! \addtogroup HALL_OBJ
//! @{
//
//*****************************************************************************

// drivers
#include "device.h"

//#include "pwmdac.h"

// modules
#include "hal_data.h"

#include "drv8323s.h"

// platforms

// Defines for I2C
#define I2C_SLAVE_ADDRESS           0x50

// Defines for DRV ICs


#define DRVIC_Obj               DRV8323_Obj
#define DRVIC_VARS_t            DRV8323_VARS_t
#define DRVIC_Handle            DRV8323_Handle
#define DRVICVARS_Handle        DRV8323VARS_Handle

#define DRVIC_init              DRV8323_init
#define DRVIC_enable            DRV8323_enable
#define DRVIC_writeData         DRV8323_writeData
#define DRVIC_readData          DRV8323_readData

#define DRVIC_setupSPI          DRV8323_setupSPI

#define DRVIC_setSPIHandle      DRV8323_setSPIHandle
#define DRVIC_setGPIOCSNumber   DRV8323_setGPIOCSNumber
#define DRVIC_setGPIOENNumber   DRV8323_setGPIOENNumber


//! \brief      Defines the HAL object
//!
typedef struct _HAL_MTR_Obj_
{
  uint32_t       pwmHandle[3];       //<! the PWM handles

  uint32_t       cmpssHandle[3];     //!< the CMPSS handle

  uint32_t       spiHandle;          //!< the SPI handle

  DRVIC_Handle   drvicHandle;        //!< the drvic interface handle
  DRVIC_Obj      drvic;              //!< the drvic interface object

  uint32_t       gateEnableGPIO;
  uint32_t       gateCalGPIO;
  // BSXL8323RS_REVA
  uint16_t       numCurrentSensors;  //!< the number of current sensors
  uint16_t       numVoltageSensors;  //!< the number of voltage sensors
  bool           flagEnablePWM;     //<! the pwm enable flag
} HAL_MTR_Obj;

//! \brief      Defines the HAL_MTR handle
//! \details    The HAL_MTR handle is a pointer to a HAL_MTR object.  In all
//!             HAL_MTR functions, the HAL_MTR handle is passed so that the
//!             function knows what peripherals are to be accessed.
//!
typedef struct _HAL_MTR_Obj_ *HAL_MTR_Handle;


//! \brief      Defines the hardware abstraction layer (HAL) data
//! \details    The HAL object contains all handles to peripherals.  When accessing a
//!             peripheral on a processor, use a HAL function along with the HAL handle
//!             for that processor to access its peripherals.
//!
typedef struct _HAL_Obj_
{
  uint32_t       adcHandle[2];      //!< the ADC handles
  uint32_t       adcResult[2];      //!< the ADC results

  uint32_t       timerHandle[3];    //<! the timer handles
  uint32_t       sciHandle;         //!< the SCI handle
  uint32_t       linHandle;         //!< the LIN handle
  uint32_t       canHandle;         //!< the CAN handle
  uint32_t       i2cHandle;         //!< the I2C handle

  uint32_t       spiHandle[2];      //!< the SPI handle

  uint32_t       dmaHandle;         //!< the DMA handle
  uint32_t       dmaChHandle[4];    //!< the DMA Channel handle

  HAL_MTR_Handle mtrHandle[2];      //!< the motor control interface handle
} HAL_Obj;

//! \brief      Defines the HAL handle
//! \details    The HAL handle is a pointer to a HAL object.  In all HAL functions
//!             the HAL handle is passed so that the function knows what peripherals
//!             are to be accessed.
//!
typedef struct _HAL_Obj_ *HAL_Handle;


//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************


#endif // end of HAL_OBJ_H definition

