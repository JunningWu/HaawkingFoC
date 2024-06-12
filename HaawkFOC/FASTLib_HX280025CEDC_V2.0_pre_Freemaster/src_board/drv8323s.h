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

#ifndef DRV8323S_H
#define DRV8323S_H

//! \file   libraries/drvic/drv8323/include/drv8323s.h
//! \brief  Contains public interface to various functions related
//!         to the DRV8323 object
//!

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \defgroup DRV8323 DRV8323
//! @{
//
//*****************************************************************************

// the includes
#include <math.h>

// drivers
#include "spi.h"
#include "gpio.h"

// **************************************************************************
// modules

// **************************************************************************
// solutions



// **************************************************************************
// the defines

//! \brief Defines the address mask
//!
#define DRV8323_ADDR_MASK                   (0x7800)

//! \brief Defines the data mask
//!
#define DRV8323_DATA_MASK                   (0x07FF)

//! \brief Defines the R/W mask
//!
#define DRV8323_RW_MASK                     (0x8000)

//
// STATUS00
//
//! \brief Defines the R/W mask
//!
#define DRV8323_FAULT_TYPE_MASK             (0x07FF)

#define DRV8323_STATUS00_VDS_LC_BITS        (1 << 0)
#define DRV8323_STATUS00_VDS_HC_BITS        (1 << 1)
#define DRV8323_STATUS00_VDS_LB_BITS        (1 << 2)
#define DRV8323_STATUS00_VDS_HB_BITS        (1 << 3)
#define DRV8323_STATUS00_VDS_LA_BITS        (1 << 4)
#define DRV8323_STATUS00_VDS_HA_BITS        (1 << 5)

//! \brief Defines the location of the OTSD (Over temperature shutdown) bits
//! in the Status 1 register
#define DRV8323_STATUS00_OTSD_BITS          (1 << 6)
#define DRV8323_STATUS00_UVLO_BITS          (1 << 7)
#define DRV8323_STATUS00_GDF_BITS           (1 << 8)
#define DRV8323_STATUS00_VDS_OCP_BITS       (1 << 9)
#define DRV8323_STATUS00_FAULT_BITS         (1 << 10)

//
// STATUS01
//
//! \brief Defines the location of the VGS_LC bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_LC_BITS        (1 << 0)

//! \brief Defines the location of the VGS_HC bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_HC_BITS        (1 << 1)

//! \brief Defines the location of the VGS_LB bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_LB_BITS        (1 << 2)

//! \brief Defines the location of the VGS_HB bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_HB_BITS        (1 << 3)

//! \brief Defines the location of the VGS_LA bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_LA_BITS        (1 << 4)

//! \brief Defines the location of the VGS_HA bits in the Status 2 register
//!
#define DRV8323_STATUS01_VGS_HA_BITS        (1 << 5)

//! \brief Defines the location of the CPUV (charge pump undervoltage) bits in
//! the Status 2 register
#define DRV8323_STATUS01_CPUV_BITS          (1 << 6)

//! \brief Defines the location of the OTW bits in the Status 2 register
//!
#define DRV8323_STATUS01_OTW_BITS           (1 << 7)

//! \brief Defines the location of the SC_OC bits in the Status 2 register
//!
#define DRV8323_STATUS01_SC_OC_BITS         (1 << 8)

//! \brief Defines the location of the SB_OC bits in the Status 2 register
//!
#define DRV8323_STATUS01_SB_OC_BITS         (1 << 9)

//! \brief Defines the location of the SA_OC bits in the Status 2 register
//!
#define DRV8323_STATUS01_SA_OC_BITS         (1 << 10)

//
// CTRL02
//
//! \brief Defines the location of the CLR_FLT bits in the Control 2 register
//!
#define DRV8323_CTRL02_CLR_FLT_BITS         (1 << 0)

//! \brief Defines the location of the BRAKE bits in the Control 2 register
//!
#define DRV8323_CTRL02_BRAKE_BITS           (1 << 1)

//! \brief Defines the location of the COAST bits in the Control 2 register
//!
#define DRV8323_CTRL02_COAST_BITS           (1 << 2)

//! \brief Defines the location of the 1PWM_DIR bits in the Control 2 register
//!
#define DRV8323_CTRL02_PWM1_DIR_BITS        (1 << 3)

//! \brief Defines the location of the 1PWM_COM bits in the Control 2 register
//!
#define DRV8323_CTRL02_PWM1_COM_BITS        (1 << 4)

//! \brief Defines the location of the PWM_MODE bits in the Control 2 register
//!
#define DRV8323_CTRL02_PWM_MODE_BITS        (3 << 5)

//! \brief Defines the location of the OTW_REP bits in the Control 2 register
//!
#define DRV8323_CTRL02_OTW_REP_BITS         (1 << 7)

