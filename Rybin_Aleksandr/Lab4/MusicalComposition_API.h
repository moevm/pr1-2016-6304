#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/* Структура "Музыкальная композиция */
struct MusicalComposition {
	char name[80];		// Название композиции 
	char author[80];	// Автор композиции 
	int year;		// Год написания композиции 
	struct MusicalComposition* next;	// Указатель на следующий элемент 
	struct MusicalComposition* prev;	// Указатель на предыдущий элемент 
};

/* Функция создания и инициализации нового экземпляра структуры "MusicalComposition" */
struct MusicalComposition* createMusicalComposition(char *name, char* author, int year);

/* Функция создания списка  */
struct MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

/* Добавление элемента в конец списка */
void push(struct MusicalComposition* head, struct MusicalComposition* element);

/* Функция удаления элемента */
void removeEl(struct MusicalComposition* head, char*name_for_remove);

/* Подсчет элементов списка */
int count(struct MusicalComposition*head);

/* Печать имен */
void print_names(struct MusicalComposition* head);

/* Освобождение памяти занятой списком  */
void free_spisok(struct MusicalComposition*head);
