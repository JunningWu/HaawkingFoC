/*
 * hal.h
 *
 *  Created on: 2023Äê1ÔÂ30ÈÕ
 *      Author: Kangaihong
 */
//#############################################################################

#ifndef HAL_H
#define HAL_H
#include "always.h"
#include "hx_intrinsics.h"
//! \file   \solutions\fast_uni_lab\f28002x\drivers\include\hal.h
//! \brief  Contains public interface to various functions related
//!         to the HAL object
//!

//! \addtogroup HAL HAL
//! @{
//
//*****************************************************************************

// the includes
#include "userParams.h"

// platforms
#include "hal_obj.h"

extern uint16_t ctrlfuncsLoadStart;
extern uint16_t ctrlfuncsLoadEnd;
extern uint16_t ctrlfuncsLoadSize;
extern uint16_t ctrlfuncsRunStart;
extern uint16_t ctrlfuncsRunEnd;
extern uint16_t ctrlfuncsRunSize;
extern __interrupt void motor1CtrlISR(void);


// 50MHz LSPCLK frequency based on the DEVICE_SYSCLK_FREQ and
#define C28X_LSPCLK_PRESCALE        SYSCTL_LSPCLK_PRESCALE_4
#define C28X_LSPCLK_FREQ            (DEVICE_SYSCLK_FREQ / 4)


#define USER_RAM_START_ADDR         0x20000  // GS0
#define USER_RAM_VARS_SIZE          0x2000

//! Trip Zones all interrupt
//!
#define HAL_TZFLAG_INTERRUPT_ALL    EPWM_TZ_INTERRUPT_DCBEVT2 |                \
                                    EPWM_TZ_INTERRUPT_DCBEVT1 |                \
                                    EPWM_TZ_INTERRUPT_DCAEVT2 |                \
                                    EPWM_TZ_INTERRUPT_DCAEVT1 |                \
                                    EPWM_TZ_INTERRUPT_OST |                    \
                                    EPWM_TZ_INTERRUPT_CBC

#define HAL_TZSEL_SIGNALS_ALL       EPWM_TZ_SIGNAL_CBC1 |                      \
                                    EPWM_TZ_SIGNAL_CBC2 |                      \
                                    EPWM_TZ_SIGNAL_CBC3 |                      \
                                    EPWM_TZ_SIGNAL_CBC4 |                      \
                                    EPWM_TZ_SIGNAL_CBC5 |                      \
                                    EPWM_TZ_SIGNAL_CBC6 |                      \
                                    EPWM_TZ_SIGNAL_DCAEVT2 |                   \
                                    EPWM_TZ_SIGNAL_DCBEVT2 |                   \
                                    EPWM_TZ_SIGNAL_OSHT1 |                     \
                                    EPWM_TZ_SIGNAL_OSHT2 |                     \
                                    EPWM_TZ_SIGNAL_OSHT3 |                     \
                                    EPWM_TZ_SIGNAL_OSHT4 |                     \
                                    EPWM_TZ_SIGNAL_OSHT5 |                     \
                                    EPWM_TZ_SIGNAL_OSHT6 |                     \
                                    EPWM_TZ_SIGNAL_DCAEVT1 |                   \
                                    EPWM_TZ_SIGNAL_DCBEVT1

//! \brief Defines the PWM frequency for PWMDAC
//!
#define HA_PWMDAC_FREQ_KHZ         100.0f

//! \brief Defines the comparator number for current protection
//!
#define HAL_NUM_CMPSS_CURRENT       3

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#define EPWMDAC1_BASE           EPWM6_BASE      // N/A
#define EPWMDAC2_BASE           EPWM6_BASE      // N/A
#define EPWMDAC3_BASE           EPWM6_BASE      // N/A
#define EPWMDAC4_BASE           EPWM6_BASE      // N/A

//------------------------------------------------------------------------------

//! \ Motor 1
#define MTR1_PWM_U_BASE         EPWM1_BASE
#define MTR1_PWM_V_BASE         EPWM2_BASE
#define MTR1_PWM_W_BASE         EPWM3_BASE


#define MTR1_CMPSS_IDC_BASE     CMPSS3_BASE

#define MTR1_CMPSS_U_BASE       CMPSS1_BASE
#define MTR1_CMPSS_V_BASE       CMPSS3_BASE
#define MTR1_CMPSS_W_BASE       CMPSS1_BASE

#define MTR1_XBAROUTPUT         XBAR_OUTPUT7

//! \brief Defines the gpio for enabling Power Module
#define MTR1_GATE_EN_GPIO       29

//! \brief Defines the gpio for the nFAULT of Power Module
#define MTR1_PM_nFAULT_GPIO     34

//! \brief Defines the gpio for the SPI_CS of DRV device
#define MTR1_DRV_SPI_CS_GPIO    8

//! \brief Defines the gpio for calibration
#define MTR1_GATE_CAL_GPIO      27

#define MTR1_SPI_BASE           SPIA_BASE


#define MTR1_QEP_BASE           EQEP1_BASE

#define MTR1_HALL_U_GPIO        14
#define MTR1_HALL_V_GPIO        25
#define MTR1_HALL_W_GPIO        26


//------------------------------------------------------------------------------
// ADC
// Single-shunt
#define MTR1_IDC_TIGGER_SOC     ADC_TRIGGER_EPWM1_SOCB  // EPWM1_SOCB

#define MTR1_IDC1_TIGGER_SOC    ADC_TRIGGER_EPWM2_SOCA  // EPWM2_SOCA
#define MTR1_IDC2_TIGGER_SOC    ADC_TRIGGER_EPWM2_SOCB  // EPWM2_SOCB
#define MTR1_IDC3_TIGGER_SOC    ADC_TRIGGER_EPWM3_SOCA  // EPWM3_SOCA
#define MTR1_IDC4_TIGGER_SOC    ADC_TRIGGER_EPWM3_SOCB  // EPWM3_SOCB

#define MTR1_IDC1_ADC_BASE      ADCC_BASE               // ADCC-A14/C4*
#define MTR1_IDC2_ADC_BASE      ADCC_BASE               // ADCC-A14/C4*
#define MTR1_IDC3_ADC_BASE      ADCC_BASE               // ADCC-A14/C4*
#define MTR1_IDC4_ADC_BASE      ADCC_BASE               // ADCC-A14/C4*

#define MTR1_IDC1_ADCRES_BASE   ADCCRESULT_BASE         // ADCC-A14/C4*
#define MTR1_IDC2_ADCRES_BASE   ADCCRESULT_BASE         // ADCC-A14/C4*
#define MTR1_IDC3_ADCRES_BASE   ADCCRESULT_BASE         // ADCC-A14/C4*
#define MTR1_IDC4_ADCRES_BASE   ADCCRESULT_BASE         // ADCC-A14/C4*

