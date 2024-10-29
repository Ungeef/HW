#include <stdio.h>
#include <string.h>
 
#define line_width 101

 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char name[line_width];
char surname[line_width];
FILE *fp;


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}

fscanf (fp, "%s", &surname);
fscanf (fp, "%s", &name);
fclose(fp);	

if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 
fprintf(fp, "Hello, %s %s!", name, surname);

fclose(fp); 	
return 0;
}
