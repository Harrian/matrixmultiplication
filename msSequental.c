#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 3
#define MODVAL 10
#define SEEDVAL 1
#define NUMTHREADS 1

int** a;
int** b;
int** c;

int size = SIZE;
int modval = MODVAL;
int seedval = SEEDVAL;
int numthreads = NUMTHREADS;

int main(int argc, char **argv) {
	char switcher;
	int i, ii, iii;

	while ((switcher = getopt (argc, argv, "t:s:m:r:")) != -1) {
		switch(switcher) {
			case 't':
				numthreads = atoi(optarg);
			break;
			case 's':
				size = atoi(optarg);
			break;
			case 'm':
				modval = atoi(optarg);
			break;
			case 'r':
				seedval = atoi(optarg);
			break;
			case '?':
				if (isprint (optopt))
        			fprintf(stderr, "Unknown option `-%c'.\n", optopt);
        		else
        			printf("some argument that was supplied broke this :P\n");
			default:
				abort();
			break;
		}
	}

	srand(seedval);
	a = malloc(size * sizeof(int*));
	b = malloc(size * sizeof(int*));
	c = malloc(size * sizeof(int*));
	for (i = 0; i < size; ++i) {
		a[i] = malloc(size * sizeof(int));
		b[i] = malloc(size * sizeof(int));
		c[i] = malloc(size * sizeof(int));
	}
	//populate and print a
	//printf("size:\n");
	for (i = 0; i < size; ++i) {
		for(ii = 0; ii<size; ++ii) {
			a[i][ii] = rand() % modval;
	//		printf("%d ", a[i][ii]);
		}
	//	printf("\n");
	}
	//populate and print b
	//printf("\nsize:\n");
	for (i = 0; i < size; ++i) {
		for(ii = 0; ii<size; ++ii) {
			b[i][ii] = rand() % modval;
	//		printf("%d ", b[i][ii]);
		}
	//	printf("\n");
	}
	//zero c for the addtion
	for (i = 0; i < size; ++i) {
		for(ii = 0; ii<size; ++ii) {
			c[i][ii] = 0;
		}
	}
	//calc
	for (iii = 0; iii < size; ++iii) {
		for (ii = 0; ii < size; ++ii) {
			for (i = 0; i < size; ++i) {
				c[iii][ii] += a[iii][i] * b[i][ii];
			}
		}
	}
	//print c
	//printf("\nsize:\n");
	/*for (i = 0; i < size; ++i) {
		for(ii = 0; ii<size; ++ii) {
			printf("%d ", c[i][ii]);
		}
		printf("\n");
	}*/

	return 0;
}