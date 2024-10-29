#include <stdio.h>
 
#define line_width 1001
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
int is_char_one[128] = {0};
char c;
FILE *fp;


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}


int count = 0;
while(((c = getc(fp)) != EOF) && (c != '\n'))
{
	if(is_char_one[c] == 0 && c != ' ')
	{
		line[count++] = c;
		is_char_one[c] = 1;
	}
}
line[count] = '\0'; 
fclose(fp);	

if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	

for (int i = 0; i < count; i++)
{ 	
		fprintf(fp, "%c", line[i]);
}
	fclose(fp); 	
	return 0;
}
