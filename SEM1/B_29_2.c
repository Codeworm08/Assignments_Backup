#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void partition(int a[200],int n)
{
    int pivot,i=-1,j,t;
    pivot=a[n-1];
    for(j=0;j<n;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[n-1];
    a[n-1]=t;
}
void random_partition(int a[200],int n)
{
    int p,t;
    srand(time(0));
    p=rand()%n;
    t=a[p];
    a[p]=a[n-1];
    a[n-1]=t;
    printf("\nPivot: %d",a[n-1]);
    partition(a,n);
}
int main()
{
    int a[200],n;
    printf("\nEnter no of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    random_partition(a,n);
    printf("\nAfter partiion:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}