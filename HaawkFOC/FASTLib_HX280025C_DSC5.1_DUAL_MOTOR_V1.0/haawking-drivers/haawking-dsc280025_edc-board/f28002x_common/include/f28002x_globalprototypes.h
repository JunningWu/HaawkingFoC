//###########################################################################
//
// FILE:   f28002x_globalprototypes.h
//
// TITLE:  Global prototypes for f28002x Examples
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef F28002x_GLOBALPROTOTYPES_H
#define F28002x_GLOBALPROTOTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// shared global function prototypes
//
extern void EnableInterrupts(void);
extern void InitPeripheralClocks(void);
extern void DisablePeripheralClocks(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
extern void InitSysCtrl(void);
extern void InitSysPll(Uint16 clock_source, Uint16 imult, Uint32 vco,Uint32 refdiv, Uint32 odiv,
                       Uint16 divsel, Uint32 dccbase);
extern bool IsPLLValid(Uint32 base, Uint16 oscSource, Uint16 pllclk, Uint16 imult,
                       Uint16 odiv, Uint16 refdiv);
extern void ComputeCntrSeedValue(Uint32 base, float fclk1_0ratio);

//
// For compatibility with previous versions
//
#define KickDog ServiceDog
extern void ServiceDog(void);
extern void DisableDog(void);
extern void EnableDog(void);

extern Uint16 CsmUnlock(void);
extern void SysIntOsc1Sel (void);
extern void SysIntOsc2Sel (void);
extern void SysXtalOscSel (void);
extern void SysXtalOscSESel (void);

//
//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
//
extern void InitFlash(void);
extern void FlashOff(void);

//
// LPM functions in f28002x_sysctrl.c
//
//void IDLE(void);
void HALT(void);

//
// ADC functions
//
extern void SetVREF(int module, int mode, int ref);

//
// DMA Functions
//
extern void DMAInitialize(void);

//
// DMA Channel 1
//
extern void DMACH1AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH1AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH1BurstConfig(Uint16 bsize, int16 srcbstep,
                              int16 desbstep);
extern void DMACH1TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH1WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH1ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont, Uint16 synce,
                             Uint16 syncsel, Uint16 ovrinte,
                             Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH1(void);

//
// DMA Channel 2
//
extern void DMACH2AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH2AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH2BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH2TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH2WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH2ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont,
                             Uint16 synce, Uint16 syncsel,
                             Uint16 ovrinte, Uint16 datasize,
                             Uint16 chintmode, Uint16 chinte);
extern void StartDMACH2(void);

//
// DMA Channel 3
//
extern void DMACH3AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH3AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH3BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH3TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH3WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH3ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont, Uint16 synce,
                             Uint16 syncsel, Uint16 ovrinte,
                             Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH3(void);

//
// DMA Channel 4
//
extern void DMACH4AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH4AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH4BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH4TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH4WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH4ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont, Uint16 synce,
                             Uint16 syncsel, Uint16 ovrinte,
                             Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH4(void);

//
// DMA Channel 5
//
extern void DMACH5AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH5AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH5BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH5TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH5WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH5ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont, Uint16 synce,
                             Uint16 syncsel, Uint16 ovrinte,
                             Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH5(void);

//
// DMA Channel 6
//
extern void DMACH6AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH6AddrConfig32bit(volatile Uint32 *DMA_Dest,
                                  volatile Uint32 *DMA_Source);
extern void DMACH6BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH6TransferConfig(Uint16 tsize, int16 srctstep,
                                 int16 deststep);
extern void DMACH6WrapConfig(Uint16 srcwsize, int16 srcwstep,
                             Uint16 deswsize, int16 deswstep);
extern void DMACH6ModeConfig(Uint16 persel, Uint16 perinte,
                             Uint16 oneshot, Uint16 cont, Uint16 synce,
                             Uint16 syncsel, Uint16 ovrinte,
                             Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH6(void);

//
// GPIO Functions
//
extern void InitGpio(void);
extern void GPIO_SetupPinMux(Uint16 gpioNumber, Uint16 cpu,
                             Uint16 muxPosition);
extern void GPIO_SetupPinOptions(Uint16 gpioNumber, Uint16 output,
                                 Uint16 flags);
extern void GPIO_SetupLock(Uint16 gpioNumber, Uint16 flags);
extern void GPIO_SetupXINT1Gpio(Uint16 gpioNumber);
extern void GPIO_SetupXINT2Gpio(Uint16 gpioNumber);
extern void GPIO_SetupXINT3Gpio(Uint16 gpioNumber);
extern void GPIO_SetupXINT4Gpio(Uint16 gpioNumber);
extern void GPIO_SetupXINT5Gpio(Uint16 gpioNumber);
Uint16 GPIO_ReadPin(Uint16 gpioNumber);
void GPIO_WritePin(Uint16 gpioNumber, Uint16 outVal);

// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in Flash to a different RUN location in internal
// RAM
//
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsRunEnd;
extern Uint16 RamfuncsRunSize;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F28002x_GLOBALPROTOTYPES_H

//
// End of file.
//
