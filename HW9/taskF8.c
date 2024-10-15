#include <stdio.h>

enum {SIZE = 1000};

int find_max_array(int size, int a[])
{
	int max = a[0];
	for(int i = 1; i < size; i++)
		if(max < a[i])
			max = a[i];
	return max;
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
		if(array[i] == 0)
			break;
	}
	return i + 1;
}

int main(void)
{	
	int array[SIZE];
	int real_size = Scan(array, SIZE);
	int max = find_max_array(real_size, array);
	printf("%d", miss_dig(real_size, array, max));
return 0;     
}
