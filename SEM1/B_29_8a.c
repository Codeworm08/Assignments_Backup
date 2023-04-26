#include<stdio.h>
void fibonacci(int x,int y,int n)
{
    if(n==0)
        return;
    printf("%d ",x);
    fibonacci(y,x+y,n-1);
}
int main()
{
    int n;
    printf("\nEnter no of fibonacci numbers: ");
    scanf("%d",&n);
    fibonacci(0,1,n);
    return 0;
}