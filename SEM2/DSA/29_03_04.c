#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct list{
    int data;
    struct list *next;
};
typedef struct list *node;

node createNode(int data)
{
    node new = (node)malloc(sizeof(struct list));
    new->data = data;
    new->next = NULL;
    return new;
}

void lpush(int n,node *top)
{
    node p;
    if(*top == NULL)
    {
        *top=createNode(n);
        return;
    }
    p=createNode(n);
    p->next=*top;
    *top=p;
}
int lpop(node *top,int *f)
{
    if(*top == NULL)
    {
        *f=-1;//flag to check Underflow
        return -1;
    }
    node p=*top;
    int t=(*top)->data;
    *top=(*top)->next;
    p->next=NULL;
    free(p);
    return t;
}

bool isEqual(node s1,node s2)
{
    int a,b;
    int f=1,g=1;
    while(s1 && s2)
    {
        a=lpop(&s1,&f);
        b=lpop(&s2,&g);
        if(a!=b)
            return false;
    }
    if(s1!=NULL || s2 !=NULL)
        return false;
    return true;
}
int main()
{
    node top1,top2;
    top1=NULL;top2=NULL;
    int d,c;
    printf("\nEnter elements of stack1:");
    do
    {
        printf("\nEnter data to push:");
        scanf("%d",&d);
        lpush(d,&top1);
        printf("\n0->stop.1->Continue");
        scanf("%d",&c);
    }while(c!=0);
    printf("\nEnter elements of stack2:");
    do
    {
        printf("\nEnter data to push:");
        scanf("%d",&d);
        lpush(d,&top2);
        printf("\n0->stop.1->Continue");
        scanf("%d",&c);
    }while(c!=0);
    printf("\nEqual?");
    if(isEqual(top1,top2))
        printf("\nAns: YES");
    else
        printf("\nAns: NO");
    return 0;
}