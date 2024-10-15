#include <stdio.h>

enum {SIZE = 5};

int sled_matrix(int a[][SIZE], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i][i];
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
	printf("%d", sled_matrix(array, SIZE));
	return 0;
}
