#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

char dir_word[100][100];

int letter_file (char* start, char c)
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
				int i;													
				for (i = 0; strlen(dir_word[i])>0; i++) 
					if (!strcmp(current_path, dir_word[i]))
						break;
				if (!strlen(dir_word[i]))
				{
					strcpy(dir_word[i], current_path);
					flag = 1;
				}
			}								
		}			
		else if (entry->d_type == DT_DIR)
			flag = letter_file(current_path, c);
		current_path[strlen(current_path) - strlen(entry->d_name)-1] = '\0';
	}
	closedir(dir);
	return flag;
}

int main (int c, char** vr)
{
	char word[100];
	int err;
	if (c != 2)
	{
		printf ("Wrong input!\n");
		exit(1);
	}
	if (vr[1][strlen(vr[1])-1] == '/')
		vr[1][strlen(vr[1])-1] = '\0';
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++)
	{
		err = letter_file(vr[1], word[i]);
		if (err < 0)
		{
			printf ("Wrong directory!\n");
			exit(-1);
		}
		else if (!err)
		{
			printf ("Sorry, but i can do nothing with this word.\n");
			exit (0);
		}
	}
	for (int i = 0; strlen(dir_word[i]); i++)
		printf ("%s\n", dir_word[i]);
	return 0;

}
