#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sozdanie kvadratnoi matrici opredelennogo vida 1 - 6

int main() {

int i,N, j;
scanf("%d", &N);

int** a = (int**)malloc(N*sizeof(int*));
for (i = 0; i<N; i++)
a[i] = (int*)malloc(N*sizeof(int));

for (i=0; i<N; i++)
for (j=0; j<N; j++)
a[i][j] = 0;

a[0][0] = 1;
a[0][N-1] = 2;
a[N-1][0] = 2;
a[N-1][N-1] = 1;

i = 0;
while (i!=N)
{
for (j = 0; j<N; j++)
printf ("%d ", a[i][j]);
i++;
printf("\n");
}

printf("\n");
return 0;
}
