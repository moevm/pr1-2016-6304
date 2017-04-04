//Vipolnil: Ivanov Vladimir 6304
//Zadanie predstavleno v otchete

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int funccmp(const void * x1, const void * x2)
{
    return strcmp((char*)x1,(char*)x2);
}
int main() {
    char mass[1000];        //text
    fgets(mass,1000,stdin);
    char str[30];       //iskomoe slovo
    fgets(str,30,stdin);
    char *k;
    int i=0;
    char dopmass[1000][1000]; // dopolnitel'niy massiv dlya hraneniya otdel'nih slov
    k=strtok(mass," .");           
    while (k!=NULL){            //razbienie na slova
        strcpy(*(dopmass+i), k);
        k=strtok(NULL," .");
        i++;
    }
    qsort(dopmass,i,1000,funccmp); //sortirovka 
    char * ptr = (char*) bsearch(str, dopmass, i, 1000, funccmp); //poisk (binarniy) str v massive
    if (ptr != NULL)
        printf("exists");
    else printf("doesn't exist");
  return 0;
}