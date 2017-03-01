#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isq(char* str){
    int i; int q=0;
    for (i=0; i<strlen(str); i++){
        if ((str[i] == '?') || (str[i] == '!'))
            q=1;
    }
    return q;
}

char* MakeStringGreatAgain(char* str){
    int i; int k;
    char* tmp = (char*)malloc(strlen(str)*sizeof(char));
    while ((str[0] == '\n') || (str[0] == '\t') || (str[0] == ' ')){
        for (i=0; i<strlen(str)-1; i++){
            str[i]=str[i+1];
        }
        str[strlen(str)-1] = '\0';
    }
    return str;
}

int main()
{
    int str_cnt=0; int i=0; int new_str_cnt=0; int k=0;
    char *str = (char*)malloc(100000*sizeof(char));
    char *temp = (char*)malloc(10000*sizeof(char));
    char ch;
    while ((ch=getchar())!='!'){
        str[i++]=ch;
    }
    str[i++]='!';
    str[i]='\0';
    i=0;
    while (i<strlen(str)){
        while ((str[i]!=';') && (str[i]!='.') && (str[i]!='?') && (str[i]!='!')){
            temp[k++]=str[i];
            i++;
        }
        temp[k++]=str[i];
        temp[k]='\0'; k=0;
        if (isq(temp) == 0){
            printf("%s\n", MakeStringGreatAgain(temp));
            new_str_cnt++;
        }
        i++; str_cnt++;
    }
    printf("Количество предложений до %d и количество предложений после %d", str_cnt-1, new_str_cnt);
    return 0;
}
