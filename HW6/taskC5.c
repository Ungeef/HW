#include <stdio.h>


int sum(int N)
{
	int sum = 0;
	for(int i = 0; i <= N; i++)
	{
		sum += i;
	}
	return sum;
}




int main(void)
{	
	int a;
	scanf("%d", &a);
	printf("%d ", sum(a));
	return 0;
}
