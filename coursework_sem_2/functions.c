#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"

//#define NEW_BMP_FILENAME "changedbmpfile.bmp"

int correctionCheck1(FILE *bmpFile, char* bmpFileN) {

    if (bmpFile==NULL) { //проверка на корректность открытия файла
        printf("Fail with %s\n.", bmpFileN);
        return 0;
    }
    return 1;
}

int correctionCheck2(FILE *bmpFile, int x0, int y0, int x1, int y1) {

    //проверка на корректность координат
    if (x0<0 || y0<0 || x1<0 || y1<0 || (x1-x0)<0 || (y0-y1)<0) {
        printf("\nFail; with coordinates. The entered coordinates are not correct!\n");
        fclose(bmpFile);
        return 0;
    }
    /*проверка на то, чтобы разность x и y координат была нечетной, для корректного
      разбиения на 4 равные части*/
    if((x1-x0)!=(y0-y1)) {
        //if (((x1-x0)%2!=0) /*|| ((y0-y1)%2==0)*/) {
        printf("\nFail with coordinates. The area is not a square shape!\n");
        fclose(bmpFile);
        return 0;
    }
    return 1;
}

char **bmpScan(FILE *bmpFile, bmHeader *BMhead, DIBheader *DIBhead) {
    int i,j,k=0;

    /*Корректное определение размера файла*/
    fseek(bmpFile,0,SEEK_END); //перемещает указатель в конец файла

    /*возвращает значение указателя текущего положения
    (значение соответствующее количеству байт от начала файла)*/
    int bmpSize=ftell(bmpFile);

    fseek(bmpFile,0,SEEK_SET); //перемещает указатель обратно в начало


    //fread(&BMhead, sizeof(bmHeader), 1, bmpFile);

    //fread(&DIBhead, sizeof(DIBheader), 1, bmpFile);
    char* bmpArr=(char*)malloc(sizeof(char)*bmpSize);
    fread(bmpArr, sizeof(char), bmpSize, bmpFile); //считывание файла

    *BMhead=*((bmHeader*)bmpArr); //заголовок с информацией о файле
    bmpArr+=sizeof(bmHeader); //указатель сдвигается на размер заголовка
    *DIBhead=*((DIBheader*)bmpArr); //заголовок с информацией о изображении
    bmpArr-=sizeof(bmHeader);
    bmpArr+=BMhead->offsetToPixels; //передвигаем указатель на битовый массив, описывающий само изображение

    int line=3*(DIBhead->width)+(DIBhead->width%4); //каждый пиксель кодируется 24 битами + выравнивание

    //заполнение двумерного массива
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

    RGB* pixels_string=NULL;

    RGB temp;
    for(i; i<=y0; i++) {
        pixels_string=(RGB*)pixArr[i];
        for(j; j<=x1; j++) {
            temp=pixels_string[j];
            temp.Blue=0x00;
            temp.Green=0x00;
            temp.Red=0x00;
            pixels_string[j]=temp;
            j=x1+1;
        }
        //i=y1+1;
        j=x0+i+1;
    }
    for(i=y1; i<=y0; i++) {
        pixels_string=(RGB*)pixArr[i];
        for(j=x1; j>=x0; j--) {
            temp=pixels_string[x1-j];
            temp.Blue=0x00;
            temp.Green=0x00;
            temp.Red=0x00;
            pixels_string[x1-j]=temp;
            j=x0-1;
        }
        //i=y1+1;
        j=x1-i-1;
    }
    return pixArr;
}

/*char **bmpReflection(char **pixArr, int x0, int y0, int x1, int y1) {
    int i,j;
    //int x=(x1+x0)/2; //х координата половины области
    //int y=(y0+y1)/2; //y координата половины области
    int mid=(x1-x0)/2;
    //int height=(y0-y1)/2;

    RGB* pixels_string=NULL; //указатель на строку из пикселей
    RGB temp; //указатель на пиксель

    for (i=y1; i<=y0; i++) {
        pixels_string=(RGB*)pixArr[i]; //char строка приводится к строке пикселей
        for (j=x0; j<=mid; j++) {
            temp=pixels_string[j];
            printf("b:%x\ng:%x\nr:%x\n", temp.Blue, temp.Green, temp.Red);
            temp.Blue=0x00;
            temp.Green=0x00;
            temp.Red=0x00;
            pixels_string[j]=temp;
            //pixels_string[x1-j]=pixels_string[j];
        }
    }
    return pixArr;
}*/

char* createNewBmp(char** pixArr, bmHeader* BMhead, DIBheader* DIBhead) {
    int i,j;
    char* newBmpN=(char*)malloc(100*sizeof(char));
    printf("Insert the name of new BMP file, please\n");
    scanf("%s", newBmpN);
    FILE* newBMPFile=fopen(newBmpN,"wb");

    //запись заголовков
    fwrite(BMhead, sizeof(bmHeader), 1, newBMPFile);
    fwrite(DIBhead, sizeof(DIBheader), 1, newBMPFile);

    int realPix=3*DIBhead->width; //число байт содержащих информацию о пикселях
    int align=DIBhead->width%4; //число байт для выравнивания

    for(i=0; i<DIBhead->height; i++) {
        fwrite(pixArr[i], sizeof(char), realPix, newBMPFile); //запись растра
        for (j=0; j<align; j++)
            fputc(0, newBMPFile); //дописывание нулей
    }

    fclose(newBMPFile);
    return newBmpN;
}
