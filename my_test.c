#include <stdio.h>
//
// Created by yongqi wang on 15/7/2025.
int isAsciiDigit(int x)
{

	int result =
		(x ^ 0x30) &
		(x ^ 0x31) &
		(x ^ 0x32) &
		(x ^ 0x33) &
		(x ^ 0x34) &
		(x ^ 0x35) &
		(x ^ 0x36) &
		(x ^ 0x37) &
		(x ^ 0x38) &
		(x ^ 0x39);
	printf("internal %d\n", result);
	return !result;
}

int main(void)
{
	int x = 0x3a;
	int result = isAsciiDigit(x);
	printf("result: %d\n", result);
}