//
// Created by yongqi wang on 22/7/2025.
//

#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y)
{
	int64_t mul = (int64_t) x * y;
	return mul >> 32;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
	uint64_t mul = (uint64_t) x * y;
	return mul >> 32;
}
// This question is a bit hard and I don't really understand it for a long time
// Even the moment of writing, I still don't understand 100%
// but the idea is that x * sig_y + y * sig_x is (chatGPT)
// sign_x * y: This term compensates for the loss due to x being interpreted as negative. It essentially adds back what the MSB 1 removed.
// sign_y * x: Similarly, this term corrects the interpretation when y is seen as negative.
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int sig_x = x >> 31;
	int sig_y = y >> 31;

	int signed_prod = signed_high_prod(x, y);
	return signed_prod + x * sig_y + y * sig_x;
}

int main(int argc, char* argv[]) {
	unsigned x = 0x12345678;
	unsigned y = 0xFFFFFFFF;

	assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
	return 0;
}