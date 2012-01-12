/* pg: 53 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	char a[] = "this is very long string \
			split into two lines";
	int x = 6, y = 2, z;

	printf("String is: %s\n", a);
	z = y++;
	printf("x is: %d\n", x); /* x is 6 */
	printf("y is: %d\n", y); /* y is 3 */
	printf("z is: %d\n", z); /* z is 2 */
	/* Maximal Munch
	 * Read this as
	 * z = (y++) + x;
	 */
	z = y+++x;
	printf("x is: %d\n", x); /* x is 6 */
	printf("y is: %d\n", y); /* y is 4 */
	printf("z is: %d\n", z); /* z is 9 */

	/* Maximal munch should have read this
	 * as z = (y++) + (x); like above
	 * resulting in x = 6; y = 6 and z = 10.
	 * BUT white space matters!
	 * The gcc reads it as z = y + (++x);
	 * resulting in x = 7, y = 4 and x = 11
	 */
	z = y + ++x;
	printf("x is: %d\n", x); /* x is 7 */
	printf("y is: %d\n", y); /* y is 4 */
	printf("z is: %d\n", z); /* z is 11 */

	z = y++ + ++x;
	printf("x is: %d\n", x); /* x is 8 */
	printf("y is: %d\n", y); /* y is 5 */
	printf("z is: %d\n", z); /* z is 12 */

#if 0
	/* maximal Munch
	 * error: lvalue required as increment operand
	 * Maximal Munch
	 * Read this as
	 * z = (y++) (++) + x;
	 */
	z = y+++++x;
	printf("x is: %d\n", x); /* x is 8 */
	printf("y is: %d\n", y); /* y is 5 */
	printf("z is: %d\n", z); /* z is 12 */
#endif

	return 0;
}


