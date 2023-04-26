#include<stdio.h>
int gcd(int a, int b)
{
    if(a==0&&b==0)
        return -1;
    if(b==0)
        return a;
    gcd(b,a%b);
}
int main()
{
    int a,b,gc;
    printf("\nEnter 2 nos for gcd: ");
    scanf("%d%d",&a,&b);
    gc=gcd(a,b);
    if(gc==-1)
        printf("\nInfinity!");
    else
    {
        printf("\nGCD: %d",gc);
    }
    return 0;
}