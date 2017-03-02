#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Описание структуры MusicalComposition
struct MusicalComposition {
char name[80];
char author[80];
int year;
struct MusicalComposition *next;
struct MusicalComposition *prior;
};
typedef struct MusicalComposition MusicalComposition;


// Создание структуры MusicalComposition

    MusicalComposition* createMusicalComposition(char* name, char* author, int year){

 MusicalComposition* head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
 strcpy(head->name, name);
 strcpy(head->author, author);
 head->year = year;
 head->prior=NULL;
 head->next=NULL;
 return head;
}


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
    int i;
    for (i=0;i<length;i++)
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

MusicalComposition* createMusicalCompositionList(char** array_names,char** array_authors, int* array_years, int n){
    MusicalComposition* tmp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* head = tmp;
    int i;
    for (i=1; i<n; i++)
    {
        tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        tmp->next->prior = tmp;
        tmp = tmp->next;
    }

    return head;
}

void push(MusicalComposition* head, MusicalComposition* element){
    while(head->next){
    head=head->next;
    }
    head->next=element;
    element->prior=head;
}

void removeEl(MusicalComposition* head, char* name_for_remove){
MusicalComposition *tmp = head;
        while (tmp->next)
        {
                if (strcmp(tmp->name, name_for_remove) == 0) {
                        if ((tmp->prior) == NULL)
                        {
                                MusicalComposition *ntmp = tmp->next;
                                strcpy(tmp->name, ntmp->name);
                                strcpy(tmp->author, ntmp->author);
                                tmp->year = ntmp->year;
                                ntmp->next->prior = tmp;
                                tmp->next = ntmp->next;
                                free(ntmp);
                        }
 else
                        {
                                tmp->prior->next = tmp->next;
                                tmp->next->prior = tmp->prior;
                                free(tmp);
                        }
                }
                tmp = tmp->next;
        }
        if ((strcmp(tmp->name, name_for_remove) == 0) && (tmp->next == NULL))
        {
                tmp->prior->next = NULL;
                free(tmp);
        }

}

int count(MusicalComposition* head){
        int count=0;
        while (head) {
                count++;
                head=head->next;
            }
        return count;
        }

void print_names(MusicalComposition* head){
        MusicalComposition *tmp = head;
        while (tmp->next){
                printf("%s\n", tmp->name);
                tmp = tmp->next;
                        }
        printf("%s\n", tmp->name);
}

