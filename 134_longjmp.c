/* pg: 133 ECP */

/* setjmp will save the pointer to Process Activation Record and return 0
 * lonjmp will use the saved pointer and return to the point and destroys it
 */

#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

void barjmp(void)
{
	printf("In %s\n", __FUNCTION__);
	longjmp(j, 2);
	/* NOTREACHED */
	printf("you'll never see this, because I longjmp'd\n");
}

void foojmp(void)
{
	printf("In %s\n", __FUNCTION__);
	longjmp(j, 1);
	/* NOTREACHED */
	printf("you'll never see this, because I longjmp'd\n");
}

int main(int argc, char *argv[])
{
	switch (setjmp(j)) {
	case 0:
		printf("In %s\n", __FUNCTION__);
		foojmp();
		break;
	case 1:
		printf("From foojmp\n");
		barjmp();
		break;
	case 2:
		printf("From barjmp\n");
		break;
	default:
		printf("Shopuld not reach here\n");
		break;
	}

	return 0;
}
