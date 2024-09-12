#include <stdio.h>

int main(void)
{
    int a, b, c;
    float arith;
    scanf("%d%d%d",&a ,&b, &c);
    arith = (float)(a+b+c)/3;
    printf("%.2f", arith);
    return 0;
}