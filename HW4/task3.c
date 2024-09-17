#include <stdio.h>

int main(void)
{	
	int a, max;
	scanf("%d", &a);
	max = a%10;
	if (max < (a/10)%10) 
		max = (a/10)%10;
	if (max < a/100) 
		max = a/100;
	printf("%d", max);
return 0;
}
