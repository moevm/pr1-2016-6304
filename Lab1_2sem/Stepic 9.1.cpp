/*
������������ ������ �1. ������ �������. ����� ��������� ��.6304
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ������� ��������� ��� ���������� � ��������� ������ */
int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main() {

	/* ����� ��� �������� ��������� ������ */
	char buffer[1000];
	
	/* ������� ����� */
	char substring[30];
	
	/* ������ �������� ���� */
	char words_array[1000][1000];

	int count = 0;

	fgets(buffer, 1000, stdin);
	(*strstr(buffer, "\n")) = '\0';

	fgets(substring, 30, stdin);

	/* ��������������� ��������� ��� ��������� �� ����� */
	char* pointer = strtok(buffer, " .");

	while (pointer)
	{
		strcpy(words_array[count], pointer);
		
		pointer = strtok(NULL, " .");
		count++;
	}

	/* ���������� ������� */
	qsort(words_array, count, 1000, compare);

	/* �������� ����� */
	char* ptr = (char*)bsearch(substring, words_array, count, 1000, compare);

	if (ptr == NULL)
		printf("doesn't exist\n");
	else
		printf("exists\n");

	system("pause");

	return 0;
}

