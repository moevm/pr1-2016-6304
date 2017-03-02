#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int arr[10];
  int x;
	for (int i=0; i<10; i++)
	  scanf("%d", &arr[i]);
	int max=arr[0];
	int min=arr[0];
	for (int i=0; i<10; i++)
	{
		if (arr[i]>max)
			max=arr[i];
		if (arr[i]<min)
			min=arr[i];
	}
	x=max-min;
	printf("%d \n",x);
	return 0;
}
