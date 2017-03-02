#include <string.h>
#include "get_name.h"
#include "print_str.h"
	int main()
		{
		char name[80], hello[10]="Hello, ";
		get_name(name);
		print_str(name, hello);
		return 0;
		}
