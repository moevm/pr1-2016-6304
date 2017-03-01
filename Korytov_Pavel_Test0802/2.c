#include <stdio.h>
#include <string.h>

void main(){
   char s[100]; int i;
   fgets(s, 100, stdin);
   for (i=1; i<strlen(s); i=i+2){
      printf("%c", s[i]);
   }
} 
