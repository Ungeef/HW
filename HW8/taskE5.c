#include <stdio.h>
 
enum {SIZE = 10};

int main() 
{
	int array[SIZE];
	int sum_pos = 0;
	for(int i = 0; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
		if(array[i] > 0)
			sum_pos += array[i];
	}
	printf("%d", sum_pos);
}
