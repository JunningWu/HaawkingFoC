//#############################################################################
//
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd
// http://www.haawking.com/ All rights reserved.
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
//   Neither the name of Beijing Haawking Technology Co.,Ltd nor the names of
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
// 
//#############################################################################
//
// Release for HXS320F280025CEDC, Bitfield DriverLib, 1.0.0
//
// Release time: 2024-01-23 15:23:22.144640
//
//#############################################################################



//---------------------------------------------------------------------------
// Extern Global Peripheral Variables:
//


//
// Structure
//
extern volatile struct ADC_REGS AdcaRegs;
extern volatile struct ADC_RESULT_REGS AdcaResultRegs;
extern volatile struct ADC_REGS AdccRegs;
extern volatile struct ADC_RESULT_REGS AdccResultRegs;
extern volatile struct ADC_CTL3_REGS AdcaCtl3Regs;
extern volatile struct ADC_CTL3_REGS AdccCtl3Regs;
extern volatile struct HIC_CFG_REGS HicRegs;
extern volatile struct DMA_REGS DmaRegs;
extern volatile struct BGCRC_REGS BgcrcCpuRegs;
extern volatile struct MEM_CFG_REGS MemCfgRegs;
extern volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;
extern volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;
extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;
extern volatile struct PIE_CTRL_REGS PieCtrlRegs;
extern volatile struct XINT_REGS XintRegs;
extern volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;
extern volatile struct PIE_VECT_TABLE PieVectTable;
extern volatile struct CAN_REGS CanaRegs;
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
extern volatile struct EPWM_REGS EPwm8Regs;
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb1LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb1LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb1DataExchRegs;
extern volatile struct CLB_LOGIC_CONFIG_REGS Clb2LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS Clb2LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS Clb2DataExchRegs;
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct HRCAP_REGS HRCap3Regs;
extern volatile struct CMPSS_REGS Cmpss1Regs;
extern volatile struct CMPSS_REGS Cmpss2Regs;
extern volatile struct CMPSS_REGS Cmpss3Regs;
extern volatile struct CMPSS_REGS Cmpss4Regs;
extern volatile struct SPI_REGS SpiaRegs;
extern volatile struct SPI_REGS SpibRegs;
extern volatile struct PMBUS_REGS PmbusaRegs;
extern volatile struct FSI_RX_REGS FsiRxaRegs;
extern volatile struct FSI_TX_REGS FsiTxaRegs;
extern volatile struct I2S_REGS I2saRegs;
extern volatile struct INPUT_XBAR_REGS InputXbarRegs;
extern volatile struct XBAR_REGS XbarRegs;
extern volatile struct INPUT_XBAR_REGS ClbInputXbarRegs;
extern volatile struct EPWM_XBAR_REGS EPwmXbarRegs;
extern volatile struct CLB_XBAR_REGS ClbXbarRegs;
extern volatile struct OUTPUT_XBAR_REGS OutputXbarRegs;
extern volatile struct OUTPUT_XBAR_REGS ClbOutputXbarRegs;
extern volatile struct ERAD_GLOBAL_REGS EradGlobalRegs;
extern volatile struct ERAD_HWBP_REGS EradHWBP1Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP2Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP3Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP4Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP5Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP6Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP7Regs;
extern volatile struct ERAD_HWBP_REGS EradHWBP8Regs;
extern volatile struct ERAD_COUNTER_REGS EradCounter1Regs;
extern volatile struct ERAD_COUNTER_REGS EradCounter2Regs;
extern volatile struct ERAD_COUNTER_REGS EradCounter3Regs;
extern volatile struct ERAD_COUNTER_REGS EradCounter4Regs;
extern volatile struct ERAD_CRC_GLOBAL_REGS EradCRCGlobalRegs;
extern volatile struct ERAD_CRC_REGS EradCRC1Regs;
extern volatile struct ERAD_CRC_REGS EradCRC2Regs;
extern volatile struct ERAD_CRC_REGS EradCRC3Regs;
extern volatile struct ERAD_CRC_REGS EradCRC4Regs;
extern volatile struct ERAD_CRC_REGS EradCRC5Regs;
extern volatile struct ERAD_CRC_REGS EradCRC6Regs;
extern volatile struct ERAD_CRC_REGS EradCRC7Regs;
extern volatile struct ERAD_CRC_REGS EradCRC8Regs;
extern volatile struct DCC_REGS Dcc0Regs;
extern volatile struct DCC_REGS Dcc1Regs;
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_DATA_READ_REGS GpioDataReadRegs;
extern volatile struct LIN_REGS LinaRegs;
extern volatile struct LIN_REGS LinbRegs;
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct I2C_REGS I2caRegs;
extern volatile struct I2C_REGS I2cbRegs;
extern volatile struct CLK_CFG_REGS ClkCfgRegs;
extern volatile struct CPU_SYS_REGS CpuSysRegs;
extern volatile struct DEV_CFG_REGS DevCfgRegs;
extern volatile struct PERIPH_AC_REGS SysPeriphAcRegs;
extern volatile struct SYNC_SOC_REGS SyncSocRegs;
extern volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;
extern volatile struct WD_REGS WdRegs;
extern volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;
extern volatile struct DCSM_BANK0_Z1_REGS DcsmBank0Z1Regs;
extern volatile struct DCSM_BANK0_Z2_REGS DcsmBank0Z2Regs;
extern volatile struct DCSM_COMMON_REGS DcsmCommonRegs;
extern volatile struct DCSM_BANK0_Z1_OTP_REGS DcsmBank0Z1OtpRegs;
extern volatile struct DCSM_BANK0_Z2_OTP_REGS DcsmBank0Z2OtpRegs;
extern volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;
extern volatile struct FLASH_ECC_REGS Flash0EccRegs;
extern volatile Uint32 IER;
extern volatile Uint32 IFR;


