#include "struct.h"
#include "bigheader.h"
// функции для работы со списком MusicalComposition

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
	int i;
	    for ( i = 1; i < n; ++i)
	    {
		    current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
	    	current->previous = previous;
	    	previous->next = current;
	    	previous = current;
	    }
    return head;
}

MusicalComposition* added_str() {
        system("cls");
        int len = 0;
        while (len<=0)
        {
                printf("Number of elements you want to add\n");
                scanf("%d", &len);
                if (len <= 0) {
                        printf("You should enter a positive number!");
                        continue;
                }
                else
                            break;
        }

        char **names = (char**)malloc(sizeof(char*)*len);
        char **authors = (char**)malloc(sizeof(char*)*len);
        int *years = (int*)malloc(sizeof(int)*len);

        int i=0;
        for (i = 0; i < len; ++i)
        {//заполняем ячейки списка
                printf("Enter the element:name [space] author [space] year:\n");
                char name[80];
                char author[80];

                scanf("%s %s %d", name, author, &years[i]);
                printf("You entered element %d\n", i+1);

                names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
                authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));

                strcpy(names[i], name);
                strcpy(authors[i], author);
        }
        return createMusicalCompositionList(names, authors, years, len);
}
void print_names(MusicalComposition *head){
            	MusicalComposition *current = head;
	            while (current->next){
		        printf("%s\n", current->name);
		        current = current->next;
	                }
	            printf("%s\n", current->name);

            }

void rem_author(struct MusicalComposition*head, char*name_for_remove)
{
	while (head) {
		if(strcmp(head->author, name_for_remove)==0) {
			if (head->previous==NULL) {
				head->next->previous=NULL;
				*head=*head->next;
				return;
			}
			else if (head->next==NULL) {
				head->previous->next=NULL;
			return;
			}
			else {
			head->previous->next=head->next;
			head->next->previous=head->previous;
			}
			}
		head=head->next;


	}
}

void threeEl(struct MusicalComposition*head)
{
	int c = 0;
	int i;
	while (head)
	{
		c++;
		struct MusicalComposition * head_next = head->next;
		if (c % 2 == 1)
		{
			head = head->next;
		}
		else
		{
			/* Делаем текущий элемент последним */
			head->next = NULL;

			/* Три раза добавляем в "конец" элементы */
			for (i = 0; i < 3; i++)
				push(head);
			/* Идем до последнего вставленного элемента */
			while (head->next)
				head = head->next;
			/* Восстанавливаем связь и двигаем указатель
			с помощью заданного ранее указателя на следующий до вставки элемент*/
			head->next = head_next;
			head = head_next;
		}
	}
}

void removeEl(struct MusicalComposition*head, char*name_for_remove)
{
	MusicalComposition *current = head;
	while (current->next)
	{
		if (strcmp(current->name, name_for_remove) == 0) {
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
		}
		current = current->next;
	}
	if ((strcmp(current->name, name_for_remove) == 0) && (current->next == 0))
	{
		current->previous->next = NULL;
		free(current);
	}
}
void push(struct MusicalComposition* head)
{
                char name_for_push[80];
                char author_for_push[80];
                int year_for_push;
                printf("Enter the name of the song, author and year using spaces\n");
                scanf("%s %s %d", name_for_push, author_for_push, &year_for_push);

    MusicalComposition* element= createMusicalComposition(name_for_push, author_for_push, year_for_push);
	while (head->next)
		head = head->next;
	head->next = element;
	element->previous = head;
	element->next = NULL;
	printf("Done!");
}
int count(MusicalComposition *head) { //возвращает число элементов списка
            int c=0;
            while (head) {
                c++;
                head=head->next;
            }
            return c;
        }
void pause()
{
	printf("Press any key to continue...\n");
	getchar();
	getchar();
}
