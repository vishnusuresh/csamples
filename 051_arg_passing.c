/* pg: 51 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	/* First Argument is the program name
	 * i.e. argc = 1 and argv[0] is program name
	 */
	printf("Number of arguments is %d\n", argc);
	 /*
	  * " and ' are used for string processing
	  * ./a.out "test 1" -f /usr/bin/man 25 'help'
	  * Try ./a.out "test"
	  * and ./a.out "test 1"
	  */
	for (; argc; argc--)
		printf("Argument %d is %s\n", argc, argv[argc-1]);

	return 0;
}

