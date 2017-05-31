/* Yaroslav Piskunov, gr 6304
Course Work - Matrix Multiplier - functions file*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
 
#define MAX_FILESIZE 10000


int** convertMatrix(char* string, int colomns, int strings) {

int i,j;

int** matrix = (int**)malloc(strings*sizeof(int*));
for (i=0; i<strings; i++)
matrix[i] = (int*)malloc(colomns*sizeof(int));

for (i=0; i<strlen(string); i++)
if ((string[i]==' ')||(string[i]=='\n'))
string[i] = '\n';



char** m = (char**)malloc(strings*colomns*sizeof(char*));
m[0] = strtok(string, "\n" );

for (i=1; i<strings*colomns; i++)
m[i] = strtok(NULL, "\n");

int k = 0;

for (i=0; i<strings; i++)
for (j=0; j<colomns; j++)
matrix[i][j] = atoi (m[k++]);




return (matrix);
}


int** multiply(char* matrix1, char* matrix2, int* data){

int i, j, z;

int** Imatrix1 = convertMatrix(matrix1, data[0], data[1]);
int** Imatrix2 = convertMatrix(matrix2, data[2], data[3]);

int** matrix = (int**)malloc(data[1]*sizeof(int*));
for(i=0; i<data[1]; i++)
matrix[i] = (int*)malloc(data[2]*sizeof(int));

for(i=0; i<data[1]; i++)
for(j=0; j<data[2]; j++){
matrix[i][j] = 0;
for(z=0; z<data[2]; z++)
matrix[i][j] = matrix[i][j] + Imatrix1[i][z]*Imatrix2[z][j];
}


return (matrix);
}


 
int checkValid(int Colomns1, int Strings1, int Colomns2, int Strings2, int elements1, int elements2){

if ((elements1!=Colomns1*Strings1)&&(elements2!=Colomns2*Strings2)) return 4;
if (elements1!=Colomns1*Strings1) return 1;
if (elements2!=Colomns2*Strings2) return 2;
if (Colomns1!=Strings2) return 3;

return 0;
}

 
int* SizeAndValid (char* matrix1, char* matrix2) {
 
int i,j;
int Colomns1 = 1;
int Colomns2 = 1;
int Strings1 = 1;
int Strings2 = 1;
int elements1 = 1;
int elements2 = 1;
 
for(i=0; i<strlen(matrix1); i++){
if(matrix1[i]=='\n')
Strings1++;
 
if((matrix1[i]==' ')||(matrix1[i]=='\n')){
elements1++;
Colomns1++;
}
}

Colomns1 = Colomns1 / Strings1;


for(i=0; i<strlen(matrix2); i++) {
if (matrix2[i]=='\n')
Strings2++;

if((matrix2[i]==' ')||(matrix2[i]=='\n')){
elements2++;
Colomns2++;
}
}

Colomns2 = Colomns2 / Strings2;


int* dataArray = (int*)malloc(5*sizeof(int));
dataArray[4] = checkValid(Colomns1, Strings1, Colomns2, Strings2, elements1, elements2);
dataArray[0] = Colomns1;
dataArray[1] = Strings1;
dataArray[2] = Colomns2;
dataArray[3] = Strings2;


return (dataArray);
}
 
char* getMatrix2(char* PrimalString) { 
 
int i, pointer;
for(i = 0; i<strlen(PrimalString); i++)
if ((PrimalString[i]=='\n')&&(PrimalString[i]==PrimalString[i+1])&&(PrimalString[i+2]==PrimalString[i]))
pointer = i;
 
PrimalString = PrimalString + pointer + 3;
 
return(PrimalString);
}
 
 
char* getMatrix1(char* PrimalString) { 

int i, pointer;
for(i = 0; i<strlen(PrimalString); i++)
if ((PrimalString[i]=='\n')&&(PrimalString[i]==PrimalString[i+1])&&(PrimalString[i+2]==PrimalString[i]))
pointer = i;
 
PrimalString[pointer] = '\0';
 
return(PrimalString);
}
