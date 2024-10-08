#include <stdio.h>
 
void Print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d",arr[i]);
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
	int array[n];
	len = n;
	for(;n >= 0; n--)
	{
		array[n-1] = dig1 % 10;
		dig1/=10;
	}
	int noSwap;
	for(int i = 0; i < len; i++)
	{
		int temp;
		noSwap = 1;
		for(int j = len-1; j > i; j--)
		{
			if(array[j-1] < array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                noSwap = 0;
            }
		}
		if(noSwap)
            break;
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
