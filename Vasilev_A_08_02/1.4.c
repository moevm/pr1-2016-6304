#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* str = (char*)malloc(sizeof(char)*1000);
	char ch;
	int count = 0;
	scanf("%s",str);
	ch = getchar();   // Ochistka buffera vvoda
	scanf("%c", &ch);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch) continue;
		printf("%c", str[i]);
	}
	printf ("\n");
}
