#include <stdio.h>

enum {SIZE = 5};

int arif(int a[][SIZE], int n)
{
	int arif = 0;
	for(int i = 0; i < n; i++)
		arif += a[i][i];
	arif/=5;
	return arif;
}

int Bigger_than(int a[][SIZE], int n, int dig)
{
	int bigger = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] > dig)
				bigger++;
	return bigger;
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
	int dig = arif(array, SIZE);
	printf("%d", Bigger_than(array, SIZE, dig));
	return 0;
}
