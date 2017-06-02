#pragma pack(push, 1)

typedef struct tagBITMAPFILEHEADER 
{ 
   unsigned short bfType; //определяет тип файла. Здесь он должен быть BM. 
   unsigned int bfSize; //размер самого файла в байтах
   unsigned short bfReserved1; //зарезервирован и должен быть нулем
   unsigned short bfReserved2; //зарезервирован и должен быть нулем
   unsigned int bfOffBits; /*показывает, где начинается сам битовый массив относительно начала файла 
   (или от начала структуры BITMAPFILEHEADER), который и описывает картинку*/
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
   unsigned int biSize; //размер самой структуры
   unsigned int biWidth; //задает ширину картинки в пикселях
   unsigned int biHeight; //задает высоту картинки в пикселях
   unsigned short biPlanes; //задает количество плоскостей, пока оно всегда устанавливается в 1
   unsigned short biBitCount; //количество бит на один пиксель
   unsigned int biCompression; //тип сжатия, если сжатия нет, то этот флаг надо устанавливать в BI_RGB
   unsigned int biSizeImage; /*обозначает размер картинки в байтах, eсли изображение несжато 
   (то есть предыдущее поле установлено в BI_RGB), то здесь должен быть записан ноль*/
   unsigned int biXPelsPerMeter; /*горизонтальное разрешение (в пикселях на метр) конечного устройства, 
   на которое будет выводиться битовый массив (растр)*/
   unsigned int biYPelsPerMeter; /*вертикальное разрешение (в пикселях на метр) конечного устройства, 
   на которое будет выводиться битовый массив (растр)*/
   unsigned int biClrUsed; //определяет количество используемых цветов из таблицы
   unsigned int biClrImportant; /*это количество важных цветов. Определяет число цветов, 
   которые необходимы для того, чтобы изобразить рисунок. 
   Если это значение равно 0 (как это обычно и бывает), то все цвета считаются важными*/
} BITMAPINFOHEADER;

#pragma pack(pop)

typedef struct RGBTRIPLE
{
	char  rgbBlue;
	char  rgbGreen;
	char  rgbRed;
} RGBTRIPLE;
