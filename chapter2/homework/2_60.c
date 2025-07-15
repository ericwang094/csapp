//
// Created by yongqi wang on 15/7/2025.
//
// Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8− 1
// (most significant). Write code for the following C function, which will return an
// unsigned value in which byte i of argument x has been replaced by byte b:
// unsigned replace_byte (unsigned x, int i, unsigned char b);
// Here are some examples showing how the function should work:
// replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
// replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB

#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	// one byte is 8 bit. << 3 is *8
	unsigned shift_byte = i << 3;
	unsigned mask = 0xFF << shift_byte;

	return (x & ~mask) | (b << shift_byte);
}

int main(void)
{
	assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
	assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);

	return 0;
}