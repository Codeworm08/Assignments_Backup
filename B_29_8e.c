#include<stdio.h>
int binary(int n)
{
    if(n<2)
        return n;
    return 10*binary(n/2)+n%2;
}
int main()
{
    int n,b;
    printf("\nEnter a decimal number: ");
    scanf("%d",&n);
    b=binary(n);
    printf("\nBinary: %d",b);
    return 0;
}