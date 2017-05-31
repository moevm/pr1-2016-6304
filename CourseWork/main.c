#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "function.h"

int main(void){
    char fname[256];                                                            //Массив под имя файла
    scanf("%[^\n]",fname);
    
    FILE* input;
    if((input=fopen(fname, "r"))==NULL)                                         //Открываем файл для чтения и проверяем на ошибку ввода
    {
        printf("Error opening file");
        return 0; 
    } 
    
    int clsnum;                                                                 //Количество строк/столбцов
    if(isNotSquare(input, &clsnum))                                             //Проверка на квадратичность
    { 
        printf("Fail");
        fclose(input);
        return 0;
    }
    
    char *buff;                                                                 //Буферный  массив
    size_t fsize=filesize(input);                                               //Размер файла
    buff=(char*)malloc(sizeof(char)*fsize);
    readfromfile(input, buff);
    fclose(input);
    
    char*** pointer;                                                            //Массив указателей на слова
    pointer = create(clsnum);
    pointer = recievePointers(buff, pointer, clsnum);                           //Получение указателей
    transpose(pointer, clsnum);                                                 //Транспонирование матрицы
    
    FILE* output=fopen("output.txt", "w");
    FillDaFile(output, pointer, clsnum);
    fclose(output);
    
    free(buff);
    erase(pointer, clsnum);
    return 0;
}

