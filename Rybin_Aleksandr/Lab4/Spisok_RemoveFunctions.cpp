#include "MusicalComposition_API.h"

/* Функции на удаление */

/* Внешний указатель на первый элемент списка */
extern struct MusicalComposition * main_head;

/* Функция удаления элемента */
void removeEl(struct MusicalComposition* head, char *name_for_remove)
{
	/* Пока не конец списка двигаем указатель и сравниваем строки */
	while (head)
	{
		if (strcmp(head->name, name_for_remove) == 0)
		{
			/* Если элемент, который надо удалить последний то разрываем связь с предыдущим */
			if (head->next == NULL)
			{
				/* Если элемент последний то просто очищаем память
				и устанавливаем главный внешний указатель в NULL*/
				if (head->prev == NULL)
				{
					free(head);
					main_head = NULL;
					return;
				}
				
				/* У пердыдущего указатель на следующий 0 */
				head->prev->next = NULL;
				/* Очищаем память */
				free(head);

				return;
			}

			/* Если элемент, который надо удалить первый то разрываем связь со следующим
			Указатель на первый элемент меняем указателем на второй элемент*/
			else if (head->prev == NULL)
			{
				
				/* Главный указатель теперь указывает на второй элемент
				потому что первый удаляем*/
				main_head = head->next;
				
				/* Указатель на предыдущий NULL
				потому что удаляем его*/
				main_head->prev = NULL;
				free(head);
				
				return;
			}

			else
			{
				/* Меняем значения поля next у предыдущего элемента */
				head->prev->next = head->next;
				/* Меняем значение поля prev у следующего элемента */
				head->next->prev = head->prev;

				/* Очищаем память */
				free(head);

				return;
			}

		}

		/* Двигаем указатель */
		head = head->next;
	}

}

/* Освобождение памяти занятой списком  */
void free_spisok(struct MusicalComposition*head)
{
	/* Пока не конец списка */
	while (head)
	{
		/* Если последний то удаляем указатель */
		if (head->next == NULL)
		{
			free(head);
			return;
		}

		/* Передвигаем указатель */
		head = head->next;

		/* Удаляем предыдущий */
		free(head->prev);
	}
}