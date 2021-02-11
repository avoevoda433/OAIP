#include <stdio.h>
#include <stdlib.h>


/* Функция GetFile используется для открытия файла.
   Первым аргументом функция получает название файла fname;
   Вторым аргументом - параметр params, от которого зависит
   будет ли файл открыт для записи ("w") или для чтения ("r"). */
FILE* GetFile(const char* fname, const char* params)
{
    FILE* f = fopen(fname, params);

    /* проверка открытия файла */
    if (f == NULL)
    {
        perror(fname); // вывод имя файла перед сообщением ошибки
        exit(EXIT_FAILURE); // вывод сообщения ошибки
    }
}


/* Функция  GetCountDigits возвращает размерность не расширенной
    матрицы, содержащейся в файле f. */
int GetMatrixSize(FILE* f) 
{
    int count = 0; // количество элементов расширеной матрицы
    float number;
    int matrixSize;
 
    /* чтение количества элементов расширенной матрицы */
    rewind(f);
    while (fscanf(f, "%f", &number) == 1) 
        count++;

    /* проверка на наличие элементов в файле */
    if (count == 0)
    {
        printf("Файл пуст\n");
        exit(EXIT_FAILURE);
    } 
 
    /* размер расширенной матрицы имеет вид Nx(N+1),
       поэтому если кол-во элементов 12, ищем ближайший
       целый корень числа, меньше 12, в данном случае это 3.
       Значит размер матрицы 3х4. По данному алгоритму преобразуем
       количество элементов в размерность матрицы. */
    for (int i = 0; i*i-count < 0; i++)
        matrixSize = i;
    
    return matrixSize;
}


/* Функция  GetMatrixNumbers создает и заполняет матрицу размером (rows)x(columns) 
элементами из файла f */
float** GetMatrixNumbers(FILE* f, int rows, int columns)
{
    float number;
    float **matrix = 0; // указатель на матрицу

    /* выделение памяти */
    matrix = (float**)malloc(rows*sizeof(float*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (float*)malloc(columns*sizeof(float));
    
    /* чтение и запись элементов из файла в матрицу */
    rewind(f);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            fscanf(f, "%f", &number);
            matrix[i][j] = number;
        }
    
    return matrix;
}


/* Функция для сортировки строк матрицы, строка с наибольшим 
    первым элементом будет первой */
void SortRows(float **matrix, int rows, int columns)
{
    for (int iteration = rows-1; iteration != 0; iteration--) 
        for (int i = 0; i < rows-1; i++)
            if (matrix[i][0] < matrix[i+1][0])
            {
                for (int j = 0; j < columns; j++)
                    matrix[i][j] = matrix[i][j] + matrix[i+1][j] - (matrix[i+1][j] = matrix[i][j]);
            }
}


/* Функция для нормализации строк матрицы */
void NormalizeMatrix(float **matrix, int rows, int columns, int start)
{
    for (int i = start; i < rows; i++)
    {
        float mainElement = matrix[i][start]; // первый элемент строки
        for (int j = start; j < columns; j++)
            matrix[i][j] = matrix[i][j] / mainElement; // делим все последующие элементы строки на первый элемент
    }
}


/* Функция для вычитания верхней строки матрицы из последующих строк */
void RowsSubtract(float **matrix, int rows, int columns, int start)
{
    for (int i = start+1; i < rows; i++)
        for (int j = start; j < columns; j++)
            matrix[i][j] -= matrix[start][j];
}


/* Функция для получения массива найденных неизвестных */
float* GetResult(float **matrix, int rows)
{
    /* Создаем массив и заполняем его нулевыми значениями */
    float *result = (float*)malloc(rows*sizeof(float));
    for (int i = 0; i < rows; i++)
        result[i] = 0;

    /* Находим результат неизвестной, которую можно получить из последней строки матрицы */
    if (matrix[rows-1][rows-1] != 0)
        result[rows-1] = matrix[rows-1][rows] / matrix[rows-1][rows-1];
    
    else 
    {
        printf("Система не совместна\n");
        exit(EXIT_FAILURE);
    }

    /* Находим все остальные переменные */
    for (int i = rows-2; i >= 0; i--)
    {
        for (int j = 0; j < rows; j++)
            matrix[i][rows] -= matrix[i][j]*result[j];

        result[i] = matrix[i][rows];
    }

    return result;
}


/* Функция для записи результата в файл */
void WriteResult(FILE* f, char *fileName, float *result, int rows)
{
    f = fopen(fileName, "aw");
    for (int i = 0; i < rows; i++)
        fprintf(f, "%sx%d = %1.2f\n", (i == 0 ? "\n\nРезультат:\n" :""), i+1, result[i]);
    
    fclose(f);
    printf("Программа выполнена успешно\nРезультат записан в файл\n");
}


int main(int argc, char* argv[])
{
    char fileName[1024];
    printf("Введите путь к файлу: ");
    scanf("%s", fileName);

    /* устанавливаем значение файлу */
    FILE* f = GetFile(fileName, "r");

    /* получаем количество строк и стобцов */
    int rows = GetMatrixSize(f);
    int columns = rows + 1;

    /* создаем и присваиваем значение матрице */
    float **matrix = GetMatrixNumbers(f, rows, columns);
    
    /* выполняем преобразования над матрицей согласно методу Гаусса */
    SortRows(matrix, rows, columns);
    for (int i = 0; i < rows-1; i++)
    {
        NormalizeMatrix(matrix, rows, columns, i);
        RowsSubtract(matrix, rows, columns, i);
    }

    /* создаем массив найденных переменных и записываем его в файл */
    float *result = GetResult(matrix, rows);
    WriteResult(f, fileName, result, rows);

    return 0;
}
