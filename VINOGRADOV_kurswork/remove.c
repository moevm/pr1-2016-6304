#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "type.h"

int removeExt(MusicalComposition* head)
{
    char* str=(char*)malloc(80*sizeof(char));
    scanf("%s", str);
	int k=0;
	MusicalComposition* bgn=head;
	while(head){
	if((strstr(head->author, str))==NULL)
	k=1;
	head=head->next;
	}
        if(k==1){
	head=bgn;
        while(head!=NULL){
        if((strstr(head->author, str))!=NULL){
        removeEl(head, head->name);
	removeEl(head, head->name);
        }
	head=head->next;
        }
	}
	else{
	printf("Со смертью этого листа нить вашей судьбы обрывается.\nЗагрузите новый лист, чтобы восстановить течение судьбы,\n или живите дальше в проклятом мире, который сами и создали.\n");
	return 0;	
}
}
