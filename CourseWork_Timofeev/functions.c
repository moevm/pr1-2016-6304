#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BmpStructures.h"
#include "functions.h"

int CheckingErrors(FILE* input_file,int x0,int y0,int x1,int y1)
{
    if (input_file == NULL) //Если файл пустой
    {
        printf("Fail with openning input_file\n");
        return 0;
    }
    if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x1 - x0 < 0 || y0-y1 < 0){ /*Если координаты отрицательны 
    или заданы не правильно*/
        printf("Fail with coordinates\n"); 
        fclose(input_file); //Закрываем открытый файл
        return 0;
    }
    if ((x1 - x0) != (y0 - y1)) //Если область не квадратная
    {
        printf("Fail with field\n");
        fclose(input_file); //Закрываем открытый файл
        return 0;
    }
}


char** LoadBmp(FILE* input_file, BMFileHeader* FileInfo, BMInfoHeader* ImageInfo)
{   int i,j,k;
	fseek(input_file,0,SEEK_END);//устанавливаем позицию в конец файла
	int BmpSize = ftell(input_file);//размер файла (Для бинарных потоков, возвращается значение соответствующее количеству байт от начала файла)
	fseek(input_file,0,SEEK_SET);//перемещение указателя в начало

	char* buffer = (char*)malloc(sizeof(char)*BmpSize); //Выделяем память под строку для работы с файлом

	fread(buffer,sizeof(char),BmpSize,input_file); //Считываем файл
	*FileInfo = *((BMFileHeader*)buffer); //Cчитываем заголовок с информацией о файле
	buffer += sizeof(BMFileHeader); //Смещаем указатель
	*ImageInfo = *((BMInfoHeader*)buffer); //Считываем информацию об изображении
	buffer -= sizeof(BMFileHeader); 
	buffer += FileInfo -> boffset; //Смещаем указатель на начало изображение

	int len = 3*ImageInfo->width + (ImageInfo->width%4); //Пиксели кодируются 3мя байтами, выравнивание
	char** raster = (char**)malloc(sizeof(char*)*ImageInfo->height); //Заполняем массив
	for(i=0; i < ImageInfo->height; i++)
	{
		raster[i] = (char*)malloc(sizeof(char)*len);
		for(j=0; j < len; j++)
		raster[i][j] = buffer[k++];
	}
	return raster;
}

char** AreaRotate(char** raster, int x0, int y0, int x1, int y1)
{
	RGB* str = NULL;
	int i,j,k;
	RGB** area = (RGB**)malloc(sizeof(RGB*)*(y0-y1+1)); //Выделяем память под массив строк
	for ( i = 0; i <=y0-y1; i++) //Заполняем двумерный массив
	{
		area[i] = (RGB*)malloc(sizeof(RGB)*(x1-x0+1));	
		memmove(area[i], raster[y1+i]+x0*sizeof(RGB), sizeof(RGB)*(x1-x0+1));
	}
	for ( j = y1; j <= y0; j++) //Ограничиваем область заданными координатами
	{
		str = (RGB*)raster[j];
		for( k = x0; k <=x1; k++)
		{
			str[k]=area[k-x0][y0-j]; //Поворачиваем область на 90 градусов		
		}
	}
	free(area);
	return raster;
}

void NewBmp(char* input_file, char** raster, BMFileHeader* FileInfo, BMInfoHeader* ImageInfo)
{   
    int i,j ;
	*(strchr(input_file, '.')) = '\0';
	strcat(input_file, "rotated.bmp");
	FILE* output_file = fopen(input_file,"wb");
	//запись заголовков
	fwrite(FileInfo,sizeof(BMFileHeader), 1, output_file);
	fwrite(ImageInfo,sizeof(BMInfoHeader),1, output_file);
	int Pixels = 3*ImageInfo->width; //Байты под пикслеи
	int Alignment = ImageInfo->width%4; //Байты под выравнивание
	for(i=0; i < ImageInfo->height; i++)
	{
		fwrite(raster[i], sizeof(char), Pixels, output_file);
		for (j=0; j < Alignment; j++)
		fputc(0, output_file);
	}
	fclose(output_file);
}
