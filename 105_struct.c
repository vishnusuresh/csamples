/* K & R */

#include <stdio.h>

#define ARR_SZ(x) (sizeof(x) / sizeof(x[0]))

struct {	/* structure tag is optional */
	int x;
	int y;
} svar; 

typedef struct { /* structure tag is optional */
	int x;
	int y;
} point_t; 

/* To find the sizeof array */
point_t arr[20]; 
char carr[25];

struct usz {
	point_t p;
	char a;
};

struct asz {	/* Align */
	char a;
	point_t p;
} __attribute__((aligned (8)));

int main(int argc, char*argv[])
{
	svar.x =  10;
	point_t p1 = {11,22};
	point_t p2 = {33,44};
	printf("svar %d x, %d y\n", svar.x, svar.y);
	printf("  p1 %d x, %d y\n", p1.x, p1.y);
	printf("  p2 %d x, %d y\n", p2.x, p2.y);
	p2 = p1;
	printf("  p1 %d x, %d y\n", p1.x, p1.y);
	printf("  p2 %d x, %d y\n", p2.x, p2.y);
	printf("Array size is %lu\n", ARR_SZ(arr));
	printf("Array size is %lu\n", ARR_SZ(carr));
	printf("sizeof char is %lu\n", sizeof(char));
	printf("sizeof unaligned struct sz is %lu\n", sizeof(struct usz));
	printf("sizeof aligned struct sz is %lu\n", sizeof(struct asz));
	return 0;
}
