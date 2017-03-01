// Задачи 08.02.2017.cpp : Defines the entry point for the console application.
//

// Задача 1.1
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{
	int a, b;
	
	printf("Введите число и степень, в которую его требуется возвести \n");
	scanf("%d %d", &a, &b);
	int c = a;

	for (int i = 0; i < b-1; i++)
	{
		a *= c;
	}

	printf("%d \n", a);

	system("pause");

    return 0;
}

