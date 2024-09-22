#include <stdio.h>

int main(void)
{
    int a;
    int check_even = 1;
    
    scanf("%d", &a);
    for(; a != 0; a/=10)
    {
        if(a%2 == 1)
        {
            check_even = 0;
            break;
        }
    }
    if(check_even == 1)
        printf("YES");
    else 
        printf("NO");
    return 0;
}