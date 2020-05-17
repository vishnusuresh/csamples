#include <stdio.h>
#define WIDTH 3
#define HEIGHT 2

int main(int argc, char *argv[])
{
		int arr[HEIGHT][WIDTH] = { {1,2,3,}, {7, 8, 9,},};
		int i = 0, j = 0;

		for (i = 0; i < HEIGHT; i++) {
				for (j = 0; j < WIDTH; j++)
						printf("%d\t", arr[i][j]);
				printf("\n");
		}

		return 0;
}

