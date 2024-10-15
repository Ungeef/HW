#include <stdio.h>

enum {SIZE = 30};

void sum_min(int size, int a[])
{
	int min = a[0];
	int indx_min = 0;
	int sec_min = a[1];
	int indx_sec_min = 1;
	if(min > sec_min)
	{
		min = a[1];
		indx_min = 1;
		sec_min = a[0];
		indx_sec_min = 0;
	}
	for(int i = 2; i < size; i++)
	{
		if(a[i] < min)
		{
			sec_min = min;
			indx_sec_min = indx_min;
			min = a[i];
			indx_min = i;
		}
		else 
			if(a[i] < sec_min)
			{
				sec_min = a[i];
				indx_sec_min = i;
			}
	}
	if(indx_min > indx_sec_min)
	{
		int temp = indx_min;
		indx_min = indx_sec_min;
		indx_sec_min = temp;
	}
	printf("%d %d", indx_min, indx_sec_min);
}

void Scan(int array[], int n)
{
	char c;
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		if((c = getchar()) == '\n')
			break;
	}
}


int main(void)
{	
	int array[SIZE];
	Scan(array, SIZE);
	sum_min(SIZE, array);
	return 0;
}