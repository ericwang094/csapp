/*
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Labby
editing the collection of functions in this source file.

INTEGER CODING RULES:

	Replace the"return" statement in each function withone
  or more lines of C code that implements the function. Your code
  must conform to the following style:

int Funct(arg1, arg2, ...)
{
	/* brief description of how your implementation works */
	int var1 = Expr1;
	...
	int varM = ExprM;

	varJ = ExprJ;
	...
	varN = ExprN;
	return ExprR;
}

Each"Expr" is an expression using ONLY the following:
  1. Integer constants0 through255 (0xFF), inclusive. You are
      not allowed to use big constants such as0xffffffff.
  2. Function arguments and local variables(no global variables).
  3. Unary integer operations! ~
  4. Binary integer operations& ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
Each"Expr" may consist of multiple operators. You are not restrictedto
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such asif, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as&&, ||, -, or?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies thatyou
cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shiftingif the shiftamount
     is less than0 or greater than31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x)
{
	/* exploit ability of shifts to compute powers of 2 */
	return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x)
{
	/* exploit ability of shifts to compute powers of 2 */
	int result = (1 << x);
	result += 4;
	return result;
}

FLOATING POINT CODINGRULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use loopingand
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
                                                                      logical, or comparison operations on int or
unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means thatyou
cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc(data lab checker) compiler(described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations(integer, logical,
                                                      or comparison) that you are allowed to usefor your implementation
     of the function.  The max operator count is checked by dlc.
Note that assignment('=') is not counted; you may use as manyof
     these as you want without penalty.
  3. Use the btest test harness to check your functionsfor correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of opsfor each function is given inthe
header commentfor each function. If there are anyinconsistencies
between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    // from my own discovery, I think the answer is 
    // ~(~x & ~y) & ~(x & y)
    // TODO: Understand why
	return ~(~x & ~y) & ~(x & y);
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    // 0xff =     1111,1111
    // oxff + 1 = 0001,1111,1111
    //  << 23 to the tmin which is 0x80000000
	return (0xff + 1) << 23;
}

//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    // This problem is divided into two parts
    // The first part is to process the normal value
    // The second part is to process the edge case FFFFFFFF 
    // The idea is that the x is the Tmax if and only if both first part and 
    // second part are true
    //
    // For the frist part
    // if x is Tmax, then its value is 
    // a: 0x7FFFFFFF
    // a: 0b0111,1111,.....
    // When we add one, it become
    // b: 0b1000,0000,.....
    // when we a ^ b
    // c:  0b1111,1111,1111
    // ~c: 0b0000,0000,0000
    // ~c is 0 only when x is Tmax.
    //
    //
    // Part two is to address 0xFFFFFFFF
    // if not to deal with 0xFFFFFFFF, and feed this to part one, it will give us
    // true value, which is wrong.
    //
    // for all other value (include Tmax) x + 1 is not 0
    // but for 0xFFFFFFFF + 1 = 0
    // so we want to make sure x + 1 is not 0
    // !(0xFFFFFFFF + 1) = 1
    // d: !(Tmax + 1) = !(0x8000000) = 0 which is what we want
    //
    //Now combine c and d, we need them both 0, so their negate !(c + d) is 1
    int part_one = ~((x + 1) ^ x);
    int part_two = !(x + 1);
    int res = !(part_one + part_two);

    return res;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    // Manually construct 0xAAAAAAAA which has 1 for all odd bit
    
    int constant = (0xAA << 8) | 0xAA;
    constant = (constant << 8) | 0xAA;
    constant = (constant << 8) | 0xAA;

    return !((constant & x ) ^ constant);
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}

//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
	int lower_bound = x + ~0x30 + 1;
	int upper_bound = 0x39 + ~x + 1;

	int is_within_lower_bound = !(lower_bound >> 31);
	int is_within_upper_bound = !(upper_bound >> 31);

	return is_within_lower_bound & is_within_upper_bound;
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
	int is_true = !!(x ^ 0);

	int bench_mark = ~is_true + 1;
	return (bench_mark & y) | (~bench_mark & z);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
	int diff_sign = !!((x >> 31) ^ (y >> 31)); // check if sign same or diff, if diff, diff_sign is 1

	// if x is neg (x >> 31 = 1) and diff_sign is (1), it means y is pos, so overall answer is x < y = 1
    // if diff sign (1) and x is pos ( x >> 31 = 0), it means y is neg, so overall answer is 0 as x > y
	int diff_sign_x_is_neg = diff_sign & (x >> 31);

	// if not diff (0), then use following to calculate result
	int same_sign = !diff_sign & !((y + (~x + 1)) >> 31);

	return diff_sign_x_is_neg | same_sign;
}

//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
	return ((x >> 31) | (~x + 1) >> 31) + 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
	return 0;
}

//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
	// (-1)^s * M * 2^E
	// s - 1 bit
	// e - 8 bit
	// M - 23 bit
	// 首先排除无穷小、0、无穷大和非数值NaN，
	// 此时浮点数指数部分（真正指数+bias）分别存储的的为0，0，,255，255。
	// 这些情况，无穷大和NaN都只需要返回参数
	// 无穷小和0只需要将原数乘二再加上符号位就行了（并不会越界）。
	// 剩下的情况，如果指数+1之后为指数为255则返回原符号无穷大，
	// 否则返回指数+1之后的原符号数。

	int sign = uf & (0x1 << 31);
	int exp = (0x7F800000 & uf) >> 23;
	if (exp == 0)
	{
		return uf << 1 | sign;
	}
	if (exp == 255)
	{
		return uf;
	}
	exp++;
	if (exp == 255)
	{
		return 0x7F800000 | sign;
	}

	return (exp << 23) | (uf & 0x807FFFFF);
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
	// the question is asking to get the int part of the float
	int sign = (1 << 31) & uf;
	unsigned exp = (0x7F800000 & uf) >> 23;

	int E = exp - 127;

	if (E < 0)
	{
		return 0;
	}

	if (E >= 31)
	{
		return 0x80000000u;
	}

	unsigned frac = uf & 0x7FFFFF;
	frac = frac | 1 << 23;
	if (E < 23)
	{
		frac = frac >> (23 - E);
	} else
	{
		frac = frac << (E - 23);
	}

	if (sign)
	{
		return -frac;
	} else
	{
		return frac;
	}
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
	return 2;
}
