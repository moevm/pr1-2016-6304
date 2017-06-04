#define TAG 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char tag[200][TAG];
    size_t size;
} Stack_t;

const char * pop(Stack_t *stack){
    stack->size--;
    return stack->tag[stack->size+1];
}

void push(Stack_t *stack, char *tag_push) {
    stack->size++;
    strncpy(stack->tag[stack->size], tag_push,15);
}

int is_empty(Stack_t * stack){
    return stack->size;
}

int main(void) {
    Stack_t head;
    char tag[TAG];
    char tcheck[TAG];   
    head.size=-1;
    char c;
    while ((c = getchar()) != EOF ){
        if (c == '<') {
            scanf("%15[^>]",tag);
            if (strcmp(tag,"br") && strcmp(tag,"hr")){
                if(tag[0] != '/'){
                    push(&head, tag);
                }else{
                    if (is_empty(&head)==-1){
                        printf("wrong");
                        return 0;
                        }
                    else{
                            strcpy(tcheck, pop(&head));
                            if(strcmp(tcheck,tag+1)!=0){
                                printf("wrong");
                                return 0;
                      }
                  }
              }
              }
        }
    }
    if (is_empty(&head)==-1)
        printf("correct");   
    else
        printf("wrong");  
}