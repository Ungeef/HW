#include <stdio.h>

enum {SIZE = 200};

void print(int array[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}

int find_max_array(int size, int a[])
{
	int max = a[0];
	for(int i = 1; i < size; i++)
		if(max < a[i])
			max = a[i];
	return max;
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
	printf("%d", find_max_array(real_size, array));
	return 0;
}
