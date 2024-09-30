#include <stdio.h>

void reverse(int n)
{
	if(n > 0)
	{
		printf("%d ", n % 10 );
		if(n/10 == 0)
		{
			return 0;
		}
		reverse(n/10);
	}
	if(n == 0)
		printf("0");
}

int main()
{
	int n;
	scanf("%d",&n);
	reverse(n);
	return 0;
}
