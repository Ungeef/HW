#include <stdio.h>
#include <inttypes.h>


uint64_t counter(int N)
{
	uint64_t count = 1;
	for(int i = 1; i < N; i++)
	{
		count *= 2;
	}
	return (uint64_t)count;
}




int main(void)
{	
	int a;
	scanf("%d", &a);
	printf("%" PRIu64, counter(a));
	return 0;
}
