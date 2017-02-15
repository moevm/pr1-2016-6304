#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n=0;
	int i=0;
	int j=0;
	int k=0;
	scanf("%d", &n);
	int** s=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		s[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++){
		k=i+1;
		for(j=0;j<n;j++){
			s[i][j]=k;
			k++;
	}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d", s[i][j]);
		}
	printf("\n");
	}
}
