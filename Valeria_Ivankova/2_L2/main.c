#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void push(int* stack, int* size,int element)
{
	stack[*size+1] = element;
	(*size)++;
}

int pop(int* stack, int* size)
{
	int str = stack[*size];
	(*size)--;

	return str;
}

int main(){
	int stack[100];
	int end = -1;
    char array[100];
	fgets(array, 100, stdin);
	char* str = strtok(array, " ");
	while (str!=0)
	{
		int element = atoi(str);
		if (element!= 0)
			push(stack, &end, element);
		else
		{
			if (end < 1)
			{
				printf("error");
				return 0;
			}
			int b = pop(stack, &end);
			int a = pop(stack, &end);

			switch (str[0])
			{
			case '+':
				push(stack, &end, a + b);
				break;
			case'-':
				push(stack, &end, a - b);
				break;
			case '*':
				push(stack, &end, a * b);
				break;
			case '/':
				push(stack, &end, a / b);
				break;
			default:
			{
				printf("error");
				return 0;
			}
			}
		}
		str = strtok(NULL, " ");
	}

	int result = pop(stack, &end);
	if (end > -1)
	{
		printf("error");
		return 0;
	}
	else
		printf("%d", result);
	return 0;
}
