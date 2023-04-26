#include<stdio.h>
int fact(int x)
{
    int f=1,i;
    for(i=1;i<=x;i++)
        f*=i;
    return f;
}
int main()
{
    int n,i,j,k,el;
    printf("\nEnter no of rows of Pascal Triangle: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        for ( k = n; k > i; k--)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)
        {
            el=fact(i)/(fact(j)*fact(i-j));
            printf("%d ",el);
        }
        printf("\n");
        
    }  
    return 0;
}