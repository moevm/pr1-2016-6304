#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int length, i;
	printf("Dlina stroki: ");
	scanf("%d", &length);
	char* str = (char*)malloc(sizeof(char)*length);
	scanf("%s", str);
	for (i = 0; i < strlen(str); i++)
	{
		if (i%2 == 1 ) printf("%c", str[i]);
	}
	printf("\n");
}
