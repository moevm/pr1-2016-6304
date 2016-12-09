#include "MusicalComposition_API.h"

int main() {
	/* Функция main взята с stepic.org из раздела с 4 лабораторной работой. Никак не изменялась.*/
	int length = 0;
	scanf("%d", &length);
	
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	
	int* years = (int*)malloc(sizeof(int)*length);

	for (int i = 0; i<length; i++)
	{
		char name[80];
		char author[80];

		
		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		fscanf(stdin, "%d\n", &years[i]);

		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;

		names[i] = (char*)malloc(sizeof(char*) * (strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*) * (strlen(author) + 1));

		strcpy(names[i], name);
		strcpy(authors[i], author);

	}

	struct MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
	
	char name_for_push[80];
	char author_for_push[80];
	
	int year_for_push;

	char name_for_remove[80];
	scanf("%s %s %d", name_for_push, author_for_push, &year_for_push);

	struct MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
	scanf("%s", name_for_remove);

	printf("%s %s %d\n", head->name, head->author, head->year);
	int k = count(head);
	printf("%d\n", k);
	
	push(head, element_for_push);
	k = count(head);
	printf("%d\n", k);

	removeEl(head, name_for_remove);
	print_names(head);
	k = count(head);
	printf("%d\n", k);

	system("pause");
	return 0;
}