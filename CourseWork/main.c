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
        printf("Error opening file");
        return 0; 
    } 
    
    int clsnum;
    if(isNotSquare(input, &clsnum))
    { 
        printf("Fail");
        fclose(input);
        return 0;
    }
    
    char *buff; 
    int fsize=filesize(input);
    buff=(char*)malloc(sizeof(char)*fsize);
    readfromfile(input, buff);
    fclose(input);
    
    char*** pointer;
    pointer = create(clsnum);
    pointer = recievePointers(buff, pointer, clsnum);
    transpose(pointer, clsnum);
    
    FILE* output=fopen("output.txt", "w");
    FillDaFile(output, pointer, clsnum);
    fclose(output);
    
    free(buff);
    erase(pointer, clsnum);
    return 0;
}

