#include <stdio.h>

enum {SIZE = 5};

int main(void)
{	
	int array[SIZE];
	float arith = 0;
	for(int i = 0; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
		arith += array[i];
	}
		printf("%.3f", arith/SIZE);
return 0;
}
