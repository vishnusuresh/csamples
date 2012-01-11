/* pg: 30 ECP */

#include <stdio.h>

int array[] = {10, 11, 12, 13, 14, 15};
#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))

int main(int argc, char *argv[])
{

	int d = -1, x;

	/* ANCI C */
	/* TOTAL_ ELEMENTS is unsigned
	 * Since sizeof returns unsigned
	 * Therefore d is converted to unsigned
	 * "-1" converted to unsigned is large
	 */
	printf("sizeof array is %u\n", sizeof(array));
	printf("sizeof array[0] is %u\n", sizeof(array[0]));
	if ( d < TOTAL_ELEMENTS -2)
		x = array[d +1];
	else
		printf("Condition failed since 'd' is unsigned int %u\n", (unsigned int)d);

	if ( d < (int) TOTAL_ELEMENTS -2)
		printf("Condition Success as both are signed numbers\n");

	return 0;
}
