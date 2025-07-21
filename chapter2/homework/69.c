//
// Created by yongqi wang on 18/7/2025.
//

#include <assert.h>
#include <stdio.h>
/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
* n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n) {
	int left_part = x << n;
	// This is to take of when n == 0
	int right_part = x >> (32 - n - 1) >> 1;

	return left_part | right_part;
}

int main() {
	assert(rotate_left(0x12345678, 4) == 0x23456781);
	assert(rotate_left(0x12345678, 20) == 0x67812345);
	return 0;
}