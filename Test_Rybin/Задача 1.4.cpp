// ������ 08.02.2017.cpp : Defines the entry point for the console application.
//

// ������ 1.4
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{

	char str[1000], c;

	printf(" ������� ������ � ������, ��� �������� ��������� ������� ������ : \n");
	scanf("%s %c", str, &c);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (c == str[i]);
		else
			printf("%c", str[i]);
	}

	printf("\n");
	system("pause");

    return 0;
}

