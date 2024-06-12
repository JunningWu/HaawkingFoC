/*
 * hx_intrinsics.h
 *
 * note : When using functions list below ,
 * please include "hx_intrinsics.h" header file.
 * 
 */

 #if !(__HAAWKING_COMPILER_VERSION__ >= 10100)   // <10100
 extern float __fsat(float val, float max, float min); 
 #endif
 #if !(__HAAWKING_COMPILER_VERSION__ >= 10101)   // <10101
 extern short __flip16(short src);
 #endif
 #if !(__HAAWKING_COMPILER_VERSION__ >= 10100)   // <10100
 extern long __flip32(long src);
 #endif
 extern long long int __flip64(long long int src); 
 extern long __lmax(long dst, long src);
 extern long long __llmax(long long dst, long long src); 
 extern long __lmin(long dst, long src);
 extern long long __llmin(long long dst, long long src);