#include<string.h>
#include <stdlib.h>

#include "struct.h"			//Подключаем файл с объявлением структуры

MusicalComposition* createMusicalComposition(char* name, char* author, int year) 
{    
    MusicalComposition* tmp=NULL;									//Создаем указатель на структуру.
	tmp =(MusicalComposition*)malloc(sizeof(MusicalComposition));	//Выделяем под структуру память.
    strcpy(tmp->name, name);								//Скопируем переданные в функцию
    strcpy(tmp->author, author);							//значения в поля созданной структуры
    tmp->year = year;													
    return tmp;	   		//Возвращаем указатель на структуру
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* hold = NULL; //Создаем указатели на вспомогательные структуры и 
	MusicalComposition* temp = NULL; //присваиваем им нулевые указатели
	MusicalComposition* start=NULL;
	start = createMusicalComposition(array_names[0], array_authors[0], array_years[0]); //Создаем первый элемент списка
    hold = start;									//и присваиваем значение "start" временной переменной, чтобы вернуть
	int i;											//значение в конце
    for (i = 1; i<=n; i++)			//Цикл начинается с единицы и выполняется, пока счетчик "i" не будет равен количеству
    {								//элементов. При условии, когда счетчик меньше "n" - присваиваем временной переменной
        if(i<n){					//"temp" текущее значение. Далее создаем следующий элемент и делаем его текущим.
        	temp = start;			//Теперь элемент "temp" является предыдущим для текущего элемента "start"
        	start->next = (MusicalComposition*)createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        	start = start->next;
        	start->prev = temp; 
        } else start->next = NULL; //При достижении последнего элемента присваиваем след. элементу нулевой указатеь
    }
    start = hold;  	//Возвращаем "start" исходное значение, сохраненное в строке 22. 
    return start;
}





