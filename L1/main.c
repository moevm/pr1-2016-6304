#include <stdio.h>
#include "get_name.h"
#include <string.h>
#include "print_str.h"
void main(){
    char hello[90] = "Hello, ";
    char* result;
    result = get_name();
    print_str(strncat(hello, result, 80));
   }