#define MTR1_IDC1_ADC_CH_NUM    ADC_CH_ADCIN4           // ADCC-A14/C4*
#define MTR1_IDC2_ADC_CH_NUM    ADC_CH_ADCIN4           // ADCC-A14/C4*
#define MTR1_IDC3_ADC_CH_NUM    ADC_CH_ADCIN4           // ADCC-A14/C4*
#define MTR1_IDC4_ADC_CH_NUM    ADC_CH_ADCIN4           // ADCC-A14/C4*

#define MTR1_IDC1_ADC_SOC_NUM   ADC_SOC_NUMBER0         // ADCC-A14/C4* -SOC0-PPB1
#define MTR1_IDC2_ADC_SOC_NUM   ADC_SOC_NUMBER1         // ADCC-A14/C4* -SOC1-PPB2
#define MTR1_IDC3_ADC_SOC_NUM   ADC_SOC_NUMBER2         // ADCC-A14/C4* -SOC2-PPB3
#define MTR1_IDC4_ADC_SOC_NUM   ADC_SOC_NUMBER3         // ADCC-A14/C4* -SOC3-PPB4

#define MTR1_IDC1_ADC_PPB_NUM   ADC_PPB_NUMBER1         // ADCC-A14/C4* -SOC0-PPB1
#define MTR1_IDC2_ADC_PPB_NUM   ADC_PPB_NUMBER2         // ADCC-A14/C4* -SOC1-PPB2
#define MTR1_IDC3_ADC_PPB_NUM   ADC_PPB_NUMBER3         // ADCC-A14/C4* -SOC2-PPB3
#define MTR1_IDC4_ADC_PPB_NUM   ADC_PPB_NUMBER4         // ADCC-A14/C4* -SOC3-PPB4

#define MTR1_IDC1_ADCRESLT      MTR1_IDC1_ADCRES_BASE + ADC_O_RESULT0     //
#define MTR1_IDC2_ADCRESLT      MTR1_IDC2_ADCRES_BASE + ADC_O_RESULT1     //
#define MTR1_IDC3_ADCRESLT      MTR1_IDC3_ADCRES_BASE + ADC_O_RESULT2     //
#define MTR1_IDC4_ADCRESLT      MTR1_IDC4_ADCRES_BASE + ADC_O_RESULT3     //

// Three-shunt
#define MTR1_ADC_TIGGER_SOC     ADC_TRIGGER_EPWM1_SOCA  // EPWM1_SOCA
#define MTR1_ADC_I_SAMPLEWINDOW     8//14//
#define MTR1_ADC_V_SAMPLEWINDOW     8//14//

#define MTR1_IU_ADC_BASE        ADCA_BASE               // ADCA-A11*/C0
#define MTR1_IV_ADC_BASE        ADCC_BASE               // ADCC-A14/C4*
#define MTR1_IW_ADC_BASE        ADCC_BASE               // ADCC-A15/C7*
#define MTR1_VU_ADC_BASE        ADCA_BASE               // ADCA-A6*
#define MTR1_VV_ADC_BASE        ADCC_BASE//ADCA_BASE               // ADCC-A3*/C5
#define MTR1_VW_ADC_BASE        ADCA_BASE//ADCC_BASE               // ADCA-A2/C9*
#define MTR1_VDC_ADC_BASE       ADCC_BASE               // ADCC-C6*
#define MTR1_POT_ADC_BASE       ADCA_BASE               // ADCA-A12*/C1

#define MTR1_IU_ADCRES_BASE     ADCARESULT_BASE         // ADCA-A11*/C0
#define MTR1_IV_ADCRES_BASE     ADCCRESULT_BASE         // ADCC-A14/C4*
#define MTR1_IW_ADCRES_BASE     ADCCRESULT_BASE         // ADCC-A15/C7*
#define MTR1_VU_ADCRES_BASE     ADCARESULT_BASE         // ADCA-A6*
#define MTR1_VV_ADCRES_BASE     ADCCRESULT_BASE//ADCARESULT_BASE         // ADCC-A3*/C5
#define MTR1_VW_ADCRES_BASE     ADCARESULT_BASE//ADCCRESULT_BASE         // ADCA-A2/C9*
#define MTR1_VDC_ADCRES_BASE    ADCCRESULT_BASE         // ADCC-C6*
#define MTR1_POT_ADCRES_BASE    ADCARESULT_BASE         // ADCA-A12*/C1

#define MTR1_IU_ADC_CH_NUM      ADC_CH_ADCIN11          // ADCA-A11*/C0
#define MTR1_IV_ADC_CH_NUM      ADC_CH_ADCIN4           // ADCC-A14/C4*
#define MTR1_IW_ADC_CH_NUM      ADC_CH_ADCIN7           // ADCC-A15/C7*
#define MTR1_VU_ADC_CH_NUM      ADC_CH_ADCIN6           // ADCA-A6*
#define MTR1_VV_ADC_CH_NUM      ADC_CH_ADCIN5//ADC_CH_ADCIN3           // ADCC-A3*/C5
#define MTR1_VW_ADC_CH_NUM      ADC_CH_ADCIN2//ADC_CH_ADCIN9           // ADCA-A2/C9*
#define MTR1_VDC_ADC_CH_NUM     ADC_CH_ADCIN6           // ADCC-C6*
#define MTR1_POT_ADC_CH_NUM     ADC_CH_ADCIN12          // ADCA-A12*/C1

#define MTR1_IU_ADC_SOC_NUM     ADC_SOC_NUMBER1         // ADCA-A11*/C10-SOC1-PPB1
#define MTR1_IV_ADC_SOC_NUM     ADC_SOC_NUMBER1         // ADCC-A14/C4* -SOC1-PPB1
#define MTR1_IW_ADC_SOC_NUM     ADC_SOC_NUMBER2         // ADCC-A15/C7* -SOC2-PPB2
#define MTR1_VU_ADC_SOC_NUM     ADC_SOC_NUMBER4         // ADCA-A6*     -SOC4
#define MTR1_VV_ADC_SOC_NUM     ADC_SOC_NUMBER5         // ADCC-A3*/C5  -SOC5
#define MTR1_VW_ADC_SOC_NUM     ADC_SOC_NUMBER5         // ADCA-A2/C9*  -SOC5
#define MTR1_VDC_ADC_SOC_NUM    ADC_SOC_NUMBER6         // ADCC-C6*     -SOC6
#define MTR1_POT_ADC_SOC_NUM    ADC_SOC_NUMBER6         // ADCA-A12*/C1 -SOC6

