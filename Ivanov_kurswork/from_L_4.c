#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct MusicalComposition {
	char name[80]; 
	char author[80]; 
	int year;
	struct MusicalComposition* next;
	struct MusicalComposition* prev;
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char *name, char* author, int year)
{
	MusicalComposition* new = (MusicalComposition*)malloc(sizeof(MusicalComposition)); 
	strcpy(new->name, name);
	strcpy(new->author, author);
	new->year = year;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *prev = head;
	MusicalComposition *curr;
	for (int i = 1; i < n; ++i)
	{
		curr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		curr->prev = prev;
		prev->next = curr;
		prev = curr;
	}
	return head; 
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	while (head->next) 
		head = head->next;
	head->next = element;
	element->prev = head;
	element->next = NULL; 
}


void removeEl(MusicalComposition*head, char*name_for_remove)
{
while (head)//Двигаемся пока список не закончится
	{
		if (strcmp(head->name, name_for_remove) == 0)//Проверяем на совпадение, и если совпало
		{
			if(head->next==NULL && head->prev==NULL){ // Если элемент единственный
				printf("Прежде чем сделать это, добавьте новый(ые) элемент(ы)\n");
				return;
			}
			else if (head->next == NULL)//Если последний элемент совпал
			{
				head->prev->next = NULL;//Разрываем с ним связь
				return;
			}
			else if (head->prev == NULL)//Если первый
			{
				while(head->next!=NULL){ //переносим все на 1 вперёд
            		strcpy(head->name,head->next->name);
            		strcpy(head->author, head->next->author);
            		head->year = head->next->year;
            		head=head->next;
        	}
			}
			else{//если по серединке
			head->prev->next = head->next; //Элемент после пред. будет след.
			head->next->prev = head->prev;//Элемент перед след. будет пред.
			}
			break;
		}

		head = head->next; //передвижение
	}
head->prev->next = head->next; //Удаляет последний элемент, если надо удалить первый , т.к. он продублируется
}
int count(MusicalComposition*head)
{
	int i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return i;
};

void print_names(MusicalComposition *head)
{
	while (head)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}
