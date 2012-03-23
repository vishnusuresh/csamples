/* pg: 133 ECP */

/* setjmp will save the pointer to Process Activation Record and return 0
 * lonjmp will use the saved pointer and return to the point and destroys it
 */

#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

void foojmp(void)
{
	printf("foojmp\n");
	longjmp(j, 1);
	/* NOTREACHED */
	printf("you'll never see this, because I longjmp'd\n");
}

int main(int argc, char *argv[])
{
	if (setjmp(j)) {
		printf("back in main\n");
	} else {
		printf("first time through\n");
		foojmp();
	}
	return 0;
}
