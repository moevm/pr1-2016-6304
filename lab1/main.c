#include <stdio.h>
#include <string.h>
#include </home/alexey/ok/zapevalov_alexey_6304/get_name.h>
#include </home/alexey/ok/zapevalov_alexey_6304/print_str.h>
#include <stdlib.h>
int main() 
{
char hello[90] = "Hello, ";
char* result;
result = get_name();
print_str(strncat(hello, result, 80));
free(result);
return 0;
}

