#include <assert.h>
//
// Created by yongqi wang on 17/7/2025.
//
/* Return 1 when x contains an odd number of 1s; 0 otherwise.
Assume w=32 */
int odd_ones(unsigned x)
{
	// This one is a bit tricky, and I didn't think out myself, it is a bit challenge even looking at solution
	// to understand https://stackoverflow.com/a/9133404/4840978
	// The idea is that for number a and b, the parity of 1 bit of (a + b) is the same as (a ^ b)
	// we can use this attribute to continuous cut the number in half and XOR itself.
	// For example, for a number 0x11111111
	// We treat this number as two number 1111 and 1111
	// There are 8 one's in the original number which is even number
	// if we do (0x1111 ^ 0x1111) we have 0000 which has 0 one, and it is also old.
	// Now we get the parity of the last 16 bit, we continue doing this for 8, 4, 2, 1
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	x &= 0x1;

	return x;
}


int main(int argc, char* argv[]) {
	assert(odd_ones(0x10101011));
	assert(!odd_ones(0x01010101));
	return 0;
}