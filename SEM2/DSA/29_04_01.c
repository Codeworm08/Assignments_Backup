#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node * create()
{
    node *t;
    int data,ch;
    t=(node*)malloc(sizeof(node));
    printf("\nEnter data in node: ");
    scanf("%d",&data);
    t->data=data;
    printf("\nAdd left child for node with data %d?(1/0): ",data);
    scanf("%d",&ch);
    if(ch)
        t->left=create();
    else
        t->left=NULL;
    printf("\nAdd right child for node with data %d?(1/0): ",data);
    scanf("%d",&ch);
    if(ch)
        t->right=create();
    else
        t->right=NULL;
    return t;    
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main()
{
    node *t=NULL;
    int ch;
    do
    {
        printf("\n0.Quit\n1.Create Binary Tree\n2.Preorder\n3.Inorder\n4.Postorder\n: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            t=create();
            break;
        case 2:
            printf("\nPreorder Traversal:\n");
            preorder(t);
            break;
        case 3:
            printf("\nInorder Traversal:\n");
            inorder(t);
            break;
        case 4:
            printf("\nPostorder Traversal:\n");
            postorder(t);
            break;
        default:
            printf("\nWrong input.");
            break;
        }
    } while (ch!=0);
    
    return 0;
}