#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define A 3
#define B A
#define C B
#define MODVAL 10

int a[A][A];
int b[B][B];
int c[C][C];

int main()
{
	srand(0);
	int i, ii, iii;
	//omp_set_num_threads(10);

	printf("A:\n");
	for (i = 0; i < A; ++i) {
		for(ii = 0; ii<A; ++ii) {
			a[i][ii] = rand() % MODVAL;
			printf("%d ", a[i][ii]);
		}
		printf("\n");
	}
	printf("\nB:\n");
	for (i = 0; i < B; ++i) {
		for(ii = 0; ii<B; ++ii) {
			b[i][ii] = rand() % MODVAL;
			printf("%d ", b[i][ii]);
		}
		printf("\n");
	}
	//zero c for the addtion
	for (i = 0; i < B; ++i) {
		for(ii = 0; ii<B; ++ii) {
			c[i][ii] = 0;
		}
	}
	#pragma omp parallel for private(iii) private(ii) private(i)
	for (iii=0; iii<A; ++iii) {
		for (ii = 0; ii < B; ++ii) {
			for (i = 0; i < A; ++i) {
				c[iii][ii] += a[iii][i] * b[i][ii];
			}
		}
	}
	printf("\nC:\n");
	for (i = 0; i < C; ++i) {
		for(ii = 0; ii<C; ++ii) {
			printf("%d ", c[i][ii]);
		}
		printf("\n");
	}
	return 0;
}