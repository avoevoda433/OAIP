#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

#define FILE_COUNT 3

int sortElements(int*, int);


int main()
{
    int k = 0;
    int s;
    int **arr = NULL;

	FILE *firstFile, *secondFile, *thirdFile, *newFile;

	firstFile = fopen("NameA.txt","r");
	secondFile = fopen("NameB.txt","r");
	thirdFile = fopen("NameC.txt","r");
	newFile = freopen("NameD.txt", "w", stdout);
	 
	while ((fscanf(firstFile, "%d",&s)!=EOF))
	{    
		if(!firstFile) break;  
	    k += 1;
	}

	arr = (int**)malloc(k*sizeof(int*));
	for (int i = 0; i < k; ++i)
	{
		arr[i] = (int*)malloc(FILE_COUNT*sizeof(int));
	}
	 
	 
	rewind(firstFile);   

	for(int i = 0; i < k ; i++)
	{
	    fscanf(firstFile, "%d",(arr[i]+0));
	    fscanf(secondFile, "%d",(arr[i]+1));
	    fscanf(thirdFile, "%d",(arr[i]+2));
	}

	fclose(firstFile);
	fclose(secondFile);
	fclose(thirdFile);

    for (int i = 0; i < k; ++i)
    {
    	printf("%d ", sortElements(arr[i], FILE_COUNT));
    }
	
	return 0;
}


int sortElements(int *arr, int n)
{
	int j;

	for (int i = 0; i < 2*n-2; ++i)
	{
		j = i;

		for (int k = i; k < 2*n-2; ++k)
		{
			if (*(arr+j) < *(arr+k)) j = k;
		}

		*(arr+i) = *(arr+i) + *(arr+j) - (*(arr+j) = *(arr+i));
	}

	return arr[0];
}