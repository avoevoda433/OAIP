#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main(void)
{
	setlocale(LC_ALL, "Russian");
	double x, y, z, a, b, c, s;

	printf("%s", "Введите число x: ");
	scanf("%lf", &x);

	printf("%s", "Введите число y: ");
	scanf("%lf", &y);

	printf("%s", "Введите число z: ");
	scanf("%lf", &z);

	a = exp(fabs(x-y))*pow(fabs(x-y), x+y);
	b = atan(x)+atan(z);
	c = cbrt(pow(x, 6)+pow(log(y), 2));

	s = a/b+c;
	printf("\n%s%g\n", "Результат выражения S: ", s);

	return 0;
}