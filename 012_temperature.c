/* K & R */
#include <stdio.h>

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		/* The following will output 0
		 * As int of (5/9) evaluates to 0.
		 * Integer divsion truncates:
		 * Any fractional part is discarded
		 */
		/* celsius = (5/9) * (fahr - 32); */
		/* Therefore use the following */
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
