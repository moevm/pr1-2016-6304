#define PS 200

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char *read(char *activepath, int *file_size)
{
    FILE *file=fopen(activepath,"rt");
    fseek(file,0, SEEK_END);
    *file_size = ftell(file);
    rewind(file);
    
    char *str=(char*)malloc(sizeof(char)*(*file_size));
    int i=0;
    char symb;
    while(fscanf(file,"%c",&symb)>0) str[i++]=symb;
    fclose(file);
    return str;
}

int list_dir(char *newcur_path,char *startdir, char* file, char **paths)
{
    char activepath[10000];
    int depth=0; 
    
    strcpy(activepath,newcur_path); 
    DIR *dir; 
    struct  dirent *de; 

    if(dir= opendir(activepath))
    {
        while(de = readdir(dir))
        {
            int length = strlen(activepath);
                strcat(activepath,"/");
                strcat(activepath,de->d_name);
            if(de->d_type==DT_REG && strstr(file,de->d_name))
            {
                int i,j=0,file_size=0;
                char *str=read(activepath,&file_size);
                char token[PS-1][file_size];
                char *buff=strtok(str," \n");
                while(buff)
                {
                    strcpy(token[j],buff);
                    j++;
                    buff=strtok(NULL," \n");
                }
                for(i=0;i<j;i++)
                { 
                    if(!strcmp(token[i],"@include"));
                        else if(strstr(token[i],"Deadlock")) return depth;
                        else if(strstr(token[i],"Minotaur"))
                        {
                            paths[depth]=(char*)malloc(sizeof(char)*1000);
                            strcpy(paths[depth],activepath);
                            depth=1;
                            return depth;
                        }
                        else
                        {
                            depth=list_dir(startdir,startdir,token[i],paths);
                            if(depth!=0)
                            {
                                paths[depth]=(char*)malloc(sizeof(char)*1000);
                                strcpy(paths[depth],activepath);
                                depth++;
                                return depth;
                            }
                        }
                }
            }
            if( de->d_type == DT_DIR && strcmp(".",de->d_name) && strcmp("..",de->d_name))
            { 
                depth=list_dir(activepath,startdir,file,paths);
            }
            if (depth!=0)
            {
                return depth;
            }
            activepath[length] = '\0';
            de = readdir(dir);
        }
        closedir(dir);
    }
    return depth;
}

int main()
{
    char **paths=(char**)malloc(PS*sizeof(char*));
    int depth=0;
    char *file="file.txt";
    depth=list_dir(".",".",file,paths);
    for(int i=depth-1;i>=0;i--)
    {
        printf("%s\n",paths[i]);
        free(paths[i]);
    }
    free(paths);
    return 0;
}
