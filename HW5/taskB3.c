#include <stdio.h>

int main(void)
{
    int a, b;
    int sum = 0;
    
    scanf("%d%d", &a, &b);
    for(; a <= b; a++)
    {
        sum +=a*a; 
    }

    printf("%d ", sum);
    return 0;
}