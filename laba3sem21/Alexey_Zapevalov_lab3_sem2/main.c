#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int comp(const void* a, const void* b)
{
    return atoi(*(char**)a)-atoi(*(char**)b);//compares content of strings, casted to int
}

int poisk(char *homedir, char** arr, int i)
{
    char buf[100];
    DIR *d;
    struct dirent *dir;
    d = opendir(homedir);//opens a directory
    if( d == NULL )
    {
        return 0;
    }
    while((dir=readdir(d))) //reading contents of directory
    {
        if( strcmp( dir->d_name, "." ) == 0 ||
                strcmp( dir->d_name, ".." ) == 0 )//checking if home directory is a root or lower than root
        {
            continue;
        }
        int path_len = strlen(homedir);//saves length of current directory path
        strcat(homedir,"/");
        strcat(homedir,dir->d_name);//adding a new folders' name to previous path
        if (dir->d_type == DT_DIR)
        {
            i=poisk(homedir, arr, i);//if current directory contains other directories, it calls function 'poisk' again
        }
        else if (strstr(dir->d_name, ".txt"))//if contained file has a .txt format, opens it
        {
            FILE *file;
            file = fopen(homedir, "r");
            fgets(buf, 90, file);
            strcpy(arr[i], buf);//reads file contents to array
            i++;
            memset(buf, 0, 100);
            fclose(file);
        }
        homedir[path_len] = '\0';//turns back to previous directory
    }
    closedir(d);
    return i;
}

int main() //creates array of strings, calls function to fill it, sorts strings.
{
    char** arr=(char**)malloc(N*sizeof(char*));//creates array of pointers to strings
    int j=0, i;
    for (i=0; i<N; i++)
    {
        arr[i]=(char*)malloc(N*sizeof(char));//creates string for each pointer
    }
    char homedir[100];
    strcpy(homedir, "./root"); //sets home directory
    poisk(homedir, arr, 0);//calls function to fill array
    qsort(arr, N, sizeof(char*), comp);//sorting array
    while(arr[j])
    {
        printf("%s", arr[j]);//output
        j++;
    }
    return 0;
}
