#include <stdio.h>

void setMatrixConfig(float matrix[1000][1000]);
void inputMatrixElements(int rows, float userElements[1000][1000]);
void viewMatrix(float matrix[1000][1000], int n);
void findZeroRow(float matrix[1000][1000], int n);


int main(void)
{
	float matrixValues[1000][1000];
	setMatrixConfig(matrixValues);

	return 0;
}


void setMatrixConfig(float matrix[1000][1000])
{
	int rows;
	
	printf("%s", "Введите размер квадратной матрицы: ");
	scanf("%d", &rows);

	inputMatrixElements(rows, matrix);
}


void inputMatrixElements(int rows, float userElements[1000][1000])
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
	findZeroRow(userElements, rows);
}


void viewMatrix(float matrix[1000][1000], int n)
{
	for(int i = 0; i < 71; i++) printf("-%s", (i == 0 || i == 70 ? "\n" : ""));
	for (int i = 0; i < n; ++i)
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


void findZeroRow(float matrix[1000][1000], int n)
{
	int rowSum;
	int check;

	for (int i = 0; i < n; ++i)
	{
		rowSum = 0;

		for (int j = 0; j < n; ++j)
		{
			rowSum += matrix[i][j];
		}

		if(rowSum == 0)
		{
			for (int k = 0; k < n; ++k) matrix[k][i] /= 2;
			check = 0;
			break;
		}
		else check = 1;
	}

	if(check == 1) printf("%s\n", "Матрица не имеет нулевых строк");
	else
	{
		printf("%s\n", "Матрица после преобразования");
		viewMatrix(matrix, n);
	}
}