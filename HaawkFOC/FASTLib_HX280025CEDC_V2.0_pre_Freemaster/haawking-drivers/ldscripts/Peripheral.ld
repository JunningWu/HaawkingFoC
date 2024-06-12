/*#############################################################################*/
/*                                                                             */
/* $Copyright:                                                                 */
/* Copyright (C) 2019-2023 Beijing Haawking Technology Co.,Ltd                 */
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
/* Release for HXS320F280025CEDC, Peripheral Linker, 1.0.0                     */
/*                                                                             */
/* Release time: 2024-01-19 15:18:15.655404                                    */
/*                                                                             */
/*#############################################################################*/


/*----------------------------------------------------------------------*/
/* Memories                                                             */
/*----------------------------------------------------------------------*/
MEMORY
{
    AdcaRegs_FILE                   (rwx)  : ORIGIN = 0x1800    , LENGTH = 0x110              /* Adca registers */               
    AdcaResultRegs_FILE             (rwx)  : ORIGIN = 0x1940    , LENGTH = 0x50               /* AdcaResult registers */         
    AdccRegs_FILE                   (rwx)  : ORIGIN = 0x1C00    , LENGTH = 0x110              /* Adcc registers */               
    AdccResultRegs_FILE             (rwx)  : ORIGIN = 0x1D40    , LENGTH = 0x50               /* AdccResult registers */         
    HicRegs_FILE                    (rwx)  : ORIGIN = 0x2800    , LENGTH = 0x100              /* Hic registers */                
    DmaRegs_FILE                    (rwx)  : ORIGIN = 0x3000    , LENGTH = 0x380              /* Dma registers */                               
    BgcrcCpuRegs_FILE               (rwx)  : ORIGIN = 0x3400    , LENGTH = 0x110              /* BgcrcCpu registers */           
    MemCfgRegs_FILE                 (rwx)  : ORIGIN = 0x3800    , LENGTH = 0x5C               /* MemCfg registers */             
    MemoryErrorRegs_FILE            (rwx)  : ORIGIN = 0x385C    , LENGTH = 0x40               /* MemoryError registers */        
    AccessProtectionRegs_FILE       (rwx)  : ORIGIN = 0x389C    , LENGTH = 0x50               /* AccessProtection registers */   
    CpuTimer0Regs_FILE              (rwx)  : ORIGIN = 0x5000    , LENGTH = 0x10               /* CpuTimer0 registers */          
    CpuTimer1Regs_FILE              (rwx)  : ORIGIN = 0x5010    , LENGTH = 0x10               /* CpuTimer1 registers */          
    CpuTimer2Regs_FILE              (rwx)  : ORIGIN = 0x5020    , LENGTH = 0x10               /* CpuTimer2 registers */          
    PieCtrlRegs_FILE                (rwx)  : ORIGIN = 0x5100    , LENGTH = 0x68               /* PieCtrl registers */            
    XintRegs_FILE                   (rwx)  : ORIGIN = 0x5200    , LENGTH = 0x20               /* Xint registers */               
    NmiIntruptRegs_FILE             (rwx)  : ORIGIN = 0x5300    , LENGTH = 0x30               /* NmiIntrupt registers */         
    PieVectTable_FILE               (rwx)  : ORIGIN = 0x5800    , LENGTH = 0x400              /* PieVectT registers */           
    CanaRegs_FILE                   (rwx)  : ORIGIN = 0x6000    , LENGTH = 0x164              /* Cana registers */               
    EPwm1Regs_FILE                  (rwx)  : ORIGIN = 0xA000    , LENGTH = 0x3FC              /* EPwm1 registers */              
    EPwm2Regs_FILE                  (rwx)  : ORIGIN = 0xA400    , LENGTH = 0x3FC              /* EPwm2 registers */              
    EPwm3Regs_FILE                  (rwx)  : ORIGIN = 0xA800    , LENGTH = 0x3FC              /* EPwm3 registers */              
    EPwm4Regs_FILE                  (rwx)  : ORIGIN = 0xAC00    , LENGTH = 0x3FC              /* EPwm4 registers */              
    EPwm5Regs_FILE                  (rwx)  : ORIGIN = 0xB000    , LENGTH = 0x3FC              /* EPwm5 registers */              
    EPwm6Regs_FILE                  (rwx)  : ORIGIN = 0xB400    , LENGTH = 0x3FC              /* EPwm6 registers */              
    EPwm7Regs_FILE                  (rwx)  : ORIGIN = 0xB800    , LENGTH = 0x3FC              /* EPwm7 registers */              
    Clb1LogicCfgRegs_FILE           (rwx)  : ORIGIN = 0xC000    , LENGTH = 0xAC               /* Clb1LogicCfg registers */       
    Clb1LogicCtrlRegs_FILE          (rwx)  : ORIGIN = 0xC100    , LENGTH = 0x80               /* Clb1LogicCtrl registers */      
    Clb1DataExchRegs_FILE           (rwx)  : ORIGIN = 0xC180    , LENGTH = 0x84               /* Clb1DataExch registers */       
    Clb2LogicCfgRegs_FILE           (rwx)  : ORIGIN = 0xC400    , LENGTH = 0xAC               /* Clb2LogicCfg registers */       
    Clb2LogicCtrlRegs_FILE          (rwx)  : ORIGIN = 0xC500    , LENGTH = 0x80               /* Clb2LogicCtrl registers */      
    Clb2DataExchRegs_FILE           (rwx)  : ORIGIN = 0xC580    , LENGTH = 0x84               /* Clb2DataExch registers */       
    EQep1Regs_FILE                  (rwx)  : ORIGIN = 0xD000    , LENGTH = 0x70               /* EQep1 registers */              
    EQep2Regs_FILE                  (rwx)  : ORIGIN = 0xD140    , LENGTH = 0x70               /* EQep2 registers */              
    ECap1Regs_FILE                  (rwx)  : ORIGIN = 0xD400    , LENGTH = 0x40               /* ECap1 registers */              
    ECap2Regs_FILE                  (rwx)  : ORIGIN = 0xD480    , LENGTH = 0x40               /* ECap2 registers */              
    ECap3Regs_FILE                  (rwx)  : ORIGIN = 0xD500    , LENGTH = 0x40               /* ECap3 registers */              
    HRCap3Regs_FILE                 (rwx)  : ORIGIN = 0xD780    , LENGTH = 0x6C               /* HRCap3 registers */             
    Cmpss1Regs_FILE                 (rwx)  : ORIGIN = 0xD800    , LENGTH = 0x58               /* Cmpss1 registers */             
    Cmpss2Regs_FILE                 (rwx)  : ORIGIN = 0xD880    , LENGTH = 0x58               /* Cmpss2 registers */             
    Cmpss3Regs_FILE                 (rwx)  : ORIGIN = 0xD900    , LENGTH = 0x58               /* Cmpss3 registers */             
    Cmpss4Regs_FILE                 (rwx)  : ORIGIN = 0xD980    , LENGTH = 0x58               /* Cmpss4 registers */             
    SpiaRegs_FILE                   (rwx)  : ORIGIN = 0xE000    , LENGTH = 0x3C               /* Spia registers */               
    SpibRegs_FILE                   (rwx)  : ORIGIN = 0xE080    , LENGTH = 0x3C               /* Spib registers */               
    PmbusaRegs_FILE                 (rwx)  : ORIGIN = 0xE400    , LENGTH = 0x3C               /* Pmbusa registers */             
    FsiRxaRegs_FILE                 (rwx)  : ORIGIN = 0xE800    , LENGTH = 0x200              /* FsiRxa registers */             
    FsiTxaRegs_FILE                 (rwx)  : ORIGIN = 0xEA00    , LENGTH = 0x200              /* FsiTxa registers */             
    I2saRegs_FILE                   (rwx)  : ORIGIN = 0xEC00    , LENGTH = 0x38               /* I2sa registers */               
    InputXbarRegs_FILE              (rwx)  : ORIGIN = 0x31000   , LENGTH = 0x7C               /* InputXbar registers */          
    XbarRegs_FILE                   (rwx)  : ORIGIN = 0x31080   , LENGTH = 0x20               /* Xbar registers */               
    ClbInputXbarRegs_FILE           (rwx)  : ORIGIN = 0x31180   , LENGTH = 0x7C               /* ClbInputXbar registers */       
    EPwmXbarRegs_FILE               (rwx)  : ORIGIN = 0x31400   , LENGTH = 0x78               /* EPwmXbar registers */           
    ClbXbarRegs_FILE                (rwx)  : ORIGIN = 0x31500   , LENGTH = 0x80               /* ClbXbar registers */            
    OutputXbarRegs_FILE             (rwx)  : ORIGIN = 0x31600   , LENGTH = 0x80               /* OutputXbar registers */         
    ClbOutputXbarRegs_FILE          (rwx)  : ORIGIN = 0x31B00   , LENGTH = 0x80               /* ClbOutputXbar registers */      
    EradGlobalRegs_FILE             (rwx)  : ORIGIN = 0x32800   , LENGTH = 0xFC               /* EradGlobal registers */         
    EradHWBP1Regs_FILE              (rwx)  : ORIGIN = 0x328FC   , LENGTH = 0x14               /* EradHWBP1 registers */          
    EradHWBP2Regs_FILE              (rwx)  : ORIGIN = 0x32910   , LENGTH = 0x14               /* EradHWBP2 registers */          
    EradHWBP3Regs_FILE              (rwx)  : ORIGIN = 0x32924   , LENGTH = 0x14               /* EradHWBP3 registers */          
    EradHWBP4Regs_FILE              (rwx)  : ORIGIN = 0x32938   , LENGTH = 0x14               /* EradHWBP4 registers */          
    EradHWBP5Regs_FILE              (rwx)  : ORIGIN = 0x3294C   , LENGTH = 0x14               /* EradHWBP5 registers */          
    EradHWBP6Regs_FILE              (rwx)  : ORIGIN = 0x32960   , LENGTH = 0x14               /* EradHWBP6 registers */          
    EradHWBP7Regs_FILE              (rwx)  : ORIGIN = 0x32974   , LENGTH = 0x14               /* EradHWBP7 registers */          
    EradHWBP8Regs_FILE              (rwx)  : ORIGIN = 0x32988   , LENGTH = 0x14               /* EradHWBP8 registers */          
    EradCounter1Regs_FILE           (rwx)  : ORIGIN = 0x3299C   , LENGTH = 0x24               /* EradCounter1 registers */       
    EradCounter2Regs_FILE           (rwx)  : ORIGIN = 0x329C0   , LENGTH = 0x24               /* EradCounter2 registers */       
    EradCounter3Regs_FILE           (rwx)  : ORIGIN = 0x329E4   , LENGTH = 0x24               /* EradCounter3 registers */       
    EradCounter4Regs_FILE           (rwx)  : ORIGIN = 0x32A08   , LENGTH = 0x24               /* EradCounter4 registers */       
    EradCRCGlobalRegs_FILE          (rwx)  : ORIGIN = 0x32A2C   , LENGTH = 0x4                /* EradCRCGlobal registers */      
    EradCRC1Regs_FILE               (rwx)  : ORIGIN = 0x32A30   , LENGTH = 0xC                /* EradCRC1 registers */           
    EradCRC2Regs_FILE               (rwx)  : ORIGIN = 0x32A3C   , LENGTH = 0xC                /* EradCRC2 registers */           
    EradCRC3Regs_FILE               (rwx)  : ORIGIN = 0x32A48   , LENGTH = 0xC                /* EradCRC3 registers */           
    EradCRC4Regs_FILE               (rwx)  : ORIGIN = 0x32A54   , LENGTH = 0xC                /* EradCRC4 registers */           
    EradCRC5Regs_FILE               (rwx)  : ORIGIN = 0x32A60   , LENGTH = 0xC                /* EradCRC5 registers */           
    EradCRC6Regs_FILE               (rwx)  : ORIGIN = 0x32A6C   , LENGTH = 0xC                /* EradCRC6 registers */           
    EradCRC7Regs_FILE               (rwx)  : ORIGIN = 0x32A78   , LENGTH = 0xC                /* EradCRC7 registers */           
    EradCRC8Regs_FILE               (rwx)  : ORIGIN = 0x32A84   , LENGTH = 0xC                /* EradCRC8 registers */           
    Dcc0Regs_FILE                   (rwx)  : ORIGIN = 0x33000   , LENGTH = 0x3C               /* Dcc0 registers */               
    Dcc1Regs_FILE                   (rwx)  : ORIGIN = 0x33080   , LENGTH = 0x3C               /* Dcc1 registers */               
    GpioCtrlRegs_FILE               (rwx)  : ORIGIN = 0x33800   , LENGTH = 0x600              /* GpioCtrl registers */           
    GpioDataRegs_FILE               (rwx)  : ORIGIN = 0x33E00   , LENGTH = 0x100              /* GpioData registers */           
    GpioDataReadRegs_FILE           (rwx)  : ORIGIN = 0x33F00   , LENGTH = 0x74               /* GpioDataRead registers */       
    LinaRegs_FILE                   (rwx)  : ORIGIN = 0x34000   , LENGTH = 0x74               /* Lina registers */               
    LinbRegs_FILE                   (rwx)  : ORIGIN = 0x34080   , LENGTH = 0x74               /* Linb registers */               
    SciaRegs_FILE                   (rwx)  : ORIGIN = 0x34400   , LENGTH = 0x3C               /* Scia registers */               
    I2caRegs_FILE                   (rwx)  : ORIGIN = 0x34800   , LENGTH = 0x3C               /* I2ca registers */               
    I2cbRegs_FILE                   (rwx)  : ORIGIN = 0x34880   , LENGTH = 0x3C               /* I2cb registers */               
    ClkCfgRegs_FILE                 (rwx)  : ORIGIN = 0x38000   , LENGTH = 0x80               /* ClkCfg registers */             
    CpuSysRegs_FILE                 (rwx)  : ORIGIN = 0x38200   , LENGTH = 0x108              /* CpuSys registers */             
    DevCfgRegs_FILE                 (rwx)  : ORIGIN = 0x38400   , LENGTH = 0x33C              /* DevCfg registers */             
    SysPeriphAcRegs_FILE            (rwx)  : ORIGIN = 0x38800   , LENGTH = 0x400              /* SysPeriphAc registers */        
    SyncSocRegs_FILE                (rwx)  : ORIGIN = 0x38C00   , LENGTH = 0x3C               /* SyncSoc registers */            
    DmaClaSrcSelRegs_FILE           (rwx)  : ORIGIN = 0x38D00   , LENGTH = 0x34               /* DmaClaSrcSel registers */       
    WdRegs_FILE                     (rwx)  : ORIGIN = 0x38E00   , LENGTH = 0x58               /* Wd registers */                 
    AnalogSubsysRegs_FILE           (rwx)  : ORIGIN = 0x39000   , LENGTH = 0x24               /* AnalogSubsys registers */       
    DcsmBank0Z1Regs_FILE            (rwx)  : ORIGIN = 0x39400   , LENGTH = 0x48               /* DcsmBank0Z1 registers */        
    DcsmBank0Z2Regs_FILE            (rwx)  : ORIGIN = 0x39450   , LENGTH = 0x48               /* DcsmBank0Z2 registers */        
    DcsmCommonRegs_FILE             (rwx)  : ORIGIN = 0x394A0   , LENGTH = 0x20               /* DcsmCommon registers */         
    DcsmBank0Z1OtpRegs_FILE         (rwx)  : ORIGIN = 0x7A0000  , LENGTH = 0x400              /* DcsmBank0Z1Otp registers */     
    DcsmBank0Z2OtpRegs_FILE         (rwx)  : ORIGIN = 0x7A0400  , LENGTH = 0x400              /* DcsmBank0Z2Otp registers */     
    Flash0CtrlRegs_FILE             (rwx)  : ORIGIN = 0x7AF000  , LENGTH = 0x200              /* Flash0Ctrl registers */         
    Flash0EccRegs_FILE              (rwx)  : ORIGIN = 0x7AF200  , LENGTH = 0x50               /* Flash0Ecc registers */          
}

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/
SECTIONS
{
    .AdcaRegs(NOLOAD)              : {*(.AdcaRegs)}              > AdcaRegs_FILE          
    .AdcaResultRegs(NOLOAD)        : {*(.AdcaResultRegs)}        > AdcaResultRegs_FILE    
    .AdccRegs(NOLOAD)              : {*(.AdccRegs)}              > AdccRegs_FILE          
    .AdccResultRegs(NOLOAD)        : {*(.AdccResultRegs)}        > AdccResultRegs_FILE    
    .HicRegs(NOLOAD)               : {*(.HicRegs)}               > HicRegs_FILE           
    .DmaRegs(NOLOAD)               : {*(.DmaRegs)}               > DmaRegs_FILE                    
    .BgcrcCpuRegs(NOLOAD)          : {*(.BgcrcCpuRegs)}          > BgcrcCpuRegs_FILE      
    .MemCfgRegs(NOLOAD)            : {*(.MemCfgRegs)}            > MemCfgRegs_FILE        
    .MemoryErrorRegs(NOLOAD)       : {*(.MemoryErrorRegs)}       > MemoryErrorRegs_FILE   
    .AccessProtectionRegs(NOLOAD)  : {*(.AccessProtectionRegs)}  > AccessProtectionRegs_FILE
    .CpuTimer0Regs(NOLOAD)         : {*(.CpuTimer0Regs)}         > CpuTimer0Regs_FILE     
    .CpuTimer1Regs(NOLOAD)         : {*(.CpuTimer1Regs)}         > CpuTimer1Regs_FILE     
    .CpuTimer2Regs(NOLOAD)         : {*(.CpuTimer2Regs)}         > CpuTimer2Regs_FILE     
    .PieCtrlRegs(NOLOAD)           : {*(.PieCtrlRegs)}           > PieCtrlRegs_FILE       
    .XintRegs(NOLOAD)              : {*(.XintRegs)}              > XintRegs_FILE          
    .NmiIntruptRegs(NOLOAD)        : {*(.NmiIntruptRegs)}        > NmiIntruptRegs_FILE    
    .PieVectTable(NOLOAD)          : {*(.PieVectTable)}          > PieVectTable_FILE      
    .CanaRegs(NOLOAD)              : {*(.CanaRegs)}              > CanaRegs_FILE          
    .EPwm1Regs(NOLOAD)             : {*(.EPwm1Regs)}             > EPwm1Regs_FILE         
    .EPwm2Regs(NOLOAD)             : {*(.EPwm2Regs)}             > EPwm2Regs_FILE         
    .EPwm3Regs(NOLOAD)             : {*(.EPwm3Regs)}             > EPwm3Regs_FILE         
    .EPwm4Regs(NOLOAD)             : {*(.EPwm4Regs)}             > EPwm4Regs_FILE         
    .EPwm5Regs(NOLOAD)             : {*(.EPwm5Regs)}             > EPwm5Regs_FILE         
    .EPwm6Regs(NOLOAD)             : {*(.EPwm6Regs)}             > EPwm6Regs_FILE         
    .EPwm7Regs(NOLOAD)             : {*(.EPwm7Regs)}             > EPwm7Regs_FILE         
    .Clb1LogicCfgRegs(NOLOAD)      : {*(.Clb1LogicCfgRegs)}      > Clb1LogicCfgRegs_FILE  
    .Clb1LogicCtrlRegs(NOLOAD)     : {*(.Clb1LogicCtrlRegs)}     > Clb1LogicCtrlRegs_FILE 
    .Clb1DataExchRegs(NOLOAD)      : {*(.Clb1DataExchRegs)}      > Clb1DataExchRegs_FILE  
    .Clb2LogicCfgRegs(NOLOAD)      : {*(.Clb2LogicCfgRegs)}      > Clb2LogicCfgRegs_FILE  
    .Clb2LogicCtrlRegs(NOLOAD)     : {*(.Clb2LogicCtrlRegs)}     > Clb2LogicCtrlRegs_FILE 
    .Clb2DataExchRegs(NOLOAD)      : {*(.Clb2DataExchRegs)}      > Clb2DataExchRegs_FILE  
    .EQep1Regs(NOLOAD)             : {*(.EQep1Regs)}             > EQep1Regs_FILE         
    .EQep2Regs(NOLOAD)             : {*(.EQep2Regs)}             > EQep2Regs_FILE         
    .ECap1Regs(NOLOAD)             : {*(.ECap1Regs)}             > ECap1Regs_FILE         
    .ECap2Regs(NOLOAD)             : {*(.ECap2Regs)}             > ECap2Regs_FILE         
    .ECap3Regs(NOLOAD)             : {*(.ECap3Regs)}             > ECap3Regs_FILE         
    .HRCap3Regs(NOLOAD)            : {*(.HRCap3Regs)}            > HRCap3Regs_FILE        
    .Cmpss1Regs(NOLOAD)            : {*(.Cmpss1Regs)}            > Cmpss1Regs_FILE        
    .Cmpss2Regs(NOLOAD)            : {*(.Cmpss2Regs)}            > Cmpss2Regs_FILE        
    .Cmpss3Regs(NOLOAD)            : {*(.Cmpss3Regs)}            > Cmpss3Regs_FILE        
    .Cmpss4Regs(NOLOAD)            : {*(.Cmpss4Regs)}            > Cmpss4Regs_FILE        
    .SpiaRegs(NOLOAD)              : {*(.SpiaRegs)}              > SpiaRegs_FILE          
    .SpibRegs(NOLOAD)              : {*(.SpibRegs)}              > SpibRegs_FILE          
    .PmbusaRegs(NOLOAD)            : {*(.PmbusaRegs)}            > PmbusaRegs_FILE        
    .FsiRxaRegs(NOLOAD)            : {*(.FsiRxaRegs)}            > FsiRxaRegs_FILE        
    .FsiTxaRegs(NOLOAD)            : {*(.FsiTxaRegs)}            > FsiTxaRegs_FILE        
    .I2saRegs(NOLOAD)              : {*(.I2saRegs)}              > I2saRegs_FILE          
    .InputXbarRegs(NOLOAD)         : {*(.InputXbarRegs)}         > InputXbarRegs_FILE     
    .XbarRegs(NOLOAD)              : {*(.XbarRegs)}              > XbarRegs_FILE          
    .ClbInputXbarRegs(NOLOAD)      : {*(.ClbInputXbarRegs)}      > ClbInputXbarRegs_FILE  
    .EPwmXbarRegs(NOLOAD)          : {*(.EPwmXbarRegs)}          > EPwmXbarRegs_FILE      
    .ClbXbarRegs(NOLOAD)           : {*(.ClbXbarRegs)}           > ClbXbarRegs_FILE       
    .OutputXbarRegs(NOLOAD)        : {*(.OutputXbarRegs)}        > OutputXbarRegs_FILE    
    .ClbOutputXbarRegs(NOLOAD)     : {*(.ClbOutputXbarRegs)}     > ClbOutputXbarRegs_FILE 
    .EradGlobalRegs(NOLOAD)        : {*(.EradGlobalRegs)}        > EradGlobalRegs_FILE    
    .EradHWBP1Regs(NOLOAD)         : {*(.EradHWBP1Regs)}         > EradHWBP1Regs_FILE     
    .EradHWBP2Regs(NOLOAD)         : {*(.EradHWBP2Regs)}         > EradHWBP2Regs_FILE     
    .EradHWBP3Regs(NOLOAD)         : {*(.EradHWBP3Regs)}         > EradHWBP3Regs_FILE     
    .EradHWBP4Regs(NOLOAD)         : {*(.EradHWBP4Regs)}         > EradHWBP4Regs_FILE     
    .EradHWBP5Regs(NOLOAD)         : {*(.EradHWBP5Regs)}         > EradHWBP5Regs_FILE     
    .EradHWBP6Regs(NOLOAD)         : {*(.EradHWBP6Regs)}         > EradHWBP6Regs_FILE     
    .EradHWBP7Regs(NOLOAD)         : {*(.EradHWBP7Regs)}         > EradHWBP7Regs_FILE     
    .EradHWBP8Regs(NOLOAD)         : {*(.EradHWBP8Regs)}         > EradHWBP8Regs_FILE     
    .EradCounter1Regs(NOLOAD)      : {*(.EradCounter1Regs)}      > EradCounter1Regs_FILE  
    .EradCounter2Regs(NOLOAD)      : {*(.EradCounter2Regs)}      > EradCounter2Regs_FILE  
    .EradCounter3Regs(NOLOAD)      : {*(.EradCounter3Regs)}      > EradCounter3Regs_FILE  
    .EradCounter4Regs(NOLOAD)      : {*(.EradCounter4Regs)}      > EradCounter4Regs_FILE  
    .EradCRCGlobalRegs(NOLOAD)     : {*(.EradCRCGlobalRegs)}     > EradCRCGlobalRegs_FILE 
    .EradCRC1Regs(NOLOAD)          : {*(.EradCRC1Regs)}          > EradCRC1Regs_FILE      
    .EradCRC2Regs(NOLOAD)          : {*(.EradCRC2Regs)}          > EradCRC2Regs_FILE      
    .EradCRC3Regs(NOLOAD)          : {*(.EradCRC3Regs)}          > EradCRC3Regs_FILE      
    .EradCRC4Regs(NOLOAD)          : {*(.EradCRC4Regs)}          > EradCRC4Regs_FILE      
    .EradCRC5Regs(NOLOAD)          : {*(.EradCRC5Regs)}          > EradCRC5Regs_FILE      
    .EradCRC6Regs(NOLOAD)          : {*(.EradCRC6Regs)}          > EradCRC6Regs_FILE      
    .EradCRC7Regs(NOLOAD)          : {*(.EradCRC7Regs)}          > EradCRC7Regs_FILE      
    .EradCRC8Regs(NOLOAD)          : {*(.EradCRC8Regs)}          > EradCRC8Regs_FILE      
    .Dcc0Regs(NOLOAD)              : {*(.Dcc0Regs)}              > Dcc0Regs_FILE          
    .Dcc1Regs(NOLOAD)              : {*(.Dcc1Regs)}              > Dcc1Regs_FILE          
    .GpioCtrlRegs(NOLOAD)          : {*(.GpioCtrlRegs)}          > GpioCtrlRegs_FILE      
    .GpioDataRegs(NOLOAD)          : {*(.GpioDataRegs)}          > GpioDataRegs_FILE      
    .GpioDataReadRegs(NOLOAD)      : {*(.GpioDataReadRegs)}      > GpioDataReadRegs_FILE  
    .LinaRegs(NOLOAD)              : {*(.LinaRegs)}              > LinaRegs_FILE          
    .LinbRegs(NOLOAD)              : {*(.LinbRegs)}              > LinbRegs_FILE          
    .SciaRegs(NOLOAD)              : {*(.SciaRegs)}              > SciaRegs_FILE          
    .I2caRegs(NOLOAD)              : {*(.I2caRegs)}              > I2caRegs_FILE          
    .I2cbRegs(NOLOAD)              : {*(.I2cbRegs)}              > I2cbRegs_FILE          
    .ClkCfgRegs(NOLOAD)            : {*(.ClkCfgRegs)}            > ClkCfgRegs_FILE        
    .CpuSysRegs(NOLOAD)            : {*(.CpuSysRegs)}            > CpuSysRegs_FILE        
    .DevCfgRegs(NOLOAD)            : {*(.DevCfgRegs)}            > DevCfgRegs_FILE        
    .SysPeriphAcRegs(NOLOAD)       : {*(.SysPeriphAcRegs)}       > SysPeriphAcRegs_FILE   
    .SyncSocRegs(NOLOAD)           : {*(.SyncSocRegs)}           > SyncSocRegs_FILE       
    .DmaClaSrcSelRegs(NOLOAD)      : {*(.DmaClaSrcSelRegs)}      > DmaClaSrcSelRegs_FILE  
    .WdRegs(NOLOAD)                : {*(.WdRegs)}                > WdRegs_FILE            
    .AnalogSubsysRegs(NOLOAD)      : {*(.AnalogSubsysRegs)}      > AnalogSubsysRegs_FILE  
    .DcsmBank0Z1Regs(NOLOAD)       : {*(.DcsmBank0Z1Regs)}       > DcsmBank0Z1Regs_FILE   
    .DcsmBank0Z2Regs(NOLOAD)       : {*(.DcsmBank0Z2Regs)}       > DcsmBank0Z2Regs_FILE   
    .DcsmCommonRegs(NOLOAD)        : {*(.DcsmCommonRegs)}        > DcsmCommonRegs_FILE    
    .DcsmBank0Z1OtpRegs(NOLOAD)    : {*(.DcsmBank0Z1OtpRegs)}    > DcsmBank0Z1OtpRegs_FILE
    .DcsmBank0Z2OtpRegs(NOLOAD)    : {*(.DcsmBank0Z2OtpRegs)}    > DcsmBank0Z2OtpRegs_FILE
    .Flash0CtrlRegs(NOLOAD)        : {*(.Flash0CtrlRegs)}        > Flash0CtrlRegs_FILE    
    .Flash0EccRegs(NOLOAD)         : {*(.Flash0EccRegs)}         > Flash0EccRegs_FILE     
}
