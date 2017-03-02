#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "td.h"


MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition* ptr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    ptr->prev = NULL;
    ptr->next = NULL;
    strcpy(ptr->name, name);
    strcpy(ptr->author, author);
    ptr->year = year;

    return ptr;
}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    int i;
    MusicalComposition* temp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* head = temp;
    for (i=1; i<n; i++)
    {
        temp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        temp->next->prev = temp;
        temp = temp->next;
    }

    return head;
}
