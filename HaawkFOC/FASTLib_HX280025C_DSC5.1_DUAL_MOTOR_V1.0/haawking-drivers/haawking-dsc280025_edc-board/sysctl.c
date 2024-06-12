//###########################################################################
//
// FILE:   sysctl.c
//
// TITLE:  H28x system control driver.
//
//###########################################################################
// $HAAWKING Release: Hal Driver Support Library V1.0.0 $
// $Release Date: 2023-04-28 06:49:27 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#include "sysctl.h"
#include "dcc.h"
#include "device.h"



//*****************************************************************************
//
// SysCtl_pollX1Counter()
//
//*****************************************************************************
static void
SysCtl_pollX1Counter(void)
{
    uint16_t loopCount = 0U;

    //
    // Delay for 1 ms while the XTAL powers up
    //
    // 2000 loops, 5 cycles per loop + 9 cycles overhead = 10009 cycles
    //
    SysCtl_delay(2000);

    //
    // Clear and saturate X1CNT 4 times to guarantee operation
    //
    do
    {
        //
        // Keep clearing the counter until it is no longer saturated
        //
        while(HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) > 0x1FFU)
        {
            HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) |= SYSCTL_X1CNT_CLR;
        }

        //
        // Wait for the X1 clock to saturate
        //
        while(HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) != SYSCTL_X1CNT_X1CNT_M)
        {
            //
            // If your application is stuck in this loop, please check if the
            // input clock source is valid.
            // If using XTAL clock source on F28002X control card, check the
            // switch S3.
            //
        }

        //
        // Increment the counter
        //
        loopCount++;
    }while(loopCount < 4U);
}

