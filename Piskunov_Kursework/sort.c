#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "td.h"

void ssswap (MusicalComposition* a, MusicalComposition* b){
    char c[80];
    int d;
    strcpy(c, a->name);
    strcpy(a->name, b->name);
    strcpy (b->name, c);
    strcpy(c, a->author);
    strcpy(a->author, b->author);
    strcpy (b->author, c);
    d = a->year;
    a->year = b->year;
    b->year = d;
}


MusicalComposition* getel (int n, MusicalComposition* head){
    int i;
    for(i = 0; i<n; i++)
        head = head->next;

    return head;
}



void sort (MusicalComposition* head, int n){
int i, j;
    for(i = 0; i<n; i++)
        for(j = i; j<n; j++)
            if (strcmp((getel(i, head))->name, (getel(j, head))->name)>0)
                ssswap(getel(i, head), getel(j, head));

}
