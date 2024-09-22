#include <stdio.h>

int main(void)
{
    int a;
    
    scanf("%d", &a);
    if(a/100 != 0 && a/1000 == 0)
        printf("YES");
    else 
        printf("NO");
    return 0;
}