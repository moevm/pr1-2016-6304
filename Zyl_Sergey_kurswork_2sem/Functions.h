#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct Student Student;

Student* createStudent(char* array);/*������� ������ ������ �������*/
Student* readingTable_1(FILE* table);/*������� ������ ������ �������*/
void readingTable_2(FILE* table, Student* head);
int maxGrade(Student* head);
int badGrades(Student* head);




