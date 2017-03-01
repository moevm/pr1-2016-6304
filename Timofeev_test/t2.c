#include<stdio.h>
#include<stdlib.h>

int main() {

	char a[256];
	scanf("%s", a);
	int i=0;
	while (a[i]!='\0'){
		if (i%2!=0){
			printf("%c", a[i]);
		}
		i++;
	}
	return 0;
}
