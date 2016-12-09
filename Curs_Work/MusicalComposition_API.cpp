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

/* Функция вставки 3 элементов после каждого нечетного в списке */
void Add3El(struct MusicalComposition*head)
{
	/* Счетчик элементов */
	int count = 0;

	/* Указатель для работы со списком */
	struct MusicalComposition * ptr = head;
	/* Фиктивный указатель для заполнения списка, который будет отставать на один элемент */
	struct MusicalComposition * f_ptr = head;

	/* Пока есть элементы в списке */
	while (head)
	{
		/* Счетчик элементов в списке */
		count++;

		if (!(count % 2 == 0))
			/* Вставляем 3 элемента */
			for (int i = 0; i < 3; i++)
			{
				/* Память для нового элемента */
				ptr = (struct MusicalComposition *)malloc(sizeof(struct MusicalComposition));

				/* Заполняем поля нового элемента */
				strcat(ptr->name, "abracadabra");
				strcat(ptr->author, "abracadabra");
				ptr->year = 1000 * count + 500;

				/* Указатель на преддыдущий равен указателю, который отстает */
				ptr->prev = f_ptr;
				/* Указатель на следующий у предыдущего равен вновь созданному */
				f_ptr->next = ptr;

				/* Уравниваем указатели */
				f_ptr = ptr;
			}

		/* Последний вставленный элемент указвает на следующий после 1, на который указывает head */
		ptr->next = head->next;
		/* Следующий после head элемент указывает на последний из вставленных 3 */
		head->next->prev = ptr;
		/* Двигаем head */
		head = head->next;
	}

}

/* Функция удаления всех элементов содержащих в имени подстроку */
void removeAllEl(struct MusicalComposition*head, char*name_for_remove)
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

		}

		head = head->next;
	}

}