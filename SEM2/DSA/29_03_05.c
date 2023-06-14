#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct list{
    int data;
    struct list *next;
}st;

st * createNode(int data)
{
    st *new = (st *)malloc(sizeof(st));
    new->data = data;
    new->next = NULL;
    return new;
}
void push(st **top,int x)
{
    if(*top==NULL)
    {
        *top = createNode(x);
        return;
    }
    st *new = createNode(x);
    new->next = *top;
    *top = new;
}
int pop(st **top,int *f)
{
    if(*top==NULL)
    {
        *f=0;
        return -1;
    }
    st *temp = *top;
    int t = temp->data;
    *top = (*top)->next;
    free(temp);
    return t;
}
int peek(st **top,int *f)
{
    if(*top==NULL)
    {
        *f=0;
        return -1;
    }
    return (*top)->data;
}

int main()
{
    int n,ch,d,x,f;
    printf("\nEnter number of stacks:");
    scanf("%d",&n);
    st **s = (st **)malloc(sizeof(st*)*n);
    for(int i=0;i<n;i++)
    {
        *(s+i)=NULL;
    }
    do
    {
        printf("\n0.Exit");
        printf("\n1.Push to specific stack");
        printf("\n2.Pop from specific stack");
        printf("\n3.Peek specific stack");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                break;
            case 1:
                printf("\nAvailable stack indices:[0-%d]",n-1);
                printf("\nEnter stack choice: ");
                scanf("%d",&x);
                while(x>(n-1) ||x <0)
                {
                    printf("\nIndex %d is invalid. Please choose between [0-%d]",x,n-1);
                    scanf("%d",&x);
                }
                printf("\nEnter data to push: ");
                scanf("%d",&d);
                push(s+x,d);
                break;
            case 2:
                printf("\nAvailable stack indices:[0-%d]",n-1);
                printf("\nEnter stack choice: ");
                scanf("%d",&x);
                while(x>(n-1) ||x <0)
                {
                    printf("\nIndex %d is invalid. Please choose between [0-%d]",x,n-1);
                    scanf("%d",&x);
                }
                f=1;
                d = pop(&s[x],&f);
                if(!f)
                    printf("\nUnderflow!");
                else
                    printf("\nPopped: %d",d);
                break;
            case 3:
                printf("\nAvailable stack indices:[0-%d]",n-1);
                printf("\nEnter stack choice: ");
                scanf("%d",&x);
                while(x>(n-1) ||x <0)
                {
                    printf("\nIndex %d is invalid. Please choose between [0-%d]",x,n-1);
                    scanf("%d",&x);
                }
                f=1;
                d = peek(&s[x],&f);
                if(!f)
                    printf("\nUnderflow!");
                else
                    printf("\nTop: %d",d);
                break;
            default:
                printf("\nInvalid input.");
        }
    } while (ch!=0);
    
    return 0;
}