#include <stdio.h>

void setMatrixConfig(int matrix[1000][1000]);
void inputMatrixElements(int rows, int userElements[1000][1000]);
void viewMatrix(int matrix[1000][1000], int n);
void rowsPower(int matrix[1000][1000], int n);
void diagonalSum(int matrix[1000][1000], int n);


int main(void)
{
	int matrixValues[1000][1000];
	
	setMatrixConfig(matrixValues);

	return 0;
}


void setMatrixConfig(int matrix[1000][1000])
{
	int rows;
	
	printf("%s", "Введите размер квадратной матрицы: ");
	scanf("%d", &rows);

	inputMatrixElements(rows, matrix);
}


void inputMatrixElements(int rows, int userElements[1000][1000])
{
	float element;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			printf("%s%d-%d\n", "Введите элемент матрицы ", i + 1, j + 1);
			scanf("%f", &element);
			userElements[i][j] = element;
		}
	}

	viewMatrix(userElements, rows);
	rowsPower(userElements, rows);
	diagonalSum(userElements, rows);
}


void viewMatrix(int matrix[1000][1000], int n)
{
	for(int i = 0; i < 71; i++) printf("-%s", (i == 0 || i == 70 ? "\n" : ""));
	for (int i = 0; i < n; ++i)
	{
		printf("\t\v");

		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}

	printf("\v");

	for(int i = 0; i < 70; i++) printf("-%s", (i == 69 ? "\n" : ""));
}


void rowsPower(int matrix[1000][1000], int n)
{
	int values[n];
	int helpValue;

	for (int i = 0; i < n; ++i)
	{
		helpValue = 1;
		for (int j = 0; j < n; ++j)
		{
			if(matrix[i][j] < 0) 
			{
				helpValue = -1;
				break;
			}
			else helpValue *= matrix[i][j];
		}
		values[i] = helpValue;
	}

	for (int i = 0; i < n; ++i)
	{
		if(values[i] != -1)
		{
			printf("%s %d - %d\n", "Произведение элементов строки", (i + 1), values[i]);
		}
		else printf("%s %d %s\n", "Строка", (i + 1), "содержит отрицательный элемент");
	}
}


// void diagonalSum(int matrix[1000][1000], int n)
// {
// 	int value[n];
// 	int value_down[n];

// 	for (int i = 0; i < n; ++i)
// 	{
// 		value[i] = 0;
// 		value_down[i] = 0;
// 	}

// 	for (int i = 0; i < n; ++i)
// 	{
// 		for (int j = 1; j < n; ++i)
// 		{
// 			value[i] += matrix[i-j-1][j];
// 		}
// 	}

// 	for (int i = 0; i < n; ++i)
// 	{
// 		printf("%d\n", value[i]);
// 	}
// }