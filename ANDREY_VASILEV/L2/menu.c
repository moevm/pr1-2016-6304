#include<stdio.h>

int get_max(int arr[], int n){
int i, max;
    max = arr[0];                          //Сначала за максимальный элемент
    for (i = 1; i < n; i++){              //принимаем первый
        if (max >= arr[i]) continue;     //С помощью цикла проверяем
        else max = arr[i];              //есть ли элементы больше текущего 
    } 			               // максимального элемента. Если да
    return max;			      // присваиваем новое макс. значение. и т.д.
}

int get_min(int arr[], int n){
int i, min;			      //По аналогии с поиском максимального
    min = arr[0];		      //значения ищется и минимальное.
    for (i = 1; i < n; i++){	      // Меняется лишь знак проверки оператора
        if (min <= arr[i]) continue;  // if
        else min = arr[i];
    }
    return min;
}

int get_sum(int arr[], int n){			//С помощью цикла и условия 
int i, sum = 0;                                 // проверяем, равен ли остаток от
    for (i = 0; i<n; i++){                      // деления значения на 2 нулю
        if (arr[i]%2 == 0) sum = sum + arr[i];	// Если это так, то элемент четный
        else continue;				// и к сумме прибавляется его значение
    }						// Если нет - элемент пропускается.
    return sum;
}

int get_count_first_el(int arr[], int n){
int i, count = 0;				//С помощью цикла и условия проверяем
    for (i =1; i<n; i++){			//равен ли текущий элемент первому
        if (arr[i] == arr[0]) count ++;		//Если равен, то к переменной count 
        else continue;				//прибавляется единица.Проверка 
    }						//осуществляется со второго элемента
    return count;				//т.к. сам первый элемент считаться
}						//не должен
void menu(int ch, int n, int arr[]){
    int a;
    switch (ch){
        case 0:
            a = get_max(arr, n);
            printf ("%d\n", a);
            break;
        case 1:
            a = get_min(arr, n);
            printf ("%d\n", a);
            break;
        case 2:
            a = get_sum(arr, n);
            printf ("%d\n", a);
            break;
        case 3:
            a = get_count_first_el(arr, n);
            printf ("%d\n", a);
            break;
        default:
            printf("Данные некорректны\n");
            break;
    }
}

