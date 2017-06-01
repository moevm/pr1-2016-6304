#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

char* txtOpen(char* txtName){ //функция открытия файла
    FILE* txt = fopen(txtName, "r");
    if (txt == NULL){ //проверяем можно ли открыть файл
        printf("ERROR\n");
	return NULL;
    }
    fseek(txt,0,SEEK_END); //перемещаем указатель на последнюю позицию потока
    int txtSize = ftell(txt); //узнаем размер файла
    fseek(txt,0,SEEK_SET); //перемещаем указатель обратно на первую позицию потока
    if(txtSize == 0){ //если размер файла равен нулю, закрываем его
	fclose(txt);
        return NULL;
    }
    char* txtStr = (char*)malloc(sizeof(char)*10000); //в противном случае выделяем память для строки
    fgets(txtStr, txtSize*sizeof(char),txt); //считываем строку из файла
    fclose(txt); 
    return txtStr;  //возвращаем считанную строку
}

void list_dir(const char* dirName, char** strsTxt, int* len){ //обход каталога
    char current_path[10000]; //выделяем память для строки, где будет путь к объекту
    strcpy(current_path, dirName);
    DIR *current_dir = opendir(current_path);
    if (current_dir == NULL) return; //проверяем корректно ли открылся каталог
    struct dirent* current_dir_file =readdir(current_dir); //считываем структуру с информацией об объекте в первом каталоге
    while(current_dir_file){ //пока в текущей дирректории есть объекты
        int path_len = strlen(current_path);
	strcat(current_path, "/");
	strcat(current_path, current_dir_file->d_name); //добавляем имя объекта к строке
        if(current_dir_file->d_type == DT_REG && strstr(current_dir_file->d_name, ".txt") != NULL){ //является ли объект нужным файлом?
		if((strsTxt[*len] = (char*)txtOpen(current_path)) != NULL) 
		(*len)++;  //если файл не пустой и не поврежден, возвращаем указатель на первую строку в нем
	}
	if (current_dir_file->d_type == DT_DIR && strcmp(".", current_dir_file->d_name) != 0 && strcmp("..",current_dir_file->d_name) != 0) list_dir(current_path,strsTxt,len); //если объект - дирректория(не родительская и не текущая), вызываем(рекурсивно) функцию обхода каталога
	current_path[path_len] = '\0'; //возвращаемся к первоначальному положению
	current_dir_file = readdir(current_dir); //считываем следующий объект
    }
    closedir(current_dir); //закрываем дирректорию после обхода всех ее объектов
}

int compare(const void* a, const void* b){ //компаратор для qsort-a
    return atoi(*(char**)a) - atoi(*(char**)b);
}

int main(){
    char** strs = (char**)malloc(sizeof(char*)*1000); //выделяем память под массив указателей на строки
    int len = 0;
    int i=0;
    char str[1000];
    FILE* fo;
    fo=fopen("fo","w"); //открываем файл для записи
    list_dir(".",strs,&len); //заполняем массив строками из файлов
    qsort(strs, len, sizeof(char*), compare); //сортируем строки
    for (i=0;i<len;i++) fprintf(fo,"%s\n", strs[i]); //выводим отсортированные строки
    fclose(fo); //закрываем
    fo=fopen("fo","r"); //открываем для чтения
    while (fgets(str, 1000, fo))
      printf("%s", str);
    fclose(fo); //закрываем
    for (i=0;i<len;i++) free(strs[i]); //освобождаем память
    free(strs);
    return 0;
}
