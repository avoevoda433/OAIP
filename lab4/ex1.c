#include <stdio.h>

int getListLenght(void);
void getUserListNumber(int arr[]);
void sortUserListNumbers(int arr[], int len);
void deleteMaxMinNumber(int arr[], int len);
void getResult(int arr[], int len);

int main(void)
{
	int userListNumbers[1000];

	getUserListNumber(userListNumbers);

	return 0;
}


int getListLenght(void)
{
	int lenght;

	printf("%s\n", "Введите число элементов массива: ");
	scanf("%d", &lenght);

	return lenght;
}


void getUserListNumber(int arr[])
{
	int userNumber, len;
	len = getListLenght();

	printf("%s\n", "Введите различные элементы массива:");

	for (int i = 0; i < len; ++i)
	{
		scanf("%d", &userNumber);
		arr[i] = userNumber;
	}

	sortUserListNumbers(arr, len);
}


void sortUserListNumbers(int arr[], int len)
{
	int helpVar;
	int noSwap;

	for (int i = len-1; i >= 0; i--)
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

	deleteMaxMinNumber(arr, len);
}


void deleteMaxMinNumber(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		if(i < len-2) arr[i] = arr[i+1];
		else arr[i] = 0;
	}

	getResult(arr, len);
}


void getResult(int arr[], int len)
{
	printf("%s\n", "Массив чисел без минимального и максимального элемента");
	printf("[ ");
	for (int i = 0; i < len; ++i)
	{
		if(arr[i] != 0) printf("%d ", arr[i]);
	}
	printf("]\n");
}