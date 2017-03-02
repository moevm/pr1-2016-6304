#include<string.h>
#include <stdio.h>
#include <stdlib.h>					
#include "text.h"			//Подключаем заголовочный файл с прототипами функций vvod и redact
int main()
{
	char* input=(char*)malloc(10000*sizeof(char));   				      //Объявляем переменные и выделяем под них
	int pered, posle, k, i, *index=(int*)malloc(500*sizeof(int));        //память c запасом
	vvod(input, index, &pered, &posle);                 //Заполняем массив символов и получаем количество предл. до и после
	char* output=(char*)malloc(strlen(input)*sizeof(char));	//Выделяем под массив вывода память
	redact(input, index, pered, output);	                //Заполняем массив редактированным текстом и печатаем результат
	free(input);							    //
	free(index);								//
	free(output);								//Освобождаем выделенную раннее память
	printf("Количество предложений до %d и количество предложений после %d\n", pered, posle);
}



