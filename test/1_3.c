#include <stdio.h>
#include <stdlib.h>
	
int main ()
{
	char* ch = (char*)malloc(1);
        char c, C;
        int i = 0;
	printf ("Строка - ");
        while ((c = getchar()) !='\n')
        {
                *(ch+i) = c;
                i++;
                ch = (char*)realloc(ch, (i+1)*sizeof(char));
        }
                *(ch+i)  = '\0';
	printf ("Символ - ");
	C = getchar();
	i = 0;
	int counter=0;
	while (*(ch+i)!='\0')
	{
		if (*(ch+i) == C)
			counter++;
		i++;
	}
	printf ("%d\n", counter);
	return 0;
}
