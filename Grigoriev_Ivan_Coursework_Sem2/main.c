/*
Курсовая работа. Второй семестр. Григорьев Иван гр.6304
----------------------------------------------------------------
Программа считывает bmp файл, делит заданную область этого файла
на 4 равные части, меняет их местами по диагонали и записывает
результат в новый bmp файл.
----------------------------------------------------------------
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LIMIT 265
#define BMP_FILENAME "bmpfile.bmp"
#define NEW_BMP_FILENAME "changedbmpfile.bmp"

int main()
{
        FILE* bmp_file=fopen(BMP_FILENAME, "rb");
        BITMAPFILEHEADER file_head; //заголовок с информацией о файле
	BITMAPINFOHEADER image_head; //заголовок с информацией о изображении
        
	int a,b;
	int x0=-1,y0=-1,x1=-1,y1=-1;
	printf("Coordinates of the left upper corner (x0, y0): ");
	scanf("%d %d", &x0, &y0);
	printf("Coordinates of the right bottom corner (x1, y1): ");
	scanf("%d %d", &x1, &y1);
	
	//Проверка введенных данных
	if(!AreDataCorrect(bmp_file, x0, y0, x1, y1))
	    return 0;
	
	if((x1-x0)%2==0) //если разность координат четная
		a=1;
	if((y0-y1)%2==0)
		b=1;
	
	/*Создание и заполнение двумерного массива символов информацией о пикселях bmp изображения*/
	char** raster=BmpScan(bmp_file, &file_head, &image_head); 
	fclose(bmp_file);
	
	if (image_head.biWidth<(x1+1) || image_head.biHeight<(y0+1)) //Если введенная область больше самого изображения
	{
		printf("Fail with <entered area>\n");
		return 0;
	}
	
	CreateChangedBmp(BmpSwap(raster, x0, y0, x1, y1, a, b), &file_head, &image_head);
	printf("Bmp file /%s/ successfully changed in the same directory with new name /%s/\n\n", BMP_FILENAME, NEW_BMP_FILENAME);
	free(raster);
  return 0;
}
