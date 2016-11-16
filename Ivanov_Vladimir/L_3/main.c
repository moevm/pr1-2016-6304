
#include <stdio.h>
#include <stdlib.h>
int main(){
    char c; //вводим переменную для посимвольного ввода  
    int nach= 0, kon= 0, n; // переменные для кол-ва предложений сначала и в конце, для перемещения по массивe
    do{ //посимвольный ввод
        n = 0;
        char* s = (char*)malloc(100000*sizeof(char)); // вводим динамический массив для хранения предложений
        while((c= getchar()) != '!' && c != '?' && c != '.' && c != ';') // условие, чтобы массив заполнялся только символами до первого знака
            {
                if (c == '\t') // условие чтобы табуляции внутри заменить на 1 пробtk
                    s[n]='\0';
                else if (c=='\n'); // если переход на новую строку ничего не делать
                else {
                    s[n]= c; 
                n++;
                }
            }
        s[n++]= c; // вводим в массив значение знака
        if(s[0] == ' ') // если сначала предложения пропуск, то смещает значения на 1 вперёд
            for(n = 0; n<100000; n++)
            {
                s[n]= s[n+1];
            }
        if(c == '?'){ // при вопрос. знаке предложение обнуляется и увеличивается кол-во предложений, которые были в исходном тексте
            nach++;
            n=0;
            }
        if(c == '.' || c == ';'){ // при точке или точке с запятой выводим массив с предложением и увеличиваем на 1 значение обоих счётчиков
            printf("%s\n", s);
            kon++;
            nach++;
        }
    }while(c != '!');
    printf("Количество предложений до %d и количество предложений после %d", nach, kon); // выводим ответ
    return 0;
} 
