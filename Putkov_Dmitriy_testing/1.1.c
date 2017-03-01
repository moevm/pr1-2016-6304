#include "stdio.h"
#include "stdlib.h"
int pow(int a, int stepen)
{
	int c=a;

	for (int i = 1; i < stepen; i++)
		c = c*a;

	return c;
}

int main()
{
	int a = 0;
	int stepen = 0;

	scanf_s("%d %d", &a, &stepen);
	printf("%d\n", pow(a,stepen));

	system("pause");
    return 0;
}
