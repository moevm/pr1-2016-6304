#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mc_functions.h"

// Create musical_composition
musical_composition* create_musical_composition(char* name, char* author, int year)
{
	musical_composition* head = (musical_composition*)malloc(sizeof(musical_composition));
	strcpy(head->name, name);
	strcpy(head->author, author);
	head->year = year;
	head->next = NULL;
	head->prev = NULL;
	return 	head;
}

musical_composition* create_musical_composition_list(char** array_names, char** array_authors, int* array_years, int n)
{
// create head item first
	musical_composition* head = create_musical_composition(array_names[0], array_authors[0], array_years[0]);
	musical_composition* prev_item = head;

	int i;
	for (i=1; i<n; i++)
	{
// create next item
		musical_composition* item = create_musical_composition(array_names[i], array_authors[i], array_years[i]);
// make it linked to the previous item
		item->prev = prev_item;
		prev_item->next = item;
		item->next = NULL;
		prev_item = item;
	}	
	return head;
}

musical_composition* copy_musical_composition_list(musical_composition* head1)
{
	musical_composition* item1 = head1;
	musical_composition* item2 = NULL;
	musical_composition* head2 = NULL;
	musical_composition* prev2 = NULL;

	while (item1 != NULL)
	{
// copy item
		item2 = create_musical_composition(item1->name, item1->author, item1->year);
		if (head2 == NULL)
		{
			head2 = item2;
		}
// make it part of the new list
		item2->prev = prev2;
		if (prev2 != NULL)
		{
			prev2->next = item2;
		}
// next item		
		item1 = item1->next;
		prev2 = item2;
// mark last item as tail if the list is not empty
		if (item2 != NULL)
		{
			item2->next = NULL;
		}
	}
	return head2;
}

void push(musical_composition* head, musical_composition* new_item)
{
	if (head == NULL)
	{
		head = new_item;
		return;
	}
	musical_composition* item = head;
	while (item->next != NULL)
	{
		item = item->next;	
	}
	item->next = new_item;
	new_item->prev = item;
}


musical_composition* remove_item(musical_composition* head, char* name_for_remove)
{ 
    if (head == NULL)
    {
        return;
    }

    musical_composition* item = head;
    musical_composition* new_head = head;
    do
    {
        if (strcmp(item->name, name_for_remove) == 0)
        {    
            musical_composition* prev = item->prev;
            musical_composition* next = item->next;
            if (prev != NULL)
            {
                prev->next = item->next;
            }
            else // we are deleting the current head
            {
                new_head = item->next;
            }
            if (next != NULL)
            {
                next->prev = item->prev;
            }
            musical_composition* item_to_delete = item;
            item = item->next;
            free(item_to_delete);
        }
        else 
        {
            item = item->next;
        }        
    } while (item != NULL);
    return new_head;
}
	
int count(musical_composition* head)
{
	int count = 0;
	musical_composition* item = head;
	while (item != NULL)
	{
		count++;
		item = item->next;
	}
	return count;
}

void print_names(musical_composition* head)
{
	musical_composition* item = head;
	while (item != NULL)
	{
		printf("%s\n", item->name);
		item = item->next;
	}
}

musical_composition* swap_head_tail(musical_composition* head)
{	
// list empty or contains just 1 element
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

// list contains 2 elements
	if (head->next->next == NULL)
	{
		musical_composition* tail = head->next;
// make tail as head
		tail->prev = NULL;
		tail->next = head;

// make head as tail
		head->next = NULL;
		head->prev = tail;

// return new head
		return tail;
	}

// find tail
	musical_composition* item = head;
	while (item->next != NULL)
	{
		item = item->next;
	}
	musical_composition* tail = item;
	musical_composition* tail_prev = tail->prev;
	musical_composition* head_next = head->next;
	

// make head as tail
	head->next = NULL;
	head->prev = tail_prev;
	tail_prev->next = head;

// make tail as head
	tail->prev = NULL;
	tail->next = head_next;
	head_next->prev = tail;

// return new head
	return tail;
}

musical_composition* cut_list_into_halves(musical_composition* head)
{
// calculate middle index
	int n = count(head);
	if (n < 2)
	{
		return NULL; //cannot cut list of less than 2 compositions
	}
	int m; //middle index
	if (n % 2 == 0)
	{
		m = n/2;
	}
	else
	{
		m = (n+1)/2;
	}
// find middle item
	musical_composition* item = head;
	int i;
	for (i = 0; i < m; i++)
	{
		item = item->next;
	}
// cut_list_into_halves
	musical_composition* tail1 = item->prev;
	tail1->next = NULL;
	musical_composition* head2 = item;
	head2->prev = NULL;

	return head2;
}

musical_composition* concatenate_two_lists(musical_composition* head1, musical_composition* head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
//find tail of list 1
	musical_composition* item1 = head1;
	while (item1->next != NULL)
	{
		item1 = item1->next;
	}
	musical_composition* tail1 = item1;

// concatenate lists
	tail1->next = head2;
	head2->prev = tail1;

	return head1;
}
