#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "kurs.h"
struct MusicalComposition {
        char name[80];
        char author[80];
        int year;
        struct MusicalComposition* next;
        struct MusicalComposition* prev;
};


typedef struct MusicalComposition MusicalComposition;

MusicalComposition* Propis(MusicalComposition *head) {
        int i=0;
        MusicalComposition *ptr = head;
                while (ptr!= NULL)
                { for (i = 0; i < strlen(ptr->author); i++) {
                                if (islower(ptr->author[i]))
                                        ptr->author[i]=toupper(ptr->author[i]);
                }
                        ptr=ptr->next;

                }
        return head;
}

void dobavlenie(struct MusicalComposition* head) 
{

	int i=0;
	while(head->next)
		head = head->next;
	for ( i = 0; i<3; i++)
		push(head, createMusicalComposition("Default","Default", i));
}
