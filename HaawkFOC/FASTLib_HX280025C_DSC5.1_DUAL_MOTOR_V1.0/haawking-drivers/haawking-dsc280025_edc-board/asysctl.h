//###########################################################################
//
// FILE:   asysctl.h
//
// TITLE:  H28x driver for Analog System Control.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2024-01-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#ifndef ASYSCTL_H
#define ASYSCTL_H

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
//! \addtogroup asysctl_api ASysCtl
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_asysctl.h"
#include "inc/hw_adc.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "debug.h"
#include "cpu.h"

//*****************************************************************************
//
// Defines used for setting AnalogReference functions.
// ASysCtl_setAnalogReferenceInternal()
// ASysCtl_setAnalogReferenceExternal()
// ASysCtl_setAnalogReference2P5()
// ASysCtl_setAnalogReference1P65()
//
//*****************************************************************************
#define ASYSCTL_VREFHIA       0x80U    //!< VREFHIA
#define ASYSCTL_VREFHIC       0x8000U  //!< VREFHIC
#define ASYSCTL_ANAREFSEL     0x1U     //!< ANAREFSEL is PMU2.5V or VREFHI
#define ASYSCTL_ANAREF2P5SEL  0x4U     //!< Control ADC input PGA Enable

//*****************************************************************************
//
// Values used for function ASysCtl_selectCMPHNMux() and
// ASysCtl_selectCMPHNMuxValue().  These values can be OR-ed together and
// passed to ASysCtl_selectCMPHNMux().
//
//*****************************************************************************
#define ASYSCTL_CMPHNMUX_SELECT_1 0x1U //!< CMPHNMUX select 1
#define ASYSCTL_CMPHNMUX_SELECT_2 0x2U //!< CMPHNMUX select 2
#define ASYSCTL_CMPHNMUX_SELECT_3 0x4U //!< CMPHNMUX select 3
#define ASYSCTL_CMPHNMUX_SELECT_4 0x8U //!< CMPHNMUX select 4

//*****************************************************************************
//
// Values used for function ASysCtl_selectCMPLNMux() and
// ASysCtl_selectCMPLNMuxValue().  These values can be OR-ed together and
// passed to ASysCtl_selectCMPLNMux().
//
//*****************************************************************************
#define ASYSCTL_CMPLNMUX_SELECT_1 0x1U //!< CMPLNMUX select 1
#define ASYSCTL_CMPLNMUX_SELECT_2 0x2U //!< CMPLNMUX select 2
#define ASYSCTL_CMPLNMUX_SELECT_3 0x4U //!< CMPLNMUX select 3
#define ASYSCTL_CMPLNMUX_SELECT_4 0x8U //!< CMPLNMUX select 4

//*****************************************************************************
//
//! ASysCtl_CMPHPMuxSelect used for function ASysCtl_selectCMPHPMux().
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_CMPHPMUX_SELECT_1 = 0U, //!< CMPHPMUX select 1
    ASYSCTL_CMPHPMUX_SELECT_2 = 3U, //!< CMPHPMUX select 2
    ASYSCTL_CMPHPMUX_SELECT_3 = 6U, //!< CMPHPMUX select 3
    ASYSCTL_CMPHPMUX_SELECT_4 = 9U  //!< CMPHPMUX select 4
} ASysCtl_CMPHPMuxSelect;

//*****************************************************************************
//
//! ASysCtl_CMPLPMuxSelect used for function ASysCtl_selectCMPLPMux().
//
//*****************************************************************************
typedef enum
{
    ASYSCTL_CMPLPMUX_SELECT_1 = 0U, //!< CMPLPMUX select 1
    ASYSCTL_CMPLPMUX_SELECT_2 = 3U, //!< CMPLPMUX select 2
    ASYSCTL_CMPLPMUX_SELECT_3 = 6U, //!< CMPLPMUX select 3
    ASYSCTL_CMPLPMUX_SELECT_4 = 9U  //!< CMPLPMUX select 4
} ASysCtl_CMPLPMuxSelect;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************

//*****************************************************************************
//
//! Enable temperature sensor.
//!
//! This function enables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void
ASysCtl_enableTemperatureSensor(void)
{
    EALLOW;

    //
    // Set the temperature sensor enable bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) |= ASYSCTL_TSNSCTL_ENABLE;

    EDIS;
}

//*****************************************************************************
//
//! Disable temperature sensor.
//!
//! This function disables the temperature sensor output to the ADC.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void
ASysCtl_disableTemperatureSensor(void)
{
    EALLOW;

    //
    // Clear the temperature sensor enable bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_TSNSCTL) &= ~(ASYSCTL_TSNSCTL_ENABLE);

    EDIS;
}

