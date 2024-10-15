#include <stdio.h>

enum {SIZE = 1000};

int count_bigger_abs(int n, int a[])
{
	int bigger = 0;
	int max = a[0];
	for(int i = 1; i < n; i++)
		if(max < a[i])
			max = a[i];
	for(int i = 0; i < n; i++)
	{
		if(-1 * a[i] > max)
			bigger++;
	}
	return bigger;
}

int miss_dig(int size, int a[], int max)
{
	int exist = 0;
	for(int i = max - 1; i > max - size + 1; i--)
	{
		for(int j = 0; j < size; j++)
		{
			if(a[j] == i)
			{
				exist = 1;
				break;
			}
		}
		if(exist == 0)
			return i;
		exist = 0;
	}
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

int main(void)
{	
	int array[SIZE];
	int real_size = Scan(array, SIZE);
	printf("%d", count_bigger_abs(real_size, array));
	return 0;
}
