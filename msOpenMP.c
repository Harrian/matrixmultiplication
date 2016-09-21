#include <stdio.h>i
nt main()
{
	int i;
	int tid;
	omp_set_num_threads(10);
	#pragma omp parallel for private(tid) private(i)
	for (i=0; i<30; ++i) 
	{
	
		tid = omp_get_thread_num();

		printf("hi from %d: %d\n", tid, i );
	}
	return 0;
}