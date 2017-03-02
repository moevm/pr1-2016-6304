#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition {
	char name[80]; //Имя композиции
	char author[80]; //Имя автора
	int year;
	struct MusicalComposition* next; //Указатель на следующий узел
	struct MusicalComposition* prev; //Указатель на предыдущий узел
}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
	MusicalComposition* nel = (MusicalComposition*)malloc(sizeof(MusicalComposition));
  //Инициализация аргументов функции
	strcpy(nel->name, name);
	strcpy(nel->author, author);
	nel->year = year;
	nel->next = NULL;
	nel->prev = NULL;
	return nel; //Указатель на новый элемент структуры
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* head=NULL; //ук. на первый элемент
	MusicalComposition* move=NULL; //для хода по списку
	MusicalComposition* fmove=NULL; //для работы со списком

	for(int i=0;i<n;i++)
	{
		move=(MusicalComposition*)malloc(sizeof(MusicalComposition));
		if(i==0)
		{
			head=move;
			strcpy(move->name, array_names[i]);
			strcpy(move->author, array_authors[i]);
			move->year=array_years[i];
			move->next=NULL;
			move->prev=NULL;
			fmove=move;
		}
		else
		{
			fmove->next=move;
			strcpy(move->name, array_names[i]);
			strcpy(move->author, array_authors[i]);
			move->year=array_years[i];
			move->next=NULL;
			move->prev=fmove;
			fmove=move;
		}
	}
	return head; //Указатель на первый элемент списка
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	while (head->next)
    {
		head = head->next;
    }
	head->next = element; //Указатель на след указывает на переданный в функцию элемент
	element->prev = head; //Указатель на предыдущий равен текущему
	element->next = NULL; 
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	while (head)//Пока не встретим последний узел списка
	{
		if (strcmp(head->name, name_for_remove) == 0) //strcmp сравнивает 2 строки(выводи 0 если они одинаковы)
		{
			if(head->next==NULL && head->prev==NULL){ // Если элемент единственный
				return;
			}
			else if (head->next == NULL) //Если последний name в списке совпал с name_for_remove
			{
				head->prev->next = NULL; //Разрываем связи
				return;
			}
			else if (head->prev == NULL)//Если первый name в списке совпал с name_for_remove
			{
				while(head->next!=NULL){ //переносим все на 1 вперёд
            		strcpy(head->name,head->next->name);
            		strcpy(head->author, head->next->author);
            		head->year = head->next->year;
            		head=head->next;
        	}
			}
			
            /*Ниже меняем указатели узлов, чтобы они указывали на предыдущий и следующий элемент относительно 
            удаленного (элемент после пред. будет след., элемент перед след. будет пред.)*/
			else head->next->prev = head->prev;
			head->prev->next = head->next; 			
			break;
		}
		head = head->next; //Ход по узлам списка
	}
}

int count(MusicalComposition*head)
{
	int i = 0;
	while (head) //Пока не встретим последний узел списка
	{
		i++; //Счетчик элементов списка
		head = head->next; //Ход по узлам списка
	}
	return i;
};

void print_names(MusicalComposition*head)
{
	while (head) //Пока не встретим последний узел списка
	{
		printf("Композиция %s, автор %s, год %d \n", head->name, head->author, head->year); //Вывод названий композиций
		head = head->next; //Ход по узлам списка
	}
}
