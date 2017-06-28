#define FNUM 200
#define PLEN 10000

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char* read(const char*, int*);

int filePath(char *, char [][PLEN], int*, char*);

int main(void){
    int fnum=0; 
    char files[200][PLEN];
    filePath(".", files, &fnum, "file.txt");
    for (int i=0; i<fnum; i++)
    {
        printf("%s", files[i]);
    }
    return 0;
}

int filePath(char *startdir, char files[][PLEN], int* fnum, char* file){
    char ActivePath[PLEN];
    strcpy(ActivePath, startdir);
    DIR *dir; 
    struct dirent *cat;
    if (dir = opendir(ActivePath));
         while(cat = readdir(dir))
        {     
            if(cat->d_type==DT_REG && !strcmp(file, cat->d_name) && strstr(cat->d_name,"."))
            {
                int path_len = strlen(ActivePath);
                strcat(ActivePath, "/");
                strcat(ActivePath, cat->d_name);
                
                char* str;
                int fsize;
                str = read(ActivePath, &fsize);
                printf("%s\n", str);
                
                if (strstr(str, "Minotaur"))
                {
                    printf("FOUND");
                    strcpy(files[(*fnum)++], ActivePath);
                    ActivePath[path_len] = '\0';
                    return 1;
                }
                
                if (strstr(cat->d_name, "Deadlock")) return 0;
                
                char token[FNUM-1][fsize];
                int i = 0;
                char *tmp=strtok(str," \n");
                while(tmp)
                {
                    strcpy(token[i],tmp);
                    printf("%s\n", token[i++]);
                    tmp=strtok(NULL," \n");
                }
                for(int j=0; j<i; j++)
                {
                    if(strstr(token[i], ".txt"))
                    {           
                        filePath(startdir, files, fnum, token[i]);
                        strcpy(files[(*fnum)++], ActivePath);
                        ActivePath[path_len] = '\0';
                    }
                }
            }
        }
            if(cat->d_type == DT_DIR && strcmp(".",cat->d_name) && strcmp("..", cat->d_name))
            {
                int path_len = strlen(ActivePath);
                strcat(ActivePath,"/");
                strcat(ActivePath,cat->d_name);
                filePath(ActivePath, files, fnum, file);
                ActivePath[path_len] = '\0';
            }
    closedir(dir);
    return 1;
}

char *read(const char *current_path, int *file_size)
{
    FILE *file=fopen(current_path,"rt");
    
    fseek(file,0, SEEK_END);
    *file_size = ftell(file);
    fseek(file,0, SEEK_SET);
    
    char *str=(char*)malloc(sizeof(char)*(*file_size));
    int i=0;
    
    char symb;
    while(fscanf(file,"%c",&symb)>0) str[i++]=symb;
    fclose(file);
    return str;
}