#define MTR1_IU_ADC_PPB_NUM     ADC_PPB_NUMBER1         // ADCA-A11*/C10-SOC1-PPB1
#define MTR1_IV_ADC_PPB_NUM     ADC_PPB_NUMBER1         // ADCC-A14/C4* -SOC1-PPB1
#define MTR1_IW_ADC_PPB_NUM     ADC_PPB_NUMBER2         // ADCC-A15/C7*- SOC2-PPB2

// only for datalog and PWMDAC
#define MTR1_IU_ADCRESLT        MTR1_IU_ADCRES_BASE + ADC_O_RESULT1     // ADCA-A11*/C10-SOC1
#define MTR1_IV_ADCRESLT        MTR1_IV_ADCRES_BASE + ADC_O_RESULT1     // ADCC-A14/C4* -SOC1
#define MTR1_IW_ADCRESLT        MTR1_IW_ADCRES_BASE + ADC_O_RESULT2     // ADCC-A15/C7*- SOC2

#define MTR1_VU_ADCRESLT        MTR1_VU_ADCRES_BASE + ADC_O_RESULT4     // ADCA-A6*     -SOC4
#define MTR1_VV_ADCRESLT        MTR1_VV_ADCRES_BASE + ADC_O_RESULT5     // ADCC-A3*/C5  -SOC5
#define MTR1_VW_ADCRESLT        MTR1_VW_ADCRES_BASE + ADC_O_RESULT5     // ADCA-A2/C9*  -SOC5
#define MTR1_VDC_ADCRESLT       MTR1_VDC_ADCRES_BASE + ADC_O_RESULT6    // ADCC-C6*     -SOC6
#define MTR1_POT_ADCRESLT       MTR1_POT_ADCRES_BASE + ADC_O_RESULT6    // ADCA-A12*    -SOC6

//------------------------------------------------------------------------------
// interrupt
#define MTR1_PWM_INT_BASE       MTR1_PWM_U_BASE         // EPWM1

#define MTR1_ADC_INT_BASE       ADCC_BASE               // ADCC-C6  -SOC6
#define MTR1_ADC_INT_NUM        ADC_INT_NUMBER1         // ADCC_INT1-SOC6
#define MTR1_ADC_INT_SOC        ADC_SOC_NUMBER6         // ADCC_INT1-SOC6

#define MTR1_PIE_INT_NUM        INT_ADCC1               // ADCC_INT1-SOC6
#define MTR1_CPU_INT_NUM        INTERRUPT_CPU_INT1      // ADCC_INT1-CPU_INT1
#define MTR1_INT_ACK_GROUP      INTERRUPT_ACK_GROUP1    // ADCC_INT1-CPU_INT1

//------------------------------------------------------------------------------
// CMPSS
#define MTR1_IDC_CMPHP_SEL      ASYSCTL_CMPHPMUX_SELECT_3    // CMPSS3-A14/C4*
#define MTR1_IDC_CMPLP_SEL      ASYSCTL_CMPLPMUX_SELECT_3    // CMPSS3-A14/C4*

#define MTR1_IDC_CMPHP_MUX      4                            // CMPSS3-A14/C4*
#define MTR1_IDC_CMPLP_MUX      4                            // CMPSS3-A14/C4*

#define MTR1_IU_CMPHP_SEL       ASYSCTL_CMPHPMUX_SELECT_1    // CMPSS1-A11
#define MTR1_IU_CMPLP_SEL       ASYSCTL_CMPLPMUX_SELECT_1    // CMPSS1-A11, N/A

#define MTR1_IV_CMPHP_SEL       ASYSCTL_CMPHPMUX_SELECT_3    // CMPSS3-C4
#define MTR1_IV_CMPLP_SEL       ASYSCTL_CMPLPMUX_SELECT_3    // CMPSS3-C4

#define MTR1_IW_CMPHP_SEL       ASYSCTL_CMPHPMUX_SELECT_1    // CMPSS1-C7, N/A
#define MTR1_IW_CMPLP_SEL       ASYSCTL_CMPLPMUX_SELECT_1    // CMPSS1-C7

#define MTR1_IU_CMPHP_MUX       1                            // CMPSS1-A11
#define MTR1_IU_CMPLP_MUX       1                            // CMPSS1-A11

#define MTR1_IV_CMPHP_MUX       4                            // CMPSS3-C4
#define MTR1_IV_CMPLP_MUX       4                            // CMPSS3-C4

#define MTR1_IW_CMPHP_MUX       3                            // CMPSS1-C7
#define MTR1_IW_CMPLP_MUX       3                            // CMPSS1-C7

#define MTR1_CMPSS_DACH_VALUE   2048+1024+512
#define MTR1_CMPSS_DACL_VALUE   2048-1024-512

//------------------------------------------------------------------------------
// XBAR-EPWM
#define MTR1_XBAR_TRIP_ADDRL    XBAR_O_TRIP7MUX0TO15CFG
#define MTR1_XBAR_TRIP_ADDRH    XBAR_O_TRIP7MUX16TO31CFG

#define MTR1_IDC_XBAR_EPWM_MUX  XBAR_EPWM_MUX05_CMPSS3_CTRIPL   // CMPSS3-LP
#define MTR1_IDC_XBAR_MUX       XBAR_MUX05                      // CMPSS3-LP

#define MTR1_IU_XBAR_EPWM_MUX   XBAR_EPWM_MUX00_CMPSS1_CTRIPH       // CMPSS1-HP
#define MTR1_IV_XBAR_EPWM_MUX   XBAR_EPWM_MUX04_CMPSS3_CTRIPH_OR_L  // CMPSS3-HP&LP
#define MTR1_IW_XBAR_EPWM_MUX   XBAR_EPWM_MUX01_CMPSS1_CTRIPL       // CMPSS1-LP

#define MTR1_IU_XBAR_MUX        XBAR_MUX00          // CMPSS1-HP
#define MTR1_IV_XBAR_MUX        XBAR_MUX04          // CMPSS3-HP&LP
#define MTR1_IW_XBAR_MUX        XBAR_MUX01          // CMPSS1-LP

#define MTR1_XBAR_INPUT1        XBAR_INPUT1
#define MTR1_TZ_OSHT1           EPWM_TZ_SIGNAL_OSHT1

#define MTR1_XBAR_TRIP          XBAR_TRIP7
#define MTR1_DCTRIPIN           EPWM_DC_COMBINATIONAL_TRIPIN7

