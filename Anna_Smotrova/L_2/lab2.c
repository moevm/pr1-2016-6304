#include<stdio.h> //подключаем функции ввода-вывода
void menu(int ch, int arr[], int n) 
{

 switch (ch) //оператор множественного выбора, зависящий от одной переменной - номера действия
 {
 case 0: printf("%d\n",get_max(arr,n)); // Если 0, выведет максимальный элемент массива
 return;
 case 1: printf("%d\n",get_min(arr,n)); // Если 1 - минимальный
 return;
 case 2: printf("%d\n",get_sum(arr,n)); // Если 2 - выведет сумму всех четных элементов
 return;
 case 3: printf("%d\n",get_count_first_el(arr,n)); // Если 3 - число повторений первого элемента массива
 return;
 default: printf("Данные некорректны\n"); // Если введено другое значение, программа выведет сообщение.
 }
}

int get_max(int arr[], int n) //функция поиска максимального элемента в массиве
{
 int max=arr[0]; //берем за максимальный первый элемент массива
 for(int i=1;i<n;i++) 
 {
 if(max<arr[i]) // и сравниваем по всему массиву, если ли элемент больше, чем max
 max=arr[i]; // если есть, записываем в переменную max
 }
 return max;

}

int get_min(int arr[], int n) //с поиском минимального элемента аналогично поиску максимального
{
 int min=arr[0];
 for(int i=1;i<n;i++)
 {
 if(min>arr[i])
 min=arr[i];
 }
 return min;
}

int get_sum(int arr[], int n) //функция, возвращающая сумму четных элементов массива
{ 
 int s=0;
 for (int i=0;i<n;i++)
 {
 if (arr[i]%2==0) //ищем четные элементы массива
 s+=arr[i]; //суммируем
 }
return s;
}

int get_count_first_el(int arr[], int n) //функция возвращает число повторов первого элемента
{
int s=0;
 for (int i=1;i<n;i++) //начинаем с 1, а не с 0, чтобы цикл не считал вхождение самого первого элемента
 {
 if (arr[i]==arr[0])
 s++;
 }
 return s;
}
