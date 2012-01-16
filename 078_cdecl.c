/* pg: 078 and 081 ECP */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {
	IDENTIFIER,
	QUALIFIER,
	TYPE,
};

struct token {
	char type;
	char string[MAXTOKENLEN];
};

static int top = -1;
static struct token stack[MAXTOKENS];
static struct token this;

#define pop stack[top--]
#define push(s) stack[++top]=s

static enum type_tag classify_string(void)
{
	char *s = this.string;

	if (!strcmp(s, "const")) return QUALIFIER;
	if (!strcmp(s, "volatile")) return QUALIFIER;
	if (!strcmp(s, "void")) return TYPE;
	if (!strcmp(s, "char")) return TYPE;
	if (!strcmp(s, "signed")) return TYPE;
	if (!strcmp(s, "unsigned")) return TYPE;
	if (!strcmp(s, "short")) return TYPE;
	if (!strcmp(s, "int")) return TYPE;
	if (!strcmp(s, "long")) return TYPE;
	if (!strcmp(s, "float")) return TYPE;
	if (!strcmp(s, "double")) return TYPE;
	if (!strcmp(s, "struct")) return TYPE;
	if (!strcmp(s, "union")) return TYPE;
	if (!strcmp(s, "enum")) return TYPE;

	/* None of the above, must be Identifier */
	return IDENTIFIER;
}

static void gettoken(void)
{
	char *p = this.string;

	/* read past any spaces */
	while ((*p = getchar()) == ' ')
		;

	if (isalnum(*p)) {
		/* It starts with A-Z, 0-9 read in identifier */
		while (isalnum(*++p=getchar()))
			;
		ungetc(*p,stdin);
		*p = '\0';
		this.type = classify_string();
		return;
	}

	if (*p == '*') {
		strcpy(this.string, "pointer to ");
		this.type = '*';
		return;
	}

	this.string[1] = '\0';
	this.type = *p;
	return;
}

static void deal_with_pointers(void)
{
	while (stack[top].type == '*') {
		printf("%s ", pop.string);
	}
	return;
}

static void deal_with_function_args(void)
{
	while (this.type != ')') {
		gettoken();
	}
	printf("function returning ");
	return;
}

static void deal_with_arrays(void)
{
	while (this.type == '[') {
		printf("array ");
		gettoken(); /* a number or ']' */
		if (isdigit(this.string[0])) {
			printf("0..%d ", atoi(this.string) - 1);
			gettoken(); /* Read the ']' */
		}
		gettoken(); /* Read next past the ']' */
		printf("of ");
	}

	return;
}

static void deal_with_declarator(void)
{
	/* Deal with possible array/function postfix */
	switch (this.type) {
		case '[': deal_with_arrays();
			  break;
		case '(': deal_with_function_args();
			  break;
	}

	/* Deal with pointer prefix */
	deal_with_pointers();

	/* Process other tokens in stack */
	while (top >=0) {
		if (stack[top].type == '(') {
			pop;
			gettoken(); /* Read past ')' */
			deal_with_declarator();
		} else {
			printf("%s ", pop.string);
		}
	}

	return;
}

static void read_to_1st_id(void)
{
	gettoken();
	while (this.type != IDENTIFIER) {
		push(this);
		gettoken();
	}

	printf("%s is ", this.string);
	gettoken();
	return;
}

int main(int argc, char * argv[])
{
	argc = argc; argv = argv;
	read_to_1st_id();
	deal_with_declarator();
	printf("\n");
	return 0;
}

