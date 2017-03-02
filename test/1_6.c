#include <stdio.h>

int main ()
{
	int N;
	printf ("N - ");
	scanf ("%d", &N);
	int arr[N][N];
	for (int i = 0, j = 0; i < N; i++ )
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
			if (i == 0)
			{
				if (j == 0)
					arr[i][j] = 1;
				if (j == N-1)
					arr[i][j] = 2;
			}
			else if (i == N-1)
			{
				if (j == 0)
					arr[i][j] = 2;
				if (j == N-1)
					arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++ )
			printf ("%d ", arr[i][j]);
		printf ("\n");
	}
	return 0;
}
