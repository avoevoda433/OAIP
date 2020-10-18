#include <stdio.h>
#include <math.h>

void getDigit(int findNumber, int digit[]);
int getDigitSum(int digit[]);
int getReverseNumber(int digit[]);

int main(void)
{
	int digitNumber[3];

	for(int i = 400; i <= 500; i++)
	{
		getDigit(i, digitNumber);
		if(getDigitSum(digitNumber) == 9 && i == (getReverseNumber(digitNumber)*47/36))
		{
			printf("%s %d\n", "Это число", i);
		}
	}

	return 0;
}

void getDigit(int findNumber, int digit[])
{
	for (int i = 3; i > 0; i--)
	{
		digit[i-1] = findNumber/pow(10, i-1);
		findNumber -= digit[i-1]*pow(10, i-1);
	}
}

int getDigitSum(int digit[])
{
	int digitSum = 0;

	for (int i = 0; i < 3; ++i)
	{
		digitSum += digit[i];
	}

	return digitSum;
}

int getReverseNumber(int digit[])
{
	int reverseNumber = 0;
	int j = 2;

	for (int i = 0; i < 3; ++i)
	{
		reverseNumber += digit[i]*pow(10, j);
		j--;
	}

	return reverseNumber;
}