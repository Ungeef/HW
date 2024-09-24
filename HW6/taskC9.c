#include <stdio.h>
#include <inttypes.h>


uint64_t factorial(int n)
{
	uint64_t factr = 1;
	for(int i = 1; i <= n; i++)
	{
		factr *= i;
	}
	return factr;
}




int main(void)
{	
	int a;
	scanf("%d", &a);
	printf("%" PRIu64, factorial(a));
	return 0;
}
