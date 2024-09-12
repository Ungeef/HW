#include <stdio.h>

int main(void)
{
    int a, mul;
    scanf("%d",&a);

    mul = a%10;
    mul *= (a/10)%10;
    mul *= (a/100)%10;

    printf("%d", mul);
    return 0;
}