#include "MusicalComposition_API.h"

/* ������� �� �������� */

/* ������� ��������� �� ������ ������� ������ */
extern struct MusicalComposition * main_head;

/* ������� �������� �������� */
void removeEl(struct MusicalComposition* head, char *name_for_remove)
{
	/* ���� �� ����� ������ ������� ��������� � ���������� ������ */
	while (head)
	{
		if (strcmp(head->name, name_for_remove) == 0)
		{
			/* ���� �������, ������� ���� ������� ��������� �� ��������� ����� � ���������� */
			if (head->next == NULL)
			{
				/* ���� ������� ��������� �� ������ ������� ������
				� ������������� ������� ������� ��������� � NULL*/
				if (head->prev == NULL)
				{
					free(head);
					main_head = NULL;
					return;
				}
				
				/* � ����������� ��������� �� ��������� 0 */
				head->prev->next = NULL;
				/* ������� ������ */
				free(head);

				return;
			}

			/* ���� �������, ������� ���� ������� ������ �� ��������� ����� �� ���������
			��������� �� ������ ������� ������ ���������� �� ������ �������*/
			else if (head->prev == NULL)
			{
				
				/* ������� ��������� ������ ��������� �� ������ �������
				������ ��� ������ �������*/
				main_head = head->next;
				
				/* ��������� �� ���������� NULL
				������ ��� ������� ���*/
				main_head->prev = NULL;
				free(head);
				
				return;
			}

			else
			{
				/* ������ �������� ���� next � ����������� �������� */
				head->prev->next = head->next;
				/* ������ �������� ���� prev � ���������� �������� */
				head->next->prev = head->prev;

				/* ������� ������ */
				free(head);

				return;
			}

		}

		/* ������� ��������� */
		head = head->next;
	}

}

/* ������� �������� ���� ��������� ���������� � ����� ��������� */
void removeAllEl(struct MusicalComposition*head, char*name_for_remove)
{
	int counter = 0;

	while (head)
	{
		/* ��������� ������� ���� ������� ��������� */
		if (strcmp(head->name, name_for_remove) == 0)
			counter++;
		head = head->next;
	}
	
	for (int i = 0; i < counter; i++)
		removeEl(main_head, name_for_remove);
	
}

/* ������������ ������ ������� �������  */
void free_spisok(struct MusicalComposition*head)
{
	/* ���� �� ����� ������ */
	while (head)
	{
		/* ���� ��������� �� ������� ��������� */
		if (head->next == NULL)
		{
			free(head);
			return;
		}

		/* ����������� ��������� */
		head = head->next;

		/* ������� ���������� */
		free(head->prev);
	}
}