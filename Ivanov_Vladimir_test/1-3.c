#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char* s=(char*)malloc(sizeof(char)*10000);
	int c=0;
	char a;
	scanf("%s %c", s, &a);
	for(int i=0;i<strlen(s);i++)
	    if(s[i]==a) c++;
	printf("%d", c);
	return 0;

}
