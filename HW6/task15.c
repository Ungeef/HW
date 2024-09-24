#include <stdio.h>
 
int grow_up(int n)
{
	if(n/10 == 0)
		return 1;
	do
	{
		if((n / 10) % 10 >= n % 10)
			return 0;
		n /= 10;
	} 
	while((n / 10) != 0);
	
	return 1; 
}
 
int main()
{
	int n;
	scanf("%d", &n);
	grow_up(n) ? printf("YES") : printf("NO");
	return 0;
}
