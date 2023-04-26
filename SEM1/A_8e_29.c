#include<stdio.h>
typedef long int li;
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
    int n;
    li sum;
	printf("\nEnter value of n: ");
	scanf("%d",&n);
	sum=prim(n);
	printf("\nOutput= %ld",sum);
    return 0;
}