#define MTR1_IU_XBAR_OUT_MUX    XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH       // CMPSS1-HP
#define MTR1_IV_XBAR_OUT_MUX    XBAR_OUT_MUX04_CMPSS3_CTRIPOUTH_OR_L  // CMPSS3-HP&LP
#define MTR1_IW_XBAR_OUT_MUX    XBAR_OUT_MUX01_CMPSS1_CTRIPOUTL       // CMPSS1-LP

//! \brief Defines the PWM deadband falling edge delay count (system clocks)
#define MTR1_PWM_DBFED_CNT      8//5           // 50ns

//! \brief Defines the PWM deadband rising edge delay count (system clocks)
#define MTR1_PWM_DBRED_CNT      8//5           // 50ns

// end of definition for site 1 (near emulator) on launchPad

// **************************************************************************
// the typedefs
//------------------------------------------------------------------------------
//! \brief Defines the function to turn LEDs off
//!
#define HAL_turnLEDOff              HAL_setGPIOHigh

//! \brief Defines the function to turn LEDs on
//!
#define HAL_turnLEDOn               HAL_setGPIOLow

//! \brief Defines the function to toggle LEDs
//!
#define HAL_toggleLED               HAL_toggleGPIO

//! \brief Enumeration for the LED numbers
//!


typedef enum
{
    HAL_GPIO_LED1C   = 31,   //!< GPIO pin number for LaunchPad LED 1
    HAL_GPIO_LED2C   = 34,   //!< GPIO pin number for LaunchPad LED 2
    HAL_GPIO_LED1B   = 19,   //!< GPIO pin number for BoostxlPak LED 1
    HAL_GPIO_LED2B   = 19,   //!< GPIO pin number for BoostxlPak LED 2
    HAL_GPIO_ISR_M1  = 39    //!< GPIO pin number for ISR Executing Time
} HAL_GPIO_Number_e;
// BSXL8323RS_REVA

//! \brief Enumeration for the sensor types
//!
typedef enum
{
    HAL_SENSORTYPE_CURRENT = 0,  //!< Enumeration for current sensor
    HAL_SENSORTYPE_VOLTAGE = 1   //!< Enumeration for voltage sensor
} HAL_SensorType_e;

//! \brief Enumeration for the QEP setup
//!
typedef enum
{
    HAL_QEP_QEP1=0,  //!< Select QEP1
    HAL_QEP_QEP2=1   //!< Select QEP2
} HAL_QEPSelect_e;

//! \brief Enumeration for the CPU Timer
//!
typedef enum
{
    HAL_CPU_TIMER0 = 0,  //!< Select CPU Timer0
    HAL_CPU_TIMER1 = 1,  //!< Select CPU Timer1
    HAL_CPU_TIMER2 = 2   //!< Select CPU Timer2
} HAL_CPUTimerNum_e;



// **************************************************************************
// the globals
//extern __interrupt void motor1CtrlISR(void);



extern volatile uint16_t mtrPIEIER;
extern volatile uint16_t mtrIER;

// **************************************************************************
// the function prototypes

//! \brief     Acknowledges an interrupt from the ADC so that another ADC
//!            interrupt can happen again.
//! \param[in] handle     The hardware abstraction layer (HAL) handle
static __UNUSED ALWAYSINLINE void HAL_ackMtr1ADCInt(void)
{
    // clear the ADC interrupt flag
    ADC_clearInterruptStatus(MTR1_ADC_INT_BASE, MTR1_ADC_INT_NUM);

    // Acknowledge interrupt from PIE group
    Interrupt_clearACKGroup(MTR1_INT_ACK_GROUP);

    return;
} // end of HAL_ackADCInt() function


//! \brief      Disables global interrupts
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_disableGlobalInts();


//! \brief      Enables the ADC interrupts
//! \details    Enables the ADC interrupt in the PIE, and CPU.  Enables the 
//!             interrupt to be sent from the ADC peripheral.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableCtrlInts();


//! \brief      Enables the ADC interrupts without CPU interrupts
//! \details    Enables the ADC interrupts to only trigger CLA, and without
//!             interrupting the CPU
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableADCIntsToTriggerCLA(HAL_Handle handle);


//! \brief      Enables the debug interrupt
//! \details    The debug interrupt is used for the real-time debugger.  It is
//!             not needed if the real-time debugger is not used.  Clears
//!             bit 1 of ST1.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableDebugInt();


//! \brief     Enables global interrupts
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableGlobalInts();


//! \brief     Gets the PWM duty cycle times
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] pDutyCycles  A pointer to memory for the duty cycle durations
static inline void
HAL_getDutyCycles(HAL_MTR_Handle handle,uint16_t *pDutyCycles)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  pDutyCycles[0] = EPWM_getCounterCompareValue(obj->pwmHandle[0],
                                               EPWM_COUNTER_COMPARE_A);
  pDutyCycles[1] = EPWM_getCounterCompareValue(obj->pwmHandle[1],
                                               EPWM_COUNTER_COMPARE_A);
  pDutyCycles[2] = EPWM_getCounterCompareValue(obj->pwmHandle[2],
                                               EPWM_COUNTER_COMPARE_A);
  return;
} // end of HAL_getDutyCycles() function


//! \brief     Gets the number of current sensors
//! \param[in] handle  The hardware abstraction layer (HAL) handle
//! \return    The number of current sensors
static inline uint16_t HAL_getNumCurrentSensors(HAL_MTR_Handle handle)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;
  
  return(obj->numCurrentSensors);
} // end of HAL_getNumCurrentSensors() function


//! \brief     Gets the number of voltage sensors
//! \param[in] handle  The hardware abstraction layer (HAL) handle
//! \return    The number of voltage sensors
static inline uint16_t HAL_getNumVoltageSensors(HAL_MTR_Handle handle)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  return(obj->numVoltageSensors);
} // end of HAL_getNumVoltageSensors() function

//! \brief     Gets the pwm enable status
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
//! \return    The pwm enable
static __UNUSED  ALWAYSINLINE bool HAL_getPwmEnableStatus(HAL_MTR_Handle handle)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  return(obj->flagEnablePWM);
} // end of HAL_getPwmStatus() function


//! \brief     Get the period of EPWM time-base module
//! \param[in] handle  The hardware abstraction layer (HAL) handle
//! \return    The periode of EPWM time-base module
static inline uint16_t
HAL_getTimeBasePeriod(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    return(EPWM_getTimeBasePeriod(obj->pwmHandle[0]));
} // end of HAL_getTimeBasePeriod() function


//! \brief      Configures the fault protection logic
//! \details    Sets up the trip zone inputs so that when a comparator
//!             signal from outside the micro-controller trips a fault,
//!             the EPWM peripheral blocks will force the
//!             power switches into a high impedance state.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupMtrFaults(HAL_MTR_Handle handle);

