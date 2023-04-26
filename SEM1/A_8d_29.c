#include<stdio.h>
int fact(int x)
{
	int i,fac=1;
	for(i=1;i<=x;i++)
		fac=fac*i;
	return fac;
}
double e(int n)
{
	int i;
	double result=0;
	for(i=1;i<=n;i++)
		result+=(1/(float)fact(i-1));
	return result;
}
int main()
{
    double result;
    int n;
    printf("\nEnter value of n(up to 10): ");
	scanf("%d",&n);
	result=e(n);
	printf("\ne= %.5lf",result);
    return 0;
}