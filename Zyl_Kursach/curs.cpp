#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FUnctions.h"
int main(){
int sw=1;
int key = 0;
int length;
int year;
char name[80];
char author[80];
printf("Let's start creating list.\n Enter the length of the list:\n");
scanf("%d", &length);
char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length);
for (int i=0;i<length;i++)
{ printf("Enter the name of song, the author and the year of creation\n");
scanf("%s%s%d", name, author, &year);
names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
strcpy(names[i], name);
strcpy(authors[i], author);
}
MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
for(int i=0; i<length; i++){
free(names[i]);
free(authors[i]);
}
free(years);
while(sw){
printf("1.Add an element to list\n2.Remove an element\n3.Count elements\n4.Print names of the list\n5.Make a copy of the second part\n6.Change the first and the last elements\n7.Quit\n");
scanf("%d", &key);
if(head == 0){
while((key != 1) || (key != 0)){
//	printf("If you want to create a list PRESS 1, otherwise PRESS 0\n");
//	scanf("%d", &key);
}
if(key == 0){
break;
sw = 0;
}
else{
printf("Enter the length of the list:\n");
scanf("%d", &length);
printf("Enter the name of song, the author and the year of creation\n");
scanf("%s%s%d", name, author, &year);
head = createMusicalComposition(name, author, year);
for (int i=0;i<length-1;i++) {
printf("Enter the name of song, the author and the year of creation\n");
scanf("%s%s%d", name, author, &year);
push(head, createMusicalComposition(name, author, year));
}
}
}
else
switch(key){
case 1:
{
printf("Enter the song, the author and the year of creation\n");
scanf("%s%s%d", name, author, &year);
push(head, createMusicalComposition(name, author, year));
break;
}
case 2:
{
printf("Enter the name of the song to remove\n");
scanf("%s", name);
removeEl(head, name);
break;
}
case 3:
{
int c = count(head);
if(c>1)
printf("There are %d elements in the list\n", c);
else
printf("There is %d element in the list\n", c);
break;
}
case 4:
{
print_names(head);
break;
}
case 5:
{
function(head);
print_names(head);
break;
}
case 6:
{
swap(head);
print_names(head);
break;
}
case 7:
{
sw = 0;
break;
}
default: ;
}
printf("If you want to create a list PRESS 1, otherwise PRESS 0\n");
scanf("%d", &key);
if(key == 0) break;
}
return 0;
}
