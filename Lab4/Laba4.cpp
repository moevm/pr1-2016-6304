
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Структура "Музыкальная композиция */
struct MusicalComposition {
	char name[80];		// Название композиции 
	char author[80];	// Автор композиции 
	int year;		// Год написания композиции 
	struct MusicalComposition* next;	// Указатель на следующий элемент 
	struct MusicalComposition* prev;	// Указатель на предыдущий элемент 
};

struct MusicalComposition * createMusicalComposition(char *name, char* author, int year);

struct MusicalComposition * createMusicalCompositionList(char** array_names, char** array_authors, int*array_years, int n);

void push(struct MusicalComposition* head, struct MusicalComposition * element);

void removeEl(struct MusicalComposition* head, char* name_for_remove);

int count(struct MusicalComposition * head);

void print_names(struct MusicalComposition*head);

int main() {

}

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
	struct MusicalComposition*head =NULL;
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

/* Функция удаления элемента */
void removeEl(struct MusicalComposition*head, char*name_for_remove)
{
	/* Пока не конец списка двигаем указатель и сравниваем строки */
	while (head)
	{
		if (strcmp(head->name, name_for_remove) == 0)
		{
			/* Если элемент, который надо удалить последний то разрываем связь с предыдущим */
			if (head->next == NULL)
			{
				head->prev->next = NULL;
				return;
			}
			
			/* Если элемент, который надо удалить первый то разрываем связь со следующим 
			Указатель на первый элемент меняем на второй элемент*/
			else if (head->prev == NULL)
			{
				head->next->prev = NULL;
				*head = *head->next;
				return;
			}
			
			/* Меняем значения поля next у предыдущего элемента */
			head->prev->next = head->next;
			/* Меняем значение поля prev у следующего элемента */
			head->next->prev = head->prev;
			
			break;
		}
		
		head = head->next;
	}

}

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
		printf("%s \n", head->name);
		head = head->next;
	}
}