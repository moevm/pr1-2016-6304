// Laba_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void print_sentence(char* buf, int lenth, int count);		// Печать предложения

int main()
{
	int buf = 0;			// Переменная для посимвольного ввода
	char* buffer = NULL;		// Массив для хранения текущего ввода

	int count = 0;			// Длина буфера ввода
	int n = 0;				// Количество предложений в изначальном тексте 
	int m = 0;				// Количество предложений в отформатированном тексте
	int lenth = 0;			// Длина текущего предложения

	/* Поссимвольно считавание веденного текста до знака "!" */
	while ((buf = getchar()) != '!')
	{
		buffer = (char*)realloc(buffer, sizeof(char)*(count + 1));
		buffer[count++] = (char)buf;
	}

	/* Форматирование текста */
	for (int i = 0; i < count; i++)
	{

		if ((buffer[i] == '.') || (buffer[i] == ';'))
		{
			print_sentence(buffer, lenth, i);		// Печатаем очередное предложение

			n++; m++;		// Увеличиваем оба счетчика
			lenth = 0;		// Обнуляем длину текущего предложения
		}

		else if (buffer[i] == '?')
		{
			n++;		// Увеличиваем только счетчик  предложений до
			lenth = 0;		// Обнуляем длину текущего предложения
		}

		/* Игнорируем табляцию и пробелы в начале предложения и символ новой строки */
		else if (((buffer[i] == '\t') && (lenth == 0)) || (buffer[i] == '\n') || ((buffer[i] == ' ') && (lenth == 0)));

		/* При встрече символа увеличиваем длину текущего предложения */
		else
			lenth++;

	}

	printf("Количество предложений до %d и количество предложений после %d \n", n, m);

	free(buffer);

	system("pause");

	return 0;
}

void print_sentence(char* buf, int lenth, int i)
/* Печать предложения. lenth - длина текущего преложения, i - текущая позиция при проходе по массиву */
{
	for (int g = i - lenth; g <= i; g++)
		printf("%c", buf[g]);
	printf("\n");
}