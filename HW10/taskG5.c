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


for (int i = 0; i < strlen(line); i++)
{
	if(line[i] == 'a' || line[i] == 'A')  	
		fprintf(fp, "%c", line[i]+1);
	else if(line[i] == 'b' || line[i] == 'B')
			fprintf(fp, "%c", line[i]-1);
	else
		fprintf(fp, "%c", line[i]);
}
fclose(fp); 	
return 0;
}