//*****************************************************************************
//
// SysCtl_getClock()
//
//*****************************************************************************
uint32_t
SysCtl_getClock(uint32_t clockInHz)
{
    uint32_t temp;
    uint32_t oscSource;
    uint32_t clockOut;

    //
    // Don't proceed if an MCD failure is detected.
    //
    if(SysCtl_isMCDClockFailureDetected())
    {
        //
        // OSCCLKSRC2 failure detected. Returning the INTOSC1 rate. You need
        // to handle the MCD and clear the failure.
        //
        clockOut = SYSCTL_DEFAULT_OSC_FREQ;
    }
    else
    {
        //
        // If one of the internal oscillators is being used, start from the
        // known default frequency.  Otherwise, use clockInHz parameter.
        //
        oscSource = HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
                    (uint32_t)SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

        if((oscSource == ((uint32_t)SYSCTL_OSCSRC_OSC2 >> SYSCTL_OSCSRC_S)) ||
           (oscSource == ((uint32_t)SYSCTL_OSCSRC_OSC1 >> SYSCTL_OSCSRC_S)))
        {
            clockOut = SYSCTL_DEFAULT_OSC_FREQ;
        }
        else
        {
            clockOut = clockInHz;
        }

        //
        // If the PLL is enabled calculate its effect on the clock
        //
        if((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &
            (SYSCTL_SYSPLLCTL1_PLLEN | SYSCTL_SYSPLLCTL1_PLLCLKEN)) == 3U)
        {
        	//
        	// Calculate integer multiplier
        	//
        	clockOut = clockOut * ((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
        	                                  SYSCTL_SYSPLLMULT_IMULT_M) >>
        	                                   SYSCTL_SYSPLLMULT_IMULT_S);
            //
            // Calculate PLL divider
            //
            temp = (((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                        SYSCTL_SYSPLLMULT_REFDIV_M) >>
                       SYSCTL_SYSPLLMULT_REFDIV_S) *
                     (HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                        SYSCTL_SYSPLLMULT_ODIV_M) >>
                       SYSCTL_SYSPLLMULT_ODIV_S);

             //
             //  Divide dividers
             //
             if(temp != 0U)
             {
                 clockOut /= temp;
             }
        }

        if((HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
            SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) != 0U)
        {
            clockOut /= (2U * (HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                               SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M));
        }
    }

    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_setClock()
//
//*****************************************************************************
bool
SysCtl_setClock(uint32_t config)
{
    uint16_t divSel, pllen;
    uint32_t oscSource, oscclksrcsel, pllLockStatus, pllMult, mult, refdiv;
    uint32_t timeout, xtalval;
    bool status = false;

    //
    // Check the arguments.
    //
    ASSERT((config & SYSCTL_OSCSRC_M) <= SYSCTL_OSCSRC_M);
    ASSERT(((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_ENABLE) ||
           ((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_BYPASS) ||
           ((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_DISABLE));

    //
    // Don't proceed to the PLL initialization if an MCD failure is detected.
    //
    if(SysCtl_isMCDClockFailureDetected())
    {
        //
        // OSCCLKSRC2 failure detected. Returning false. You'll need to clear
        // the MCD error.
        //
        status = false;
    }
    else
    {
        //
        // Bypass PLL
        //
        EALLOW;
        HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
            ~SYSCTL_SYSPLLCTL1_PLLCLKEN;
        EDIS;

        //
        // Delay of at least 120 OSCCLK cycles required post PLL bypass
        //
       SysCtl_delay(23U);


        //
        // Derive the current and previous oscillator clock source values
        //
        oscclksrcsel = HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
                      (uint16_t)SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

        xtalval = (HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) &
                  (uint16_t)SYSCTL_XTALCR_SE);

        oscSource = (config & SYSCTL_OSCSRC_M) >> SYSCTL_OSCSRC_S;

        //
        // Check if the oscillator clock source has changed
        //
        if((oscclksrcsel | xtalval) != oscSource)
        {
            //
            // Turn off PLL
            //
            EALLOW;
            HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
                ~SYSCTL_SYSPLLCTL1_PLLEN;
            EDIS;

            //
            // Delay of at least 66 OSCCLK cycles required between
            // powerdown to powerup of PLL
            //
            SysCtl_delay(12U);


            //
            // Configure oscillator source
            //
            SysCtl_selectOscSource(config & SYSCTL_OSCSRC_M);

            //
            // Delay of at least 60 OSCCLK cycles
            //
            SysCtl_delay(11U);

        }
        //        Set divider to produce slower output frequency to limit current
        //        increase.
        //
        // Set dividers to /1 to ensure the fastest PLL configuration
        //
        SysCtl_setPLLSysClk(0U);
        divSel = (uint16_t)(config & SYSCTL_SYSDIV_M) >> SYSCTL_SYSDIV_S;
        //
        // Set the divider to user value
        //
        EALLOW;
        HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) =
        (HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
        ~SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) | divSel;
        EDIS;

        //
        // Configure PLL if PLL usage is enabled or bypassed in config
        //
        if(((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_ENABLE) ||
           ((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_BYPASS))
        {
            //
            // Get the PLL multiplier settings from config
            //
            pllMult  = ((config & SYSCTL_IMULT_M) <<
                         SYSCTL_SYSPLLMULT_IMULT_S);

            pllMult |= (((config & SYSCTL_REFDIV_M) >>
                        SYSCTL_REFDIV_S) <<
                        SYSCTL_SYSPLLMULT_REFDIV_S);

            pllMult |= (((config & SYSCTL_ODIV_M) >>
                          SYSCTL_ODIV_S) <<
                          SYSCTL_SYSPLLMULT_ODIV_S);


            pllMult |= (((config & SYSCTL_VCO_M) >>
            		SYSCTL_VCO_S) <<
            		SYSCTL_SYSPLLMULT_VCO_S);

            //
            // Get the PLL multipliers currently programmed
            //
            mult  = ((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                      SYSCTL_SYSPLLMULT_IMULT_M) >>
                      SYSCTL_SYSPLLMULT_IMULT_S);

            mult |= (HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                     SYSCTL_SYSPLLMULT_REFDIV_M);

            mult |= (HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                     SYSCTL_SYSPLLMULT_ODIV_M);

            pllen = (HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &
                     SYSCTL_SYSPLLCTL1_PLLEN);

            //
            // Lock PLL only if the multipliers need an update or PLL needs
            // to be powered on / enabled
            //
            if((mult !=  pllMult) || (pllen != 1U))
            {
                //
                // Turn off PLL
                //
                EALLOW;
                HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
                    ~SYSCTL_SYSPLLCTL1_PLLEN;
                EDIS;

                //
                // Delay of at least 66 OSCCLK cycles required between
                // powerdown to powerup of PLL
                //
                SysCtl_delay(12U);


                //
                // Write multiplier, which automatically turns on the PLL
                //
                EALLOW;
                HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) = pllMult;
                //
                // Enable/ turn on PLL
                //
                HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |=
                       SYSCTL_SYSPLLCTL1_PLLEN;

                //
                // Wait for the SYSPLL lock counter or a timeout
                // This timeout needs to be computed based on OSCCLK
                // with a factor of REFDIV.
                // Lock time is 1024 OSCCLK * (REFDIV+1)
                //
                refdiv  = ((config & SYSCTL_REFDIV_M) >> SYSCTL_REFDIV_S);

                timeout = (1024U * (refdiv + 1U));
                pllLockStatus = HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLSTS) &
                                SYSCTL_SYSPLLSTS_LOCKS;

                while((pllLockStatus != 1U) && (timeout != 0U))
                {
                    pllLockStatus = HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLSTS) &
                                    SYSCTL_SYSPLLSTS_LOCKS;
                    timeout--;
                }
                HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |=
                		SYSCTL_SYSPLLCTL1_PLLCLKEN;

                EDIS;


                //
                // Check PLL Frequency using DCC
                //
               status = SysCtl_isPLLValid(
                        (config & SYSCTL_DCC_BASE_M ),
                       (config & SYSCTL_OSCSRC_M),
                       (config & (SYSCTL_IMULT_M | SYSCTL_ODIV_M |
                                   SYSCTL_REFDIV_M)));
            }
            else
            {
                //
                // Re-Lock of PLL not needed since the multipliers
                // are not updated
                //
                status = true;
            }
        }
        else if((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_DISABLE)
        {
            //
            // Turn off PLL when the PLL is disabled in config
            //
            EALLOW;
            HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
                   ~SYSCTL_SYSPLLCTL1_PLLEN;
            EDIS;

            //
            // PLL is bypassed and not in use
            // Status is updated to true to allow configuring the dividers later
            //
            status = true;
        }

        //
        // If PLL locked successfully, configure the dividers
        // Or if PLL is bypassed, only configure the dividers
        //
        if(status)
        {
             //
             // Feed system clock from SYSPLL only if PLL usage is enabled
             //
             if((config & SYSCTL_PLL_CONFIG_M) == SYSCTL_PLL_ENABLE)
             {
                 //
                 // Enable PLLSYSCLK is fed from system PLL clock
                 //
                 EALLOW;
                 HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |=
                        SYSCTL_SYSPLLCTL1_PLLCLKEN;
                 EDIS;
             }
             //
             // ~200 PLLSYSCLK delay to allow voltage regulator to stabilize
             // prior to increasing entire system clock frequency.
             //
             SysCtl_delay(40U);
			             //
            // Set divider to produce slower output frequency to limit current
            // increase.
            //
            divSel = (uint16_t)(config & SYSCTL_SYSDIV_M) >> SYSCTL_SYSDIV_S;

            EALLOW;
            HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) =
            (HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
             ~(uint32_t)SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) | divSel;

            EDIS;
        }
        else
        {
            ESTOP0; // If the frequency is out of range, stop here.
        }
    }

    return(status);
}

//*****************************************************************************
//
// SysCtl_selectXTAL()
//
//*****************************************************************************
void
SysCtl_selectXTAL(void)
{
    EALLOW;

    //
    // Enable XOSC pads initialization and set X1, X2 high
    //
    HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR2) |= SYSCTL_XTALCR2_FEN |
                                              SYSCTL_XTALCR2_XIF |
                                              SYSCTL_XTALCR2_XOF;
    //
    // Wait for few cycles to allow load capacitors to charge
    //
//    asm(" RPT #5 || NOP");

    //
    // Turn on XTAL and select crystal mode
    //
    HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_OSCOFF;
    HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_SE;
    EDIS;

    //
    // Wait for the X1 clock to saturate
    //
    SysCtl_pollX1Counter();

    //
    // Select XTAL as the oscillator source
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
    ((HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
      (~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
     ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S));
    EDIS;

    //
    // If a missing clock failure was detected, try waiting for the X1 counter
    // to saturate again. Consider modifying this code to add a 10ms timeout.
    //
    while(SysCtl_isMCDClockFailureDetected())
    {
        //
        // Clear the MCD failure
        //
        SysCtl_resetMCD();

        //
        // Wait for the X1 clock to saturate
        //
        SysCtl_pollX1Counter();

        //
        // Select XTAL as the oscillator source
        //
        EALLOW;
        HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
        ((HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
          (~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
         ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S));
        EDIS;
    }
}

//*****************************************************************************
//
// SysCtl_selectXTALSingleEnded()
//
//*****************************************************************************
void
SysCtl_selectXTALSingleEnded(void)
{
    //
    // Turn on XTAL and select single-ended mode.
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_OSCOFF;
    HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) |= SYSCTL_XTALCR_SE;
    EDIS;

    //
    // Wait for the X1 clock to saturate
    //
    SysCtl_pollX1Counter();

    //
    // Select XTAL as the oscillator source
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
    ((HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
      (~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
     ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S));
    EDIS;

    //
    // Something is wrong with the oscillator module. Replace the ESTOP0 with
    // an appropriate error-handling routine.
    //
    while(SysCtl_isMCDClockFailureDetected())
    {
        ESTOP0;
    }
}

//*****************************************************************************
//
// SysCtl_selectOscSource()
//
//*****************************************************************************
void
SysCtl_selectOscSource(uint32_t oscSource)
{
    ASSERT((oscSource == SYSCTL_OSCSRC_OSC1) ||
           (oscSource == SYSCTL_OSCSRC_OSC2) ||
           (oscSource == SYSCTL_OSCSRC_XTAL) ||
           (oscSource == SYSCTL_OSCSRC_XTAL_SE));

    //
    // Select the specified source.
    //
    EALLOW;
    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            //
            // Clk Src = INTOSC2
            //
            HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

            break;

        case SYSCTL_OSCSRC_XTAL:
            //
            // Select XTAL in crystal mode and wait for it to power up
            //
            SysCtl_selectXTAL();
            break;

        case SYSCTL_OSCSRC_XTAL_SE:
            //
            // Select XTAL in single-ended mode and wait for it to power up
            //
            SysCtl_selectXTALSingleEnded();
            break;

        case SYSCTL_OSCSRC_OSC1:
            //
            // Clk Src = INTOSC1
            //
            HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
                   (HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
                    ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M) |
                   ((uint32_t)SYSCTL_OSCSRC_OSC1 >> SYSCTL_OSCSRC_S);

            break;

        default:
            //
            // Do nothing. Not a valid oscSource value.
            //
            break;
    }
    EDIS;
}

//*****************************************************************************
//
// SysCtl_getLowSpeedClock()
//
//*****************************************************************************
uint32_t
SysCtl_getLowSpeedClock(uint32_t clockInHz)
{
    uint32_t clockOut;

    //
    // Get the main system clock
    //
    clockOut = SysCtl_getClock(clockInHz);

    //
    // Apply the divider to the main clock
    //
    if((HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) &
        SYSCTL_LOSPCP_LSPCLKDIV_M) != 0U)
    {
        clockOut /= (2U * (HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) &
                            SYSCTL_LOSPCP_LSPCLKDIV_M));
    }

    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_getDeviceParametric()
