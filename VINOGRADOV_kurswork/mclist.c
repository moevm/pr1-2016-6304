#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "type.h"

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);



void push(MusicalComposition* head, MusicalComposition* element)
{
    while(head->next){
        head=head->next;
    }
    head->next=element;
    element->prev=head;
}

int removeEl(MusicalComposition* head, char* name_for_remove){
	if(((head->next)==NULL)&&((head->prev)==NULL)){
		if((strcmp(name_for_remove, head->name))==0){
		printf("Со смертью этого листа нить вашей судьбы обрывается.\nЗагрузите новый лист, чтобы восстановить течение судьбы,\n или живите дальше в проклятом мире, который сами и создали.\n");
		return 0;
		}
	}
	else{
    while (head!=NULL){
        if (strcmp(name_for_remove, head->name) == 0)
           break; 	
        else
            head = head->next;  
    }
    if (head == NULL){
        printf("Element does not exists\n");
    }
    else if  ((head->prev!=NULL)&&(head->next!=NULL)){
       head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    else if (head->next == NULL){
        head->prev->next = NULL; 
    }
    else if(head->prev == NULL){
        while(head->next!=NULL){
            strcpy(head->name,head->next->name);
            strcpy(head->author, head->next->author);
            head->year = head->next->year;
            head=head->next;
        }
        head->prev->next = NULL;
        head->prev = NULL;
    }


}
}
    

int count(MusicalComposition* head)
    {
    int i=0;

    while(head!=NULL){
        head=head->next;
    i++;
    }
    return i;
}

void print_list(MusicalComposition* head)
{
    while(head!=NULL){
        printf("%s %s %d\n", head->name, head->author, head->year);
        head=head->next;   
    }
}

int menu()
{
    char ch;
   // printf("\033[2J"); // Clear the entire screen.  
   // printf("\033[0;0f"); // Move cursor to the top left hand corner 
    printf("What do you want to do?\n1)Print the names of the songs\n2)Add one element\n3)Add some elements\n4)Remove an element\n5)Remove some elements\n6)Add 3 el. after even el.\n7)Exit\n");
    scanf("%c", &ch);
    return ch;
}


int main(){
    MusicalComposition* head =(MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusicalComposition* element_for_push = (MusicalComposition*)malloc(sizeof(MusicalComposition));  
    head=NULL;

    int length, length2, pmenu, pushy;
    char pushn[80];
    char pusha[80];
    int i=0;
    int f=1;

    while(f==1){
    if(head==NULL){
    printf("\033[2J");   
    printf("\033[0;0f"); 
    printf("You need to fill the list up\nEnter a number of elements first\n");
    scanf("%d\n", &length);
    if(length==0){
    goto exit;
    }
    printf("For now you have to write down the name, author and year of out for each composition\n");
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
   // printf("For now you have to write down the name, author and year of out for each composition\n");
    for (i=0;i<length;i++)
    {
        char name[80];
        char author[80];
	scanf("%s %s %d", name, author, &years[i]);
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
	strcpy(names[i], name);
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(authors[i], author);

    }
    head = createMusicalCompositionList(names, authors, years, length);
	}
    int n=count(head);
    pmenu=menu();
    switch(pmenu){
	case '1':
	printf("\033[2J");   
	printf("\033[0;0f"); 
	print_list(head);
	getchar();
	break;
	case '2':
	printf("\033[2J");   
	printf("\033[0;0f"); 
	printf("Enter the name, author and year for this element\n");
	scanf("%s %s %d", pushn, pusha, &pushy);	
	element_for_push = createMusicalComposition(pushn,pusha, pushy);
	push(head, element_for_push);
	getchar();
	break;
	case '3':
	printf("\033[2J");   
	printf("\033[0;0f"); 
	printf("Enter the amount of elements you want to push\n");
	scanf("%d", &length2);
	for(i=0;i<length2;i++){
		printf("Enter the name, author and year for this element\n");
		scanf("%s %s %d", pushn, pusha, &pushy);	
		element_for_push = createMusicalComposition(pushn, pusha, pushy);
		push(head, element_for_push);
	}
	getchar();
	break;
	case '4':
	printf("\033[2J");   
	printf("\033[0;0f"); 
	printf("Enter the name of composition you want to remove\n");
	scanf("%s", pushn);
	f=removeEl(head, pushn);
	getchar();
	break;
	case '5':
	printf("\033[2J");   
	printf("\033[0;0f");
	printf("Enter the author`s name you want to remove\n");
	f=removeExt(head);
	getchar();
	break;
	case '6':
	printf("\033[2J");   
	printf("\033[0;0f"); 
	printf("Enter the data for each of three elements\n");
	pushExt(head);
	getchar();
	break;
	case '7':
	printf("\033[2J");   
	printf("\033[0;0f");
	goto exit;
	break;
	default:
	printf("You, probably, miss the right button. Try again\n");
	getchar();	
	}	
   }
      exit:


      return 0;

}
