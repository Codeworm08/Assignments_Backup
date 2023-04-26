#include<stdio.h>
void max3min5mid(int *a, int n)
{
    int largest=a[0], large2=a[0], large3=a[0],i,min,min2,min3,min4,min5,mid,p;
    min=min2=min3=min4=min5=__INT_MAX__;
    if(n<5)
    {
        printf("\nInsufficient no of elements!");
        return;
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>largest)
        {
            large3=large2;
            large2=largest;
            largest=a[i];            
        }
        else if(a[i]>large2)
        {
            large3=large2;
            large2= a[i];
        }
        else if(a[i]>large3)
        {
            large3=a[i];
        }
        if(a[i]<min)
        {
            min5=min4;
            min4=min3;
            min3=min2;
            min2=min;
            min=a[i];
        }
        else if(a[i]<min2)
        {
            min5=min4;
            min4=min3;
            min3=min2;
            min2=a[i];
        }
        else if(a[i]<min3)
        {
            min5=min4;
            min4=min3;
            min3=a[i];
        }
        else if(a[i]<min4)
        {
            min5=min4;
            min4=a[i];
        }
        else if(a[i]<min5)
        {
            min5=a[i];
        }
    }
    printf("\n3rd maximum: %d",large3);
    printf("\n5th minimum: %d",min5);
    if(n%2==0)
    {
        printf("\nMiddle elements: %d %d",a[n/2-1],a[n/2]);
    }
    else
        printf("\nMiddle element: %d",a[n/2]);

}
int main()
{
    int n,a[100],i;
    printf("\n Enter n: ");
    scanf("%d",&n);
    printf("\nEnter %d numbers: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    max3min5mid(a,n);
    return 0;
}