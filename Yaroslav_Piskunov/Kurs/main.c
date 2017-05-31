/*Yaroslav Piskunov, gr 6304
CourseWork - Matrix Multiplier - main file*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
 
#define MAX_FILESIZE 10000


 
 
int main () {
 
printf("Matrix Multiplier v1.0\n");
printf("Hello, please enter path to the input file\n");
 
char* in_path = (char*)malloc(10000*sizeof(char));
fgets(in_path, 10000, stdin);
*(strchr(in_path, '\n')) = '\0';
 
printf("Now enter path to the output file\n");
 
char* out_path = (char*)malloc(10000*sizeof(char));
fgets(out_path, 10000, stdin);
*(strchr(out_path, '\n')) = '\0';
 
FILE* in_file = fopen(in_path, "r");
 
if (in_file==NULL){
printf("Error 404: File Not Found\n");
return 0;
}
 
char ch;
int i = 0;
char* PrimalString = (char*)malloc(10000*sizeof(char));
 
while ((ch = fgetc(in_file))!=EOF)
PrimalString[i++] = ch;
PrimalString[i-1] = '\0';
 
char* matrixString1 = (char*)getMatrix1(PrimalString);
char* matrixString2 = (char*)getMatrix2(PrimalString);
 
int* data = SizeAndValid(matrixString1, matrixString2); 
switch (data[4]) {

case 1:
printf ("Error. Failed with Matrix 1\n");
return 0;
break;

case 2:
printf ("Error. Failed with Matrix 2\n");
return 0;
break;

case 3: 
printf ("Error. Can't multiply: invalid size\n");
return 0;
break;

case 4: 
printf ("Error.\nFailed with Matrix 1.\nFailed with Matrix 2.\n");
return 0;
break;
}



int** newMatrix = multiply(matrixString1, matrixString2, data);
int j;

FILE* out_file = fopen(out_path, "wb");

for (i=0; i<data[1]; i++){
for (j=0; j<data[2]; j++)
fprintf(out_file, "%d ", newMatrix[i][j]);
fprintf(out_file, "\n");
}

 free (in_path);
 free (out_path);
 free (PrimalString);
 
 for (i=0; i<data[1]; i++)
  free (newMatrix[i]);
free (newMatrix);
free (matrixString1);
free (matrixString2);
free (data);
 
fclose (in_file);
fclose (out_file);
return 0;
}
