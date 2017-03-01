#include <stdio.h>
#include <string.h>

int main(){

	char a[500];
	int i = 0;
	scanf("%s", a);
	while(a[i]!='\0'){
		if(i%2!=0){
			printf("%c", a[i]);
		}
		i++;
	}
return 0;
}
