#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *get_matrix(char *file, int* height, int* widht)
{
	FILE *bmp = fopen(file, "r");
	if (!bmp)
		return NULL;
	fseek(bmp, 18, SEEK_SET);
	for (int i = 0; i < 4; i++)
		*widht += fgetc(bmp) * pow(256, i);
	for (int i = 0; i < 4; i++)
		*height += fgetc(bmp) * pow(256, i);
	int b_widht = ((*widht*3)%4) ? ((*widht*3)/4+1)*4 : *widht*3;
	int padding = b_widht - *widht*3;
	int *matrix = (int*)malloc(sizeof(int)*(*height)*(*widht));
	int pxl[3];
	fseek(bmp, 54, SEEK_SET);
	for (int y = 0; y < *height; y++)
	{
		for (int x = 0; x < *widht; x++)
		{
			for (int i = 0; i < 3; i++)
				pxl[i] = fgetc(bmp);
			*(matrix+y*(*widht)+x) = (pxl[0] != 0xff || pxl[1] != 0xff || pxl[2] != 0xff) ? 0 : 1; 
		}
		fseek(bmp, padding, SEEK_CUR);
	}
	fclose(bmp);

	return matrix;
}