//! \brief      Initializes the hardware abstraction layer (HAL) object
//! \details    Initializes all handles to the microcontroller peripherals.
//!             Returns a handle to the HAL object.
//! \param[in]  pMemory   A pointer to the memory for the hardware abstraction layer object
//! \param[in]  numBytes  The number of bytes allocated for the hardware abstraction layer object, bytes
//! \return     The hardware abstraction layer (HAL) object handle
extern HAL_Handle HAL_init(void *pMemory);


//! \brief      Initializes the hardware abstraction layer (HAL) object
//! \details    Initializes all handles to the microcontroller peripherals.
//!             Returns a handle to the HAL_MTR object.
//! \param[in]  pMemory   A pointer to the memory for the hardware abstraction layer object
//! \param[in]  numBytes  The number of bytes allocated for the hardware abstraction layer object, bytes
//! \return     The hardware abstraction layer (HAL_MTR) object handle
extern HAL_MTR_Handle HAL_MTR1_init(void *pMemory, const size_t numBytes);


//! \brief      Initializes the interrupt vector table
//! \details    Points the ISR to the function mainISR.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
//static inline void HAL_initIntVectorTable(HAL_Handle handle)
static inline void HAL_initIntVectorTable(void)
{
    // Motor_1->ADCA_INT1
    Interrupt_register(MTR1_PIE_INT_NUM, &motor1CtrlISR);

    return;
} // end of HAL_initIntVectorTable() function

//! \brief      Reads the ADC data with offset
//! \details    Reads in the ADC result registers and scales the values
//!             according to the settings in user_m1.h or user_m2.h.
//!             The structure gAdcData holds three phase voltages,
//!             three line currents, and one DC bus voltage.
//! \param[in]  handle    The hardware abstraction layer (HAL) handle
//! \param[in]  pADCData  A pointer to the ADC data buffer
static __UNUSED ALWAYSINLINE void HAL_readMtr1ADCData(HAL_ADCData_t *pADCData)
{
    float32_t value;

    // convert phase A current
//    value = (float32_t)ADC_readPPBResult(MTR1_IU_ADCRES_BASE, MTR1_IU_ADC_PPB_NUM);
    value = (float32_t)ADC_readResult(MTR1_IU_ADCRES_BASE, ADC_SOC_NUMBER1);
    pADCData->I_A.value[0] = value * pADCData->current_sf;

    // convert phase B current
//    value = (float32_t)ADC_readPPBResult(MTR1_IV_ADCRES_BASE, MTR1_IV_ADC_PPB_NUM);
    value = (float32_t)ADC_readResult(MTR1_IV_ADCRES_BASE, ADC_SOC_NUMBER1);
    pADCData->I_A.value[1] = value * pADCData->current_sf;

    // convert phase C current
//    value = (float32_t)ADC_readPPBResult(MTR1_IW_ADCRES_BASE, MTR1_IW_ADC_PPB_NUM);
    value = (float32_t)ADC_readResult(MTR1_IW_ADCRES_BASE, ADC_SOC_NUMBER8);
    pADCData->I_A.value[2] = value * pADCData->current_sf;


    // convert phase A voltage
    value = (float32_t)ADC_readResult(MTR1_VU_ADCRES_BASE, ADC_SOC_NUMBER4);
    pADCData->V_V.value[0] = value * pADCData->voltage_sf;

    // convert phase B voltage
    value = (float32_t)ADC_readResult(MTR1_VV_ADCRES_BASE, ADC_SOC_NUMBER5);
    pADCData->V_V.value[1] = value * pADCData->voltage_sf;

    // convert phase C voltage
    value = (float32_t)ADC_readResult(MTR1_VW_ADCRES_BASE, ADC_SOC_NUMBER7);
    pADCData->V_V.value[2] = value * pADCData->voltage_sf;

    // convert dc bus voltage
    value = (float32_t)ADC_readResult(MTR1_VDC_ADCRES_BASE, ADC_SOC_NUMBER11);
    pADCData->VdcBus_V = value * pADCData->dcBusvoltage_sf;

    return;
} // end of HAL_readMtr1ADCData() functions

//! \brief     Reads the timer count
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
//! \return    The timer count
static inline uint32_t
HAL_readTimerCnt(HAL_Handle handle,const uint16_t timerNumber)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    uint32_t timerCnt = CPUTimer_getTimerCount(obj->timerHandle[timerNumber]);

    return(timerCnt);
} // end of HAL_readTimerCnt() function

//! \brief     Sets the GPIO pin high
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] gpioNumber  The GPIO number
static __UNUSED ALWAYSINLINE void HAL_setGPIOHigh(const uint32_t gpioNumber)
{

  // set GPIO high
  GPIO_writePin(gpioNumber, 1);

  return;
} // end of HAL_setGPIOHigh() function


//! \brief     Read the GPIO pin
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] gpioNumber  The GPIO number
//! \return    The GPIO pin
static __UNUSED ALWAYSINLINE uint32_t
HAL_readGPIOData(const uint32_t gpioNumber)
{
    uint32_t gpioPinData;

    // set GPIO high
    gpioPinData = GPIO_readPin(gpioNumber);

    return(gpioPinData);
} // end of HAL_readGPIOData() function


//! \brief     Sets the GPIO pin low
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] gpioNumber  The GPIO number
static __UNUSED ALWAYSINLINE void HAL_setGPIOLow(const uint32_t gpioNumber)
{
    // set GPIO low
    GPIO_writePin(gpioNumber, 0);

    return;
} // end of HAL_setGPIOLow() function


//! \brief     Sets the value of the internal DAC of the high comparator
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] cmpssNumber The CMPSS number
//! \param[in] dacValue    The DAC value of the high comparator
static inline void
HAL_setCMPSSDACValueHigh(HAL_MTR_Handle handle,
                         const uint16_t cmpssNumber, uint16_t dacValue)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    // set GPIO low
    CMPSS_setDACValueHigh(obj->cmpssHandle[cmpssNumber], dacValue);

    return;
} // end of HAL_setCMPSSDACValueHigh() function


//! \brief     Sets the value of the internal DAC of the low comparator
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] cmpssNumber The CMPSS number
//! \param[in] dacValue    The DAC value of the low comparator
static inline void
HAL_setCMPSSDACValueLow(HAL_MTR_Handle handle,
                        const uint16_t cmpssNumber, uint16_t dacValue)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  // set GPIO low
  CMPSS_setDACValueLow(obj->cmpssHandle[cmpssNumber], dacValue);

  return;
} // end of HAL_setCMPSSDACValueLow() function

