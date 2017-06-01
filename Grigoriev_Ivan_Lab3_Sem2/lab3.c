/*
Лабораторная работа №3. Второй семестр. Григорьев Иван гр.6304
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define PATH_NAME_LIMIT 5000
#define DIR_NAME_LIMIT 3
#define ADD_PTR 0 
#define MUL_PTR 1


/*функция для определения операции: если это add, то переменной, 
  по которой будет распознаваться необходимая операция, присвоится
  значение 0, если mul - 1 */
long long int WhichIsOperation(const char *operation) 
{
  long long int operation_ptr=ADD_PTR;
  if(!strcmp(operation, "mul/"))
    operation_ptr=MUL_PTR;
  return operation_ptr;
}

/*Рекурсивная функция, которая, проходя по всему дереву и одновременно
  выполняя поиск .txt файлов, считывает числа с этих файлов и выполняет 
  необходимые операции над ними*/
long long int recDirOperations(char *path_of_start_dir, const char *operation)
{
  long long int result=WhichIsOperation(operation);
  int path_length=strlen(path_of_start_dir);
  //к исходному пути добавляем новую директорию
  strcat(path_of_start_dir, operation); 
  /*открывает поток каталога и возвращает указатель на структуру типа DIR, 
    которая содержит информацию о каталоге*/
  DIR *dir=opendir(path_of_start_dir); 
  struct dirent *de=readdir(dir); //указатель на название следующего файла в каталоге
  while(de) //пока в директории есть объекты
  {
    if (de->d_type==DT_REG && strstr(de->d_name, ".txt")) //если рассматриваемый объект является txt файлом
    {
      strcat(path_of_start_dir, de->d_name); //путь до файла
      FILE *file=fopen(path_of_start_dir, "r"); //открываем файл в режиме чтения
      int num;
      while(fscanf(file, "%d", &num)>0) //пока в файле есть числа
      {
          if(WhichIsOperation(operation)) //если файл лежит в директории mul
            result*=num;
          else 
            result+=num;
      }
     path_of_start_dir[path_length+DIR_NAME_LIMIT+1]='\0'; 
      fclose(file);
    }
    if(de->d_type==DT_DIR && !strcmp(de->d_name, "mul")) //если рассматриваемый объект директория с именем mul
    {
        if(WhichIsOperation(operation)) //если объект лежит в директории mul
            result*=recDirOperations(path_of_start_dir, "mul/"); 
        else
            result+=recDirOperations(path_of_start_dir, "mul/");
    }        
    if(de->d_type==DT_DIR && !strcmp(de->d_name, "add")) //если рассматриваемый объект директория с именем add
    {
        if(WhichIsOperation(operation)) //если объект лежит в директории mul
            result*=recDirOperations(path_of_start_dir, "add/");
        else
            result+=recDirOperations(path_of_start_dir, "add/");
    }
    de=readdir(dir);
  }    
  closedir(dir);
  path_of_start_dir[path_length]='\0';
  return result;
}

int main()
{
  char current_path[PATH_NAME_LIMIT];
  strcat(current_path, "./root/"); 
  DIR *dir=opendir(current_path);
  
  struct dirent *de=readdir(dir);
  if(dir)
    while (de)
    {
        if (!strcmp(de->d_name, "mul")) //если первый объект имеет имя mul
            printf("The result of all add & mul operations: <%lld>\n", recDirOperations(current_path, "mul/"));
        if (!strcmp(de->d_name, "add")) //если первый объект имеет имя add
            printf("The result of all add & mul operations: <%lld>\n", recDirOperations(current_path, "add/"));
        de=readdir(dir);
    }
  closedir(dir);
  return 0;
}
