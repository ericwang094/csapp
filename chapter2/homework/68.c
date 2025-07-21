//
// Created by yongqi wang on 18/7/2025.
//

#include <assert.h>
#include <stdio.h>
/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n)
{
	int x = 0x1 << (n - 1);
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	return x;
}


int main(int argc, char* argv[]) {
	assert(lower_one_mask(6) == 0x3F);
	assert(lower_one_mask(17) == 0x1FFFF);
	assert(lower_one_mask(32) == 0xFFFFFFFF);
	return 0;
}