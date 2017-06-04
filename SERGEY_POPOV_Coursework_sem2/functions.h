unsigned char* load_BMP_file(char* filename, BITMAPFILEHEADER* bitmapFileHeader, BITMAPINFOHEADER* bitmapInfoHeader);
int save_BMP_file(char* filename, BITMAPFILEHEADER* bitmapFileHeader, BITMAPINFOHEADER* bitmapInfoHeader, unsigned char* bitmapImage);
void black_BMP_except_square(unsigned char* bitmapImage, BITMAPINFOHEADER* bitmapInfoHeader, int x0, int y0, int x1, int y1);
