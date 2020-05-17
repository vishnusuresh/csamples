/* K & R */
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXWORD 10

struct node {
	char *w;
	uint8_t c;
	struct node *l;
	struct node *r;
};

void treeprint(struct node *t)
{
	if (t) {
		treeprint(t->l);
		printf("Word:%s (%d)\n", t->w, t->c);
		treeprint(t->r);
		free(t);
	}
}

struct node * addtree(struct node *t, char *w)
{
	int c;

	if (!t) {
		t = (struct node *) malloc (sizeof (struct node));
		t->w = (char *) malloc (sizeof(strlen(w)) + 1);
		memcpy(t->w, w, strlen(w) + 1);
		t->c = 1;
		t->l = t->r = NULL;
	} else {
	       	if ((c = strcmp(t->w, w)) == 0) {
			t->c++;
		} else if (c < 0) {
			t->l = addtree(t->l, w);
		} else {
			t->r = addtree(t->r, w);
		}
	}

	return t;
}

int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getchar()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++) {
		if (!isalnum(*w = getchar())) {
			ungetc(*w, stdin);
			break;
		}
	}

	*w = '\0';
	return word[0];
}

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	char word[MAXWORD];


	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]))
			root = addtree(root, word);
	}

	treeprint(root);

	return 0;
}
