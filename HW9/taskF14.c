#include <stdio.h>

enum {SIZE = 200};

int sum_between_ab(int from, int to, int size, int a[])
{
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		if(a[i] >= from && a[i] <= to || a[i] <= from && a[i] >= to)
			sum+=a[i];
	}
	return sum;
}

int Scan(int array[], int n)
{
	char c;
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
		if((c = getchar()) == '\n')
			break;
	}
	return i + 1;
}


int main(void)
{	
	int array[SIZE];
	int from;
	int to;
	scanf("%d", &from);
	scanf("%d", &to);
	int count = Scan(array, SIZE);
	printf("%d", sum_between_ab(from, to, count, array));
	return 0;
}
