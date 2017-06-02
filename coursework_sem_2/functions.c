#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"


int correctionCheck1(FILE *bmpFile, char* bmpFileN) {

    if (bmpFile==NULL) { //if file is not open correct
        printf("Fail with %s\n.", bmpFileN);
        return 0;
    }
    return 1;
}

int correctionCheck2(FILE *bmpFile, int x0, int y0, int x1, int y1) {

    //checking if coordiantes are correct
    if (x0<0 || y0<0 || x1<0 || y1<0 || (x1-x0)<0 || (y0-y1)<0) {
        printf("\nFail; with coordinates. The entered coordinates are not correct!\n");
        fclose(bmpFile);
        return 0;
    }
    /*checking if zone is a square*/
    if((x1-x0)!=(y0-y1)) {
        printf("\nFail with coordinates. The area is not a square shape!\n");
        fclose(bmpFile);
        return 0;
    }
    return 1;
}

char **bmpScan(FILE *bmpFile, bmHeader *BMhead, DIBheader *DIBhead) {
    int i,j,k=0;

    /* checking file size */
    fseek(bmpFile,0,SEEK_END); //moves pointer to the end of the file

    /*gets file size in bytes */
    int bmpSize=ftell(bmpFile);

    fseek(bmpFile,0,SEEK_SET); //moves pointer to the start

    char* bmpArr=(char*)malloc(sizeof(char)*bmpSize);
    fread(bmpArr, sizeof(char), bmpSize, bmpFile); //reads file to array

    *BMhead=*((bmHeader*)bmpArr); //writes down file header
    bmpArr+=sizeof(bmHeader); //moves pointer forward on a header size
    *DIBhead=*((DIBheader*)bmpArr); //writes down the pic header
    bmpArr-=sizeof(bmHeader);
    bmpArr+=BMhead->offsetToPixels; //moves pointer to a pixel array

    int line=3*(DIBhead->width)+(DIBhead->width%4); //counts amount of memory for each line

    //scans pic to an array
    char** pixArr=(char**)malloc(sizeof(char*)*DIBhead->height);
    for(i=0; i<DIBhead->height; i++) {
        pixArr[i]=(char*)malloc(sizeof(char)*line);
        for (j=0; j<line; j++)
            pixArr[i][j]=bmpArr[k++];
    }

    return pixArr;
}

char **Diags(char **pixArr, int x0, int y0, int x1, int y1) {
    int i=y1;
    int j=x0;

    RGB* pixelsString=NULL; //pointer to a pixel array

    RGB temp;
    for(i; i<=y0; i++) {
        pixelsString=(RGB*)pixArr[i]; //char string to a pixel string
        for(j; j<=x1; j++) {
            temp=pixelsString[j];
            temp.Blue=0x00;
            temp.Green=0x00;
            temp.Red=0x00;
            pixelsString[j]=temp;
            temp=pixelsString[x1-j];
            temp.Blue=0x00;
            temp.Green=0x00;
            temp.Red=0x00;
            pixelsString[x1-j]=temp;
            j=x1+1;
        }
        j=x0+i+1;
    }
}


char* createNewBmp(char** pixArr, bmHeader* BMhead, DIBheader* DIBhead) {
    int i,j;
    char* newBmpN=(char*)malloc(100*sizeof(char));
    printf("Insert the name of new BMP file, please\n");
    scanf("%s", newBmpN);
    FILE* newBMPFile=fopen(newBmpN,"wb");

    //writes headers in new file
    fwrite(BMhead, sizeof(bmHeader), 1, newBMPFile);
    fwrite(DIBhead, sizeof(DIBheader), 1, newBMPFile);

    int realPix=3*DIBhead->width; //counts amount of memory for pic string
    int align=DIBhead->width%4; //counts amount of memory for aligning

    for(i=0; i<DIBhead->height; i++) {
        fwrite(pixArr[i], sizeof(char), realPix, newBMPFile); //writes pixels in a new file
        for (j=0; j<align; j++)
            fputc(0, newBMPFile); //adding nulls to aligning
    }

    fclose(newBMPFile);
    return newBmpN;
}
