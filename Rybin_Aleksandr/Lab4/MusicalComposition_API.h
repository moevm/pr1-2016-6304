#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/* ��������� "����������� ���������� */
struct MusicalComposition {
	char name[80];		// �������� ���������� 
	char author[80];	// ����� ���������� 
	int year;		// ��� ��������� ���������� 
	struct MusicalComposition* next;	// ��������� �� ��������� ������� 
	struct MusicalComposition* prev;	// ��������� �� ���������� ������� 
};

/* ������� �������� � ������������� ������ ���������� ��������� "MusicalComposition" */
struct MusicalComposition* createMusicalComposition(char *name, char* author, int year);

/* ������� �������� ������  */
struct MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

/* ���������� �������� � ����� ������ */
void push(struct MusicalComposition* head, struct MusicalComposition* element);

/* ������� �������� �������� */
void removeEl(struct MusicalComposition* head, char*name_for_remove);

/* ������� ��������� ������ */
int count(struct MusicalComposition*head);

/* ������ ���� */
void print_names(struct MusicalComposition* head);

/* ������������ ������ ������� �������  */
void free_spisok(struct MusicalComposition*head);
