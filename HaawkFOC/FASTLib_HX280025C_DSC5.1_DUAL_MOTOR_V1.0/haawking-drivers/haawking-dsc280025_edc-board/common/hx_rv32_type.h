
#ifndef __HX_RV32_TYPE_H
#define __HX_RV32_TYPE_H



#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>




typedef 	unsigned char  Uint8;
typedef 	unsigned short int  Uint16;
typedef 	unsigned int  Uint32;
typedef		unsigned long long int	Uint64;

typedef 	signed char  Int8;
typedef 	signed short int Int16;
typedef 	signed int Int32;
typedef		signed long long int Int64;



typedef 	unsigned char  uint8;
typedef 	unsigned short int  uint16;
typedef 	unsigned int  uint32;
typedef		unsigned long long int	uint64;


typedef 	signed char  int8;
typedef 	signed short int int16;
typedef 	signed int int32;
typedef		signed long long int int64;


typedef     uint8  u8;
typedef     uint16  u16;
typedef     uint32  u32;
typedef     uint64  u64;


typedef     Int8  s8;
typedef     Int16  s16;
typedef     Int32  s32;
typedef     Int64  s64;


typedef float              float32;
typedef double             float64;



typedef  _Bool   bool_t;




#ifndef  __HAAWKING_COMPILER_VERSION__

  #error The library not support current compiler

#endif



typedef    __attribute__((interrupt("machine")))  void(*PINT)(void);





#endif


