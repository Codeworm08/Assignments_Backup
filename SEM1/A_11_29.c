#include<stdio.h>
#include<math.h>
typedef long double ld;

ld fib_formula(int n)
{
    ld a,b,c,fib;
    a=1+pow(5,0.5);
    b=1-pow(5,0.5);
    // a=a/2;
    // b=b/2;
    c=1/pow(5,0.5);
    fib = c*((pow(a,n)-pow(b,n))/pow(2,n));
    return fib;   
}
ld fib_manual(int n)
{
    ld a=0, b=1, c;
    int i;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    for(i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}
int main()
{
    int n;
    ld actual,formula,diff;
    printf("\nInput: ");
    scanf("%d",&n);
    actual=fib_manual(n);
    formula=fib_formula(n);
    printf("\nActual Output: %0.0Lf",actual);
    printf("\nFormula Output: %0.0Lf",formula);
    diff=actual-formula;
    if(diff<0)
        diff=-diff;
    if(n==2 || n==71)
        printf("\nDifference: %Lf",diff);
    else
        printf("\nDifference: %Le",diff);
    return 0;
}