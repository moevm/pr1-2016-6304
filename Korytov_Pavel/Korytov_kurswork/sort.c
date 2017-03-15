#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void swap(MusicalComposition *a, MusicalComposition *b){
    char rswap[80]; int i;
    strcpy(rswap, a->name); strcpy(a->name, b->name); strcpy(b->name, rswap);
    strcpy(rswap, a->author); strcpy(a->author, b->author); strcpy(b->author, rswap);
    i = a->year; a->year = b->year; b->year = i;
    //Простой swap - проще поменять местами 3 элемента чем изменить 8 указателей
}


MusicalComposition* access(MusicalComposition* head, int n){
    int i=0; //Функция возвращает элемент списка под указанным номером,
			 //чтобы обеспечить доступ к списку подобно массиву.
    while ((head!=NULL) && (i!=n)){
        head=head->next;
        i++;
    }
    return head;
}

//Сортировка пузырьком по году
void yearsort(MusicalComposition* head){
    int i; int k; int N = count(head);
    for (i=0; i<N; i++)
        for (k=i; k<N; k++){
            if (access(head, k)->year > access(head, i)->year)
                swap(access(head, i), access(head, k)); 
        }
}
//Тот же пузырек, но через strcmp
void namesort(MusicalComposition* head){
    int i; int k; int N = count(head);
    int t;
    for (i=0; i<N; i++)
        for (k=i; k<N; k++){
            t = strcmp(access(head, k)->name,access(head, i)->name);
            if (t > 0)
                swap(access(head, i), access(head, k)); 
        }
}

