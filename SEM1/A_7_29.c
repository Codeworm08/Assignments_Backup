#include<stdio.h>
#include<stdlib.h>
typedef long int li;
li euclid(li a, li b)
{
    li r;
    while(b>0)
    {
        r = a % b;
        a=b;
        b=r;
    }
    return a;
}
li LCM(li a, li b)
{
    if(a==0 || b==0)
        return -1;
    return (a*b)/euclid(a,b);
}
int main()
{
    li a[200],n,i,lcm;
    printf("\nEnter no of numbers: ");
    scanf("%ld",&n);
    printf("\nInput %ld numbers: ",n);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    if(n==1)
    {
        printf("LCM: %ld",a[0]);
        exit(1);
    }
    lcm=LCM(a[0],a[1]);
    if(lcm==-1)
    {
        printf("\nCannot be calculated(undefined)");
        exit(1);
    }
    
    if(n==2)
    {
        printf("\nLCM = %ld",lcm);
        exit(1);
    }
    for(i=2;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("\nCannot be calculated(undefined)");
            exit(1);
        }
        lcm = LCM(lcm,a[i]);
    }
    printf("\nLCM = %ld",lcm);
    return 0;
}