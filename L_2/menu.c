#include <stdio.h>
#include <stdlib.h>

int get_max (int arr [], int n);
int get_min (int arr [], int n);
int get_sum (int arr [], int n);
int get_count_first_el (int arr [], int n);

void menu (int ch, int arr[], int n)
{
        int a; 
        switch (ch)
        {
                case 0:
                        a = get_max (arr, n);
                        break;
                case 1:
                        a = get_min (arr, n);
                        break;
                case 2:
                        a = get_sum (arr, n);
                        break;
                case 3:
                        a = get_count_first_el (arr, n);
                        break;
                default:
                        printf ("Данные не корректны\n");
                        exit (1);
        }               
        printf ("%d\n", a);
}

