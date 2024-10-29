#include <stdio.h>
 
#define line_width 1001
 
void BubbleSort(int* array, int n)
{
	int noSwap;
	int temp;
	for (int i = 0; i < n; i++)
	{
		noSwap = 1;
		for (int j = n-1; j > i; j--)
	{
	if(array[j-1] > array[j])
	{
		temp = array[j-1];
		array[j-1] = array[j];
		array[j] = temp;
		noSwap = 0;
	}
        }
	if(noSwap)
		break;
    }
}


int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
int digit_in_line[line_width-1];
char c;
FILE *fp;

if((fp = fopen(input_fn, "r")) == NULL)
{
	perror("Error occured while opening input file!");
	return 1;
}

int temp = 0;
int temp_count = 0;
int count = 0;
while(((c = getc(fp)) != EOF) && (c != '\n'))
{
	if(c >= 48 && c <= 57)
	{
		temp = c-48;
		while(((c = getc(fp)) != EOF) && (c != '\n') && (c >= 48 && c <= 57))
		{
			temp = temp*10 + c-48;
		}
		digit_in_line[temp_count++] = temp;
	}
	
}
line[count] = '\0'; 
fclose(fp);	

if((fp = fopen(output_fn, "w")) == NULL)
{
	perror("Error occured while opening output file!");
	return 1;
} 	

BubbleSort(digit_in_line, temp_count);

for (int i = 0; i < temp_count; i++)
{	
	fprintf(fp, "%d ", digit_in_line[i]);
}
	fclose(fp); 	
	return 0;
}
