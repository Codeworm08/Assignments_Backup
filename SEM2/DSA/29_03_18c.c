#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct priority_queue{
	int **a;
    int front;
    int rear;
    int maxsize;
}queue;

void create(queue *q)
{
	printf("Enter the size of the queue = ");
	scanf("%d",&q->maxsize);
    q->a=(int **)malloc(sizeof(int *)* q->maxsize);
	for(int i=0;i<q->maxsize;i++)
	{
		q->a[i]=(int *)malloc(sizeof(int)*(q->maxsize+1));
	}
	q->front=-1;
	q->rear=-1;
	return;
}

bool isempty(queue q)
{
	if(q.front==-1&&q.rear==-1)
		return true;
	return false;
}

bool isfull(queue q)
{
	if(q.rear+1==q.maxsize)
		return true;
	return false;
}

void enqueue(queue *q)
{
	int p,d,i,j,f=0;
	if(isfull(*q))
	{
		printf("Queue overflow\n");
		return;
	}
	printf("Enter data: ");
	scanf("%d",&d);
	printf("Enter priority: ");
	scanf("%d",&p);
	if(isempty(*q))
	{
		q->front=0;
		q->rear=0;
		q->a[0][0]=p;
		q->a[0][1]=d;
		printf("Enqueued successfully\n");
		return;
	}
	for(i=q->front;i<=q->rear;i++)
	{
		if(p<q->a[i][0])
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		for(j=q->rear;j>=i;j--)
		{
			q->a[j+1][0]=q->a[j][0];
			q->a[j+1][1]=q->a[j][1];
		}
	}
	q->a[i][0]=p;
	q->a[i][1]=d;
	q->rear++;
	printf("Enqueued successfully\n");
	return;
}
int dequeue(queue *q,int *d)
{
	int p;
	if(isempty(*q))
	{
		printf("Queue underflow\n");
		return -1;
	}
	*d=q->a[q->front][1];
	p=q->a[q->front][0];
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	q->front++;
	return(p);
}

int getfront(queue q,int *d)
{
	int p;
	if(isempty(q))
	{
		printf("Queue is empty\n");
		return -1;
	}
	*d=q.a[q.front][1];
	p=q.a[q.front][0];
	return(p);
}

void display(queue q)
{
	int i;
	if(isempty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("(data , priority)\n");
	for(i=q.front;i<=q.rear;i++)
	{
		printf("(%d,%d),",q.a[i][1],q.a[i][0]);
	}
	printf("\n");
	return;
}

int main()
{
    queue q;
	int ch,p,d;
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
				enqueue(&q);
				break;
			case 2:
				p=dequeue(&q,&d);
				if(p!=-1)
					printf("\nDequeued element is %d, and priority is %d",d,p);
				break;
			case 3:
				p=getfront(q,&d);
				if(p!=-1)
					printf("\nFront element is %d, and priority is %d",d,p);				
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