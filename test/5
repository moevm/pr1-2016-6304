#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int K;
	scanf("%d", &K);
	int* a;
	a = (int*)malloc(sizeof(int)*K);
	for (int i = 0; i < K; i++)
		scanf_s("%d", &a[i]);

	int max = a[0];
	int min = a[0];

	for (int i = 0; i < K; i++)
	{
		if (a[i] <= min) min = a[i];
		if (a[i] >= max) max = a[i];
		
	}

	printf("%d", max - min);
	system("pause");
	return 0;
}
