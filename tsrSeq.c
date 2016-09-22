#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** createTwoDArray(int a, int b, int init){
  int i=0,j=0;
  int ** r = malloc(a * sizeof(int *));
  for(i=0;i<a;i++)
    r[i]=malloc(b * sizeof(int));
  for(i=0;i<a;i++){
    for(j=0;j<b;j++)
      r[i][j]=init?rand()%init:0;
  }
  return r;
}
void printTwoDArray(int ** a, int b, int c){
	int i,j;
	for(i=0;i<b;i++){
		for(j=0;j<c;j++)
			printf("%2d ",a[i][j]);
		printf("\n");
	}
	return;
}
int main(int argc, char * argv[]){
	if(argc!=4){
		printf("Error\nUsage: \% ./a.out PRINTFLAG SIZE MOD\nPrint Flag should be 0 for off or any other number for on\n");
		exit(1);
	}
int printFlag=atoi(argv[1]);
int size=atoi(argv[2]);
int mod=atoi(argv[3]);
int ** ar1=createTwoDArray(size,size,mod);
int ** ar2=createTwoDArray(size,size,mod);
int ** results = createTwoDArray(size,size,0);
if(printFlag){
	printf("%d\n",size);
	printTwoDArray(ar1,size,size);
	printf("\n");
	printTwoDArray(ar2,size,size);
}
int i,j,k;
for(i=0;i<size;i++){
	for(j=0;j<size;j++){
		for(k=0;k<size;k++){
			results[i][j] += ar1[i][k]*ar2[k][j];
		}
	}
}
// printf("Here: %d %d\n",ar1[1][0],ar2[0][1]);
// printf("Here: %d %d %d\n",ar1[0][0]*ar2[0][1],
						  // ar1[0][1]*ar2[1][1],
						  // ar1[0][2]*ar2[2][1]);

if(printFlag)
	printTwoDArray(results,size,size);
return 0;	
}