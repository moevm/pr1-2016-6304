/*

functions.c

Функции для работы с bmp файлами.

Васильев А. - 6304

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp_structs.h"
#include "functions.h"

int input_errors_checker(FILE* bmp_file, int x0, int y0, int x1, int y1)
{
/*Если файл не открыт, то указатель обнуляется.
В этом случае возвращается 0 (критерий ошибки)*/
	if (bmp_file == NULL)
	{
		printf("Fail with input file\n");
		return 0;
	};
/*Проверки на корректность введенных координат.
В случае обнаружения ошибки, возращается 0, а также 
закрывается открытый файл.*/
	if (x0<0 || x1<0 || y0<0 || y1<0)
	{
		printf("Fail with coordinates\n");
		fclose(bmp_file);
		return 0;
	};
	if ((y0-y1)!=(x1-x0) || (y0-y1) < 0 || (x1-x0) < 0)
	{
		printf("Fail with area\n");
		fclose(bmp_file);
		return 0;
	}
	return 1;

}

char** get_headers_and_raster(FILE* bmp_file, BITMAPFILEHEADER* file_info,
								BITMAPINFOHEADER* picture_info)
{
/*Определяется размер файла и выделяется память под строку, куда скопируется файл,
для дальнейшей с ним работы.*/
	fseek(bmp_file,0,SEEK_END);
	int picture_size = ftell(bmp_file);
	fseek(bmp_file,0, SEEK_SET);

	char* array_for_extract = (char*)malloc(sizeof(char)*picture_size);
	char* copy_of_arr = array_for_extract;

/*Файл считывается в выделенную память.*/
	fread(array_for_extract, sizeof(char), picture_size, bmp_file);

/*Заголовок с информацией о файле считывается в отдельную переменную.
Указатель в строке сдвигается на размер заголовка.*/
	*file_info = *((BITMAPFILEHEADER*)array_for_extract);
	array_for_extract += sizeof(BITMAPFILEHEADER);

/*Аналогично считывается информация об изображении. Затем указатель перемещается
на начало самого изображения (растра).*/
	*picture_info = *((BITMAPINFOHEADER*)array_for_extract);
	
	array_for_extract -= sizeof(BITMAPFILEHEADER);
	array_for_extract+=file_info->bfOffBits;

/*Согласно с полученной из заголовков информацией, выделяется память под 
строки (каждый пиксель кодируется 3 байтами) с непосредственной информацией
о пикселях. Также в каждой строке выделяется память, которая необходима для
корректного выравнивания.*/
	int string_len = 3*picture_info->biWidth + (picture_info->biWidth%4);
	char** raster = (char**)malloc(sizeof(char*)*picture_info->biHeight);
	int k = 0;
	/*Двумерный массив заполняется информацией*/
	for(int i = 0; i < picture_info->biHeight; i++)
	{
		raster[i] = (char*)malloc(sizeof(char)*string_len);
		for (int e = 0; e < string_len; e++)  
		{
			raster[i][e] = array_for_extract[k++];
		}
	}
	free(copy_of_arr); //Освобождается память для строки
	return raster;
}

char** write_cross(char** raster, int x0, int y0, int x1, int y1)
{
	int black_point_a = x0;
	int black_point_b = x1;
	RGBTRIPLE* string_for_work = NULL; //Указатель на пиксель (строку из пикселей)
	RGBTRIPLE black_pixel = {0,0,0};	//Пиксель черного цвета
/*Цикл "бегает" только в пределах введеных координат*/
	for (int i = y1; i <= y0; i++)
	{
/*Указатель на строку из символов приводится к указателю на строку из пикселей*/
		string_for_work = (RGBTRIPLE*)raster[i];
	
/*Цикл ставит две точки в каждой строке и тем самым 
рисует крест*/
		for(int k = x0; k <= x1; k++)
		{
			if(k==black_point_a || k==black_point_b)
			string_for_work[k] = black_pixel;
		}
			black_point_a++;
			black_point_b--;
	}
	return raster;
	
}

void create_new_bmp(char* old_name, char** raster, BITMAPFILEHEADER* file_info,
					BITMAPINFOHEADER* picture_info)
{
/*К старому имени файла прибавляется строчка "with_cross".
Создается новый файл, с новым именем.*/
	*(strchr(old_name, '.')) = '\0';
	strcat(old_name, "_with_cross.bmp");
	FILE* new_bmp_file = fopen(old_name,"wb");

/*В новый файл записываются заголовки, переданные функции*/
	fwrite(file_info,sizeof(BITMAPFILEHEADER), 1, new_bmp_file);
	fwrite(picture_info,sizeof(BITMAPINFOHEADER),1,new_bmp_file);

/*Определяется число байт в строчке, которые содержат информацию 
о пикселях изображения. Также определяется количество байт, необходимых
для выравнивания. Данные байты должны содержать нули.*/
	int part_with_pixels = 3*picture_info->biWidth;
	int part_with_garbage = picture_info->biWidth%4;

/*В новый файл построчно записывается растр изображения.
Также в каждой строке в конце дописывается необходимое число
нулевых байт, необходимых для выравнивания.*/
	for(int i = 0; i < picture_info->biHeight; i++)
	{
		fwrite(raster[i], sizeof(char),part_with_pixels, new_bmp_file);
		for (int k = 0; k < part_with_garbage; k++)
			fputc(0, new_bmp_file);
	}
	fclose(new_bmp_file); //Новый файл закрывается.
}


