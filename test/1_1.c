#include <stdio.h>

int main ()
{
	int a, p;
	double A, B=1;
	printf ("Число - ");
	scanf("%d", &a);
	printf ("Степень - ");
	scanf("%d", &p);
	if (p > 0)
	{
		for (int i=0; i<p; i++)
			B*=a;
	}
	else if (p < 0)
	{
		for (int i=0; i < (p*(-1)); i++)
			B*=a;
			
	}
	A = (p>0) ? B:1/B;
	printf ("Ответ - %g\n", A);
	return 0;
}
