#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* z1, const void* z2){//сравнивнение двух чисел
	return *(int*)z1 - *(int*)z2;//возвращет 0, если числа равны
}


int main(){
	int* arr = (int*)malloc(100*sizeof(int));//выделение динамическрй памяти
	int key = 0;
	int len = 1000;
	int i;
	int is_null  = 1;
	clock_t time;
	for(i = 0; i<len; i++)//считывание массива
		scanf("%d",&arr[i]);
	qsort(arr, len, sizeof(int), compare);//алгоритм быстрой сортировки
	
	time = clock();//функция времени
	int * element = (int*) bsearch(&key, arr, len, sizeof(int), compare);//реализация алгоритма двоичного поиска
	time = clock() - time;//подсчет времени работы части программы
	if(element!=NULL)
		printf("exists\n");
	else 
		printf("doesn't exist\n");
	printf("%f\n", (double)time);

	time = clock();
	for(i=0; i<len; i++){//поиск нуля методом перебора массива
		if(arr[i] == key){
			printf("exists\n");
			time = time - clock();
			is_null++;
			break;
		}
	}

	if(is_null == 1)
		printf("doesn't exist\n");
	printf("%f\n", (double)time);
	free(arr);//освобождение выделенной динамической памяти
	return 0;
} 
