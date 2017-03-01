#include <stdio.h>
#include <string.h>

int main(){

	char s[500];
	char a;
	int i = 0;
	int n = 0;
	fgets(s, 500, stdin);
	a = getchar();
		while (s[i]!='\0'){
		if(s[i]==a)
		n++;
		i++;
}
printf("%d", n);
return 0;
}
