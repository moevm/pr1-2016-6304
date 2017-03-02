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
MusicalComposition* createMusicalComposition(char* name, char* author, int year){
MusicalComposition* nw = (MusicalComposition*)malloc(sizeof(MusicalComposition));
strcpy(nw->name, name);
strcpy(nw->author, author);
nw->year = year;
nw->next = NULL;
nw->prev = NULL;
return nw;
}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
MusicalComposition* head = createMusicalComposition( array_names[0], array_authors[0], array_years[0]);
MusicalComposition* ptr = head;
MusicalComposition* point = NULL;
for(int i = 1; i<n; i++){
point = createMusicalComposition( array_names[i], array_authors[i], array_years[i]);
point->prev = ptr;
ptr->next = point;
ptr = point;
}
return head;
}
void push(MusicalComposition* head, MusicalComposition* element){
while(head->next)
head = head->next;
head->next = element;
element->prev = head;
element->next = NULL;
}
void removeEl(MusicalComposition* head, char* name_for_remove){
MusicalComposition *ptr = head;
while(head){
if(strcmp(head->name, name_for_remove) == 0){
if((head->next == NULL) && (head->prev == NULL)){
free(head);
head = NULL;
return;
}
if(head->prev == 0){
head->next->prev = NULL;
//head = head->next;
return;
}
else if (head->next == NULL){
head->prev->next = NULL;
return;
}
head->prev->next = head->next;
head->next->prev = head->prev;
break;
}
head = head->next;
}
head = ptr;
}
int count(MusicalComposition* head){
int c = 0;
while(head){
c++;
head = head->next;
}
return c;
}
void print_names(MusicalComposition* head){
int i = 1;
while(head){
printf(" %d. %s %s %d\n", i++, head->name, head->author, head->year);
head = head->next;
}
}
void function(MusicalComposition* head){
int len = count(head);
MusicalComposition *current = head;
int i;
if(len%2==0){
i = len/2;
}
else{
i = len/2 +1;
}
for(int j = 0; j<(i-1); j++){
current = current->next;
}
for(int j=0; j<i; j++){
MusicalComposition* trash = (MusicalComposition*)malloc(sizeof(MusicalComposition));
strcpy(trash->name, current->name);
strcpy(trash->author, current->author);
trash->year = current->year;
push(head, trash);
current = current->next;
}
}
void swap(MusicalComposition* head){
char n[80], a[80];
strcpy(n, head->name);
strcpy(a, head->author);
int y = head->year;
MusicalComposition *curr = head;
while(curr->next){
curr = curr->next;
}
strcpy(head->name, curr->name);
strcpy(head->author, curr->author);
head->year = curr->year;
strcpy(curr->name, n);
strcpy(curr->author, a);
curr->year = y;
}
