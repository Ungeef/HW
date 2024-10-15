#include <stdio.h>

enum {SIZE = 20};

void sort_even_odd(int n, int a[])
{
	int karetka = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			if(karetka != i)
			{
				int temp = a[i];	
				for(int j = i; j > karetka; j--)
				{
					a[j] = a[j-1];
				}
				a[karetka] = temp;
			}
			karetka++;
		}
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
	sort_even_odd(count, array);
	print(array, count);
	return 0;
}
