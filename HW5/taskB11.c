#include <stdio.h>

int main(void)
{
    int a;
    int b = 0;
    scanf("%d", &a);

    for(; a != 0; a/=10)
    {
        b = b*10 + (a%10);
    }
    printf("%d", b);
    
    return 0;
}