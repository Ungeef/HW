#include <stdio.h>
 
#define line_width 1001
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char c;
FILE *fp;


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}


int number_word_a = 0;
char last_char;
while(((c = getc(fp)) != EOF) && (c != '\n'))
{
	if(last_char == 'a' && c == ' ')
		number_word_a++;
	last_char = c;
}
if(last_char == 'a')
		number_word_a++;
fclose(fp);	


if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	

	fprintf(fp, "%d", number_word_a);

	fclose(fp); 	
	return 0;
}
