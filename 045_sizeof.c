/* pg: 45 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 4;
	int i;
	int *j;
	void *p;

	i = a * sizeof a;
	printf("i is %d\n", i);
	i = a * sizeof *p;
	printf("i is %d\n", i);
	j = &a;
#if 0
	/* Error: invalid operands to binary * (have 'unsigned int' and 'int *')
	 * 'binary *' means multipliation. Unary * is pointer indirection
	 * 'unisgned int' is the type of the result of sizeof(int))
	 * 'int *' is the type of variable j
	 */
	i = sizeof (int) * j;
	printf("i is %d\n", i);
#endif

	return 0;
}
