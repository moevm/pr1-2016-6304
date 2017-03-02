#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[100], c;
	int x=0;
	printf("Vvedite stroku, zatem neobhodimiy simvol: \n");
	scanf("%s %c", s, &c);
	int n=strlen(s);
	for (int i=0; i<n; i++)
	{
		if (c == s[i])
			x++;
	}
	printf("%d \n",x);
    return 0;
}
