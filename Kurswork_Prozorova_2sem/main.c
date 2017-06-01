/*

	Курсовая работа, 2-й семестр
	Тема: Обработка BMP-файла
	Гр. 6304 Прозорова А.Д.

	Программа вырезает квадрат из исходного изображения и записывает полученное изображение в новый файл. В случае некорректного ввода данных выводит сообщение об ошибке.

	1.06.2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp_structs.h"
#include "bmp_func.h"


int main()
{
	//выделяем память под имя файла, вводим имя файла и угловые координаты области, которую нужно будет вырезать из изображения
	char* bmp_file_name = (char*)malloc(sizeof(char) * 100);  
	printf("Write name\n");
	fgets (bmp_file_name, 100, stdin);
	*(strchr(bmp_file_name, '\n')) = '\0';
	int x0, x1, y0, y1, i;
	printf("Write top left coordinates\n");
	scanf("%d %d", &x0, &y0);
	printf("Write bottom right coordinates\n");
	scanf("%d %d", &x1, &y1);

	//открываем двоичный файл для чтения и проверяем корректность введенных данных
	FILE* bmp_file = fopen(bmp_file_name, "rb");
	if (error_checking(x0, x1, y0, y1, bmp_file) == 0) 
	{	
		free(bmp_file_name);
		fclose(bmp_file);
		return 0;
	}
	
	//считываем информацию о файле и закрываем его
	bitmap_file_header bfh; 	// заголовок bmp файла
	bitmap_info_header bih; 	// структура изображения
	char** pixels = get_bmp_file_info(bmp_file, &bfh, &bih); //матрица пикселей
	fclose(bmp_file); 

	//проверяем, не вылазят ли введенные координаты за рамки изображения
	if (bih.bi_width <= x1-1 || bih.bi_height < y0-1)
	{
		printf("Error(size of picture)\n");
		free(bmp_file_name);
		return 0;
	}

	//создаем новый файл с обрезанным изображением
	bih.bi_height = y0-y1;
	bih.bi_width = x1-x0;
	create_new_bmp(bmp_file_name, pixels, &bfh, &bih, x0, y0, x1, y1);
	printf("New bmp_file %s created\n", bmp_file_name);
	free(bmp_file_name);
	return 0;
}
