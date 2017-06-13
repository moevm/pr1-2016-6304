#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int main(void){
    char fname[256];
    scanf("%[^\n]",fname);
    
    FILE* input;
    if((input=fopen(fname, "r"))==NULL)
    {
        perror("Error opening file");
        return 0; 
    } 
    
    int clsnum;
    if(isNotSquare(input, &clsnum))
    { 
        printf("Fail");
        fclose(input);
        return 0;
    }
    
    char* buff;
    int* space=(int*)calloc(clsnum,sizeof(int));
    int fsize=filesize(input);
    buff=(char*)malloc(sizeof(char)*fsize);
    readfromfile(input, buff, space);
    fclose(input);
    
    char*** pointer;
    pointer = create(clsnum);
    pointer = recievePointers(buff, pointer, clsnum);
    transpose(pointer, clsnum);
    
    FILE* output;
    if ((output=fopen("output.txt", "w"))==NULL)
    { 
        perror("Error opening output file");
    }
    FillDaFile(output, pointer, clsnum, space);
    if (ferror(output))
    {
        perror("Write error");
    }
    fclose(output);
    
    free(buff);
    erase(pointer, clsnum);
    
    return 0;
}