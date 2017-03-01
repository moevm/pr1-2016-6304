#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//raznica minimalnogo i maksimalnogo elementov massiva 1 - 5

int main() {

int i, min, max, b;
int length;
scanf("%d", &length);
int* arr = (int*)malloc(length*sizeof(int));

for (i = 0; i<length; i++)
scanf("%d", &arr[i]);

min = arr[0];
max = arr[0];

for (i = 1; i<length; i++){

if (arr[i]>max)
max = arr[i];

if (arr[i]<min)
min = arr[i];

}

b = max - min;
printf("%d", b);

return 0;
}
