#include <stdio.h>
 
int is_brack_correct(char a)
{
	static int excess = 0;
	if(a == '(')
		excess++;
	else 
		excess--;
		
	if(excess < 0)	//Если excess стал отрицательным 
		excess = -2; //Он навсегда останется отрицательным
	if(excess != 0)
		return 0;
    return 1;
}
 
int main()
{
char input;
int ans;
    while (1)
    {
        scanf("%c", &input);
    if (input == '.')
        break;
    ans = is_brack_correct(input);
    }
    ans ? printf("YES") : printf("NO");


    return 0;
}
