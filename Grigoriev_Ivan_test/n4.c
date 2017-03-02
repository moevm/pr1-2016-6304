#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char s[100], c;
	printf("Vvedite predlojenie, a zatem neobhodimiy simvol: \n");
	scanf("%s %c", s, &c);
	int n=strlen(s);
	for (int i=0; i<n; i++)
	{
		if (c == s[i]);
		else
			printf("%c", s[i]);
	}
	printf("\n");
}
