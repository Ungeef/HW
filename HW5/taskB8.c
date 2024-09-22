#include <stdio.h>

int main(void)
{
    int a;
    int check_nine = 0;
    
    scanf("%d", &a);
    for(; a != 0; a/=10)
    {
        if(a%10 == 9)
        {
            check_nine++;
        }
    }
    if(check_nine == 1)
        printf("YES");
    else 
        printf("NO");
    return 0;
}