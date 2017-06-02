#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAG 20 
#define MAX_STACK 1000
     
void push(char  (*stack)[MAX_TAG], char *element, int j) //добавляет элемент в массив со стеком
{
    strcpy(stack[j],element);
}

int pop(int j)  //"удаляет" вершину стека, смещает индекс последнего элемента
{ 
    return j-1;
}

int vacuum(int* j) //определяет, пустой ли стек по индексу последнего элемента
{ 
    if(j==-1) return 1;
    else return 0;
}
     
int main(){
    int j = -1;
    char stack[MAX_STACK][MAX_TAG]; 
    char c;
    char tag[MAX_TAG]; //указатель на текущий тэг 
    while (c!='\n')  //пока не закончилась текущая строка
    {
        scanf("%c",&c); //вводим символ
        if (c=='<')    //если этот символ равен символу, открывающему тег
        { 
            scanf("%20[^>]с",tag); //записываем следующие символы, пока не встретим закрывающий символ, в строку tag
            if (strcmp(tag,"br") && strcmp(tag,"hr"))  //если тег не равен тегу <br> или <hr>
            {
                if (tag[0] != '/') //если тег не закрывающий, записываем его в стек, прибавляем к j единицу 
                {
                    j++;
                    push(stack,tag, j);
                }         
                else
                {
                    if (vacuum(j) == 1)//если стек "пустой", след-но последний записанный тег закрывающий, то строка неверная, выходим из программы
                    {
                        printf("wrong");
                        return 0;
                    }
                    else  //если тег закрывающий, но стек не пустой
                    {
                        if (strcmp(stack[j],tag+1) != 0)//если последний элемент стека и тег, не считая одного элемента "/", не идентичны, закрываем программу
                        { 
                            printf("wrong");
                            return 0;
                        }
                        else //если идентичны, "удаляем" последний элемент
                        {
                            j = pop(j);
                        }
                    }
                }
            }
        }                                       
    }
    if (vacuum(j) == 1) //если стек пустой (не осталось открывающих тегов)
    printf("correct");
    else //если стек не пустой
    printf("wrong");
}
