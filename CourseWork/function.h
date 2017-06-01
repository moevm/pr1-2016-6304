int filesize(FILE*); 
void readfromfile(FILE *, char*);
void FillDaFile(FILE*, char***, int);

int isNotSquare(FILE*, int*);

void transpose(char***, int);

char*** create(int);
char*** recievePointers(char*, char***, int);

void swap(char**, char**);

void erase(char ***, int);