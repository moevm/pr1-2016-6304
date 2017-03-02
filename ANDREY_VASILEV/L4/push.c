#include <stdlib.h>

#include "struct.h"  //Подключаем файл с объявлением структуры

void push(MusicalComposition* head,MusicalComposition* element)
{
	MusicalComposition* tmp = head;  //Сохраняем указатель на "head".
    while(head->next)		//Пока указатель на следующий элемент
    {						//не будет равен нулю будем передвигать
        head = head->next;  //указатель на следующий.
    }						//В конце "head" указывает на последний элем.
    head->next = element;	//Вместо указателя на "NULL" присваиваем ему
	element->prev = head;	//указатель на "element". Предыдущий указатель
	element->next = NULL;	//становится "head",а указатель на след. "NULL"
    head = tmp;				//Возвращаем исходное значение.
}



