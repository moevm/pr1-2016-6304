#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char* s=(char*)malloc(sizeof(char)*10000);
	char a;
	int j;
	scanf("%s %c", s, &a);
	for(int i=0;i<strlen(s);i++)
	    if(s[i]==a) {
	        j=i;
	        while(j<strlen(s)){
	        s[j]=s[j+1];
	        j++;}
	    };
	printf("%s", s);
	return 0;

}
