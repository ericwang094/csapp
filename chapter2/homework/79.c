//
// Created by yongqi wang on 22/7/2025.
//

#include <assert.h>
// Write code for a function mul3div4 that, for integer argument x, computes 3 ∗
// x/4 but follows the bit-level integer coding rules (page 164). Your code should
// replicate the fact that the computation 3*x can cause overflow.
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

int mul3div4(int x)
{
	int multiply_res = (x << 1) + x;
	return divide_power2(multiply_res, 2);
}

int main(int argc, char* argv[]) {
	int x = 0x87654321;
	assert(mul3div4(x) == x * 3 / 4);
	return 0;
}