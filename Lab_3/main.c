#define MAXPATH 200
#define MAXLENGTH 1000

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char* read(char *cpath, int *fsize);

int filefinder(char *npath, char *startdir, char* file, char **paths);



int main()
{
    char **paths=(char**)malloc(MAXPATH*sizeof(char*));
    int depth=0;
    depth=filefinder(".", ".", "file.txt", paths);
    
    for(int i=depth-1;i>=0;i--)
    {                       
        printf("%s\n",paths[i]);
        free(paths[i]);
    }
    free(paths);
    return 0;
}



char *read(char *cpath, int *fsize)
{
    FILE *file=fopen(cpath,"r");
    fseek(file,0, SEEK_END);
    *fsize = ftell(file);
    rewind(file);
    char *str=(char*)malloc(sizeof(char)*(*fsize));
    fread(str, sizeof(char), *fsize, file);
    fclose(file);
    return str;
}



int filefinder(char *npath, char *startdir, char* file, char **paths)
{
    char cpath[MAXLENGTH]; 
    int depth = 0; 
    strcpy (cpath, npath);
    DIR *dir = opendir(cpath); 
    struct  dirent *cat = readdir(dir);
    while(cat) 
    {
        int path_len = strlen(cpath);
        strcat(cpath, "/");
        strcat(cpath,cat->d_name);            
        if(cat->d_type == 8 && !strcmp(cat->d_name, file) && strstr(cat->d_name,".txt"))
        {
            int j = 0;
            int fsize = 0;
            char *str=read(cpath,&fsize);
            if(strstr(str, "Minotaur"))
            {
                paths[depth]=(char*)malloc(sizeof(char)*1000);
                strcpy(paths[depth],cpath);
                depth=1;
                return depth;
            }   
            if(strstr(str,"Deadlock")) return depth;
            char tokens[MAXPATH][fsize];
            char *item=strtok(str," \n");
            while(item!=NULL)
            {
                strcpy(tokens[j++],item);
                if(strstr(tokens[j-1], ".txt"))
                {
                    depth=filefinder(startdir, startdir, tokens[j-1], paths);
                    if (depth)
                    {
                        paths[depth]=(char*)malloc(sizeof(char)*1000);
                        strcpy(paths[depth++],cpath);
                        return depth;
                    }
                }
                item=strtok(NULL," \n");
            }
        }
        if (cat->d_type == 4 && strcmp(".",cat->d_name) && strcmp("..",cat->d_name))
        { 
            depth = filefinder(cpath, startdir, file, paths);
        }
        cpath[path_len] = '\0'; 
        cat = readdir(dir);  
    }
    closedir(dir);
    return depth;
}