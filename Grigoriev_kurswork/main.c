#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "api.h"
#include "kursfunc.h"

typedef struct MusicalComposition {
	char name[80]; //Имя композиции
	char author[80]; //Имя автора
	int year;
	struct MusicalComposition* next; //Указатель на следующий узел
	struct MusicalComposition* prev; //Указатель на предыдущий узел
}MusicalComposition;

int main(){
  int year;
	int len;
	int bool=1;
	int sw=0;
	printf("Чтобы начать работу со списком, вы должны его создать.\n");
	printf("Введите количество позиций списка:\n");
	scanf("%d", &len);
	/*Динамически выделяем память для хранения массивов данных*/
	char** names = (char**)malloc(sizeof(char*)*len);
	char** authors = (char**)malloc(sizeof(char*)*len);
	int* years = (int*)malloc(sizeof(int)*len);
	char name[80];
    char author[80];
	/*Заполняем список*/
	for (int i=0;i<len;i++)
	{
		printf("Введите название композиции, автора и год создания\n");
		scanf("%s%s%d", name, author, &year);
		printf("--------------------------------------------------\n");
		names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));
		strcpy(names[i], name);
		strcpy(authors[i], author);
		years[i] = year;
	}

	MusicalComposition* head=createMusicalCompositionList(names, authors, years, len); //Создание списка
	
	for(int i=0;i<len; i++) //Очистка данных, кот. были необходимы для создания списка
	{
		free (names[i]);
		free (authors[i]);
	}

	/*Очистка указателей на указатели*/
	free(names);
	free(authors);
	free(years);

	while(bool != 0)
	{
		printf("****************************************************************************\n");
		printf("Выберите команду:\n");
		printf("Добавить элемент в конец списка(enter '1')\n");
		printf("Удалить элемент(enter '2')\n");
		printf("Подсчет количества элементов списка(enter '3')\n");
		printf("Вывести названия композиций(enter '4')\n");
		printf("После каждого нечетного элемента добавить 3 произвольных элемента(enter '5')\n");
		printf("Удалить все элементы(enter '6')\n");
		printf("Выйти(enter '7')\n");
		scanf("%d", &sw);
		printf("****************************************************************************\n");

		switch(sw)
		{
			case 1:
				printf("Введите название композиции, автора и год создания:\n");
				scanf("%s %s %d", name, author, &year);
				push(head, createMusicalComposition(name, author, year));
                break;
            case 2:
            	printf("Введите название композиции, которую хотите удалить:\n");
            	scanf("%s", name);
            	removeEl(head, name);
            	break;
            case 3:
            	printf("Количество элементов в списке: %d\n", count(head));
            	break;
            case 4:
            	print_names(head);
            	break;
            case 5:
            	push3el(head);
            	break;
            case 6:
            	printf("Введите название композиций, которые хотите удалить:\n");
            	scanf("%s", name);
            	removeAllEl(head, name);
            	break;
           	case 7:
           		bool=0; 
           		break;
           	default: 
           		printf("Данная команда отсутствует!");
           		break;
		}
	}
	globalfree(head);
    return 0;
}
