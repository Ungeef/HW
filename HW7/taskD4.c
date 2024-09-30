#include <stdio.h>

void print_num(int n)
{
	static int flag = 0;
	if(n > 0)
	{
		flag++;
		print_num(n/10);
		printf("%d ", n % 10 );
	}
	if(n == 0 && flag == 0)
		printf("0");
}

int main()
{
	int n;
	scanf("%d",&n);
	print_num(n);
	return 0;
}
