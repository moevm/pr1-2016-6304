#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int len, i;
	printf("Введите длину строки либо очень большое число: ");
	scanf("%d", &len);
	char* s = (char*)malloc(sizeof(char)*len);
	scanf("%s", s);
	for (i = 0; i < strlen(s); i++)
	{
	if (i%2 == 1 ) printf("%c", s[i]);
    }
	printf("\n");

}