//! \brief Defines the location of the DIS_GDF bits in the Control 2 register
//!
#define DRV8323_CTRL02_DIS_GDF_BITS         (1 << 8)

//! \brief Defines the location of the DIS_CPUV bits in the Control 2 register
//!
#define DRV8323_CTRL02_DIS_CPUV_BITS        (1 << 9)

//! \brief Defines the location of the RESERVED1 bits in the Control 2 register
//!
#define DRV8323_CTRL02_RESERVED1_BITS       (1 << 10)

//
// CTRL03
//
//! \brief Defines the location of the IDRIVEN_HS bits in the Control 3
//! register
#define DRV8323_CTRL03_IDRIVEN_HS_BITS      (15 << 0)

//! \brief Defines the location of the IDRIVEP_HS bits in the Control 3
//! register
#define DRV8323_CTRL03_IDRIVEP_HS_BITS      (15 << 4)

//! \brief Defines the location of the LOCK bits in the Control 3 register
//!
#define DRV8323_CTRL03_LOCK_BITS            (7 << 8)

//
// CTRL04
//
//! \brief Defines the location of the IDRIVEN_LS bits in the Control 4
//! register
#define DRV8323_CTRL04_IDRIVEN_LS_BITS      (15 << 0)

//! \brief Defines the location of the IDRIVEP_LS bits in the Control 4
//! register
#define DRV8323_CTRL04_IDRIVEP_LS_BITS      (15 << 4)

//! \brief Defines the location of the TDRIVE bits in the Control 4 register
//!
#define DRV8323_CTRL04_TDRIVE_BITS          (3 << 8)

//! \brief Defines the location of the CBC bits in the Control 4 register
//!
#define DRV8323_CTRL04_CBC_BITS             (1 << 10)

//
// CTRL05
//
//! \brief Defines the location of the VDS_LVL bits in the Control 5 register
//!
#define DRV8323_CTRL05_VDS_LVL_BITS         (15 << 0)

//! \brief Defines the location of the OCP_DEG bits in the Control 5 register
//!
#define DRV8323_CTRL05_OCP_DEG_BITS         (3 << 4)

//! \brief Defines the location of the OCP_MODE bits in the Control 5 register
//!
#define DRV8323_CTRL05_OCP_MODE_BITS        (3 << 6)

//! \brief Defines the location of the DEAD_TIME bits in the Control 5 register
//!
#define DRV8323_CTRL05_DEAD_TIME_BITS       (3 << 8)

//! \brief Defines the location of the TRETRY bits in the Control 5 register
//!
#define DRV8323_CTRL05_TRETRY_BITS          (1 << 10)

//
// CTRL06
//
//! \brief Defines the location of the SEN_LVL bits in the Control 6 register
//!
#define DRV8323_CTRL06_SEN_LVL_BITS         (3 << 0)

//! \brief Defines the location of the CSA_CAL_C bits in the Control 6 register
//!
#define DRV8323_CTRL06_CSA_CAL_C_BITS       (1 << 2)

//! \brief Defines the location of the CSA_CAL_B bits in the Control 6 register
//!
#define DRV8323_CTRL06_CSA_CAL_B_BITS       (1 << 3)

//! \brief Defines the location of the CSA_CAL_A bits in the Control 6 register
//!
#define DRV8323_CTRL06_CSA_CAL_A_BITS       (1 << 4)

//! \brief Defines the location of the DIS_SEN bits in the Control 6 register
//!
#define DRV8323_CTRL06_DIS_SEN_BITS         (1 << 5)

//! \brief Defines the location of the CSA_GAIN bits in the Control 6 register
//!
#define DRV8323_CTRL06_CSA_GAIN_BITS        (3 << 6)

//! \brief Defines the location of the LS_REF bits in the Control 6 register
//!
#define DRV8323_CTRL06_LS_REF_BITS          (1 << 8)

//! \brief Defines the location of the VREF_DIV bits in the Control 6 register
//!
#define DRV8323_CTRL06_VREF_DIV_BITS        (1 << 9)

//! \brief Defines the location of the CSA_FET bits in the Control 6 register
//!
#define DRV8323_CTRL06_CSA_FET_BITS         (1 << 10)

// **************************************************************************
// the typedefs

//------------------------------------------------------------------------------
//! \brief Enumeration for the R/W modes
//!
typedef enum
{
    DRV8323_CTRLMODE_WRITE    = 0,  //!< Write Mode
    DRV8323_CTRLMODE_READ     = 1   //!< Read Mode
} DRV8323_CtrlMode_e;

