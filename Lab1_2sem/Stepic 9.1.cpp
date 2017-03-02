/*
Лабораторная работа №1. Второй семестр. Рыбин Александр гр.6304
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Функция сравнения для сортировки и бинарного поиска */
int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main() {

	/* Буфер для хранения исходного текста */
	char buffer[1000];
	
	/* Искомое слово */
	char substring[30];
	
	/* Массив хранения слов */
	char words_array[1000][1000];

	int count = 0;

	fgets(buffer, 1000, stdin);
	(*strstr(buffer, "\n")) = '\0';

	fgets(substring, 30, stdin);

	/* Вспомогательный указатель для разбиения на слова */
	char* pointer = strtok(buffer, " .");

	while (pointer)
	{
		strcpy(words_array[count], pointer);
		
		pointer = strtok(NULL, " .");
		count++;
	}

	/* Сортировка массива */
	qsort(words_array, count, 1000, compare);

	/* Бинарный поиск */
	char* ptr = (char*)bsearch(substring, words_array, count, 1000, compare);

	if (ptr == NULL)
		printf("doesn't exist\n");
	else
		printf("exists\n");

	system("pause");

	return 0;
}

