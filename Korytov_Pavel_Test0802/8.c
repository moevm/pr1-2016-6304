#include <stdio.h>
#include <stdlib.h>

void main(){
   int N; int i; int k;
   scanf("%d", &N);
   int **a = (int**)malloc(N*sizeof(int*));
   for (i=0; i<N; i++){
      a[i]=(int*)malloc(N*sizeof(int));
   }
  
   for (i=0; i<N; i++) {
      for (k=0; k<N; k++){
         a[i][k]=i+k+1;
         printf("%d ", a[i][k]);
      }
       printf("\n");
    }
}
