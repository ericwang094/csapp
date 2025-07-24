#include <stdio.h>
//
// Created by yongqi wang on 15/7/2025.


int isLessOrEqual(int x, int y)
{
	int diff_sign = !!((x >> 31) ^ (y >> 31)); // check if sign same or diff, if diff, diff_sign is 1

	printf("diff_sign %d\n", diff_sign);
	// if x is neg (x >> 31 = 1) and diff_sign is (1), it means y is pos, so overall answer is x < y = 1
	// if diff sign (1) and x is pos ( x >> 31 = 0), it means y is neg, so overall answer is 0 as x > y
	int diff_sign_x_is_neg = diff_sign & (x >> 31);

	// if not diff (0), then use following to calculate result
	int same_sign = !diff_sign & !((y + (~x + 1)) >> 31);

	return diff_sign_x_is_neg | same_sign;
}

// int isAsciiDigit(int x)
// {
// 	printf("x: %d\n", x);
// 	// if this is neg, then should return 0
// 	int is_neg = !!(x >> 31);
// 	printf("is_neg %d\n", is_neg);
//
// 	// if it is pos, 0x39 - x, the result should be positive
// 	int subtract_is_positive = !((0x39 - x) >> 31);
// 	printf("0x39 - x: %d\n", 0x39-x);
// 	printf("(0x39 -x) >> 39: %d\n", (0x39 - x) >> 31);
// 	printf("!((0x39 - x) >> 31: %d\n", !((0x39 - x) >> 31));
// 	printf("subtract_is_positive %d\n", subtract_is_positive);
//
// 	int result = is_neg | ((!is_neg) & subtract_is_positive);
// 	printf("result: %d\n\n", result);
// 	return result;
// }

int isAsciiDigit(int x)
{
	int lowerBound = x + ~0x30 + 1;  // Equivalent to x - 0x30
	int upperBound = 0x39 + ~x + 1;  // Equivalent to 0x39 - x

	// Check if x is greater than or equal to 0x30
	int isGreaterOrEqual0x30 = !(lowerBound >> 31);
	// Check if x is less than or equal to 0x39
	int isLessOrEqual0x39 = !(upperBound >> 31);
		printf("result: %d\n\n", isGreaterOrEqual0x30 & isLessOrEqual0x39);
	return isGreaterOrEqual0x30 & isLessOrEqual0x39;
}

int main(void)
{
	int result = isAsciiDigit(-2147483648);
	int result2 = isAsciiDigit('9');
	int result3 = isAsciiDigit(2147483647);
}