//! \brief Enumeration for the register addresses
//!
typedef enum
{
    DRV8323_ADDRESS_STATUS_0  = (0 << 11),  //!< Status Register 0
    DRV8323_ADDRESS_STATUS_1  = (1 << 11),  //!< Status Register 1
    DRV8323_ADDRESS_CONTROL_2 = (2 << 11),  //!< Control Register 2
    DRV8323_ADDRESS_CONTROL_3 = (3 << 11),  //!< Control Register 3
    DRV8323_ADDRESS_CONTROL_4 = (4 << 11),  //!< Control Register 4
    DRV8323_ADDRESS_CONTROL_5 = (5 << 11),  //!< Control Register 5
    DRV8323_ADDRESS_CONTROL_6 = (6 << 11)   //!< Control Register 6
} DRV8323_Address_e;

//! \brief Enumeration for the Status 0 register, faults
//!
typedef enum
{
    DRV8323_VDS_LC      = (1 << 0),    //!< VDS overcurrent fault on C low-side MOSFET
    DRV8323_VDS_HC      = (1 << 1),    //!< VDS overcurrent fault on C high-side MOSFET
    DRV8323_VDS_LB      = (1 << 2),    //!< VDS overcurrent fault on B low-side MOSFET
    DRV8323_VDS_HB      = (1 << 3),    //!< VDS overcurrent fault on B high-side MOSFET
    DRV8323_VDS_LA      = (1 << 4),    //!< VDS overcurrent fault on A low-side MOSFET
    DRV8323_VDS_HA      = (1 << 5),    //!< VDS overcurrent fault on A high-side MOSFET
    DRV8323_OTSD        = (1 << 6),    //!< Overtemperature shutdown
    DRV8323_UVLO        = (1 << 7),    //!< Undervoltage lockout fault condition
    DRV8323_GDF         = (1 << 8),    //!< Gate driver fault condition
    DRV8323_VDS_OCP     = (1 << 9),    //!< VDS monitor overcurrent fault condition
    DRV8323_FAULT       = (1 << 10)    //!< FAULT type, 0-Warning, 1-Latched
} DRV8323_STATUS00_WarningWatchdog_e;

//! \brief Enumeration for the Status 1 register, OV/VDS faults
//!
typedef enum
{
    DRV8323_VGS_LC      = (1 << 0),    //!< VGS gate drive fault on C low-side MOSFET
    DRV8323_VGS_HC      = (1 << 1),    //!< VGS gate drive fault on C high-side MOSFET
    DRV8323_VGS_LB      = (1 << 2),    //!< VGS gate drive fault on B low-side MOSFET
    DRV8323_VGS_HB      = (1 << 3),    //!< VGS gate drive fault on B high-side MOSFET
    DRV8323_VGS_LA      = (1 << 4),    //!< VGS gate drive fault on A low-side MOSFET
    DRV8323_VGS_HA      = (1 << 5),    //!< VGS gate drive fault on A high-side MOSFET
    DRV8323_CPUV        = (1 << 6),    //!< charge pump undervoltage fault
    DRV8323_OTW         = (1 << 7),    //!< overtemperature warning
    DRV8323_SC_OC       = (1 << 8),    //!< overcurrent on phase C
    DRV8323_SB_OC       = (1 << 9),    //!< overcurrent on phase B
    DRV8323_SA_OC       = (1 << 10)    //!< overcurrent on phase A
} DRV8323_STATUS01_OvVdsFaults_e;

//! \brief Enumeration for the driver PWM mode
//!
typedef enum
{
    DRV8323_PWMMODE_6 = 0,     //!< PWM_MODE = 6 inputs
    DRV8323_PWMMODE_3 = 1,     //!< PWM_MODE = 3 inputs
    DRV8323_PWMMODE_1 = 2      //!< PWM_MODE = 1 input
} DRV8323_CTRL02_PWMMode_e;

//! \brief Enumeration for the high side gate drive peak source current;
//! gate currents not consistent with DS
//!
typedef enum
{
    DRV8323_ISOUR_HS_0P010_A = 0,  //!< IDRIVEP_HS = 0.010A
    DRV8323_ISOUR_HS_0P030_A = 1,  //!< IDRIVEP_HS = 0.030A
    DRV8323_ISOUR_HS_0P060_A = 2,  //!< IDRIVEP_HS = 0.060A
    DRV8323_ISOUR_HS_0P080_A = 3,  //!< IDRIVEP_HS = 0.080A
    DRV8323_ISOUR_HS_0P120_A = 4,  //!< IDRIVEP_HS = 0.120A
    DRV8323_ISOUR_HS_0P140_A = 5,  //!< IDRIVEP_HS = 0.140A
    DRV8323_ISOUR_HS_0P170_A = 6,  //!< IDRIVEP_HS = 0.170A
    DRV8323_ISOUR_HS_0P190_A = 7,  //!< IDRIVEP_HS = 0.190A
    DRV8323_ISOUR_HS_0P260_A = 8,  //!< IDRIVEP_HS = 0.260A
    DRV8323_ISOUR_HS_0P330_A = 9,  //!< IDRIVEP_HS = 0.330A
    DRV8323_ISOUR_HS_0P370_A = 10, //!< IDRIVEP_HS = 0.370A
    DRV8323_ISOUR_HS_0P440_A = 11, //!< IDRIVEP_HS = 0.440A
    DRV8323_ISOUR_HS_0P570_A = 12, //!< IDRIVEP_HS = 0.570A
    DRV8323_ISOUR_HS_0P680_A = 13, //!< IDRIVEP_HS = 0.680A
    DRV8323_ISOUR_HS_0P820_A = 14, //!< IDRIVEP_HS = 0.820A
    DRV8323_ISOUR_HS_1P000_A = 15  //!< IDRIVEP_HS = 1.000A
} DRV8323_CTRL03_PeakSourCurHS_e;

