#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXCEPTIONAL_TAG_1 "<br>"
#define EXCEPTIONAL_TAG_2 "<hr>"

struct stack{
    char value[15];
    struct stack *prev;
};
typedef struct stack stack;

stack *push(stack *head,char* elem) {
    stack* tmp = (stack*)malloc(sizeof(stack));
    strcpy(tmp->value, elem);
    if(head!=NULL) tmp->prev = head;
    else tmp->prev = NULL;
    return tmp;
}

stack *pop(stack *head) {
    stack* tmp = head->prev;
    free(head);
    return tmp;
}

void freeStack(stack *head){
    while (head->prev) {
        stack* tmp=head->prev;
        free(head);
        head = tmp;
    }
}

int checkingException(char* str, int i){
    char* exception=(char*)malloc(sizeof(char)*5);
    int j=0;
    for(j=0;j<4;j++) 
    { *(exception+j)=*(str+i);
      i++;
     }
    *(exception+j)='\0';
    if ((strcmp(exception,EXCEPTIONAL_TAG_1))==0 || strcmp(exception,EXCEPTIONAL_TAG_2)==0) {
    free(exception); 
    return 1;
    }
    return 0;
}

char* creatingTag(int i,char* str, char* strTag){
    int j=0;
    while(*(str+i)!='>'){ 
    if(*(str+i)=='/') { 
    i++; 
    continue;
    } 
    {
    *(strTag+j)=*(str+i); 
    j++; 
    i++;
    }
    }
    *(strTag+j)='\0';
    return strTag;
}

void checkingStr(char* str){
    stack* head=NULL;
    char* strTag=(char*)malloc(sizeof(char)*15);
    int i=0;
    int len;
    len=strlen(str);
    char tag[15];
    while(i<len){
        if(*(str+i)=='<'){
        if(checkingException(str,i)==1) { 
        i+=4; 
	continue;
	}
        else  if(*(str+i+1)!='/') {
		head=push(head, creatingTag(i,str,strTag));
		i+=strlen(head->value);
		}
                else { 
			if(strcmp(head->value,creatingTag(i,str,strTag))==0) {
				i+=strlen(head->value); head=pop(head);
			}  
			else { 
				printf("wrong"); {
                 freeStack(head);
               }
				return;
				} 
			} 
		}
        else i++;
	}
    if (head==NULL) printf("correct\n");
        else {
            printf("wrong\n");
            freeStack(head);
        }
     free(strTag);
    return;
}

int main() {
     char* str=(char*)malloc(3000*sizeof(char));
    int i=0,k=0;
        fgets(str,3000,stdin);
        (*strstr(str,"\n"))= 0;
        checkingStr(str);
    free(str);
return 0;
}
