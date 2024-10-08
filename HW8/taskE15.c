#include <stdio.h>
 
enum {SIZE = 10};
 
void Print(int *arr)
{
    for (int i = 0; arr[i] != 0 && i < 10; i++)
        printf("%d ",arr[i]);
}
 
void Input(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
 
void separation(int array[], int pos[], int neg[])
{
	int len_pos = 0;
	int len_neg = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if(array[i] > 0)
		{
			pos[len_pos] = array[i];
			len_pos++;
		}
		else if(array[i] < 0)
		{
			neg[len_neg] = array[i];
			len_neg++;
		}
	}
}

int main() 
{
int array[SIZE];
int pos[SIZE] = {0};
int neg[SIZE] = {0};

Input(array, SIZE);
separation(array, pos, neg);
Print(pos);
Print(neg);  
return 0;
}