//! \brief Enumeration for the high side gate drive peak sink current;
//! gate currents not consistent with DS
//!
typedef enum
{
    DRV8323_ISINK_HS_0P020_A = 0,  //!< IDRIVEN_HS = 0.020A
    DRV8323_ISINK_HS_0P060_A = 1,  //!< IDRIVEN_HS = 0.060A
    DRV8323_ISINK_HS_0P120_A = 2,  //!< IDRIVEN_HS = 0.120A
    DRV8323_ISINK_HS_0P160_A = 3,  //!< IDRIVEN_HS = 0.160A
    DRV8323_ISINK_HS_0P240_A = 4,  //!< IDRIVEN_HS = 0.240A
    DRV8323_ISINK_HS_0P280_A = 5,  //!< IDRIVEN_HS = 0.280A
    DRV8323_ISINK_HS_0P340_A = 6,  //!< IDRIVEN_HS = 0.340A
    DRV8323_ISINK_HS_0P380_A = 7,  //!< IDRIVEN_HS = 0.380A
    DRV8323_ISINK_HS_0P520_A = 8,  //!< IDRIVEN_HS = 0.520A
    DRV8323_ISINK_HS_0P660_A = 9,  //!< IDRIVEN_HS = 0.660A
    DRV8323_ISINK_HS_0P740_A = 10, //!< IDRIVEN_HS = 0.740A
    DRV8323_ISINK_HS_0P880_A = 11, //!< IDRIVEN_HS = 0.880A
    DRV8323_ISINK_HS_1P140_A = 12, //!< IDRIVEN_HS = 1.140A
    DRV8323_ISINK_HS_1P360_A = 13, //!< IDRIVEN_HS = 1.360A
    DRV8323_ISINK_HS_1P640_A = 14, //!< IDRIVEN_HS = 1.640A
    DRV8323_ISINK_HS_2P000_A = 15  //!< IDRIVEN_HS = 2.000A
} DRV8323_CTRL03_PeakSinkCurHS_e;

//! \brief Enumeration for the high side and low side gate drive peak source
//! time; adapt timings to DRV8323
//!
typedef enum
{
    DRV8323_LOCK_UNLOCK   = 3,           //!< Unlock settings
    DRV8323_LOCK_LOCK     = 6,          //!< Lock settings
} DRV8323_CTRL03_Lock_e;

//! \brief Enumeration for the high side and low side gate drive peak source
//! time; adapt timings to DRV8323
//!
typedef enum
{
    DRV8323_TSOUR_500_NS  = 0,     //!< TDRIVE = 500ns
    DRV8323_TSOUR_1000_NS = 1,     //!< TDRIVE = 1000ns
    DRV8323_TSOUR_2000_NS = 2,     //!< TDRIVE = 2000ns
    DRV8323_TSOUR_4000_NS = 3      //!< TDRIVE = 4000ns
} DRV8323_CTRL04_PeakTime_e;

//! \brief Enumeration for the low side gate drive peak source current;
//!  adapt current ratings
//!
typedef enum
{
    DRV8323_ISOUR_LS_0P010_A = 0,  //!< IDRIVEP_LS = 0.010A
    DRV8323_ISOUR_LS_0P030_A = 1,  //!< IDRIVEP_LS = 0.030A
    DRV8323_ISOUR_LS_0P060_A = 2,  //!< IDRIVEP_LS = 0.060A
    DRV8323_ISOUR_LS_0P080_A = 3,  //!< IDRIVEP_LS = 0.080A
    DRV8323_ISOUR_LS_0P120_A = 4,  //!< IDRIVEP_LS = 0.120A
    DRV8323_ISOUR_LS_0P140_A = 5,  //!< IDRIVEP_LS = 0.140A
    DRV8323_ISOUR_LS_0P170_A = 6,  //!< IDRIVEP_LS = 0.170A
    DRV8323_ISOUR_LS_0P190_A = 7,  //!< IDRIVEP_LS = 0.190A
    DRV8323_ISOUR_LS_0P260_A = 8,  //!< IDRIVEP_LS = 0.260A
    DRV8323_ISOUR_LS_0P330_A = 9,  //!< IDRIVEP_LS = 0.330A
    DRV8323_ISOUR_LS_0P370_A = 10, //!< IDRIVEP_LS = 0.370A
    DRV8323_ISOUR_LS_0P440_A = 11, //!< IDRIVEP_LS = 0.440A
    DRV8323_ISOUR_LS_0P570_A = 12, //!< IDRIVEP_LS = 0.570A
    DRV8323_ISOUR_LS_0P680_A = 13, //!< IDRIVEP_LS = 0.680A
    DRV8323_ISOUR_LS_0P820_A = 14, //!< IDRIVEP_LS = 0.820A
    DRV8323_ISOUR_LS_1P000_A = 15  //!< IDRIVEP_LS = 1.000A
} DRV8323_CTRL04_PeakSourCurLS_e;

