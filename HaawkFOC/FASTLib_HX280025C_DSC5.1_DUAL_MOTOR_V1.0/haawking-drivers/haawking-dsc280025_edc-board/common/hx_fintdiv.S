.section .text, "a", @progbits
/////////////////////////////// 1 /////////////////////////////////
	.global __traditional_div_i16byi16
__traditional_div_i16byi16:
// a0: num  a1:den

	tdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_i16byi16, .-__traditional_div_i16byi16

/////////////////////////////// 2 /////////////////////////////////
	.global __euclidean_div_i16byi16
__euclidean_div_i16byi16:
// a0: num  a1:den

	ediv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __euclidean_div_i16byi16, .-__euclidean_div_i16byi16

/////////////////////////////// 3 /////////////////////////////////
	.global __modulo_div_i16byi16
__modulo_div_i16byi16:
// a0: num  a1:den

	mdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __modulo_div_i16byi16, .-__modulo_div_i16byi16

/////////////////////////////// 4 /////////////////////////////////
	.global __traditional_div_u16byu16
__traditional_div_u16byu16:
// a0: num  a1:den

	tdiv32u d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_u16byu16, .-__traditional_div_u16byu16

/////////////////////////////// 5 /////////////////////////////////
	.global __traditional_div_i32byi32
__traditional_div_i32byi32:
// a0: num  a1:den

	tdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_i32byi32, .-__traditional_div_i32byi32

/////////////////////////////// 6 /////////////////////////////////
	.global __euclidean_div_i32byi32
__euclidean_div_i32byi32:
// a0: num  a1:den

	ediv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __euclidean_div_i32byi32, .-__euclidean_div_i32byi32

/////////////////////////////// 7 /////////////////////////////////
	.global __modulo_div_i32byi32
__modulo_div_i32byi32:
// a0: num  a1:den

	mdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __modulo_div_i32byi32, .-__modulo_div_i32byi32

/////////////////////////////// 8 /////////////////////////////////
	.global __traditional_div_i32byu32
__traditional_div_i32byu32:
// a0: num  a1:den

	tdiv32su d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_i32byu32, .-__traditional_div_i32byu32

/////////////////////////////// 9 /////////////////////////////////
	.global __euclidean_div_i32byu32
__euclidean_div_i32byu32:
// a0: num  a1:den

	ediv32su d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __euclidean_div_i32byu32, .-__euclidean_div_i32byu32

/////////////////////////////// 10 /////////////////////////////////
	.global __modulo_div_i32byu32
__modulo_div_i32byu32:
// a0: num  a1:den

	mdiv32su d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __modulo_div_i32byu32, .-__modulo_div_i32byu32

/////////////////////////////// 11 /////////////////////////////////
	.global __traditional_div_u32byu32
__traditional_div_u32byu32:
// a0: num  a1:den

	tdiv32u d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_u32byu32, .-__traditional_div_u32byu32

/////////////////////////////// 12 /////////////////////////////////
	.global __traditional_div_i32byi16
__traditional_div_i32byi16:
// a0: num  a1:den

	tdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_i32byi16, .-__traditional_div_i32byi16

/////////////////////////////// 13 /////////////////////////////////
	.global __euclidean_div_i32byi16
__euclidean_div_i32byi16:
// a0: num  a1:den

	ediv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __euclidean_div_i32byi16, .-__euclidean_div_i32byi16

/////////////////////////////// 14 /////////////////////////////////
	.global __modulo_div_i32byi16
__modulo_div_i32byi16:
// a0: num  a1:den

	mdiv32 d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __modulo_div_i32byi16, .-__modulo_div_i32byi16

/////////////////////////////// 15 /////////////////////////////////
	.global __traditional_div_u32byu16
__traditional_div_u32byu16:
// a0: num  a1:den

	tdiv32u d5, a1  //a0, a1

// a0:quot  a1:rem

	ret
.size __traditional_div_u32byu16, .-__traditional_div_u32byu16

/////////////////////////////// 16 /////////////////////////////////
	.global __traditional_div_i64byi64
__traditional_div_i64byi64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	tdiv64 q2, d6  // s0, a2   //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)     //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __traditional_div_i64byi64, .-__traditional_div_i64byi64

/////////////////////////////// 17 /////////////////////////////////
	.global __euclidean_div_i64byi64
__euclidean_div_i64byi64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	ediv64 q2, d6  //s0, a2   //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack ///////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)     //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __euclidean_div_i64byi64, .-__euclidean_div_i64byi64

