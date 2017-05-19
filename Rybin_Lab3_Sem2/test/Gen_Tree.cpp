#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_STR 15
#define MIN_STR 5
#define MAX_FILES 5
#define MIN_FILES 3
#define MAX_NUM 1000
#define MIN_NUM 1
#define MAX_LEVELS 8
#define MIN_LEVELS 5

struct Vertex
{
	int flag;
	char path[1000];
};

void Gen_Files(char* dir);
char* Gen_Str();
struct Vertex** Gen_Matrix(int* size);
void Gen_Tree(struct Vertex** arr,int size);

int main()
{

	srand(time(NULL));
	Gen_Files((char*)".");
	int size = 0;
	struct Vertex** arr = Gen_Matrix(&size);

//	for(int i = 0; i < size; i++)
//	{
//		for(int g = 0; g < size; g++)
//			printf("%d ",arr[i][g].flag);
//		printf("\n");
//	}

	Gen_Tree(arr,size);	

	for(int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
	return 0;
}

char* Gen_Str()
{
	int len = MIN_STR + rand() % (MAX_STR - MIN_STR);
	char* str = (char*)malloc(sizeof(char) * len);

	for (int i = 0; i < len; i++)
		str[i] = (char)(97 + rand() % 25);
	return str;
}

void Gen_Files (char* dir)
{
	int file_num = MIN_FILES + rand() % (MAX_FILES - MIN_FILES);
	
	for (int i = 0; i < file_num; i++)
	{

		if (rand() % 2)
		{	
			char file_num [4];
			sprintf(file_num,"%d",rand() % 1000);
			char* file_name = (char*)malloc(sizeof(char) * (strlen("file") + strlen(file_num) + strlen(dir) + 5));
			strcpy(file_name, dir);
			strcat(file_name,"/");
			strcat(file_name, "file");
			strcat(file_name,file_num);
			strcat(file_name, ".txt");

			FILE* file = fopen(file_name, "w");
			
			if(file == NULL)
				return;
			
			int num = MIN_NUM + rand() % (MAX_NUM - MIN_NUM);
			char* str = Gen_Str();
			fprintf(file, "%d %s", num, str);

			free(str);
			free(file_name);
			fclose(file);
		}
		else
		{
			char file_num[4];
			sprintf(file_num,"%d",rand() % 1000);
			char* file_name = (char*)malloc(sizeof(char) * (strlen("file") + strlen(file_num) + strlen(dir) + 2));
			strcpy(file_name, dir);
			strcat(file_name,"/");
			strcat(file_name, "file");
			strcat(file_name,file_num);

			FILE* file = fopen(file_name, "w");

			if(file == NULL)
				return;;

			free(file_name);
			fclose(file);
		}
	}
}

struct Vertex** Gen_Matrix(int* size)
{
	int n = MIN_LEVELS + rand() % (MAX_LEVELS - MIN_LEVELS);	
	*size = n;

	struct Vertex** arr = (struct Vertex**)malloc(sizeof(struct Vertex*) * n);
	for(int i = 0; i < n; i++)
	{
		arr[i] = (struct Vertex*)malloc(sizeof(struct Vertex) * n);
		for(int g = 0; g < n; g++)
			arr[i][g].flag = 0;
	}

	for(int i = 1; i < n; i++)
		arr[rand() % i][i].flag = 1;	

	return arr;
}

void Gen_Tree(struct Vertex** arr,int size)
{
	char current_path[1000];

	for(int i = 0; i < size; i++)
	{
		for(int g = i + 1; g < size; g++)
		{
			if(arr[i][g].flag == 1)
			{
				char* dir_num = (char*)malloc(sizeof(char) * (size / 10 + 2));
				sprintf(dir_num,"%d",g);
				char* dir_name = (char*)malloc((strlen("dir") + strlen(dir_num) + 1) * sizeof(char));
				
				strcpy(dir_name,"dir");
				strcat(dir_name,dir_num);
				free(dir_num);
				
				if(i == 0)					
					strcpy(current_path,".");
				else
				{				
					int num = -1;
					for(int ind = 0; ind < i; ind++)
					{
						if(arr[ind][i].flag == 1)
						{
							num = ind;
							break;
						}
					}

					strcpy(current_path, arr[num][i].path);
				}

				strcpy(arr[i][g].path,current_path);
				strcat(arr[i][g].path,"/");
				strcat(arr[i][g].path,dir_name);
				free(dir_name);
				
				mkdir((const char*)arr[i][g].path,00007);
				Gen_Files(arr[i][g].path);
			}
		}
	}
}
