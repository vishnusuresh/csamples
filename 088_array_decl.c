/* pg: 88 ECP */

/* use 'size' command
 * Global Arrays are stored in BSS
 * Extern DOES NOT allocate storage
 * Local arrays are not allocated storage
 */

#include <stdio.h>

int arr[10][20][30];
int i[10];

/* can have multiple Extern delarations */
extern int arr[][20][30]; /* Valid */
extern int arr[10][20][30]; /* Valid */
//extern int arr[][][30]; /* Incomplete Element Type */
//extern int arr[20][20][30]; /* Conflicting Types */
//extern int *arr[20][30]; /* Conflicting Types */

extern int i[]; /* Valid */
//extern int i[20]; /* Conflicting Types */
//extern int *i; /* Conflicting Types */

int main(int argc, char *argv[])
{
	/* Static 'initialises' i,
	 * IF the variable is used later on.
	 * Stores in text space
	 */
	static int i; /* Within function scope redeclared 'i' */
	argc = argc; argv = argv;
	arr[0][0][0] = 0;
	//i = 1; /* No increase in text size */
	i++; /*No increase in Text size. Optimized by gcc? */
	printf("Element 0 is %d\n", arr[0][0][0]);
	return 0;
}
