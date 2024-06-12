//###########################################################################
//
// FILE:   f28002x_dma_defines.h
//
// TITLE:  #defines used in DMA examples
//
//###########################################################################
// $HAAWKING Release: BitField Support Library V1.0.0 $
// $Release Date: 2024-01-25 05:17:42 $
// $Copyright:
// Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef F28002X_DMA_DEFINES_H_
#define F28002X_DMA_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//

//
// PERINTSEL bits
//
#define DMA_ADCAINT1    1
#define DMA_ADCAINT2    2
#define DMA_ADCAINT3    3
#define DMA_ADCAINT4    4
#define DMA_ADCAEVT     5
#define DMA_ADCCINT1    11
#define DMA_ADCCINT2    12
#define DMA_ADCCINT3    13
#define DMA_ADCCINT4    14
#define DMA_ADCCEVT     15

#define DMA_XINT1       29
#define DMA_XINT2       30
#define DMA_XINT3       31
#define DMA_XINT4       32
#define DMA_XINT5       33

#define DMA_EPWM1A      36
#define DMA_EPWM1B      37
#define DMA_EPWM2A      38
#define DMA_EPWM2B      39
#define DMA_EPWM3A      40
#define DMA_EPWM3B      41
#define DMA_EPWM4A      42
#define DMA_EPWM4B      43
#define DMA_EPWM5A      44
#define DMA_EPWM5B      45
#define DMA_EPWM6A      46
#define DMA_EPWM6B      47
#define DMA_EPWM7A      48
#define DMA_EPWM7B      49

#define DMA_TINT0       68
#define DMA_TINT1       69
#define DMA_TINT2       70

#define DMA_ECAP1       75
#define DMA_ECAP2       76
#define DMA_ECAP3       77

#define DMA_SPIATX      109
#define DMA_SPIARX      110
#define DMA_SPIBTX      111
#define DMA_SPIBRX      112

#define DMA_LINATX      117
#define DMA_LINARX      118
#define DMA_LINBTX      119
#define DMA_LINBRX      120

#define DMA_FSITXA      123
#define DMA_FSIRXA      125

#define DMA_CLB1        127
#define DMA_CLB2        128

#define DMA_CANAIF1     167
#define DMA_CANAIF2     168
#define DMA_CANAIF3     169

//
// OVERINTE bit
//
#define OVRFLOW_DISABLE 0x0
#define OVEFLOW_ENABLE  0x1

//
// PERINTE bit
//
#define PERINT_DISABLE  0x0
#define PERINT_ENABLE   0x1

//
// CHINTMODE bits
//
#define CHINT_BEGIN     0x0
#define CHINT_END       0x1

//
// ONESHOT bits
//
#define ONESHOT_DISABLE 0x0
#define ONESHOT_ENABLE  0x1

//
// CONTINOUS bit
//
#define CONT_DISABLE    0x0
#define CONT_ENABLE     0x1

//
// SYNCE bit
//
#define SYNC_DISABLE    0x0
#define SYNC_ENABLE     0x1

//
// SYNCSEL bit
//
#define SYNC_SRC        0x0
#define SYNC_DST        0x1

//
// DATASIZE bit
//
#define SIXTEEN_BIT     0x0
#define THIRTYTWO_BIT   0x1

//
// CHINTE bit
//
#define CHINT_DISABLE   0x0
#define CHINT_ENABLE    0x1

#ifdef __cplusplus
}
#endif

#endif /*end of F28002X_DMA_DEFINES_H_ */
//
// End of file
//
