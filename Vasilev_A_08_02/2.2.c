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
			arr[i][e] = e + i +1;
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
