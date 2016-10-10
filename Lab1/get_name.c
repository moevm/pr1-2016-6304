#include <stdio.h>
const char * get_name(char* name, int lenth_name)
	{
	char ch;
	int i = 0;
	while (((ch = getchar()) != '\n') && (i<lenth_name))
		{
		name[i++] = ch;
		}
	
	return name;
	}

