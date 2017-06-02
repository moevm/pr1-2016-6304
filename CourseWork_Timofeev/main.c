#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BmpStructures.h"
#include "functions.h"

int main()
{
	char* BmpName = (char*)malloc(sizeof(char)*100);
	printf("Enter name of the BMP file:  ");
	fgets(BmpName,100,stdin);
	*(strchr(BmpName,'\n')) = '\0';
	int x0,x1,y0,y1;
	x0 = x1 = y0 = y1 = -1;
	printf("Top left coordinates (x, y): ");
	scanf("%d %d", &x0, &y0);
	printf("Bottom right coordinates (x, y): ");
	scanf("%d %d", &x1, &y1);
	FILE* input_file = fopen(BmpName, "rb");
	if (CheckingErrors(input_file, x0,y0,x1,y1) == 0)
	{
		free(BmpName);
		return 0;
	}
	BMFileHeader FileInfo;
	BMInfoHeader ImageInfo;
	char** buf = LoadBmp(input_file, &FileInfo, &ImageInfo);
	fclose(input_file);
	if (ImageInfo.width < x1+1 || ImageInfo.height < y0+1)
	{
		printf("Fail with area\n");
		free(BmpName);
		return 0;
	}
	buf = AreaRotate(buf, x0, y0,x1,y1);
	NewBmp(BmpName,buf, &FileInfo, &ImageInfo);
	printf("Rotated BMP file \"%s\" created\n", BmpName);
	free(BmpName);
	free(buf);
	return 0;
}
