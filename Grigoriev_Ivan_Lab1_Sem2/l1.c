/*
Лабораторная работа №1. Второй семестр. Григорьев Иван гр.6304
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int funccmp(const void * x1, const void * x2)  // функция сравнения
{
  return ( *(int*)x1 - *(int*)x2 );  // если результат вычитания - 0, значит числа равны
}

int main() {
    int i;
    time_t t1,t2,t3,t4;
    int j=0;
    int key=0;
    int arr[1000];
    for(i=0;i<1000;i++)
        scanf("%d\n", &arr[i]);
    qsort(arr, 1000, sizeof(int), funccmp); //Сортировка массива с помощью алгоритма быстрой сортировки
    t1=time(NULL);
    int *ptr=(int*)bsearch(&key, arr, 100, sizeof(int), funccmp); //Двоичный поиск ключа
    t2=time(NULL);
    if(ptr!=NULL)
        printf("exists\n");
    else
        printf("doesn't exist\n");
    printf("%I\n", t2-t1); //Время двоичного поиска ключа
    t3=time(NULL);
    for(i=0;i<1000;i++){
        if(arr[i]==key){
            j=arr[i];
            break;
        }    
    }
    t4=time(NULL);
    if(j==key)
        printf("exists\n");
    else
        printf("doesn't exist\n");
    printf("%I\n", t4-t3); //Время поиска перебором
        
  return 0;
}