//
// Pointer
//
extern volatile struct ADC_REGS *const P_AdcaRegs;
extern volatile struct ADC_RESULT_REGS *const P_AdcaResultRegs;
extern volatile struct ADC_REGS *const P_AdccRegs;
extern volatile struct ADC_RESULT_REGS *const P_AdccResultRegs;
extern volatile struct ADC_CTL3_REGS *const P_AdcaCtl3Regs;
extern volatile struct ADC_CTL3_REGS *const P_AdccCtl3Regs;
extern volatile struct HIC_CFG_REGS *const P_HicRegs;
extern volatile struct DMA_REGS *const P_DmaRegs;
extern volatile struct BGCRC_REGS *const P_BgcrcCpuRegs;
extern volatile struct MEM_CFG_REGS *const P_MemCfgRegs;
extern volatile struct MEMORY_ERROR_REGS *const P_MemoryErrorRegs;
extern volatile struct ACCESS_PROTECTION_REGS *const P_AccessProtectionRegs;
extern volatile struct CPUTIMER_REGS *const P_CpuTimer0Regs;
extern volatile struct CPUTIMER_REGS *const P_CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS *const P_CpuTimer2Regs;
extern volatile struct PIE_CTRL_REGS *const P_PieCtrlRegs;
extern volatile struct XINT_REGS *const P_XintRegs;
extern volatile struct NMI_INTRUPT_REGS *const P_NmiIntruptRegs;
extern volatile struct PIE_VECT_TABLE *const P_PieVectTable;
extern volatile struct CAN_REGS *const P_CanaRegs;
extern volatile struct EPWM_REGS *const P_EPwm1Regs;
extern volatile struct EPWM_REGS *const P_EPwm2Regs;
extern volatile struct EPWM_REGS *const P_EPwm3Regs;
extern volatile struct EPWM_REGS *const P_EPwm4Regs;
extern volatile struct EPWM_REGS *const P_EPwm5Regs;
extern volatile struct EPWM_REGS *const P_EPwm6Regs;
extern volatile struct EPWM_REGS *const P_EPwm7Regs;
extern volatile struct EPWM_REGS *const P_EPwm8Regs;
extern volatile struct CLB_LOGIC_CONFIG_REGS *const P_Clb1LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS *const P_Clb1LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS *const P_Clb1DataExchRegs;
extern volatile struct CLB_LOGIC_CONFIG_REGS *const P_Clb2LogicCfgRegs;
extern volatile struct CLB_LOGIC_CONTROL_REGS *const P_Clb2LogicCtrlRegs;
extern volatile struct CLB_DATA_EXCHANGE_REGS *const P_Clb2DataExchRegs;
extern volatile struct EQEP_REGS *const P_EQep1Regs;
extern volatile struct EQEP_REGS *const P_EQep2Regs;
extern volatile struct ECAP_REGS *const P_ECap1Regs;
extern volatile struct ECAP_REGS *const P_ECap2Regs;
extern volatile struct ECAP_REGS *const P_ECap3Regs;
extern volatile struct HRCAP_REGS *const P_HRCap3Regs;
extern volatile struct CMPSS_REGS *const P_Cmpss1Regs;
extern volatile struct CMPSS_REGS *const P_Cmpss2Regs;
extern volatile struct CMPSS_REGS *const P_Cmpss3Regs;
extern volatile struct CMPSS_REGS *const P_Cmpss4Regs;
extern volatile struct SPI_REGS *const P_SpiaRegs;
extern volatile struct SPI_REGS *const P_SpibRegs;
extern volatile struct PMBUS_REGS *const P_PmbusaRegs;
extern volatile struct FSI_RX_REGS *const P_FsiRxaRegs;
extern volatile struct FSI_TX_REGS *const P_FsiTxaRegs;
extern volatile struct I2S_REGS *const P_I2saRegs;
extern volatile struct INPUT_XBAR_REGS *const P_InputXbarRegs;
extern volatile struct XBAR_REGS *const P_XbarRegs;
extern volatile struct INPUT_XBAR_REGS *const P_ClbInputXbarRegs;
extern volatile struct EPWM_XBAR_REGS *const P_EPwmXbarRegs;
extern volatile struct CLB_XBAR_REGS *const P_ClbXbarRegs;
extern volatile struct OUTPUT_XBAR_REGS *const P_OutputXbarRegs;
extern volatile struct OUTPUT_XBAR_REGS *const P_ClbOutputXbarRegs;
extern volatile struct ERAD_GLOBAL_REGS *const P_EradGlobalRegs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP1Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP2Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP3Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP4Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP5Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP6Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP7Regs;
extern volatile struct ERAD_HWBP_REGS *const P_EradHWBP8Regs;
extern volatile struct ERAD_COUNTER_REGS *const P_EradCounter1Regs;
extern volatile struct ERAD_COUNTER_REGS *const P_EradCounter2Regs;
extern volatile struct ERAD_COUNTER_REGS *const P_EradCounter3Regs;
extern volatile struct ERAD_COUNTER_REGS *const P_EradCounter4Regs;
extern volatile struct ERAD_CRC_GLOBAL_REGS *const P_EradCRCGlobalRegs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC1Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC2Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC3Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC4Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC5Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC6Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC7Regs;
extern volatile struct ERAD_CRC_REGS *const P_EradCRC8Regs;
extern volatile struct DCC_REGS *const P_Dcc0Regs;
extern volatile struct DCC_REGS *const P_Dcc1Regs;
extern volatile struct GPIO_CTRL_REGS *const P_GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS *const P_GpioDataRegs;
extern volatile struct GPIO_DATA_READ_REGS *const P_GpioDataReadRegs;
extern volatile struct LIN_REGS *const P_LinaRegs;
extern volatile struct LIN_REGS *const P_LinbRegs;
extern volatile struct SCI_REGS *const P_SciaRegs;
extern volatile struct I2C_REGS *const P_I2caRegs;
extern volatile struct I2C_REGS *const P_I2cbRegs;
extern volatile struct CLK_CFG_REGS *const P_ClkCfgRegs;
extern volatile struct CPU_SYS_REGS *const P_CpuSysRegs;
extern volatile struct DEV_CFG_REGS *const P_DevCfgRegs;
extern volatile struct PERIPH_AC_REGS *const P_SysPeriphAcRegs;
extern volatile struct SYNC_SOC_REGS *const P_SyncSocRegs;
extern volatile struct DMA_CLA_SRC_SEL_REGS *const P_DmaClaSrcSelRegs;
extern volatile struct WD_REGS *const P_WdRegs;
extern volatile struct ANALOG_SUBSYS_REGS *const P_AnalogSubsysRegs;
extern volatile struct DCSM_BANK0_Z1_REGS *const P_DcsmBank0Z1Regs;
extern volatile struct DCSM_BANK0_Z2_REGS *const P_DcsmBank0Z2Regs;
extern volatile struct DCSM_COMMON_REGS *const P_DcsmCommonRegs;
extern volatile struct DCSM_BANK0_Z1_OTP_REGS *const P_DcsmBank0Z1OtpRegs;
extern volatile struct DCSM_BANK0_Z2_OTP_REGS *const P_DcsmBank0Z2OtpRegs;
extern volatile struct FLASH_CTRL_REGS *const P_Flash0CtrlRegs;
extern volatile struct FLASH_ECC_REGS *const P_Flash0EccRegs;

//===========================================================================
// End of file.
//===========================================================================
