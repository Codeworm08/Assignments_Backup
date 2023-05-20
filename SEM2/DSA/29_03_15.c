#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct queue{
	node *rear;
	node *front;
}queue;

void create(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
	printf("Queue created\n");
	return;
}

node * createnode(int n)
{
	node *c=(node *)malloc(sizeof(node));
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
