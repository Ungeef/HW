#include <stdio.h>

int bin_count_one(int n)
{
	if (n > 0)
		return (n % 2 == 1) ? 1 + bin_count_one(n/2) :  bin_count_one(n/2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", bin_count_one(n));
	return 0;
}
