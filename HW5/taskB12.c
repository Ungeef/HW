#include <stdio.h>

int main(void)
{
    int a;
    int min = 9, max = 0;
    scanf("%d", &a);
    for(; a != 0; a/=10)
    {
        if(a%10 < min)
        {
            min = a%10;
        }
        if(a%10 > max)
        {
            max = a%10;
        }
    }
    printf("%d %d", min, max);
    
    return 0;
}