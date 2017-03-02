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
                *(ch+i++) = c;
                ch = (char*)realloc(ch, (i+1)*sizeof(char));
        }
                *(ch+i)  = '\0';
        printf ("Символ - ");
        C = getchar();
	char* ch1 = (char*)malloc(1);
	int j = 0;
	i = 0;
	while (*(ch+i)!='\0')
	{
		if (*(ch+i) != C)
		{
			*(ch1+j++) = *(ch+i);
			ch1 = (char*)realloc(ch1, (j+1)*sizeof(char));
		}
		i++;
	}
	*(ch1+j) = '\0';
	j = 0;
	while (*(ch1+j)!='\0')	
		printf ("%c", *(ch1+(j++)));
	printf ("\n");
	return 0;
}
