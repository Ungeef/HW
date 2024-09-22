#include <stdio.h>

int main(void)
{
    int a;
    int sum = 0;
    scanf("%d", &a);
    
    for(; a != 0; a/=10)
        {
            sum += a%10; 
        }

        if(sum == 10)
            printf("YES");
        else
            printf("NO");
    
    return 0;
}