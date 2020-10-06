#include <stdio.h>
#include <stdlib.h>
#define N 3

void getUserNumbers(void);
void sortUserNumbers(float arr[]);
void endResult(float arr[]);

int main(void)
{
	getUserNumbers();

	return 0;
}

void getUserNumbers(void)
{
	float numbers[N];
	float x;

	printf("%s\n", "Введите числа a, b, c:");

	for (int i = 0; i < N; i++)
	{
		scanf("%f", &x);
		numbers[i] = x;
	}

	sortUserNumbers(numbers);
}

void sortUserNumbers(float arr[])
{
	float helpVar;
	int noSwap;

	for (int i = N-1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				helpVar = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = helpVar;
				noSwap = 0;
			}
		}

		if(noSwap == 1)
		{
			break;
		} 
	}

	endResult(arr);
}

void endResult(float arr[])
{
	if((arr[2]-arr[1]) == (arr[1]-arr[0]))
	{
		printf("%s\n", "Из этих чисел можно образовать арифметическую прогрессию");
	}

	else
	{
		printf("%s\n", "Из этих чисел нельзя образовать арифметическую прогрессию");
	}
}