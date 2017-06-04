#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 600
typedef struct index{
    int a;
    struct index *next;
    struct index *prev;
}index;

index* stackInit(index* stack){ 
    stack = (index*)malloc(sizeof(index));
    stack->prev = NULL;
    return stack;
}

index* push(index* stack, int a){ 
    if (stack!=NULL){
        stack->a = a;
        stack->next = (index*)malloc(sizeof(index));
        stack->next->prev=stack;
        stack = stack->next;
        return stack;
    }
    return NULL;
}



void pop(index** stack2, int* a){
    index* stack = *stack2;
    if (stack!=NULL){
        if (stack->prev!=NULL){
            *a=stack->prev->a;
            stack = stack->prev;
            free(stack->next);
            *stack2 = stack;

        }
        else {
            free(*stack2);
            *stack2 = NULL;
        }
    }
}

int size(index* stack){
    int i=0;
    while (stack->prev!=NULL){
        i++;
        stack = stack->prev;
    }
    return i;
}

int getLastTwo(index** stack, int *a, int *b){ 
    pop(stack, a);
    if (*stack!= NULL){
        pop(stack, b);
        if (*stack!=NULL){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a; int b; int end= 0;
    char* str = (char*)malloc(N*sizeof(char));
    fgets(str, N, stdin); 
    index* stack = NULL;
    char *k = strtok(str, " ");
    while ((k!=NULL) && (end == 0)){ 
        switch (k[0]){
            case '+':
                end = getLastTwo(&stack, &a, &b);
                stack = push(stack, a+b);
                break;
            case '*':
                end = getLastTwo(&stack, &a, &b);
                stack = push(stack, a*b);
                break;
            case '/':
                end = getLastTwo(&stack, &a, &b);
                stack = push(stack, b/a);
                break;
            default:
                if ((k[0]=='-') && ((k[1] == '\0') || (k[1] == '\n'))){ 
                    end = getLastTwo(&stack, &a, &b); 
                    stack = push(stack, b-a);
                }
                else{
                    if (stack == NULL) 
                        stack = stackInit(stack); 
                    stack = push(stack, atoi(k));
                }
                break;
        }
        k = strtok(NULL, " ");
    }
    if ((end == 1) || (size(stack)!=1))
        printf("error\n");
    else
        printf("%d", stack->prev->a);
    while (stack!=NULL){
       pop(&stack, &a);
    }
    return 0;
}
