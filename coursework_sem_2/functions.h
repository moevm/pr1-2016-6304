int correctionCheck1(FILE *bmpFile, char* bmpFileN);

int correctionCheck2(FILE *bmpFile, int x0, int y0, int x1, int y1);

char **bmpScan(FILE *bmpFile, bmHeader *BMhead, DIBheader *DIBhead);

char **Diags(char **pixArr, int x0, int y0, int x1, int y1);

char* createNewBmp(char** pixArr, bmHeader* BMhead, DIBheader* DIBhead);
