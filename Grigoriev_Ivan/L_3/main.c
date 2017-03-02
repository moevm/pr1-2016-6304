#include <stdio.h>
#include <stdlib.h>

void print(char* a, int len); //Прототип 

int main() 
{
	char c;  //Переменная для символов
	char* buf=NULL; 
	int m = 0, n = 0, len = 0, i = 0;  //m-количество предложений до, n-количество предложений после, len-длина строки

	while ((c = getchar()) != '!')   //Посимвольное считывание до "!"
	{
		switch (c)
		{
		case '.':  print(buf, len); printf("%c\n", c); i = 0; m++; n++; break;  //Вывод символов до точки и самой точки 
		case ';':  print(buf, len); printf("%c\n", c); i = 0; m++; n++; break;  //Вывод символов до ";" и самой";"
		case '?':  i = 0; m++;  break;
		case '\n': i = 0;	break;
		case '\t': i = 0;	break;
		default:
			{
				len = ++i;
				buf = (char*)realloc(buf, i * sizeof(char));  //Выделение памяти на новый символ
				buf[i - 1] = c; //Запись символа в буфер
			}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n); //Вывод подсчета предложение
	return 0;
}

void print(char* a, int len)    //Описание функции, выводящей элементы буфера
{	for (int i = (a[0] == ' ') ? 1 : 0; i < len; i++)
	{
		printf("%c", a[i]);
	}
}
