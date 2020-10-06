#include <stdio.h>

int main(void)
{
	float a, b, c;

	printf("%s", "Введите длины сторон треугольника a, b, c: ");
	scanf("%f %f %f", &a, &b, &c);

	if(a==b && b==c)
	{
		printf("%s\n", "Треугольник равносторонний");
	}

	else
	{
		printf("%s\n", "Треугольник не равносторонний");
	}

	return 0;
}