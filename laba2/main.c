#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int n;
    struct stack* sec;
    struct stack* first;
} stack;

stack* push(stack* sc, int i)
{
    sc->n=i;
    sc->sec = (stack*)malloc(sizeof(stack));
    sc->sec->first = sc;
    sc = sc->sec;
    printf("ok\n");
    return sc;
}

stack* pop(stack *sc)
{
    if (sc->first != NULL)
    {
        printf("%d\n", sc->first->n);
        sc = sc->first;
        free(sc->sec);
        return sc;
    }
    else
        printf("error\n");

}
stack* top(stack *sc)
{
    if (sc->first != NULL)
    {
        printf("%d\n", sc->first->n);
return sc;
    }
    else
        printf("error\n");

}

int size(stack *sc)
{
    int i=0;
    while (sc->first != NULL)
    {
        i++;
        sc = sc->first;
    }
    return i;
}

int main()
{
    int i=0;
    stack* sc=(stack*)malloc(sizeof(stack));
    sc->first=NULL;
    char input[100];
    char *qwe;
    while(strcmp(input, "exit") !=0)
    {
        gets(input);
        if (strcmp("\0", input)!=0)
        {
            qwe = strtok (input," ");
            if (strcmp("push", qwe) == 0)
            {
                qwe = strtok (NULL," ");
                i=atoi(qwe);
                sc = push(sc, i);
            }
            if (strcmp("pop", qwe) == 0)
            {
                sc = pop(sc);
            }
            if (strcmp("top", qwe) == 0)
            {
                sc = top(sc);
            }
            if (strcmp("size", qwe) == 0)
            {
                printf("%d\n", size(sc));
            }
        }
    }
    printf("bye\n");
}
