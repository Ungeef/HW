#include <stdio.h>
#include <string.h>
 
#define line_width 1001

 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
FILE *fp;
const char html_str[6] = ".html"; 


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}

fscanf (fp, "%[^\n]", &line);
 
fclose(fp);	
if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 

if(strstr(line, html_str))
	fprintf(fp, "%s", line);
else
{
	_Bool is_dot_exist = 0;
	for(int lenght = strlen(line); line[lenght] != '/'; lenght--)
	{
		if(line[lenght] == '.')
			is_dot_exist = 1;
	}
	if(is_dot_exist)
	{
		int pos = strrchr(line, '.') - line;
		line[pos] = 0;
	}
	strcat(line, html_str);
	fprintf(fp, "%s", line);
}

fclose(fp); 	
return 0;
}
