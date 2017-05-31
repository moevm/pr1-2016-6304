#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

struct Student { 
	char last_name[20];
	char first_name[20];
	char fathers_name[20];
	char github[20];
	char mail[20];
	int group;
	int result;
	struct	Student* next;
};

typedef struct Student Student; 

Student* createStudent(char* array) { 
	Student* new_Student = (Student*)malloc(sizeof(Student)); 
	char* array_of_words[50];
	char* ptr = strtok(array, "; ,"); // ðàçäåëåíèå ñòðîêè íà ëåêñåìû
	int i = 0;
	while (ptr) {
		array_of_words[i++] = ptr;// çàïîëíåíèå ìàññèâà ëåêñåìàìè 
		ptr = strtok(NULL, "; ,");
	}

	strcpy(new_Student->last_name, array_of_words[0]);
	strcpy(new_Student->first_name, array_of_words[1]);
	strcpy(new_Student->fathers_name, array_of_words[2]);
	strcpy(new_Student->github, array_of_words[3]);
	strcpy(new_Student->mail, array_of_words[4]);
	new_Student->group = atoi(array_of_words[5]); // atoi ïðåîáðàçóåò char* â int

	return new_Student;
}

/*Ôóíêöèÿ ÷òåíèÿ ïåðâîé òàáëèöû*/
Student* readingTable_1(FILE* table) {
	char array[500];
	char* array_of_strings[50];
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
	fclose(table);
	return current;
}

/*Ôóíêöèÿ ÷òåíèÿ âòîðîé òàáëèöû*/
void readingTable_2(FILE* table, Student* head) {
	char array[500];
	char* array_of_strings[50];
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
	fclose(table);
}

/*Ôóíêöèÿ íàõîæäåíèÿ ìàêñèìàëüíîé îöåíêè ñðåäè ñòóäåíòîâ*/
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

/*Ôóíêöèÿ íàõîæäåíèÿ êîëè÷åñòâà ñòóäåíòîâ, îöåíêà êîòîðûõ íèæå, ÷åì 60% îò ìàêñèìàëüíîé îöåíêè*/
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



