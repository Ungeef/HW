#include <stdio.h>

enum {SIZE = 2000};


void print_digit(char s[])
{
		int r[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int i=0; s[i] != '\0'; i++)
		{
			if (s[i] >= '0' && s[i] <= '9') 
				r[s[i] - '0']++;
		}
		for(int i = 0; i < 10; i++)
			if(r[i] != 0)
				printf("%d %d ", i, r[i]);
}


void print(int array[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}


int main(void)
{	
	char c;
	char array[SIZE];
	int i = 0;
	while( (c=getchar())!='\n' )
		array[i++]=c;
	array[i++] = '\0';
	print_digit(array);
	return 0;
}
