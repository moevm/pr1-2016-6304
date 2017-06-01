#pragma pack(push, 1)

typedef struct BMFileHeader
{
	unsigned short btype; //тип файла
	unsigned int bsize; //размер файла в байтах
	unsigned int breserved12; //зарезервирован и должен быть нулем
	unsigned int boffset; //Определяет смещение от начала битов точечного рисунка в структуре  BMFileHeader, в байтах
}BMFileHeader;

typedef struct BMInfoHeader
{
	unsigned int size; //размер структуры
	unsigned int width; //ширина изображения в пикселях
	unsigned int height; //высота изображения в пикселях
	unsigned short planes; //Количество плоскостей. Всегда равно 1
	unsigned short bitCount; //Глубина цвета в битах на пиксель
	unsigned int compression; //Тип сжатия. Если компрессия не используется, то флаг имеет значенине BI_RGB
	unsigned int sizelmage; //Размер изображения в байтах
	unsigned int xPelsPerMeter; //Горизонтальное и вертикальное разрешение (в пикселях на метр) соответственно
	unsigned int yPelsPerMeter;
	unsigned int clrUsed; //Количество используемых цветов кодовой таблицы
	unsigned int clrImportant; /*Количество основных цветов. 
	Определяет число цветов, необходимых для отображения изображения. 
	Если значение поля равно 0, то используются все цвета.*/

}BMInfoHeader;

#pragma pack(pop)

typedef struct RGB
{
	char  red;
	char  green;
	char  blue;

} RGB;