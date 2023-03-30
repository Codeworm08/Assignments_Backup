#include<stdio.h>
#include<stdlib.h>

int* create(int *a)
{
    int i,ch;
    if(a!=NULL)
    {
        printf("\nArray already created!!");
        return a;
    }
    a=(int*)malloc(sizeof(int ));
    i=0;
    while(1)
    {
        printf("\nEnter a number:");
        scanf("%d",(a+i));
        printf("\n1 to continue.0->Stop : ");
        scanf("%d",&ch);
        if(ch)
        {
            i+=1;
            a=realloc(a,sizeof(int)*(i+1));
        }
        else break;
    }
    return a;
}
void display(int *a)
{
    int l,i;
    l=sizeof(a)/sizeof(int);
    printf("\n");
    for(i=0;i<l;i++)
    {
        printf("%d\t",a[i]);
    }
}
int count(int *a)
{
    return sizeof(a)/sizeof(int);
}
void reverse(int *a)
{
    int l,r,t;
    l=0;
    r=(sizeof(a)/sizeof(int))-1;
    while(l<r)
    {
        t=a[l];
        a[l]=a[r];
        a[r]=t;
        l+=1;
        r-=1;
    }
}
int main()
{
    int *a=NULL,i;
    a=create(a);
    for(i=0;i<=2;i++)
    {
        printf("\n%d",a[i]);
    }
    return 0;
}