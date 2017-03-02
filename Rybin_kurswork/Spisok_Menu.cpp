
#include "stdafx.h"
#include "MusicalComposition_API.h"

/* Меню работы со списком MysicalCompositionList */

/* Внешний указатель на первый элемент списка */
struct MusicalComposition * main_head = NULL;

int main()
{
	setlocale(LC_ALL, "Rus");// Русская локаль

	int switcher = 0;	// Для switch в меню
	int boolean = 1;	// Для switch в меню

	char name[80];	// Название композиции
	char author[80];	// Автор композиции
	int year = 0;	// Год создания
	int length = 0;	// Длина массивов данных для хранения имен и авторов

	printf("Для начала работы необходимо создать список. Введите длину списка\n");
	scanf("%d", &length);

	/* Память для массивов данных */
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);

	/* Первоначальное заполнение массивов данных для создания списка */
	for (int i = 0; i < length; i++)
	{
		printf("Введите название композиции затем автора и год создания\n");
		
		/* Очистим поток ввода */
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

	/* Указатель на первый элемент и создание списка */
	main_head = createMusicalCompositionList(names, authors, years, length);

	/* Освобождение памяти занятой массивами данных указателей 
	После создания списка очистим память от данных для его создания*/
	for (int i = 0; i < length; i++)
	{
		free(names[i]);
		free(authors[i]);
	}

	/* Освобождение памяти занятой массивами данных указателей на указатели*/
	free(names);
	free(authors);
	free(years);

	/* Работа меню работы со списком */
	do
	{
		printf("Меню работы со списком MusicalComposition\n1-Добавить элемент в список\n2-Удалить элемент\n3-Удалить все элементы\n4-Посчитать количество элементов\n5-Вывести элементы списка\n6-Добавить после каждого нечетного элемента еще три\n7-Выход из меню\n");
		scanf("%d", &switcher);

		if (main_head == NULL)
		{

			do
			{
				printf("Необходимо создать новый список. Если хотите продолжить и создать новый список - 1 Если выйти - 0 \n");
				scanf("%d", &switcher);
			} while (!((switcher == 1) || (switcher == 0))) ;

			if (switcher == 0)
			{
				break;
				boolean = 0;
			}
			
			else
			{
				printf("Введите длину списка \n");
				scanf("%d", &length);
				
				/* Отдельно создадим первый элемент списка */
				printf("Введите название композиции затем автора и год создания\n");
				
				/* Очистим поток ввода */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				fgets(author, 80, stdin);
				scanf("%d", &year);

				main_head = createMusicalComposition(name, author, year);
				
				for (int i = 0; i < length-1; i++)
				{
					printf("Введите название композиции затем автора и год создания\n");
					
					/* Очистим поток ввода */
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
				printf("Введите название композиции затем автора и год создания, которую хотите добавить в список\n");
				
				/* Очистим поток ввода */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				fgets(author, 80, stdin);
				scanf("%d", &year);

				push(main_head, createMusicalComposition(name, author, year));

				break;
			}
			case 2:
			{
				printf("Введите название композиции, которую хотите удалить\n");
				
				/* Очистим поток ввода */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				
				removeEl(main_head, name);

				break;
			}
			case 3:
			{
				printf("Введите название композициий, которые хотите удалить\n");
				
				/* Очистим поток ввода */
				while (getchar() != '\n');
				fgets(name, 80, stdin);
				
				removeAllEl(main_head, name);
				
				break;
			}
			case 4:
			{
				int number = count(main_head);
				
				if (number > 4)
					printf("В списке %d элементов \n", number);
				else if (number > 1)
					printf("В списке %d элемента \n", number);
				else 
					printf("В списке %d элемент \n", number);
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
				/* Установим значения лог. переменной в 0 
				чтобы остановить цикл */
				boolean = 0;
				break;
			}
			
			default:;
		}

	} while (boolean);

	/* Освобождение памяти занятой списком */
	free_spisok(main_head);

	return 0;
	}