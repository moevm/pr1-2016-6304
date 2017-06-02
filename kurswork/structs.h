#pragma pack(push, 1)

typedef struct BMFileHeader
{
	    unsigned short btype;
	    unsigned int bsize;
	    unsigned int breserved12;//зарезервированные поля, должны содержать ноль
	    unsigned int boffset;//положение пиксельных данных относительно начала данной структуры
}BMFileHeader;

typedef struct BMInfoHeader
{
	unsigned int size;//размер структуры
	unsigned int width;//ширина изображения
	unsigned int height;//высота
	unsigned short planes;//количество плоскостей
	unsigned short bitCount;//количество бит на один пиксель
	unsigned int compression;//указывает на способ хранения пикселей
	unsigned int sizelmage;//размер пиксельных данных в байтах
	unsigned int xPelsPerMeter;//количество пикселей на метр по горизонтали 
	unsigned int yPelsPerMeter;//по вертикали
	unsigned int clrUsed;//размер таблицы цветов в ячейках
	unsigned int clrImportant;//количество ячеек от начала таблицы цветов до последней используемой(включая её саму)

}BMInfoHeader;

typedef struct RGB
{
        char  red;
        char  green;
        char  blue;
} RGB;

#pragma pack(pop)

