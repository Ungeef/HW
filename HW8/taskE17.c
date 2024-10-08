#include <stdio.h>
 
enum {SIZE = 10};
 
void Input(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
 
void one_time(int array[], int n)
{
	_Bool flag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(array[i] == array[j] && i != j)
				flag = 0;
		}
		if(flag == 1)
			printf("%d ", array[i]);
		flag = 1;
			
	}
}

int main() 
{
int array[SIZE];
Input(array, SIZE);
one_time(array, SIZE);
return 0;
}
