#ifndef FUNCTION_H
#define FUNCTION_H

int filesize(FILE*); 
void readfromfile(FILE *, char*, int*);
void FillDaFile(FILE*, char***, int, int*);

int isNotSquare(FILE*, int*);

void transpose(char***, int);

char*** create(int);
char*** recievePointers(char*, char***, int);

void swap(char**, char**);

void erase(char ***, int);
#endif	// FUNCTION_H