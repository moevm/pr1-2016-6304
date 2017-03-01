#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//udalenie simvola iz stroki 1 - 4

int main() {

char s;
char* str = (char*)malloc(100*sizeof(char));
int i;

scanf("%c", &s);
scanf("%s", str);

for (i = 0; i<strlen(str); i++)
if (str[i]!=s)
printf("%c", str[i]);

printf("\n");
return 0;
}
