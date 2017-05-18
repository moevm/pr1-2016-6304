#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp (const void*, const void*);

main(){
    int i,j,mas[1000];
    clock_t start, end;
    double time;
    for (i = 0; i<1000; i++)
        scanf("%d",&mas[i]);
    start = clock();
    qsort(mas, 1000, sizeof(int), comp);
    end = clock();
    for (j = 0; j<1000; j++)  
        printf("%d ", mas[j]);
    time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\n%f\n",time);
}

int comp (const void * a, const void * b){
    return (*(int*)b - *(int*)a);
}