//! \brief Enumeration for the low side gate drive peak sink current;
//!  adapt current ratings
//!
typedef enum
{
    DRV8323_ISINK_LS_0P020_A = 0,  //!< IDRIVEN_LS = 0.020A
    DRV8323_ISINK_LS_0P060_A = 1,  //!< IDRIVEN_LS = 0.060A
    DRV8323_ISINK_LS_0P120_A = 2,  //!< IDRIVEN_LS = 0.120A
    DRV8323_ISINK_LS_0P160_A = 3,  //!< IDRIVEN_LS = 0.160A
    DRV8323_ISINK_LS_0P240_A = 4,  //!< IDRIVEN_LS = 0.240A
    DRV8323_ISINK_LS_0P280_A = 5,  //!< IDRIVEN_LS = 0.280A
    DRV8323_ISINK_LS_0P340_A = 6,  //!< IDRIVEN_LS = 0.340A
    DRV8323_ISINK_LS_0P380_A = 7,  //!< IDRIVEN_LS = 0.380A
    DRV8323_ISINK_LS_0P520_A = 8,  //!< IDRIVEN_LS = 0.520A
    DRV8323_ISINK_LS_0P660_A = 9,  //!< IDRIVEN_LS = 0.660A
    DRV8323_ISINK_LS_0P740_A = 10, //!< IDRIVEN_LS = 0.740A
    DRV8323_ISINK_LS_0P880_A = 11, //!< IDRIVEN_LS = 0.880A
    DRV8323_ISINK_LS_1P140_A = 12, //!< IDRIVEN_LS = 1.140A
    DRV8323_ISINK_LS_1P360_A = 13, //!< IDRIVEN_LS = 1.360A
    DRV8323_ISINK_LS_1P640_A = 14, //!< IDRIVEN_LS = 1.640A
    DRV8323_ISINK_LS_2P000_A = 15  //!< IDRIVEN_LS = 2.000A
} DRV8323_CTRL04_PeakSinkCurLS_e;

//! \brief Enumeration for the VDS comparator threshold
//!
typedef enum
{
    DRV8323_VDS_LEVEL_0P060_V = 0,    //!< VDS_LEVEL = 0.060V
    DRV8323_VDS_LEVEL_0P130_V = 1,    //!< VDS_LEVEL = 0.130V
    DRV8323_VDS_LEVEL_0P200_V = 2,    //!< VDS_LEVEL = 0.200V
    DRV8323_VDS_LEVEL_0P260_V = 3,    //!< VDS_LEVEL = 0.260V
    DRV8323_VDS_LEVEL_0P310_V = 4,    //!< VDS_LEVEL = 0.310V
    DRV8323_VDS_LEVEL_0P450_V = 5,    //!< VDS_LEVEL = 0.450V
    DRV8323_VDS_LEVEL_0P530_V = 6,    //!< VDS_LEVEL = 0.530V
    DRV8323_VDS_LEVEL_0P600_V = 7,    //!< VDS_LEVEL = 0.600V
    DRV8323_VDS_LEVEL_0P680_V = 8,    //!< VDS_LEVEL = 0.680V
    DRV8323_VDS_LEVEL_0P750_V = 9,    //!< VDS_LEVEL = 0.750V
    DRV8323_VDS_LEVEL_0P940_V = 10,   //!< VDS_LEVEL = 0.940V
    DRV8323_VDS_LEVEL_1P130_V = 11,   //!< VDS_LEVEL = 1.130V
    DRV8323_VDS_LEVEL_1P300_V = 12,   //!< VDS_LEVEL = 1.300V
    DRV8323_VDS_LEVEL_1P500_V = 13,   //!< VDS_LEVEL = 1.500V
    DRV8323_VDS_LEVEL_1P700_V = 14,   //!< VDS_LEVEL = 1.700V
    DRV8323_VDS_LEVEL_1P880_V = 15    //!< VDS_LEVEL = 1.880V
} DRV8323_CTRL05_VDSLVL_e;

