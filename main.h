

// Define musical_composition structure
typedef struct musical_composition
{
	char name[80];
	char author[80];
	int year;
	struct musical_composition* next;
	struct musical_composition* prev;		
} musical_composition;

// Print the user menu
void print_menu();