//
//*****************************************************************************
uint16_t
SysCtl_getDeviceParametric(SysCtl_DeviceParametric parametric)
{
    uint32_t value;

    //
    // Get requested parametric value
    //
    switch(parametric)
    {
        case SYSCTL_DEVICE_QUAL:
            //
            // Qualification Status
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_PINCOUNT:
            //
            // Pin Count
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_INSTASPIN:
            //
            // InstaSPIN Feature Set
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_FLASH:
            //
            // Flash Size (KB)
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_FAMILY:
            //
            // Device Family
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_PARTNO:
            //
            // Part Number
            //
            value = 0;
            break;

        case SYSCTL_DEVICE_CLASSID:
            //
            // Class ID
            //
            value = 0;
            break;

        default:
            //
            // Not a valid value for PARTID register
            //
            value = 0U;
            break;
    }

    return((uint16_t)value);
}
//*****************************************************************************
//
// SysCtl_isPLLValid()
//
//*****************************************************************************
bool
SysCtl_isPLLValid(uint32_t base, uint32_t oscSource,
                  uint32_t pllMultDiv)
{
    uint32_t imult, odiv, refdiv;
    float  fclk1_0ratio;
    uint32_t dccCounterSeed0, dccCounterSeed1, dccValidSeed0;

    ASSERT((base == SYSCTL_DCC_BASE_0) || (base == SYSCTL_DCC_BASE_1));

    DCC_Count0ClockSource dccClkSrc0;
    DCC_Count1ClockSource dccClkSrc1;


    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            //
            // Select DCC Clk Src0 as INTOSC2
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC2;
            break;
        case SYSCTL_OSCSRC_XTAL:
        case SYSCTL_OSCSRC_XTAL_SE:
            //
            // Select DCC Clk Src0 as XTAL
            //
            dccClkSrc0 = DCC_COUNT0SRC_XTAL;
            break;
        case SYSCTL_OSCSRC_OSC1:
            //
            // Select DCC Clk Src0 as INTOSC1
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC1;
            break;
        default:
            //
            // Select DCC Clk Src0 as INTOSC1
            //
            dccClkSrc0 = DCC_COUNT0SRC_INTOSC1;
            break;
    }

    //
    // Select DCC Clk Src1 as SYSPLL
    //
    dccClkSrc1 = DCC_COUNT1SRC_PLL;

    //
    // Assigning DCC for PLL validation
    //
    if(base == SYSCTL_DCC_BASE_0)
    {
        base = DCC0_BASE;
    }
    else if(base == SYSCTL_DCC_BASE_1)
    {
        base = DCC1_BASE;
    }


    //
    // Retrieving PLL parameters
    //
    imult = pllMultDiv & SYSCTL_IMULT_M;
    odiv = (pllMultDiv & SYSCTL_ODIV_M) >> SYSCTL_ODIV_S;
    refdiv = (pllMultDiv & SYSCTL_REFDIV_M) >> SYSCTL_REFDIV_S;

    fclk1_0ratio = (float)imult / (odiv * refdiv);

	dccCounterSeed1 = 100000;
	dccCounterSeed0 = (uint32_t)(dccCounterSeed1/1.03/fclk1_0ratio);
	dccValidSeed0 = (uint32_t)(dccCounterSeed1*1.03/fclk1_0ratio) - dccCounterSeed0;

    //
    // Enable peripheral clock to DCC
    //
    if(base == DCC0_BASE)
    {
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
    }
    else if(base == DCC1_BASE)
    {
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC1);
    }

    //
    // Clear Error & Done Flag
    //
    DCC_clearErrorFlag(base);
    DCC_clearDoneFlag(base);

    //
    // Disable DCC
    //
    DCC_disableModule(base);

    //
    // Disable Error Signal
    //
    DCC_disableErrorSignal(base);

    //
    // Disable Done Signal
    //
    DCC_disableDoneSignal(base);

    //
    // Configure Clock Source0 to whatever set as a clock source for PLL
    //
    DCC_setCounter0ClkSource(base, dccClkSrc0);

    //
    // Configure Clock Source1 to PLL
    //
    DCC_setCounter1ClkSource(base, dccClkSrc1);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(base, dccCounterSeed0, dccValidSeed0,
                        dccCounterSeed1);

    //
    // Enable Single Shot mode
    //
    DCC_enableSingleShotMode(base, DCC_MODE_COUNTER_ZERO);


    //
    // Enable DCC to start counting
    //
    DCC_enableModule(base);

    //
    // Wait until Error or Done Flag is generated
    //
    while((HWREG(base + DCC_O_STATUS) &
           (DCC_STATUS_ERR | DCC_STATUS_DONE)) == 0U)
    {
    }

    //
    // Returns true if DCC completes without error
    //
    return((HWREG(base + DCC_O_STATUS) &
            (DCC_STATUS_ERR | DCC_STATUS_DONE)) == DCC_STATUS_DONE);
}
//*****************************************************************************
//
// SysCtl_configureType()
//
//*****************************************************************************
void
SysCtl_configureType(SysCtl_SelType type , uint32_t config, uint32_t lock)
{
    ASSERT(lock <= 1U);

    EALLOW;

    //
    // Check which type needs to be configured , the type would be enabled /
    // disabled along with making the configurations unalterable as per input.
    //
    switch((uint16_t)type)
    {
        case SYSCTL_ECAPTYPE:
            HWREG(DEVCFG_BASE + SYSCTL_O_ECAPTYPE) =
                                config | (lock << SYSCTL_TYPE_LOCK_S);
            break;

        default:
            break;
    }
    EDIS;

}

