//###########################################################################
//
// FILE:   f28002x_defaultisr.h
//
// TITLE:  f28002x Device Default Interrupt Service Routines Definitions
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef F28002X_DEFAULTISR_H
#define F28002X_DEFAULTISR_H
#ifdef __cplusplus
extern "C" {
#endif

//
// Default Interrupt Service Routine Declarations:
// The following function prototypes are for the
// default ISR routines used with the default PIE vector table.
// This default vector table is found in the f28002x_pievect.h
// file.
//
INTERRUPT void TIMER1_ISR(void);
INTERRUPT void TIMER2_ISR(void);
INTERRUPT void DATALOG_ISR(void);
INTERRUPT void RTOS_ISR(void);
INTERRUPT void EMU_ISR(void);
INTERRUPT void NMI_ISR(void);
INTERRUPT void ILLEGAL_ISR(void);
INTERRUPT void USER1_ISR(void);
INTERRUPT void USER2_ISR(void);
INTERRUPT void USER3_ISR(void);
INTERRUPT void USER4_ISR(void);
INTERRUPT void USER5_ISR(void);
INTERRUPT void USER6_ISR(void);
INTERRUPT void USER7_ISR(void);
INTERRUPT void USER8_ISR(void);
INTERRUPT void USER9_ISR(void);
INTERRUPT void USER10_ISR(void);
INTERRUPT void USER11_ISR(void);
INTERRUPT void USER12_ISR(void);
INTERRUPT void ADCA1_ISR(void);
INTERRUPT void ADCC1_ISR(void);
INTERRUPT void XINT1_ISR(void);
INTERRUPT void XINT2_ISR(void);
INTERRUPT void TIMER0_ISR(void);
INTERRUPT void WAKE_ISR(void);
INTERRUPT void EPWM1_TZ_ISR(void);
INTERRUPT void EPWM2_TZ_ISR(void);
INTERRUPT void EPWM3_TZ_ISR(void);
INTERRUPT void EPWM4_TZ_ISR(void);
INTERRUPT void EPWM5_TZ_ISR(void);
INTERRUPT void EPWM6_TZ_ISR(void);
INTERRUPT void EPWM7_TZ_ISR(void);
INTERRUPT void EPWM8_TZ_ISR(void);
INTERRUPT void EPWM1_ISR(void);
INTERRUPT void EPWM2_ISR(void);
INTERRUPT void EPWM3_ISR(void);
INTERRUPT void EPWM4_ISR(void);
INTERRUPT void EPWM5_ISR(void);
INTERRUPT void EPWM6_ISR(void);
INTERRUPT void EPWM7_ISR(void);
INTERRUPT void EPWM8_ISR(void);
INTERRUPT void ECAP1_ISR(void);
INTERRUPT void ECAP2_ISR(void);
INTERRUPT void ECAP3_ISR(void);
INTERRUPT void EQEP1_ISR(void);
INTERRUPT void EQEP2_ISR(void);
INTERRUPT void CLB1_ISR(void);
INTERRUPT void CLB2_ISR(void);
INTERRUPT void SPIA_RX_ISR(void);
INTERRUPT void SPIA_TX_ISR(void);
INTERRUPT void SPIB_RX_ISR(void);
INTERRUPT void SPIB_TX_ISR(void);
INTERRUPT void DMA_CH1_ISR(void);
INTERRUPT void DMA_CH2_ISR(void);
INTERRUPT void DMA_CH3_ISR(void);
INTERRUPT void DMA_CH4_ISR(void);
INTERRUPT void DMA_CH5_ISR(void);
INTERRUPT void DMA_CH6_ISR(void);
INTERRUPT void I2CA_ISR(void);
INTERRUPT void I2CA_FIFO_ISR(void);
INTERRUPT void I2CB_ISR(void);
INTERRUPT void I2CB_FIFO_ISR(void);
INTERRUPT void SCIA_RX_ISR(void);
INTERRUPT void SCIA_TX_ISR(void);
INTERRUPT void CANA0_ISR(void);
INTERRUPT void CANA1_ISR(void);
INTERRUPT void ADCA_EVT_ISR(void);
INTERRUPT void ADCA2_ISR(void);
INTERRUPT void ADCA3_ISR(void);
INTERRUPT void ADCA4_ISR(void);
INTERRUPT void XINT3_ISR(void);
INTERRUPT void XINT4_ISR(void);
INTERRUPT void XINT5_ISR(void);
INTERRUPT void MPOST_ISR(void);
INTERRUPT void FMC_ISR(void);
INTERRUPT void FPU_OVERFLOW_ISR(void);
INTERRUPT void FPU_UNDERFLOW_ISR(void);
INTERRUPT void ECAP3_2_ISR(void);
INTERRUPT void FSITXA1_ISR(void);
INTERRUPT void FSITXA2_ISR(void);
INTERRUPT void FSIRXA1_ISR(void);
INTERRUPT void FSIRXA2_ISR(void);
INTERRUPT void DCC0_ISR(void);
INTERRUPT void LINA_0_ISR(void);
INTERRUPT void LINA_1_ISR(void);
INTERRUPT void LINB_0_ISR(void);
INTERRUPT void LINB_1_ISR(void);
INTERRUPT void PMBUSA_ISR(void);
INTERRUPT void DCC1_ISR(void);
INTERRUPT void BGCRC_ISR(void);
INTERRUPT void HICA_ISR(void);
INTERRUPT void ADCC_EVT_ISR(void);
INTERRUPT void ADCC2_ISR(void);
INTERRUPT void ADCC3_ISR(void);
INTERRUPT void ADCC4_ISR(void);
INTERRUPT void RAM_CORR_ERR_ISR(void);
INTERRUPT void FLASH_CORR_ERR_ISR(void);
INTERRUPT void RAM_ACC_VIOL_ISR(void);
INTERRUPT void SYS_PLL_SLIP_ISR(void);
//
// Catch-all for PIE Reserved Locations for testing purposes:
//
INTERRUPT void PIE_RESERVED_ISR(void);              // Reserved ISR
INTERRUPT void EMPTY_ISR(void);                     // Only does a return
INTERRUPT void NOTUSED_ISR(void);
#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif   // end of f28002x_PIEVECT_H definition

//
// End of file
//

