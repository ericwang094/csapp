#include <assert.h>
#include <stdio.h>
//
// Created by yongqi wang on 17/7/2025.
//
// Write a function int_shifts_are_arithmetic() that yields 1 when run on a
// machine that uses arithmetic right shifts for data type int and yields 0 otherwise.
// Your code should work on a machine with any word size. Test your code on several
// machines.
int int_shifts_are_arithmetic()
{
	// This will work as well
	// return !~((10 | (int) 0x80000000) >> 31);
	int num = -1;
	return !(num ^ (num >> 1));
}

int main(void)
{
	int signed_test = -1;
	printf("%x\n", signed_test >> 1);

	// ######### Important ##########
	// In C, integer literals like 0xF0000000 are typically treated as unsigned int unless explicitly cast to a signed type.
	// ##############################

	printf("%x\n", 0x80000000 >> 1); // 0x40000000
	printf("%x\n", (int) 0x80000000 >> 1); // C0000000

	assert(int_shifts_are_arithmetic() == 1);
	return 1;
}