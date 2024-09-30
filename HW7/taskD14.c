#include <stdio.h>

void is_odd()
{
	int n;
	scanf("%d", &n);
	if (n != 0)
	{
		if(n % 2 != 0)
		printf("%d ", n);
		is_odd();
	}
}
	
int main()
{
	is_odd();
	return 0;
}