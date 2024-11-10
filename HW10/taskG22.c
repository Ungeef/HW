#include <stdio.h>
#include <string.h>
 
#define SIZE 21
 
void input(char *strIn)
{
FILE *in;
in = fopen("input.txt", "r");
while(fscanf(in, "%[^\n]", strIn) == 1);
fclose(in);
}
 
void Soundex(char *str, char *str_temp)
{
	str_temp[0] = str[0];
	int count = 1;
	for(int i = 1; i < strlen(str); i++)
	{
		if (strchr("aehiouswy ", str[i]) == NULL)
			str_temp[count++] = str[i];
	}
	for(int i = 1; i < strlen(str_temp); i++)
	{
		switch(str_temp[i])
		{
			case'b': case'f': case'p': case'v':
				str_temp[i] = '1';
				break;
			case'c': case'g': case'j': case'q': case's': case'x': case'z':
				str_temp[i] = '2';
				break;
			case'd': case't':
				str_temp[i] = '3';
				break;
			case'l': 
				str_temp[i] = '4';
				break;
			case'm': case'n':
				str_temp[i] = '5';
				break;
			case'r':
				str_temp[i] = '6';
				break;
		}
	}
	int temp = 0;
	int last;
	for(int i = 2; i < strlen(str_temp)+1; i++)
	{
		while(str_temp[i-1] == str_temp[i])
		{
			temp++;
			i++;
		}
		if(str_temp[i-1] >= '0' && str_temp[i-1] <= '9' )
		{
			str[i-1-temp] = str_temp[i-1];
			last = i - 1 - temp;
		}

	}
	for(int i = last+1; i < 4; i++)
		str[i] = '0';
	str[4] = 0;
}
void output(char *strOut)
{  
FILE *out;
out = fopen("output.txt", "w");
fprintf(out, "%s", strOut);
fclose(out);
}
 
int main(int argc, char **argv)
{
char str[SIZE]={0}, str_temp[SIZE]={0};
input(str);
Soundex(str, str_temp);
output(str);
return 0;
}
