#include "main.h"

// Create musical composition
musical_composition* create_musical_composition(char* name, char* author, int year);

// Create list of musical compositions
musical_composition* create_musical_composition_list(char** array_names, char** array_authors, int* array_years, int n);

// Copy list of musical compositions
musical_composition* copy_musical_composition_list(musical_composition* head1);

// Add new musical composition to the end of the list
void push(musical_composition* head, musical_composition* new_item);

// Remove musical composition by the name
musical_composition* remove_item(musical_composition* head, char* name_for_remove);

// Count musical compositions in the list
int count(musical_composition* head);

// Print names of musical compositions in the list
void print_names(musical_composition* head);

// Swap tail and head in the list
musical_composition* swap_head_tail(musical_composition* head);

// Cut list into halves
musical_composition* cut_list_into_halves(musical_composition* head);

// Concatenate two lists
musical_composition* concatenate_two_lists(musical_composition* head1, musical_composition* head2);



