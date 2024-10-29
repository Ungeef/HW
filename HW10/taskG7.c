#include <stdio.h>
#include <string.h>
 
#define line_width 10001
 
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


fp = fopen("input.txt", "r");
while(fscanf(fp, "%[^\n]", line) == 1);
fclose(fp);	


if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	

int big = 0;
int small = 0;
for (int i = 0; i < strlen(line); i++)
{
	if(line[i] >= 65 && line[i] <= 90)
		big++;
	if(line[i] >= 97 && line[i] <= 122)
		small++;
}
fprintf(fp, "%d %d", small, big);
fclose(fp); 	
return 0;
}
