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
MusicalComposition* s = (MusicalComposition*)malloc(sizeof(MusicalComposition));
strcpy(s->name, name);
strcpy(s->author, author);
years[i]=year;
s->year = year;
s->next = NULL;
s->prev = NULL;
return s;
}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
MusicalComposition* head = createMusicalComposition( array_names[0], array_authors[0], array_years[0]);
MusicalComposition* ptr = head;
MusicalComposition* point = NULL;
int i;
for(i = 1; i<n; i++){
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
void pushmid(MusicalComposition * head, MusicalComposition* element) {
        MusicalComposition * ptr = head;
        int schet = 0;
        while ( ptr->next != NULL) {
                ++schet;
                ptr = ptr->next;
        }
        int j;
        for ( j=0; j<((schet/2)+1); ++j) {
                ptr = ptr->prev;
        }
        MusicalComposition* second = ptr->next ;
        MusicalComposition* pp= createMusicalComposition(element->name, element->author, element->year);
        ptr->next = pp;
        pp->next=second;

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
int j;
for(j = 0; j<i; j++){
MusicalComposition* part = (MusicalComposition*)malloc(sizeof(MusicalComposition));
strcpy(part->name, current->name);
strcpy(part->author, current->author);
part->year = current->year;
pushmid(head, part);
current = current->next;
}
}
void exchange(MusicalComposition* a, MusicalComposition* b){

	char t[80];

	int r;

	strcpy(t, a->name);

	strcpy(a->name, b->name);

	strcpy (b->name, t);

	strcpy(t, a->author);

	strcpy(a->author, b->author);

	strcpy (b->author, t);

	r=a->year;

	a->year=b->year;

	b->year=r;

}

//разбить список на группы и поменять в нем начальный и конечный элементы местами

MusicalComposition* ChangeList1(MusicalComposition* head, int m){

	int i=0; 

	int j=0;

	int n=count(head);

	MusicalComposition** arr = (MusicalComposition**)malloc((n+1)*sizeof(MusicalComposition*));

        for (i = 0; i<n; i++) arr[i] = (MusicalComposition*)malloc(sizeof(MusicalComposition*));

        for (i = 0; i<n; i++){

        	arr[i] = head;

        	head = head->next;
  }
if (n%m==0){

        	for(i = 0; i<n-1; i = i + m){

        		arr[i+m-1]->next = NULL;

        		arr[i]->prev = NULL;

        		exchange(arr[i], arr[i+m-1]);
	}
for (i = 1; i<n-1; i = i + m){

        		arr[i+m-2]->next = arr[i+m-1];

        		arr[i+1]->prev = arr[i];

        	}

	}

	else {

        	for(i = 0; i<n-2; i = i + m){

        		arr[i+m-1]->next = NULL;

        		arr[i]->prev = NULL;

        		exchange(arr[i], arr[i+m-1]);
}
	for (i = 1; i<n-2; i = i + m){
arr[i+m-2]->next = arr[i+m-1];
arr[i+1]->prev = arr[i];

       }
i=n-2;
arr[i+1]->next=arr[i+2];
arr[i+1]->prev=arr[i];

       }
head = arr[0];
return head;

}
//разбить список на две части относительно индекса n, вторую часть разбить группы по m элементов, поменять в каждой начальный и конечный элемент местами, соединить обратно

MusicalComposition* ChangeList2(MusicalComposition* head, int n, int m){
MusicalComposition *tmp = head;
int j;
for(j=0;j<(n-1);j++) tmp=tmp->next;
MusicalComposition *curr=tmp->next;
tmp->next=NULL;
ChangeList1(curr, m);
	tmp->next=curr;
	return head;
}


