#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct MusicalComposition {
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition * next;
    struct MusicalComposition * previous;
};

typedef struct MusicalComposition MusicalComposition;



MusicalComposition *createMusicalComposition(char *name, char *author, int year)
{
    MusicalComposition *mc = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    strcpy(mc->name, name);
	strcpy(mc->author, author);

    mc->year = year;
    mc->previous = NULL;
    mc->next = NULL;

    return mc;
};



struct MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *previous = head;
	MusicalComposition *current;
	    for (int i = 1; i < n; ++i)
	    {
		    current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
	    	current->previous = previous;
	    	previous->next = current;
	    	previous = current;
	    }
    return head;
}

void push(struct MusicalComposition* head, struct MusicalComposition* element)
{
	while (head->next)
		head = head->next;
	head->next = element;
	element->previous = head;
	element->next = NULL;
}


void removeEl(struct MusicalComposition*head, char*name_for_remove)
{
	MusicalComposition *current = head;
	while (current->next)
	{
		if (strcmp(current->name, name_for_remove) == 0)
			if ((current->previous) == 0)
			{
				MusicalComposition *newcurrent = current->next;
				    strcpy(current->name, newcurrent->name);
				    strcpy(current->author, newcurrent->author);
				    current->year = newcurrent->year;
				    newcurrent->next->previous = current;
				    current->next = newcurrent->next;
				free(newcurrent);
			}
			else
			{
				current->previous->next = current->next;
				current->next->previous = current->previous;
				free(current);
			}
		current = current->next;
	}
	if ((strcmp(current->name, name_for_remove) == 0) && (current->next == 0))
	{
		current->previous->next = NULL;
		free(current);
	}
}


        int count(MusicalComposition *head) {
            int c=0;
            while (head) {
                c++;
                head=head->next;
            }
            return c;
        }
            void print_names(MusicalComposition *head){
            	MusicalComposition *current = head;
	            while (current->next){
		        printf("%s\n", current->name);
		        current = current->next;
	                }
	            printf("%s\n", current->name);

            }


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
