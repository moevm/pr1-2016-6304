#include <string.h>
<<<<<<< HEAD
#include "print_str.h"
#include "get_name.h"	
=======
#include "get_name.h"
#include "print_str.h"
>>>>>>> de1d2125e6834bbc48a4f12a753a527654a21707
	int main()
		{
		char name[80];
		get_name(name,73);
		strcat(name, " Hello!");
		print_str(name);
		return 0;
		}

