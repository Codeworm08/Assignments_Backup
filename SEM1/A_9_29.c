#include<stdio.h>
int main()
{
    int n,a[100000],i,p;
    printf("\nEnter n: ");
    scanf("%d",&n);
    if(n<=2)
        printf("\nNo prime number present");
    for(i=0;i<n;i++)
        a[i]=1;
    for(p=2;p*p<n;p++)
    {
        if(a[p])
        {
            for(i=p*p;i<n;i+=p)
                a[i]=0;            
        }
    }
    for(int i=2;i<n;i++)
        if(a[i])
            printf("%d ",i);
    return 0;
}