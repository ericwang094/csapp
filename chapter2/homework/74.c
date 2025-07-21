//
// Created by yongqi wang on 20/7/2025.
//

#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
	int sub = x - y;
	int pos_flag = x >= 0 && y < 0 && sub < 0;
	int neg_flag = x < 0 && y >= 0 && sub > 0;

	return !pos_flag && !neg_flag;
}

int main() {
	assert(!tsub_ok(INT_MIN, 1));
	assert(!tsub_ok(INT_MAX, -1));
	assert(tsub_ok(0, 0));
	assert(!tsub_ok(INT_MIN, INT_MAX));
	assert(!tsub_ok(INT_MAX, INT_MIN));
	assert(tsub_ok(10, 8));
	return 0;
}