#include <stdio.h>

int main(void)
{
    int a;
    int even = 0, odd = 0;
    scanf("%d", &a);
    
    for(; a != 0; a/=10)
    {
        if(a%2 == 0)
            even++;
        else
            odd++;
    }
    printf("%d %d", even, odd);
    
    return 0;
}