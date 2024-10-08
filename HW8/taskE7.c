#include <stdio.h>
 
enum {SIZE = 10};

int main() 
{
	int array[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		if(i < 5)
			scanf("%d", &array[4-i]);
		else
			scanf("%d", &array[14-i]);
	}
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
