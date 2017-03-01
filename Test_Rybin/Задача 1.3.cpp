// Задачи 08.02.2017.cpp : Defines the entry point for the console application.
//

// Задача 1.3
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{

	char str[1000], c;

	int count = 0;

	printf(" Введите строку и искомый символ : \n");
	scanf("%s %c", str, &c);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (c == str[i])
			count++;
	}

	printf("%d \n",count);
	system("pause");

    return 0;
}

