#include<stdio.h>
double sin(double x)
{
	double s=0,t=x;int i;
	for (i=0;i<600;i++)
	{
		s+=t;
		t*=-1*x*x/((2*i+3)*(2*i+2));
	}
	return s;
}
int main()
{
    double x, result;
    printf("\nEnter x(radians): ");
	scanf("%lf",&x);
	result=sin(x);
	printf("\nsin(%lf) = %lf",x,result);
    return 0;
}