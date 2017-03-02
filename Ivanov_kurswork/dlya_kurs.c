#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "from_L_4.h"
struct MusicalComposition {
	char name[80]; 
	char author[80]; 
	int year;
	struct MusicalComposition* next;
	struct MusicalComposition* prev;
};

typedef struct MusicalComposition MusicalComposition;
void RemoveNechet(MusicalComposition *head) 
{	int i=0;
		if(head->next==NULL && head->prev==NULL){
				printf("Прежде чем сделать это, добавьте новый(ые) элемент(ы)\n");
				return;
			}
	strcpy(head->name,head->next->name);
            		strcpy(head->author, head->next->author);
            		head->year = head->next->year;
            		            head=head->next;
            if (head->next!=NULL){
            head->prev->next = head->next;
			head->next->prev = head->prev;}
			else head->prev->next=NULL;
	while (head->next)
	{

		if (((++i) % 2) == 0) removeEl(head, head->name);//удаляем далее все чётные элементы, т.к. начинаем с 3ьего элемента
			head=head->next;

	}
	
	if(i%2==1)
		if(head->prev)
			head->prev->next=NULL;

}

void sortirovka(MusicalComposition *head) 
{ 
	int i=count(head);
	int k=0;
	MusicalComposition *curr; // Создаём дополнительный указатель, для перемещения по списку 
	while (k<i){
		while(head->prev)
			head=head->prev;
		
	while (head->next) //Перемещаемся до конца списка 
	{ 
		curr = head;
		while (curr->next) //опять же перемещаемся до конца 
		{ 
			if (strcmp(curr->author,curr->next->author)>0) //Если авор больше то свапает 
				{ 

					MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition)); //Выделяем память для доп. переменной 
					strcpy(tmp->name, curr->next->name); strcpy(tmp->author, curr->next->author); tmp->year = curr->next->year; //функция 
					strcpy(curr->next->name, curr->name); strcpy(curr->next->author, curr->author); curr->next->year = curr->year; //для 
					strcpy(curr->name, tmp->name); strcpy(curr->author, tmp->author); curr->year = tmp->year; //свапа 

					free(tmp);//освобождаем память 
				} 
			curr = curr->next; //продвигаемся 
		} 
		head = head->next; //продвигаемся 
	} 
k++;}
}
