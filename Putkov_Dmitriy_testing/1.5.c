#include "stdio.h"
#include "stdlib.h"

int main()
{
	int N;
	scanf_s("%d", &N);
	int* a;
	a = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &a[i]);

	int max = a[0];
	int min = a[0];

	for (int i = 0; i < N; i++)
	{
		if (a[i] >= max) max = a[i];
		if (a[i] <= min) min = a[i];
	}

	printf("%d\n", max-min);
		system("pause");
    return 0;
}
