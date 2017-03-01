#include <stdio.h>
#include <stdlib.h>

int main(){

	int N;
	scanf("%d", &N);
	int arr[100][100];

	for (int i=0; i<N; i++){
		for (int j=0; j<N;j++){
			arr[i][j]=i+j+1;
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
