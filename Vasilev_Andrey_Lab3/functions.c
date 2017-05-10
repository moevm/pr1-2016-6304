/*
Функции для работы с директориями,
необходимые для Л.Р. №3..
Васильев Андрей - 6304.
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>				//Необходимые заголовочные фалы для работы с директориями
#include <string.h>
#include <stdlib.h>

#include "functions.h"

	/*Функция, которая открывает txt файл и возвращает
	указатель на первую его строку (если она есть)*/
char* open_txt_file(char* file_name)
{
/*Открытие файла. Значение NULL предусмотрено в функции "read_catalog",
которая вызывает данную функцию.*/
	FILE* txt_file = fopen(file_name, "r");
	if(txt_file == NULL)
	{
		printf("error!\n");
		return NULL;
	}
/*Определение размера файла для корректного выделения памяти*/
	fseek(txt_file,0, SEEK_END);
	int file_size = ftell(txt_file);
	fseek(txt_file,0, SEEK_SET);

/*Если размер равен нулю, то сообщается, что файл пуст.
Если размер ненулевой, то выделяется память под строку.*/
	if(file_size == 0)
	{
		fclose(txt_file);
		printf("<!file %s is empty!>\n", file_name);
		return NULL;
	}
	char* string_in_file = (char*)malloc(sizeof(char)*(file_size+100));

/*Первая строка txt файла считывается в выделенную память.
Файл закрывается, указатель на строку возвращается.*/
	fgets(string_in_file, file_size*sizeof(char), txt_file);
	fclose(txt_file);
	return string_in_file;
}
 
	/*Данная функция обходит каталог и при наличии txt файла открывает его
	с помощью функции "open_txt_file". Полученный указатель помещается в массив
	из указателей на строк.*/
void read_catalog(const char* dir_name,char** strings_in_txt, int* len)
{
/*Выделяется память под строку, в которую будет помещаться путь к файлам.
Используется макрос NAME_MAX, определяющий максимально возможную длину имени файла*/
	char* current_path = (char*)malloc(sizeof(char)*(strlen(dir_name)+NAME_MAX));
  	strcpy(current_path,dir_name);

/*Открывается поток каталога и проверяется на корректное открытие.
Далее с помощью функции readdir считывается структура с информацией
о первом файле в каталоге.*/
  	DIR *current_dir = opendir(current_path);
	if(current_dir == NULL)
		return;
	dirent* file_in_current_dir = (dirent*)readdir(current_dir);

/*Цикл выполнятеется, пока в текущей директории будут объекты*/
		while(file_in_current_dir)
    	{
/*К строке, содержащий путь, добавляется имя объекта*/
    	 	int path_len = strlen(current_path);
			strcat(current_path, "/");
			strcat(current_path, file_in_current_dir->d_name);

			printf("[%s]\n", current_path); //Печать для контроля (можно отключить).

/*С помощью спец макросов проверяется, является ли объект файлом или директорией.*/
			if
			(
				file_in_current_dir->d_type == DT_REG &&
				strstr(file_in_current_dir->d_name, ".txt")!=NULL
			) 
			{
/*Если объект - это неповрежденный и непустой (данные условия проверяются в open_txt_file) txt файл,
то возвращается указатель на первую строку из него. (*/
				if((strings_in_txt[*len] = (char*)open_txt_file(current_path))!=NULL )
					(*len)++;
			}
    		if
			(
			 	file_in_current_dir->d_type == DT_DIR && 
    		  	strcmp(".",file_in_current_dir->d_name)!=0 && 
				strcmp("..",file_in_current_dir->d_name)!=0
			)
   			{ 
/*Если объект - это директория (причем не родительская и не текущая), то рекурсивно вызывается функция
read_catalog для прочтения данной директории*/
     		 	read_catalog(current_path,strings_in_txt, len);
   			} 
/*После проверки текущего объекта current_path "обрезается" до первоначального положения.
Далее считывается следующий объект из данной директории*/
			current_path[path_len] = '\0';
			file_in_current_dir = (dirent*)readdir(current_dir);
		}
/*После обхода всех объектов в директории, она закрывается*/
  closedir(current_dir);
}

	/*Функция-компаратор для qsort.
	Так как известно, что строка начинается с числа, 
	то с помощью библиотечной функции вычисляется разность
	между числами двух строк.*/
int compare(const void* a, const void* b)
{
	return atoi(*(char**)a) - atoi(*(char**)b);
}
