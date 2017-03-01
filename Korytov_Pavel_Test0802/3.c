#include <stdio.h>
#include <string.h>

void main(){
   char s[100]; char ch; int k=0; int i;
   scanf("%s %c", s, &ch);
   for (i=0; i<strlen(s); i++)
      if (s[i] == ch)
         k++;
   printf("%d\n", k);
}
