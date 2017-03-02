#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int N;
	scanf("%d", &N);
	int** a;
	a = (int**)malloc(N*sizeof(int*));

  	for (int i = 0; i < N; i++)
	{
		  a[i] = (int*)malloc(N*sizeof(int));
		    for (int j = 0; j < N; j++)
		  	a[i][j] = 0;
	}

	  a[0][0] = 1;
  	a[N - 1][0] = 1;
	  a[N - 1][N - 1] = 2;
	  a[0][N - 1] = 2;

	for (int i = 0; i < N; i++)
	{
		printf("\n");
		  for (int j = 0; j < N; j++)
			  printf("%d ", a[i][j]);

	}
	printf("\n");
	system("pause");
	return 0;
}
