#include <stdio.h>

void setMatrixConfig(int matrix[1000][1000]);
void inputMatrixElements(int rows, int userElements[1000][1000]);
void viewMatrix(int matrix[1000][1000], int n);
void rowsPower(int matrix[1000][1000], int n);
void diagonalSum(int matrix[1000][1000], int n);
int sortElements(int arr[100], int n);


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


int sortElements(int arr[100], int n)
{
	int j;

	for (int i = 0; i < 2*n-2; ++i)
	{
		j = i;
		for (int k = i; k < 2*n-2; ++k)
		{
			if (arr[j] < arr[k]) j = k;
		}

		arr[i] = arr[i] + arr[j] - (arr[j] = arr[i]);
	}

	return arr[0];
}


void diagonalSum(int matrix[1000][1000], int n)
{
	int upValue[n-1];
	int downValue[n-1];
	int values[100];
	int p, j;
	int d = n-2;

	for (int i = 0; i < n-1; ++i)
	{
		upValue[i] = 0;
		downValue[i] = 0;
	}

	for (int i = 0; i < n-1; ++i)
	{
		j = 0;
		p = n-(i+1);

		while (p != 0)
		{
			upValue[i] += matrix[j][n-p];
			downValue[i] += matrix[n-p][j];

			j++;
			p--;
		}
	}

	for (int i = 0; i < n-1; ++i)
	{
		values[i] = upValue[i];
		values[n+i] = downValue[i];
	}

	printf("Наибольшая сумма элементов диагонали, параллельной главной: %d\n", sortElements(values, n));

}
