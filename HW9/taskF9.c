#include <stdio.h>

enum {SIZE = 200};

void swap_negmax_last(int size, int a[])
{
	int max = 0;
	int indx = 0;
	_Bool first_neg = 1;
	for(int i = 0; i < size; i++)
		if(a[i] < 0 && (first_neg || max < a[i]))
		{
			max = a[i];
			indx = i;
			first_neg = 0;
		}
	if(first_neg == 1)
		return;
	a[indx] = a[size-1];
	a[size-1] = max;
}

int Scan(int array[], int n)
{
	char c;
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		if((c = getchar()) == '\n')
			break;
	}
	return i + 1;
}

void print(int array[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}


int main(void)
{	
	int array[SIZE];
	int count = Scan(array, SIZE);
	swap_negmax_last(count, array);
	print(array, count);
	return 0;
}
