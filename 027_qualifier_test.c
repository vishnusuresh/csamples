/* pg: 27 ECP */

#include <stdio.h>

int main(int argc, char *argv[])
{

	/* (unqualified) ptr to char with no qualifiers */
	char *cp = NULL;
	/* (unqualified) ptr to char with qualifier const */
	const char *ccp = NULL;

	/* (unqualified) ptr to a (unqualified) ptr to char with no qualifiers */
	char **cpp = &cp;
	/* (unqualified) ptr to a (unqualified) ptr to char with qualifier const */
	const char **ccpp = &ccp;

	/* Assignment rule Section 6.3.1.6.1 */
	/* Both operands are pointers to qualified or
	 * unqualified versions of compatible types,
	 * and the type pointed by the LEFT has ALL
	 * the qualifiers of the type pointed by the right
	 */

	/* This works */
	/* left is char qualified by const; right is char unqualified */
	ccp = cp;

	/* left is char unqualified; Discards qualifier 'const' present in right */
	/* "warning: assignment discards qualifier from pointer target type" */
	cp = ccp;

	/* Both assignments generates warning */
	/* "warning: assignment from incompatible pointer type" */
	/* Because ccpp is a pointer to Type A (ptr to char)
	 * Whereas cpp is a pointer to Type B (ptr to CONST char)
	 */
	ccpp = cpp;
	cpp = ccpp;

	return 0;
}
