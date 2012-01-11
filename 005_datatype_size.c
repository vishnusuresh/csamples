/* pg: 5 ECP */
#include <stdio.h>

int main (int argc, char *argv[])
{
	argc = argc;
	argv = argv;

	printf("Sizeof short is:%02X \n", sizeof (short));
	printf("Sizeof char is:%02X \n", sizeof (char));
	printf("Sizeof int is:%02X \n", sizeof (int));
	printf("Sizeof float is:%02X \n", sizeof (float));
	printf("Sizeof double is:%02X \n", sizeof (double));
	printf("Sizeof long is:%02X \n", sizeof (long));
	printf("Sizeof long long is:%02X \n", sizeof (long long));
	printf("Sizeof long double is:%02X \n", sizeof (long double));

	return 0;
}
