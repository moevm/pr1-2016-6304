#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

char* get_name()
{
	char* ret = NULL;
	char ch;
	int k = 0;
	while((ch = getchar())!='\n'){
		ret = (char*)realloc(ret, (k+2)*sizeof(char));
		ret[k++] = ch;
	}
	if (k==0) return " ";
	ret[k--] = '\0';
	while(ret[k] == ' ' || ret[k] == '\t'){
		ret[k--] = '\0';
	}
	return ret;
}

MusicalComposition* createMusicalComposition(char* name, char* author, int year) 
{    
    MusicalComposition* tmp=NULL;									
	tmp =(MusicalComposition*)malloc(sizeof(MusicalComposition));	
    strcpy(tmp->name, name);								
    strcpy(tmp->author, author);							
    tmp->year = year;
	tmp->next = NULL;
	tmp->prev = NULL;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* hold = NULL; 
	MusicalComposition* temp = NULL;
	MusicalComposition* start=NULL;
	start = createMusicalComposition(array_names[0], array_authors[0], array_years[0]); 
    hold = start;		
	int i;		
    for (i = 1; i<n; i++)			
    {												
       	temp = start;			
       	start->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
       	start = start->next;
       	start->prev = temp; 
    }
    start = hold;  
    return start;
}

void push(MusicalComposition* head)
{
	int i, k;		
	MusicalComposition* end = NULL;
	printf("Количество новых композиций: ");
	k = atoi(get_name());
	char** names = (char**)malloc(sizeof(char*)*k);		
	char** authors = (char**)malloc(sizeof(char*)*k);	
	int* years = (int*)malloc(sizeof(int)*k);				
    for (i=0;i<k;i++)								
    {									
        printf("[%d] Композиция: ", i+1);
		names[i] = get_name();
        printf("[%d] Исполнитель: ", i+1);
		authors[i] = get_name();
        printf("[%d] Год: ", i+1);
		years[i] = atoi(get_name());
    }
	end = createMusicalCompositionList(names, authors, years, k);
	for(i = 0; i < k; i++){
		free(names[i]);
		free(authors[i]);
	}
	free(names);
	free(authors);
	free(years);
    while(head->next)		
    {						
        head = head->next; 
    }				
    head->next = end;	
	end->prev = head;
}

void removeEl(MusicalComposition** TrueHead, char* name_for_remove)
{
	MusicalComposition *head = *TrueHead; 		
    while(head)	
   	{	       
		if (strcmp(head->name, name_for_remove)==0) 
		{
			if(head->next == NULL && head->prev == NULL){
					*TrueHead = NULL;
					free(head);
					return;
				} else	if (head->next == NULL){   
				head->prev->next = NULL;
				free(head);
				return;
			} else if (head->prev == NULL){
				head->next->prev = NULL;
				*TrueHead = head->next;
				free(head);
				return;
			} else {
				head->next->prev = head->prev;	
				head->prev->next = head->next;
				free(head);
				return;
			}
								
		}
		head = head->next;	
	}
	printf("\nВ списке нет этой композиции!\n");
}

int count(MusicalComposition* head)  
{									
    int count=0;				
    while(head)			
    {			 	
         count++;			
        head = head->next;	
    }  						 		
	return count;		
};

void print_names(MusicalComposition* head)
{					
	int i = 1;
	printf("+------------------------------------------------------------+\n");
	printf("|Номер|                Композиция|          Исполнитель|  Год|\n");
	printf("+=====+==========================+=====================+=====+\n");
    while(head)					
    {						
        printf("│%5d│%26s│%21s│%5d│\n", i++, head->name, head->author, head->year);	  
		if (head->next == NULL)
			printf("+------------------------------------------------------------+\n");
		else printf("+------------------------------------------------------------+\n");
        head = head->next;	
    }  						
};

MusicalComposition* removeYear(MusicalComposition* head)
{
	MusicalComposition *i, *start = head;		
	printf("Удалить композиции, написанные раньше: "); 
	int k = atoi(get_name());
	while(head){						
		if (head->year < k){	
			if (head->next ==NULL && head->prev == NULL){
				free(head);
				return NULL;
			}
			if (head->next == NULL){	
				head->prev->next = NULL;
				free(head);
				break;
			} else if (head->prev == NULL){
				head->next->prev = NULL;	
				start = head->next;
				free(head);
			} else {
				head->next->prev = head->prev;	
				head->prev->next = head->next;
				free(head);
			}
		}
		head = head->next;		
	}
	return start;		
}

MusicalComposition* AddToBegin(MusicalComposition* head)
{
	int i, k;									
	printf("Количество новых композиций: ");	
	k = atoi(get_name());
	char** names = (char**)malloc(sizeof(char*)*k);			
	char** authors = (char**)malloc(sizeof(char*)*k);		
	int* years = (int*)malloc(sizeof(int)*k);		
    for (i=0;i<k;i++)								
    {											
        printf("%d Композиция: ", i+1);
		names[i] = get_name();
        printf("%d Исполнитель: ", i+1);
		authors[i] = get_name();
        printf("%d Год: ", i+1);
		years[i] = atoi(get_name());
    }
	MusicalComposition* NewHead;	
	NewHead= createMusicalCompositionList(names, authors, years, k);
	MusicalComposition* temp = NewHead;	
	for(i = 0; i < k; i++){
		free(names[i]);
		free(authors[i]);
	}
	free(names);
	free(authors);
	free(years);
	while(NewHead->next){			
		NewHead = NewHead->next;	
	}										
	NewHead->next = head;			
	head->prev = NewHead;			
	return temp;			
}

