#include "structure.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
// Создание MusicalComposition
MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition* temp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    temp->previous=NULL;
    temp->next=NULL;
    strcpy(temp->name, name); //Невозможно сделать с temp->name = name
    strcpy(temp->author, author); //В этом случае копировались бы указатели, а не символы
    temp->year=year;
    return temp;
}

// Создание списка структур MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition* temp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* head = temp; //Голова списка, функция её возвращает
    int i;
    for (i=1; i<n; i++){
        temp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        temp->next->previous = temp; //Указатель следующей структуры на предыдущую должен указывать на текущую
        temp = temp->next; 
    }
    return head;
};




