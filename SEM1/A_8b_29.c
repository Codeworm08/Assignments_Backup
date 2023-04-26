#include<stdio.h>
double cos(double x)
{
	double s=0,t=1;int i;
	for(i=0;i<150;i++)
	{
		s+=t;
		t*=-1*x*x/((2*i+2)*(2*i+1));
	}
	return s;
}
int main()
{
    double x,result;
    printf("\nEnter x(radians): ");
	scanf("%lf",&x);
    result=cos(x);
	printf("\ncos(%lf) = %lf",x,result);
    return 0;
}