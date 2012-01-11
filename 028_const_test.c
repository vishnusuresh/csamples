/* pg: 28 ECP */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	const int ci = 10;

	int *pi = NULL;
	const int *pci = &ci;

	i = 15; /* No warnings */
	//ci = 20; /* error: assignment read-only variable */
	pi = &i; /* No Warnings */
	pi = &ci; /* warnings: assignment discards qualifiers from ptr target type  */
	pci = &i; /* No Warnings */
	pci = &ci; /* No Warnings */
	pci = pi; /* No Warnings */

	return 0;
}
