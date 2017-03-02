#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
char c;
int i = 0;
while ((c = getchar()) != '\n')
{
i++;
if ((i % 2) != 1) printf("%c", c);
}
printf("\n");

system("pause");
return 0;
}
