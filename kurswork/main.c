#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "functions.h"

int main()
{
        char* input_file_name = (char*)malloc(sizeof(char)*100);
        printf("Enter the name of the bmp_file:  ");
        fgets(input_file_name,100,stdin);
        *(strchr(input_file_name,'\n')) = '\0';
        int x0,x1,y0,y1;
        x0 = x1 = y0 = y1 = -1;
        printf("Top left coordinates (x0, y0): ");
        scanf("%d %d", &x0, &y0);
        printf("Bottom right coordinates (x1, y1): ");
        scanf("%d %d", &x1, &y1);
        FILE* input_file = fopen(input_file_name, "rb");
        if (errors(input_file, x0,y0,x1,y1) == 0)
        {
                free(input_file_name);
                return 0;
	}
	BMFileHeader info_file;
	BMInfoHeader info_picture;
	char** buffer = bmp(input_file, &info_file, &info_picture);
	fclose(input_file);
	if (info_picture.width < x1+1 || info_picture.height < y0+1)
        {
		printf("Fail with size of picture\n");
		free(input_file_name);
		return 0;
	}
	buffer = rotation(buffer, x0, y0,x1,y1);
	create_new_file(input_file_name,buffer, &info_file, &info_picture);
	printf("\nNew bmp file \"%s\" created\n\n", input_file_name);
	free(input_file_name);
	return 0;
}
