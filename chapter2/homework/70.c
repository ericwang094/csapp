//
// Created by yongqi wang on 18/7/2025.
//

#include <assert.h>

int fits_bits(int x, int n)
{
	/*
	* Return 1 when x can be represented as an n-bit, 2’s-complement
	* number; 0 otherwise
	* Assume 1 <= n <= w
	 * 1 <= n <= w
	 *
	 * assume w = 8, n = 3
	 * if x > 0
	 *   0b00000010 is ok, 0b00001010 is not, and 0b00000110 is not yet (thanks itardc@163.com)
	 * if x < 0
	 *   0b11111100 is ok, 0b10111100 is not, and 0b11111000 is not yet
	 *
	 * the point is
	 *   x << (w-n) >> (w-n) must be equal to x itself.
	 *
	 *
	 * From GPT, this is further explanation.
	 * The range of numbers that can be represented using n bits is from -2^(n-1) to 2^(n-1) - 1.
	 * For example, with 4 bits, the range is from -8 to 7.
	 */
	int w = sizeof(int) << 3;
	return !(x ^ x << (w - n) >> (w - n));
}

int main(int argc, char* argv[]) {
	assert(!fits_bits(0xFF, 8));
	assert(!fits_bits(~0xFF, 8));

	assert(fits_bits(0b0010, 3));
	assert(!fits_bits(0b1010, 3));
	assert(!fits_bits(0b0110, 3));

	assert(fits_bits(~0b11, 3));
	assert(!fits_bits(~0b01000011, 3));
	assert(!fits_bits(~0b111, 3));
	return 0;
}
