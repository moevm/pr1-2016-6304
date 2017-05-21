#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_STACK 1000

void push(char** stack, char* tag, int number){
    strcpy(stack[number], tag);
}

void removeEl(char** stack, int number){
    stack[number] = '\0';
}

int checker(char** stack, char* tag, int number){
    int i;
    for(i = 0; i<number; i++){
        if(strstr(tag, stack[i]) != NULL){
            break;
        }
    }
    return i;
}

int main(){
    char** stack = (char**)malloc(SIZE_OF_STACK*sizeof(char*));
    char c;
    int i = 0;
    int key;
    char* array = (char*)malloc(50*sizeof(char));
    scanf("%c", &c);
    while (c != '\n' ){
        if(c == '<'){
            stack[i] = (char*)malloc(50*sizeof(char));
            int j = 0;
            scanf("%c", &c);
            if(c != '/'){
               array[j] = '/';
                j++;
            }
            while((c!='>') && (c!='\n')){
                array[j] = c;
                j++;
                scanf("%c", &c);
            }
            if(c=='\n')
            {
				printf("wrong\n");	
				return 0;
			}
            array[j] = '\0';
            if((strcmp("/br", array)!= NULL) && (strcmp("/hr", array)!=NULL)){
                key = checker(stack, array, i);
                if( i == key){
                    push(stack, array, i);
                    ++i;
                }
                else if(i- 1 == key){
                    removeEl(stack, i);
                    free(stack[i]);
                    --i;
                }
                else{
                    printf("wrong\n");
                    return 0;
                }
                free(array);
            }
        }
        scanf("%c", &c);
    }
    free(stack);
    if(i == 0)
        printf("correct\n");
    else
        printf("wrong");
    return 0;
}
