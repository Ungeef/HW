#include <stdio.h>

int main(void)
{
    int a;
    int sum, mult;
    scanf("%d", &a);
    
    for(int i = 10; i <= a; i++)
    {
        sum = 0;
        mult = 1;
        for(int dig = i; dig != 0; dig/=10)
        {
            sum += dig%10; 
        }
        for(int dig = i; dig != 0; dig/=10)
        {
            mult *= dig%10; 
        }
        if(sum == mult)
            printf("%d ", i);
    }
    
    
    return 0;
}