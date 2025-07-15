//
// Created by yongqi wang on 15/7/2025.
//

// Write a C expression that will yield a word consisting of the least significant byte of
// x and the remaining bytes of y. For operands x =0x89ABCDEF and y=0x76543210,
// this would give 0x765432EF.
#include <assert.h>
int combine(int x, int y)
{
	int least_significant_byte_x = 0xFF & x;
	int remaining_y = ~0xFF & y;

	return least_significant_byte_x | remaining_y;

}

int main(void)
{
	assert(combine(0x89ABCDEF, 0x76543210) == 0x765432EF);

	return 0;
}