//
// Created by yongqi wang on 22/7/2025.
//

// Suppose we are given the task of generating code to multiply integer variable x
// by various different constant factors K. To be efficient, we want to use only the
// operations +,-, and <<. For the following values of K, write C expressions to
// perform the multiplication using at most three operations per expression.

// A. K = 17
// B. K = -7
// C. k = 60
// D. K = -112

#include <assert.h>

int A(int x)
{
	// K = 17
	// x * 17 = x * ( 1 + 16) = x*16 + x = x << 4 + x
	return (x << 4) + x;
}

int B(int x)
{
	// K = -7
	return -(x << 3) + x;
}

int C(int x)
{
	// K = 60
	return (x << 6) - (x << 2);
}

int D(int x)
{
	// K = -112
	return -(x << 7) + (x << 4);
}

int main(int argc, char* argv[]) {
	int x = 0x87654321;
	assert(A(x) == 17 * x);
	assert(B(x) == -7 * x);
	assert(C(x) == 60 * x);
	assert(D(x) == -112 * x);
	return 0;
}