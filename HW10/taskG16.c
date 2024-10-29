#include <stdio.h>
#include <string.h>
 
#define line_width 1001
 
void input(char *line)
{
FILE *fp;
fp = fopen("input.txt", "r");
while(fscanf(fp, "%[^\n]", line) == 1);
fclose(fp);
}
 
void changeName(char *line, char *Final_line)
{
int count = 0;
	for(int i =  0; i < strlen(line); i++)
	{  
		if(!memcmp(line+i,"Ling",4))
		{
			strcat(Final_line, "Cao");
			count += 3;
			i += 4;
		}
		Final_line[count++] = line[i];
	}
}
void output(char *line)
{  
FILE *fp;
fp = fopen("output.txt", "w");
fprintf(fp, "%s", line);
fclose(fp);
}
 
int main(int argc, char **argv)
{
	char line[line_width]={0}, Final_line[line_width]={0};
	input(line);
	changeName(line, Final_line);
	output(Final_line);
	return 0;
}
