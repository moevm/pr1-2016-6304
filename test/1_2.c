#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char* ch = (char*)malloc(1);
	char c;
	int i = 0;
	while ((c = getchar()) !='\n')
	{
		*(ch+i) = c;
		i++;
		ch = (char*)realloc(ch, (i+1)*sizeof(char));	
	}
		*(ch+i)  = '\0';
	i = 0;
	while (*(ch+i) != '\0')
	{
		if (i%2 == 1)
			printf ("%c", *(ch+i));
		i++;
	}
	printf ("\n");
	return 0;
}
