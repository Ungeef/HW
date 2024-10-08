#include <stdio.h>

enum {SIZE = 10};

int main() 
{
	int array[SIZE];
	for(int i = 1; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
	}
	scanf("%d", &array[0]);
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
