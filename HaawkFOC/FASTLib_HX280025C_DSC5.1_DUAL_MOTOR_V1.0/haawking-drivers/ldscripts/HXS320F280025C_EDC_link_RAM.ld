/*
//###########################################################################################################
//
//FILE:    DSC280025_EDC_link_RAM.ld
//
//
//TITLE: RAM Project linker file
//
//       Keep in mind that LS4~LS7 is protected by 
//       the dual code security module
//
//###########################################################################################################
//$Release Data:February  1 ,2024$
//
//###########################################################################################################
*/

OUTPUT_ARCH( "riscv" )
ENTRY(_start)
INCLUDE "Peripheral.ld" 
INCLUDE "BootROM.ld" 

/*----------------------------------------------------------------------*/
/* Memories                                                             */
/*----------------------------------------------------------------------*/
MEMORY
{
  /*PAGE 0:*/
    BEGIN                           (rwx)  : ORIGIN = 0x0       , LENGTH = 0x10                                   
    BOOT_RSVD                       (rwx)  : ORIGIN = 0x10      , LENGTH = 0x1F0
    PRAMM0                          (rwx)  : ORIGIN = 0x200     , LENGTH = 0x600        
    PRAMM1                          (rwx)  : ORIGIN = 0x800     , LENGTH = 0x800             
    PRAMLS4567                      (rwx)  : ORIGIN = 0x10000   , LENGTH = 0x8000 
    RAMGS0                          (rwx)  : ORIGIN = 0x18000   , LENGTH = 0x2000  
    FLASH                           (rwx)  : ORIGIN = 0x600000  , LENGTH = 0x40000
    USER_OTP_FILE                   (rw)   : ORIGIN = 0x7A0000  , LENGTH = 0x800       
  
    IER_REGISTER_FILE               (rw)   : ORIGIN = 0x100C10  , LENGTH = 0x04
    IFR_REGISTER_FILE               (rw)   : ORIGIN = 0x100D10  , LENGTH = 0x04        
}

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/

SECTIONS
{
    . = 0x7A0000;
    .USER_OTP_TABLE       : {KEEP(*(.User_Otp_Table))}  >  USER_OTP_FILE
    
    . = 0x800;
    .M1 :
    {
    __global_sp$ = . + 0x800;
    } > PRAMM1
	
    /* text: test code section */
      . = 0x0;
    .codestart : { *(codestart) } > BEGIN
    . = 0x00010000;
    .text.init  : { *(.text.init)  }  > PRAMLS4567
    .text ALIGN(0x80) : { *(.text) *(.IQmath.*) *(.text*)  *(.rodata .rodata.*)  *(ramfuncs) } > PRAMLS4567
    
     /* data segment */
    .sdata ALIGN(0x80) :{
      __data_start = .;   
      __global_pointer$ = . + 0x800;	
      *(.data)  *(.data.*)
      *(.srodata.cst16) *(.srodata.cst8) *(.srodata.cst4) *(.srodata.cst2) *(.srodata*)
      *(.sdata .sdata.* .gnu.linkonce.s.*)
      __data_end = .; 
    }  >PRAMLS4567
    
     /* bss segment */
    .sbss ALIGN(0x80) : {
     __bss_start = .;
      *(.sbss .sbss.* .gnu.linkonce.sb.*)
      *(.scommon)
    }  > PRAMLS4567
    .bss  ALIGN(0x8) : { *(.bss)  *(.bss.*)   *(COMMON)  __bss_end = ALIGN(0x8); } > PRAMLS4567
    
    . = 0x18000;
    .ramgs0  :{*(ramgs0)}  > RAMGS0
    
    . = 0x100C10;
    .IER_REGISTER(NOLOAD) : {*(.ier_register)} > IER_REGISTER_FILE
    . = 0x100D10;
    .IFR_REGISTER(NOLOAD) : {*(.ifr_register)} > IFR_REGISTER_FILE
    
    /* End of uninitalized data segement */
    _end = .;
}

