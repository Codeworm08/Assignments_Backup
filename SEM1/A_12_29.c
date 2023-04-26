#include<stdio.h>
int main()
{
    int n1,n2,a[100],b[100],uni[100],i,j,k=0;
    printf("\nEnter length of first list: ");
    scanf("%d",&n1);
    printf("\nEnter 1st list:\n");
    for(i=0;i<n1;i++)
        scanf("%d",&a[i]);
    printf("\nEnter length of 2nd list: ");
    scanf("%d",&n2);
    printf("\nEnter 2nd list:\n");
    for(i=0;i<n2;i++)
        scanf("%d",&b[i]);
    i=0;
    j=0;
    while (i<n1 && j<n2)
    {
        if(a[i]<b[j])
            uni[k++]=a[i++];
        else if(a[i]>b[j])
            uni[k++]=b[j++];
        else
        {
            uni[k++]=a[i++];
            uni[k++]=b[j++];
        }
        
    }
    if(i<n1)
    {
        for(;i<n1;i++)
            uni[k++]=a[i];
    }
    if(j<n2)
    {
        for(;j<n2;j++)
            uni[k++]=b[j];
    }
    printf("\nUnion:\n");
    for (i=0;i<n1+n2; i++)
        printf("%d ",uni[i]);
    return 0;
}