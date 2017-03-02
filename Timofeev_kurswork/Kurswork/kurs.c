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
        MusicalComposition* new_song = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        strcpy(new_song->name, name);
        strcpy(new_song->author, author);
        new_song->year = year;
        new_song->next = NULL;
        new_song->prev = NULL;
        return new_song;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
        MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
        MusicalComposition *prev = head;
        MusicalComposition *current;
        for (int i = 1; i < n; ++i)
        {
                current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                current->prev = prev;
                prev->next = current;
                prev = current;
        }
        return head;
}

void push(MusicalComposition* head)
{
        char name_for_push[80];
        char author_for_push[80];
        int year_for_push;

        printf("Enter name, author and year (using spaces):\n");
        scanf("%s %s %d", name_for_push, author_for_push, &year_for_push);


        MusicalComposition *element = createMusicalComposition(name_for_push, author_for_push, year_for_push);
        MusicalComposition *current = head;
	

        while (current->next)
                current = current->next;
	

        current->next = element;
        element->prev = current;
        element->next = NULL;
}

void removeEl(MusicalComposition* head, char* name_for_remove, int* CreatedList)
{
	
        while (head)
        {
		
                if (strcmp(head->name, name_for_remove) == 0)
                { 
			
                        if ((head->next == NULL) && (head->prev == NULL))
                        {
				/* Удаляем список*/
                                free(head);
                                head=NULL;
				
                                printf("\nYou removed the last element in the List\nTo continue use this programm create new List!\n");
                                *CreatedList = 0;
                                return;
                        }
			
			
                        else if ((head->prev == NULL) && (head->next))
                        {
				
                                *head = *head->next;
                                head->prev = NULL;
                                return;
                        }
			

                        else if ((head->next == NULL) && (head->prev))
                        {
				/*Смещаем назад указатель на предыдущий элемент*/
                                head = head->prev;
                                head->next = NULL;
                                return;
                        }
			
                        else if ((head->next) && (head->prev))
                        {
                                head->next->prev = head->prev;
                                head->prev->next = head->next;
                                return;
                        }
                }
                head = head->next;
        }
}
int count(MusicalComposition*head)
{
        int count = 0;
        while (head)
        {
                count++;
                head = head->next;
        }
        return count;
};

void print_names(MusicalComposition *head)
{
        while (head)
        {
                printf("%s\n", head->name);
                head = head->next;
        }
}
