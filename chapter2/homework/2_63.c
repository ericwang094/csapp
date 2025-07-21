//
// Created by yongqi wang on 17/7/2025.
//
// Fill in code for the following C functions. Function srl performs a logical right
// shift using an arithmetic right shift (given by value xsra), followed by other oper-
// ations not including right shifts or division. Function sra performs an arithmetic
// right shift using a logical right shift (given by value xsrl), followed by other
// operations not including right shifts or division. You may use the computation
// 8*sizeof(int) to determine w, the n

#include <assert.h>
#include <stdio.h>

unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int) x >> k;

	int int_size = 8 * sizeof(int);
	int pre_mask = -1 << (int_size - k);
	int mask = ~pre_mask;

	return xsra & mask;
}

int sra(int x, int k)
{
	// Perform shift logically
	int xsrl = (unsigned) x >> k;

	// 1. This will give us if the most significant bit is 1 or not.
	int value = x & 0x80000000;
	// 2. do the same amount of shift, if the most significant bit is 1, then we will have 1111....
	// if the most significant bit is 0, then we will have 0000...
	int shift_same = value >> k;

	// use | to replace the first few bits.
	return shift_same | xsrl;

}

int main(void)
{
	unsigned test_unsigned = 0x12345678;
	int test_int = 0x12345678;

	assert(srl(test_unsigned, 4) == test_unsigned >> 4);

	printf("expect 1: %x\n", test_int >> 4);
	assert(sra(test_int, 4) == test_int >> 4);

	test_unsigned = 0x87654321;
	test_int = 0x87654321;

	assert (srl (test_unsigned, 4) == test_unsigned >> 4);
	printf("expect 2: %x\n", test_int >> 4);
	assert (sra (test_int, 4) == test_int >> 4);

	return 0;

}