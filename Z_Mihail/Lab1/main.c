#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
int abs(int a){
    if (a>0)return a;
    else return -a;
}
int compare(const void* b, const void *a){
    return abs(*(int*)a) - abs(*(int*)b);
}
int main()
{
    int a[N]; int i; int time; int time1;
    for (i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    time = clock();
    qsort(a, N, sizeof(int), compare);
    time1 = clock() - time;
    for (i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    printf("\n%d", time1);
    return 0;
}

