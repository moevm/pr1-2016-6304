#include <stdio.h>
#include <stdlib.h>

int get_max(int* arr, int len)
{
	int maxx = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > maxx) maxx = arr[i];
	}
	return maxx;
}
int get_min(int* arr, int len)
{
	int minn = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < minn) minn = arr[i];
	}
	return minn;
}
int main()
{
	int len;
	printf("Dlina posledovat :");
	scanf("%d", &len);
	int* str = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &str[i]);
	}
	
	printf("%d\n", get_max(str, len) - get_min(str, len));

}
