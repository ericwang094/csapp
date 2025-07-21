//
// Created by yongqi wang on 17/7/2025.
//

#include <assert.h>
/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32 */
int any_odd_one(unsigned x)
{
	return !((0xAAAAAAAA & x ) ^ 0xAAAAAAAA);
}

int main(int argc, char* argv[]) {
	// This solution is not right
	assert(any_odd_one(0x2));
	assert(!any_odd_one(0x4));
	return 0;
}