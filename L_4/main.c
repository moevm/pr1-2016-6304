#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

//Структура MusicalComposition
typedef struct MusicalComposition
{
	char* name;
	char* author;
	int year;
	struct MusicalComposition *next;
}MusicalComposition;
//Инициализация структуры
MusicalComposition* createMusicalComposition (char* name, char* author, int year)
{
	MusicalComposition* composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	composition->name = name;
	composition->author = author;
	composition->year = year;
	composition->next = NULL;
	return composition;
}
//Создание списка
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition* tmp = head;
	for (int i = 1; i < n; i++)
	{
		tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		tmp = tmp->next;
	}
	return head;
}
//Добавление нового элемента в список
void push (MusicalComposition* head, MusicalComposition* element)
{
	MusicalComposition* tmp = head;
	while (tmp->next != NULL)
	tmp = tmp->next;
	tmp->next = element;
}
//Удаление элемента имеющего указанное имя из списка
void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition *bef = head, *tmp = head->next;
	while (tmp != NULL)
	{
		if (strcmp(tmp->name, name_for_remove) == 0)
		{	
			bef->next = tmp->next;
			tmp->next;
			
		}
			bef = bef->next;
			tmp = tmp->next;
	}
}
//Счетчик элементов списка
int count (MusicalComposition* head)
{
	MusicalComposition* tmp = head;
	int count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
//Вывод имен элементов списка
void print_names(MusicalComposition *head)
{
	MusicalComposition *tmp = head; 
	while (tmp != NULL)
	{	
		printf ("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

int main()
{
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
