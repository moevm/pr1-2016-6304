/*
Лабораторная работа №2 "Моделирование стека"
2 семестр.
Васильев Андрей, группа 6304.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMANDS 100

/* Данная функция проверяет корректность введеной команды
и возвращает, в зависимости от команды, определенное целое.
Также для команды push определяется аргумент (value). */
int check_correction(char* choice, int* value)
{
	if(!choice) return 0;  //Проверка на пустую строку. 
	
	if(strcmp(choice, "pop") == 0) return 1;
	if(strcmp(choice, "top") == 0) return 2;
	if(strcmp(choice, "size") == 0) return 3;
	if(strcmp(choice, "exit") == 0) return 4;

/* Если строка содержит команду push, то ищем её аргумент*/
    if (strstr(choice, "push ") && strlen(choice) >= 6)
	{
		choice = choice + sizeof(char)*5;
		*value = atoi(choice);
		return 5;
    }
	return 0; //Во всех остальных случаях возвращается 0. 
}

int* pop(int* stack, int* len)
{
 (*len) --;
    return stack;
}

void top(int* stack, int len){
	printf("%d\n", stack[len-1]);
}

void size(int len)
{
 printf("%d\n", len);   
}

int* push (int* stack, int * len, int el)
{
    stack[(*len)] = el;
    (*len)++;
    printf("ok\n");
    return stack;
}
int main()
{
	int pushing_value = 0; //Добавляемый элемент
	int* stack = (int*)malloc(sizeof(int)*COMMANDS);	//Указатель на стек
	int multiplier = 1;   //Кол-во выделенных сейчас блоков памяти размером COMMANDS.
	int len = 0;	//Текущий размер стека
	char* choice = (char*)malloc(sizeof(char)*20); //Строка для команд.
	while (1)
	{
/*  Если кол-во элементов равно  количеству выделенной в данный момент памяти, то
выделяется доп память размером COMMANDS*/
		if(len == COMMANDS*multiplier)
			stack = (int*)realloc(stack, sizeof(int)*COMMANDS*(++multiplier));

		fgets(choice, 20, stdin); //Считываем команду и удаляем знак переноса (если есть)
		if(strchr(choice, '\n')) *strchr(choice, '\n') = '\0';

/* Передаем в проверяющую функцию команду и проверяем возвращаемое значение*/
		switch(check_correction(choice, &pushing_value))
		{
			case 1:    //команда pop
				if (len) 
				{
                    printf("%d\n", stack[len-1]);
                    stack = pop(stack, &len);
				} 
				else //Если стек пуст, то программа завершает работу.
				{
					printf("error\n");
					return 0;
				}
				break;

			case 2:    //команда top
				if(len)
                {
                    top(stack, len);
					//printf("%d\n", stack[len-1]); //вывод верхнего элемента стека
                }
                else
				{
					printf("error\n");
					return 0;
				}
				break;

			case 3:   //команда size
				size(len);	
				break;

			case 4:  //команда exit
				printf("bye\n");
                free(stack);
				return 0;
				break;

			case 5: //команда push
				stack = push(stack, &len, pushing_value);
				break;

			case 0:    //при вводе некорректной команды или 
			default:   //пустой строки работа продолжается
				continue;
				break;


		}
	}
	return 0;
}
