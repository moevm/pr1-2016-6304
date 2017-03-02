nclude <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>


// Описание структуры MusicalComposition
typedef struct MusicalComposition {
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition* prev;
    struct MusicalComposition* next;
} MusicalComposition;

// Создание структуры MusicalComposition
MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
    MusicalComposition* ptr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    ptr->prev = NULL;
    ptr->next = NULL;
    strcpy(ptr->name, name);
    strcpy(ptr->author, author);
    ptr->year = year;
    
 return ptr;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove); 

int count(MusicalComposition* head); 

void print_names(MusicalComposition* head);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition* temp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* head = temp;
        for (int i=1; i<n; i++)
    {
     temp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
     temp->next->prev = temp;
     temp = temp->next;
    }
    
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element){
 while (head->next!=NULL)
     head = head->next;
    
    head->next = element;
    element->prev = head;
}

int count(MusicalComposition* head){
   int number = 0;
    while (head!=NULL){
     head = head->next; 
     number++;
    }
    return number;
}

void print_names(MusicalComposition* head){
    while (head!=NULL){
     printf("%s\n", head->name);
        head = head->next;
    }
}

void removeEl(MusicalComposition* head, char* name_for_remove){
    while (strcmp(head->name, name_for_remove)!=0){
        head = head->next;
    }
    while ((strcmp(name_for_remove, head->name)!=0) && (head!=NULL)){
        head = head->next;
    }
    if  ((head->prev!=NULL)&&(head->next!=NULL)){
        head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    else if (head->next == NULL){
        head->prev->next = NULL;
    }
    else if(head->prev == NULL){
        while(head->next!=NULL){
            strcpy(head->name,head->next->name);
            strcpy(head->author, head->next->author);
            head->year = head->next->year;
        }
        head->prev->next = NULL;
        head->prev = NULL;
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
