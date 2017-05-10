/*
Лабораторная работа №3 "Обход дерева"
2 семестр.
Васильев Андрей, группа 6304.
*/

#include <stdio.h>
#include <stdlib.h>

#include "functions.h" //Файл с объявлением функций
 					   //(определения в "functions.c")
#define MEM_BLOCK 50

int main()
{
/*Выделяется память под массив указателей на строки*/
	char** strings = (char**)malloc(sizeof(char*)*MEM_BLOCK);
	int len = 0;

/*Специальная функция обходит директории и заполняет 
массив из строк строками из файлов(реализация в "functions.c").
Далее выводится несортированные строки (для контроля).*/
	read_catalog(".",strings, &len);	
	printf("\n\n");
	for (int i = 0; i < len; i++)
		printf("%s\n", strings[i]);

/*Строки сортируются библиотечной функцией,
компаратор для которой сравнивает числа в начале строк.
Выводится уже отсортированные строки.*/
	qsort(strings, len, sizeof(char*),compare);
	printf("\n\n");
	for (int i = 0; i < len; i++)
		printf("%s\n", strings[i]);

/*Освобождение памяти, выделенную под каждую строку.
Освобождение памяти под массив строк*/
	for(int i = 0; i < len; i++)
		free(strings[i]);
	free(strings);
  	return 0;
}
