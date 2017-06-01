#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void bubble_sort(int *array, int number)
{
    int element;
    for (int i=number-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
            if(array[j]>array[j+1])
        {
            element=array[j];
            array[j]=array[j+1];
            array[j+1]=element;
        }
    }
}
int cmp(const void *first, const void *second)
{
    return(*(int*)first-*(int*)second);
}
int main()
{
    int *array;
    int number=1000;
    array=(int*)malloc(sizeof(int)*number);
    for(int i=0;i<number;i++)
    {
        scanf("%d", &array[i]);
    }
    int *save=(int*)malloc(sizeof(int)*number);
    for(int i=0;i<number;i++)
    {
        save[i]=array[i];
    }
    time_t a = clock();
    bubble_sort(array, number);
    a=clock()-a;
    time_t b = clock();
    qsort(save, number, sizeof(int), cmp);
    b=clock()-b;
    for(int i=0;i<number;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nTime of bebble=%d", a);
    printf("\nTime of Qsort=%d", b);
  return 0;
}
