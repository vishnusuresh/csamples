#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SAMPLE 0xF5AE10

uint8_t wordlength(uint64_t data)
{
	/* TODO
	 * ceiling nearest power of 2 */
	return 64;
}

void runcount(uint64_t data)
{
	uint8_t c = (data & 0x1);
	uint8_t d = 0;
	uint8_t o = 0;
	uint8_t p = 1;
	uint8_t i = 0;


	for (i = 1; i < wordlength(data); i++) {
		d = ((data >> i) & 0x1);

		if (d == c) {
			if (p) {
				printf("%d,", o);
				p = 0;
			}
		} else {
			o = i;
			c = d;
			p = 1;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	uint64_t i  = SAMPLE;

	if (argc == 2)
		i = strtoul(argv[1], NULL, 10);

	printf("Run offsets for 0x%08X are:\n", i);
	runcount(i);
	printf("\n");
	return 0;

}
