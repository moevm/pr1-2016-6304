
// Функция, которая проверяет корректность введенных данных

int error_checking(int x0, int x1, int y0, int y1, FILE* bmp_file);

//Функция, считывающая информацию о bmp файле

char** get_bmp_file_info(FILE* bmp_file, bitmap_file_header* bfh, bitmap_info_header* bih);

//Функция, создающая новый файл и записывающая в него обрезанное изображение 

void create_new_bmp(char* name, char** pixels, bitmap_file_header* bfh, bitmap_info_header* bih, int x0, int y0, int x1, int y1); 
