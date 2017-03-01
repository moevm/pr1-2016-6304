// Задачи 08.02.2017.cpp : Defines the entry point for the console application.
//

// Задача 1.6
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{
	int n = 0;

	printf(" Введите размер : \n");
	scanf("%d", &n);

	int** a = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int)*n);

		for (int g = 0; g < n; g++)
			a[g] = 0;
	}


	**a = 1;
	*(*a + n - 1) = 2;
	*(*(a + n - 1)) = 2;
	*(*(a + n - 1) + n - 1) = 1;

	for (int i = 0; i < n; i++)
		for (int g = 0; g < n; g++)
			printf("%d", *(*(a + i) + g));
	printf("\n");

	system("pause");

	return 0;
}

