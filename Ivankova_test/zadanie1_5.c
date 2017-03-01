#include <stdio.h>

int main() {
	int length;
	scanf("%d",&length);
	int arr[length];
	for (int i=0;i<length;i++){
	scanf("%d",&arr[i]);
	}
	int max=arr[0], min=arr[0];
	for (int i=0;i<length;i++)
	{
		if (arr[i]>max)
		max=arr[i];
		if (arr[i]<min)
		min=arr[i];
	}
	int rez;
	rez=max-min;
	printf("%d",rez);
}
