#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4
struct list{
    int data;
    struct list *next;
};
typedef struct list *node;
int sta[MAX_SIZE];
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
void push(int n, int *f,int *top)
{
    if(*top==MAX_SIZE)
    {
        *f=-1;//flag to check Overflow
        return;
    }
    sta[(*top)++]=n;
    
}
//For debugging purposes
/* void display(int t)
{
    int i;
    for(i=0;i<=t;i++)
    {
        printf("%d->",sta[i]);
    }
    printf("%d\n",sta[i]);
} */
int pop(int *f,int *top)
{
    if((*top)==0)
    {
        *f=-1;//flag to check Underflow
        return -1;
    }
    return sta[--(*top)];
}
int main()
{
    int t=0,ch,f,data,x;
    node top=NULL;
    do
    {
        printf("\n1->Push to Arr Stack\n2->Pop to Arr Stack");
        printf("\n3->Push to Liked List Stack\n4->Pop to Liked List Stack");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d",&data);
                f=0;
                push(data,&f,&t);
                if(f==-1)
                {
                    printf("\nOverflow");
                }
                //display(t);
                break;
            case 2:
                f=0;
                x=pop(&f,&t);
                if(f==-1)
                {
                    printf("\nUnderflow");
                }
                else
                {
                    printf("\nValue popped: %d",x);
                }
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d",&data);
                f=0;
                lpush(data,&top);
                break;
            case 4:
                f=0;
                x=lpop(&top,&f);
                if(f==-1)
                {
                    printf("\nUnderflow");
                }
                else
                {
                    printf("\nValue popped: %d",x);
                }
                break;
            default:
                printf("\nInvalid data\n");
        }
    } while (ch);
    
    return 0;
}