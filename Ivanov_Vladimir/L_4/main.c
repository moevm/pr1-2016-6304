#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct MusicalComposition {
	char name[80]; //Название композиции
	char author[80]; // Её автор
	int year;//Её год написания
	struct MusicalComposition* next;//Указатель на следующий элемент
	struct MusicalComposition* prev;//Указатель на предыдущий элемент
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char *name, char* author, int year)
{
	MusicalComposition* new = (MusicalComposition*)malloc(sizeof(MusicalComposition)); //Выделение памяти для новой записи
	strcpy(new->name, name); //Инициализируем полученные в функцию данные 
	strcpy(new->author, author);
	new->year = year;
	new->next = NULL;
	new->prev = NULL;
	return new;//Возвращаем указатель на новый элемент структуры
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);//Создаём указатель на 1ый элемент списка, а также создаём 1ый элемент списка
	MusicalComposition *prev = head;//Создаём указатель на предыдущий элемент и в качестве пред. эл. задаём 1ый
	MusicalComposition *curr;//Создаём указатель на текущий элемент
	for (int i = 1; i < n; ++i)
	{
		curr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);//В текущий элемент записываем новый
		curr->prev = prev;//Указатель на пред. элемент равен пред. элементу
		prev->next = curr;//Указатель на след. элемент равен текущему
		prev = curr;// В предыдущий записываем текущий
	}
	return head; //Возвращаем указатель на первый жлемент списка
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	while (head->next) //Двигаемся, пока существует след. эл., т.е. до последнего эл.
		head = head->next;
	head->next = element;//Указатель на след.эл. равен полученному
	element->prev = head;//Указатель на пред.эл. равен текущему
	element->next = NULL; //Текущий-последний
}


void removeEl(MusicalComposition*head, char*name_for_remove)
{

	while (head)//Двигаемся пока список не закончится
	{
		if (strcmp(head->name, name_for_remove) == 0)//Проверяем на совпадение, и если совпало
		{
			if (head->next == NULL)//Если последний элемент совпал
			{
				head->prev->next = NULL;//Разрываем с ним связь
				return;
			}
			else if (head->prev == NULL)//Если первый
			{
				head->next->prev = NULL;//Разрываем с ним связь
				return;
			}

			head->prev->next = head->next; //Элемент после пред. будет след.
			head->next->prev = head->prev;//Элемент перед след. будет пред.

			break;
		}

		head = head->next;//передвижение
	}

}
int count(MusicalComposition*head)
{
	int i = 0;
	while (head)//до последнего элемента
	{
		i++;
		head = head->next;//передвижение
	}
	return i;
};

void print_names(MusicalComposition *head)
{
	while (head)//до последнего
	{
		printf("%s\n", head->name);
		head = head->next;//передвижение
	}
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
