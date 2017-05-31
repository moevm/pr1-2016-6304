#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#include "Functions.h"

#define INPUT_FILE_1 "t1.csv"
#define INPUT_FILE_2 "t2.csv"
int main() {
	setlocale(0, "");
	FILE* table1 = fopen(INPUT_FILE_1, "r");
	FILE* table2 = fopen(INPUT_FILE_2, "r");
	if (table1 == NULL) {
		printf("Fail with INPUT_FILE_1\n");
		return 0;
	}
	else if (table2 == NULL) {
		printf("Fail with INPUT_FILE_2\n");
		return 0;
	}
	Student* head = readingTable_1(table1);
	readingTable_2(table2, head);
	int counter = badGrades(head);
	printf("The number of students whose result is worse than 60%% of the maximum score: %d\n", counter);
	system("pause");
	fclose(table1);
	fclose(table2);
	return 0;
}
