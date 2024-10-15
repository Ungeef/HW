#include <stdio.h>

enum {SIZE = 200};

int is_two_same(int size, int a[])
{
	int flag = 0;;
	for(int i = 0; i < size-1; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if(a[i] == a[j])
			{
				return 1;
			}
				
		}
	}
	return 0;
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
	printf("%d", is_two_same(real_size, array));
	return 0;
}
