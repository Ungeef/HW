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

void BubbleSort(int* array, int Start, int Count, _Bool increase)
{
	int noSwap;
	int temp;
    for (int i = Start; i < Start + Count; i++)
    {
        noSwap = 1;
        if(increase == 1)
		{
			for (int j = Start + Count - 1; j > i; j--)
        	{
				if(array[j-1] > array[j])
            	{
                	temp = array[j-1];
                	array[j-1] = array[j];
                	array[j] = temp;
                	noSwap = 0;
            	}
        	}
		}
		else
		{
			for (int j = Start + Count - 1; j > i; j--)
        	{
				if(array[j-1] < array[j])
            	{
                	temp = array[j-1];
                	array[j-1] = array[j];
                	array[j] = temp;
                	noSwap = 0;
            	}
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
	
	BubbleSort(array, 0, 5, 1);
	BubbleSort(array, 5, 5, 0);

	Print(array, SIZE);
	
	
	return 0;
}
