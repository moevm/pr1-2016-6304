#pragma pack(push, 1)

typedef struct bmHeader
{
   unsigned short signature; //определяет тип файла. Здесь он должен быть BM.
   unsigned int fileSize; //размер самого файла в байтах
   unsigned short Reserved1; //зарезервирован и должен быть нулем
   unsigned short Reserved2; //зарезервирован и должен быть нулем
   unsigned int offsetToPixels; /*показывает, где начинается сам битовый массив относительно начала файла
   (или от начала структуры BITMAPFILEHEADER), который и описывает картинку*/
} bmHeader;

typedef struct DIBheader
{
   unsigned int DIBSize; //размер самой структуры
   unsigned int width; //задает ширину картинки в пикселях
   unsigned int height; //задает высоту картинки в пикселях
   unsigned short planes; //задает количество плоскостей, пока оно всегда устанавливается в 1
   unsigned short bitCount; //количество бит на один пиксель
   unsigned int compression; //тип сжатия, если сжатия нет, то этот флаг надо устанавливать в BI_RGB
   unsigned int sizeImage; /*обозначает размер картинки в байтах, eсли изображение несжато
   (то есть предыдущее поле установлено в BI_RGB), то здесь должен быть записан ноль*/
   unsigned int xPixPerMeter; /*горизонтальное разрешение (в пикселях на метр) конечного устройства,
   на которое будет выводиться битовый массив (растр)*/
   unsigned int yPixPerMeter; /*вертикальное разрешение (в пикселях на метр) конечного устройства,
   на которое будет выводиться битовый массив (растр)*/
   unsigned int colourUsed; //определяет количество используемых цветов из таблицы
   unsigned int colourImportant; /*это количество важных цветов. Определяет число цветов,
   которые необходимы для того, чтобы изобразить рисунок.
   Если это значение равно 0 (как это обычно и бывает), то все цвета считаются важными*/
} DIBheader;



typedef struct RGB
{
	char  Blue;
	char  Green;
	char  Red;
} RGB;
#pragma pack(pop)
