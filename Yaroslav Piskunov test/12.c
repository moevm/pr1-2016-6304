#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Vivod kazdogo vtorogo simvloa stroki 1 - 2

int main() {
int i = 0;
char* str = (char*)malloc(100*sizeof(char));
char ch;
int k;

while ((ch = getchar()) != '\n'){
str[i] = ch;
i++;
}


for (k = 1; k<i; k = k+2)
printf("%c", str[k]);

printf("\n");
return 0;
}
