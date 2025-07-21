//
// Created by yongqi wang on 18/7/2025.
//


#include <stdio.h>

int main(void)
{
	if (10 - sizeof(int) > 0)
	{
		printf("10 is greater than 32"); // code will print this
	} else
	{
		printf("10 is smaller than 32");
	}

	return 0;
}
