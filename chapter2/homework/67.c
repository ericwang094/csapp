//
// Created by yongqi wang on 17/7/2025.
//

int int_size_is_32()
{
	// set most significant bit (msb) of 32-bit machine
	int set_msb = 1 << 31;

	// shift past msb of 32-bit word
	int beyond_msb = set_msb << 1;

	return set_msb && !beyond_msb;
}

int int_size_is_16bit()
{
	int set_msb = 1 << 15 << 15 << 1;
	int beyond_msb = set_msb << 1;

	return set_msb && !beyond_msb;
}