#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef long int li; 
int fact(int x)
{
	int i,fac=1;
	for(i=1;i<=x;i++)
		fac=fac*i;
	return fac;
}
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
double olog(double x)
{
	int i;
	double result=0;
	for(i=1;i<=100;i++)
		result+=((pow(-1,i+1)*pow(x,i))/i);
	return result;
}
double e(int n)
{
	int i;
	double result=0;
	for(i=1;i<=n;i++)
		result+=(1/(float)fact(i-1));
	return result;
}
li next(li a)
{
	li i=a+1;
	int f=1;
	while (1)
	{
		f=1;
		for (li j = 2; j < i; j++)
		{
			if(i%j==0)
				f=0;
		}
		if(f==1)
			return i;
		i++;
	}
	
}
double prim(int n)
{
	li result=0,a=2,b=3;
	for (int i = 1; i <= n; i++)
	{
		result += a*b;
		a=b;
		b=next(b);
	}
	return result;
}
int main()
{
	int choice,n;
	double result,x;
	while(1)
	{
		printf("\nEnter 1 for sinx.\n2 for cosx.\n3 for log(1+x)(-1<x<=1)");
		printf("\n4 for e= 1/1! + 2/2! + 3/3! + ... +(up to 10 terms)");
		printf("\n5 for 2*3 + 3*5 +5*7 + ... +(up to n terms, n user input)");
		printf("\nEnter any other number to exit.");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter x(radians): ");
			scanf("%lf",&x);
			result=sin(x);
			printf("\nsin(%lf) = %lf",x,result);
			break;
		case 2:
			printf("\nEnter x(radians): ");
			scanf("%lf",&x);
    		result=cos(x);
			printf("\ncos(%lf) = %lf",x,result);
			break;
		case 3:
			printf("\nEnter x in -1<x<=1: ");
			scanf("%lf",&x);
			result=olog(x);
			printf("\nlog(1 + %lf)= %lf",x,result);
			break;
		case 4:
			printf("\nEnter value of n(up to 10): ");
			scanf("%d",&n);
			result=e(n);
			printf("\ne= %lf",result);
			break;
		case 5:
			li sum;
			printf("\nEnter value of n: ");
			scanf("%d",&n);
			sum=prim(n);
			printf("\nOutput= %ld",sum);
			break;
		default:
			exit(1);
		}
	}
		
	return 0;
}

