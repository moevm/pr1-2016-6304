#include "stdio.h"
void print(char* a, int len)
{	for (int i = (a[0] == ' ') ? 1 : 0; i < len; i++)
		printf("%c", a[i]);
}
int main(){
	char c; 
	char* buf=NULL;
	int m = 0, n = 0, len = 0, i = 0;
	while ((c = getchar()) != '!')
	{
		switch (c)
		{
		case '.':  print(buf, len); printf("%c\n", c); i = 0; m++; n++; break;
		case ';':  print(buf, len); printf("%c\n", c); i = 0; m++; n++; break;
		case '?':  i = 0; m++;  break;
		case '\n': i = 0;	break;
		case '\t': i = 0;	break;
		default:
		{
			len = ++i;
			buf = (char*)realloc(buf, i * sizeof(char));
			buf[i - 1] = c; 
		}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n);
	return 0;
}