#include <stdio.h>

int akkerman(int n, int m)
{
	if(n == 0)
		return m + 1;
	else if(m == 0)
			return akkerman(--n, 1);
	akkerman(--n, akkerman(n, --m));
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", akkerman(n, m));
	return 0;
}
