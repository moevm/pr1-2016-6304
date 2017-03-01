#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct MusicalComposition{
    char name[80];    
    char author[80];
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
}MusicalComposition;
    
    

// Описание структуры MusicalComposition


// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year){
        MusicalComposition* song =(MusicalComposition*)malloc(sizeof(MusicalComposition));
        strcpy(song->name, name);
        strcpy(song->author, author);
        song->year=year;
        MusicalComposition* next=NULL;
        MusicalComposition* prev=NULL;
    return song;
}
        
    

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition* t1=createMusicalComposition(array_names[0], array_authors[0],  array_years[0]);
    MusicalComposition* head=t1;
    for(int i=1;i<n;i++){
        t1->next=createMusicalComposition(array_names[i], array_authors[i],  array_years[i]);
        t1->next->prev=t1;
        t1=t1->next;
    }
    return head;
}


void push(MusicalComposition* head, MusicalComposition* element)
{
    while(head->next){
        head=head->next;
    }
    head->next=element;
    element->prev=head;
}

void removeEl(MusicalComposition* head, char* name_for_remove) 
{
    while((strcmp(name_for_remove,head->name)) && (head!=NULL))
       {
        head=head->next;
       }
          if(head->next==NULL){
              head->prev->next=NULL;
          }
          if((head->next!=NULL) && (head->prev!=NULL)){
              head->prev->next=head->next;
              head->next->prev=head->prev;
          }
          if(head->prev==NULL){
              while(head->next){
                  strcpy(head->name, head->next->name);
                  strcpy(head->author, head->next->author);
                  head->year=head->next->year;
              }
              head->prev->next=NULL;
              head->prev=NULL;
          }
          }
         
             
              
          
              
        

int count(MusicalComposition* head)
    {
    int i=0;

    while(head){
        head=head->next;
    i++;
    }
    return i;
}

void print_names(MusicalComposition* head)
{
    while(head){
        printf("%s\n", head->name);
        head=head->next;   
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
