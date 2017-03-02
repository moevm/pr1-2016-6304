
#include "stdafx.h"
#include "MusicalComposition_API.h"

/* ���� ������ �� ������� MysicalCompositionList */

/* ������� ��������� �� ������ ������� ������ */
struct MusicalComposition * main_head = NULL;

int main()
{
	setlocale(LC_ALL, "Rus");// ������� ������

	int switcher = 0;	// ��� switch � ����
	int boolean = 1;	// ��� switch � ����

	char name[80];	// �������� ����������
	char author[80];	// ����� ����������
	int year = 0;	// ��� ��������
	int length = 0;	// ����� �������� ������ ��� �������� ���� � �������

	printf("��� ������ ������ ���������� ������� ������. ������� ����� ������\n");
	scanf("%d", &length);

	/* ������ ��� �������� ������ */
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);

	/* �������������� ���������� �������� ������ ��� �������� ������ */
	for (int i = 0; i < length; i++)
	{
		printf("������� �������� ���������� ����� ������ � ��� ��������\n");
		
		/* ������� ����� ����� */
		while (getchar() != '\n');
		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		scanf("%d", &year);

		names[i] = (char*)malloc(sizeof(char*) * (strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*) * (strlen(author) + 1));

		strcpy(names[i], name);
		strcpy(authors[i], author);
		years[i] = year;
	}

	/* ��������� �� ������ ������� � �������� ������ */
	main_head = createMusicalCompositionList(names, authors, years, length);

	/* ������������ ������ ������� ��������� ������ ���������� 
	����� �������� ������ ������� ������ �� ������ ��� ��� ��������*/
	for (int i = 0; i < length; i++)
	{
		free(names[i]);
		free(authors[i]);
	}

	/* ������������ ������ ������� ��������� ������ ���������� �� ���������*/
	free(names);
	free(authors);
	free(years);

	/* ������ ���� ������ �� ������� */
	do
	{
		printf("���� ������ �� ������� MusicalComposition\n1-�������� ������� � ������\n2-������� �������\n3-������� ��� ��������\n4-��������� ���������� ���������\n5-������� �������� ������\n6-�������� ����� ������� ��������� �������� ��� ���\n7-����� �� ����\n");
		scanf("%d", &switcher);

		if (main_head == NULL)
		{

			do
			{
				printf("���������� ������� ����� ������. ���� ������ ���������� � ������� ����� ������ - 1 ���� ����� - 0 \n");
				scanf("%d", &switcher);
			} while (!((switcher == 1) || (switcher == 0))) ;

			if (switcher == 0)
			{
				break;
				boolean = 0;
			}
			
			else
			{
				printf("������� ����� ������ \n");
				scanf("%d", &length);
				
				/* �������� �������� ������ ������� ������ */
				printf("������� �������� ���������� ����� ������ � ��� ��������\n");
				
				/* ������� ����� ����� */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				fgets(author, 80, stdin);
				scanf("%d", &year);

				main_head = createMusicalComposition(name, author, year);
				
				for (int i = 0; i < length-1; i++)
				{
					printf("������� �������� ���������� ����� ������ � ��� ��������\n");
					
					/* ������� ����� ����� */
					while (getchar() != '\n');
					fgets(name, 80, stdin);
					fgets(author, 80, stdin);
					scanf("%d", &year);

					push(main_head, createMusicalComposition(name, author, year));
				}
			}
		}

		else
		switch (switcher)
		{
			case 1:
			{
				printf("������� �������� ���������� ����� ������ � ��� ��������, ������� ������ �������� � ������\n");
				
				/* ������� ����� ����� */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				fgets(author, 80, stdin);
				scanf("%d", &year);

				push(main_head, createMusicalComposition(name, author, year));

				break;
			}
			case 2:
			{
				printf("������� �������� ����������, ������� ������ �������\n");
				
				/* ������� ����� ����� */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				
				removeEl(main_head, name);

				break;
			}
			case 3:
			{
				printf("������� �������� �����������, ������� ������ �������\n");
				
				/* ������� ����� ����� */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				
				removeAllEl(main_head, name);
				
				break;
			}
			case 4:
			{
				int number = count(main_head);
				
				if (number > 4)
					printf("� ������ %d ��������� \n", number);
				else if (number > 1)
					printf("� ������ %d �������� \n", number);
				else 
					printf("� ������ %d ������� \n", number);
				break;
			}
			case 5:
			{
				print_names(main_head);
				break;
			}
			case 6:
			{
				Add3El(main_head);
				break;
			}
			case 7: 
			{
				/* ��������� �������� ���. ���������� � 0 
				����� ���������� ���� */
				boolean = 0;
				break;
			}
			
			default:;
		}

	} while (boolean);

	/* ������������ ������ ������� ������� */
	free_spisok(main_head);

	return 0;
	}