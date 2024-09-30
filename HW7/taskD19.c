#include <stdio.h>

int acounter()
{
	char n;
	scanf("%c", &n);
	static int count = 0;
	
	if (n != '.')
	{
		if(n == 'a')
			return 1 + acounter();
		else
			return acounter();
	}
	else 
		return 0;
}
	
int main()
{
	printf("%d", acounter());
	return 0;
}