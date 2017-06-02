#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int search(char* name, char* path){ //Searching file in path
    DIR* dir = opendir(path);
    struct dirent *de = readdir(dir);
    while (de){
        if ((de->d_type == DT_DIR) && (strcmp(de->d_name, ".")!=0) && (strcmp(de->d_name, "..")!=0)){
            int temp = strlen(path); //If it's directory, searching file there
            strcat(path, "/");
            strcat(path, de->d_name);
            if (search(name, path) == 0){ //If file was found, zero is returned. That way every incarnation of function returns 0, and recursion stops.
                return 0;
            }
            path[temp]='\0';
        }
        else if (strcmp(de->d_name, name) == 0){ //Retunr zero if file was found.
            strcat(path, "/");
            strcat(path, de->d_name);
            printf("%s\n", path);
            return 0;
        }
        de = readdir(dir);
    }
    return 1; //If file wasn't found, return 1
}

int analyze(char* path, char* root){
    FILE* file = fopen(path, "r");
    char str[256];
    char tr[10000];
    strcpy(tr, root); //Backuping root because "search" changes it.
    int i=0; int t;
    while (i!=EOF){
        i = fscanf(file, "%s", str);;
        if (strcmp(str, "Deadlock") == 0)
            return 1;
        if (strcmp(str, "Minotaur") == 0)
            return 2;
        if (strncmp(str, "@include", 8) == 0){
            fscanf(file, "%s", str);
            search(str, root);
            t = analyze(root, tr); //If name of file was found, procedure is searching and analyzing it.
            strcpy(root, tr);
            if (t == 2)
                return 2; //If Minotaur was found, recursion stops.
        }
    }
    return 0;
}

int main()
{
    char path[10000]=".";
    char root[10000]=".";
    search("file.txt", path);
    analyze(path, root);
    return 0;
}
