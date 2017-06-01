#pragma pack(push, 1)


typedef struct bitmap_file_header //заголовок файла
 {
   unsigned short    bf_type;              // тип файла
   unsigned int      bf_size;              //размер файла в байтах
   unsigned short    bf_reserved1;         //зарезервированы и должны быть нулями
   unsigned short    bf_reserved2;
   unsigned int      bf_off_bits;          //показывает, где начинается сам битовый массив относительно начала файла
} bitmap_file_header;




typedef struct bitmap_info_header  //структура файла (информация об изображении)
 {
   unsigned int      bi_size;              //размер самой структуры
   unsigned int      bi_width;             //ширина картинки (в пикселях)
   unsigned int      bi_height;            //высота картинки (в пикселях)
   unsigned short    bi_planes;            //количество плоскостей (устанавливается в 1)
   unsigned short    bi_bit_count;         //количество бит на один пиксель
   unsigned int      bi_compression;       //тип сжатия(BI_RGB, если картинка не сжата)
   unsigned int      bi_size_image;        // размер картинки (в байтах), если изображение не сжато, то должен быть записан ноль
   unsigned int      bi_X_pels_per_meter;  //горизонтальное разрешение (в пикселях на метр) устройства, на который будет выводиться битовый массив (растр)
   unsigned int      bi_Y_pels_per_meter;  //вертикальное разрешение (в пикселях на метр)
   unsigned int      bi_color_used;        //определяет кол-во используемых цветов из таблицы (если значение 0 - то используется максимальное кол-во цветов, которые разрешены значением biBitCount)
   unsigned int      bi_color_important;   //кол-во важных цветов, определяет число цветов, которые необходимы для того, чтобы изобразить рисунок (если значение 0 - то все цвета важные)
} bitmap_info_header;
#pragma pack(pop)
 



typedef struct rgb_triple   //структура для описания одного пикселя, 3 байта определяют 3 компонента цвета
{
   char    rgb_blue;
   char    rgb_green;
   char    rgb_red;
} rgb_triple;