/////////////////////////////// 18 /////////////////////////////////
	.global __modulo_div_i64byi64
__modulo_div_i64byi64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	mdiv64 q2, d6  //s0, a2   //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack ///////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)      //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __modulo_div_i64byi64, .-__modulo_div_i64byi64

/////////////////////////////// 19 /////////////////////////////////
	.global __traditional_div_i64byu64
__traditional_div_i64byu64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	tdiv64su q2, d6  //s0, a2   //   //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __traditional_div_i64byu64, .-__traditional_div_i64byu64

/////////////////////////////// 20 /////////////////////////////////
	.global __euclidean_div_i64byu64
__euclidean_div_i64byu64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	ediv64su q2, d6  //s0, a2      //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __euclidean_div_i64byu64, .-__euclidean_div_i64byu64

/////////////////////////////// 21 /////////////////////////////////
	.global __modulo_div_i64byu64
__modulo_div_i64byu64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	mdiv64su q2, d6  //s0, a2      //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __modulo_div_i64byu64, .-__modulo_div_i64byu64

/////////////////////////////// 22 /////////////////////////////////
	.global __traditional_div_u64byu64
__traditional_div_u64byu64:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3/a4   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	mv a3, a4    // input a4: Den  High32bit

	tdiv64u q2, d6  //s0, a2   //output rem : H s1 | s0 L     // quot: H a1 | a0 L

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52

	ret
.size __traditional_div_u64byu64, .-__traditional_div_u64byu64

/////////////////////////////// 23 /////////////////////////////////
	.global __traditional_div_i64byi32
__traditional_div_i64byi32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f  // symbol extension

	tdiv64 q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __traditional_div_i64byi32, .-__traditional_div_i64byi32

/////////////////////////////// 24 /////////////////////////////////
	.global __euclidean_div_i64byi32
__euclidean_div_i64byi32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	ediv64 q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __euclidean_div_i64byi32, .-__euclidean_div_i64byi32

/////////////////////////////// 25 /////////////////////////////////
	.global __modulo_div_i64byi32
__modulo_div_i64byi32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	mdiv64 q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __modulo_div_i64byi32, .-__modulo_div_i64byi32

/////////////////////////////// 26 /////////////////////////////////
	.global __traditional_div_i64byu32
__traditional_div_i64byu32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	tdiv64su q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	//sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32    // rem: 64bit
	sdp d5, 0(a2)      //a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __traditional_div_i64byu32, .-__traditional_div_i64byu32

/////////////////////////////// 27 /////////////////////////////////
	.global __euclidean_div_i64byu32
__euclidean_div_i64byu32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	ediv64su q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32    // rem: 64bit
	//sdp a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __euclidean_div_i64byu32, .-__euclidean_div_i64byu32

/////////////////////////////// 28 /////////////////////////////////
	.global __modulo_div_i64byu32
__modulo_div_i64byu32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	mdiv64su q2, d6  //s0, a2    //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     ////sw a0, 8(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32    // rem: 64bit
	//sdp a0, 0(a2)

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __modulo_div_i64byu32, .-__modulo_div_i64byu32

/////////////////////////////// 29 /////////////////////////////////
	.global __traditional_div_u64byu32
__traditional_div_u64byu32:
	addi sp, sp, -52
	sw ra, 48(sp)
	sw s0, 44(sp)
	sw s1, 40(sp)
	sw a0, 36(sp)     //a0 adress: return value store location

///////////  input data in default register : a1/a2/a3   /////////////
	mv s0, a1     // input a1:  Num Low 32bit
	mv s1, a2     // input a2: Num High32bit
	mv a2, a3    // input a3: Den  Low 32bit
	//mv a3, a4    // input a4: Den  High32bit
	srai a3, a3, 0x1f

	tdiv64u q2, d6  //s0, a2   //

///////////  put the result into the stack  ////////////////////
	lw a2, 36(sp)    //load a0 address
	//sw s0, 0(a2)     //s0:  quot Low32
    //sw s1, 4(a2)      //s1:  quot High32
    sdp d4, 8(a2)       //s0, 8(a2)
	sw a0, 0(a2)     //a0: rem  Low32
	//sw a1, 12(a2)    //a1:  rem  High32

	lw s1, 40(sp)
	lw s0, 44(sp)
	lw ra, 48(sp)
	add sp, sp, 52
	ret
.size __traditional_div_u64byu32, .-__traditional_div_u64byu32