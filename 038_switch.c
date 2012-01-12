/* pg: 38 ECP */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	const int two = 2;
	int three = 3;

	switch (i) {
		// default: i++; /* Results in Looping for any value of i */
		/* loops on i == 2 or i == 8 */
		case 5+3: do_again:	/* FallThru */
		// default: i++; /* Results in Looping for any value of i */
		case 2: printf("I loop unremittingly %d \n", i);
			goto do_again;
		default: i++; /* No Looping if default is here */
		case 3: ;
	}

	printf("i is %d \n", i);
	printf("Const 'two' DOES NOT mean 'a constant' %d\n" /* String Concat */
		"nor is integer 'three' reduced to integral value %d\n"
		"inside switch statements\n%s", two, three,
		/* The %s in the "format string" (first arg for printf)
		 * is required to read the following line as 'char *'
		 * arguments and gets printed
		 */
		"Uncomment 'case two' " /* String gets conactenated */
		"or 'case three\n" /* String conactenated */
		"resulting in a compilation error\n");

	switch (i) {
		case 1: printf("case 1 \n");
			i = 10;
			if (i == 10) {
				printf("i is now %d\n", i);
				i--;
				if (i > 1) {
					printf("i is now %d\n", i);
					break; /* Breaks out of Switch rather than if. */
				}
				i--;
			}
			/* If the break was intended here, it does not reach here" */
			printf("i is now %d\n", i);
		/* ERROR: case label does not reduce to an integer constant */
		// case two: printf("case two \n");
		// case three: printf("case 3 \n");
		default: ;
	}

	return 0;
}

