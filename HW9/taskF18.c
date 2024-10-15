#include <stdio.h>

enum {SIZE = 10};

int sum_max(int a[][SIZE], int n)
{
	int sum = 0;
	int max;
	for(int i = 0; i < n; i++)
	{
		max = a[i][0];
		for(int j = 1; j < n; j++)
		{
			if(a[i][j] > max)
				max = a[i][j];
		}
		sum += max;
	}
	return sum;
}

int Scan(int array[][SIZE], int n)
{
	char c;
	int i;
	for(i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	return SIZE*SIZE;
}


int main(void)
{	
	int array[SIZE][SIZE];
	int count = Scan(array, SIZE);
	printf("%d", sum_max(array, SIZE));
return 0;
}
