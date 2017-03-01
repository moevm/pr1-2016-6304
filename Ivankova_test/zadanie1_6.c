#include <stdio.h>

int main() {
	int **arr;
	int n;
	scanf("%d",&n);
	arr=(int**)malloc(n*sizeof(int*));
	for (int i=0;i<n;i++)
	arr[i]=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
	arr[i][j]=0;
	arr[0][0]=1;
	arr[0][n-1]=2;
	arr[n-1][n-1]=1;
	arr[n-1][0]=2;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		printf("%d",arr[i][j]);
		printf("\n");
	
	}
	return 0;
}
