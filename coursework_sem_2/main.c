#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"

int main() {
    char* bmpFileN=(char*)malloc(100*sizeof(char));
    char* newBmpN=(char*)malloc(100*sizeof(char));
    printf("Insert the BMP file name, please\n");
    scanf("%s", bmpFileN);
    FILE* bmpFile=fopen(bmpFileN, "rb");
    bmHeader BMhead; //file header
    DIBheader DIBhead; //pic header

    //checking if file is correct
    if(!correctionCheck1(bmpFile, bmpFileN))
        return 0;

    int x0=-1,y0=-1,x1=-1,y1=-1;
    printf("Coordinates of the left upper corner (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Coordinates of the right bottom corner (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    //checking if coordinates are correct
    if(!correctionCheck2(bmpFile, x0, y0, x1, y1))
        return 0;

    /* scans a file to an array */
    char** pixArr=bmpScan(bmpFile, &BMhead, &DIBhead);
    fclose(bmpFile);

    if (DIBhead.width<(x1+1) || DIBhead.height<(y0+1)) { //if area is not corrrect
        printf("Fail with the entered area\n");
        return 0;
    }

    newBmpN=createNewBmp(Diags(pixArr, x0, y0, x1, y1), &BMhead, &DIBhead);
    printf("Bmp file /%s/ successfully changed in the same directory with new name /%s/\n\n", bmpFileN, newBmpN);

    free(bmpFileN);
    free(newBmpN);
    return 0;
}
