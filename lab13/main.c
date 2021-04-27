#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int arrSize; // размер сортируемого массива
int *arr = 0; // указатель на сортируемый массив
int *sortArr = 0; // указатель на отсортированный массив

int negaticveArrSize = 0; // размер подмассива отрицательных элементов 
int zeroArrSize = 0; // размер подмассива нулевых элементов
int positiveArrSize = 0; // размер подмассива положительных элементов

int *negativeElements = 0; // указатель на подмассив отрицательных элементов
int *zeroElements = 0; // указатель на подмассив нулевых элементов
int *positiveElements = 0; // указатель на подмассив положительных элементов


/* Функция позволяет пользователю указать размер массива и заполнить его значениями */
void createUserArr()
{
    do{
        printf("Введите число элементов массива: ");
        scanf("%d", &arrSize);
    } while (arrSize <= 0);

    arr = (int*)malloc(sizeof(int)*arrSize); // выделение памяти для массива

    for (int i = 0; i < arrSize; i++)
    {
        printf("Введите целочисленный элемент %d массива: ", i+1);
        scanf("%d", arr+i);
    }
}


/* Функция разделяет элементы массива на отрицательные, положительные и нулевые */
void separateArrElements()
{
    for (int i = 0; i < arrSize; i++)
    {
        if (*(arr+i) > 0) 
        {
            ++positiveArrSize;
            positiveElements = (int*)realloc(positiveElements, sizeof(int)*positiveArrSize);
            *(positiveElements+positiveArrSize-1) = *(arr+i);
        }

        else if (*(arr+i) < 0)
        {
            ++negaticveArrSize;
            negativeElements = (int*)realloc(negativeElements, sizeof(int)*negaticveArrSize);
            *(negativeElements+negaticveArrSize-1) = *(arr+i);
        }

        else
        {
            ++zeroArrSize;
            zeroElements = (int*)realloc(zeroElements, sizeof(int)*zeroArrSize);
            *(zeroElements+zeroArrSize-1) = *(arr+i);
        }
    }
}


/* Функция выводит массив в консоль */
void showArr(int n, int* array)
{
    printf("массив: ");
    for (int i = 0; i < n; i++)
        printf("%d%s", *(array+i), (i==n-1) ? "\n" : " ");
}


/* Сортировка по возрастанию */
void sortMin(int n, int* array)
{
    int minElement;
    int indexMinElement;
    int separate = 0;

    for (int i = 0; i < n; i++)
    {
        minElement = *(array+i);
        for (int j = i; j < n; j++)
            if (*(array+j) < minElement)
            {
                minElement = *(array+j);
                indexMinElement = j;
                separate = 1;
            }
        if (separate) *(array+i) = *(array+i) + *(array+indexMinElement) - (*(array+indexMinElement) = *(array+i));
    }
}


/* Сортировка по убыванию */
void sortMax(int n, int* array)
{
    int maxElement;
    int indexMaxElement;
    int separate = 0;

    for (int i = 0; i < n; i++)
    {
        maxElement = *(array+i);
        for (int j = i; j < n; j++)
            if (*(array+j) < maxElement)
            {
                maxElement = *(array+j);
                indexMaxElement = j;
                separate = 1;
            }
        if (separate) *(array+i) = *(array+i) + *(array+indexMaxElement) - (*(array+indexMaxElement) = *(array+i));
    }
}


/* Создание отсортированного массива */
void createNewSortArr()
{
    sortArr = (int*)malloc(sizeof(int)*arrSize);

    for (int i = 0; i < negaticveArrSize; i++)
        *(sortArr+i) = *(negativeElements+i);
    
    for (int i = 0; i < positiveArrSize; i++)
        *(sortArr+i+negaticveArrSize) = *(positiveElements+i);

    for (int i = 0; i < zeroArrSize; i++)
        *(sortArr+i+negaticveArrSize+positiveArrSize) = *(zeroElements+i);
}


int main(void)
{
    createUserArr();
    printf("\nНесортированный ");
    showArr(arrSize, arr);
    separateArrElements();

    sortMin(negaticveArrSize, negativeElements);
    sortMax(positiveArrSize, positiveElements);

    createNewSortArr();
    printf("\nОтсортированный ");
    showArr(arrSize, sortArr);

    return 0;
}