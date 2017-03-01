#include <stdio.h>

void main(){
   int a; int b; int m=0; int mn=0; int N; int i; int c;
   scanf("%d %d", &N, &a);
   for (i=1; i<N; i++){
      scanf("%d", &b);
      if (a == b) m++;
      else if (m>mn) { mn = m; m=0; c = a; }
      else m=0;
      a = b;
   }
   if (m>mn) { mn = m; c=b; }
   printf("%d(%d)", mn, c);
     
}
