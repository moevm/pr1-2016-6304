#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Swaps.h"

/*Функция, меняющая значения двух элементов*/
void swap(float* prevEl, float* newEl){
    float c=*prevEl;
    *prevEl=*newEl;
    *newEl=c;
}

/*Функция меняет значения элементов одной строки с соответсвующими элементами
другой строки*/
void swapstr(float* mass[], int prevStr, int newStr, int col){
    int i;
    for(i=0;i<col;i++){
        swap(&mass[prevStr][i],&mass[newStr][i]);
    }
}
/*Функция проверяет значение исходного элемента, если оно не нулевое,то ничего не делает и возращает 0,
иначе проверяет значения элементов под ним, если есть ненулевые, то меняет местами значения элементо
исходной строки и выбранной и возращает 0, иначе увеличивает счётчик сдвига и проделыает те же операции
с элементом, находящимся спара от исходного, если он существует, и возвращает значение сдвига*/
int FinalSwap(float** mass,int i,int newi, int str){
  int shift=0,j;
  if(newi<str && mass[i][newi]==0 ){
    for(j=i+1;j<str;j++)
      if(mass[j][newi]!=0){
        swapstr(mass,i,j,str);
      }
  }
  if(mass[i][newi]==0){
    shift++;
    return shift+FinalSwap(mass,i,newi+1,str);
  }
  return shift;
}
