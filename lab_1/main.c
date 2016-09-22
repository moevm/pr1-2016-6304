#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include </home/bi/laba/get_name.h>
#include </home/bi/laba/print_str.h>

int main(){
  char hello[90] = "Hello, ";
  char* result;
  result = get_name();
  print_str(strncat(hello, result, 80));
  free(result);
  return 0;
}
