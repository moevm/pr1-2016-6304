#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "from_L_4.h"
#include "dlya_kurs.h"
int main(){
    int length; int a = 1,year;
    printf("Количество композиций в списке: ");
    scanf("%d", &length);
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    int i,t;
    char name[80];
    char author[80];
    for (i=0;i<length;i++)
    {
        printf("%d) Введите название, автора и год : ", i+1); 
        scanf("%s %s %d", name, author, &year);
        printf("-----------------------------------------\n");
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    while (a!=0){

        printf("Выберите действие: \n");
        printf("0. Выйти\n1. Добавить 1 элемент\n2. Добавить несколько элементов \n3. Удалить\n4. Список\n5. Количество элементов\n6.Удалить нечётные\n7.Просортировать по возрастанию авторов\n");
        scanf("%d", &a);
         printf("-----------------------------------------\n");
        switch (a){
            case 0: break;
            case 1:
                printf("Введите имя, автора и год: "); //просим ввести название, автора и год написания композиции
                scanf("%s %s %d", name, author, &year);//записываем значения
                push(head, createMusicalComposition(name, author, year));//обращаемся к функции push
                break;
            case 2:
            	printf("Сколько композиций вы хотите добавить?\n");
            	scanf("%d", &t);//записываем количество композиций для добавления
            	for(i=0;i<t;i++){
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
				RemoveNechet(head);
                break;
            case 7:
            	sortirovka(head);
            	break;
            default: printf("Дейсвие не существует"); break;
        }
         printf("-----------------------------------------\n");
    }
    return 0;

}
