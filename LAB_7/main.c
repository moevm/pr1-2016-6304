#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int letter_file (char *dir_word, char *start, char c)
{
	DIR *dir = opendir(start);
	if (dir == NULL)
		return -1;
	struct dirent *entry;
	char current_path[1000];
	int flag = 0;
	strcpy(current_path, start);
	while ((entry = readdir(dir)) && !flag)
	{
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;
		strcat(current_path, "/");
		strcat(current_path, entry->d_name);
		if (entry->d_type == DT_REG)
		{
			if ((c == (entry->d_name)[0]) && (strlen(entry->d_name) == 5)) 
			{	
				if(!strstr(dir_word, current_path))	
				{
					strcat(dir_word, current_path);
					strcat(dir_word, "\n");
					flag = 1;
				}		
			}								
		}			
		else if (entry->d_type == DT_DIR)
			flag = letter_file(dir_word, current_path, c);
		current_path[strlen(current_path) - strlen(entry->d_name)-1] = '\0';
	}
	closedir(dir);
	return flag;
}

int main (int c, char** vr)
{
	char dir_word[10000];
	char word[100];
	int err;
	if (c != 2)
	{
		printf ("Wrong input!\n");
		return 0;
	}
	if (vr[1][strlen(vr[1])-1] == '/')
		vr[1][strlen(vr[1])-1] = '\0';
	scanf("%s", word);

	for (int i = 0; i < strlen(word); i++)
	{
		err = letter_file(dir_word, vr[1], word[i]);
		switch (err)
		{
			case -1: printf ("Wrong directory!\n"); return 0;
			case 0: printf ("Sorry, but i can do nothing with this word.\n"); return 0; 
		}
	}
	printf ("%s", dir_word);
	return 0;
}