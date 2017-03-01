#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char* string=(char*)malloc(100*sizeof(char));
int amount=0;
char *symbol=(char*)malloc(100*sizeof(char));
scanf("%s", string);
scanf("%s", symbol);
for (int i=0; i<strlen(string); i++)
        if ( *symbol== *(string+i) )
        amount++;
printf("%d", amount);
return 0;
}
