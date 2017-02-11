#include "stdio.h"

void print(char* a, int len) //описание функции вывода предложения
{	for (int i = (a[0] == ' ') ? 1 : 0; i < len; i++) //проверка предложения на предмет наличия пробела
		printf("%c", a[i]);
}

int main()
{
	char c;
	char* buf=NULL;
	int m = 0, n = 0, len = 0;
	while ((c = getchar()) != '!') //считываем все символы до (!)
	{
		switch (c) //сортировка знаков препинания
		{
		case '.':  print(buf, len); printf("%c\n", c); len = 0; m++; n++; break;
		case ';':  print(buf, len); printf("%c\n", c); len = 0; m++; n++; break;
		case '?':  len = 0; m++;    break;
		case '\n': len = 0;    	    break;
		case '\t': len = 0;    	    break;
		default: // запись других символов ( не ; . ? \n \t)
            {
                buf = (char*)realloc(buf, (++len) * sizeof(char)); // выделяем память под каждый символ
                buf[len - 1] = c;
            }
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n); //вывод результата
	return 0;
}
