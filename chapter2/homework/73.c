//
// Created by yongqi wang on 18/7/2025.
//

// Instead of overflowing the way normal two’s-complement addition does, sat-
// urating addition returns TMax when there would be positive overflow, and TMin
// when there would be negative overflow. Saturating arithmetic is commonly used
// in programs that perform digital signal processing.

#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
	int sum = x + y;
	int mask = INT_MIN;

	// If this is pos overflow, x > 0, y > 0 and sum < 0;
	int pos_overflow = !(x & mask) && !(y & mask) && (sum & mask);
	// If this is neg overflow, x < 0, y < 0 and sum > 0;
	int neg_overflow = (x & mask) && (y & mask) && !(sum & mask);

	(pos_overflow && (sum = INT_MAX)) || (neg_overflow && (sum = INT_MIN));

	return sum;
}

int main(int argc, char* argv[]) {
	assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
	assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
	assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
	return 0;
}