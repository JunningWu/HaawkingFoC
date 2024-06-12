

//---------------------------------------------------------------------------
// Included Files
//

#include "f28002x_device.h" 

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//


//
// Structure
//
volatile struct ADC_REGS CODE_SECTION(".AdcaRegs") AdcaRegs;
volatile struct ADC_RESULT_REGS CODE_SECTION(".AdcaResultRegs") AdcaResultRegs;
volatile struct ADC_REGS CODE_SECTION(".AdccRegs") AdccRegs;
volatile struct ADC_RESULT_REGS CODE_SECTION(".AdccResultRegs") AdccResultRegs;
volatile struct ADC_CTL3_REGS CODE_SECTION(".AdcaCtl3Regs") AdcaCtl3Regs;
volatile struct ADC_CTL3_REGS CODE_SECTION(".AdccCtl3Regs") AdccCtl3Regs;
volatile struct HIC_CFG_REGS CODE_SECTION(".HicRegs") HicRegs;
volatile struct DMA_REGS CODE_SECTION(".DmaRegs") DmaRegs;
volatile struct BGCRC_REGS CODE_SECTION(".BgcrcCpuRegs") BgcrcCpuRegs;
volatile struct MEM_CFG_REGS CODE_SECTION(".MemCfgRegs") MemCfgRegs;
volatile struct MEMORY_ERROR_REGS CODE_SECTION(".MemoryErrorRegs") MemoryErrorRegs;
volatile struct ACCESS_PROTECTION_REGS CODE_SECTION(".AccessProtectionRegs") AccessProtectionRegs;
volatile struct CPUTIMER_REGS CODE_SECTION(".CpuTimer0Regs") CpuTimer0Regs;
volatile struct CPUTIMER_REGS CODE_SECTION(".CpuTimer1Regs") CpuTimer1Regs;
volatile struct CPUTIMER_REGS CODE_SECTION(".CpuTimer2Regs") CpuTimer2Regs;
volatile struct PIE_CTRL_REGS CODE_SECTION(".PieCtrlRegs") PieCtrlRegs;
volatile struct XINT_REGS CODE_SECTION(".XintRegs") XintRegs;
volatile struct NMI_INTRUPT_REGS CODE_SECTION(".NmiIntruptRegs") NmiIntruptRegs;
volatile struct PIE_VECT_TABLE CODE_SECTION(".PieVectTable") PieVectTable;
volatile struct CAN_REGS CODE_SECTION(".CanaRegs") CanaRegs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm1Regs") EPwm1Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm2Regs") EPwm2Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm3Regs") EPwm3Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm4Regs") EPwm4Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm5Regs") EPwm5Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm6Regs") EPwm6Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm7Regs") EPwm7Regs;
volatile struct EPWM_REGS CODE_SECTION(".EPwm8Regs") EPwm8Regs;
volatile struct CLB_LOGIC_CONFIG_REGS CODE_SECTION(".Clb1LogicCfgRegs") Clb1LogicCfgRegs;
volatile struct CLB_LOGIC_CONTROL_REGS CODE_SECTION(".Clb1LogicCtrlRegs") Clb1LogicCtrlRegs;
volatile struct CLB_DATA_EXCHANGE_REGS CODE_SECTION(".Clb1DataExchRegs") Clb1DataExchRegs;
volatile struct CLB_LOGIC_CONFIG_REGS CODE_SECTION(".Clb2LogicCfgRegs") Clb2LogicCfgRegs;
volatile struct CLB_LOGIC_CONTROL_REGS CODE_SECTION(".Clb2LogicCtrlRegs") Clb2LogicCtrlRegs;
volatile struct CLB_DATA_EXCHANGE_REGS CODE_SECTION(".Clb2DataExchRegs") Clb2DataExchRegs;
volatile struct EQEP_REGS CODE_SECTION(".EQep1Regs") EQep1Regs;
volatile struct EQEP_REGS CODE_SECTION(".EQep2Regs") EQep2Regs;
volatile struct ECAP_REGS CODE_SECTION(".ECap1Regs") ECap1Regs;
volatile struct ECAP_REGS CODE_SECTION(".ECap2Regs") ECap2Regs;
volatile struct ECAP_REGS CODE_SECTION(".ECap3Regs") ECap3Regs;
volatile struct HRCAP_REGS CODE_SECTION(".HRCap3Regs") HRCap3Regs;
volatile struct CMPSS_REGS CODE_SECTION(".Cmpss1Regs") Cmpss1Regs;
volatile struct CMPSS_REGS CODE_SECTION(".Cmpss2Regs") Cmpss2Regs;
volatile struct CMPSS_REGS CODE_SECTION(".Cmpss3Regs") Cmpss3Regs;
volatile struct CMPSS_REGS CODE_SECTION(".Cmpss4Regs") Cmpss4Regs;
volatile struct SPI_REGS CODE_SECTION(".SpiaRegs") SpiaRegs;
volatile struct SPI_REGS CODE_SECTION(".SpibRegs") SpibRegs;
volatile struct PMBUS_REGS CODE_SECTION(".PmbusaRegs") PmbusaRegs;
volatile struct FSI_RX_REGS CODE_SECTION(".FsiRxaRegs") FsiRxaRegs;
volatile struct FSI_TX_REGS CODE_SECTION(".FsiTxaRegs") FsiTxaRegs;
volatile struct I2S_REGS CODE_SECTION(".I2saRegs") I2saRegs;
volatile struct INPUT_XBAR_REGS CODE_SECTION(".InputXbarRegs") InputXbarRegs;
volatile struct XBAR_REGS CODE_SECTION(".XbarRegs") XbarRegs;
volatile struct INPUT_XBAR_REGS CODE_SECTION(".ClbInputXbarRegs") ClbInputXbarRegs;
volatile struct EPWM_XBAR_REGS CODE_SECTION(".EPwmXbarRegs") EPwmXbarRegs;
volatile struct CLB_XBAR_REGS CODE_SECTION(".ClbXbarRegs") ClbXbarRegs;
volatile struct OUTPUT_XBAR_REGS CODE_SECTION(".OutputXbarRegs") OutputXbarRegs;
volatile struct OUTPUT_XBAR_REGS CODE_SECTION(".ClbOutputXbarRegs") ClbOutputXbarRegs;
volatile struct ERAD_GLOBAL_REGS CODE_SECTION(".EradGlobalRegs") EradGlobalRegs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP1Regs") EradHWBP1Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP2Regs") EradHWBP2Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP3Regs") EradHWBP3Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP4Regs") EradHWBP4Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP5Regs") EradHWBP5Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP6Regs") EradHWBP6Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP7Regs") EradHWBP7Regs;
volatile struct ERAD_HWBP_REGS CODE_SECTION(".EradHWBP8Regs") EradHWBP8Regs;
volatile struct ERAD_COUNTER_REGS CODE_SECTION(".EradCounter1Regs") EradCounter1Regs;
volatile struct ERAD_COUNTER_REGS CODE_SECTION(".EradCounter2Regs") EradCounter2Regs;
volatile struct ERAD_COUNTER_REGS CODE_SECTION(".EradCounter3Regs") EradCounter3Regs;
volatile struct ERAD_COUNTER_REGS CODE_SECTION(".EradCounter4Regs") EradCounter4Regs;
volatile struct ERAD_CRC_GLOBAL_REGS CODE_SECTION(".EradCRCGlobalRegs") EradCRCGlobalRegs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC1Regs") EradCRC1Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC2Regs") EradCRC2Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC3Regs") EradCRC3Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC4Regs") EradCRC4Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC5Regs") EradCRC5Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC6Regs") EradCRC6Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC7Regs") EradCRC7Regs;
volatile struct ERAD_CRC_REGS CODE_SECTION(".EradCRC8Regs") EradCRC8Regs;
volatile struct DCC_REGS CODE_SECTION(".Dcc0Regs") Dcc0Regs;
volatile struct DCC_REGS CODE_SECTION(".Dcc1Regs") Dcc1Regs;
volatile struct GPIO_CTRL_REGS CODE_SECTION(".GpioCtrlRegs") GpioCtrlRegs;
volatile struct GPIO_DATA_REGS CODE_SECTION(".GpioDataRegs") GpioDataRegs;
volatile struct GPIO_DATA_READ_REGS CODE_SECTION(".GpioDataReadRegs") GpioDataReadRegs;
volatile struct LIN_REGS CODE_SECTION(".LinaRegs") LinaRegs;
volatile struct LIN_REGS CODE_SECTION(".LinbRegs") LinbRegs;
volatile struct SCI_REGS CODE_SECTION(".SciaRegs") SciaRegs;
volatile struct I2C_REGS CODE_SECTION(".I2caRegs") I2caRegs;
volatile struct I2C_REGS CODE_SECTION(".I2cbRegs") I2cbRegs;
volatile struct CLK_CFG_REGS CODE_SECTION(".ClkCfgRegs") ClkCfgRegs;
volatile struct CPU_SYS_REGS CODE_SECTION(".CpuSysRegs") CpuSysRegs;
volatile struct DEV_CFG_REGS CODE_SECTION(".DevCfgRegs") DevCfgRegs;
volatile struct PERIPH_AC_REGS CODE_SECTION(".SysPeriphAcRegs") SysPeriphAcRegs;
volatile struct SYNC_SOC_REGS CODE_SECTION(".SyncSocRegs") SyncSocRegs;
volatile struct DMA_CLA_SRC_SEL_REGS CODE_SECTION(".DmaClaSrcSelRegs") DmaClaSrcSelRegs;
volatile struct WD_REGS CODE_SECTION(".WdRegs") WdRegs;
volatile struct ANALOG_SUBSYS_REGS CODE_SECTION(".AnalogSubsysRegs") AnalogSubsysRegs;
volatile struct DCSM_BANK0_Z1_REGS CODE_SECTION(".DcsmBank0Z1Regs") DcsmBank0Z1Regs;
volatile struct DCSM_BANK0_Z2_REGS CODE_SECTION(".DcsmBank0Z2Regs") DcsmBank0Z2Regs;
volatile struct DCSM_COMMON_REGS CODE_SECTION(".DcsmCommonRegs") DcsmCommonRegs;
volatile struct DCSM_BANK0_Z1_OTP_REGS CODE_SECTION(".DcsmBank0Z1OtpRegs") DcsmBank0Z1OtpRegs;
volatile struct DCSM_BANK0_Z2_OTP_REGS CODE_SECTION(".DcsmBank0Z2OtpRegs") DcsmBank0Z2OtpRegs;
volatile struct FLASH_CTRL_REGS CODE_SECTION(".Flash0CtrlRegs") Flash0CtrlRegs;
volatile struct FLASH_ECC_REGS CODE_SECTION(".Flash0EccRegs") Flash0EccRegs;
//volatile Uint32 CODE_SECTION(".ier_register") IER;
//volatile Uint32 CODE_SECTION(".ifr_register") IFR;



