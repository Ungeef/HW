#include <stdio.h>
 
#define line_width 1001
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
char c;
FILE *fp;


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}


int count = 0;
int lenght = 0;
int lenght_max = 0;
int indx_start = 0;
while(((c = getc(fp)) != EOF) && (c != '\n'))
{
	line[count++] = c;
	lenght++;
	while(((c = getc(fp)) != EOF) && (c != '\n') && (c != ' '))
	{
		line[count++] = c;
		lenght++;
	}
	if(lenght_max < lenght)
	{
		lenght_max = lenght;
		indx_start = count - lenght_max;
	}
	lenght = 0;
}
line[count] = '\0'; 
fclose(fp);	


if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	


for (int i = indx_start; lenght_max > 0; i++, lenght_max--)
{ 	
	fprintf(fp, "%c", line[i]);
}
	fclose(fp); 	
	return 0;
}
