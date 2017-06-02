#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int mas[200];
    int size;
} Stack;

void push(Stack *stack, char* a) //adds new element
{
    stack->mas[stack->size]=atoi(a);
    printf("ok\n");
    stack->size++;
}

void size(Stack *stack) //shows current size
{
    printf("%d\n", stack->size);
}

int printexit()//ends program
{
    printf("bye\n");
    return 1;
}

void pop(Stack *stack)//prints and deletes top element
{
    printf("%d\n", stack->mas[stack->size-1]);
    stack->size--;
}

void top(Stack *stack)//shows top element
{
    printf("%d\n", stack->mas[stack->size-1]);
}

int main()
{
    Stack stack;
    int i=0, c=1, n, j=0, flag=0;   // c - input strings counter, n - result strings amount counter
    char del[]="\n ";               // i - strtok counter, j - result counter
    char vvod[200][20];             // del - dividing symbols array, vvod - input array
    char mas[200][20];              // mas - in-between result counter                // array - result counter
    vvod[0][0]='0';                 //checking previous result needs array to begin with 1
    while(strcmp(vvod[c-1], "exit\n")!=0)   //reading strings
    {
            fgets(vvod[c], 20, stdin);
            //printf("%s\n", vvod[c]);
            c++;
    }
    for (n=1; n<c; n++)
    {
    char *p=strtok(vvod[n], del); // Divides words from input strings
    while (p != NULL)
    {
        strcpy(mas[i], p);
        p = strtok (NULL, del);
        i++;
    }
    }
    for (n=0; n<i; n++)
    {
        if (flag==0)
        {
            if (strcmp(mas[n], "push")==0)
            {
                push(&stack, mas[n+1]);
                n++; //jumps over the number
            }
            else if (strcmp(mas[n], "size")==0)
            {чё
                size(&stack);
            }
            else if (strcmp(mas[n], "exit")==0)
            {
                flag=printexit();
            }
            else if (stack.size!=0)
            {
                if (strcmp(mas[n], "pop")==0)
                {
                    pop(&stack);
                }
                else if (strcmp(mas[n], "top")==0)
                {
                    top(&stack);
                }
            }
            else
            {
                printf("error\n");
                flag=1;
            }
        }
    }
    return 0;
}
