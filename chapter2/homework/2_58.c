#include <assert.h>
#include <stdio.h>
// Write a procedure is_little_endian that will return 1 when compiled and run
//on a little-endian machine, and will return 0 when compiled and run on a big-
//endian machine. This program should run on any machine, regardless of its word
//size.
typedef unsigned char* byte_pointer;

int is_little_endian()
{
	int test_num = 0xAAFF;
	byte_pointer byte_start = (byte_pointer) &test_num;

	if (byte_start[0] == 0xFF)
	{
		return 1;
	}

	return 0;

}
int main(void)
{
	assert(is_little_endian());
	return 0;
}