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
// Release for HXS320F280025CEDC, Hal DriverLib, 1.0.0
//
// Release time: 2024-01-25 15:09:27.423271
//
//#############################################################################


#ifndef HW_HRCAP_H
#define HW_HRCAP_H

//*************************************************************************************************
//
// The following are defines for the HRCAP register offsets
//
//*************************************************************************************************
#define HRCAP_O_HCCTL           0x0U    // none
#define HRCAP_O_HCIFR           0x4U    // none
#define HRCAP_O_HCICLR          0x8U    // none
#define HRCAP_O_HCIFRC          0xCU    // none
#define HRCAP_O_HCCOUNTER       0x10U   // none
#define HRCAP_O_HCCAL           0x14U   // none
#define HRCAP_O_HCCALMEP        0x18U   // none
#define HRCAP_O_HCMEPSTATUS     0x1CU   // none
#define HRCAP_O_HCCAPCNTRISE0   0x40U   // none
#define HRCAP_O_HCCAPCNTFALL0   0x48U   // none
#define HRCAP_O_HCCAPCNTRISE1   0x60U   // none
#define HRCAP_O_HCCAPCNTFALL1   0x68U   // none


//*************************************************************************************************
//
// The following are defines for the bit fields in the HCCTL register
//
//*************************************************************************************************
#define HRCAP_HCCTL_SOFTRESET     0x1U     // Writing 1 to this bit will clear HCCOUNTER
#define HRCAP_HCCTL_RISEINTE      0x2U     // High Resolution Clock Enable
#define HRCAP_HCCTL_FALLINTE      0x4U     // Calibration Period Match
#define HRCAP_HCCTL_OVFINTE       0x8U     // Calibration start
#define HRCAP_HCCTL_HCCAPCLKSEL   0x100U   // Calibration status

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCIFR register
//
//*************************************************************************************************
#define HRCAP_HCIFR_INT          0x1U    // Global interrupt flag
#define HRCAP_HCIFR_RISE         0x2U    // Rising edge capture interrupt flag
#define HRCAP_HCIFR_FALL         0x4U    // Falling edge capture interrupt flag
#define HRCAP_HCIFR_COUNTEROVF   0x8U    // Counter overflow interrupt flag
#define HRCAP_HCIFR_RISEOVF      0x10U   // Rising edge interrupt overflow event flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCICLR register
//
//*************************************************************************************************
#define HRCAP_HCICLR_INT          0x1U    // Global clear flag
#define HRCAP_HCICLR_RISE         0x2U    // Rising edge capture clear flag
#define HRCAP_HCICLR_FALL         0x4U    // Falling edge capture clear flag
#define HRCAP_HCICLR_COUNTEROVF   0x8U    // Counter overflow interrupt clear bit
#define HRCAP_HCICLR_RISEOVF      0x10U   // Rising edge interrupt overflow clear bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCIFRC register
//
//*************************************************************************************************
#define HRCAP_HCIFRC_RISE         0x2U   // Rising edge interrupt forcing bit
#define HRCAP_HCIFRC_FALL         0x4U   // Falling edge interrupt forcing bit
#define HRCAP_HCIFRC_COUNTEROVF   0x8U   // Counter overflow interrupt forcing bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCCOUNTER register
//
//*************************************************************************************************
#define HRCAP_HCCOUNTER_CALIBINT       0x1U   // Clear Global calibration Interrupt Flag
#define HRCAP_HCCOUNTER_CALIBDONE      0x2U   // Clear Calibration Done Interrupt Flag Bit
#define HRCAP_HCCOUNTER_CALPRDCHKSTS   0x4U   // Clear Calibration period check status Flag Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCCAL register
//
//*************************************************************************************************
#define HRCAP_HCCAL_DLL_START_POINTS_S   0U
#define HRCAP_HCCAL_DLL_START_POINTS_M   0xFFU     // Dll initial value
#define HRCAP_HCCAL_PHASE_DETECT_SEL_S   8U
#define HRCAP_HCCAL_PHASE_DETECT_SEL_M   0x700U    // And DLL START Point is used together to calculate
#define HRCAP_HCCAL_HRCAPMODE            0x4000U   // When HRPWMSEL is equal to 1, HRCAP belongs to
#define HRCAP_HCCAL_HRPWMSEL             0x8000U   // 

//*************************************************************************************************
//
// The following are defines for the bit fields in the HCMEPSTATUS register
//
//*************************************************************************************************
#define HRCAP_HCMEPSTATUS_LOCK_S               0U
#define HRCAP_HCMEPSTATUS_LOCK_M               0x3U     // Lock status bit
#define HRCAP_HCMEPSTATUS_MEP_SCALE_FACTOR_S   2U
#define HRCAP_HCMEPSTATUS_MEP_SCALE_FACTOR_M   0x3FCU   // MEP Scale Factor bit



#endif