//! \brief Enumeration for the OCP/VDS sense deglitch time;
//!  adapt deglitch time comments
//!
typedef enum
{
    DRV8323_VDSDEG_2_US = 0,       //!< OCP_DEG = 2us
    DRV8323_VDSDEG_4_US = 1,       //!< OCP_DEG = 4us
    DRV8323_VDSDEG_6_US = 2,       //!< OCP_DEG = 6us
    DRV8323_VDSDEG_8_US = 3        //!< OCP_DEG = 8us
} DRV8323_CTRL05_OcpDeg_e;

//! \brief Enumeration for the OCP report mode
//!
typedef enum
{
    DRV8323_LATCHED_SHUTDOWN = 0,  //!< OCP_MODE = Latched fault
    DRV8323_AUTOMATIC_RETRY  = 1,  //!< OCP_MODE = Automatic Retry
    DRV8323_REPORT_ONLY      = 2,  //!< OCP_MODE = Report only
    DRV8323_DISABLE_OCP      = 3   //!< OCP_MODE = Disabled
} DRV8323_CTRL05_OcpMode_e;

//! \brief Enumeration for the driver dead time
//!
typedef enum
{
    DRV8323_DEADTIME_50_NS  = 0,   //!< DEAD_TIME = 50ns
    DRV8323_DEADTIME_100_NS = 1,   //!< DEAD_TIME = 100ns
    DRV8323_DEADTIME_200_NS = 2,   //!< DEAD_TIME = 200ns
    DRV8323_DEADTIME_400_NS = 3    //!< DEAD_TIME = 400ns
} DRV8323_CTRL05_DeadTime_e;

//! \brief Enumeration for the Sense OCP level
//!
typedef enum
{
    DRV8323_SEN_Lvl_Ocp_0p25 = 0,  //!< SEN_LVL = 0.25V
    DRV8323_SEN_Lvl_Ocp_0p50 = 1,  //!< SEN_LVL = 0.50V
    DRV8323_SEN_Lvl_Ocp_0p75 = 2,  //!< SEN_LVL = 0.75V
    DRV8323_SEN_Lvl_Ocp_1p00 = 3   //!< SEN_LVL = 1.00V
} DRV8323_CTRL06_SENLevel_e;


//! \brief Enumeration for the gain of shunt amplifier
//!
typedef enum
{
    DRV8323_Gain_5VpV  = 0,      //!< GAIN_CSA = 5V/V
    DRV8323_Gain_10VpV = 1,      //!< GAIN_CSA = 10V/V
    DRV8323_Gain_20VpV = 2,      //!< GAIN_CSA = 20V/V
    DRV8323_Gain_40VpV = 3       //!< GAIN_CSA = 40V/V
} DRV8323_CTRL06_CSAGain_e;

//------------------------------------------------------------------------------
//! \brief Object for the DRV8323 STATUS00 register
//!
struct DRV8323_STAT00_BITS {                    // bits description
    bool                VDS_LC:1;         // Bits 0
    bool                VDS_HC:1;         // Bits 1
    bool                VDS_LB:1;         // Bits 2
    bool                VDS_HB:1;         // Bits 3
    bool                VDS_LA:1;         // Bits 4
    bool                VDS_HA:1;         // Bits 5
    bool                OTSD:1;           // Bits 6
    bool                UVLO:1;           // Bits 7
    bool                GDF:1;            // Bits 8
    bool                VDS_OCP:1;        // Bits 9
    bool                FAULT:1;          // Bits 10
    uint16_t            rsvd2:5;          // 15:11 Reserved
};

union DRV8323_STAT00_REG
{
    uint16_t all;
    struct   DRV8323_STAT00_BITS bit;
};

//! \brief Object for the DRV8323 STATUS01 register
//!
struct DRV8323_STAT01_BITS {                    // bits description
    bool                VGS_LC:1;         // Bits 0
    bool                VGS_HC:1;         // Bits 1
    bool                VGS_LB:1;         // Bits 2
    bool                VGS_HB:1;         // Bits 3
    bool                VGS_LA:1;         // Bits 4
    bool                VGS_HA:1;         // Bits 5
    bool                CPUV:1;           // Bits 6
    bool                OTW:1;            // Bits 7
    bool                SC_OC:1;          // Bits 8
    bool                SB_OC:1;          // Bits 9
    bool                SA_OC:1;          // Bits 10
    uint16_t            rsvd2:5;          // 15:11 Reserved
};

union DRV8323_STAT01_REG
{
    uint16_t all;
    struct   DRV8323_STAT01_BITS bit;
};

