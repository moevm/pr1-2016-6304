#include <stdio.h>

int main()
{
	int a, b, c = 1;
	int i;
	printf("Vvedite chislo i stepen:");
	scanf ("%d %d", &a, &b);
	for (i = 0; i< b; i++)
	{
		c *=a;
	}
	printf("%d^%d = %d\n", a, b, c);
}
