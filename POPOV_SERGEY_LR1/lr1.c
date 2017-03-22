#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

int main()
{
	clock_t start_t, end_t;
	double qsort_time;
	int array[1000];
	int i,j;
	for (i = 0; i<1000; i++)
	{
		scanf("%d",&array[i]);
	}
	start_t = clock();
	qsort(array, 1000, sizeof(int), cmpfunc);
	end_t = clock();
	for (j = 0; j<1000; j++) 
	{   
		printf("%d ", array[j]);
	}
	printf("\n");
	qsort_time = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	printf("%f\n",qsort_time);
	return 0;
}
