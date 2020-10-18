#include <stdio.h>
#include <math.h>

int main(void)
{
	float a;

	printf("%s\n", "Введите число a: ");
	scanf("%f", &a);

	while(1)
	{
		a = pow(a, 2) + 1;

		if(a > pow(10, 6))
		{
			printf("%f\n", a);
			break;
		}
	}

	return 0;
}