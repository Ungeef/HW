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

void del_extra_space(char *strExt)
{
	int del = 0;
	_Bool flag = 0;
	int lenght = strlen(strExt);
	for(int i = 0; i < lenght; i++)
	{
		while(strExt[i] == ' ' && !flag)
		{
			del++;
			i++;
		}
		flag = 1;
		while(strExt[i] == ' ' && strExt[i+1] == ' ' && strExt[i+1] != 0)
		{
			del++;
			i++;
		}
		strExt[i-del] = strExt[i];
	}
	strExt[lenght-del]  = 0;
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
char str[SIZE]={0}; 
int space[SIZE]={0};
input(str);
del_extra_space(str);
output(str);
return 0;
}
