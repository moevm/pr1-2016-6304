#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

//Функция для определения размера файла
int filesize(FILE* input){
    fseek(input,0,SEEK_END); 
    int size = ftell(input); 
    return size;
}

//Функция проверки на квадратичность
int isNotSquare(FILE *in, int *size){
    int str = 0;
    int col = 0;
    int c;
    while((c=fgetc(in))!=EOF)
    {
        if (c==' ')
            str++;
        if (c=='\n')
            col++;
    }
    col++;
    str/=col;
    str+=1;
    if (str!=col)
        return 1;
    else
    {
        *size=str;
        return 0;
    }
}

//Функция обмена значений указателей
void swap(char **a, char **b){
    char *c = *a;
    *a = *b;
    *b = c;
}

//Функция считывания данных из файла
void readfromfile (FILE * fp, char * p, int* space){
    char c;
    int num = 0;
    int z = 0;
    int i=0;
    rewind(fp);
    while((c=fgetc(fp))!=EOF)
    {
        if(c!='\r')
        {
            p[i++]=c;
            num++;
        }
        if (c == ' ' || c == '\n')
        {
            space[z] = (num > space[z])? num-1 : space[z];
            num = 0;
            if (c=='\n')
                z++;  
        }
    }
    space[z] = (num > space[z])? num : space[z];
}

//Функция для транспонирования матрицы
void transpose(char*** ar, int n){
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++)
            swap(&ar[i][j], &ar[j][i]);
}

//Функция создания двумерного массива указателей
char*** create(int num){
    char *** temp = (char ***) malloc(num * sizeof(char **));
    for (int i=0; i<num; i++)
        temp[i] = (char **) malloc(num * sizeof(char*));   
    return temp;   
}

//Функция записи указателей в массив
char*** recievePointers(char* str, char*** pointer, int num){
    pointer[0][0]=strtok(str, " \n");
    for(int i=1; i<num; i++)
        pointer[0][i]=strtok(NULL," \n");
    for(int i=1; i<num; i++)
        for(int j=0; j<num; j++)
            pointer[i][j]=strtok(NULL," \n");
    return pointer;
}

//Функция очистки массива
void erase(char ***array3d, int num){
    for (int i = 0; i < num; i++){
        free(array3d[i]);
    }
    free(array3d);
}

//Функция записи в файл
void FillDaFile(FILE* out, char*** ar, int n, int* space){
    int z = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            fprintf(out," %*s ",space[z++], ar[i][j]);
        fprintf(out, "\r\n");
        z=0;
    }
}