//! \brief     Sets the number of voltage sensors
//! \param[in] handle             The hardware abstraction layer (HAL) handle
//! \param[in] numVoltageSensors  The number of voltage sensors
static inline void
HAL_setNumVoltageSensors(HAL_MTR_Handle handle,const uint16_t numVoltageSensors)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  obj->numVoltageSensors = numVoltageSensors;

  return;
} // end of HAL_setNumVoltageSensors() function

//! \brief     Sets the number of current sensors
//! \param[in] handle             The hardware abstraction layer (HAL) handle
//! \param[in] numCurrentSensors  The number of current sensors
static inline void
HAL_setNumCurrentSensors(HAL_MTR_Handle handle,const uint16_t numCurrentSensors)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  obj->numCurrentSensors = numCurrentSensors;

  return;
} // end of HAL_setNumCurrentSensors() function

//! \brief      Sets the hardware abstraction layer parameters
//! \details    Sets up the microcontroller peripherals.  Creates all of the scale
//!             factors for the ADC voltage and current conversions.  Sets the initial
//!             offset values for voltage and current measurements.
//! \param[in]  handle       The hardware abstraction layer (HAL) handle
extern void HAL_setParams(HAL_Handle handle);

//! \brief      Sets the hardware abstraction layer parameters
//! \details    Sets up the microcontroller peripherals.  Creates all of the scale
//!             factors for the ADC voltage and current conversions.  Sets the initial
//!             offset values for voltage and current measurements.
//! \param[in]  handle       The hardware abstraction layer (HAL) handle
extern void HAL_MTR_setParams(HAL_MTR_Handle handle, USER_Params *pUserParams);

//! \brief      Sets up the ADCs (Analog to Digital Converters)
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupADCs(HAL_Handle handle);


//! \brief      Sets up the CMPSSs (Comparator Subsystems)
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupCMPSSs(HAL_MTR_Handle handle);

//! \brief      Sets up the clocks
//! \details    Sets up the micro-controller's main oscillator
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupClks(HAL_Handle handle);

//! \brief     Sets up the GPIO (General Purpose I/O) pins
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupGPIOs();

//! \brief     Sets up the FLASH.
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupFlash(HAL_Handle handle);

//! \brief     Sets up the CLA
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupCLA(HAL_Handle handle);

//! \brief     Sets up the peripheral clocks
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupPeripheralClks();

//! \brief     Sets up the PIE (Peripheral Interrupt Expansion)
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupPIE(HAL_Handle handle);

//! \brief     Sets up the QEP peripheral
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupQEP(HAL_MTR_Handle handle);

//! \brief     Sets up the SCIA
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupSCIA(HAL_Handle handle);

//! \brief     Sets up the I2CA
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupI2CA(HAL_Handle halHandle);

// Declare HAL_setupGate and HAL_enableDRV

//! \brief      Enables the drv8323/drv8353/drv8316 device
//! \details    Provides the correct timing to enable the drv8323/8353/8316
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableDRV(HAL_MTR_Handle handle);

//! \brief     Sets up the GATE object
//! \param[in] handle       The hardware abstraction layer (HAL) handle
extern void HAL_setupGate(HAL_MTR_Handle handle);

//! \brief     Writes data to the driver
//! \param[in] handle         The hardware abstraction layer (HAL) handle
//! \param[in] drv8323Vars  SPI variables
void HAL_writeDRVData(HAL_MTR_Handle handle, DRVIC_VARS_t *drvicVars);

//! \brief     Reads data from the driver
//! \param[in] handle         The hardware abstraction layer (HAL) handle
//! \param[in] drv8323Vars  SPI variables
void HAL_readDRVData(HAL_MTR_Handle handle, DRVIC_VARS_t *drvicVars);

//! \brief     Sets up the SPI interface for the driver
//! \param[in] handle         The hardware abstraction layer (HAL) handle
//! \param[in] drv8323Vars  SPI variables
extern void HAL_setupDRVSPI(HAL_MTR_Handle handle, DRVIC_VARS_t *drvicVars);

//! \brief     Sets up the SPI
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupSPI(HAL_MTR_Handle handle);
       // BSXL8323RS_REVA || BSXL8353RS_REVA || BSXL8316RT_REVA

//! \brief     Sets up the GATE object
//! \param[in] handle       The hardware abstraction layer (HAL) handle
extern void HAL_setupGate(HAL_MTR_Handle handle);

//! \brief      Enables the drv8323/8353/8316 device
//! \details    Provides the correct timing to enable the drv8323/8353/8316
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableDRV(HAL_MTR_Handle handle);

//! \brief     Sets up the GATE object
//! \param[in] handle       The hardware abstraction layer (HAL) handle
extern void HAL_setupGate(HAL_MTR_Handle handle);

//! \brief      Enables the high voltage kit device
//! \details    Provides the correct timing to enable the high voltage kit
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableDRV(HAL_MTR_Handle handle);


//! \brief     Sets up the CPU timer for time base
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] systemFreq_MHz  The system frequency, MHz
extern void HAL_setupTimeBaseTimer(HAL_Handle handle,
                                   const float32_t timeBaseFreq_Hz);

//! \brief     Sets up the CPU timer for ADC trigger
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] systemFreq_MHz  The system frequency, MHz
extern void HAL_setupADCTriggerTimer(HAL_Handle handle,
                                     const float32_t adcTriggerFreq_Hz);

//! \brief     Sets up the timers for CPU usage diagnostics
//! \param[in] handle          The hardware abstraction layer (HAL) handle
extern void HAL_setupCPUUsageTimer(HAL_Handle handle);

//! \brief     Sets up the timers
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] cpuTimerNumber  The CPU timer number
static inline void
HAL_clearCPUTimerFlag(HAL_Handle halHandle, const uint16_t cpuTimerNumber)
{
    HAL_Obj   *obj = (HAL_Obj *)halHandle;

    CPUTimer_clearOverflowFlag(obj->timerHandle[cpuTimerNumber]);

    return;
}   // end of HAL_clearTimerFlag() function


//! Sets the CPU timer period count.
//! \param base is the base address of the timer module.
//! \param timerCount is the CPU timer timer count.
static inline void HAL_setCPUTimerCount(HAL_Handle halHandle, uint32_t timerCount)
{
    HAL_Obj   *obj = (HAL_Obj *)halHandle;

    //
    // Load the MSB timer Count
    //
    HWREG(obj->timerHandle[1] + CPUTIMER_O_TIM) = timerCount;

    return;
}

//! \brief     Gets CPU Timer status
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] cpuTimerNumber  The CPU timer number
static inline bool
HAL_getCPUTimerStatus(HAL_Handle halHandle, const uint16_t cpuTimerNumber)
{
    HAL_Obj   *obj = (HAL_Obj *)halHandle;

    return (CPUTimer_getTimerOverflowStatus(obj->timerHandle[cpuTimerNumber]));
}

