#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct elem{
	int data;
	int pri;
}elem;

typedef struct queue{
	elem *a;
	int front;
	int rear;
	int size;
}queue;

bool isempty(queue p)
{
	if(p.front==-1&&p.rear==-1)
		return true;
	return false;
}

bool isfull(queue p)
{
	if(p.rear+1==p.size)
		return true;
	return false;
}

void create(queue *p)
{
	int n;
	printf("Enter the size of the priority queue = ");
	scanf("%d",&n);
	p->a=(elem *)malloc(sizeof(elem)*n);
	p->front=-1;
	p->rear=-1;
	p->size=n;
	return;
}

void enqueue(queue *p,elem d)
{
	int i,j;
	if(isfull(*p))
	{
		printf("Queue overflow\n");
		return;
	}
	else if(isempty(*p))
	{
		p->front=0;
		p->rear=0;
		p->a[p->rear]=d;
		return;
	}
	for(i=p->rear;i>=p->front;i--)
	{
		if(d.pri>=p->a[i].pri)
			break;
	}
	for(j=p->rear;j>i;j--)
	{
		p->a[j+1]=p->a[j];
	}
	p->a[i+1]=d;
	printf("Data enqueued successfully\n");
	p->rear++;
	return;
}

bool dequeue(queue *p, elem *n)
{
	
	if(isempty(*p))
		return false;
	
	*n=p->a[p->front];
	if(p->front==p->rear)
	{
		p->front=-1;
		p->rear=-1;
	}
	else
		p->front++;
	return true;
}

bool getfront(queue p, elem *n)
{
	
	if(isempty(p))
		return false;
	*n=p.a[p.front];
	return true;
}

void display(queue p)
{
    if(isempty(p))
    {
        printf("\nUnderflow");
        return;
    }
    printf("(data , priority)\n");
	for(int i=p.front;i<=p.rear;i++)
		printf("(%d,%d)\t",p.a[i].data,p.a[i].pri);
	printf("\n");
	return;
}

int main()
{
	queue q;
	elem p;
	int c;
	create(&q);
	do
	{
		printf("\n0->exit\n1->enqueue\n2->dequeue\n3->get front\n4->display queue");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("\nEnter data: ");
				scanf("%d",&p.data);
				printf("\nEnter priority: ");
				scanf("%d",&p.pri);
				enqueue(&q,p);
				break;
			case 2:
				if(dequeue(&q,&p))
					printf("\nDequeued element is %d, and priority is %d",p.data,p.pri);
                else
                    printf("\nUnderflow");
				break;
			case 3:
				if(getfront(q,&p))
					printf("\nFront element is %d, and priority is %d",p.data,p.pri);
                else
                    printf("\nUnderflow");
				break;
            case 4:
                display(q);
                break;
			default:
				printf("\nInvalid Input");
				break;
		}
	}while(c!=0);
	free(q.a);
	return(0);
}