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

MusicalComposition* createMusicalComposition(char* name, char* author, int year);//Прототип функции для создания элемента списка
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);//Прототип функции, которая создает список музыкальных композиций MusicalCompositionList
void push(MusicalComposition* head, MusicalComposition* element);//Прототип функции, которая добавляет element в конец списка musical_composition_list
void removeEl(MusicalComposition* head, char* name_for_remove);//Прототип функции, которая удаляет элемент element списка, у которого значение name равно значению  name_for_remove
int count(MusicalComposition* head);//Прототип функции, которая возвращает количество элементов списка
void print_names(MusicalComposition* head);//Прототип функции, которая выводит названия композиций


int main(){
    int length;
    scanf("%d\n", &length);  
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    for (int i=0;i<length;i++)
    {
        char name[80];
        char author[80];
        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);
        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(names[i], name);
        strcpy(authors[i], author);
    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;
    char name_for_remove[80];
    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;
    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
    fgets(name_for_remove, 80, stdin);
    (*strstr(name_for_remove,"\n"))=0;
    printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);
    printf("%d\n", k);
    push(head, element_for_push);
    k = count(head);
    printf("%d\n", k);
    removeEl(head, name_for_remove); 
    print_names(head);
    k = count(head);
    printf("%d\n", k);
    return 0;
}

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
	MusicalComposition* head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);           //Указатель на первый элемент
	MusicalComposition* p = head;
	MusicalComposition* curr;
	for (int i=1;i<n;i++)
	{
        //В текущий элемент записывается новый
		curr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]); 
		curr->prev = p;
		p->next = curr;
		p = curr;
	}
	return head; //Указатель на первый элемент списка    
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	while (head->next)
    {
		head = head->next;
    }
	head->next = element;
	element->prev = head;
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
			head->prev->next = head->next; 
			head->next->prev = head->prev;
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

void print_names(MusicalComposition *head)
{
	while (head) //Пока не встретим последний узел списка
	{
		printf("%s\n", head->name); //Вывод названий композиций
		head = head->next; //Ход по узлам списка
	}
}
