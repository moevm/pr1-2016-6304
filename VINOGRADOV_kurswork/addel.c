#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "type.h"

void pushExt(MusicalComposition* head)
{
    int k=0;
    int i=0;
    while(head->next){
	head=head->next;
	k++;
	if(k%2!=0){
	if(head->next!=NULL){
        MusicalComposition *nexttmp=head->next;
	head->next=NULL;
		for(i=0;i<3;i++){
		push(head, createMusicalComposition("ne ochen`", "ez", 322));
		}
		while(head->next){
		head=head->next;
		}
		head->next=nexttmp;
		
	}
	else{
	for(i=0;i<3;i++){
		push(head, createMusicalComposition("2", "ez", 322));
		}
		while(head->next){
		head=head->next;
		}
	}
}	
} 
}
