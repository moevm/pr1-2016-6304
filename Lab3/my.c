#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //различные типы данных
#include <dirent.h> //Открытие и вывод каталогов
 
#define PATHLEN 1000
 
typedef struct character //структура для хранения: 
{
    char symbol; //буквы
    char path[PATHLEN]; //директории
    int trigger; //триггерa есть-нет
} character;
 
int is_name_full (character *Ch_Path, int len) //функция для проверки готовности слова
{
    for (int i = 0; i < len; i++)
        if (!(Ch_Path + i)->trigger)
            return 0;
    return 1;
}
 
void check_Ch(character *Ch_Path, char *Current_Dir, char *fileName, int len) //функция ищет букву в имени файла 
{
    for (int i = 0; i < len; ++i)
    {
        if (((Ch_Path + i)->symbol == *fileName) && !((Ch_Path + i)->trigger))
        {
              *(fileName + strlen(fileName)) = '.';
              int Current_Dir_len = strlen(Current_Dir);
              strcat(Current_Dir, "/");
              strcpy((Ch_Path + i)->path, strcat(Current_Dir, fileName));
              (Ch_Path + i)->trigger = 1;
              *(Current_Dir + Current_Dir_len) = '\0';
              break;
        }
    }
}
 
int check_Dr (char *Name_Dir, character *Ch_Path, int len) //проверка директории
{
    char Current_Dir[100];
 strcpy(Current_Dir, Name_Dir);//скопировали имя директории в новый массив
 
 DIR *dir = opendir(Current_Dir);

struct dirent *content = readdir(dir);//создаём структуру типа dirent
 
    if(dir)
        while(content)
        {
            if (content->d_type == 8)
{//если это файл
char *fileName = strtok(content->d_name, ".");//имя файла до точки
check_Ch(Ch_Path, Current_Dir, fileName, len);//проверяем первую букву
if (is_name_full(Ch_Path, len))//если имя полное,  выходим
return 0;
}
if ((content->d_type == 4) && strcmp(".", content->d_name) && strcmp("..", content->d_name))//если это директория
{
int Current_Dir_len = strlen(Current_Dir);//длина этой директории
strcat(Current_Dir, "/");//добавил файловый разделитель
strcat(Current_Dir, content->d_name);//добавили имя файла
check_Dr(Current_Dir, Ch_Path, len);//проверки директории
 *(Current_Dir + Current_Dir_len) = '\0';//ставим конец строки
 }
            content = readdir(dir);
        }
 closedir(dir); 
return 0;
}
 
int main ()
{
    char Name_Dir[100] = {'.', '\0'};
    char s[100];
 
    fgets(s, (102), stdin); //читаем строку, в которой записана последовательность букв
    int len;
    len= (strlen(s) - 1);
 
    character *Ch_Path = (character*)malloc(len * sizeof(character));
    for (int i = 0; i < len; ++i)
    {
        (Ch_Path + i)->symbol = s[i];
        (Ch_Path + i)->trigger = 0;
    }
 
    check_Dr(Name_Dir, Ch_Path, len);
 
    for (int i = 0; i < len; ++i)
        printf("%s\n", (Ch_Path + i)->path);
 
 
    return 0;
} 
