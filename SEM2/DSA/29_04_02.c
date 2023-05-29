#include<stdio.h>
#include<stdlib.h>
#define NON -100

void create(int *a, int n,int i)
{
    int data,ch;
    if(i<n)
    {
        printf("\nEnter data in node: ");
        scanf("%d",&data);
        a[i]=data;
        printf("\nAdd left child for node with data %d?(1/0): ",data);
        scanf("%d",&ch);
        if(ch)
            create(a,n,2*i+1);
        printf("\nAdd right child for node with data %d?(1/0): ",data);
        scanf("%d",&ch);
        if(ch)
            create(a,n,2*i+2);
    }
    else
        printf("\nArray is full");
}
void preorder(int *a,int n, int i)
{
    if(i>=n||a[i]==NON)
        return;
    printf("%d ",a[i]);
    preorder(a,n,2*i+1);
    preorder(a,n,2*i+2);
}
void inorder(int *a,int n, int i)
{
    if(i>=n||a[i]==NON)
        return;
    inorder(a,n,2*i+1);
    printf("%d ",a[i]);
    inorder(a,n,2*i+2);
}
void postorder(int *a,int n, int i)
{
    if(i>=n||a[i]==NON)
        return;
    postorder(a,n,2*i+1);
    postorder(a,n,2*i+2);
    printf("%d ",a[i]);
}
int main()
{
    int *a=NULL;
    int ch,data,n,i;
    do
    {
        printf("\n0.Quit\n1.Create Binary Tree\n2.Preorder\n3.Inorder\n4.Postorder\n: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter no of nodes in the tree: ");
            scanf("%d",&n);
            n=2*n;//2n to accomodate all possible edges
            a=(int*)malloc(sizeof(int)*n);
            for(i=0;i<n;i++)
                a[i]=NON;
            create(a,n,0);
            break;
        case 2:
            if(a==NULL)
            {
                printf("\nNo tree created!");
                break;
            }
            printf("\nPreorder Traversal:\n");
            preorder(a,n,0);
            break;
        case 3:
            if(a==NULL)
            {
                printf("\nNo tree created!");
                break;
            }
            printf("\nInorder Traversal:\n");
            inorder(a,n,0);
            break;
        case 4:
            if(a==NULL)
            {
                printf("\nNo tree created!");
                break;
            }
            printf("\nPostorder Traversal:\n");
            postorder(a,n,0);
            break;
        default:
            printf("\nWrong input.");
            break;
        }                           
    } while (ch!=0);
    return 0;
}