#include <stdio.h>
#include <stdlib.h>




int get_max(int arr[], int n){
int i=0;
int max=0;
            for (i=0; i<n; i++)
                {
                if (arr[i]>max)
                    {
                    max = arr[i];
                    }
                }
            printf("%d", max);
    return 0;
}

int get_min(int arr[], int n){
int i=0;
int min=arr[0];
            for (i=1; i<n; i++)
                {
                if (arr[i]<min)
                    {
                    min = arr[i];
                    }
                }
            printf("%d", min);
    return 0;
}

int get_sum(int arr[], int n){
int i=0, sum=0;
 for (i=0; i<n; i++)
                {
                if (arr[i]%2==0)
                    {
                    sum = sum+arr[i];
                    }
                }
            printf("%d", sum);
    return 0;
}

int get_count_first_el(int arr[], int n){
  int i, cntr=-1;
for (i=0; i<n; i++)
                {
                if (arr[i]==0)
                    {
                    cntr++;
                    }
                }
            printf("%d", cntr);
    return 0;
}
void menu(int ch, int arr[], int n){

 switch (ch)
        {
        case 0:
            {
            get_max(arr, n);
            }
     break;
        case 1:
        {
            get_min(arr, n);
            break;
        }
        case 2:
        {
         get_sum(arr, n);
            break;
        }
        case 3:
        {
            get_count_first_el(arr, n);
            break;
        }
        default:
        {
            printf("Данные некорректны");
            break;
        }
    }
}
    int main()
    { int n=0, ch=0, i=0;
    scanf ("%d", &n);
    scanf ("%d", &ch);
    int* arr=(int*)malloc(n*sizeof(int));
    for (i=0; i<n; i++)
        {
        scanf ("%d", &arr[i]);
        }
    menu(ch,  arr, n);
    return 0;
    }




