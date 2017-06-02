int AreDataCorrect(FILE *bmp_file, int x0, int y0, int x1, int y1); 

char **BmpScan(FILE *bmp_file, BITMAPFILEHEADER *file_head, BITMAPINFOHEADER *image_head);

char **BmpSwap(char **raster, int x0, int y0, int x1, int y1, int a, int b);

void CreateChangedBmp(char** raster, BITMAPFILEHEADER* file_head, BITMAPINFOHEADER* image_head);
