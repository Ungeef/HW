#include <stdio.h>
 
void Print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);
} 


void sep_dig(int dig)
{
	int dig1 = dig;
	int n = 0;
	int len;
	while(dig > 0)
	{
		n++;
		dig/=10;
	}
	int array[n-1];
	len = n;
	for(;n-1 >= 0; n--)
	{
		array[n-1] = dig1 % 10;
		dig1/=10;
	}	
	Print(array, len);
}


 

int main() 
{
	int digital;
	scanf("%d", &digital);
	sep_dig(digital);
	return 0;
}
