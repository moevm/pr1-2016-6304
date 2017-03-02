#include <stdio.h>

#include "struct.h"		//Подключаем заголовочный файл с
						//объявлением структуры
void print_names(MusicalComposition* head)
{					
     MusicalComposition* hold = head; //Сохраняем значение "head"
    while(head)						  //Пока указатель не равен "NULL"
    {								    //выводим текущее значение "name"
        printf("%s\n", head->name);	  
        head = head->next;		        //Делаем текущим указатель на след.
    }  								    //структуру

    head = hold;   //Возвращаем исходное значение указателя
};


