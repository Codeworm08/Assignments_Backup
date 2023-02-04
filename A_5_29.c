#include<stdio.h>
float power(double x, int a)
{
    int i=0;
    double result,obase=x;int og=a;
    if(x==0.0 || x==1.0 || x==-1.0)
        return x;
    if(a<0)
        a=-a;
    if(obase<0)
        x = -x;
    result=x;
    for(i=1;i<a;i++)
    {
        result *= x;
        
    }
    if(obase<0 && a%2!=0)
        result = -result;
    if(og<0)
        result = 1/result; 
    return result;
}
int main()
{
    double base,result;
    int pow;
    printf("\nEnter base: ");
    scanf("%lf",&base);
    printf("\nEnter power: ");
    scanf("%d",&pow);
    if(base==0.0 && pow<=0)
        printf("\nundefined\n");
    else
    {
        result=power(base, pow);
        printf("\n Result= %lf\n",result);
    }
    return 0;
}