/*
 * hx_intrinsics.c
 *
 * note : When using functions list below ,
 * please include "hx_intrinsics.h" header file.
 * 
 */

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>


///////////////  FPU Intrinsics //////////////
#if !(__HAAWKING_COMPILER_VERSION__ >= 10100)  // <10100
float __attribute__((weak))  __fsat(float val, float max, float min){
    float temp,result;
    asm volatile
    (
    "fmax.s  %[z], %[x], %[y]\n\t"
    : [z] "=f" (temp)
	: [x] "f" (val),  [y] "f" (min)
    );
	asm volatile
    (
    "fmin.s  %[z], %[x], %[y]\n\t"
    : [z] "=f" (result)
	: [x] "f" (temp), [y] "f" (max)
    );
    return  result;
}
#endif

///////////////  Compiler Intrinsics //////////////
#if !(__HAAWKING_COMPILER_VERSION__ >= 10101)  // <10101
short __attribute__((weak))  __flip16(short src){
	long temp;
	short result;
    asm volatile
    (
    "rbit  %[y], %[x]\n\t"
    : [y] "=r" (temp)
	: [x] "r" (src)
    );
    asm volatile
    (
    "srli  %[z], %[x], %[y]\n\t"
    : [z] "=r" (result)
    : [x] "r" (temp), [y] "I" (16)
    );
    return  result;
}
#endif

#if !(__HAAWKING_COMPILER_VERSION__ >= 10100)  // <10100
long __attribute__((weak))  __flip32(long src){
	long result;
    asm volatile
    (
    "rbit  %[y], %[x]\n\t"
    : [y] "=r" (result)
	: [x] "r" (src)
    );
    return  result;
}
#endif

long long int __attribute__((weak))  __flip64(long long int src){
	unsigned long srch, srcl,resulth,resultl;
	unsigned long long int result;
	srch=(unsigned long)(src>>32);
	srcl=(unsigned long)(src&0xffffffff);
    asm volatile
    (
    "rbit  %[y], %[x]\n\t"
    : [y] "=r" (resulth)
	: [x] "r" (srcl)
    );
    asm volatile
    (
    "rbit  %[y], %[x]\n\t"
    : [y] "=r" (resultl)
	: [x] "r" (srch)
    );
    result=(unsigned long long int)resulth<<32 | resultl;  //stitch
    return result;
}

long __attribute__((weak))  __lmax(long dst, long src){
	long result;
    asm volatile
    (
    "max  %[z], %[x], %[y]\n\t"
    : [z] "=r" (result)
    : [x] "r" (dst), [y] "r" (src)
    );
    return result;
}

long long __llmax(long long dst, long long src){
	if(dst<src)
		dst=src;
	return dst;
}

long __attribute__((weak))  __lmin(long dst, long src){
	long result;
    asm volatile
    (
    "min  %[z], %[x], %[y]\n\t"
    : [z] "=r" (result)
    : [x] "r" (dst), [y] "r" (src)
    );
    return result;
}

long long __llmin(long long dst, long long src){
	if(dst>src)
		dst=src;
	return dst;
}
