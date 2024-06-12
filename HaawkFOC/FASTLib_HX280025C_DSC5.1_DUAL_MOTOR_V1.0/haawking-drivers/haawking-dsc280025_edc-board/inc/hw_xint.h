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


#ifndef HW_XINT_H
#define HW_XINT_H

//*************************************************************************************************
//
// The following are defines for the XINT register offsets
//
//*************************************************************************************************
#define XINT_O_1CR    0x0U    // XINT1 configuration register
#define XINT_O_2CR    0x4U    // XINT2 configuration register
#define XINT_O_3CR    0x8U    // XINT3 configuration register
#define XINT_O_4CR    0xCU    // XINT4 configuration register
#define XINT_O_5CR    0x10U   // XINT5 configuration register
#define XINT_O_1CTR   0x14U   // XINT1 counter register
#define XINT_O_2CTR   0x18U   // XINT2 counter register
#define XINT_O_3CTR   0x1CU   // XINT3 counter register


//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT1CR register
//
//*************************************************************************************************
#define XINT_1CR_ENABLE       0x1U   // XINT1 Enable
#define XINT_1CR_POLARITY_S   2U
#define XINT_1CR_POLARITY_M   0xCU   // XINT1 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT2CR register
//
//*************************************************************************************************
#define XINT_2CR_ENABLE       0x1U   // XINT2 Enable
#define XINT_2CR_POLARITY_S   2U
#define XINT_2CR_POLARITY_M   0xCU   // XINT2 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT3CR register
//
//*************************************************************************************************
#define XINT_3CR_ENABLE       0x1U   // XINT3 Enable
#define XINT_3CR_POLARITY_S   2U
#define XINT_3CR_POLARITY_M   0xCU   // XINT3 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT4CR register
//
//*************************************************************************************************
#define XINT_4CR_ENABLE       0x1U   // XINT4 Enable
#define XINT_4CR_POLARITY_S   2U
#define XINT_4CR_POLARITY_M   0xCU   // XINT4 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the XINT5CR register
//
//*************************************************************************************************
#define XINT_5CR_ENABLE       0x1U   // XINT5 Enable
#define XINT_5CR_POLARITY_S   2U
#define XINT_5CR_POLARITY_M   0xCU   // XINT5 Polarity



#endif
