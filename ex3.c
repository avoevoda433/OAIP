#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Russian");
    char *months[] = {"Январь", 
                      "Февраль",
                      "Март",
                      "Апрель",
                      "Май",
                      "Июнь",
                      "Июль",
                      "Август",
                      "Сентябрь",
                      "Октябрь",
                      "Ноябрь",
                      "Декабрь"};

    int numbersOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char userMonth[20];

    printf("Введите название месяца (Пример: Май): ");
    scanf("%s", userMonth);

    for (int i = 0; i < 12; i++)
    {
        if(strcmp(months[i], userMonth) == 0)
        {
            printf("Количество дней в месяце - %d\n", numbersOfDays[i]);
        }
    }
    
    
    return 0;
}
