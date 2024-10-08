#include <stdio.h>
 
enum {SIZE = 16};
 
void Input(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

 
void krat(int array[], int digital)
{
	for (int i = 1; i < 9; i++)
	{
		array[2*i-2] = i+1;
		
		for(int j = 2; j <= digital; j++)
		{	
			if( i != 0 && j % (i+1) == 0)
				array[2*i-1]++;
		}
		printf("%d ", array[2*i-2]);
		printf("%d\n", array[2*i-1]);
	}
}

int main() 
{
int array[16] = {0};
int digital;
scanf("%d", &digital);
krat(array, digital);
return 0;
}
