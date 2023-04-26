#include<stdio.h>
void readArray(int M[200][200],int r, int c)
{
    int i,j;
    printf("\nEnter array: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&M[i][j]);
    }
}
void print(int M[200][200], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}
void sort(int a[400],int n)
{
    int i,j,k,t;
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int merge(int a[400],int b[400],int c[800],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else if(b[j]<a[i])
            c[k++]=b[j++];
        else
        {
            c[k++]=a[i++];
            c[k++]=b[j++];
        }
    }
    while(i<n1)
        c[k++]=a[i++];
    while(j<n2)
        c[k++]=b[j++];
    return k;
}
int main()
{
    int A[200][200],B[200][200],C[200][200],a[400],b[400],c[800],r1,c1,r2,c2,r3=0,c3=0,i,j,k,n1,n2,n3;
    printf("\nEnter dimensions of 1st array: ");
    scanf("%d%d",&r1,&c1);
    printf("\nEnter elements of 1st array: ");
    readArray(A,r1,c1);
    printf("\nEnter dimensions of 2nd array: ");
    scanf("%d%d",&r2,&c2);
    printf("\nEnter elements of 2nd array: ");
    readArray(B,r2,c2);
    n1=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            a[n1++]=A[i][j];
    }
    n2=0;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            b[n2++]=B[i][j];
    }
    sort(a,n1);
    sort(b,n2);
    printf("\n1st Array Sorted:\n");
    k=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            A[i][j]=a[k++];
    }
    print(A,r1,c1);
    printf("\n2nd Array Sorted:\n");
    k=0;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
            B[i][j]=b[k++];
    }
    print(B,r2,c2);
    n3=merge(a,b,c,n1,n2);
    printf("\nEnter dimensions for new sorted array:");
    scanf("%d%d",&r3,&c3);
    while((r3*c3)!=n3)
    {
        printf("\nTotal no of elements in new array must be %d",n3);
        scanf("%d%d",&r3,&c3);
    }
    k=0;
    for(i=0;i<r3;i++)
    {
        for(j=0;j<c3;j++)
        {
            C[i][j]=c[k++];
        }
    }
    printf("\nFinal merged array:\n");
    print(C,r3,c3);
    return 0;
}