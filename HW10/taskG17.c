#include <stdio.h>
#include <string.h>
 
#define SIZE 1001
 
void input(char *strIn, int *space)
{
FILE *in;
in = fopen("input.txt", "r");
int count = 0;
char c;
int i = 1;
while(((c = getc(in)) != EOF) && (c != '\n'))
{
	if(c == ' ')
	{
		space[count+1]++;
		i = 2;
	}
	else
		strIn[count++] = c;
}
strIn[count] = '\0';
space[0] = i-1;
fclose(in);
}
 
void reverse(char *strExt)
{
int count = 0;
char temp;
int lenght = strlen(strExt);
if(lenght % 2 == 1)
	lenght--;
for(int i =  1; i < lenght; i+=2)
{
	temp = strExt[i];
	strExt[i] = strExt[i-1];
	strExt[i-1] = temp;
}
}

void output(char *strOut, int *space)
{  
FILE *out;
out = fopen("output.txt", "w");
int count_space = 0;
if(space[0] != 0)
{
	for(int i = 0; i < strlen(strOut); i++)
	{
	
		{
			if(space[i+1] > 0)
				for(int j = 0; j < space[i+1]; j++)
					fprintf(out, " ");
		}
		fprintf(out, "%c", strOut[i]);
	}
}
else
	fprintf(out, "%s", strOut);

fclose(out);
}
 
int main(int argc, char **argv)
{
char str[SIZE]={0}; 
int space[SIZE]={0};
input(str, space);
reverse(str);
output(str, space);
return 0;
}
