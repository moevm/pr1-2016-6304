#include <stdlib.h>

#include "struct.h"

void removeEl(MusicalComposition** TrueHead, char* name_for_remove)
{
	MusicalComposition *head = *TrueHead; //Создаем переменную и 
   				         //сохраняем в ней "TrueHead".
    	while(head)	//Цикл выполняется пока указатель 
    	{	       //станет равен "NULL".
		if (strcmp(head->name, name_for_remove)==0) //Сравниваем строки 
         	{	
			if (head->next == NULL){   //Если элемент последний, то текущим
				head->prev->next = NULL; //становится предыдущий элемент, а
				free(head); //его указатель на след. становится NULL				break;
				break;
			} else if (head->prev == NULL){	//Если удаляемый элемент первый, то
				head->next->prev = NULL;	//"TrueHead" присваивается следующий
				*TrueHead = head->next;	//элемент списка, т.е.новое начало списка.
				free(head);
				break;
			} else {
//В случае, когда элемент является не крайним, перемещаем указатели данным образом
				head->next->prev = head->prev;	
				head->prev->next = head->next;
				free(head);
				break;
			}
								
		}
		head = head->next;	/*Если строки не совпали, делаем текущим указатель на след. структуру */
	}
}
