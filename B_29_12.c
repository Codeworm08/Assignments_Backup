#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node * next;
};
struct node * create(int a)
{
    struct node *w =(struct node*)malloc(sizeof(struct node));
    w->a=a;
    w->next=NULL;
    return w;
}
void insert(struct node *head,int a,int n)
{
    int i=0;
    struct node *p=head;
    struct node *q=(struct node*)malloc(sizeof(struct node));
    while(p->next)
    {
        i++;
        p=p->next;
    }
    if(i==n-1)
    {
        printf("\nOverflow!Delete elements!");
        return;
    }
    q=create(a);
    p->next=q;
}
int size(struct node *head)
{
    int i=0;
    struct node *t=head;
    while(t)
    {
        t=t->next;
        i++;
    }
    return i;
}
struct node * delete(struct node *head,int p, int n)
{
    int i,len;
    struct node *t=head,*s;
    if(head==NULL)
    {
        printf("\nUnderflow!Insert elements!");
        return NULL;
    }
   
    len=size(head);
    if(p>=len)
    {
        printf("\nList has elements upto position: %d",len-1);
        return head;
    }
    if(p==0)
    {
        head=head->next;
        return head;
    }
    for(i=0;i<p-1;i++)
        t=t->next;
    if(p==n-1)
    {
        t->next=NULL;
        return head;
    }
    s=t->next;
    t->next=t->next->next;
    s->next=NULL;
    return head;
}
void print(struct node *head)
{
    struct node*p=head;
    printf("\nThe List:\n");
    if(head==NULL)
    {
        printf("\nThe List is empty!");
        return;
    }
    while (p->next)
    {
        printf("%d->",p->a);
        p=p->next;
    }
    printf("%d",p->a);
}
void search(struct node *head,int s)
{
    struct node *p=head;
    int i=0,f=1;
    if(head==NULL)
    {
        printf("\nList is empty!");
        return;
    }
    while (p)
    {
        if(p->a==s)
        {
            printf("\n%d found at %d (0 indexing)",s,i);
            f=0;
            break;
        }
        i++;
        p=p->next;
    }
    if(f)
        printf("\nElement not found!");
    
}
int main()
{
    int n,i,a,ch;
    struct node *head=NULL;
    printf("\nEnter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter value of node %d: ",i);
        scanf("%d",&a);
        if(head==NULL)
            head=create(a);
        else
            insert(head,a,n);
    }
    do
    {
        printf("\n\n\n\tEnter:\n\t1 to insert new node.\n\t2 to delete specific node.\n\t3 to print the list.\n\t4 to search specific element.\n\t-1 to quit.");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value of new node: ");
            scanf("%d",&a);
            insert(head,a,n);
            break;
        case 2:
            printf("\nEnter index of node to be deleted(0 indexing): ");
            scanf("%d",&a);
            head=delete(head,a,n);
            break;
        case 3:
            print(head);
            break;
        case 4:
            printf("\nEnter element to be searched: ");
            scanf("%d",&a);
            search(head,a);
        case -1:
            break;
        default:
            printf("\nInvalid input!");
        }
    } while (ch!=-1);
    
    return 0;
}