#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int comp (const char * w1, const char * w2) //функция для сравнения элемента массива с искомым словом 
{ 
return strcmp((char*)w1, (char*)w2); //сравнение 2х строк
} 

int main() { 
char txt[1000]; //массив на 1000 символов 
char wtxt[1000][1000]; //массив строк для записи отдельных слов 
char sep[10]=" ."; //разделители 
char str[30]; //искомое слово 
char *ptxt,*bs; //указатели
int a=0; //счетчик 

fgets(txt,1000,stdin); //считываем массив 
fgets(str,30,stdin); //считываем слово 

ptxt = strtok(txt,sep); //делим считанный массив на массив из строк, состоящих из отдельных слов 
while (ptxt != NULL) { 
strcpy(wtxt[a],ptxt); 
ptxt = strtok (NULL,sep); 
a++; 
} 

qsort(wtxt, a, 1000, comp); //сортируем слова 

bs = (char*)bsearch(&str, wtxt, a, 1000, comp); // Если массив не содержит ключа, то возвращается нулевой указатель. 
if (bs != NULL) 
printf("exists\n"); 
else 
printf("doesn't exist\n"); 

// put your code here 
return 0; 
}
