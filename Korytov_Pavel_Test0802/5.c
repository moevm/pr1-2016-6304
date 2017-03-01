#include <stdio.h>
#include <stdlib.h>

void main(){
   int N;
   scanf("%d", &N);
   int *a = (int*)malloc(N*sizeof(int));
   int i; int c; int b;
   for (i=0; i<N; i++){
      scanf("%d", &a[i]);
      if (i==0){
         c=a[i]; b=a[i];
      }
      else{
	 if (a[i]>c)
            c=a[i];
         if (a[i]<b)
            b=a[i];
      }
   }
   printf("%d\n", c-b);
}
