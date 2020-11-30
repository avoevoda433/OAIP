#include <stdio.h>
#include <locale.h>

int findCharInString(char[102], char);


int main(void)
{
	setlocale(LC_ALL, "Russian");

	char userString[102] = {};
	char userChar;

	printf("%s\n", "Введите строку на латинице не более 100 символов: ");
	fgets(userString, sizeof(userString), stdin);

	printf("%s\n", "Введите символ на латинице: ");
	userChar = getchar();

	printf("Символ %c повторяется %d раз(а)\n", userChar, findCharInString(userString, userChar));

	return 0;
}


int findCharInString(char string[102], char sumbol)
{
	int count = 0;
	for (int i = 0; i < (sizeof(char)*102/sizeof(char)); ++i)
	{
		if ((int)string[i] == (int)sumbol)
		{
			count++;
		}
	}

	return count;
}