//
// Pointer
//
volatile struct ADC_REGS *const CODE_SECTION(".text") P_AdcaRegs = (volatile struct ADC_REGS *)0x1800;
volatile struct ADC_RESULT_REGS *const CODE_SECTION(".text") P_AdcaResultRegs = (volatile struct ADC_RESULT_REGS *)0x1940;
volatile struct ADC_REGS *const CODE_SECTION(".text") P_AdccRegs = (volatile struct ADC_REGS *)0x1C00;
volatile struct ADC_RESULT_REGS *const CODE_SECTION(".text") P_AdccResultRegs = (volatile struct ADC_RESULT_REGS *)0x1D40;
volatile struct ADC_CTL3_REGS *const CODE_SECTION(".text") P_AdcaCtl3Regs = (volatile struct ADC_CTL3_REGS *)0x1990;
volatile struct ADC_CTL3_REGS *const CODE_SECTION(".text") P_AdccCtl3Regs = (volatile struct ADC_CTL3_REGS *)0x1D90;
volatile struct HIC_CFG_REGS *const CODE_SECTION(".text") P_HicRegs = (volatile struct HIC_CFG_REGS *)0x2800;
volatile struct DMA_REGS *const CODE_SECTION(".text") P_DmaRegs = (volatile struct DMA_REGS *)0x3000;
volatile struct BGCRC_REGS *const CODE_SECTION(".text") P_BgcrcCpuRegs = (volatile struct BGCRC_REGS *)0x3400;
volatile struct MEM_CFG_REGS *const CODE_SECTION(".text") P_MemCfgRegs = (volatile struct MEM_CFG_REGS *)0x3800;
volatile struct MEMORY_ERROR_REGS *const CODE_SECTION(".text") P_MemoryErrorRegs = (volatile struct MEMORY_ERROR_REGS *)0x385C;
volatile struct ACCESS_PROTECTION_REGS *const CODE_SECTION(".text") P_AccessProtectionRegs = (volatile struct ACCESS_PROTECTION_REGS *)0x389C;
volatile struct CPUTIMER_REGS *const CODE_SECTION(".text") P_CpuTimer0Regs = (volatile struct CPUTIMER_REGS *)0x5000;
volatile struct CPUTIMER_REGS *const CODE_SECTION(".text") P_CpuTimer1Regs = (volatile struct CPUTIMER_REGS *)0x5010;
volatile struct CPUTIMER_REGS *const CODE_SECTION(".text") P_CpuTimer2Regs = (volatile struct CPUTIMER_REGS *)0x5020;
volatile struct PIE_CTRL_REGS *const CODE_SECTION(".text") P_PieCtrlRegs = (volatile struct PIE_CTRL_REGS *)0x5100;
volatile struct XINT_REGS *const CODE_SECTION(".text") P_XintRegs = (volatile struct XINT_REGS *)0x5200;
volatile struct NMI_INTRUPT_REGS *const CODE_SECTION(".text") P_NmiIntruptRegs = (volatile struct NMI_INTRUPT_REGS *)0x5300;
volatile struct PIE_VECT_TABLE *const CODE_SECTION(".text") P_PieVectTable = (volatile struct PIE_VECT_TABLE *)0x5800;
volatile struct CAN_REGS *const CODE_SECTION(".text") P_CanaRegs = (volatile struct CAN_REGS *)0x6000;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm1Regs = (volatile struct EPWM_REGS *)0xA000;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm2Regs = (volatile struct EPWM_REGS *)0xA400;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm3Regs = (volatile struct EPWM_REGS *)0xA800;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm4Regs = (volatile struct EPWM_REGS *)0xAC00;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm5Regs = (volatile struct EPWM_REGS *)0xB000;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm6Regs = (volatile struct EPWM_REGS *)0xB400;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm7Regs = (volatile struct EPWM_REGS *)0xB800;
volatile struct EPWM_REGS *const CODE_SECTION(".text") P_EPwm8Regs = (volatile struct EPWM_REGS *)0xBC00;
volatile struct CLB_LOGIC_CONFIG_REGS *const CODE_SECTION(".text") P_Clb1LogicCfgRegs = (volatile struct CLB_LOGIC_CONFIG_REGS *)0xC000;
volatile struct CLB_LOGIC_CONTROL_REGS *const CODE_SECTION(".text") P_Clb1LogicCtrlRegs = (volatile struct CLB_LOGIC_CONTROL_REGS *)0xC100;
volatile struct CLB_DATA_EXCHANGE_REGS *const CODE_SECTION(".text") P_Clb1DataExchRegs = (volatile struct CLB_DATA_EXCHANGE_REGS *)0xC180;
volatile struct CLB_LOGIC_CONFIG_REGS *const CODE_SECTION(".text") P_Clb2LogicCfgRegs = (volatile struct CLB_LOGIC_CONFIG_REGS *)0xC400;
volatile struct CLB_LOGIC_CONTROL_REGS *const CODE_SECTION(".text") P_Clb2LogicCtrlRegs = (volatile struct CLB_LOGIC_CONTROL_REGS *)0xC500;
volatile struct CLB_DATA_EXCHANGE_REGS *const CODE_SECTION(".text") P_Clb2DataExchRegs = (volatile struct CLB_DATA_EXCHANGE_REGS *)0xC580;
volatile struct EQEP_REGS *const CODE_SECTION(".text") P_EQep1Regs = (volatile struct EQEP_REGS *)0xD000;
volatile struct EQEP_REGS *const CODE_SECTION(".text") P_EQep2Regs = (volatile struct EQEP_REGS *)0xD140;
volatile struct ECAP_REGS *const CODE_SECTION(".text") P_ECap1Regs = (volatile struct ECAP_REGS *)0xD400;
volatile struct ECAP_REGS *const CODE_SECTION(".text") P_ECap2Regs = (volatile struct ECAP_REGS *)0xD480;
volatile struct ECAP_REGS *const CODE_SECTION(".text") P_ECap3Regs = (volatile struct ECAP_REGS *)0xD500;
volatile struct HRCAP_REGS *const CODE_SECTION(".text") P_HRCap3Regs = (volatile struct HRCAP_REGS *)0xD780;
volatile struct CMPSS_REGS *const CODE_SECTION(".text") P_Cmpss1Regs = (volatile struct CMPSS_REGS *)0xD800;
volatile struct CMPSS_REGS *const CODE_SECTION(".text") P_Cmpss2Regs = (volatile struct CMPSS_REGS *)0xD880;
volatile struct CMPSS_REGS *const CODE_SECTION(".text") P_Cmpss3Regs = (volatile struct CMPSS_REGS *)0xD900;
volatile struct CMPSS_REGS *const CODE_SECTION(".text") P_Cmpss4Regs = (volatile struct CMPSS_REGS *)0xD980;
volatile struct SPI_REGS *const CODE_SECTION(".text") P_SpiaRegs = (volatile struct SPI_REGS *)0xE000;
volatile struct SPI_REGS *const CODE_SECTION(".text") P_SpibRegs = (volatile struct SPI_REGS *)0xE080;
volatile struct PMBUS_REGS *const CODE_SECTION(".text") P_PmbusaRegs = (volatile struct PMBUS_REGS *)0xE400;
volatile struct FSI_RX_REGS *const CODE_SECTION(".text") P_FsiRxaRegs = (volatile struct FSI_RX_REGS *)0xE800;
volatile struct FSI_TX_REGS *const CODE_SECTION(".text") P_FsiTxaRegs = (volatile struct FSI_TX_REGS *)0xEA00;
volatile struct I2S_REGS *const CODE_SECTION(".text") P_I2saRegs = (volatile struct I2S_REGS *)0xEC00;
volatile struct INPUT_XBAR_REGS *const CODE_SECTION(".text") P_InputXbarRegs = (volatile struct INPUT_XBAR_REGS *)0x31000;
volatile struct XBAR_REGS *const CODE_SECTION(".text") P_XbarRegs = (volatile struct XBAR_REGS *)0x31080;
volatile struct INPUT_XBAR_REGS *const CODE_SECTION(".text") P_ClbInputXbarRegs = (volatile struct INPUT_XBAR_REGS *)0x31180;
volatile struct EPWM_XBAR_REGS *const CODE_SECTION(".text") P_EPwmXbarRegs = (volatile struct EPWM_XBAR_REGS *)0x31400;
volatile struct CLB_XBAR_REGS *const CODE_SECTION(".text") P_ClbXbarRegs = (volatile struct CLB_XBAR_REGS *)0x31500;
volatile struct OUTPUT_XBAR_REGS *const CODE_SECTION(".text") P_OutputXbarRegs = (volatile struct OUTPUT_XBAR_REGS *)0x31600;
volatile struct OUTPUT_XBAR_REGS *const CODE_SECTION(".text") P_ClbOutputXbarRegs = (volatile struct OUTPUT_XBAR_REGS *)0x31B00;
volatile struct ERAD_GLOBAL_REGS *const CODE_SECTION(".text") P_EradGlobalRegs = (volatile struct ERAD_GLOBAL_REGS *)0x32800;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP1Regs = (volatile struct ERAD_HWBP_REGS *)0x328FC;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP2Regs = (volatile struct ERAD_HWBP_REGS *)0x32910;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP3Regs = (volatile struct ERAD_HWBP_REGS *)0x32924;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP4Regs = (volatile struct ERAD_HWBP_REGS *)0x32938;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP5Regs = (volatile struct ERAD_HWBP_REGS *)0x3294C;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP6Regs = (volatile struct ERAD_HWBP_REGS *)0x32960;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP7Regs = (volatile struct ERAD_HWBP_REGS *)0x32974;
volatile struct ERAD_HWBP_REGS *const CODE_SECTION(".text") P_EradHWBP8Regs = (volatile struct ERAD_HWBP_REGS *)0x32988;
volatile struct ERAD_COUNTER_REGS *const CODE_SECTION(".text") P_EradCounter1Regs = (volatile struct ERAD_COUNTER_REGS *)0x3299C;
volatile struct ERAD_COUNTER_REGS *const CODE_SECTION(".text") P_EradCounter2Regs = (volatile struct ERAD_COUNTER_REGS *)0x329C0;
volatile struct ERAD_COUNTER_REGS *const CODE_SECTION(".text") P_EradCounter3Regs = (volatile struct ERAD_COUNTER_REGS *)0x329E4;
volatile struct ERAD_COUNTER_REGS *const CODE_SECTION(".text") P_EradCounter4Regs = (volatile struct ERAD_COUNTER_REGS *)0x32A08;
volatile struct ERAD_CRC_GLOBAL_REGS *const CODE_SECTION(".text") P_EradCRCGlobalRegs = (volatile struct ERAD_CRC_GLOBAL_REGS *)0x32A2C;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC1Regs = (volatile struct ERAD_CRC_REGS *)0x32A30;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC2Regs = (volatile struct ERAD_CRC_REGS *)0x32A3C;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC3Regs = (volatile struct ERAD_CRC_REGS *)0x32A48;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC4Regs = (volatile struct ERAD_CRC_REGS *)0x32A54;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC5Regs = (volatile struct ERAD_CRC_REGS *)0x32A60;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC6Regs = (volatile struct ERAD_CRC_REGS *)0x32A6C;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC7Regs = (volatile struct ERAD_CRC_REGS *)0x32A78;
volatile struct ERAD_CRC_REGS *const CODE_SECTION(".text") P_EradCRC8Regs = (volatile struct ERAD_CRC_REGS *)0x32A84;
volatile struct DCC_REGS *const CODE_SECTION(".text") P_Dcc0Regs = (volatile struct DCC_REGS *)0x33000;
volatile struct DCC_REGS *const CODE_SECTION(".text") P_Dcc1Regs = (volatile struct DCC_REGS *)0x33080;
volatile struct GPIO_CTRL_REGS *const CODE_SECTION(".text") P_GpioCtrlRegs = (volatile struct GPIO_CTRL_REGS *)0x33800;
volatile struct GPIO_DATA_REGS *const CODE_SECTION(".text") P_GpioDataRegs = (volatile struct GPIO_DATA_REGS *)0x33E00;
volatile struct GPIO_DATA_READ_REGS *const CODE_SECTION(".text") P_GpioDataReadRegs = (volatile struct GPIO_DATA_READ_REGS *)0x33F00;
volatile struct LIN_REGS *const CODE_SECTION(".text") P_LinaRegs = (volatile struct LIN_REGS *)0x34000;
volatile struct LIN_REGS *const CODE_SECTION(".text") P_LinbRegs = (volatile struct LIN_REGS *)0x34080;
volatile struct SCI_REGS *const CODE_SECTION(".text") P_SciaRegs = (volatile struct SCI_REGS *)0x34400;
volatile struct I2C_REGS *const CODE_SECTION(".text") P_I2caRegs = (volatile struct I2C_REGS *)0x34800;
volatile struct I2C_REGS *const CODE_SECTION(".text") P_I2cbRegs = (volatile struct I2C_REGS *)0x34880;
volatile struct CLK_CFG_REGS *const CODE_SECTION(".text") P_ClkCfgRegs = (volatile struct CLK_CFG_REGS *)0x38000;
volatile struct CPU_SYS_REGS *const CODE_SECTION(".text") P_CpuSysRegs = (volatile struct CPU_SYS_REGS *)0x38200;
volatile struct DEV_CFG_REGS *const CODE_SECTION(".text") P_DevCfgRegs = (volatile struct DEV_CFG_REGS *)0x38400;
volatile struct PERIPH_AC_REGS *const CODE_SECTION(".text") P_SysPeriphAcRegs = (volatile struct PERIPH_AC_REGS *)0x38800;
volatile struct SYNC_SOC_REGS *const CODE_SECTION(".text") P_SyncSocRegs = (volatile struct SYNC_SOC_REGS *)0x38C00;
volatile struct DMA_CLA_SRC_SEL_REGS *const CODE_SECTION(".text") P_DmaClaSrcSelRegs = (volatile struct DMA_CLA_SRC_SEL_REGS *)0x38D00;
volatile struct WD_REGS *const CODE_SECTION(".text") P_WdRegs = (volatile struct WD_REGS *)0x38E00;
volatile struct ANALOG_SUBSYS_REGS *const CODE_SECTION(".text") P_AnalogSubsysRegs = (volatile struct ANALOG_SUBSYS_REGS *)0x39000;
volatile struct DCSM_BANK0_Z1_REGS *const CODE_SECTION(".text") P_DcsmBank0Z1Regs = (volatile struct DCSM_BANK0_Z1_REGS *)0x39400;
volatile struct DCSM_BANK0_Z2_REGS *const CODE_SECTION(".text") P_DcsmBank0Z2Regs = (volatile struct DCSM_BANK0_Z2_REGS *)0x39450;
volatile struct DCSM_COMMON_REGS *const CODE_SECTION(".text") P_DcsmCommonRegs = (volatile struct DCSM_COMMON_REGS *)0x394A0;
volatile struct DCSM_BANK0_Z1_OTP_REGS *const CODE_SECTION(".text") P_DcsmBank0Z1OtpRegs = (volatile struct DCSM_BANK0_Z1_OTP_REGS *)0x7A0000;
volatile struct DCSM_BANK0_Z2_OTP_REGS *const CODE_SECTION(".text") P_DcsmBank0Z2OtpRegs = (volatile struct DCSM_BANK0_Z2_OTP_REGS *)0x7A0400;
volatile struct FLASH_CTRL_REGS *const CODE_SECTION(".text") P_Flash0CtrlRegs = (volatile struct FLASH_CTRL_REGS *)0x7AF000;
volatile struct FLASH_ECC_REGS *const CODE_SECTION(".text") P_Flash0EccRegs = (volatile struct FLASH_ECC_REGS *)0x7AF200;

//===========================================================================
// End of file.
//===========================================================================
