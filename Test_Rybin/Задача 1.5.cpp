// ������ 08.02.2017.cpp : Defines the entry point for the console application.
//

// ������ 1.5
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

int main()
{

	int masiv[10];

	printf(" ������� �������� ������� \n");

	for (int i = 0; i < 10; i++)
		scanf("%d", &masiv[i]);

	int max = masiv[0];
	int min = masiv[0];

	for (int i = 0; i < 10; i++)
	{
		if (masiv[i] > max)
			max = masiv[i];

		if (masiv[i] < min)
			min = masiv[i];
	}

	printf("%d \n", max - min);
    
	system("pause");
	return 0;
}

