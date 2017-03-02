#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_str.h"
#include "get_name.h"
int main(){
    char hello[90] = "Hello, ";
    char* result;
    result = get_name();
    print_str(strncat(hello, result, 90));
    free(result); /* free the memory */
    return 0;
}
