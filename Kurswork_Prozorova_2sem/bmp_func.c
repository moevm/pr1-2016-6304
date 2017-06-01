#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp_structs.h"



// Функция, которая проверяет корректность введенных данных

int error_checking(int x0, int x1, int y0, int y1, FILE* bmp_file) 
{
	if (bmp_file == NULL)
	{
		printf("Error(fail with input file)");
		return 0;
	}

	if (x0 < 0 || x1 < 0 || y0 < 0 || y1 < 0 || (y0 - y1) != (x1 - x0) || (y0 - y1) < 0 || (x1 - x0) < 0)
	{
		printf("Error(invalid coordinates)");
		return 0;
	}
	else return 1;
}



//Функция, считывающая информацию о bmp файле

char** get_bmp_file_info(FILE* bmp_file, bitmap_file_header* bfh, bitmap_info_header* bih)
{
	//получаем размер изображения в байтах
	fseek(bmp_file, 0, SEEK_END);
	int art_size = ftell(bmp_file); //ftell возвращает значение указателя текущего положения потока, для бинарных потоков возвращает кол-во байт от начала файла (в данном случае возвращает размер изображения)
	fseek(bmp_file, 0, SEEK_SET);

	//считываем файл в отдельную строку
	char* arr = (char*)malloc(sizeof(char) * art_size); 
	char* copy_arr = arr; 
	fread(arr, sizeof(char), art_size, bmp_file); 

	//считываем в отдельные переменные информацию о заголовке файла и информацию об изображении
	*bfh = *((bitmap_file_header*)arr); 
	arr = arr + sizeof(bitmap_file_header);
	*bih = *((bitmap_info_header*)arr); 
	arr = arr - sizeof(bitmap_file_header);

	//сдвигаем указатель на начало строки пикселей в файле и считываем ее в двумерный массив
	arr = arr + bfh->bf_off_bits;
	char** pixels = (char**)malloc(sizeof(char*) * bih->bi_height);
	int str_len = bih->bi_width * 3 + bih->bi_width % 4; //размер одной строки пикселей + кол-во байт для корректного выравнивания
	int i, j, k = 0;
	for( i = 0; i < bih->bi_height; i++)
	{
		pixels[i] = (char*)malloc(sizeof(char) * str_len);
		for (j = 0; j < str_len; j++)  
		{
			pixels[i][j] = arr[k];
			k++;
		}
	}
	free(copy_arr);
	return pixels;
}



//Функция, создающая новый файл и записывающая в него обрезанное изображение 

void create_new_bmp(char* name, char** pixels, bitmap_file_header* bfh, bitmap_info_header* bih, int x0, int y0, int x1, int y1)
{
	//создаем новый файл
	*(strchr(name, '.')) = '\0'; 
	strcat(name, "_new.bmp"); 
	FILE* new_bmp_file = fopen(name, "wb"); 

	//записываем в новый файл информацию о заголовке и изображении
	fwrite(bfh, sizeof(bitmap_file_header), 1, new_bmp_file);
	fwrite(bih, sizeof(bitmap_info_header), 1, new_bmp_file);

	//записываем в новый файл строку пикселей
	int str_len_rubbish = bih->bi_width % 4; //кол-во байт для корректного выравнивания
	int i, j;
	for(i = y1; i < y0; i++)
	{
		for (j = (x0)*3; j < x1*3; j++) 
		fputc(pixels[i][j], new_bmp_file);
		for (j = 0; j < str_len_rubbish; j++) 
		fputc(0, new_bmp_file); 
	}
	fclose(new_bmp_file);
}


