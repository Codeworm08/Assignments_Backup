#include<stdio.h>
#include<math.h>
int fact(int x)
{
    int f=1;
    for(int i=1;i<=x;i++)
        f*=i;
    return f;
}
double cosine(double x,double sum,double t,int i,int n)
{
    if(i<=n)
    {
        sum+=t;
        t*=-1*x*x/(double)((2*i+2)*(2*i+1));
        cosine(x,sum,t,++i,n);
    }
    else
        return sum;
}
int main()
{
    double rad,cos;
    int n;
    printf("\nNo of terms: ");
    scanf("%d",&n);
    printf("\nEnter angle in radians: ");
    scanf("%lf",&rad);
    cos=cosine(rad,0,1.0f,0,n);
    printf("\ncos(%.3lf): %.3lf",rad,cos);
    return 0;
}