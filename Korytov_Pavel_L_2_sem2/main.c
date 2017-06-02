#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 600
typedef struct num{
    int a;
    struct num *next;
    struct num *prev;
}num;

num* stackInit(num* stack){ //Initializing stack
    stack = (num*)malloc(sizeof(num));
    stack->prev = NULL;
    return stack;
}

num* push(num* stack, int a){ //Pushing element to the stack
    if (stack!=NULL){
        stack->a = a;
        stack->next = (num*)malloc(sizeof(num));
        stack->next->prev=stack;
        stack = stack->next;
        return stack;
    }
    return NULL;
}



void pop(num** stack2, int* a){
    num* stack = *stack2;
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

int size(num* stack){
    int i=0;
    while (stack->prev!=NULL){
        i++;
        stack = stack->prev;
    }
    return i;
}

int getLastTwo(num** stack, int *a, int *b){ //Getting last two elements
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
    int a; int b; int err = 0;
    char* str = (char*)malloc(N*sizeof(char));
    fgets(str, N, stdin); //Input. I couldn't figure out the ending symbol of input, so fgets instead of getchar cycle
    num* stack = NULL;
    char *s = strtok(str, " ");
    while ((s!=NULL) && (err == 0)){ //There is no point of going through the cycle if an error was found
        switch (s[0]){
            case '+':
                err = getLastTwo(&stack, &a, &b);
                stack = push(stack, a+b);
                break;
            case '*':
                err = getLastTwo(&stack, &a, &b);
                stack = push(stack, a*b);
                break;
            case '/':
                err = getLastTwo(&stack, &a, &b);
                stack = push(stack, b/a);
                break;
            default:
                if ((s[0]=='-') && ((s[1] == '\0') || (s[1] == '\n'))){ //Both "-" and negative number start with '-'
                    err = getLastTwo(&stack, &a, &b); //So i check this case separately
                    stack = push(stack, b-a);
                }
                else{
                    if (stack == NULL) //If there were no pushes, init stack.
                        stack = stackInit(stack); //It's easier to understand that way if there were no "oush" calls.
                    stack = push(stack, atoi(s));
                }
                break;
        }
        s = strtok(NULL, " ");
    }
    if ((err == 1) || (size(stack)!=1)) //Checking also if there is more than one element in stack
        printf("error\n");
    else
        printf("%d", stack->prev->a);
    while (stack!=NULL){
       pop(&stack, &a);
    }
    return 0;
}
