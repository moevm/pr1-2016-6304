#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char* s=(char*)malloc(sizeof(char)*512);
	  int k=0;
	  char a;
	   scanf("%s %k", s, &a);
	     for(int i=0;i<strlen(s);i++)
	       if(s[i]==a) k++;
	        printf("%d", k);
	return 0;

}
