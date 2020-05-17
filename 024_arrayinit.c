/* K & R */
#include <stdio.h>

#define dprintf(expr) printf(#expr " = %g\n", expr)
#define LIT(x) (x ## A)
#define ARSIZE 10

	enum delta{
		DELTA = 'y'
	};
main()
{
	enum alphabet {
		ALPHA = 'a',
		BETA,
		GAMMA,
		DELTA,
	};


	char xx = '\141';
	float pi = 3.14;
	int ndigit[ARSIZE] = {1}; /* Array intialisation */
	for (int i = 0; i < ARSIZE; i++)
		printf("%d\t", ndigit[i]);
	printf("CHar:c:%c, 0x%02X, d%d, 0%o \n",xx, xx, xx, xx);
	printf("beta is :%c and Delta is %c\n", BETA, DELTA);
	printf("LIT is: %c\n", LIT(ALPH));
	dprintf(LIT(ALPH) * 10/LIT(GAMM));
	dprintf((ALPHA) * 10/(GAMMA));

	printf("FLoat is %F, in hex is %a or %X\n", pi,pi,pi);
}
