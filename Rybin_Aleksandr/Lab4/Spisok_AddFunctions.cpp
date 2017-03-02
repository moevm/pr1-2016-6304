#include "MusicalComposition_API.h"

/* ������� �� ���������� */

/* ������� �������� � ������������� ������ ���������� ��������� "MusicalComposition" */
struct MusicalComposition* createMusicalComposition(char *name, char* author, int year) {

	/* ������� ������ ��� ������ ���������� ��������� "MusicalComposition" */
	struct MusicalComposition* new_element = (struct MusicalComposition*)malloc(sizeof(struct MusicalComposition));

	/* ����������������� ���� ������������ ����������� � ������� */
	strcpy(new_element->name, name);
	strcpy(new_element->author, author);
	new_element->year = year;
	new_element->next = NULL;
	new_element->prev = NULL;

	/* ������ ��������� �� ����� ��������� ��������� "MusicalComposition" */
	return new_element;
}

/* ������� �������� ������  */
struct MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {

	/* ��������� �� ������ �������, ������� ������ ������� */
	struct MusicalComposition*head = NULL;
	/* ��������� ��� �������� �� ������ */
	struct MusicalComposition*ptr = NULL;
	/* ��������� ��������� ��� ������ �� ������� */
	struct MusicalComposition*f_ptr = NULL;


	/* ���������� ������  */
	for (int i = 0; i < n; i++)
	{
		/* �������� ������ ��� ������ �������� */
		ptr = (struct MusicalComposition*)malloc(sizeof(struct MusicalComposition));

		/* ������� ������ ������� �������� ����� ������� head */
		if (i == 0)
		{
			head = ptr;
			strcpy(ptr->name, array_names[i]);
			strcpy(ptr->author, array_authors[i]);
			ptr->year = array_years[i];
			ptr->next = NULL;
			ptr->prev = NULL;
			f_ptr = ptr;
		}
		else
		{
			/* ��������� �� ��������� ������� � ���������� ��������� ����� ����� ��������� */
			f_ptr->next = ptr;

			strcpy(ptr->name, array_names[i]);
			strcpy(ptr->author, array_authors[i]);
			ptr->year = array_years[i];
			ptr->next = NULL;

			/* ��������� �� ���������� ������� ����� ���������� ��������� */
			ptr->prev = f_ptr;

			/* ������� ��������� ��������� ������ � ����� */
			f_ptr = ptr;
		}
	}

	/* ������ ��������� �� ������ ������� ������ */
	return head;
}

/* ���������� �������� � ����� ������ */
void push(struct MusicalComposition* head, struct MusicalComposition* element)
{	
	/* ������� ��������� �� ���������� �������� */
	while (head->next)
		head = head->next;

	/* ��������� �� ��������� ����� ����������� � ������� ��������� */
	head->next = element;

	/* ��������� �� ���������� ����� �������� */
	element->prev = head;

	element->next = NULL;
}