//! \brief Object for the DRV8323 CTRL02 register
//!
struct DRV8323_CTRL02_BITS {                    // bits description
    bool                        CLR_FLT:1;        // Bits 0
    bool                        BRAKE:1;          // Bits 1
    bool                        COAST:1;          // Bits 2
    bool                        PWM1_DIR:1;       // Bits 3
    bool                        PWM1_COM:1;       // Bits 4
    DRV8323_CTRL02_PWMMode_e    PWM_MODE:2;       // Bits 6-5
    bool                        OTW_REP:1;        // Bits 7
    bool                        DIS_GDF:1;        // Bits 8
    bool                        DIS_CPUV:1;       // Bits 9
    bool                        rsvd1:1;          // Bits 10
    uint16_t                    rsvd2:5;          // 15:11 Reserved
};

union DRV8323_CTRL02_REG
{
    uint16_t all;
    struct   DRV8323_CTRL02_BITS bit;
};

//! \brief Object for the DRV8323 CTRL03 register
//!
struct DRV8323_CTRL03_BITS {                    // bits description
    DRV8323_CTRL03_PeakSinkCurHS_e  IDRIVEN_HS:4;     // Bits 3-0
    DRV8323_CTRL03_PeakSourCurHS_e  IDRIVEP_HS:4;     // Bits 7-4
    DRV8323_CTRL03_Lock_e           LOCK:3;           // Bits 10-8
    uint16_t                        rsvd:5;           // 15:11 Reserved
};

union DRV8323_CTRL03_REG
{
    uint16_t all;
    struct   DRV8323_CTRL03_BITS bit;
};

//! \brief Object for the DRV8323 CTRL04 register
//!
struct DRV8323_CTRL04_BITS {                    // bits description
    DRV8323_CTRL04_PeakSinkCurLS_e  IDRIVEN_LS:4;     // Bits 3-0
    DRV8323_CTRL04_PeakSourCurLS_e  IDRIVEP_LS:4;     // Bits 7-4
    DRV8323_CTRL04_PeakTime_e       TDRIVE:2;         // Bits 9-8
    bool                            CBC:1;            // Bits 10
    uint16_t                        rsvd:5;           // 15:11 Reserved
};

union DRV8323_CTRL04_REG
{
    uint16_t all;
    struct   DRV8323_CTRL04_BITS bit;
};

//! \brief Object for the DRV8323 CTRL05 register
//!
struct DRV8323_CTRL05_BITS {                    // bits description
    DRV8323_CTRL05_VDSLVL_e     VDS_LVL:4;        // Bits 3-0
    DRV8323_CTRL05_OcpDeg_e     OCP_DEG:2;        // Bits 5-4
    DRV8323_CTRL05_OcpMode_e    OCP_MODE:2;       // Bits 7-6
    DRV8323_CTRL05_DeadTime_e   DEAD_TIME:2;      // Bits 9-8
    bool                        TRETRY:1;         // Bits 10
    uint16_t                    rsvd:5;           // 15:11 Reserved
};

union DRV8323_CTRL05_REG
{
    uint16_t all;
    struct   DRV8323_CTRL05_BITS bit;
};

//! \brief Object for the DRV8323 CTRL05 register
//!
struct DRV8323_CTRL06_BITS {                    // bits description
    DRV8323_CTRL06_SENLevel_e   SEN_LVL:2;        // Bits 1-0
    bool                        CSA_CAL_C:1;      // Bits 2
    bool                        CSA_CAL_B:1;      // Bits 3
    bool                        CSA_CAL_A:1;      // Bits 4
    bool                        DIS_SEN:1;        // Bits 5
    DRV8323_CTRL06_CSAGain_e    CSA_GAIN:2;       // Bits 7-6
    bool                        LS_REF:1;         // Bits 8
    bool                        VREF_DIV:1;       // Bits 9
    bool                        CSA_FET:1;        // Bits 10
    uint16_t                    rsvd:5;           // 15:11 Reserved
};

union DRV8323_CTRL06_REG
{
    uint16_t all;
    struct   DRV8323_CTRL06_BITS bit;
};

//! \brief Object for the DRV8323 registers and commands
//!
typedef struct _DRV8323_VARS_t_
{
    union DRV8323_STAT00_REG    statReg00;
    union DRV8323_STAT01_REG    statReg01;

    union DRV8323_CTRL02_REG    ctrlReg02;
    union DRV8323_CTRL03_REG    ctrlReg03;
    union DRV8323_CTRL04_REG    ctrlReg04;
    union DRV8323_CTRL05_REG    ctrlReg05;
    union DRV8323_CTRL06_REG    ctrlReg06;

    bool                writeCmd;
    bool                readCmd;
    uint16_t            manWriteAddr;
    uint16_t            manReadAddr;
    uint16_t            manWriteData;
    uint16_t            manReadData;
    bool                manWriteCmd;
    bool                manReadCmd;
}DRV8323_VARS_t;

//! \brief Defines the DRV8323_VARS_t handle
//!
typedef struct _DRV8323_VARS_t_ *DRV8323VARS_Handle;

