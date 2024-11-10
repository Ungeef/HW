#include <stdio.h>
#include <string.h>
 
#define SIZE 1001
 
void input(char *strIn)
{
FILE *in;
in = fopen("input.txt", "r");
while(fscanf(in, "%[^\n]", strIn) == 1);
fclose(in);
}
 
void is_palindrom(char *strExt)
{
	int alphabet[27]={0};
	int count_odd = 0;
	int count_space = 0;
	for(int i = 0; i < strlen(strExt); i++)
	{
		if(strExt[i] != ' ')
			alphabet[strExt[i] - 97]++;
		else
			count_space++;
	}
	for(int i = 0; i < 26; i++)
	{
		if(alphabet[i] % 2 == 1)
			count_odd++;
	}
	switch(count_odd)
	{
		case 0:
			printf("YES");
			break;
		case 1:
			if((strlen(strExt) - count_space) % 2 == 1)
				printf("YES");
			else
				printf("NO");
			break;
		default:
			printf("NO");
			break;
	}
	
}
 
int main(int argc, char **argv)
{
char str[SIZE]={0};
input(str);
is_palindrom(str);
return 0;
}
