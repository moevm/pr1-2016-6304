#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;
    int a=1;
 while ((c=getchar())!=EOF)
 {
    if (a%2==0)
        printf("%c", c);
    a++;
 }
 return 0;
}

