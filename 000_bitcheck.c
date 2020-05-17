#include <stdio.h>
#include <stdint.h>

#define DIGITS 32
#define MAX (((uint64_t)1 << DIGITS) - 1)

int toBin(uint32_t x)
{
	int r = 0; /* For neater print */
	uint32_t i;
	for (i = 0; i < DIGITS ; i++) {
		if (!(x & (x >> 1))) {
			int val = (0x00000001 & (x >> i));
			printf("%d", val);
			r = 1;
		}
	}
	return r;
}

int main(int argc, char *argv[])
{
	uint32_t i = 0;

	for (i = 0; i < MAX; i++) {
		if (toBin(i))
			printf("\n");
	}
	return 0;
}
