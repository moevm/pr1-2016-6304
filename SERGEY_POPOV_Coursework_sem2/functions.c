#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"

unsigned char* load_BMP_file(char* filename, BITMAPFILEHEADER* bitmapFileHeader, BITMAPINFOHEADER* bitmapInfoHeader)
{
// Open filename in read binary mode
    FILE* fp = fopen(filename,"rb");
    if (fp == NULL)
    {
        return NULL;
    }
    
// Read the bitmap file header
    fread(bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    
// Verify that this is a bmp file by checking bitmap id
     if (bitmapFileHeader->bfType != 0x4D42)
     {
         fclose(fp);
         return NULL;
     }
    
// Read the bitmap info header
    fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
    
// Move file pointer to the begining of bitmap data
    fseek(fp, bitmapFileHeader->bfOffBits, SEEK_SET);
    
// Calculate padding
    int padding = 0;
    while ((bitmapInfoHeader->biWidth * 3 + padding) % 4 != 0)
    {
        padding++;
    }
    
// Calculate new width, which includes padding
    int width_pad = bitmapInfoHeader->biWidth * 3 + padding;
    
// Allocate memory to store image data (non-padded)
unsigned char* bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biWidth * bitmapInfoHeader->biHeight * 3 * sizeof(unsigned char));
    
// Verify memory allocation
    if (bitmapImage == NULL)
    {
        fclose(fp);
        return NULL;
    }
    
// Allocate temporary memory to read width_pad size of data (one row)
    unsigned char* row = (unsigned char *)malloc(width_pad * sizeof(unsigned int));
    
// Read row by row of data and remove padded data.
    int i;
    for (i = 0; i<bitmapInfoHeader->biHeight; i++)
    {
    // Read width_pad length of data (one row)
        fread(row, sizeof(unsigned char), width_pad, fp);
        
    // Move pixels to bitmapImage and swap RB component.
    // BMP stores in BGR format, my usecase needs RGB format
        int j;
        for (j = 0; j < bitmapInfoHeader->biWidth * 3; j += 3)
        {
            int index = (i * bitmapInfoHeader->biWidth * 3) + j;
            bitmapImage[index + 2] = row[j + 0];
            bitmapImage[index + 1] = row[j + 1];
            bitmapImage[index + 0] = row[j + 2];
        }
    }
// Free temporary allocated data
    free(row);
    
// Close file and return bitmap image data
    fclose(fp);
    return bitmapImage;
}


int save_BMP_file(char* filename, BITMAPFILEHEADER* bitmapFileHeader, BITMAPINFOHEADER* bitmapInfoHeader, unsigned char* bitmapImage)
{
// Open filename in write binary mode
    FILE* fp = fopen(filename,"wb");
    if (fp == NULL)
    {
        return -1;
    }
    
// Write the bitmap file header
    fwrite(bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    
// Write the bitmap info header
    fwrite(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
    
// Calculate padding
    int padding = 0;
    while ((bitmapInfoHeader->biWidth * 3 + padding) % 4 != 0)
    {
        padding++;
    }
    
// Calculate new width, which includes padding
    int width_pad = bitmapInfoHeader->biWidth * 3 + padding;
    
// Allocate temporary memory to write width_pad size of data (one row)
    unsigned char* row = (unsigned char *)malloc(width_pad * sizeof(unsigned int));
    
// Write row by row of data and add padded data.
    int i;
    for (i = 0; i<bitmapInfoHeader->biHeight; i++)
    {
    // Move pixels from bitmapImage to row and swap RB component.
    // BMP stores in BGR format, my usecase needs RGB format
        int j, index=0;
        for (j = 0; j < bitmapInfoHeader->biWidth * 3; j += 3)
        {
            index = (i * bitmapInfoHeader->biWidth * 3) + j;
            row[j + 0] = bitmapImage[index + 2];
            row[j + 1] = bitmapImage[index + 1];
            row[j + 2] = bitmapImage[index + 0];
        }
    // Write padding zeros at the end of row
        for (j = bitmapInfoHeader->biWidth * 3; j < width_pad; j+= 3)
        {
            index = (i * bitmapInfoHeader->biWidth * 3) + j;
            row[j + 0] = 0;
            row[j + 1] = 0;
            row[j + 2] = 0;
        }
    // Write width_pad length of data (one row)
        fwrite(row, sizeof(unsigned char), width_pad, fp);
    }
    // Free temporary allocated data
    free(row);

    if (ferror(fp))
    {
        fclose(fp);
        return -1;
    }
// Close file
    fclose(fp);
    return 0;
}


void black_BMP_except_square(unsigned char* bitmapImage, BITMAPINFOHEADER* bitmapInfoHeader, int x0, int y0, int x1, int y1)
{
    int i, j;
    for (i = 0; i < bitmapInfoHeader->biHeight; i++)
    {
        for (j = 0; j < bitmapInfoHeader->biWidth * 3; j += 3)
        {
            if ((j < (x0*3) || j > (x1*3)) || (i < y0 || i > y1))
            {
                int index = (i * bitmapInfoHeader->biWidth * 3) + j;
                bitmapImage[index + 2] = 0;
                bitmapImage[index + 1] = 0;
                bitmapImage[index + 0] = 0;
            }
        }
    }
}
