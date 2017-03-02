#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu (int ch, int arr[], int n);

int main ()
{
	int ch, n = 20;
	int arr [n];
	srand(time(NULL));
	for (int i=0;i<n;i++)
		arr[i] = (rand()%1000 + 1);
	printf("ARR - ");
	for (int i=0;i<n;i++)
		printf("%d ", arr[i]);
	printf ("\nChoice - ");
	scanf ("%d", &ch);
	menu (ch, arr, n);
	return 0;
}
