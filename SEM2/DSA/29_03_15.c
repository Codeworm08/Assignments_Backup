#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct queue{
	NODE *rear;
	NODE *front;
}queue;

void create(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
	printf("Queue created\n");
	return;
}

NODE * createnode(int n)
{
	NODE *c=(NODE *)malloc(sizeof(NODE));
	c->data=n;
	c->next=NULL;
	return c;
}

bool isempty(queue q)
{
	if((q.rear==NULL)&&(q.front==NULL))
		return true;
	else
		return false;
}

bool enqueue(int x, queue *q)
{
    if(isempty(*q))
    {
        q->front=createnode(x);
        q->rear=q->front;
    }
    else
    {
        q->rear->next=createnode(x);
        q->rear=q->rear->next;
    }
    return true;
}

bool dequeue(queue *q, int *x)
{
    if(isempty(*q))
        return false;
    *x=q->front->data;
    q->front=q->front->next;
    return true;
}

bool getFront(queue *q, int *x)
{
    if(isempty(*q))
        return false;
    *x=q->front->data;
    return true;
}

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

int main()
{
    int ch,data;
    queue *q=NULL;
    NODE *t;
    do
    {
        printf("\n0->Quit\nEnter 1 to enque\nEnter 2 to dequeue\nEnter 3 to getFront\n=> ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            enqueue(data,q);
            break;
        case 2:
            if(dequeue(q,&data))
                printf("\nData removed: %d",data);
            else
                printf("\nQueue Empty!");
            break;
        case 3:
            if(getFront(q,&data))
                printf("\nData at front = %d",data);
            else
                printf("\nQueue Empty!");
            break;
        default:
            printf("\nInvalid input");
            break;
        }
    } while (ch!=0);
    
    return 0;
}