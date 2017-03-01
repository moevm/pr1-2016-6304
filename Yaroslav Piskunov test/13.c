#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kolichestvo povtorov simvola v stroke 1 - 3

int main() {

int i;
char s;
char* str = (char*)malloc(100*sizeof(char));
int k = 0;

scanf ("%c", &s);
scanf ("%s", str);

for (i = 0; i<strlen(str); i++)
if (str[i]==s)
k++;

printf("%d\n", k);


return 0;
}

