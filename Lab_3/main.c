#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILES 200

int file_read(const char*, const char*, char**); //Функция считывания файлов

void index_files(const char *, char**, int*); //Функция вывода пути

void find_file(char **, const char *, const char*);//Функция поиска файла

int main(int c, char **v, char **env ){
    char** files;
    int files_num=0; 
    files=(char**)malloc(200*sizeof(char*));
    for(int i=0;i<200;i++)
    {
        files[i]=(char*)malloc(1000*sizeof(char));
    }
    index_files(".", files, &files_num);
    find_file(files, "file.txt", "");
    return 0;
}

void find_file(char **files, const char *file_to_find, const char* buff){
    char buffer[10000];
    for(int i=0;i<MAX_FILES;i++)
    {
        if(strstr(files[i], file_to_find)!=NULL)
        {
            strcpy(buffer, buff);
            strcat(buffer, files[i]);
            strcat(buffer, "\n");
            if(file_read(files[i], buffer, files))
            {
                char *ptext;
                char *temp;
                char *pdir;
                char dir[1001];
                getcwd(dir, 1000); //Копируем полный путь
                pdir=strtok(dir, "/"); //Разбиваем по /
                while(pdir!=NULL)
                {
                    temp=pdir;
                    pdir=strtok(NULL, "/");
                }
                ptext=strtok(buffer, "\n");
                while(ptext!=NULL)
                {
                    printf("/%s/%s\n", temp, ptext);
                    ptext=strtok(NULL, "\n");
                }
            }
        }
    }
}

void index_files(const char *startdir, char** files, int* files_num){
    char current_path[10000]; //Массив под путь
    strcpy(current_path, startdir);
    DIR *dir = opendir(current_path); 
    struct  dirent *de = readdir(dir);
    if(dir)
        while(de = readdir(dir))//Пока есть что читать
        {
            if(de->d_type==8) //8 тип для дериктории (декодируется ASCII)
            {
                int path_len = strlen(current_path); //Продлеваем на длину нашего пути
                strcat(current_path,"/");
                strcat(current_path,de->d_name);
                strcpy(files[(*files_num)++], current_path);
                current_path[path_len] = '\0'; //Добавляем в конец \0, чтобы strcat работал
            }
            if(de->d_type == DT_DIR && strcmp(".",de->d_name) && strcmp("..", de->d_name))
            {
                int path_len = strlen(current_path); //Изменяем длину пути на текущий
                strcat(current_path,"/");
                strcat(current_path,de->d_name);
                index_files(current_path, files, files_num);
                current_path[path_len] = '\0'; //Добавляем 0 для strcat
            }
        }
  closedir(dir);
}

int file_read(const char* filename, const char* buff, char** files){
    FILE *file; 
    if ((file= fopen (filename, "r")) != NULL){ //Открываем файл на чтение и проверяем на правильность
        char line [128]; //Буфер для содержимого
        while (fgets(line, sizeof(line), file)!= NULL) //Считываем файл
        {           
            if (strstr(line, "Minotaur"))
                return 1;
	    char *ptext;//Объвляем массив для внутренних инклюдов
	    ptext=strtok(line, " \n\r"); 
	    while(ptext!=NULL){
                if(strstr(ptext, ".txt\0"))
                    find_file(files, ptext, buff); //Начинаем поиск файлов
            ptext=strtok(NULL, " \n\r"); 
	    }
        }
        fclose(file);
  }
    else
  {
        perror(filename);
  }
  return 0;
}