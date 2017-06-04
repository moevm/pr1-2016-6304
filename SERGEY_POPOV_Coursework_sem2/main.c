#include <stdio.h>
#include <stdlib.h>

#include "functions.c"

int main()
{
	char filename[250] = "";
	int x0, y0, x1, y1;

	printf("Enter filename:\n");
	scanf("%s", filename);

	printf("Enter x0 and y0:\n");
	scanf("%d %d", &x0, &y0);

	printf("Enter x1 and y1:\n");
	scanf("%d %d", &x1, &y1);
    
    
// Make sure the area is not a point and the width and lenght are not negative
	if (x0 >= x1 || y0 >= y1)
	{
		printf("The area isn't correctly defined\n");
		return 0;
	}
    
// Make sure the area is a square
	if ((y1 - y0) != (x1 - x0))
	{
		printf("The area isn't correctly defined\n");
		return 0;
	}

// Allocate header structures
	BITMAPINFOHEADER bitmapInfoHeader;
	BITMAPFILEHEADER bitmapFileHeader;

// Load BMP file from file and fill header structures, returns pointer to image data
	unsigned char* bitmapData = load_BMP_file(filename, &bitmapFileHeader, &bitmapInfoHeader);
	if ( bitmapData == NULL )
	{
		printf("Cannot open file: %s\n", filename);
		return 0;
	}
    
// Bitmap image starts from bottom-left corner, our square is defined from top-left corner, so - recalculate it
	int temp = y0;
	y0 = bitmapInfoHeader.biHeight-y1-1;
	y1 = bitmapInfoHeader.biHeight-temp-1;
    
// Make sure the square is inside the image
	if (y1 > bitmapInfoHeader.biHeight || x1 > bitmapInfoHeader.biWidth)
	{
		printf("The area isn't correctly defined\n");
		return 0;
	}

// Fill area outside of given square with black
	black_BMP_except_square(bitmapData, &bitmapInfoHeader,x0,y0,x1,y1);
 
// Save changed bitmap image to new file. In our case we don't have to change header structures, so pass them as is
	char new_filename[] = "new_file.bmp";
	int result = save_BMP_file(new_filename, &bitmapFileHeader, &bitmapInfoHeader, bitmapData);

	if ( result != 0 )
	{
		printf("Cannot save file: %s\n", new_filename);
		return 0;
	}
	return result;
}
