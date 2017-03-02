#include "struct.h"

int count(MusicalComposition* head)  
{									 //Создаем указатель и присваиваем
    MusicalComposition* hold = head; //ему значение передаваемой структ.
    int count=0;					 //Создаем счетчик со значением 0.
    while(head)				 //Цикл "while" будет выполнятся пока 
    {			 			 //указатель не примет значение "NULL".
         count++;			 //При каждом выполнение цикла увеличиваем
        head = head->next;	 //счетчик на единицу.
    }  						 //
    head = hold; 			 //Присваиваем "head" исходное значение
	return count;			 //Возвращаем счетчик
};




