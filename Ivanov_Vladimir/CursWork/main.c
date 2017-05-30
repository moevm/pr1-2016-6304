#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gauss.h"

/*Функция для определения размера матрицы*/
void Size(char *s, int *str, int *col){
    int newstr=0,i=0,all=0;
    /*Считаем количество всех элементов в матрице и количество строк*/
    while(s[i]!='\0'){
        if(s[i]==' ')
            all++;
        if (s[i]=='\n'){
            all++;
            newstr++;
        }
        i++;
    }
    *str=newstr+1;//т.к. в предыдущем цикле не учтена последня строка
    *col=(all+1)/(newstr+1); //Т.к. последний символ также не учитывается
}


int main(){
    char s[100];
    char symb;
    int i=0,str=0,col=0,rank;
    /*Открытие файла для чтения и посимвольная запись его содержимого в строку*/
    FILE *input_file=fopen("./input_file.txt","r");
    while(fscanf(input_file,"%c",&symb)>0)
        s[i++]=symb;
    Size(s,&str,&col);//Определение размера матрицы
    /*Нахождение ранга матрицы и проверка на квадратную матрицу*/
    rank=calc_rank(s,str,col);
    if (rank==-1){
        printf("Fail\n");
        fclose(input_file);
        return 0;
    }
    /*Открытие/создание файла для записи*/
    FILE *output_file=fopen("./output_file.txt","w");
    fprintf(output_file,"%d",rank);
    /*Закрытие открытых файлов*/
    fclose(input_file);
    fclose(output_file);
    return 0;
}
