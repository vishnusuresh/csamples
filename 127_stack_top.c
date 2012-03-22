/* pg: 127 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	static char *i = "abcdef";
	int j;
	static int k = 30;
	static int l;

	printf("Text top is near %p\n", &i);
	printf("Stack top is near %p\n", &j);
	printf("Data top is near %p\n", &k);
	printf("BSS top is near %p\n", &l);
	return 0;
}
