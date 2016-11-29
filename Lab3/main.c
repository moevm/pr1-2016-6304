// Laba_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void print_sentence(char* buf, int lenth);		// Печать предложения

int main()
{
	int buf = 0;			// Переменная для посимвольного ввода
	char* buffer = NULL;		// Массив для хранения текущего ввода

	int lenth = 0;			// Длина текущего предложения
	int n = 0;				// Количество предложений в изначальном тексте 
	int m = 0;				// Количество предложений в отформатированном тексте

	do						//	Посимвольный ввод
	{
		buf = getchar();

		if ((buf == '.') || (buf == ';'))
		{
			buffer[lenth++] = (char)buf;		// Записываем текущий символ
			print_sentence(buffer, lenth);		// Печатаем очередное предложение

			n++; m++;		// Увеличиваем оба счетчика
			lenth = 0;		// Обнуляем длину текущего предложения

			buffer = '\0';
		}

		else if (buf == '?')
		{
			lenth = 0;		// Обнуляем длину текущего предложение, потому что предложения с "?" отбрасываются
			n++;		// Увеличиваем только счетчик до
		}

		else if (((buf == '\t') && (lenth == 0)) || (buf == '\n'))
		{
			lenth = 0;		//	Обнуляем длину , потому что табуляция и символы новой строки ложны игнорироваться
		}

		else
		{
			buffer = (char*)realloc(buffer, (lenth + 1) * sizeof(char));		// Увеличиваем память на один символ, чтобы записать его
			buffer[lenth++] = (char)buf;		// Записываем текущий символ
		}

	} while (!(buf == '!'));

	printf("Количество предложений до %d и количество предложений после %d \n", n, m);

	free(buffer);

	system("pause");

	return 0;
}

void print_sentence(char* buf, int lenth)
{
	for (int i = (buf[0] == ' ') ? 1 : 0; i < lenth; i++)		// Пропускаем первый пробел в предложении
		printf("%c", buf[i]);
	printf("\n");
}
