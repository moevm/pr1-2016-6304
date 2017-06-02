#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "functions.h"

int errors(FILE* input_file,int x0,int y0,int x1,int y1)
{
       if(input_file == NULL)
       {
             printf("Fail with opening file\n");
             return 0;
       }
       else if (x0<0 || y0<0 || x1<0 || y1<0)
       {
             printf("Fail with coordinates\n");
             fclose(input_file);
             return 0;
       }
																					        else if ((y0-y1) != (x1-x0) || (x1-x0)<0 || (y0-y1)<0)
																					        {
             printf("Fail with area\n");
             fclose(input_file);
             return 0;
       }
       return 1;
}

char** bmp (FILE* input_file, BMFileHeader* info_file, BMInfoHeader* info_picture)
{
	fseek(input_file,0,SEEK_END);//устанавливаем позицию в конец файла
	int file_size = ftell(input_file);//размер файла (Для бинарных потоков, возвращается значение соответствующее количеству байт от начала файла)
	fseek(input_file,0,SEEK_SET);//перемещение указателя в начало
	char* buffer = (char*)malloc(sizeof(char)*file_size);
        size_t result = fread(buffer,sizeof(char),file_size,input_file);//считывание файла в выделенную память
        if (result != file_size)
       {
            printf("Fail with memory");
	    return 0;
       }
       *info_file = *((BMFileHeader*)buffer);//заголовок с информацией
       buffer += sizeof(BMFileHeader);//указатель смещается на размер заголовка
       *info_picture = *((BMInfoHeader*)buffer);//информация об изображении
       buffer -= sizeof(BMFileHeader);////указатель перемещается на начало изображения
       buffer += info_file -> boffset;
       int len = 3*info_picture -> width + (info_picture -> width%4);
       char** array = (char**)malloc(sizeof(char*)*info_picture->height);
       int count = 0;
       for(int i =0; i<info_picture->height; i++)
       {
             array[i] = (char*)malloc(sizeof(char)*len);
             for(int j = 0; j< len; j++)
	             array[i][j] = buffer[count++];
       }
       return array;
}

void create_new_file(char* input_file, char** array, BMFileHeader* info_file, BMInfoHeader* info_picture)
{
       *(strchr(input_file, '.')) = '\0';
        strcat(input_file, "_rotated.bmp");
        FILE* new_bmp_file = fopen(input_file,"wb");
        //запись заголовков
        fwrite(info_file,sizeof(BMFileHeader), 1, new_bmp_file);
        fwrite(info_picture,sizeof(BMInfoHeader),1,new_bmp_file);
        int part_with_pixels = 3*info_picture->width;
        int trash = info_picture->width%4;
        for(int i= 0; i < info_picture->height; i++)
        {
               fwrite(array[i], sizeof(char),part_with_pixels, new_bmp_file);
               for (int j = 0; j < trash; j++)
		       fputc(0, new_bmp_file);
	}
	fclose(new_bmp_file);
}
char** rotation(char** array, int x0, int y0, int x1, int y1)
{
        RGB* string = NULL;
        RGB** arr = (RGB**)malloc(sizeof(RGB*)*(y0-y1+1));
        for (int k = 0; k <=y0-y1; k++)
        {
               arr[k] = (RGB*)malloc(sizeof(RGB)*(x1-x0+1));   //Копируем массив символов
               memmove(arr[k], array[y1+k]+x0*sizeof(RGB), sizeof(RGB)*(x1-x0+1));     //в двумерный массив пикселей
        }
        for (int z = y1; z <= y0; z++)//в пределах заданной области
        {
               string = (RGB*)array[z];
               for(int i = x0; i <=x1; i++)
	       {
	             string[i]=arr[i-x0][y0-z];              //поворот по часовой на 90 градусов
																					                }
	}
	free(arr);
	return array;
}