//! \brief     Sets up the DMA
//! \param[in] N/A
void HAL_setupDMA(void);

//! \brief     Toggles the GPIO pin
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] gpioNumber  The GPIO number
static __UNUSED ALWAYSINLINE void HAL_toggleGPIO(const uint32_t gpioNumber)
{

    // set GPIO high
    GPIO_togglePin(gpioNumber);

    return;
} // end of HAL_toggleGPIO() function

//! \brief     Writes DAC data to the PWM comparators for DAC output
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pPWMDACData  The pointer to the DAC data
void HAL_setPWMDACParameters(HAL_Handle handle, HAL_PWMDACData_t *pPWMDACData);

//! \brief
//! \param[in]
//! \param[in]
void HAL_clearDataRAM(void *pMemory, uint16_t lengthMemory);

//! \brief     Reads PWM period register
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
//! \return    The PWM period value
static inline uint16_t
HAL_readPWMPeriod(HAL_MTR_Handle handle,const uint16_t pwmNumber)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  // the period value to be returned
  uint16_t pwmPeriodValue;

  pwmPeriodValue = EPWM_getTimeBasePeriod(obj->pwmHandle[pwmNumber]);

  return(pwmPeriodValue);
} // end of HAL_readPWMPeriod() function

//! \brief     Writes PWM data to the PWM comparators for motor control
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pPWMData  The pointer to the PWM data
static __UNUSED ALWAYSINLINE void
HAL_writePWMData(HAL_MTR_Handle handle, HAL_PWMData_t *pPWMData)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    float32_t period = (float32_t)(EPWM_getTimeBasePeriod(obj->pwmHandle[0]));

    uint16_t pwmCnt;

    for(pwmCnt=0; pwmCnt<3; pwmCnt++)
    {
      // compute the value
        float32_t V_pu = -pPWMData->Vabc_pu.value[pwmCnt];      // Negative
        float32_t V_sat_pu = __fsat(V_pu, 0.5f, -0.5f);           // -0.5~0.5
        float32_t V_sat_dc_pu = V_sat_pu + 0.5;                 // 0~1.0
        pPWMData->cmpValue[pwmCnt]  = (int16_t)(V_sat_dc_pu * period);  //

        if(pPWMData->cmpValue[pwmCnt] < pPWMData->minCMPValue)
        {
            pPWMData->cmpValue[pwmCnt] = pPWMData->minCMPValue;
        }

        // write the PWM data value
        EPWM_setCounterCompareValue(obj->pwmHandle[pwmCnt],
                                    EPWM_COUNTER_COMPARE_A,
                                    pPWMData->cmpValue[pwmCnt]);

        EPWM_setCounterCompareValue(obj->pwmHandle[pwmCnt],
                                    EPWM_COUNTER_COMPARE_B,
                                    pPWMData->cmpValue[pwmCnt]);
    }

    return;
} // end of HAL_writePWMData() function


//! \brief      Enables the PWM devices for motor control
//! \details    Turns on the outputs of the EPWM peripheral which will allow
//!             the power switches to be controlled.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_enablePWM(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    // Clear any comparator digital filter output latch
    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[0]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[0]);

    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[1]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[1]);

    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[2]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[2]);

    // Clear any Trip Zone flag
    EPWM_clearTripZoneFlag(obj->pwmHandle[0], HAL_TZFLAG_INTERRUPT_ALL);
    EPWM_clearTripZoneFlag(obj->pwmHandle[1], HAL_TZFLAG_INTERRUPT_ALL);
    EPWM_clearTripZoneFlag(obj->pwmHandle[2], HAL_TZFLAG_INTERRUPT_ALL);

    obj->flagEnablePWM = true;

    return;
} // end of HAL_enablePWM() function


//! \brief      Enables the PWM for braking
//! \details    Turns on the outputs of the EPWM peripheral which will allow
//!             the power switches to be controlled.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_enableBrakePWM(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;
    uint16_t  cnt;

    for(cnt=0; cnt<3; cnt++)
    {
        // setup the Action-qualifier Continuous Software Force Register (AQCSFRC)
         EPWM_setActionQualifierContSWForceAction(obj->pwmHandle[cnt],
                                                  EPWM_AQ_OUTPUT_A,
                                                  EPWM_AQ_SW_OUTPUT_LOW);

        // setup the Action-qualifier Continuous Software Force Register (AQCSFRC)
         EPWM_setActionQualifierContSWForceAction(obj->pwmHandle[cnt],
                                                  EPWM_AQ_OUTPUT_B,
                                                  EPWM_AQ_SW_OUTPUT_HIGH);

         // setup the Dead-Band Generator Control Register (DBCTL)
         EPWM_setDeadBandDelayMode(obj->pwmHandle[cnt], EPWM_DB_RED, false);
         EPWM_setDeadBandDelayMode(obj->pwmHandle[cnt], EPWM_DB_FED, false);
    }

    obj->flagEnablePWM = false;

    return;
} // end of HAL_enableBrakePWM() function


//! \brief      Enables the PWM for braking
//! \details    Turns on the outputs of the EPWM peripheral which will allow
//!             the power switches to be controlled.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_exitBrakeResetPWM(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;
    uint16_t  cnt;

    for(cnt=0; cnt<3; cnt++)
    {
        // setup the Dead-Band Generator Control Register (DBCTL)
        EPWM_setDeadBandDelayMode(obj->pwmHandle[cnt], EPWM_DB_RED, true);
        EPWM_setDeadBandDelayMode(obj->pwmHandle[cnt], EPWM_DB_FED, true);

        // setup the Action-qualifier Continuous Software Force Register (AQCSFRC)
         EPWM_setActionQualifierContSWForceAction(obj->pwmHandle[cnt],
                                                  EPWM_AQ_OUTPUT_A,
                                                  EPWM_AQ_SW_DISABLED);

        // setup the Action-qualifier Continuous Software Force Register (AQCSFRC)
         EPWM_setActionQualifierContSWForceAction(obj->pwmHandle[cnt],
                                                  EPWM_AQ_OUTPUT_B,
                                                  EPWM_AQ_SW_DISABLED);
    }

    obj->flagEnablePWM = false;

    return;
} // end of HAL_enableBrakePWM() function

