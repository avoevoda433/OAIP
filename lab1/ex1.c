#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main(void)
{
	setlocale(LC_ALL, "Russian");
	double x;

	printf("%s", "Введите число x: ");
	scanf("%lf", &x);

	x *= 128;
	printf("%s %g\n", "Результат:", x);

	return 0;
}