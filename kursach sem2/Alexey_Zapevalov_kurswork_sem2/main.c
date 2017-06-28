#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define input_file_1 "./Worksheet 1.csv"
#define input_file_2 "./Worksheet 2.csv"
#define output_file "./Worksheet 3.csv"
#define BUFSZ 1000
#define N 10000
#define P 30
#define L 4

int compare(const void** a, const void** b)//сравнение
{
    return strcmp(*(char**)a, *(char**)b);
}

int checkWriteableFile(char* sourcefile) //Проверка на возможность записи в файл
{
    FILE* file = fopen(sourcefile, "a");
    if (errno)
    {
        printf("Problem with file %s\n", sourcefile);
        return 0;
    }
    else
        return 1;
    fclose(file);
}

int checkReadableFile(char* sourcefile) //Проверка на наличие исходных файлов
{
    FILE* file =fopen(sourcefile, "r");
    if (errno)
    {
        printf("Problem with file %s\n", sourcefile);
        return 0;
    }
    else
        return 1;
    fclose(file);
}

void printThem(char** arrayOne, int i, char** arrayTwo, int k)//вывод данных из строк
{
    FILE *file;
    file=fopen(output_file, "a");
    int c=0;
    for (c=0; c<5; c++)
    {
        fprintf(file, "%s,", arrayOne[i+c]);
    }
    fprintf(file, "%s", arrayTwo[k+2]);
    fclose(file);
}

void printNumber(char* number)//вывод номера группы
{
    FILE *file;
    file=fopen(output_file, "a");
    fprintf(file, "%s", number);
    fclose(file);
}

void printTitle(char** arrayOne, char** arrayTwo)//вывод заголовка
{
    int i=0;
    FILE *file;
    file=fopen(output_file, "a");
    for (i=0; i<5; i++)
    {
        fprintf(file, "%s,", arrayOne[i]);
        if (i==4)
            fprintf(file, "%s", arrayTwo[2]);
    }
    fclose(file);
}

void printGap()//печать пробела между группами
{
    FILE *file;
    file=fopen(output_file, "a");
    fprintf(file, "\n\n");
    fclose(file);
}

void freeArray(char** arr)
{
    int i=0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void findStudents(char* number, char** arrayOneNoCommas, char** arrayTwoNoCommas)
{
    //поиск студентов одной группы, нахождение соответствия со второй таблицей
    int i=6, k=3, findIt=0;
    printTitle(arrayOneNoCommas, arrayTwoNoCommas);
    while(i<N-6)
    {
        if (strcmp(arrayOneNoCommas[i+5], number)==0)
        {
            while(k<N)
            {
                if (strcmp(arrayTwoNoCommas[k], arrayOneNoCommas[i])==0&&strcmp(arrayTwoNoCommas[k+1], arrayOneNoCommas[i+1])==0)
                {
                    findIt=1;
                    printThem(arrayOneNoCommas, i, arrayTwoNoCommas, k);
                    break;
                }
                k+=3;
            }
            if (findIt==0)
            {
                printf("Fail with Name or Surname comparison");
                remove(output_file);
            }
            findIt=0;
        }
        i+=6;
        k=3;
    }
    printGap();
}


char** createArrayOfStrings(int rows, int columns)//создается массив
{
    int i;
    char** array = (char**)malloc(rows*sizeof(char*));
    for (i=0; i<rows; i++)
    {
        array[i]=(char*)malloc(columns*sizeof(char));
    }
    return array;
}

char** returnNumbersOfGroups(char** array) //нахождение номеров групп и их сортировка
{
    int i, j=0, m=0, flagNumberOfGroup=0;
    char** numbers = createArrayOfStrings(P, L);
    i=11;
    while (array[i][0])
    {
        while(numbers[j][0]!=0)
        {
            if (strcmp(numbers[j], array[i])==0)
            {
                flagNumberOfGroup=1;
                break;
            }
            j++;
        }
        if (flagNumberOfGroup==0)
        {
            strcpy(numbers[m], array[i]);
            m++;
        }
        flagNumberOfGroup=0;
        j=0;
        i+=6;
    }
    if (m==0)
    {
        printf("Fail with group numbers\n");
    }
    i=0;
    qsort(numbers, m, L*sizeof(char), compare);
    return numbers;
}

void read(char* filename, char** array) //считываются строки из файла
{
    char buf[BUFSZ];
    int j=0;
    FILE *file = fopen(filename,"r");
    while(!feof(file))
    {
        fgets(buf, BUFSZ-1, file);
        strcpy(array[j], buf);
        j++;
    }
    memset(array[j-1], 0, N*sizeof(char));//последняя строка считывается дважды, заполняем ее нулями
    fclose(file);
}

void checkCompleteness(char** array, int commas) //проверяем количество запятых в строках
{
    int i=0, j=0, counter=0;
    while(array[i][j]!=0)
    {
        while(array[i][j])
        {
            if (array[i][j]==',')
            {
                counter++;
            }
            j++;
        }
        j=0;
        if (counter!=commas)
        {
            printf("Fail with commas(Line %d)", i+1);
        }
        counter=0;
        i++;
    }
}

char** arrayNoCommas(char** array) //разделяем строки с данными на токены запятыми и заполняем массив
{
    char** arrNoCommas=createArrayOfStrings(N, P);
    int i=0, j=0;
    char delim[]=",";
    for (j=0; j<N; j++)
    {
        char* p=strtok(array[j], delim);
        while (p!=NULL)
        {
            strcpy(arrNoCommas[i], p);
            p=strtok(NULL, delim);
            i++;
        }
    }
    return arrNoCommas;
}

void findGroups(char** arrayOne, char** arrayTwo) //разделяем данные, находим номера групп и студентов
{
    int i=0;
    char** arrOneNoCommas=arrayNoCommas(arrayOne);
    char** arrTwoNoCommas=arrayNoCommas(arrayTwo);
    char** groupNumbersArray = returnNumbersOfGroups(arrOneNoCommas);
    while (groupNumbersArray[i][0]!=0)
    {
        printNumber(groupNumbersArray[i]);
        findStudents(groupNumbersArray[i], arrOneNoCommas, arrTwoNoCommas);
        i++;
    }
    i=0;
    freeArray(arrOneNoCommas);
    freeArray(arrTwoNoCommas);
    freeArray(groupNumbersArray);
}

int main() //вызываются функции по созданию массивов, считыванию файлов и нахождению номеров групп
{
    if (checkReadableFile(input_file_1)&&checkReadableFile(input_file_2)&&checkWriteableFile(output_file))
    {
        char** arrayOne = createArrayOfStrings(N, N);
        char** arrayTwo = createArrayOfStrings(N, N);
        read(input_file_1, arrayOne);
        read(input_file_2, arrayTwo);
        checkCompleteness(arrayOne, 5);
        checkCompleteness(arrayTwo, 2);
        findGroups(arrayOne, arrayTwo);
        freeArray(arrayOne);
        freeArray(arrayTwo);
    }
    return 0;
}
