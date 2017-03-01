#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char string[100], c;
  
	scanf("%s %c", string, &c);
        
	int length=strlen(string);
        
	for (int i=0; i<length; i++)
	{
	        if (c != string[i])
		printf("%c", string[i]);
	}
}
