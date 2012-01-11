/* pg: 36 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 10;
	int *pi;

	printf("Contents of ptr is %02X\n", *pi);
	printf("I is %d and ptr to i is %02X\n", i, pi);
	pi = &i;
	printf("Contents of ptr to i is %02X\n", *pi);
	pi = NULL;
	printf("Dereference NULL ptr %02X\n", pi);
	i =  *pi; /* Runtime Error */
	printf("Dereference NULL ptr %02X\n", i);

	return 0;
}

