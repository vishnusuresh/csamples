/* pg: 108 ECP */

#include <stdio.h>
#include "108_01_static_linker_lib.h"

int main(int argc, char *argv[])
{
	int a = 10;
	int b = 12;
	int c;

	c = sumthisup(a, b);
	printf("Result of using libsumthisup: %d\n", c);
	return 0;
}
