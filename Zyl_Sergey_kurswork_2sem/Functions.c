#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

struct Student { // структура, описывающая информацию в csv файлах
	char last_name[20];
	char first_name[20];
	char fathers_name[20];
	char github[20];
	char mail[20];
	int group;
	int result;
	struct	Student* next;
};

typedef struct Student Student; // спецификатор "typedef" делает новое имя типа

Student* createStudent(char* array) { // функция инициализации элемента списка
	Student* new_Student = (Student*)malloc(sizeof(Student)); 
	char** array_of_words = (char**)malloc(50 * sizeof(char*));
	char* ptr = strtok(array, "; ,"); // разделение строки на лексемы
	int i = 0;
	while (ptr) {
		array_of_words[i++] = ptr;// заполнение массива лексемами 
		ptr = strtok(NULL, "; ,");
	}

	strcpy(new_Student->last_name, array_of_words[0]);
	strcpy(new_Student->first_name, array_of_words[1]);
	strcpy(new_Student->fathers_name, array_of_words[2]);
	strcpy(new_Student->github, array_of_words[3]);
	strcpy(new_Student->mail, array_of_words[4]);
	new_Student->group = atoi(array_of_words[5]); // atoi преобразует char* в int

	free(array_of_words);
	return new_Student;
}

/*Функция чтения первой таблицы*/
Student* readingTable_1(FILE* table) {
	char* array = (char*)malloc(500 * sizeof(char));
	char** array_of_strings = (char**)malloc(50 * sizeof(char*));
	int i = 0;
	Student* current;
	Student* prev;
	Student* next;
	while (fgets(array, 500, table)) {
		if (array[strlen(array) - 1] == '\n')
			array[strlen(array) - 1] = '\0';
		array_of_strings[i] = array;
	
		if (i == 0) {
			current = createStudent(*array_of_strings);
			current->next = NULL;
			prev = current;
		}
		else {
			current = createStudent(array_of_strings[i]);
			current->next = prev;
			prev = current;

		}
		i++;
	}
	free(array);
	free(array_of_strings);
	fclose(table);
	return current;
}

/*Функция чтения второй таблицы*/
void readingTable_2(FILE* table, Student* head) {
	char* array = (char*)malloc(500 * sizeof(char));
	char** array_of_strings = (char**)malloc(50 * sizeof(char*));
	int i = 0;
	Student* current;
	current = head;
	while(current){
		fgets(array, 500, table);
		if (array[strlen(array) - 1] == '\n')
			array[strlen(array) - 1] = '\0';
		array_of_strings[i] = array;
		array_of_strings[i] = strtok(array_of_strings[i], ";,");
		int key = 0;
		while (array_of_strings[i]) {
			if (key<2) {
				array_of_strings[i] = strtok(NULL, ";,");
			}
			else {
				current->result = atoi(array_of_strings[i]);
				array_of_strings[i] = strtok(NULL, ";,");
			}
			key++;
		}
		current = current->next;
		i++;

	}
	free(array);
	free(array_of_strings);
	fclose(table);
}

/*Функция нахождения максимальной оценки среди студентов*/
int maxGrade(Student* head) {
	int result = 0;
	int max = 0;
	while (head) {
		result = head->result;
		if (result>max)
			max = result;
		head = head->next;
	}
	return max;
}

/*Функция нахождения количества студентов, оценка которых ниже, чем 60% от максимальной оценки*/
int badGrades(Student* head) {
	int counter = 0;
	int max = maxGrade(head)*0.6;
	while (head) {
		if (head->result < max) {
			counter++;
		}
		head = head->next;
	}
	return counter;
}



