#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define NAME_ELEMENTS 3
#define ADRESS_ELEMENTS 2
#define NAME_ELEMENTS_LENGTH 40
#define ADRESS_LENGTH 40
#define PHONE_LENGTH 15

void inputInfo(void);
int save(char*);
int printInfo(char*);
int findInfo(char*);

typedef struct buyer
{
	char name[NAME_ELEMENTS][NAME_ELEMENTS_LENGTH];
	char address[ADRESS_ELEMENTS][ADRESS_LENGTH];
	long int cardNumber;
	char phoneNumber[PHONE_LENGTH];

} buyType;

buyType *clients = NULL;
int clientsCount = 0;


void printFindInfo(int, buyType*);


int main(void)
{
	char *filename = "struct.bin";

	int userChoise;
	do
	{
		printf("\n%s\n%s\n%s\n%s\n%s\n\n", "(1) Ввод массива структур",
									       "(2) Поиск массива структур",
									       "(3) Просмотр массива структур",
									       "(4) Запись структуры в бинарный файл",
									       "(0) Выход");
		scanf("%d", &userChoise);

		switch(userChoise)
		{
			case 1:
				inputInfo();
				break;

			case 2:
				findInfo(filename);
				break;

			case 3:
				printInfo(filename);
				break;

			case 4:
				save(filename);
				break;

			case 0:
				userChoise = 0;
				break;

			default: 
				main();
		}

	} while (userChoise != 0);

	return 0;
}


void inputInfo(void)
{
	clients = (buyType*)realloc(clients, sizeof(buyType)*(clientsCount+1));

	printf("%s\n", "Введите ФИО:");
	scanf("%s%s%s", (clients+clientsCount)->name[0],
					  (clients+clientsCount)->name[1],
					  (clients+clientsCount)->name[2]);

	printf("%s\n", "Введите адрес (Улица, дом/квартира):");
	scanf("%s%s", (clients+clientsCount)->address[0],
				  (clients+clientsCount)->address[1],
						 

	printf("%s\n", "Введите номер телефона:");
	scanf("%s", (clients+clientsCount)->phoneNumber);

	printf("%s\n", "Введите номер банковской карты:");
	scanf("%ld", &(clients+clientsCount)->cardNumber);

	clientsCount++;
}


int save(char *filename)
{
    FILE *structFile;
    char *c;
    int size = clientsCount * sizeof(buyType);
 
    if ((structFile = fopen(filename, "w")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    
    c = (char*)&clientsCount;
    for (int i = 0; i < sizeof(int); i++)
    {
        putc(*c++, structFile);
    }

    c = (char *)clients;
    for (int i = 0; i < size; i++)
    {
        putc(*c, structFile);
        c++;
    }

    fclose(structFile);
    printf("Структура записана в бинарный файл\n");
    return 0;
}


void printFindInfo(int k, buyType *info)
{
	 printf("\nФИО: %s %s %s \nАдрес: %s %s \nНомер телефона: %s \nНомер карты: %ld\n\n", (info + k)->name[0],
        					 															  (info + k)->name[1], 
        					 													    	  (info + k)->name[2],
        																				  (info + k)->address[0],
        																				  (info + k)->address[1],
        					 															  (info + k)->phoneNumber,
        					 															  (info + k)->cardNumber);
}


int printInfo(char *filename)
{
    FILE * structFile;
    char *c;
    int m = sizeof(int);
    int n, l;
 
    int *saveStruct = (int*)malloc(m);
 
    if ((structFile = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }

    c = (char *)saveStruct;
    while (m > 0)
    {
        l = getc(structFile);
        if (l == EOF) break;
        *c = l;
        c++;
        m--;
    }
   
    n = *saveStruct;
 
    buyType *info = (buyType*)malloc(n*sizeof(buyType));
    c = (char *)info;
  
    while ((l= getc(structFile))!=EOF)
    {
        *c = l;
        c++;
    }
 
    for (int k = 0; k < n; k++)
    {
    	printFindInfo(k, info);
    }
 
    free(saveStruct);
    free(info);
    fclose(structFile);
    return 0;
}


int findInfo(char *filename)
{
    FILE *structFile;
    char *c;
    int m = sizeof(int);
    int n, l;
 
    int *saveStruct = (int*)malloc(m);
 
    if ((structFile = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }

    c = (char *)saveStruct;
    while (m > 0)
    {
        l = getc(structFile);
        if (l == EOF) break;
        *c = l;
        c++;
        m--;
    }
   
    n = *saveStruct;
 
    buyType *info = (buyType*)malloc(n*sizeof(buyType));
    c = (char *)info;
  
    while ((l= getc(structFile))!=EOF)
    {
        *c = l;
        c++;
    }

    int choise;
	int helpCount = 0;
	int check = 1;
	char findName[NAME_ELEMENTS][NAME_ELEMENTS_LENGTH] = {};
	char findAddress[ADRESS_ELEMENTS][ADRESS_LENGTH] = {};
	char findPhone[PHONE_LENGTH] = {};
	long int findCard;

	printf("Выберете параметр поиска:\n%s\n%s\n%s\n%s\n\n", "(1) ФИО",
															"(2) Адрес",
														   	"(3) Номер телефона",
															"(4) Номер карты");
	scanf("%d", &choise);
	switch(choise)
	{

		case 1:

			printf("Введите ФИО:\n");

			for (int i = 0; i < NAME_ELEMENTS; ++i)
			{
				scanf("%s", findName[i]);
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < NAME_ELEMENTS; ++j)
				{
					if (strcmp((info+i)->name[j], findName[j]) == 0) helpCount++;
				}

				if(helpCount == NAME_ELEMENTS) 
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					helpCount = 0;
					check = 0;
				}

				helpCount = 0;
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 2:

			printf("Введите адрес:\n");
			for (int i = 0; i < ADRESS_ELEMENTS; ++i)
			{
				scanf("%s", findAddress[i]);
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < ADRESS_ELEMENTS; ++j)
				{
					if (strcmp((info+i)->address[j], findAddress[j]) == 0) helpCount++;
				}

				if(helpCount == ADRESS_ELEMENTS) 
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					helpCount = 0;
					check = 0;
				}

				helpCount = 0;
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 3:

			printf("Введите номер телефона:\n");
			scanf("%s", findPhone);

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < PHONE_LENGTH; ++j)
				{
					if (strcmp((info+i)->phoneNumber, findPhone) == 0) helpCount++;
				}

				if(helpCount == PHONE_LENGTH) 
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					helpCount = 0;
					check = 0;
				}

				helpCount = 0;
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 4:

			printf("Введите номер карты:\n");
			scanf("%ld", &findCard);

			for (int i = 0; i < n; ++i)
			{
				if ((info+i)->cardNumber == findCard)
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					check = 0;
				}
			}

			if (check) printf("Информация не найдена\n");

			break;

		default:
			findInfo(filename);
	}
 
    free(saveStruct);
    free(info);
    fclose(structFile);
    return 0;
}