#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "api.h"

typedef struct MusicalComposition {
	char name[80]; //Имя композиции
	char author[80]; //Имя автора
	int year;
	struct MusicalComposition* next; //Указатель на следующий узел
	struct MusicalComposition* prev; //Указатель на предыдущий узел
}MusicalComposition;

void push3el(MusicalComposition*head)
{
	int c=0; //Счетчик элементов списка
	MusicalComposition* head_next; //указатель для сохранения следующего элемента
	while (head) //Пока не встретим конец списка
	{ 
		c++; //По входу в цикл наращиваем счетчик
		head_next = head->next; //Сохраним указатель на следюущий элемент 
		if (c % 2 == 0) //Если элемент нечетный то двигаем указатель дальше 
		{
			head = head->next;
		}
		else
		{
			head->next = NULL; //Делаем текущий элемент последним 
			for (int i = 0; i < 3; i++) //Трижды добавляем в "конец" элементы 
				push(head, createMusicalComposition("something", "somebody", i));
			while (head->next) // Идем до последнего вставленного элемента 
				head = head->next;
			/* Восстанавляваем связь и двигаем указатель
			с помощью заданного ранее указателя на следющий до вставки элемент*/
			head->next = head_next;
			head = head_next;
		}
	}
}

void removeAllEl(MusicalComposition*head, char*name_for_remove)
{
	int c=count(head);
	for (int i=0; i<c; i++) 
	{
		removeEl(head, name_for_remove);
	}
}

void globalfree(MusicalComposition* head) //Функция для удаления списка
{
    while (head)
	{
		if (head->next == NULL) // Если последний то удаляем указатель 
		{
			free(head);
			return;
		}
		head = head->next; // Передвигаем указатель 
		free(head->prev); // Удаляем предыдущий 
	}
}
