#include <stdio.h>
#include <string.h>
 
#define line_width 1001
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
FILE *fp;


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}



fp = fopen("input.txt", "r");
while(fscanf(fp, "%[^\n]", line) == 1);
fclose(fp);	


if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	

int lenght = strlen(line) - 1;
for (int i = 0; i < lenght; i++)
{
	if(line[i] == line[lenght])  	
		fprintf(fp, "%d ", i);
}
	fclose(fp); 	
	return 0;
}
