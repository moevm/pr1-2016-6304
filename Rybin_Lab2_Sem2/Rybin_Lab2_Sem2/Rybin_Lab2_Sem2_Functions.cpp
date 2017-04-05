/*!
\file
\brief Lab2_Sem2 Functions for stek
\author Rybin Aleksandr 1 course 2 half
\date 05.04.2017
\version 1.0
*/

#include "Rybin_Lab2_Sem2.h"

void push(int* stek, int* index,int element)
{
	stek[*index + 1] = element;
	(*index)++;
}

int pop(int* stek, int* index)
{
	int tmp = stek[*index];
	(*index)--;

	return tmp;
}