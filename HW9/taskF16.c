#include <stdio.h>

enum {SIZE = 8};

void which_color(char letter, int dig)
{
	if(!((int)letter%2 == 0) != !(dig%2 == 0))
		printf("WHITE");
	else
		printf("BLACK");
}

int main(void)
{	
	char letter;
	int dig;
	scanf("%c", &letter);
	scanf("%d", &dig);
	which_color(letter, dig);
	return 0;
}
