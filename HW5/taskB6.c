#include <stdio.h>

int main(void)
{
    int a;
    _Bool check_doubl = 0;
    
    scanf("%d", &a);
    for(; a != 0; a/=10)
    {
        if(a%10 == (a/10)%10)
        {
            check_doubl = 1;
            break;
        }
    }
    if(check_doubl)
        printf("YES");
    else 
        printf("NO");
    return 0;
}