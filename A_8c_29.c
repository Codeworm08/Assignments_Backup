#include<stdio.h>
#include<math.h>
double olog(double x)
{
	int i;
	double result=0;
	for(i=1;i<=100;i++)
		result+=((pow(-1,i+1)*pow(x,i))/i);
	return result;
}
int main()
{
    double result,x;
    printf("\nEnter x in -1<x<=1: ");
	scanf("%lf",&x);
	result=olog(x);
	printf("\nlog(1 + %lf)= %lf",x,result);
    return 0;
}