//*****************************************************************************
//
//! Set the analog voltage reference selection to external.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b ASYSCTL_VREFHIA
//! - \b ASYSCTL_VREFHIC
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void
ASysCtl_setAnalogReferenceExternal(uint32_t reference)
{
	ASSERT((reference & (
						 ASYSCTL_VREFHIA |
						 ASYSCTL_VREFHIC
						)) == reference);

    EALLOW;

    //
    // Write selection to the Analog External Reference Select bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) |= ASYSCTL_ANAREFCTL_ANAREFSEL;
	HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFASEL);
	HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFCSEL);
    HWREG(0x38F20) &= ~(0x8);
    EDIS;
}
//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 2.5V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b ASYSCTL_VREFHIA
//! - \b ASYSCTL_VREFHIC
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_setAnalogReference2P5(uint32_t reference)
{
	ASSERT((reference & (
						 ASYSCTL_VREFHIA |
						 ASYSCTL_VREFHIC
						)) == reference);


    EALLOW;

    //
    // Write selection to the Analog Internal Reference Select bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFSEL);
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFASEL);
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFCSEL);
    HWREG(0x38F20) &= ~(0x8);

    EDIS;
}

//*****************************************************************************
//
//! Set the internal analog voltage reference selection to 1.65V.
//!
//! \param reference is the analog reference.
//!
//! The parameter \e reference can be a combination of the following values:
//!
//! - \b ASYSCTL_VREFHIA
//! - \b ASYSCTL_VREFHIC
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_setAnalogReference1P65(uint16_t reference)
{
	ASSERT((reference & (
						 ASYSCTL_VREFHIA |
						 ASYSCTL_VREFHIC
						)) == reference);

    EALLOW;

    //
    // Write selection to the Analog Voltage Reference Select bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) |= (ASYSCTL_ANAREFCTL_ANAREFSEL);
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) |= (ASYSCTL_ANAREFCTL_ANAREFASEL);
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ANAREFCTL) &= ~(ASYSCTL_ANAREFCTL_ANAREFCSEL);
    HWREG(0x38F20) &= ~(0x8);

    EDIS;
}

//*****************************************************************************
//
//! Select the value for CMPHNMXSEL.
//!
//! \param select is a combination of CMPHNMXSEL values.
//!
//! The parameter \e select can be a bitwise OR of the below values:
//!
//! - \b ASYSCTL_CMPHNMUX_SELECT_1
//! - \b ASYSCTL_CMPHNMUX_SELECT_2
//! - \b ASYSCTL_CMPHNMUX_SELECT_3
//! - \b ASYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_selectCMPHNMux(uint16_t select)
{
    ASSERT(select <= 0x7FU);

    EALLOW;

    //
    // Write a select to the mux select bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHNMXSEL) = select;

    EDIS;
}
//*****************************************************************************
//
//! Select the value for individual CMPxHNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b ASYSCTL_CMPHNMUX_SELECT_1
//! - \b ASYSCTL_CMPHNMUX_SELECT_2
//! - \b ASYSCTL_CMPHNMUX_SELECT_3
//! - \b ASYSCTL_CMPHNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_selectCMPHNMuxValue(uint32_t select, uint32_t value)
{
    ASSERT(select <= 0x7FU);
    ASSERT(value <= 1U);

    EALLOW;

    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHNMXSEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHNMXSEL) |= select;
    }

    EDIS;
}
//*****************************************************************************
//
//! Select the value for individual CMPxLNMXSEL.
//!
//! \param select is a combination of CMPLNMXSEL values.
//!
//! The parameter \e select can be the bitwise OR of the below values:
//!
//! - \b ASYSCTL_CMPLNMUX_SELECT_1
//! - \b ASYSCTL_CMPLNMUX_SELECT_2
//! - \b ASYSCTL_CMPLNMUX_SELECT_3
//! - \b ASYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_selectCMPLNMux(uint32_t select)
{
    ASSERT(select <= 0x7FU);

    EALLOW;

    //
    // Write a select to the mux select bit.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPLNMXSEL) = select;

    EDIS;
}

