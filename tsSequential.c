#include <stdio.h>

int main()
{
	int arraya[100][100];
	int arrayb[100][100];
	int arrayc[100][100];

	int i = 0;
	int j = 0;
	int k = 0;

	int size = 3; //size of square matrix

	printf("Matrix A:\n");
	for(i = 1; i <= size; i++) //fill arraya
	{
		for(j = 1; j <= size; j++)
		{
			arraya[i][j] = rand() % 10;
			printf("%4d", arraya[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix B: \n");
	for(i = 1; i <= size; i++) //fill arrayb
        {
                for(j = 1; j <= size; j++)
                {
                        arrayb[i][j] = rand() % 10;
                        printf("%4d", arrayb[i][j]);
                }
                printf("\n");
        }
        printf("\n");

	printf("Answer:\n");
	for(i = 1; i <= size; i++) //calculate answers and fill arrayc
	{
		for(j = 1; j <= size; j++)
		{
			for(k = 1; k <= size; k++)
				arrayc[i][j] += arraya[i][k]*arrayb[k][j];
			printf("%4d", arrayc[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
