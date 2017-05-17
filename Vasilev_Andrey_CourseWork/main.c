/*

Курсовая работа - 2 семестр

Программа рисует крест в заданной области bmp файла.
Полученное изображение сохраняется в новом файле.
В случае неверных входных данных программа завершает работу
и сообщает о данных, в которых допущена ошибка.

Васильев Андрей
гр. 6304

version 1.0
1.05.2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp_structs.h" //Включение заголовочных файлов с объявлением
#include "functions.h"   //структур и функций.

#define NAME_SIZE 100



int main()
{
	
	system("clear");		//вызывается функция для 

/*Выделяется память под строку и считывается имя файла и
координаты левого верхнего и правого нижнего углов,
в пределах которых будет нарисован крест.*/
	char* bmp_file_name = (char*)malloc(sizeof(char)*NAME_SIZE);
	printf("Write name of an existing bmp file: ");
	fgets (bmp_file_name, 100, stdin);
	*(strchr(bmp_file_name, '\n')) = '\0';

	int x0,x1,y0,y1;
	x0 = x1 = y0 = y1 = -1;
	printf("Top left coordinates (x, y): ");
	scanf("%d %d", &x0, &y0);
	printf("Bottom right coordinates (x, y): ");
	scanf("%d %d", &x1, &y1);

/*Специальной функцией проверяется корректность введенных данных
(реализация в "functions.c")*/
	FILE* bmp_file = fopen(bmp_file_name, "rb");
	if (input_errors_checker(bmp_file, x0,y0,x1,y1) == 0)
	{	
		free(bmp_file_name);

		return 0;
	}

/*Создается двумерный массив символов и заполняется информацией о пикселях
bmp картинки. Также выделяются заголовки с информацией о файле и изображении.
Реализация функции в "functions.c"*/
	BITMAPFILEHEADER file_info;
	BITMAPINFOHEADER picture_info;
	char** raster = get_headers_and_raster(bmp_file, &file_info, &picture_info);
	fclose(bmp_file); //Закрытие файла.

/*Дополнительная проверка на основании полученных данных об изображении.
Проверка на то, вмещается ли введенная область в рамки изображения.*/
	if (picture_info.biWidth < x1+1 || picture_info.biHeight < y0+1)
	{
		printf("Fail with size of picture\n");
		free(bmp_file_name);

		return 0;
	}

/*Специальная функция, которая рисует крест, в заданной области.
Реализация в "functions.c"*/
	raster = write_cross(raster, x0, y0, x1,y1);

/*Специальная функция создает новый bmp файл с нарисованным крестом.
Сохраняет его под именем "'старое имя'_with_cross.bmp".
Реализация функции в "functions.c"*/
	create_new_bmp(bmp_file_name,raster, &file_info, &picture_info);
	printf("\nNew bmp fie \"%s\" created\n\n", bmp_file_name);

	free(bmp_file_name); //Память, выделенная под строку, освобождается



	return 0;
}
