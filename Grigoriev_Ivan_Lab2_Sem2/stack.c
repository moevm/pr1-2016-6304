/*
Лабораторная работа №2. Второй семестр. Григорьев Иван гр.6304
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_tag {
    int num;
    struct Node_tag *next;
}Node_t;

void push(Node_t **head, int value) {
    Node_t *tmp =(Node_t*)malloc(sizeof(Node_t)); //sozdaem noviy uzel
    tmp->next=*head; //kidaem na stariy uzel
    tmp->num=value; 
    *head=tmp; //vershinu steka kidaem na noviy uzel
}

void pop(Node_t **head){ //snimaet element s vershini steka, peremeshaya vershinu k sled elemntu
    Node_t *out;
    out=*head; //zapominaem staruyu golovu
    *head=(*head)->next; //prisvaevaem golove noviy adress
    free(out);
}

int main() {
    int count=0, num1, num2;
    Node_t *head = NULL;
    char *string=(char*)malloc(sizeof(char)*100); 
    fgets(string,100,stdin);
    char *pch=strtok(string," "); //berem 1st leksemu
    while(pch){
        if((atoi(pch)!=0)){ //vozvrashaet 0, kogda ne nahodit int
            push(&head, atoi(pch)); //kladem v stack
            count++; //uvelichivaem razmer stack'a
        }
        else if(count>=2){
            num2=head->num; //zapominaem verh stack'a
            pop(&head); //udalyaem verh
            num1=head->num; //zapominaem noviy verh stack'a
            pop(&head); //udalyaem
            count--; //v itoge razmer vsegda budet -1
            if(pch[0]=='+')
                push(&head,num1+num2);
            else if(pch[0]=='-')
                push(&head,num1-num2);
            else if(pch[0]=='*')
                push(&head,num1*num2);
            else if(pch[0]=='/')
                push(&head,num1/num2);
        }
        else{ //esli elementov v stack'e ne dostatochno
            printf("error\n");
            return 0;
        }
        pch=strtok(NULL," "); //peredvigaem ukazatel na sled leksemu
    }
    if(count!=1) //proverka na kol-vo elementov
        printf("error\n");
    else
        printf("%d", head->num); //pechataem edinstvenniy element v stack'e
    return 0;
}
