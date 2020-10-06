#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a, b;
	int choise = -1;

	printf("%s\n", "Введите два числа a, b:");
	scanf("%f %f", &a, &b);

	printf("%s%s%s%s%s", "\nВыберите операцию:\n",
							 "(1) Сумма\n",
							 "(2) Разность\n",
							 "(3) Произведение\n",
						 	 "(4) Частное\n");

	scanf("%d", &choise);
	switch(choise)
	{
		case 1:	
			printf("\n%g\n", a+b);
			break;
		case 2:	
			printf("\n%g\n", a-b);
			break;
		case 3:	
			printf("\n%g\n", a*b);
			break;
		case 4:	
			printf("\n%g\n", a/b);
			break;
		}

	return 0;
}