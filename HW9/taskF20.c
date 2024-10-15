#include <stdio.h>

enum {SIZE = 10};

void even_odd(int a[], int n)
{
	int even = 0;
	int mult = 1;
	int is_even_more = 0;
	for(int i = 0; i < n; i++)
		if(a[i] % 2 == 0)
			even++;
	if(even > n/2)
		is_even_more++;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == is_even_more)
		{
			while(a[i] > 0)
			{
				if(((a[i] % 10) % 2) == is_even_more)
					mult *= a[i] % 10;
				a[i] /= 10;
			}
			a[i] = mult;
			mult = 1;
		}
	}
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
	Scan(array, SIZE);
	even_odd(array, SIZE);
	print(array, SIZE);
return 0;
}
