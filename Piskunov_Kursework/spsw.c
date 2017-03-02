#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "td.h"


MusicalComposition* split_and_swap (MusicalComposition* head, int n) {
int i = 0; int j = 0;
MusicalComposition** arr = (MusicalComposition**)malloc((n+1)*sizeof(MusicalComposition*));
for (i = 0; i<n; i++)
    arr[i] = (MusicalComposition*)malloc(sizeof(MusicalComposition*));

	for (i = 0; i<n; i++){
	arr[i] = head;
	head = head->next;
}

	for (i = 0; i<n-1; i = i + 2){
	arr[i+1]->next = NULL;
	arr[i]->prev = NULL;
	ssswap(arr[i], arr[i+1]);	
	}

	for (i = 1; i<n-1; i = i + 2){
	arr[i]->next = arr[i+1];
	arr[i+1]->prev = arr[i];
}

	

 head = arr[0];
 return head;
}
