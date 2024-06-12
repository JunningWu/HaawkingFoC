/*#############################################################################*/
/*                                                                             */
/* $Copyright:                                                                 */
/* Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd               */
/* http://www.haawking.com/ All rights reserved.                               */
/*                                                                             */
/* Redistribution and use in source and binary forms, with or without          */
/* modification, are permitted provided that the following conditions          */
/* are met:                                                                    */
/*                                                                             */
/*   Redistributions of source code must retain the above copyright            */
/*   notice, this list of conditions and the following disclaimer.             */
/*                                                                             */
/*   Redistributions in binary form must reproduce the above copyright         */
/*   notice, this list of conditions and the following disclaimer in the       */
/*   documentation and/or other materials provided with the                    */
/*   distribution.                                                             */
/*                                                                             */
/*   Neither the name of Beijing Haawking Technology Co.,Ltd nor the names of  */
/*   its contributors may be used to endorse or promote products derived       */
/*   from this software without specific prior written permission.             */
/*                                                                             */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS         */
/* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT           */
/* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR       */
/* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT        */
/* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,       */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT            */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,       */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY       */
/* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT         */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE       */
/* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.        */
/*                                                                             */
/*#############################################################################*/
/*                                                                             */
/* Release for HXS320F280025CEDC, BootROM Linker, 1.0.0                        */
/*                                                                             */
/* Release time: 2024-01-19 15:18:15.896573                                    */
/*                                                                             */
/*#############################################################################*/


/*----------------------------------------------------------------------*/
/* Memories                                                             */
/*----------------------------------------------------------------------*/
MEMORY
{
    BOOTROM_FILE                    (rx)   : ORIGIN = 0x7E0000  , LENGTH = 0x20000            /* On-Chip BootROM */              
}

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/
SECTIONS
{
    _IQsinTable            0x7E2804(NOLOAD)   : {IQsinTable = .; IQcosTable = . + 512;}    > BOOTROM_FILE           
    _IQdivRoundSatTable    0x7E3208(NOLOAD)   : {IQdivRoundSatTable = .;}                  > BOOTROM_FILE           
    _IQdivTable            0x7E3224(NOLOAD)   : {IQdivTable = .;}                          > BOOTROM_FILE           
    _IQisqrtRoundSatTable  0x7E3628(NOLOAD)   : {IQisqrtRoundSatTable = .;}                > BOOTROM_FILE           
    _IQisqrtTable          0x7E3648(NOLOAD)   : {IQisqrtTable = .;}                        > BOOTROM_FILE           
    _IQatan2HalfPITable    0x7E384C(NOLOAD)   : {IQatan2HalfPITable = .;}                  > BOOTROM_FILE           
    _IQatan2Table          0x7E38C8(NOLOAD)   : {IQatan2Table = .;}                        > BOOTROM_FILE           
    _IQexpTableMinMax      0x7E3EA4(NOLOAD)   : {IQexpTableMinMax = .;}                    > BOOTROM_FILE           
    _IQexpTableCoeff       0x7E3F94(NOLOAD)   : {IQexpTableCoeff = .;}                     > BOOTROM_FILE           
    _IQasinTable           0x7E3FBC(NOLOAD)   : {IQasinTable = .;}                         > BOOTROM_FILE           
}