//*****************************************************************************
//
// SysCtl_isConfigTypeLocked()
//
//*****************************************************************************
bool
SysCtl_isConfigTypeLocked(SysCtl_SelType type)
{
    bool lock = 0x0U;

    //
    // Check if the provided type registers can be modified or not.
    //
    switch((uint16_t)type)
    {
        case SYSCTL_ECAPTYPE:
            lock = ((HWREG(DEVCFG_BASE + SYSCTL_O_ECAPTYPE) &
                     SYSCTL_ECAPTYPE_LOCK) != 0U);
            break;

        default:
            break;
    }

  return(lock);
}

//*****************************************************************************
//
// SysCtl_lockClkConfig()
//
//*****************************************************************************
void
SysCtl_lockClkConfig(SysCtl_ClkRegSel registerName)
{
    uint16_t bitIndex;

    //
    // Decode the register variable.
    //
    bitIndex = ((uint16_t)registerName & SYSCTL_PERIPH_BIT_M) >>
                SYSCTL_PERIPH_BIT_S;

    //
    // Locks the particular clock configuration register
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_CLKCFGLOCK1) |= ((uint32_t)1U << bitIndex);
    EDIS;
}

//*****************************************************************************
//
// SysCtl_lockSysConfig()
//
//*****************************************************************************
void
SysCtl_lockSysConfig (SysCtl_CpuRegSel registerName)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the register variable.
    //
    regIndex = (uint16_t)2U * ((uint16_t)registerName &
                               (uint16_t)SYSCTL_PERIPH_REG_M);
    bitIndex = ((uint16_t)registerName & SYSCTL_PERIPH_BIT_M) >>
                 SYSCTL_PERIPH_BIT_S;

    //
    // Locks the particular System configuration register
    //
    EALLOW;
    HWREG(CPUSYS_BASE + SYSCTL_O_CPUSYSLOCK1 + regIndex) |=
                                            ((uint32_t)1U << bitIndex);
    EDIS;
}


