#include <stdio.h>
 
enum {SIZE = 12};

int main() 
{
	int array[SIZE];
	float arith = 0;
	for(int i = 0; i < SIZE; i++)
	{
		scanf("%d", &array[i]);
			arith += array[i];
	}
	if(arith != 0)
		printf("%.2f", arith/SIZE);
	else 
		printf("%.2f", arith);
}
