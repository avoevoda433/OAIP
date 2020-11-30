#include <stdio.h>
#include <math.h>

void setMatrixConfig(float matrix[1000][1000]);
void inputMatrixElements(int rows, int collumn, float userElements[1000][1000]);
void checkMatrixRows(float userElements[1000][1000],  int m, int n);
void viewMatrix(float matrix[1000][1000], int m, int n);
void checkTask(float matrix[1000][1000], float zeroInfo[100], int len,  int collumn);
void modificateMatrix(float matrix[1000][1000], int m, int n);


int main(void)
{
	float matrixValues[1000][1000];
	
	setMatrixConfig(matrixValues);

	return 0;
}


void setMatrixConfig(float matrix[1000][1000])
{
	int rows, collumn;
	
	printf("%s", "Введите количество строк матрицы:");
	scanf("%d", &rows);

	printf("%s", "Введите количество столбцов матрицы:");
	scanf("%d", &collumn);

	inputMatrixElements(rows, collumn, matrix);
}


void inputMatrixElements(int rows, int collumn, float userElements[1000][1000])
{
	float element;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < collumn; ++j)
		{
			printf("%s%d-%d\n", "Введите элемент матрицы ", i + 1, j + 1);
			scanf("%f", &element);
			userElements[i][j] = element;
		}
	}

	printf("\n%s", "-Изначальная матрица");
	viewMatrix(userElements, rows, collumn);
	checkMatrixRows(userElements, rows, collumn);
}


void viewMatrix(float matrix[1000][1000], int m, int n)
{
	for(int i = 0; i < 71; i++) printf("-%s", (i == 0 || i == 70 ? "\n" : ""));
	for (int i = 0; i < m; ++i)
	{
		printf("\t\v");

		for (int j = 0; j < n; ++j)
		{
			printf("%g\t", matrix[i][j]);
		}

		printf("\n");
	}

	printf("\v");
	for(int i = 0; i < 70; i++) printf("-%s", (i == 69 ? "\n" : ""));
}


void checkMatrixRows(float userElements[1000][1000], int m, int n)
{
	float findZero[m];
	int help;

	for (int i = 0; i < m; ++i)
	{
		help = 1;

		for (int j = 0; j < n; ++j)
		{
			if(userElements[i][j] == 0)
			{
				findZero[i] = 0;
				help = 0;
				break;
			}
		}

		if(help) findZero[i] = 1;
	}

	checkTask(userElements, findZero, m, n);
}


void checkTask(float matrix[1000][1000], float zeroInfo[100], int len, int collumn)
{
	float result = 0.0;

	for (int i = 0; i < len; ++i)
	{
		result += zeroInfo[i];
	}

	if(result == 0) printf("\n%s\n", "Все строки матрицы содержат нулевые элементы");
	else 
	{
		printf("\n%s\n", "Матрица не содержит нулевые элементы в каждой строке");
		modificateMatrix(matrix, len, collumn);
	}
}


void modificateMatrix(float matrix[1000][1000], int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(matrix[i][j] < 0)
			{
				matrix[i][j] = fabs(matrix[i][j]);
			}
		}
	}

	printf("\n%s", "-Измененная матрица");
	viewMatrix(matrix, m, n);
}