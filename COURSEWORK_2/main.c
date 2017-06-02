#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct rect
{
	int x1, x2, y1, y2;
	unsigned int square;
}rect;

rect *arr;
int sz = 0;

rect *r_arr;
int r_sz = 0;

void push (rect A, char m)
{
	switch (m)
	{
		case 'a':
			*(arr+(sz++)) = A;
			arr = (rect*)realloc(arr, sizeof(rect)*(sz+1));
			break;
		case 'r':
			*(r_arr+(r_sz++)) = A;
			r_arr = (rect*)realloc(r_arr, sizeof(rect)*(r_sz+1));
			break;
	}
}

void rmv (int n)
{
	for (int i = n, j = n+1; j < sz; i++, j++)
		*(arr+i) = *(arr+j);
	sz--;
}

void is_rect (rect A)
{
	int i;
	for (i = 0; i < sz ; i++)
	{	
		if (((arr+i)->x1 == A.x1) && ((arr+i)->x2 == A.x2) && ((arr+i)->y2 == (A.y1-1)))
		{
			(arr+i)->square += A.square;
			(arr+i)->y2 = A.y1;
			push(A,'r');
			break;
		}
		else if ((((((arr+i)->x1) <= A.x1) && ((arr+i)->x2 >= A.x1)) || ((arr+i)->x1 <= A.x1 && (arr+i)->x2 >= A.x2) || ((arr+i)->x1 > A.x1 && (arr+i)->x2 <A.x2))
					&& ((arr+i)->y2 == (A.y1 - 1)))
		{
			rmv(i); 
			push(A,'r');
			break;
		}
	}	
	if (i == sz)
	{	
		for (i = 0; i < r_sz; i++)
		{
			if ((((((r_arr+i)->x1) <= A.x1) && ((r_arr+i)->x2 >= A.x1)) || ((r_arr+i)->x1 <= A.x1 && (r_arr+i)->x2 >= A.x2) || ((r_arr+i)->x1 > A.x1 && (r_arr+i)->x2 <A.x2)) && ((r_arr+i)->y2 == (A.y1 - 1)))
				break;
		}
		if (i == r_sz)
			push(A,'a');
		else
			push(A, 'r');	
	}
}

void rect_searching (FILE *file, int widht, int height, int padding)
{
	rect A;
	int pixel[3], mod = 0;
	fseek(file, 54, SEEK_SET);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < widht-2; x += 3)
		{
			for (int i = 0; i < 3; i++)
				pixel[i] = fgetc(file);
			if ((pixel[0] != 0xff || pixel[1] != 0xff || pixel[2] != 0xff) || ((x == widht-3) && mod))
			{
				if (mod)
				{
					mod = 0;
					A.x2 = (x-3)/3+1;
					A.square = A.x2 - A.x1 + 1;
					is_rect(A);
				}
				continue;
			}
			if (!mod)															
			{
				A.x1 = x/3;
				A.y1 = A.y2 = y;	
				mod = 1;
				if (x == (widht-3))
				{	
					A.x2 = A.x1;
					is_rect(A);
					mod = 0;
				}
			}
		}
		fseek(file, padding, SEEK_CUR);
	}
}

int main (int count, char** input)
{
	arr = (rect*)malloc(sizeof(rect));
	r_arr = (rect*)malloc(sizeof(rect));
	FILE *bmp = fopen(input[1], "r");
	if (bmp == NULL || !(strstr(input[1], ".bmp")))
	{		printf ("Error, wrong input\n");
			return 0;
	}
	fseek(bmp, 18, SEEK_SET);
	int widht = 0;
	for (int i = 0; i < 4; i++)
		widht += fgetc(bmp)*pow(256, i);
	int height = 0;
	for (int i = 0; i < 4; i++)
		height += fgetc(bmp)*pow(256, i); 
	int b_widht = ((widht*3)%4) ? ((widht*3)/4+1)*4 : widht*3;
	int ix = 0;
	rect_searching(bmp, widht*3, height, b_widht-widht*3);
	if (!sz)
		printf ("There are no white rectangles in %s\n", input[1]);
	else
	{
		for (int i = 0; i < sz; i++)
			ix = ((arr+i)->square > (arr+ix)->square) ? i : ix;
		printf ("Top left corner:\n\t\tX1 = %d\n\t\tY1 = %d\nBottom right corner:\n\t\tX2 = %d\n\t\tY2 = %d\n", (arr+ix)->x1, (arr+ix)->y2, (arr+ix)->x2, (arr+ix)->y1);
	}
	free(arr);
	free(r_arr);
	fclose(bmp);
	return 0;
}
