
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ��������� "����������� ���������� */
struct MusicalComposition {
	char name[80];		// �������� ���������� 
	char author[80];	// ����� ���������� 
	int year;		// ��� ��������� ���������� 
	struct MusicalComposition* next;	// ��������� �� ��������� ������� 
	struct MusicalComposition* prev;	// ��������� �� ���������� ������� 
};

struct MusicalComposition * createMusicalComposition(char *name, char* author, int year);

struct MusicalComposition * createMusicalCompositionList(char** array_names, char** array_authors, int*array_years, int n);

void push(struct MusicalComposition* head, struct MusicalComposition * element);

void removeEl(struct MusicalComposition* head, char* name_for_remove);

int count(struct MusicalComposition * head);

void print_names(struct MusicalComposition*head);

int main() {

}

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
	struct MusicalComposition*head =NULL;
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

/* ������� �������� �������� */
void removeEl(struct MusicalComposition*head, char*name_for_remove)
{
	/* ���� �� ����� ������ ������� ��������� � ���������� ������ */
	while (head)
	{
		if (strcmp(head->name, name_for_remove) == 0)
		{
			/* ���� �������, ������� ���� ������� ��������� �� ��������� ����� � ���������� */
			if (head->next == NULL)
			{
				head->prev->next = NULL;
				return;
			}
			
			/* ���� �������, ������� ���� ������� ������ �� ��������� ����� �� ��������� 
			��������� �� ������ ������� ������ �� ������ �������*/
			else if (head->prev == NULL)
			{
				head->next->prev = NULL;
				*head = *head->next;
				return;
			}
			
			/* ������ �������� ���� next � ����������� �������� */
			head->prev->next = head->next;
			/* ������ �������� ���� prev � ���������� �������� */
			head->next->prev = head->prev;
			
			break;
		}
		
		head = head->next;
	}

}

/* ������� ��������� ������ */
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

/* ������ ���� */
void print_names(struct MusicalComposition* head)
{
	while (head)
	{
		printf("%s \n", head->name);
		head = head->next;
	}
}