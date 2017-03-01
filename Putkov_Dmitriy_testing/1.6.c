#include <stdlib.h>
#include <stdio.h>

int main(){

	int N;	// размерность матрицы;
	scanf("%d", &N);

	int **array=(int**)malloc(N*sizeof(int*));
	for (int i=0; i<N; i++)
		*(array+i)=(int*)malloc(N*sizeof(int));

	for (int i=0; i<N; i++)
		
		for (int j=0; j<N; j++)
		{
			if (((i==0) && (j==0)) || ((i==(N-1)) && (j==(N-1))))
				array[i][j]=1;

			else if (((i==(N-1)) && (j==0)) || ((i==0) && (j==(N-1))))
				array[i][j]=2;
			else
				array[i][j]=0;
		}

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<N; j++)
			{
			printf("%d", array[i][j]);
			}
		printf("\n");
		}
		system("pause");
}
