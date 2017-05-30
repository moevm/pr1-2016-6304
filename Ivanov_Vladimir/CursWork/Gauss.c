#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Swaps.h"
#include "Gauss.h"

/*Функция, которая считает ранг матрицы, приведённой к
ступенчатому виду*/
int find_rang(int str, int *rank, float **mass){
    int i,j;
    for(i=0;i<str;i++)
        for(j=0;j<str;j++)
            if (mass[i][j]==1){
                (*rank)++;
                j=str;
        }
}
/*Запись элементов из строки в матрицу*/
void creation_matrix(char* s, float** mass,int str){
    int i=0,j=0;
    char *k=strtok(s," \n");
    while(k){
        if(j==str){
            i++;
            j=0;
        }
        mass[i][j]=atoi(k);
        j++;
        k=strtok(NULL," \n");
    }
    
}
/*Функция, которая с помощью метода Гаусса находит ранг матрицы */
int calc_rank(char *s, int str, int col){
    if(str!=col) //Проверка на квадратную матрицу
        return -1;
    int i=0,j=0,p,rank=0, shift;
    /*Выделение памяти для хранения и изменения матрицы*/
    float **mass=(float**)malloc(str*sizeof(float*));
    for(p=0;p<str;p++)
        mass[p]=(float*)malloc(col*sizeof(float));
    
    /*Запись элементов в матрицу*/
    creation_matrix(s,mass,str);
    /*Приведение матрицы к ступенчатому виду методом Гаусса*/
    for(i=0;i<str;i++){
        
        /*Свап значений i-ой строки с одной из нижних, если исходный элемент (i,i) нулевой,
        и определение сдвига для будущих действий, если свап строк не помогает */
        shift=FinalSwap(mass,i,i,str);
        
         /*Деление каждого элемента строки, начиная с конца, на первый ненулевой элемент i-ой строки*/
        for(j=1;j<str+1;j++){
            if(i+shift<str)//Проверка на наличи ненулевого элемента
                mass[i][col-j]=mass[i][col-j]/mass[i][i+shift];
        }
        
        /*Сложение элементов i-ой строки, умноженных на элементы следующих строк того же столбца,
        с соотв. элементами других строк*/
        for(j=i+1;j<str;j++){
            for(p=i;p<str;p++){
                if(i+shift<str)
                    mass[j][col-p-1+i]= mass[j][col-p-1+i]-(mass[i][col-p-1+i]*mass[j][i+shift]);
            }
        }
    }
    /*Подсчёт количества ненулевых строк, число которых равно рангу матрицы*/
    find_rang(str,&rank,mass);
    for(i=0;i<str;i++)
        free(mass[i]);
    free(mass);
    return rank;
}
