#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ARG_CNT 3
#define FALSE 0
#define TRUE 1
#define touch(x) ((x)=(x))

void usage(void)
{
	printf("\nUsage: filecreate filename sizeX\n");
	printf("\t Where 'X' is either B, K, M or G\n");
	exit(0);
}

int parsesize(char *size, int *denom)
{
	int i = 0;
	for (i = 0; (size[i]) && (i < strlen(size)); i++)
		if (size[i] < '0' || size[i] > '9')
			break;

	if (!size[i] || size[i] == 'B' || size[i] == 'b') 
		*denom = 1;
	if (size[i] == 'K' || size[i] == 'k')
		*denom = 2;
	if (size[i] == 'M' || size[i] == 'm')
		*denom = 3;
        if (size[i] == 'G' || size[i] == 'G')
		*denom = 4;
	else
		return FALSE;
	size[i] = '\0';
	return TRUE;
}

void getfilesize(char *size, int *sizeval, int * denom)
{
	parsesize(size, denom);
	*sizeval = atoi(size);
	return;
}

int main (int argc, char *argv[])
{
	int fo, i = 0, j = 0, k = 0, denom = 0;
	long long size;
	char *c = "a";

	touch(argc); touch(argv);
	touch(fo); touch(i); touch(j); touch(k); 
	touch(size); touch(denom); touch(c);

	if (argc < ARG_CNT) {
		usage();
	}
	
	fo = open(argv[1], O_RDWR | O_CREAT);
	getfilesize(argv[2], &i, &denom);
	size = 1;

	for (j = 0; j < denom - 1; j++) {
		size = size * 1024;
	}

	for (j = 0; j < i; j++)
	 	for (k = 0; k < size; k++) {
			write(fo, c, 1 );
		}
	
	close(fo);
	return 0;
}

