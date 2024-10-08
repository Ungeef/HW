#include <stdio.h>

enum {SIZE = 10};

void Scan(int *array, int n)
{
    for(int i = 0; i < n; i++)
	    scanf("%d", &array[i]);
}

void Print(int *array, int n)
{
    for(int i = 0; i < n; i++)
		printf("%d ", array[i]);
}

void BubbleSort(int* array, int n)
{
	int noSwap;
	int temp;
    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = 9; j > i; j--)
        {
			if(array[j-1] % 10 > array[j] % 10)
            {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

 
int main() 
{
	int array[SIZE];
    Scan(array, SIZE);
	BubbleSort(array, SIZE);
    Print(array, SIZE);
	return 0;
}
