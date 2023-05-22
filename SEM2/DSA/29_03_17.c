#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
typedef struct queue{
	node *rear;
	node *front;
}queue;

void create(queue *p)
{
	p->front=NULL;
	p->rear=NULL;
	return;
}

node * createnode(int n)
{
	node *c=(node *)malloc(sizeof(node));
	c->data=n;
	c->left=NULL;
	c->right=NULL;
	return c;
}

bool isempty(queue p)
{
	if((p.rear==NULL)&&(p.front==NULL))
		return true;
	else
		return false;
}

void insertFront(node **p,int n)
{
    node *t;
    t = createnode(n);
    if ((*p) != NULL)
    {
        (*p)->left=t;
    }
    t->right=*p;
	*p=t;
	return;
}

void enqueue_front(queue *p,int n)
{
	int f=0;
	if(isempty(*p))
		f=1;
	insertFront(&(p->front),n);
	if(f==1)
		p->rear=p->front;
	printf("Enqueued at the front successfully\n");
	return;
}

void insertEnd(node **p, int n)
{
    node *t;
    t=createnode(n);
    if ((*p)!= NULL)
		(*p)->right=t;
	t->left=*p;
	*p=t;
	return;
}

void enqueue_rear(queue *p, int n)
{
	int f=0;
	if(isempty(*p))
		f=1;
	insertEnd(&(p->rear),n);
	if(f==1)
		p->front=p->rear;
	printf("Enqueued at the rare successfully\n");
	return;
}

int deleteFront(node **p)
{
	int x;
	node *c=*p;
	x=c->data;
	*p=c->right;
	if(c->right)
		(*p)->left=NULL;
	free(c);
	return(x);
}

bool dequeue_front(queue *p,int *x)
{
	int f=0;
	if(isempty(*p))
		return false;

	else if(p->front==p->rear)
		f=1;
	*x=deleteFront(&(p->front));
	if(f==1)
		p->rear=p->front;
	printf("Dequeued at the front successfully\n");
	return true;
}

int deleteEnd(node **p)
{
	int x;
	node *c=*p;
	x=c->data;
	*p=c->left;
	if(c->left)
		(*p)->right=NULL;
	free(c);
	return x;
}

bool dequeue_rear(queue *p, int *x)
{
	int f=0;
	//printf("%d\n",p->rare->data);
	if(isempty(*p))
		return false;

	else if(p->front==p->rear)
		f=1;
	*x=deleteEnd(&(p->rear));
	if(f==1)
		p->front=p->rear;
	printf("Dequeued at the rare successfully\n");
	return true;
}

int getfront(queue p, int *x)
{
	int f=0;
	if(isempty(p))
		return false;
	*x=p.front->data;
	return true;
}

int main()
{
	queue q;
	int x,c;
	create(&q);
	do
	{
		printf("\nEnter your choice :\n0->quit\n1->enqueue front\n2->enqueue rear\n3->dequeue front\n4->dequeue rear\n5->get front\n=> ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("\nEnter data = ");
				scanf("%d",&x);
				enqueue_front(&q,x);
				break;
			case 2:
				printf("\nEnter data = ");
				scanf("%d",&x);
				enqueue_rear(&q,x);
				break;
			case 3:
				if((dequeue_front(&q,&x)))
					printf("\nDequeued element from front is = %d",x);
				else
					printf("\nUnderflow");
				break;
			case 4:
				if((dequeue_rear(&q,&x)))
					printf("\nDequeued element from rare is = %d",x);
				else
					printf("\nUnderflow");
				break;
			case 5:
				if((getfront(q,&x)))
					printf("\nFront element is = %d",x);
				else
					printf("\nUnderflow");
				break;
			default:
				printf("\nInvalid Input");
				break;
		}
	}while(c!=0);
	return 0;
}