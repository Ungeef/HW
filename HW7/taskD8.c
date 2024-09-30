#include <stdio.h>

void print_num(int a, int b)
{
	if(a == b)
		printf("%d ", a );

		
	if(a < b)
	{
		printf("%d ", a );
		print_num(++a, b);
	}
	else if(a > b)
	{
		printf("%d ", a );
		print_num(--a, b);
	}
	
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	print_num(a, b);
	return 0;
}
