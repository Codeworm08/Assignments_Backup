#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int factorization(int a, int b)
{
    int gcd=1,i,x=2,m;
    if(a==0 && b==0)
        return -1;
    printf("\nPrime Factors:\n");
    if(a==0)
        return b;
    if(b==0)
        return a;
    m=(a<b)? a:b;
    while (x<sqrt(m))
    {
        while(a%x==0 && b%x==0)
        {
            a/=x;
            b/=x;
            gcd*=x;
            printf("\n%4d | %d, %d |",x,a,b);
        }        
        x++;
    }
    return gcd;
}
int euclid(int a, int b)
{
    int r;
    if(a==0 && b==0)
        return -1;
    printf("\nRemainders: ");
    while(b>0)
    {
        r = a % b;
        a=b;
        b=r;
        printf("%d ",a);
    }
    return a;
}
int main()
{
    int x,y,gcdf,gcde;
    printf("\nEnter the 2 numbers: ");
    scanf("%d%d",&x,&y);
    gcdf = factorization(x,y);
    gcde = euclid(x,y);
    if(gcdf==gcde && gcdf==-1)
    {
        printf("\nFactorisation: Infinity");
        printf("\nEuclid: Infinity");
        exit(1);
    }
    printf("\nGCD with factorization: %d",gcdf);
    printf("\nGCD with euclid: %d",gcde);
    return 0;
}