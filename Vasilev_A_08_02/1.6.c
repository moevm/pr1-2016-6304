#include <stdio.h>
#include <stdlib.h>

int main()
{
	int razm;
	scanf("%d", &razm);
	int** arr = (int**)malloc(sizeof(int*)*razm);
	for (int i = 0; i<razm; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*razm);
	}
	for (int i = 0; i <razm; i++)
	{
		for (int e = 0; e < razm; e++)
		{
			if (i == 0 && e == 0){
			arr[i][e] = 1; continue;};
			if (i== 0 && e+1 == razm){
			arr[i][e] = 2; continue;}
			
			if (i+1 == razm && e == 0){
			arr[i][e] = 2; continue;}
			if (i+1== razm && e+1 == razm){
			arr[i][e] = 1; continue;}
			arr[i][e] = 0;
			

		}
	}

	for (int i = 0; i <razm; i++)
	{
		for (int e = 0; e < razm; e++)
		{
			printf("%d ",arr[i][e]);
		}
		printf("\n");
	}
}
