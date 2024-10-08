#include <stdio.h>

enum {SIZE = 12};

int main() 
{
	int array[SIZE];
	for(int i = 4; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	for(int i = 0; i < 4; i++)
	{
		scanf("%d", &array[i]);
	}
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
