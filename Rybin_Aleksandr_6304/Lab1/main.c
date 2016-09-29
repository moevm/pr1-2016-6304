#include <string.h>
#include "print_str.h"
#include "get_name.h"	
	int main()
		{
		char name[80];
		get_name(name,73);
		strcat(name, " Hello!");
		print_str(name);
		return 0;
		}

