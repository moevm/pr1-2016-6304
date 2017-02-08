#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char s[100];
	fgets(s,100,stdin);
	int i=0;
	int j=1;
	int k=0;
	char c=0;
	for(i=1;i<strlen(s);i++){
		if(s[i-1]==s[i]){
			j++;
			c=s[i-1];
			if(j>k)
			k=j;
		}
		else{
			j=1;
			
		}

}
	printf("%c(%d)\n", c, k);
}
