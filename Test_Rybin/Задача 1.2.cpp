// Задачи 08.02.2017.cpp : Defines the entry point for the console application.
//

// Задача 1.2
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{	
	char str[1000];
	printf(" Введите строку : \n");
	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if ( !(i % 2 == 0) )
			printf("%c", str[i]);
	}

	printf("\n");
	system("pause");

    return 0;
}

