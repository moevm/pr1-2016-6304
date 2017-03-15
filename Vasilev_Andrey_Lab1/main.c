/*
Лабораторная работа №1 "Обзор стандартной библиотеки"
2 семестр.
Васильев Андрей, группа 6304.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * a, const void * b)        /*Функция сравнения*/ 
{
	return strcmp(*(char**)a, *(char**)b);      /* Возвращает результат сравнения двух строк:    */
}                                               /* 0 - "a" = "b"; >0 - "a" > "b"; <0 - "a" < "b" */

int main()
{
    char* input_text = (char*)malloc(sizeof(char)*1000);  /* Выделяем память под текст и слово для поиска*/
    char* str = (char*)malloc(sizeof(char)*30);
    char** words = (char**)realloc(words, sizeof(char*)); /*Выделяем память под первое слово*/
    
    fgets(input_text, 1000, stdin);                /*Считываем исходный текст и слово для поиска*/
    fgets(str,30, stdin);
    *strchr (input_text, '\n') = '\0'; /* Для корректной работы в консоли Ubuntu требуются данные строки */
    *strchr (str, '\n') = '\0';        /* которые удаляют знаки переноса строки                          */
    
    int count = 0;                            
	words[count] = strtok(input_text, " .");  /* Ищем первую лексему и помещаем её в массив*/
    
    while(words[count])            /* Цикл выполняется пока элемент массива не равен NULL*/
    {		
        words = (char**)realloc(words, sizeof(char*)*(count+2));    /* Выделяем память под новое слово   */
		words[++count] = strtok(NULL, " .");                        /* и помещаем в неё следующую лексему*/      
    }
    words = (char**)realloc(words, sizeof(char*)*(count));    /* Перераспределяем память, так как последний элемент не указывает на строку, а указывает на NULL*/
    
	qsort (words, count, sizeof(char*), compare);    /* Сортируем массив строк библиотечной функцией*/
	char** text_has_str = (char**)bsearch(&str, words, count, sizeof(char*), compare); /* Ищем строку "str" в массиве*/
	
    if(text_has_str)
        printf("exists\n");
	else
        printf("doesn't exist\n");
		

    return 0;
}
