int CheckingErrors(FILE* input_file,int x0,int y0,int x1,int y1);

char** LoadBmp(FILE* input_file, BMFileHeader* FileInfo, BMInfoHeader* ImageInfo);

char** AreaRotate(char** raster, int x0, int y0, int x1, int y1);

void NewBmp(char* input_file, char** raster, BMFileHeader* FileInfo, BMInfoHeader* ImageInfo);