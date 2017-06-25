#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Считывание матрицы
void readMatrixFromFile(char* file_name, int row, int column, int** array)
{
	FILE* input_file = fopen(file_name, "r");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
             //Считывание элемента из файла с матрицей
			fscanf(input_file, "%d", &array[i][j]);
		}
	}

}

//Вывод матрицы на консоль
void printMatrix(int** array, int row, int column)
{
	printf("\nArray:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

//Сохранение отсортированной матрицы в файл
void saveToFileMatrix(int** array, int row, int column)
{
	FILE* output_file = fopen("./output.txt", "w");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fprintf(output_file, "%d ", array[i][j]);
		}
		fprintf(output_file, "\n");
	}
	fclose(output_file);
}

int column_ = 0;
//Сравнение двух элементов
int comparator(const void *a, const void *b)
{
	int **aa = (int**)a;
	int **bb = (int**)b;
	for (int i = 0; i < column_; i++)
	{
		if ((*aa)[i] != (*bb)[i])
		{
			return (*aa)[i] - (*bb)[i];
		}
		
	}
}




int main()
{
	printf("Enter path to file with matrix: ");
	char file_name[100];
	fgets(file_name, 100, stdin);
	(*strstr(file_name, "\n")) = 0;
	
    //Открываем файл с матрицей
	FILE* input_file = fopen(file_name, "r");

    //Выводим сообщение, если файл не существует
	if (!input_file)
	{
		printf("Fail!\n");
		printf("Error with file: %s\n", file_name);
		return 0;
	}


	int NumberOfElements = 0;  //Количество элементов в матрице
	int row = 0;               //Количество строк в матрице
	int column = 0;            //Количество столбцов в матрице 

        //Считываем все символы из файла
	while (!feof(input_file))
	{
		char currentSymbol;
		fscanf(input_file, "%c", &currentSymbol);

                // Если считанный символ - \n - увеличиваем количество строк
		if (currentSymbol == '\n')
			column++;
                /*
                     Если считанный символ - пробел - увеличиваем количество
                     элементов матрицы, так как после каждого числа идет
                     пробел, кроме последних чисел в строке - там абзац
                */

		if (currentSymbol == ' ')
			NumberOfElements++;
	}
         /*
              Увеличиваем количество стоблов на 1, так
              как после последней строки не стоит знак абзаца
         */
	column++;
         /*
              Добавляем к NumberOfElements количество последних числел в строке
              после которых идет абазц, они не были посчтина в цикле
        */
	NumberOfElements += column;

        //Высчитываем количество строк в матрице
	row = NumberOfElements / column;

	//Проверка на квадратность матрицы
	if (row != column)
	{
		printf("Fail!\n");
		printf("Matrix is not square\n");

		return 0;
	}

	printf("\nNumber Of Elements: %d\nColumn: %d\nRow: %d\n\n", NumberOfElements, column, row);
	fclose(input_file);



	int** array = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; i++)
	{
		array[i] = (int*)malloc(sizeof(int)*column);
	}

	readMatrixFromFile(file_name, row, column, array);
	printMatrix(array, row, column);

	column_ = column;
	qsort(array, row, sizeof(int*), comparator); //Быстрая сортировка


	printMatrix(array, row, column);
	saveToFileMatrix(array, row, column);


	system("pause");
	return 0;
}
