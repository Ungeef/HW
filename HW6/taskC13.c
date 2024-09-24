#include <stdio.h>
#include <math.h>

const float PI = 3.1415926;

double cosinus(float x)
{
	const float EPS = 0.001;
	double Xn = 1;
	double cosn = 1;
	
	for(int i = 1; fabs(Xn) > EPS ; i++)
	{
		
		Xn *= -1.0 * x * x / ((2 * i) * (2 * i - 1));
		cosn += Xn;
		
	}
	
	return cosn;
}




int main(void)
{	
	double x;
    scanf("%lf",&x);
    x *= PI/180.0;
	printf("%.3f", cosinus(x));
	return 0;
}
