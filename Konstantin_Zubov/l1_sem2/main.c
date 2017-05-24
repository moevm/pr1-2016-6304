#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);

}
int main() {
char s[1000][1000];
char str[30];
int i=0;

fgets (s, 1000, stdin);
fgets (str, 30, stdin);
char * pch = strtok (s," .") ;

  while (pch)
  {
      strcpy(s[i], pch);
      pch = strtok (NULL, " .");
      i++;
  }


qsort(s, i, 1000, compare);

char* ptrItem = (char*)bsearch(str, s, i, 1000, compare);

if (ptrItem == NULL)
    printf("doesn't exist\n");
else
    printf("exists\n");

system("pause");

	return 0;
}