void menu()
{
	char* bufClean = NULL;
	system("clear");
	int size;
	char* name = NULL;
	printf("\n\n\n\n");
	MusicalComposition* head = NULL;
	int length;
	int i;
	int ListCreated = 0;
	char* choice = "m";
	while(choice[0] != 'q')
	{
		printf("****Меню****\n1: Создать список \n2: Показать список  \n3: Добавить композиции в начало списка \n");
		printf("4: Добавить композиции в конец списка \n5: Удалить композицию\n6: Удалить композиции, написанные раньше данного года\nq: Выход из программы\n\nВведите команду: ");
		choice = get_name();
		system("clear");
		switch(choice[0])

		{
			case '1':
				if(ListCreated){
					printf("\n\n\n\nВаш старый список будет удален! Продолжить? (y/n): ");
					choice = get_name();
					if (choice[0] == 'y') printf("\n");
					else {
						system("clear");
						printf("\n\n\n\n");
						break;
					}
				}
				printf("\n\n\n\nКоличество композиций: ");
				length = atoi(get_name());
    			char** names = (char**)malloc(sizeof(char*)*length);
    			char** authors = (char**)malloc(sizeof(char*)*length);
    			int* years = (int*)malloc(sizeof(int)*length);
    			for (i=0;i<length;i++)
   				 {
					printf("%d Название композиции: ", i+1);
					names[i] = get_name();
					printf("%d Исполнитель: ", i+1);
					authors[i] = get_name();
					printf("%d Год: ", i+1);
					years[i] = atoi(get_name());
    			}
				head = createMusicalCompositionList(names, authors, years, length);
				ListCreated = 1;
				for (i = 0; i <length; i++){
					free(names[i]);
					free(authors[i]);
				}
				free(names);
				free(years);
				free(authors);
				system("clear");
				printf("\n\n\n\n");
				break;
			case '2':
				if (ListCreated == 0){
					printf("\n\n\n\nСписок не создан\n");
					bufClean = get_name();
					system("clear");
					printf("\n\n\n\n");
					break;
				}
				printf("\n\nКоличество композиций: %d\n\n", count(head));
				print_names(head);
				bufClean = get_name();
				system("clear");
				printf("\n\n\n\n");
				break;
			case '3':
				if (ListCreated == 0){
					printf("\n\n\n\nСписок не создан!\n");
					bufClean = get_name();
					system("clear");
					printf("\n\n\n\n");
					break;
				}
				printf("\n\n\n\n");
				head = AddToBegin(head);
				system("clear");
				printf("\n\n\n\n");	
				break;
			case '4':
				if (ListCreated == 0){
					printf("\n\n\n\nСписок не создан!\n");
					bufClean = get_name();
					system("clear");
					printf("\n\n\n\n");
					break;
				}
				printf("\n\n\n\n");
				push(head);
				system("clear");
				printf("\n\n\n\n");
				break;
			case '5':
				if (ListCreated == 0){
					printf("\n\n\n\nСписок не создан!\n");
					bufClean = get_name();
					system("clear");
					printf("\n\n\n\n");
					break;
				}
				printf("\n\n\n\n");
				print_names(head);
				printf("Введите название композиции: ");
				size = count(head);
				name = get_name();
				removeEl(&head, name);
				if(head == NULL){
					printf("\nУдалена последняя композиция!\n");
					ListCreated = 0;
				} else if (size != count(head)){
					printf ("\nКомпозиция удалена!\n");
				} else printf("\nКомпозиция не удалена!\n");
				bufClean = get_name();
				system("clear");
				printf("\n\n\n\n");
				break;
			case '6':
				if (ListCreated == 0){
					printf("\n\n\n\nСписок не создан!\n");
					bufClean = get_name();
					system("clear");
					printf("\n\n\n\n");
					break;
				}
				printf("\n\n\n\n");
				print_names(head);
				head = removeYear(head);
				if (head == NULL){
					printf("\nУдалена последняя композиция!\n"); 
					bufClean = get_name();
					ListCreated = 0;
				}
				system("clear");
				printf("\n\n\n\n");
				break;
			case 'q':
				if(ListCreated){
					printf("\n\n\n\nВаш список будет утерян! Продолжить? (y/n): ");
					choice = get_name();
					if (choice[0] == 'y') printf("\n");
					else {
						system("clear");
						printf("\n\n\n\n");
						break;
					}
				}
				choice[0] = 'q';
				printf("\n\nДо свидания!\n\n\n");
				break;
			default: printf("\n\nОшибка, такой команды нет.\n\n");

		}
	}
}
