#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

//Функция для определения размера файла
size_t filesize(FILE* input){
    fseek(input,0,SEEK_END); 
    size_t size = ftell(input); 
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

//Функция считывания данных из файла
void readfromfile (FILE * fp, char * p){
    char c;
    int i=0;
    rewind(fp);
    while((c=fgetc(fp))!=EOF)
        if(c=='\r') p[i++]=' ';
            else
        p[i++]=c;
        
}

//Функция для транспонирования матрицы
void transpose(char*** ar, int n){
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++)
            swap(&ar[i][j], &ar[j][i]);
}

//Функция обмена значений указателей
void swap(char **a, char **b){
    char *c = *a;
	 *a = *b;
	 *b = c;
}

//Функция создания двумерного массива указателей
char*** create(int num){
    char *** temp = (char ***) malloc(num * sizeof(char **));
    for (int i=0; i<num; i++)                                   
        temp[i] = (char **) malloc(num * sizeof(char*));        
    return temp;   
}

//Функция записи указателей в массив
char*** recievePointers(char* str, char*** pointer, int num){ // ИСПРАВИТЬ - НЕПРАВИЛЬНЫЙ УКАЗАТЕЛЬ
    pointer[0][0]=strtok(str, " \n");
    for(int i=1; i<num; i++)
        pointer[0][i]=strtok(NULL," \n");
    for(int i=1; i<num; i++)
        for(int j=0; j<num; j++)
            pointer[i][j]=strtok(NULL," \n");
    return pointer;
}

//Функция очистки массива
void erase(char *** p, int num){
    for (int i=0; i<num; i++)
        free(p[i]);
    free(p);
}

//Функция записи в файл
void FillDaFile(FILE* out, char*** ar, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            fprintf(out," %s", ar[i][j]);
        fprintf(out, "\r\n");
    }
}