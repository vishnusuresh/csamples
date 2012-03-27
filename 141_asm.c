/* pg: 141 ECP */

/* Mixing assembly and C code */
/* Using GCC syntax */
/*
 * asm ( assembler template
 * 	: output operands
 * 	: input operands
 * 	* clobbered registers
 * 	);
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10, b = 0, c = 3, d = 4;

	printf("Starting values\n");
	printf("a is %d\n", a);
	printf("b is %d\n", b);
	printf("c is %d\n", c);
	printf("d is %d\n", d);

	asm (/* Copy contents of a to b */
		"movl %3, %%eax\n\t"	/* Copy first input to EAX */
		"movl %%eax, %0\n\t"	/* Copy EAX to first output */
		/* Now to Swap c and d */
		"movl %4, %%ebx\n\t"
		"movl %5, %1\n\t"	/* Copy var5 (i/p d) to var1 (o/p c) */
		"movl %%ebx, %2\n\t"
		: "=r" (b), "=r" (c), "=r" (d)	/* output */
		: "r" (a), "r" (c), "r" (d)	/* input */
		: "%eax", "%ebx"	/* clobbered reg */
	    );

	printf("\nEnding values\n");
	printf("a is %d\n", a);
	printf("b is %d\n", b);
	printf("c is %d\n", c);
	printf("d is %d\n", d);

	return 0;
}
