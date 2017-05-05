//Выполнил Иванов Владимир 6304
//Задание представлено в отчёте

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int numb;
    struct stack *prev;
};

typedef struct stack stack;

stack *push(stack *up, int n){
    stack* newup = (stack*)malloc(sizeof(stack));
    newup->numb = n;
    if(up != NULL) newup->prev = up;
    else newup->prev = NULL;
    return newup;
}

void pop(stack **up){
    stack* befup=*up;
    *up = (*up)->prev;
    free(befup);
}

int main(){
  stack *up=NULL;
  char arr[200];
  int i,e1,e2,k=0,el;
  fgets(arr,200,stdin);
  char *tmp=strtok(arr," "); //Берём символ(число) до пробела
  while(tmp){
    el=atoi(tmp); //Преобразуем char в integer
    if(el!=0 || (tmp[0]-48)==0){ //Если atoi возвращает не 0, либо сам символ и есть 0, то добавляем в стек
      up=push(up,el);
      k++;//счётчик элементов в стеке
    }
    else if(k>=2){
      e2=up->numb; //записываем верхний
      pop(&up); //спускаемся вниз
      e1=up->numb; //записываем следующий
      pop(&up); //спускаемся вниз
      k--;//после следующей операции записываем в стек результат
      switch(tmp[0]){
        case '+': up=push(up,e1+e2);break;
        case '-': up=push(up,e1-e2);break;
        case '*': up=push(up,e1*e2);break;
        case '/': up=push(up,e1/e2);break;
        default: printf("error");return 0; //если введён другой символ
      }
    }
    else{ printf("error"); return 0;} //если в стеке недостаточно чисел
    tmp = strtok(NULL, " ");
  }
  if(k==1) printf("%d",up->numb); //проверка на наличие в стеке лишних элементов
  else printf("error");
  return 0;
}