//*****************************************************************************
//
//! Select the value for CMPLNMXSEL.
//!
//! \param select is the CMPxHNMXSEL to be set.
//! \param value is 0 or 1.
//!
//! The parameter \e select can be one of the below values:
//!
//! - \b ASYSCTL_CMPLNMUX_SELECT_1
//! - \b ASYSCTL_CMPLNMUX_SELECT_2
//! - \b ASYSCTL_CMPLNMUX_SELECT_3
//! - \b ASYSCTL_CMPLNMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_selectCMPLNMuxValue(uint32_t select, uint32_t value)
{
    ASSERT(select <= 0x7FU);
    ASSERT(value <= 1U);

    EALLOW;

    //
    // Write a select to the mux select bit.
    //
    if(value == 0U)
    {
        HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPLNMXSEL) &= ~select;
    }
    else if(value == 1U)
    {
        HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPLNMXSEL) |= select;
    }

    EDIS;
}

//*****************************************************************************
//
//! Select the value for CMPHPMXSEL.
//!
//! \param select is of type ASysCtl_CMPHPMuxSelect.
//! \param value is 0, 1, 2, 3, or 4.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b ASYSCTL_CMPHPMUX_SELECT_1
//! - \b ASYSCTL_CMPHPMUX_SELECT_2
//! - \b ASYSCTL_CMPHPMUX_SELECT_3
//! - \b ASYSCTL_CMPHPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void
ASysCtl_selectCMPHPMux(ASysCtl_CMPHPMuxSelect select, uint32_t value)
{
    ASSERT(value <= 4);

    EALLOW;

    //
    // Set the value for the appropriate Mux Select.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHPMXSEL) =
    (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPHPMXSEL) &
    ~((uint32_t)ASYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M << (uint32_t)select)) |
    (value << (uint32_t)select);

    EDIS;
}

//*****************************************************************************
//
//! Select the value for CMPLPMXSEL.
//!
//! \param select is of type ASysCtl_CMPLPMuxSelect.
//! \param value is 0, 1, 2, 3, or 4.
//!
//! This function is used to write a value to one mux select at a time.
//! The parameter \e select can be one of the following values:
//!
//! - \b ASYSCTL_CMPLPMUX_SELECT_1
//! - \b ASYSCTL_CMPLPMUX_SELECT_2
//! - \b ASYSCTL_CMPLPMUX_SELECT_3
//! - \b ASYSCTL_CMPLPMUX_SELECT_4
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void
ASysCtl_selectCMPLPMux(ASysCtl_CMPLPMuxSelect select, uint32_t value)
{
    ASSERT(value <= 4);

    EALLOW;

    //
    // Set the value for the appropriate Mux Select.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPLPMXSEL) =
    (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_CMPLPMXSEL) &
    ~((uint32_t)ASYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M << (uint32_t)select)) |
    (value << (uint32_t)select);

    EDIS;
}

//*****************************************************************************
//
//! Locks the temperature sensor control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockTemperatureSensor(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_TSNSCTL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the analog reference control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockANAREF(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_ANAREFCTL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the voltage monitor control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockVMON(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_VMONCTL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the CMPHPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockCMPHPMux(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPHPMXSEL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the CMPLPMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockCMPLPMux(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPLPMXSEL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the CMPHNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockCMPHNMux(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPHNMXSEL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the CMPLNMXSEL control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockCMPLNMux(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_CMPLNMXSEL;

    EDIS;
}

//*****************************************************************************
//
//! Locks the VREG control register.
//!
//! \return None.
//
//*****************************************************************************
static __always_inline void ASysCtl_lockVREG(void)
{
    EALLOW;

    //
    // Write a 1 to the lock bit in the LOCK register.
    //
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_LOCK) |= ASYSCTL_LOCK_VREGCTL;

    EDIS;
}

//*****************************************************************************
//
//! Enable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - ASYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - ASYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static __always_inline void ASysCtl_enableADCDACLoopback(uint32_t config)
{
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ADCDACLOOPBACK) =
            (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ADCDACLOOPBACK) | config) |
            (0xA5A5UL << ASYSCTL_ADCDACLOOPBACK_KEY_S);
}

//*****************************************************************************
//
//! Disable loopback from DAC to ADCs.
//!
//! \param config can be bitwise OR of the following values:
//! - ASYSCTL_ADCDACLOOPBACK_ENLB2ADCA
//! - ASYSCTL_ADCDACLOOPBACK_ENLB2ADCC
//!
//! \return None
//
//*****************************************************************************
static __always_inline void ASysCtl_disableADCDACLoopback(uint32_t config)
{
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ADCDACLOOPBACK) =
            (HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_ADCDACLOOPBACK) & ~config) |
            (0xA5A5UL << ASYSCTL_ADCDACLOOPBACK_KEY_S);
}

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

#endif // ASYSCTL_H
