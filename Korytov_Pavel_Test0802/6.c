#include <stdio.h>
#include <stdlib.h>

void main(){
   int N; int i; int k;
   scanf("%d", &N);
   int **a = (int**)malloc(N*sizeof(int*));
   for (i=0; i<N; i++){
      a[i]=(int*)malloc(N*sizeof(int));
   }
   a[0][0]=1; a[0][N-1]=2; a[N-1][0]=2; a[N-1][N-1]=1;
   for (i=0; i<N; i++) {
      for (k=0; k<N; k++)
         printf("%d ", a[i][k]);
       printf("\n");
    }
}
