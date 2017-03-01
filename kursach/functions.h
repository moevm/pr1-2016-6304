#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MusicalComposition{
char name[80];
char author[80];
int year;
struct MusicalComposition *next;
struct MusicalComposition *prev;
};
typedef struct MusicalComposition MusicalComposition;
MusicalComposition* createMusicalComposition(char* name, char* author, int year);
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
void push(MusicalComposition* head, MusicalComposition* element);
void removeEl(MusicalComposition* head, char* name_for_remove);
int count(MusicalComposition* head);
void print_names(MusicalComposition* head);
void function(MusicalComposition *head);
void change(MusicalComposition* head);
