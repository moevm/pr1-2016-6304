#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <locale.h> 


// Описание структуры MusicalComposition 
typedef struct MusicalComposition {
	char* name;
	char* author;
	int year;
	struct MusicalComposition *next;
	struct MusicalComposition *prev;
} MusicalComposition;

// Создание структуры MusicalComposition 

MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
	MusicalComposition* song = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	song->name = name;
	song->author = author;
	song->year = year;
	song->next = NULL;
	song->prev = NULL;
	return song;
}

// Функции для работы со списком MusicalComposition 

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n) {
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *prev = head;
	MusicalComposition *current;

	for (int i = 1; i < n; i++) {
		current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		current->prev = prev;
		prev->next = current;
		prev = current;
	}
	return head;
}


void push(MusicalComposition* head, MusicalComposition* element) {
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = element;
	element->prev = tmp;
}


void removeEl(MusicalComposition* head, char* name_for_remove) {
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	while (strcmp(tmp->name, name_for_remove)) {
		tmp = tmp->next;
	}
	if (tmp->prev == NULL) {
		tmp = tmp->next;
		tmp->prev = NULL;
		*head = *tmp;
	}
	else if (tmp->next == NULL) {
		tmp = tmp->prev;
		tmp->next = NULL;
	}
	else {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
}


int count(MusicalComposition* head) {
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	int count = 1;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		count++;
	}
	return count;
}


void print_names(MusicalComposition * head) {
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	while (tmp->next != NULL) {
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	printf("%s\n", tmp->name);
}


void removeUnevenEls(MusicalComposition* head) {
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	int count = 1;
	while (tmp != NULL) {
		if (!((count % 2) == 0)) {
			if (tmp->prev == NULL) {
				tmp = tmp->next;
				tmp->prev = NULL;
				*head = *tmp;
			}
			else if (tmp->next == NULL) {
				tmp = tmp->prev;
				tmp->next = NULL;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
		}
		tmp = tmp->next;
		count++;
	}
}

void swap(MusicalComposition* a, MusicalComposition* b) {
	if (a->prev == NULL) {
		MusicalComposition* temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
		temp->name = b->name;
		temp->author = b->author;
		temp->year = b->year;
		b->name = a->name;
		b->author = a->author;
		b->year = a->year;
		a->name = temp->name;
		a->author = temp->author;
		a->year = temp->year;

	}
	else {
		a->next = b->next;
		b->prev = a->prev;

		if (a->next != NULL) {
			a->next->prev = a;
		}
		if (b->prev != NULL) {
			b->prev->next = b;
		}
		b->next = a;
		a->prev = b;
	}
	return;
}


void sortirovka(MusicalComposition* head) {
	MusicalComposition* current;
	MusicalComposition* next;
	if (head != NULL) {
		current = head;
		next = current->next;
		int len = count(head);
		for (int i = 0; i<len; ++i) {
			current = head;
			next = current->next;
			for (int j = 0; j<len - i - 1; ++j) {
				if
					(strcmp(current->author, next->author)>0)
					swap(current, next);
				current = current->next;
				next = next->next;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int length; int a = 1, year;
	printf("Количество композиций в списке: ");
	scanf("%d", &length);
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);
	int i, t;
	char name[80];
	char author[80];
	for (i = 0;i<length;i++)
	{
		printf("%d) Введите название, автора и год : ", i + 1);
		scanf("%s %s %d", name, author, &year);
		printf("-----------------------------------------\n");
		names[i] = (char*)malloc(sizeof(char*) * (strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*) * (strlen(author) + 1));
		strcpy(names[i], name);
		strcpy(authors[i], author);

	}
	MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
	while (a != 0) {

		printf("Выберите действие: \n");
		printf("0. Выйти\n1. Добавить 1 элемент\n2. Добавить несколько элементов \n3. Удалить\n4. Список\n5. Количество элементов\n6.Удалить нечётные\n7.Просортировать по возрастанию авторов\n");
		scanf("%d", &a);
		printf("-----------------------------------------\n");
		switch (a) {
		case 0: break;
		case 1:
			printf("Введите имя, автора и год: "); //просим ввести название, автора и год написания композиции 
			scanf("%s %s %d", name, author, &year);//записываем значения 
			push(head, createMusicalComposition(name, author, year));//обращаемся к функции push 
			break;
		case 2:
			printf("Количество композиций на добавление\n");
			scanf("%d", &t);//записываем количество композиций для добавления 
			for (i = 0;i<t;i++) {
				printf("Введите имя, автора и год: ");//просим ввести название, автора и год написания композиции 
				scanf("%s %s %d", name, author, &year);//записываем значения 
				push(head, createMusicalComposition(name, author, year));//обращаемся к функции push 
			}
			break;
		case 3:
			printf("Введите название: ");
			scanf("%s", name);
			removeEl(head, name);
			break;
		case 4:
			print_names(head);
			break;
		case 5:
			printf("Количество композиций в списке %d\n", count(head));
			break;
		case 6:
			removeUnevenEls(head);
			break;
		case 7:
			sortirovka(head);
			break;
		default: printf("Дейсвия не существует"); break;
		}
		printf("-----------------------------------------\n");
	}
	return 0;

}
