#include "struct.h"
int count(MusicalComposition *head);
MusicalComposition* createMusicalComposition(char *name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
MusicalComposition* added_str();
void print_names(MusicalComposition *head);
void push(struct MusicalComposition* head);
void rem_author(struct MusicalComposition*head, char*name_for_remove);
void removeEl(struct MusicalComposition*head, char* name_for_remove);
void threeEl(struct MusicalComposition*head);
void pause();