//! \brief      clear fault status of motor control
//! \details
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_clearMtrFaultStatus(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    // Clear any comparator digital filter output latch
    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[0]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[0]);

    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[1]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[1]);

    CMPSS_clearFilterLatchHigh(obj->cmpssHandle[2]);
    CMPSS_clearFilterLatchLow(obj->cmpssHandle[2]);

    // Clear any Trip Zone flag
    EPWM_clearTripZoneFlag(obj->pwmHandle[0], HAL_TZFLAG_INTERRUPT_ALL);
    EPWM_clearTripZoneFlag(obj->pwmHandle[1], HAL_TZFLAG_INTERRUPT_ALL);
    EPWM_clearTripZoneFlag(obj->pwmHandle[2], HAL_TZFLAG_INTERRUPT_ALL);

    return;
} // end of HAL_clearMtrFaultStatus() function

//! \brief      Disables the PWM device for motor control
//! \details    Turns off the outputs of the EPWM peripherals which will put
//!             the power switches into a high impedance state.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_disablePWM(HAL_MTR_Handle handle)
{
  HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

  EPWM_forceTripZoneEvent(obj->pwmHandle[0], EPWM_TZ_FORCE_EVENT_OST);
  EPWM_forceTripZoneEvent(obj->pwmHandle[1], EPWM_TZ_FORCE_EVENT_OST);
  EPWM_forceTripZoneEvent(obj->pwmHandle[2], EPWM_TZ_FORCE_EVENT_OST);
  obj->flagEnablePWM = false;

  return;
} // end of HAL_disablePWM() function

//! \brief     Sets up the PWMs (Pulse Width Modulators)
//! \param[in] handle          The hardware abstraction layer (HAL) handle
extern void HAL_setupPWMs(HAL_MTR_Handle handle);

//! \brief     Sets up the PWMs (Pulse Width Modulators)
//! \param[in] handle          The hardware abstraction layer (HAL) handle
static inline uint16_t HAL_getMtrTripFaults(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;
    uint16_t tripFault = 0;

    tripFault = (EPWM_getTripZoneFlagStatus(obj->pwmHandle[0]) &
            (EPWM_TZ_FLAG_OST | EPWM_TZ_FLAG_DCAEVT1 | EPWM_TZ_FLAG_DCAEVT2)) |
                    (EPWM_getTripZoneFlagStatus(obj->pwmHandle[1]) &
            (EPWM_TZ_FLAG_OST | EPWM_TZ_FLAG_DCAEVT1 | EPWM_TZ_FLAG_DCAEVT2)) |
                    (EPWM_getTripZoneFlagStatus(obj->pwmHandle[2]) &
            (EPWM_TZ_FLAG_OST | EPWM_TZ_FLAG_DCAEVT1 | EPWM_TZ_FLAG_DCAEVT2));

    return(tripFault);
}

//! \brief     Sets up the PWMs (Pulse Width Modulators)
//! \param[in] handle          The hardware abstraction layer (HAL) handle
extern void HAL_setMtrCMPSSDACValue(HAL_MTR_Handle handle,
                               const uint16_t dacValH, const uint16_t dacValL);

//! \brief     Set trigger point in the middle of the low side pulse
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] ignoreShunt  The low side shunt that should be ignored
//! \param[in] midVolShunt  The middle length of output voltage
/*static inline void HAL_setTrigger(HAL_MTR_Handle handle, HAL_PWMData_t *pPWMData,
                                  const SVGENCURRENT_IgnoreShunt_e ignoreShunt,
                                  const SVGENCURRENT_VmidShunt_e midVolShunt)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;

    int16_t pwmNum = midVolShunt;
    int16_t pwmCMPA = EPWM_getCounterCompareValue(obj->pwmHandle[pwmNum],
                                                   EPWM_COUNTER_COMPARE_A);

    int16_t pwmSOCCMP = 5;

    if(ignoreShunt == SVGENCURRENT_USE_ALL)
    {
        // Set up event source for ADC trigger
        EPWM_setADCTriggerSource(obj->pwmHandle[0],
                                 EPWM_SOC_A,
                                 EPWM_SOC_TBCTR_D_CMPC);
    }
    else
    {
        pwmSOCCMP = pwmCMPA - pPWMData->deadband - pPWMData->noiseWindow;

        if(pwmSOCCMP <= 0)
        {
            pwmSOCCMP = 5;

            // Set up event source for ADC trigger
            EPWM_setADCTriggerSource(obj->pwmHandle[0],
                                     EPWM_SOC_A,
                                     EPWM_SOC_TBCTR_U_CMPC);
        }
        else
        {
            pwmSOCCMP = 5;

            // Set up event source for ADC trigger
            EPWM_setADCTriggerSource(obj->pwmHandle[0],
                                     EPWM_SOC_A,
                                     EPWM_SOC_TBCTR_D_CMPC);
        }

    }

    //
    pPWMData->socCMP = pwmSOCCMP;

    // write the PWM data value  for ADC trigger
    EPWM_setCounterCompareValue(obj->pwmHandle[0],
                                EPWM_COUNTER_COMPARE_C,
                                pwmSOCCMP);
    return;
} // end of HAL_setTrigger() function
*/
//! \brief     Set trigger point near period for dc-link current offset
//! \param[in] handle       The hardware abstraction layer (HAL) handle
static inline void HAL_setOffsetTrigger(HAL_MTR_Handle handle)
{
    HAL_MTR_Obj *obj = (HAL_MTR_Obj *)handle;
    uint16_t pwmPRD = HAL_getTimeBasePeriod(handle);
    uint16_t offsetUpSoc = pwmPRD*(3.0f/4.0f);
    uint16_t offsetDownSoc = pwmPRD*(1.0f/4.0f);

    //
    // set the SOC trigger point for UP count
    //
    EPWM_setCounterCompareValue(obj->pwmHandle[1],
                                EPWM_COUNTER_COMPARE_C,
                                offsetUpSoc);

    EPWM_setCounterCompareValue(obj->pwmHandle[1],
                                EPWM_COUNTER_COMPARE_D,
                                offsetUpSoc);

    //
    // set the SOC trigger point for DOWN count
    //
    EPWM_setCounterCompareValue(obj->pwmHandle[2],
                                EPWM_COUNTER_COMPARE_C,
                                offsetDownSoc);

    EPWM_setCounterCompareValue(obj->pwmHandle[2],
                                EPWM_COUNTER_COMPARE_D,
                                offsetDownSoc);

    return;
} // end of HAL_setOffsetTrigger() function

//! \brief     Set trigger point in the middle of the low side pulse
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] deadband     The setting deadband for mosfet gate driver
//! \param[in] noisewindow  The noise window
extern void HAL_setTriggerPrams(HAL_PWMData_t *pPWMData, const float32_t systemFreq_MHz,
                   const float32_t deadband_us, const float32_t noiseWindow_us);


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


#endif // end of HAL_H definition

