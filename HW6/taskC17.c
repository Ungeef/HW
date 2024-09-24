#include <stdio.h>

 
int is_happy_number(int n)
{
	int sum = 0;
	int mult = 1;
	
	for(int i = 0; n > 0; n /= 10)
	{
		sum += n % 10;
		mult *= n % 10;
	}
	
	if(sum == mult)
		return 1;
	return 0;
    
        
}
 
int main()
{
	int n;
    scanf("%d", &n);
    is_happy_number(n) ? printf("YES") : printf("NO");
    return 0;
}
