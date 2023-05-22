#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	int pri;
	struct node *next;
}node;

typedef struct queue{
	node *rear;
	node *front;
}queue;

bool isempty(queue p)
{
	if((p.rear==NULL)&&(p.front==NULL))
		return true;
	else
		return false;
}

node * createnode(int n,int p)
{
	node *c=(node *)malloc(sizeof(node));
	c->data=n;
	c->pri=p;
	c->next=NULL;
	return c;
}

void create(queue *p)
{
	p->front=NULL;
	p->rear=NULL;
	printf("Queue created\n");
	return;
}

void enqueue(queue *p,node *d)
{
	node *c=p->front;
	if(isempty(*p))
	{
		p->front=d;
		p->rear=d;
		return;
	}
	if(d->pri<c->pri)
	{
		d->next=c;
		p->front=d;
		return;
	}
	while(c->next!=NULL&&d->pri>=c->next->pri)
		c=c->next;
	d->next=c->next;
	c->next=d;
	printf("Data enqueued successfully\n");
	return;
}

node * deletefirst(node **p)
{
	node *c=*p;
	*p=(*p)->next;
	return(c);
}

node * dequeue(queue *p)
{
	node *x;
	int f=0;
	if(isempty(*p))
	{
		printf("Underflow\n");
		return(NULL);
	}
	else if(p->front==p->rear)
		f=1;
	x=deletefirst(&(p->front));
	if(f==1)
		p->rear=NULL;
	return(x);
}

node * getfront(queue p)
{
	node *c;
	if(isempty(p))
	{
		printf("Underflow\n");
		return(NULL);
	}
	c=p.front;
	return(c);
}

void display(queue p)
{
	node *c=p.front;
	if(isempty(p))
	{
		printf("Queue is empty\n");
		return;	
	}
	printf("(Data , priority)\n");
	while(c!=NULL)
	{
		printf("(%d,%d)\t",c->data,c->pri);
		c=c->next;
	}
	printf("\n");
	return;
}

int main()
{
	queue q;
	node *p;
	int n,k,ch;
	create(&q);
    do
	{
		printf("\n0->exit\n1->enqueue\n2->dequeue\n3->get front\n4->display queue");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				break;
			case 1:
				printf("\nEnter data: ");
				scanf("%d",&n);
				printf("\nEnter priority: ");
				scanf("%d",&k);
                p=createnode(n,k);
				enqueue(&q,p);
				break;
			case 2:
				p=dequeue(&q);
				if(p!=NULL)
					printf("Dequeued element is %d\nAnd priority is %d\n",p->data,p->pri);
				break;
			case 3:
				p=getfront(q);
				if(p!=NULL)
					printf("Front element is %d\nAnd priority is %d\n",p->data,p->pri);
				break;
            case 4:
                display(q);
                break;
			default:
				printf("\nInvalid Input");
				break;
		}
    }while(ch!=0);
    return 0;
}