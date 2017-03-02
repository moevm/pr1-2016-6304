#include "MusicalComposition_API.h"

/* ������� ������ ���������� � ������ MysicalCompositionList */ 

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
		printf("�������� %s ����� %s ��� %d \n", head->name, head->author , head->year);
		head = head->next;
	}
}