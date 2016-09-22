#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <queue>
#include <ctime>

pthread_mutex_t mutexlock;
class jobnode{
  private:
    int ** arr1;
    int ** arr2;
    int ** results;
    int size;
    int i;
  public:
    jobnode(int**a,int**b,int**c,int d, int e);
    int ** getArr1(void){return arr1;}
    int ** getArr2(void){return arr2;}
    int ** getResults(void){return results;}
    int getSize(void){return size;}
    int getI(void){return i;}
};

jobnode::jobnode(int**a,int**b,int**c,int d, int e){
  arr1=a;
  arr2=b;
  results=c;
  size=d;
  i=e;
}

void* threadfunction(void* param){
  std::queue<jobnode *> * jobqueue = (std::queue<jobnode *> *)param;
  jobnode * job = NULL;
  int j,k;
  while(!jobqueue->empty()){
    pthread_mutex_lock(&mutexlock);
    if(!jobqueue->empty()){
      job=jobqueue->front();
      jobqueue->pop();
    }
    pthread_mutex_unlock(&mutexlock);
    if(job!=NULL){
      for(j=0;j<job->getSize();j++){
    		for(k=0;k<job->getSize();k++){
    			job->getResults()[job->getI()][j] += job->getArr1()[job->getI()][k]*job->getArr2()[k][j];
    		}
    	}
    }
    delete job;
    job = NULL;
  }
  pthread_exit(NULL);
}
int ** createTwoDArray(int a, int b, int init){
  int i=0,j=0;
  int ** r =(int **) malloc(a * sizeof(int *));
  for(i=0;i<a;i++)
    r[i]=(int *)malloc(b * sizeof(int));
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
	if(argc!=5){
		printf("Error\nUsage: a.out PRINTFLAG SIZE MOD NUMOFTHREADS\nPrint Flag should be 0 for off or any other number for on\n");
		exit(1);
	}
  pthread_mutex_init(&mutexlock,NULL);
int printFlag=atoi(argv[1]);
int size=atoi(argv[2]);
int mod=atoi(argv[3]);
int NUM_THREADS=atoi(argv[4]);
int ** ar1=createTwoDArray(size,size,mod);
int ** ar2=createTwoDArray(size,size,mod);
int ** results = createTwoDArray(size,size,0);
if(printFlag){
	printf("%d\n",size);
	printTwoDArray(ar1,size,size);
	printf("\n");
	printTwoDArray(ar2,size,size);
}
std::queue<jobnode *> jobqueue;
int i;
for(i=0;i<size;i++){
  jobqueue.push(new jobnode(ar1,ar2,results,size,i));
}
pthread_t tids[NUM_THREADS];
for(i=0;i<NUM_THREADS;i++){
  pthread_create( &tids[i], NULL, threadfunction, (void *) &jobqueue);
}
void*status;
for(i=0;i<NUM_THREADS;i++){
  pthread_join( tids[i], &status );
}
// printf("Here: %d %d\n",ar1[1][0],ar2[0][1]);
// printf("Here: %d %d %d\n",ar1[0][0]*ar2[0][1],
						  // ar1[0][1]*ar2[1][1],
						  // ar1[0][2]*ar2[2][1]);

if(printFlag)
	printTwoDArray(results,size,size);
pthread_mutex_destroy(&mutexlock);
return 0;
}
