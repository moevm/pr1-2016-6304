#include <stdlib.h>
#include <stdio.h>
#include <string.h>


 struct MusicalComposition{   //описание структуры
    char name[80]; //название композиции
    char author[80];  //имя автора
    int year;  //год 
    struct MusicalComposition *next; //указатель на следующий элемент списка
    struct MusicalComposition *prev;  // указатель на предыдущий элемент
};

typedef struct MusicalComposition MusicalComposition;  //изменение названия типа
//прототипы функций
MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n); 

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head); 

void print_names(MusicalComposition* head);


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


MusicalComposition* createMusicalComposition(char* name, char* author, int year){   //Создание структуры 
    MusicalComposition* soundtrack  = (MusicalComposition*)malloc(sizeof(MusicalComposition));  //Выделение памяти
  //инициализация полей
    strcpy(soundtrack->name, name);
    strcpy(soundtrack->author, author);
    soundtrack->year = year;
    soundtrack->next = NULL;
    soundtrack->prev = NULL;
    return soundtrack; 
}


                                                           
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)  //Функция для создания списка композиций 
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]); //первый элемент списка
	MusicalComposition *prev = head; // элемент для движения по списку
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
                                                           
void push(MusicalComposition* head, MusicalComposition* element){  //добавление элемента
    while(head->next)
        head = head->next;
        head->next = element;
        element->prev = head;
        element->next = NULL;
    
}

void removeEl(MusicalComposition* head, char* name_for_remove){ //удаление элемента
    while(head){
        if(strcmp(head->name, name_for_remove) == 0){ //сравнение поля имени с заданным именем
            if(head->prev == 0){   //если элемент в начале
                head->next->prev = NULL;
               
                return;
            }
            else if (head->next == NULL){  //если элемент в конце
                head->prev->next = NULL;
                return;
            }
               
                head->prev->next = head->next;
                head->next->prev = head->prev;
                break;
                
        }
        head = head->next;
    }
}
                 
        
int count(MusicalComposition*head) // функиця подсчета элементов
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
};
        
        
void print_names(MusicalComposition* head){  //вывод имен
    while(head){
        printf("%s\n", head->name);
        head = head->next;
    }
}
