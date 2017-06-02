#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct Students_file1
{
	char last_name[15];
	char first_name[15];
} Students_file1;

typedef struct Students_file2
{
    char last_name[15];
	char first_name[15];
	int Score;
} Students_file2;

int getstudfile_1(char *string, Students_file1 *Studfrom1, int num)
{
	char *last_name = strtok(string, ";,");
	char *first_name = strtok(NULL, ";,");
	strcpy(Studfrom1[num].last_name, last_name);
	strcpy(Studfrom1[num].first_name, first_name);
	return 0;
}
int getstudfile_2(char *string, Students_file2 *Studfrom2, int num)
{
	char *last_name = strtok(string, ";,");
	char *first_name = strtok(NULL, ";,");
	char *Score = strtok(NULL, ";,");
	strcpy(Studfrom2[num].last_name, last_name);
	strcpy(Studfrom2[num].first_name, first_name);
	Studfrom2[num].Score = atoi(Score);
	return 0;
}
	
int getscore(Students_file2 Studfrom2, int NumOfStud)
{

	int i;
	for (i = 0; i < NumOfStud; i++)
			{
			return Studfrom2.Score;
		}
}

int  Numofstud(FILE *file_1, FILE *file_2, Students_file1 *Studfrom1, Students_file2 *Studfrom2) {
 int n = 0, m = 0;
 char *string = (char *)malloc(200);
while (!feof(file_1))
	{
		fscanf(file_1, "%s", string);
		if (string[0] != '\0')
		{
		    if (getstudfile_1(string, Studfrom1, n) == 0)
		    n++;
			string[0] = '\0';
}
}
while (!feof(file_2))
	{
		fscanf(file_2, "%s", string);
		if (string[0] != '\0')
		{
		    if (getstudfile_2(string, Studfrom2, m) == 0) 
		    m++;
			string[0] = '\0';
}
}
free(string);
if (n == m){
	return n;}
	else{
	    printf("Fail with number of students");
	}
	
}

int main() {
setlocale(LC_ALL, "");

	
	FILE* file_1 = fopen("cw/input_file_1.csv", "r");
	FILE* file_2 = fopen("cw/input_file_2.csv", "r");
	Students_file1 *Studfrom1 = (Students_file1 *)calloc(100, sizeof(Students_file1));
	Students_file2 *Studfrom2 = (Students_file2 *)calloc(100, sizeof(Students_file2));
	if (file_1 == NULL) {
		printf("Fail with input_file_1\n");
		return 0;
	}
	else if (file_2 == NULL) {
		printf("Fail with input_file_2\n");
		return 0;
	}
int NumOfStud = Numofstud( file_1, file_2, Studfrom1, Studfrom2);

	int max = 0, count = 0,i = 0;
	for ( i; i<NumOfStud; i++)
	{
		int studsscore = getscore(Studfrom2[i], NumOfStud);            
		
	

		if (studsscore > max)												
		{
			max = studsscore;
			count = 1;
		}
		else if (studsscore == max)
			count++;
		
	}

	printf("Кол-во студентов с высшим баллом = %d\n",  count);
    fclose(file_1);
	fclose(file_2);
	free(Studfrom2);
	free(Studfrom1);

	
	return 0;
}
