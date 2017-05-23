#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int recDir(const char* start_dir, int option){
	char current_path[1000];
	char string[200];
	strcpy(current_path, start_dir);
	int result;
	if (option == 1)
		result = 0;
	else if (option == 2)
		result = 1;
	DIR* dir = opendir(current_path);
	struct dirent* de = readdir(dir);
	
	if(dir)
		while(de){
			if((strstr(de->d_name, ".txt")) && (option!=0)){
				int path_len = strlen(current_path);
				strcat(current_path, "/");
				strcat(current_path, de->d_name);
				FILE* file = fopen(current_path, "r");
				current_path[path_len] = '\0';
				fgets(string, 200, file);
				if(string[0] != '\n'){
					int digit;
					char* digits = strtok(string,"  \n");
					while(digits){
					   sscanf(digits, "%d", &digit);
					   if(option == 1)
						result+=digit;
					   else if(option == 2)
						result*=digit;
					digits = strtok(NULL, "  \n");
					}
				}
				fclose(file);
			}

			else{
				if(strcmp(".", de->d_name)!=0 && strcmp("..", de->d_name)!=0 && de->d_type == DT_DIR){
				int path_len = strlen(current_path);
				strcat(current_path, "/");
                                strcat(current_path, de->d_name);
				if(strcmp(de->d_name, "add") == 0){
					if(option == 1)
						result+=recDir(current_path, 1);
					else if(option == 2)
						result*=recDir(current_path, 1);
					else 
						result=recDir(current_path, 1);
				}
				else if(strcmp(de->d_name, "mul") == 0){
                                        if(option == 1)
                                                result+=recDir(current_path, 2);
                                        else if(option == 2)
                                                result*=recDir(current_path, 2);                                        else
                                                result=recDir(current_path, 2);                                 } 
				current_path[path_len] = '\0';
				}
			}
		 
		de = readdir(dir);
	}
	closedir(dir);
	return result;
}


int main(){
	printf("%d\n", recDir(".", 0));
return 0;
}
