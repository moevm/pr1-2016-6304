#include "MusicalComposition_API.h"

/* Функции вывода информации о списке MysicalCompositionList */ 

/* Подсчет элементов списка */
int count(struct MusicalComposition*head)
{
	int count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return count;
}

/* Печать имен */
void print_names(struct MusicalComposition* head)
{
	while (head)
	{
		printf("Название %s Автор %s Год %d \n", head->name, head->author , head->year);
		head = head->next;
	}
}