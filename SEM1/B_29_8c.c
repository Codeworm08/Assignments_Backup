#include<stdio.h>
#include<stdlib.h>
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void permutation(int *a, int x, int y)
{
    if(x==y)
    {
        print(a,y+1);
        return;
    }
    for(int i=x;i<=y;i++)
    {
        swap((a+i),(a+x));
        permutation(a, x+1,y);
        swap((a+i),(a+x));
    }
}
int main()
{
    int n,*a;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("\nEnter %d numbers: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nPermutations:\n");
    permutation(a,0,n-1);
    return 0;
}