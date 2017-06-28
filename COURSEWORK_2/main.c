#include <stdlib.h>
#include "rectangle.h"
#include "get_matrix.h"
#include "searching.h"

int main (int count, char** input)
{
	int height = 0, widht = 0;
	int *matrix = get_matrix(input[1], &height, &widht);
	if (!matrix)
	{
		printf ("Error, wrong input!\n");
		return 0;
	}
	rectangle answer = rect_search(matrix, height, widht);
	if(!answer.square)
		printf ("There are no white rectangles in %s\n", input[1]);
	else
		printf ("Top left corner:\n\t\t%d\n\t\t%d\nBottom right corner\n\t\t%d\n\t\t%d\n", answer.x1, answer.y2, answer.x2, answer.y1);
	free(matrix);
	return 0;		
}