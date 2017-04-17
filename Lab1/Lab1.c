#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#define SIZE 1000

void print_time(time_t time) {
	printf("\n%f\n", ((float)time) / CLOCKS_PER_SEC);
}
void bubbleSort2b(int *a, int size) {
    int i, j;
    int tmp;
    clock_t time;
    time=clock();
    for (i = 1; i < size; i++) {
        for (j = 1; j <= size-i; j++) {
            if (a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
    time = clock()-time;
    for (i=0; i<SIZE; i++) {
        printf("%d ", a[i]);
    }
     print_time(time);
}


int compare(const void * x1, const void * x2)
{
	return (*(int*)x1 - *(int*)x2);
}


int main() {
    int* a;
    a = (int*)malloc(sizeof(int)*SIZE);
	clock_t t;
    int i;
    for (i=0; i<SIZE; i++) {
        scanf("%d", &a[i]);
    }
    bubbleSort2b(a, SIZE);
    t=clock();
    qsort(a, SIZE, sizeof(int), compare);
    t=clock()-t;
    print_time(t);

  // put your code here
  return 0;
}
