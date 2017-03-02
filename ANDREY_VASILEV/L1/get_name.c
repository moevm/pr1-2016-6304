#include <stdio.h>
const char * get_name(char* name)
	{
	char ch;
	int i = 0;
	while (((ch = getchar()) != '\n'))
	{
		name[i] = ch;
		i +=1;
	}
	name[i] = '\0';
	return name;
	}
