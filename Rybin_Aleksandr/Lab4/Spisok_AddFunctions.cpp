#include "MusicalComposition_API.h"

/* Функции на добавление */

/* Функция создания и инициализации нового экземпляра структуры "MusicalComposition" */
struct MusicalComposition* createMusicalComposition(char *name, char* author, int year) {

	/* Выделим память для нового экземпляра структуры "MusicalComposition" */
	struct MusicalComposition* new_element = (struct MusicalComposition*)malloc(sizeof(struct MusicalComposition));

	/* Проинициализируем поля параматерами переданными в функцию */
	strcpy(new_element->name, name);
	strcpy(new_element->author, author);
	new_element->year = year;
	new_element->next = NULL;
	new_element->prev = NULL;

	/* Вернем указатель на новый экземпляр структуры "MusicalComposition" */
	return new_element;
}

/* Функция создания списка  */
struct MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {

	/* Указатель на первый элемент, который вернет функция */
	struct MusicalComposition*head = NULL;
	/* Указатель для движения по списку */
	struct MusicalComposition*ptr = NULL;
	/* Фиктивный указатель для работы со списком */
	struct MusicalComposition*f_ptr = NULL;


	/* Заполнение списка  */
	for (int i = 0; i < n; i++)
	{
		/* Выделяем память для нового элемента */
		ptr = (struct MusicalComposition*)malloc(sizeof(struct MusicalComposition));

		/* Создаим первый элемент отдельно чтобы вернуть head */
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
			/* Указатель на следующий элемент у фиктивного указателя равен вновь созданому */
			f_ptr->next = ptr;

			strcpy(ptr->name, array_names[i]);
			strcpy(ptr->author, array_authors[i]);
			ptr->year = array_years[i];
			ptr->next = NULL;

			/* Указатель на предыдущий элемент равен фиктивному указателю */
			ptr->prev = f_ptr;

			/* Двигаем фиктивный указатель вместе с новым */
			f_ptr = ptr;
		}
	}

	/* Вернем указатель на первый элемент списка */
	return head;
}

/* Добавление элемента в конец списка */
void push(struct MusicalComposition* head, struct MusicalComposition* element)
{	
	/* Двигаем указатель до последнего элемента */
	while (head->next)
		head = head->next;

	/* Указатель на следующий равен переданному в функцию параметру */
	head->next = element;

	/* Указатель на предыдущий равен текущему */
	element->prev = head;

	element->next = NULL;
}