//! \brief Defines the DRV8323 object
//!
typedef struct _DRV8323_Obj_
{
    uint32_t  spiHandle;     //!< handle for the serial peripheral interface
    uint32_t  gpioNumber_CS; //!< GPIO connected to the DRV8323 CS pin
    uint32_t  gpioNumber_EN; //!< GPIO connected to the DRV8323 enable pin
    bool      rxTimeOut;     //!< timeout flag for the RX FIFO
    bool      enableTimeOut; //!< timeout flag for DRV8323 enable
} DRV8323_Obj;

//! \brief Defines the DRV8323 handle
//!
typedef struct _DRV8323_Obj_ *DRV8323_Handle;

//! \brief Defines the DRV8323 Word type
//!
typedef  uint16_t    DRV_Word_t;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

//! \brief     Initializes the DRV8323 object
//! \param[in] pMemory   A pointer to the memory for the DRV8323 object
//! \param[in] numBytes  The number of bytes allocated for the DRV8323
//!                      object, bytes
//! \return    The DRV8323 object handle
extern DRV8323_Handle DRV8323_init(void *pMemory);

//! \brief     Builds the control word
//! \param[in] ctrlMode  The control mode
//! \param[in] regName   The register name
//! \param[in] data      The data
//! \return    The control word
static inline DRV_Word_t DRV8323_buildCtrlWord(
                                            const DRV8323_CtrlMode_e ctrlMode,
                                            const DRV8323_Address_e regAddr,
                                            const uint16_t data)
{
    DRV_Word_t ctrlWord = ctrlMode | regAddr | (data & DRV8323_DATA_MASK);

    return(ctrlWord);
} // end of DRV8323_buildCtrlWord() function

//! \brief     Enables the DRV8323
//! \param[in] handle     The DRV8323 handle
extern void DRV8323_enable(DRV8323_Handle handle);

//! \brief     Sets the SPI handle in the DRV8323
//! \param[in] handle     The DRV8323 handle
//! \param[in] spiHandle  The SPI handle to use
void DRV8323_setSPIHandle(DRV8323_Handle handle,uint32_t spiHandle);

//! \brief     Sets the GPIO number in the DRV8323
//! \param[in] handle       The DRV8323 handle
//! \param[in] gpioHandle   The GPIO number to use
void DRV8323_setGPIOCSNumber(DRV8323_Handle handle,uint32_t gpioNumber);

//! \brief     Sets the GPIO number in the DRV8323
//! \param[in] handle       The DRV8323 handle
//! \param[in] gpioHandle   The GPIO number to use
void DRV8323_setGPIOENNumber(DRV8323_Handle handle,uint32_t gpioNumber);

//! \brief     Resets the enable timeout flag
//! \param[in] handle   The DRV8323 handle
static inline void DRV8323_resetEnableTimeout(DRV8323_Handle handle)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;

    obj->enableTimeOut = false;

    return;
} // end of DRV8323_resetEnableTimeout() function

//! \brief     Resets the RX fifo timeout flag
//! \param[in] handle   The DRV8323 handle
static inline void DRV8323_resetRxTimeout(DRV8323_Handle handle)
{
    DRV8323_Obj *obj = (DRV8323_Obj *)handle;

    obj->rxTimeOut = false;

    return;
} // end of DRV8323_resetRxTimeout() function

//! \brief     Initialize the interface to all DRV8323 SPI variables
//! \param[in] handle  The DRV8323 handle
extern void DRV8323_setupSPI(DRV8323_Handle handle,
                             DRV8323_VARS_t *drv8323Vars);

//! \brief     Reads data from the DRV8323 register
//! \param[in] handle   The DRV8323 handle
//! \param[in] regAddr  The register address
//! \return    The data value
extern uint16_t DRV8323_readSPI(DRV8323_Handle handle,
                                const DRV8323_Address_e regAddr);

//! \brief     Writes data to the DRV8323 register
//! \param[in] handle   The DRV8323 handle
//! \param[in] regAddr  The register name
//! \param[in] data     The data value
extern void DRV8323_writeSPI(DRV8323_Handle handle,
                             const DRV8323_Address_e regAddr,
                             const uint16_t data);

//! \brief     Write to the DRV8323 SPI registers
//! \param[in] handle  The DRV8323 handle
//! \param[in] drv8323Vars  The (DRV8323_VARS_t) structure that contains
//!                           all DRV8323 Status/Control register options
extern void DRV8323_writeData(DRV8323_Handle handle,
                              DRV8323_VARS_t *drv8323Vars);

//! \brief     Read from the DRV8323 SPI registers
//! \param[in] handle  The DRV8323 handle
//! \param[in] drv8323Vars  The (DRV8323_VARS_t) structure that contains
//!                           all DRV8323 Status/Control register options
extern void DRV8323_readData(DRV8323_Handle handle,
                             DRV8323_VARS_t *drv8323Vars);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // end of DRV8323_H definition
