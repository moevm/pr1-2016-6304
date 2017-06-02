#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


char* scanData(char* path) {
    FILE* file=fopen(path, "r");
    if(file==NULL){
        //printf("Corrupted file\n");
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int file_size=ftell(file);
    fseek(file, 0, SEEK_SET);
    if(file_size==0){
        //printf("Empty file\n");
        fclose(file);
        return NULL;
        }
    char* data=(char*)malloc(1000*sizeof(char));
    fgets(data, 1000, file);
    fclose(file);
    return(data);
}

void pathSearch(char* path, char** origin, int* str_counter) {
    DIR *dir = opendir(path);
    if (dir != NULL) {
        struct dirent* s_dir=(struct dirent*)malloc(sizeof(struct dirent));
        s_dir =readdir(dir);
        while(s_dir!=NULL) {
            int close = strlen(path);
            strcat(path, "/");
            strcat(path, s_dir->d_name);
            if(s_dir->d_type == DT_REG &&(strcmp(s_dir->d_name, "a.out")!=0)&&(strcmp(s_dir->d_name, "main.c")!=0)) {
                if(scanData(path)!=NULL) {
                    origin[*str_counter]=(char*)malloc(1000*sizeof(char));
                    strcpy(origin[*str_counter], scanData(path));
                    (*str_counter)++;
                }
            }
            if (s_dir->d_type == DT_DIR && strcmp(s_dir->d_name, ".") != 0 && strcmp(s_dir->d_name, "..") != 0) {
                pathSearch(path,origin,str_counter);
            }
            path[close] = '\0';
            s_dir = readdir(dir);
        }
        closedir(dir);
    } else return;

}

int compare(const void* a, const void* b) {
    return atoi(*(char**)a) - atoi(*(char**)b);
}


int main() {
    char** origin=(char**)malloc(1000*sizeof(char*));
    char path[1000]=".";
    int i=0;
    int str_counter=0;
    pathSearch(path, origin, &str_counter);
    qsort(origin, str_counter, sizeof(char*), compare);
    for (i=0; i<str_counter; i++) {
        printf("%s\n", origin[i]);
    }
    for (i=0; i<str_counter; i++) {
        free(origin[i]);
    }
    free(origin);
    return 0;
}

int compare(const void* a, const void* b) {
    return atoi(*(char**)a) - atoi(*(char**)b);
}

int main() {
    char** origin=(char**)malloc(1000*sizeof(char*));
    char path[1000]=".";
    int i=0;
    int str_counter=0;
    pathSearch(path, origin, &str_counter);
    qsort(origin, str_counter, sizeof(char*), compare);
    for (i=0; i<str_counter; i++) {
        printf("%s\n", origin[i]);
    }
    for (i=0; i<str_counter; i++) {
        free(origin[i]);
    }
    free(origin);
    return 0;
}	