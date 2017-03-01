#include <stdio.h>

void main(){
   int a; int b; int i; double c=1;
   scanf("%d %d", &a, &b);
   if (b>0)
       for (i=1; i<=b; i++){
          c=c*a;
       }
   else 
       for (i=1; i<=-b; i++){
          c=(double)c/a;
       }
	
   printf("%g\n", c);
}
