#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "func.h"
int main(){
    int length, i;
    scanf("%d\n", &length);  
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    for (i=0;i<length;i++)
    {
        char name[80];
        char author[80];
        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);
        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;
        names[i] = (char*)malloc(sizeof(char) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char) * (strlen(author)+1));
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



