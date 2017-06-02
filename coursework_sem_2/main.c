/*
Курсовая работа. Второй семестр. Григорьев Иван гр.6304
----------------------------------------------------------------
Программа считывает bmp файл, делит заданную область этого файла
на 4 равные части, меняет их местами по диагонали и записывает
результат в новый bmp файл.
----------------------------------------------------------------
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"
//#define NAME_LIMIT 265
//#define BMP_FILENAME "bmpfile.bmp"
//#define NEW_BMP_FILENAME "changedbmpfile.bmp"

int main() {
    char* bmpFileN=(char*)malloc(100*sizeof(char));
    char* newBmpN=(char*)malloc(100*sizeof(char));
    printf("Insert the BMP file name, please\n");
    scanf("%s", bmpFileN);
    FILE* bmpFile=fopen(bmpFileN, "rb");
    bmHeader BMhead; //заголовок с информацией о файле
    DIBheader DIBhead; //заголовок с информацией о изображении

    if(!correctionCheck1(bmpFile, bmpFileN))
        return 0;

    int x0=-1,y0=-1,x1=-1,y1=-1;
    printf("Coordinates of the left upper corner (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Coordinates of the right bottom corner (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    //Проверка введенных данных
    if(!correctionCheck2(bmpFile, x0, y0, x1, y1))
        return 0;

    /*Создание и заполнение двумерного массива символов информацией о пикселях bmp изображения*/
    char** pixArr=bmpScan(bmpFile, &BMhead, &DIBhead);
    fclose(bmpFile);

    if (DIBhead.width<(x1+1) || DIBhead.height<(y0+1)) { //Если введенная область больше самого изображения
        printf("Fail with the entered area\n");
        return 0;
    }

    newBmpN=createNewBmp(Diags(pixArr, x0, y0, x1, y1), &BMhead, &DIBhead);
    printf("Bmp file /%s/ successfully changed in the same directory with new name /%s/\n\n", bmpFileN, newBmpN);

    free(bmpFileN);
    free(newBmpN);
    return 0;
}
