/*
 * hx_fintdiv.h
 *
 * note : When using functions list below ,
 * please include "hx_fintdiv.h" header file.
 * 
 */

#include <hx_rv32_type.h>

//typedef struct { long quot, rem; }                                  ldiv_t;
//typedef struct {long long quot, rem;} lldiv_t;
typedef struct { long long quot; long rem; }                        __llldiv_t;
typedef struct { unsigned long quot; unsigned long rem; }           __uldiv_t;
typedef struct { unsigned long long quot; unsigned long long rem; } __ulldiv_t;
typedef struct { unsigned long long quot; unsigned long rem; }      __ullldiv_t;

/*************************************************************************************/
/*  NOTE: The result of division between two unsigned values does not vary       */
/*            between traditional, euclidean, and modulo versions. Thus, only          */
/*            traditional versions are provided for unsigned inputs                          */
/*************************************************************************************/

/* 16-bit by 16-bit */
ldiv_t __traditional_div_i16byi16(int16 numerator, int16 denominator);
ldiv_t __euclidean_div_i16byi16(int16 numerator, int16 denominator);
ldiv_t __modulo_div_i16byi16(int16 numerator, int16 denominator);

__uldiv_t __traditional_div_u16byu16(uint16 numerator, uint16 denominator); //

/* 32-bit by 32-bit */
ldiv_t __traditional_div_i32byi32(long numerator, long denominator);
ldiv_t __euclidean_div_i32byi32(long numerator, long denominator);
ldiv_t __modulo_div_i32byi32(long numerator, long denominator);

ldiv_t __traditional_div_i32byu32(long numerator, unsigned long denominator);
ldiv_t __euclidean_div_i32byu32(long numerator, unsigned long denominator);
ldiv_t __modulo_div_i32byu32(long numerator, unsigned long denominator);

__uldiv_t __traditional_div_u32byu32(unsigned long numerator, unsigned long denominator);

/* 32-bit by 16-bit */
ldiv_t __traditional_div_i32byi16(long numerator, int16 denominator);
ldiv_t __euclidean_div_i32byi16(long numerator, int16 denominator);
ldiv_t __modulo_div_i32byi16(long numerator, int16 denominator);

__uldiv_t __traditional_div_u32byu16(unsigned long numerator, uint16 denominator);

/* 64-bit by 64-bit */
lldiv_t __traditional_div_i64byi64(long long numerator, long long denominator);
lldiv_t __euclidean_div_i64byi64(long long numerator, long long denominator);
lldiv_t __modulo_div_i64byi64(long long numerator, long long denominator);

lldiv_t __traditional_div_i64byu64(long long numerator, unsigned long long denominator);
lldiv_t __euclidean_div_i64byu64(long long numerator, unsigned long long denominator);
lldiv_t __modulo_div_i64byu64(long long numerator, unsigned long long denominator);

__ulldiv_t __traditional_div_u64byu64(unsigned long long numerator,
											  unsigned long long denominator);

/* 64-bit by 32-bit */
__llldiv_t __traditional_div_i64byi32(long long numerator, long denominator);

__llldiv_t __euclidean_div_i64byi32(long long numerator, long denominator);

__llldiv_t __modulo_div_i64byi32(long long numerator, long denominator);

lldiv_t __traditional_div_i64byu32(long long numerator, unsigned long denominator);

__llldiv_t __euclidean_div_i64byu32(long long numerator, unsigned long denominator);

__llldiv_t __modulo_div_i64byu32(long long numerator, unsigned long denominator);

__ullldiv_t __traditional_div_u64byu32(unsigned long long numerator, unsigned long denominator);
