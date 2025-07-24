#include <assert.h>
//
// Created by yongqi wang on 22/7/2025.
//
/* Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k)
{
	// here is the logic of two's compliment division by a power of 2
	// 1. x < 0
	//    x = x + 2^k - 1  this 2^k - 1 is bias
	//	  x >> k
	// 2. x >= 0
	//    x >> k

	int word_size = sizeof(int) << 3;
	int msb = x >> (word_size - 1);
	int bias = (1 << k) - 1;

	bias = bias & msb;

	return (x + bias) >> k;

}

int main(int argc, char* argv[]) {
	int x = 0x80000007;
	assert(divide_power2(x, 1) == x / 2);
	assert(divide_power2(x, 2) == x / 4);
	return 0;
}
