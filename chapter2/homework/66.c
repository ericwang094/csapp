//
// Created by yongqi wang on 17/7/2025.
//

#include <assert.h>
/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
* If x = 0, then return 0.
*/
int leftmost_one(unsigned x)
{
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	return x ^ x >> 1;
}

int main(int argc, char* argv[]) {
	assert(leftmost_one(0xFF00) == 0x8000);
	assert(leftmost_one(0x6000) == 0x4000);
	assert(leftmost_one(0x0) == 0x0);
	assert(leftmost_one(0x80000000) == 0x80000000);
	return 0;
}