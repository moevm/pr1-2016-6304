#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comparator(const void* x1, const void* x2) {
        return (abs(*(int*)x2) - abs(*(int*)x1) ); //сравнение элементов массива по модулю
}

int main()
{
        int *arr=(int*)malloc(sizeof(int)*10); //выделение памяти под массив
        int i;
        for (i=0; i<10;i++) fscanf(stdin,"%d", (arr+i)); //ввод элементов массива
        qsort(arr, 10, sizeof(int), comparator); //сортировка элементов массива по убыванию модуля
        int sorttime=clock(); //счетчик времени выполнения сортировки (в тактах)
        for (i=0;i<10; i++) printf("%d", *(arr+i)); //вывод отсортированного массива
        printf("\n");
        printf("%d", sorttime); //вывод времени сортировки
        free(arr); //освобождение памяти под массив
        return 0;
}
