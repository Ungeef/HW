#include <stdio.h>
 
#define line_width 202
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
char c;
FILE *fp;
int arr_char[26] = {0};
int arr_exam[26] = {0};


if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}


int count = 1;
while(((c = getc(fp)) != ' '))
{
	if(c > 122)
	{
		perror("Error wrong data in input file!");
		return 1;	
	}
	arr_char[c-97]++;
	if(arr_exam[c-97] == 0)
	{
		arr_exam[c-97] = count;
		count++;
	}
}
while(((c = getc(fp)) != EOF) && (c != '\n'))
{
	if(c > 122)
	{
		perror("Error wrong data in input file!");
		return 1;	
	}
	arr_char[c-97]-=100;
	if(arr_exam[c-97] == 0)
	{
		arr_exam[c-97] = count;
		count++;
	}
}
fclose(fp);	


if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	


for (int i = 1; i < count; i++)
{
	for (int j = 0; j < 26; j++)
		if(arr_exam[j] == i && arr_char[j] == -99)
			fprintf(fp, "%c ", (char)(j+97));
}
	fclose(fp); 	
	return 0;
}
