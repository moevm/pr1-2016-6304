#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WAYS 200
#define WAY_SIZE 1000
#define MAX_TOKENS 200

//Считываем из текстового файла строку
char *get_file_info(const char *way_buff, int *file_size){
    
    FILE *file=fopen(way_buff,"rt"); //открываем файл для чтения
    //находим размер файла
    fseek(file,0, SEEK_END);
    *file_size = ftell(file);
    fseek(file,0, SEEK_SET);
    //выделяем память по строку
    char *str=(char*)malloc(sizeof(char)*(*file_size));
    //считываем информацию в строку
    fread(str, 1, *file_size, file);
    //закрываем файл
    fclose(file);
    return str;
}


//Обход директории в поиске файла, содержащего слово Minotaur, возвращает длину пути до этого файла
int search_minotaur(char *new_way, char *start_dir, char* file_name, char **all_ways)
{
    char way_buff[WAY_SIZE];   //временный буфер
    int length_way=0;       //Длина пути
    strcpy(way_buff,new_way);       //Запись пути для дальнейшего использования и изменения

    DIR *dir = opendir(way_buff);       //Открываем директорию
    struct  dirent *file_info = readdir(dir);      //Читаем информацию о текущем файле в директории
    while(file_info) //пока в директории не закончились файлы
    {
        //получаем текущий путь
        int path_len = strlen(way_buff);
        strcat(way_buff,"/");
        strcat(way_buff,file_info->d_name);
             

        //ищем нужный файл
        //если нужный файл это регулярный файл и его имя совпадает с искомым файлом   
        if(file_info->d_type==DT_REG && !strcmp(file_info->d_name,file_name))
        {
            int number_of_tokens = 0;
            file_size = 0;
            //считываем строку из файла
            char *str=get_file_info(way_buff,&file_size);
            //разбиваем строку на лексемы
            char tokens_arr[MAX_TOKENS][file_size];     //массив лексем
            //разбиваем строку на лексемы
            char *item=strtok(str," \n");  //указатель на текущую лексему  
            while(item!=NULL)
            {
                strcpy(tokens_arr[number_of_tokens++],item);
                item=strtok(NULL," \n");
            }
                

            //анализируем лексемы
            int i;
            for(i=0;i<number_of_tokens;i++)
            { 
                   

                //если тупик, возвращаем длину пути
                if(!strcmp(tokens_arr[i],"Deadlock")) return length_way;
                    
                //если файл-минотавр найден, запоминаем найденный путь
                else if(!strcmp(tokens_arr[i],"Minotaur"))
                {
                    all_ways[length_way]=(char*)malloc(sizeof(char)*1000);
                    strcpy(all_ways[length_way],way_buff);
                    length_way=1;
                    return length_way;
                }

                //если предыдущая лексема указывает на то, что данная лексема - название следующего файла, переходим к следующему файлу
                else  if(!strcmp(tokens_arr[i-1],"@include"));
                {
                    length_way=search_minotaur(start_dir,start_dir,tokens_arr[i],all_ways);
                    if(length_way!=0)
                    {
                        all_ways[length_way]=(char*)malloc(sizeof(char)*1000);
                        strcpy(all_ways[length_way],way_buff);
                        length_way++;
                        return length_way;
                    }
                }
            }
        }


        //если файл это директория (не родительская и не текущая), проверяем ее
        if( file_info->d_type == DT_DIR && strcmp(".",file_info->d_name)!=0 && strcmp("..",file_info->d_name)!=0)
        { 
            length_way = search_minotaur(way_buff,start_dir,file_name,all_ways);
        }

        way_buff[path_len] = '\0'; //если слово не найдено, переходим к следующему файлу, очищаем последний найденный путь
        file_info = readdir(dir);  
    }
    closedir(dir);
    return length_way;
}




int main()
{
    char *file_name="file.txt";     //файл, с которого начинаем поиск
    char **all_ways=(char**)malloc(MAX_WAYS*sizeof(char*));     //Массив путей
    int length_way=0;

    //ищем пути к файлу-минотавру 
    length_way=search_minotaur(".",".",file_name,all_ways);
    //Вывод путей и очищение памяти
    int i;
    for(i=length_way-1;i>=0;i--){                       
        printf("%s\n",all_ways[i]);
        free(all_ways[i]);}
    free(all_ways);
    return 0;
}
