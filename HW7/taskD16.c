#include <stdio.h>

int is2pow(int n)
{
	static int flag = 0;
	flag++;
	if(n == 1 && flag == 1)
	{
		printf("YES");
		return 0;
	}
	if(n == 2)
		printf("YES");
	else
		(n % 2 == 0) ? is2pow(n/2) : printf("NO");
}

int main()
{
	int n;
	scanf("%d", &n);
	is2pow(n);
	return 0;
}
