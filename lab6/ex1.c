#include <stdio.h>
#include <malloc.h>

int getArrLenght();
void getArrElements(int*);
void positiveElements(int*, int);
void sumElements(int*, int);


int main(void)
{
	int *num;
	getArrElements(num);
	return 0;
}


int getArrLenght()
{
	int lenght;
	printf("%s\n", "Введите число элементов массива: ");
	scanf("%d", &lenght);
	return lenght;
}


void getArrElements(int *arr)
{
	int n = getArrLenght();
	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		printf("Введите %d элемент массива\n", i+1);
		scanf("%d", (arr + i));
	}

	positiveElements(arr, n);
	sumElements(arr, n);
}


void positiveElements(int *arr, int n)
{
	int positiveCount = 0;
	for (int i = 0; i < n; ++i)
	{
		if(*(arr+i) > 0) positiveCount++;
	}

	printf("Количество положительных элементов массива равно %d\n", positiveCount);
}


void sumElements(int *arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += *(arr+i);
		if(sum == sum - *(arr+i)) sum = 0;
	}

	printf("Сумма элементов массива, стоящих после последнего нуля, равна %d\n", sum);
}