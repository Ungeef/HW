#include <stdio.h>
 
int main() 
{
	int n = 0;
	int array[10];
	int second_0[10];
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", &array[i]);
	}

	for(int i = 0; i < 10; i++)
	{
		if((array[i] / 10) % 10 == 0)
		{
			second_0[n] = array[i];
			printf("%d ", second_0[n]);
			n++;
		}
	}
	return 0;
}
