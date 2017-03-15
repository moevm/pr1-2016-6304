#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "structure.h"
#define WAIT getchar(); getchar()



void not_so_stupid_cls(){
    if (system("cls"))   //Кроссплатформенная очистка экрана. На Windows очистка - cls
        system("clear"); //на Linux - clear
}

//Добавление элемента в конец списка
void push(MusicalComposition* head, MusicalComposition* element){
    while (head->next!=NULL){
        head = head->next; //Поиск конца списка
    }
    head->next=element;
    head->next->previous = head;
};

//Удаление элемента
void removeEl(MusicalComposition* head, char* name_for_remove){
    while (head!=NULL){
        if (strcmp(name_for_remove, head->name) == 0)
            break;  //Даже если head==NULL, while будет пытаться сделать strcmp с NULL->name
                    //и получит null pointer exception
        else
            head = head->next; //Переключение на следующий элемент. В head будет либо нужный элемент, либо NULL
    }
    if (head == NULL){
        printf("Element does not exists\n"); WAIT;
    }
    else if  ((head->previous!=NULL)&&(head->next!=NULL)){
        head->previous->next = head->next; //Случай, когда элемент стоит не в начале и не в конце
        head->next->previous = head->previous;
    }
    else if (head->next == NULL){
        head->previous->next = NULL; //Если элемент последний
    }
    else if(head->previous == NULL){
        while(head->next!=NULL){//Если элемент первый. 
								//Чтобы удалить его мы смещаем все элементы на 1 в сторону начала и удаляем последний (2->1, 3->2, 4->3, ... n->n-1, удалить n)
            strcpy(head->name,head->next->name);
            strcpy(head->author, head->next->author);
            head->year = head->next->year;
            head=head->next;
        }
        head->previous->next = NULL; 
        head->previous = NULL;
    }


};

int count(MusicalComposition* head){
    int i;
    for (i=0; head!=NULL; i++)
        head = head->next; //Подсчёт элементов - прибавление i пока не дойдем до конца
    return i;
};

void print_names(MusicalComposition* head){
    while (head!=NULL){
        printf("%s\n", head->name); //Тот же принцип, но с выводом имён
        head = head->next; 
    }
};

void print_all(MusicalComposition* head){
    int i=0;
    while (head!=NULL){
        printf("#%d: %s; %s; %d\n",i++, head->name, head->author, head->year);
        head = head->next; //А теперь - с выводом всех элементов структуры
    }
}

int main(){
    int length; int a = 1;
    printf("Input length of list: ");
    scanf("%d", &length);
    char** names = (char**)malloc(sizeof(char*)*length); 
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    int i;
    char name[80];
    char author[80];
    for (i=0;i<length;i++)
    {
        printf("Enter name #%d: ", i+1); //Ввод данных
        scanf("%s", name);
        printf("Enter author #%d: ", i+1);
        scanf("%s", author);
        printf("Enter year: ");
        scanf("%d", &years[i]);
        printf("--------------------\n");
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length); //Создание списка
    while (a!=0){
        not_so_stupid_cls(); 
        printf("Status: %d objects in list\n", count(head)); //Простое меню через switch
        printf("Choose action: \n");
        printf("0. Exit\n1. Add element \n2. Remove element\n3. Print names\n");
        printf("4. Print elements\n5. Sort elements by name\n6. Sort elements by year\n>");
        scanf("%d", &a);
        switch (a){
            case 0: break;
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter author: ");
                scanf("%s", author);
                printf("Enter age: ");
                scanf("%d", &i);
                push(head, createMusicalComposition(name, author, i));
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                removeEl(head, name);
                break;
            case 3:
                print_names(head); WAIT; //WAIT - это два getchar(), два необходимо для корректной работы
                break;
            case 4:
                print_all(head); WAIT;
                break;
            case 5:
                namesort(head);
                break;
            case 6:
                yearsort(head);
                break;
        }
    }
    return 0;

}
