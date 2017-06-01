#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmpstructures.h"
#include "bmpfunctions.h"
#define NEW_BMP_FILENAME "changedbmpfile.bmp"

int AreDataCorrect(FILE *bmp_file, int x0, int y0, int x1, int y1)
{
    
	if (bmp_file==NULL) //проверка на корректность открытия файла
	{
		printf("Fail with <BMP_FILENAME>!\n");
		return 0;
	}
    //проверка на корректность координат
	if (x0<0 || y0<0 || x1<0 || y1<0 || (x1-x0)<0 || (y0-y1)<0) 
	{
		printf("\nFai; with <coordinates>. The entered coordinates are not correct!\n");
		fclose(bmp_file);
		return 0;
	}
    /*проверка на то, чтобы разность x и y координат была нечетной, для корректного
      разбиения на 4 равные части*/
   if (((x1-x0)%2==0) || ((y0-y1)%2==0)) 
	{
		printf("\nFail with <coordinates>. Can't devide image on equal parts!\n");
		fclose(bmp_file);
		return 0;
	}
	return 1;
}

char **BmpScan(FILE *bmp_file, BITMAPFILEHEADER *file_head, BITMAPINFOHEADER *image_head)
{
	int i,j,k=0;
  
    /*Корректное определение размера файла*/
	fseek(bmp_file,0,SEEK_END); //перемещает указатель в конец файла
  
	/*возвращает значение указателя текущего положения 
	(значение соответствующее количеству байт от начала файла)*/
	int image_size=ftell(bmp_file); 
  
	fseek(bmp_file,0,SEEK_SET); //перемещает указатель обратно в начало

	char* str=(char*)malloc(sizeof(char)*image_size);
	fread(str, sizeof(char), image_size, bmp_file); //считывание файла

	*file_head=*((BITMAPFILEHEADER*)str); //заголовок с информацией о файле
	str+=sizeof(BITMAPFILEHEADER); //указатель сдвигается на размер заголовка
	*image_head=*((BITMAPINFOHEADER*)str); //заголовок с информацией о изображении
	str-=sizeof(BITMAPFILEHEADER); 
	str+=file_head->bfOffBits; //передвигаем указатель на битовый массив, описывающий само изображение

	int str_len=3*(image_head->biWidth)+(image_head->biWidth%4); //каждый пиксель кодируется 24 битами + выравнивание 
	
  //заполнение двумерного массива
	char** raster=(char**)malloc(sizeof(char*)*image_head->biHeight);
	for(i=0;i<image_head->biHeight;i++)
	{
		raster[i]=(char*)malloc(sizeof(char)*str_len);
		for (j=0;j<str_len;j++)  
			raster[i][j]=str[k++];
	}
	
	return raster;
}

char **BmpSwap(char **raster, int x0, int y0, int x1, int y1)
{
	int i,j;
	int x=(x1+x0)/2; //х координата половины области
	int y=(y0+y1)/2; //y координата половины области
	int weight=(x1-x0)/2;
	int height=(y0-y1)/2;
	
	RGBTRIPLE* pixels_string=NULL; //указатель на строку из пикселей
	RGBTRIPLE temp; 
	
	for (i=y1;i<=y0;i++) 
	{ 
		pixels_string=(RGBTRIPLE*)raster[i]; //char строка приводится к строке пикселей
		for (j=x0;j<=x;j++) 
		{ 
			temp=pixels_string[j]; 
			pixels_string[j]=pixels_string[weight+j+1]; 
			pixels_string[weight+j+1]=temp; 
		} 
	} 
	
	RGBTRIPLE* second_string=NULL;
	for (i=y1;i<=y;i++) 
	{ 
		pixels_string=(RGBTRIPLE*)raster[i]; 
		second_string=(RGBTRIPLE*)raster[height+i+1];
		for(j=x0;j<=x1;j++)
		{
			temp=pixels_string[j];
			pixels_string[j]=second_string[j];
			second_string[j]=temp;
		}
	} 
	
	return raster;
}

void CreateChangedBmp(char** raster, BITMAPFILEHEADER* file_head, BITMAPINFOHEADER* image_head)
{
	int i,j;
	
	FILE* changed_bmp_file=fopen(NEW_BMP_FILENAME,"wb");
	
	//запись заголовков
	fwrite(file_head, sizeof(BITMAPFILEHEADER), 1, changed_bmp_file);
	fwrite(image_head, sizeof(BITMAPINFOHEADER), 1, changed_bmp_file);

	int byte_pixelsnum=3*image_head->biWidth; //число байт содержащих информацию о пикселях
	int byte_lining=image_head->biWidth%4; //число байт для выравнивания

	for(i=0;i<image_head->biHeight;i++)
	{
		fwrite(raster[i], sizeof(char), byte_pixelsnum, changed_bmp_file); //запись растра
		for (j=0;j<byte_lining;j++)
			fputc(0, changed_bmp_file); //дописывание нулей
	}
	
	fclose(changed_bmp_file); 
}
