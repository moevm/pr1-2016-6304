/*!
\file
\brief Lab2_Sem2 
\author Rybin Aleksandr 1 course 2 half
\date 05.04.2017
\version 1.0
*/

#include "Rybin_Lab2_Sem2.h"

int main()
{
	int stek[100];
	/* Index of last element in stek */
	int end = -1;

	char buffer[200];
	fgets(buffer, 200, stdin);

	char* ptr = strtok(buffer, " ");
	while (ptr)
	{
		/* Do integer from char */
		int element = atoi(ptr);

		/* If integer value push */
		if (!(element == 0))
			push(stek, &end, element);
		else
		{
			/* If too few arguments */
			if (end < 1)
			{
				printf("error");
				return 0;
			}
			int b = pop(stek, &end);
			int a = pop(stek, &end);

			switch (ptr[0])
			{
			case '+':
				push(stek, &end, a + b);
				break;
			case'-':
				push(stek, &end, a - b);
				break;
			case '*':
				push(stek, &end, a * b);
				break;
			case '/':
				push(stek, &end, a / b);
				break;
			default:
			{
				printf("error");
				return 0;
			}
			}
		}
		ptr = strtok(NULL, " ");
	}

	int result = pop(stek, &end);
	/* Check if any elements exists in stek */
	if (end > -1)
	{
		printf("error");
		return 0;
	}
	else
		printf("%d", result);
	return 0;
}

