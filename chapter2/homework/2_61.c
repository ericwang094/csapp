//
// Created by yongqi wang on 16/7/2025.
//

// Write C expressions that evaluate to 1 when the following conditions are true and
// to 0 when they are false. Assume x is of type int.

#include <assert.h>
#include <stdio.h>

int a_any_bit_of_x_equals_1(int x)
{
	return !~x;
}

int b(int x)
{
	// Any bit of x equals 0.
	return !x;
}

int c(int x)
{
	// Any bit in the least significant byte of x equals 1.
	return !~(x | ~0xFF);
}

int d(int x)
{
	return !((x >> 24) & 0xFF);
}

int main(void)
{
	assert(a_any_bit_of_x_equals_1(0) == 0);
	assert(a_any_bit_of_x_equals_1(0x1000) == 0);
	assert(a_any_bit_of_x_equals_1(0xFFFFFFFF) == 1);

	assert(b(0) == 1);
	assert(b(1) == 0);

	assert(c(0xFF) == 1);
	assert(c(0x01) == 0);

	assert(d(0x00ABCDEF) == 1);
	assert(d(0xAAABCDEF) == 0);
}