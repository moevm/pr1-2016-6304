#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isQuestion (char* str)
{
    int i;
    for (i=0; i<strlen(str); i++)
        if ((str[i]=='?')||(str[i]=='!'))
            return 1;

    return 0;

}

char* obrabotka(char* str)
{
    int i;
    while ((str[0]=='\n')||(str[0]=='\t')||(str[0]==' '))
    {
        for (i=0; i<strlen(str)-1; i++)
            str[i] = str[i+1];

        str[strlen(str)-1]='\0';
    }
    return(str);
}

int main()
{
    int i = 0;
    int k = 0;
    int doo = 0, posle = 0;
    char ch;
    int str_len = 10;
    int sen_len = 10;
    char* str = (char*)malloc(str_len*sizeof(char));
    char* sen = (char*)malloc(sen_len*sizeof(char));
    while ((ch=getchar())!='!'){
        str[i++]=ch;
        if (i+5>str_len){
            str_len = str_len + 10;
            str = (char*)realloc(str, str_len*sizeof(char));
        }
    }
    str[i++] = ch;
    str[i] = '\0';
    i=0;
    while (i<strlen(str))
    {
        while ((str[i]!=';')&&(str[i]!='.')&&(str[i]!='?')&&(str[i]!='!'))
        {
            sen[k++]=str[i];
            if (k+5>sen_len){
            sen_len = sen_len + 10;
            sen = (char*)realloc(sen, sen_len*sizeof(char));
        }

            i++;
        }
        sen[k++] = str[i];
        sen[k] = '\0';
        k=0;
        if (isQuestion(sen)!=1)
        {
             printf("%s\n", obrabotka(sen));
            posle++;
        }
        doo++;
        i++;
    }
    printf("Количество предложений до %d и количество предложений после %d", doo-1, posle);
    return 0;
}

