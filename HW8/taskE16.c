#include <stdio.h>
 
enum {SIZE = 10};
 
void Input(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
 
void often(int array[], int n)
{
	int count = 0;
	int last_count = 0;
	int dig = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if(array[i] == array[j])
			count++;
		}
		if(count > last_count)
		{
			last_count = count;
			dig = array[i];
		}
		count = 0;
	}
	printf("%d", dig);
	
}

int main() 
{
int array[SIZE];
Input(array, SIZE);
often(array, SIZE);
return 0;
}
